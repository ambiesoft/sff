#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"
#include "ListGroup.h"

namespace sff {


	System::Void FormMain::FormMain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		ThreadOn(false);
	}

	System::Void FormMain::btnStart_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if(gcurthread==NULL)
		{
			lvResult->Items->Clear();
			LVDATA^ lvdata = (LVDATA^)lvResult->Tag;
			if(!lvdata)
			{
				lvdata=gcnew LVDATA;
				lvResult->Tag=lvdata;
			}
			lvdata->Clear();


			LPCTSTR pDir = _tcsdup(_T("z:"));
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

				ListViewGroup^ lvg = lvResult->Groups[pFD->GetLeng().ToString()];
				if ( !lvg )
				{
					lvg = gcnew ListViewGroup(pFD->GetLeng().ToString(), pFD->GetLeng().ToString());
					lvResult->Groups->Add(lvg);
				}
				else
				{
					lvg->Header = pFD->GetLeng().ToString();
				}
				lvResult->Groups->Add(lvg);


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
				item->Group=lvg;

				lvResult->Items->Add(item);
				

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