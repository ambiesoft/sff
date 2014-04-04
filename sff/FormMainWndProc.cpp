#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"
//#include "ListGroup.h"
#include "helper.h"

namespace sff {

	
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
				ListViewGroup^ lvg;//= ((LVDATA^)lvResult->Tag)->getGroup(pFD->GetLeng());

				if(!false)
				{
					lvg = lvResult->Groups[pFD->GetLeng().ToString()];
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
				

				
				LPCTSTR pGotName = pFD->GetName();
				String^ fullpath = gcnew String(pGotName);
				LPCTSTR pName = _tcsrchr(pGotName, _T('\\'));
				String^ name = pName?gcnew String(pName+1):String::Empty;

				ListViewItem^ item = gcnew ListViewItem(
								gcnew array<String^>
									{
										fullpath,
										pFD->GetLeng().ToString(),
										name
									}
								);
				
				{
					//ListViewItem::ListViewSubItem lvis;
					//lvis.Text=gcnew String();

					//lvi.SubItems->Add(%lvis);
				}
				item->Group=lvg;

				
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
				slMain->Text=progline;

				m.Result=(IntPtr)1;

			}
			break;

			case WM_APP_SEARCHDONE:
			{
				Application::DoEvents();
				

				slMain->Text=String::Empty;

				gthid++;
				gcurthread = NULL;
				ThreadOn(false);
			}
			break;

			case WM_APP_APIERROR:
			{
				DWORD id = (DWORD)m.WParam.ToInt32();
				APIERROR* ae = (APIERROR*)m.LParam.ToPointer();
				if(id!=gthid)
				{
					m.Result = (IntPtr)0;
					break;
				}

				ListViewItem^ item = gcnew ListViewItem(
				gcnew array<String^>
					{
						gcnew String(GetLastErrorString(ae->dwLE).c_str()),
						gcnew String(ae->pFile)

					}
				);

				frmError.lvError->Items->Add(item);
				m.Result=(IntPtr)1;
			}
			break;

			default:
				Form::WndProc(m);
		}
	}

}