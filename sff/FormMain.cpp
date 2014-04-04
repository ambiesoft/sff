#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"
//#include "ListGroup.h"

namespace sff {

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

	System::Void FormMain::FormMain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		ThreadOn(false);
	}

	System::Void FormMain::lvResult_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e)
	{
		lvResult->ListViewItemSorter =
			gcnew ListViewItemComparer(e->Column);
		lvResult->Sort();


	}
	System::Void FormMain::btnStart_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(gcurthread==NULL)
		{
			lvResult->Items->Clear();
			lvResult->Groups->Clear();
			groupI_.Clear();
			
			//LVDATA^ lvdata = (LVDATA^)lvResult->Tag;
			//if(!lvdata)
			//{
			//	lvdata=gcnew LVDATA;
			//	lvResult->Tag=lvdata;
			//}
			//lvdata->Clear();


			LPCTSTR pDir = _tcsdup(_T("E:\\T\\10"));
			//LPCTSTR pDir = _tcsdup(_T("Y:\\download"));
			THREADPASSDATA* pData = new THREADPASSDATA(
				0,
				NULL,
				(HWND)this->Handle.ToPointer(),
				0,
				pDir);
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
		}
	}
		
	void FormMain::ThreadOn(bool on)
	{
		btnStart->Enabled=!on;
		btnPause->Enabled=on;
		btnResume->Enabled=on;
	}
	
	void FormMain::WndProc(Message% m) 
	{
		switch( m.Msg )
		{
			//case WM_APP_ADDLINE:
			//{
			//	DWORD id = (DWORD)m.WParam.ToInt32();
			//	if(id!=gthid)
			//	{
			//		m.Result = (IntPtr)0;
			//		break;
			//	}
			//	
			//	String^ line = gcnew String((LPCTSTR)m.LParam.ToPointer());
			//	line += L"\r\n";
			//	txtResult->Text = txtResult->Text + line;
			//	m.Result=(IntPtr)1;
			//
			//}
			//break;

			case WM_APP_ADDLINE2:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}
				
				CFileData* pFD = (CFileData*)m.LParam.ToPointer();
				//ListViewGroup^ lvg= ((LVDATA^)lvResult->Tag)->getGroup(pFD->GetLeng());

				if(false)
				{
					ListViewGroup^ lvg = lvResult->Groups[pFD->GetLeng().ToString()];
					if ( !lvg )
					{
						lvg = gcnew ListViewGroup(pFD->GetLeng().ToString(), pFD->GetLeng().ToString());
						ULL len=pFD->GetLeng();
						DASSERT(!groupI_.Contains(len));
						lvResult->Groups->Add(lvg);
						groupI_.Add(len);
						groupI_.Sort();
						int index = groupI_.IndexOf(len);
						DASSERT(0 <= index);
						if(index==0)
						{
							lvResult->Groups->Insert(index,lvg);// Add(lvg);
						}
						else
						{
							//ULL prev = groupI_[index-1];
							//index = groupI_.IndexOf(prev);
							//DASSERT(0 <= index);
							index = lvResult->Groups->IndexOf(lvResult->Groups[index-1]);
							lvResult->Groups->Insert(index+1,lvg);// Add(lvg);
						}


					}
					else
					{
						lvg->Header = pFD->GetLeng().ToString();
					}
				}					
				

				

				ListViewItem^ item = gcnew ListViewItem(
								gcnew array<String^>
									{
										gcnew String(pFD->GetName()),
										pFD->GetLeng().ToString()
									}
								);
				
				{
					//ListViewItem::ListViewSubItem lvis;
					//lvis.Text=gcnew String();

					//lvi.SubItems->Add(%lvis);
				}
				//item->Group=lvg;

				
				lvResult->Items->Add(item);
				lvResult->Sort();
				

				m.Result=(IntPtr)1;							
			}
			break;

			//case WM_APP_ADDSEPARATOR:
			//{
			//	DWORD id = (DWORD)m.WParam.ToInt32();
			//	if(id!=gthid)
			//	{
			//		m.Result = (IntPtr)0;
			//		break;
			//	}

			//	txtResult->Text += L"---------------------------------";				

			//	m.Result=(IntPtr)1;

			//}
			//break;
			
			case WM_APP_ADDPROGRESS:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}

				String^ progline= gcnew String((LPCTSTR)m.LParam.ToPointer());
				lblProgress->Text=progline;

				m.Result=(IntPtr)1;

			}
			break;

			case WM_APP_SEARCHDONE:
			{
				Application::DoEvents();
				

				lblProgress->Text=String::Empty;

				gthid++;
				gcurthread = NULL;
				btnStart->Enabled=true;
			}
			break;

			default:
				Form::WndProc(m);
		}
	}

	System::Void FormMain::btnPause_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SuspendThread(gcurthread);
	}
	System::Void FormMain::btnResume_Click(System::Object^  sender, System::EventArgs^  e)
	{
		while(ResumeThread(gcurthread)>0)
			;
	}


	System::Void FormMain::FormMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{


		if(gcurthread == NULL)
			return;

		Enabled=false;		
		Application::DoEvents();

		gthid++;
		while(ResumeThread(gcurthread)>0)
			;

		while(gcurthread != NULL && WAIT_TIMEOUT==WaitForSingleObject(gcurthread, 500))
		{
			Application::DoEvents();
		}
		DTRACE(L"Closing Done.");
	}

}