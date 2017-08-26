#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"
#include "helper.h"
#include "dnhelper.h"

#include "../../MyUtility/getStdString.net.h"
#include "../../MyUtility/browseFolder.h"

namespace sff {
	using namespace Ambiesoft;
	using namespace System::Text;

	FormMain::FormMain(System::Collections::Generic::List<String^>^ args)
	{
		args_ = args;
		InitializeComponent();

		StringBuilder sb;
		for each(String^ line in args)
		{
			sb.AppendLine(line);
		}
		txtInDir->Text = sb.ToString();

		orgShowErrorText_ = btnShowError->Text;
	}


	public ref class ListViewItemComparer : System::Collections::IComparer
	{
	private:
		static int rev_;
		int _column;

	public:
		static ListViewItemComparer()
		{
			rev_ = 1;
		}
		ListViewItemComparer(int col)
		{
			_column = col;
			rev_ = rev_ * -1;
		}

		virtual int Compare(Object^ o1, Object^ o2)
		{
			//ListViewItem�̎擾
			ListViewItem^ item1 = (ListViewItem^) o1;
			ListViewItem^ item2 = (ListViewItem^) o2;

			ULL u1;
			ULL u2;
			System::UInt64::TryParse(item1->SubItems[_column]->Text, u1);
			System::UInt64::TryParse(item2->SubItems[_column]->Text, u2);

			LONGLONG uret=u1-u2;
			int ret=0;
			if(uret==0)
				ret =0;
			else if(uret>0)
				ret=1;
			else
				ret=-1;

			return ret * rev_;
		}
	};

	void FormMain::SetTitle(String^ addition)
	{
		if(String::IsNullOrEmpty(addition))
		{
			this->Text = Application::ProductName;
		}
		else
		{
			this->Text = addition + " - " + Application::ProductName;
		}
	}
	System::Void FormMain::FormMain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		ThreadOn(false);
		cmbNameReg->Items->Add(L"\\.pdf$");
		cmbNameReg->SelectedIndex = 0;
		cmbNameReg->Text = L"";

		cmbMinSize->Items->Add(L"10M");
		cmbMinSize->SelectedIndex = 0;
		cmbMinSize->Text = L"";

		SetTitle(nullptr);	
		Application::Idle += gcnew EventHandler(this, &FormMain::onIdle);

		lblVersion->Text = "SFF ver" + System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version;
	}

	System::Void FormMain::onIdle(System::Object^, System::EventArgs^)
	{
		slItemCount->Text = I18NLS(L"Items : ") + lvProgress->Items->Count.ToString();
		slGroupCount->Text = I18NLS(L"Groups : ") + lvProgress->Groups->Count.ToString();

		bool on =(gcurthread != NULL);

		btnPause->Enabled=on  && !bSuspended_;
		btnResume->Enabled=on && bSuspended_;

		
	}

	System::Void FormMain::lvProgress_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e)
	{
		lvProgress->ListViewItemSorter =
			gcnew ListViewItemComparer(e->Column);
		lvProgress->Sort();


	}
	System::Void FormMain::btnStart_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(gcurthread==NULL)
		{
			// List<String^>^ inlines = gcnew List<String^>;
			TSTRINGVECTOR vinlines;
			String^ title = String::Empty;
			for each(String^ inl in txtInDir->Lines)
			{
				inl=inl->TrimStart();
				if(String::IsNullOrEmpty(inl))
					continue;

				try
				{
					System::IO::DirectoryInfo di(inl);
					if(!di.Exists)
					{
						if(System::Windows::Forms::DialogResult::Yes != MessageBox::Show(L"\"" + inl + L"\"" + L" does not exist.\r\nContinue?",
							Application::ProductName,
							MessageBoxButtons::YesNo,
							MessageBoxIcon::Question,
							MessageBoxDefaultButton::Button2))
						{
							return;
						}
					}
				}
				catch(System::Exception^ ex)
				{
					MessageBox::Show(ex->Message + L"\"" + inl + L"\"",
						Application::ProductName,
						MessageBoxButtons::OK,
						MessageBoxIcon::Exclamation);
					return;
				}
				// inlines->Add(inl);
				vinlines.push_back(getStdWstring(inl->TrimEnd(L'\\')));
				title += inl + "|";
			}
			title = title->TrimEnd('|');

			if(vinlines.size()==0)
			{
				MessageBox::Show(L"No Folders specified.",
					Application::ProductName,
					MessageBoxButtons::OK,
					MessageBoxIcon::Exclamation);
				return;
			}

			if(vinlines.size() < 2 && chkEachFolder->Checked)
			{
				MessageBox::Show(L"\"Find from each line\" is invalid when only one entry exists.",
					Application::ProductName,
					MessageBoxButtons::OK,
					MessageBoxIcon::Exclamation);
				return;

			}

			String^ namereg = cmbNameReg->Text;
			try
			{
				gcnew System::Text::RegularExpressions::Regex(namereg);
			}
			catch(System::Exception^ ex)
			{
				AmbLib::ExceptionMessageBox(ex);
				return;
			}

			ULL uminsize = 0;
			do
			{
				String^ text = cmbMinSize->Text;
				if(String::IsNullOrEmpty(text))
					break;

				Char lc = text[text->Length-1];
				ULL mul=1;
				if( L'0' <= lc && lc <= L'9')
				{
				
				}
				else
				{
					text = text->Substring(0, text->Length-1);
				
				
					switch(lc)
					{
						case L'k':mul=1000;   break;
						case L'K':mul=1024;   break;
						case L'm':mul=1000 * 1000;   break;
						case L'M':mul=1024 * 1024;   break;
						case L'g':mul=1000 * 1000 * 1000;   break;
						case L'G':mul=1024 * 1024 * 1024;   break;
						default:
						{
							MessageBox::Show(L"File size illegal.");
							return;
						}
						break;
					}
				}

				if(!System::UInt64::TryParse(text, uminsize))
				{
					MessageBox::Show(L"File size illegal.");
					return;
				}

				uminsize = uminsize * mul;
			} while(false);
			
			
			// checkdone


			lvProgress->Items->Clear();
			lvProgress->Groups->Clear();
			groupI_.Clear();
			frmError.lvError->Items->Clear();
			
			//LVDATA^ lvdata = (LVDATA^)lvProgress->Tag;
			//if(!lvdata)
			//{
			//	lvdata=gcnew LVDATA;
			//	lvProgress->Tag=lvdata;
			//}
			//lvdata->Clear();

			//LPCTSTR pDir = _tcsdup(_T("E:\\T\\10"));
			pin_ptr<const wchar_t> pWC = PtrToStringChars(namereg);
			THREADPASSDATA* pData = new THREADPASSDATA(
				0,
				NULL,
				(HWND)this->Handle.ToPointer(),
				0,
				&vinlines,
				pWC,
				uminsize,
				chkEachFolder->Checked);
			uintptr_t threadhandle = _beginthreadex(NULL, 0, startOfSearch, (void*)pData, CREATE_SUSPENDED, NULL);
			if(threadhandle==0)
			{
				MessageBox::Show(L"thread creation failed");
				return;
			}
			gthid++;
			gcurthread = (HANDLE)threadhandle;
			pData->thid_ = gthid;
			pData->thisthread_ = (HANDLE)threadhandle;
			DVERIFY_NOT(ResumeThread((HANDLE)threadhandle), 0xFFFFFFFF);
			
			ThreadOn(true);
			SetTitle(title);
			tabMain->SelectedTab= tbProgress;

		}
		else
		{
			try
			{
				SuspendThread(gcurthread); // (gcurthread,THREAD_PRIORITY_LOWEST);
				if(System::Windows::Forms::DialogResult::Yes != MessageBox::Show(I18NLS(L"Are you sure you want to cancel?"),
					Application::ProductName,
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question))
				{
					return;
				}
			}
			finally
			{
				ResumeThread(gcurthread);// SetThreadPriority(gcurthread,THREAD_PRIORITY_NORMAL);
			}
			CloseThread();

			ThreadOn(false);
		}
	}
		
	void FormMain::ThreadOn(bool on)
	{
		btnStart->Text = on ? L"&Cancel" : L"&Start";
	}
	

	System::Void FormMain::btnPause_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SuspendThread(gcurthread);
		bSuspended_ = true;
	}
	System::Void FormMain::btnResume_Click(System::Object^  sender, System::EventArgs^  e)
	{
		while(ResumeThread(gcurthread)>0)
			;
		bSuspended_ = false;
	}


	void FormMain::CloseThread()
	{
		if(gcurthread == NULL)
			return;

		Enabled=false;		
		Application::DoEvents();

		gthid++;
		while(ResumeThread(gcurthread)>0)
			;

		int waited=0;
		while(gcurthread != NULL && WAIT_TIMEOUT==WaitForSingleObject(gcurthread, 500))
		{
			Application::DoEvents();
			//if(waited++ > 10)
			//{
			//	TerminateThread(gcurthread, -1);
			//	break;
			//}
		}
		gcurthread=NULL;
		Enabled=true;
		DTRACE(L"Closing Done.");

	}
	System::Void FormMain::FormMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		e->Cancel=false;
		CloseThread();
		Application::Idle -= gcnew EventHandler(this, &FormMain::onIdle);
	}

		
	System::Void FormMain::btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ folder;
		browseFolder(this, Application::ProductName, folder);

		//if(System::Windows::Forms::DialogResult::OK != fbd_.ShowDialog())
		//	return;


		if(!txtInDir->Text->EndsWith(L"\n"))
			txtInDir->Text += L"\r\n";
		txtInDir->Text += folder + L"\r\n";
	}

	System::Void FormMain::explorerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{

		try
		{
			pin_ptr<const wchar_t> pIn = PtrToStringChars(lvProgress->SelectedItems[0]->Text);
			

			tstring arg;
			arg += _T("/select,\"");
			arg += pIn;
			arg += _T("\",/n");
#pragma comment(lib, "shell32.lib")
			ShellExecute((HWND)this->Handle.ToPointer(), _T("open"), _T("explorer.exe"), 
					arg.c_str()  ,NULL, SW_SHOW);
		}
		catch(System::Exception^ )
		{
			// ExceptionMessageBox(ex);
		}
		finally
		{
			
		}
	}
	
	System::Void FormMain::btnShowError_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(!frmError.Visible)
			frmError.Show();

		frmError.BringToFront();
	}

	System::Void FormMain::tsbRemoveNonExistFiles_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		for each(ListViewItem^ item in this->lvProgress->Items)
		{
			if(!System::IO::File::Exists(item->Text))
				lvProgress->Items->Remove(item);
		}
	}

	System::Void FormMain::linkHomepage_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
	{

	}
}