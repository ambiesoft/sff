#include "stdafx.h"
#include "work.h"
#include "FormMain.h"


namespace sff {


	
	System::Void FormMain::button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		txtResult->Text = String::Empty;
		try
		{
			UINT oldmode = SetErrorMode(SEM_FAILCRITICALERRORS);
			dowork(_T("y:\\download"));
			dowork(_T("z:\\download"));
			dowork(_T("E:\\Movie"));
			
			//dowork(_T("z:"));
			//dowork(_T("X:"));
			SetErrorMode(oldmode);
		}
		catch(LPCTSTR pError)
		{
			MessageBox::Show(gcnew String(pError),
				Application::ProductName,
				MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}
		catch(System::Exception^ ex)
		{
			MessageBox::Show(ex->Message,
				Application::ProductName,
				MessageBoxButtons::OK,
				MessageBoxIcon::Asterisk);
		}

		String^ result = getResult();
		txtResult->Text = result;
	
		clearwork();
	}

}