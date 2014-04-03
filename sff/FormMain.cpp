#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"

namespace sff {


	
	System::Void FormMain::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		txtResult->Text = String::Empty;
		txtResult->Enabled=false;

		LPCTSTR pDir = _tcsdup(_T("Y:\\download"));
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

	}

	void FormMain::WndProc(Message% m) 
	{
		switch( m.Msg )
		{
			case WM_APP_ADDLINE:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}
				
				String^ line = gcnew String((LPCTSTR)m.LParam.ToPointer());
				line += L"\r\n";
				txtResult->Text = txtResult->Text + line;
				m.Result=(IntPtr)1;
			
			}
			break;

			case WM_APP_ADDLINE2:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}
				
				CFileData* pFD = (CFileData*)m.LParam.ToPointer();
				String^ line = gcnew String(pFD->GetName());
				line += L"\r\n";
				txtResult->Text = txtResult->Text + line;
				m.Result=(IntPtr)1;							
			}
			break;

			case WM_APP_ADDSEPARATOR:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}

				if(id==gthid)
				{
					txtResult->Text += L"---------------------------------";				
				}

				m.Result=(IntPtr)1;

			}
			break;

			case WM_APP_SEARCHDONE:
			{
				Application::DoEvents();
				
				txtResult->Enabled=true;			
				
				gthid++;
				gcurthread = NULL;
			}
			break;

			default:
				Form::WndProc(m);
		}
	}
}