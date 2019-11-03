#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "FormMain.h"
#include "FileData.h"
//#include "ListGroup.h"
#include "helper.h"

#include "../../lsMisc/GetLastErrorString.h"

using namespace Ambiesoft;

namespace sff {

	ref struct UpDate {
					ListView^ lv_;
					UpDate(ListView^ lv) {
						lv_=lv;
						lv_->BeginUpdate();
					}
					~UpDate() {
						lv_->EndUpdate();
					}
				};

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
				
				UpDate upDate(lvProgress);

				CFileData* pFD = (CFileData*)m.LParam.ToPointer();
				ListViewGroup^ lvg;//= ((LVDATA^)lvProgress->Tag)->getGroup(pFD->GetLeng());

				lvProgress->BeginUpdate();
				try
				{
					lvg = lvProgress->Groups[pFD->GetLeng().ToString()];
					if ( !lvg )
					{
						lvg = gcnew ListViewGroup(pFD->GetLeng().ToString(), GetBytelenFormatText(pFD->GetLeng()));
						ULL len=pFD->GetLeng();
						DASSERT(!groupI_.Contains(len));
						// lvProgress->Groups->Add(lvg);
						groupI_.Add(len);
						groupI_.Sort();
						int index = groupI_.IndexOf(len);
						DASSERT(0 <= index);
						if(index==0)
						{
							lvProgress->Groups->Insert(index,lvg);// Add(lvg);
						}
						else
						{
							//ULL prev = groupI_[index-1];
							//index = groupI_.IndexOf(prev);
							//DASSERT(0 <= index);
							index = lvProgress->Groups->IndexOf(lvProgress->Groups[index-1]);
							lvProgress->Groups->Insert(index+1,lvg);// Add(lvg);
						}
					}
					else
					{
						lvg->Header = GetBytelenFormatText(pFD->GetLeng());
					}
				}	
				finally
				{
					lvProgress->EndUpdate();
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

				
				
				lvProgress->Items->Add(item);
				

				//if(0!=lvProgress->SelectedItems->Count)
				//{
				//	ListViewItem^ lvic = lvProgress->SelectedItems[0];
				//	System::Drawing::Size s = lvProgress->Size;
				//	System::Drawing::Rectangle r = lvic->Bounds;
				//	if(r.Y > 0 && r.Y < s.Height)
				//	{
				//		lvic->EnsureVisible();
				//	}
				//}
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
				DWORD id = (DWORD)m.WParam.ToInt32();

				slMain->Text=String::Empty;

				bool bRealDone = id==gthid;
				gthid++;
				gcurthread = NULL;
				ThreadOn(false);
				if(bRealDone)
				{
					CppUtils::Info(this, I18N(L"Done"));
				}
				btnShowError->Text = orgShowErrorText_ + " : " +  frmError.getErrorCount().ToString();
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