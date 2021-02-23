#pragma once
#include "OptListView.h"
#include "FormError.h"

namespace sff {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	private:
		void CloseThread();
		void ThreadOn(bool on);
		System::Windows::Forms::ContextMenuStrip ctxRecents_;
		property String^ IniPath
		{
			String^ get()
			{
				String^ dir = System::IO::Path::GetDirectoryName(System::Windows::Forms::Application::ExecutablePath);
				String^ filepart = System::IO::Path::GetFileNameWithoutExtension(System::Windows::Forms::Application::ExecutablePath);
				String^ ret = System::IO::Path::Combine(dir, filepart + ".ini");
				return ret;
			}
		}
		property String^ ToolsPath
		{
			String^ get()
			{
				String^ dir = System::IO::Path::GetDirectoryName(System::Windows::Forms::Application::ExecutablePath);
				String^ ret = System::IO::Path::Combine(dir, L"ExternalTools.xml");
				return ret;
			}
		}
		System::Windows::Forms::FolderBrowserDialog fbd_;
	private: System::Windows::Forms::StatusStrip^  ssMain;
	private: System::Windows::Forms::ToolStripStatusLabel^  slMain;
	private: System::Windows::Forms::ColumnHeader^  chFilename;
	private: System::Windows::Forms::ComboBox^  cmbNameReg;
	private: System::Windows::Forms::ComboBox^  cmbMinSize;
	private: System::Windows::Forms::ToolStrip^ tsList;

	private: System::Windows::Forms::ToolStripButton^  tsbRemoveNonExistFiles;
	private: System::Windows::Forms::ColumnHeader^  chDriveType;

	private: System::Windows::Forms::ToolStripStatusLabel^  slGroupCount;
	private: System::Windows::Forms::ToolStripStatusLabel^  slItemCount;



		FormError frmError;
	private: System::Windows::Forms::TabPage^  tbAbout;
	private: System::Windows::Forms::LinkLabel^  linkHomepage;
	private: System::Windows::Forms::Label^  lblVersion;
	private: System::Windows::Forms::CheckBox^  chkEachFolder;
	private: System::Windows::Forms::Label^ lblSize;

	private: System::Windows::Forms::Label^ lblFilter;

	private: System::Windows::Forms::Button^  btnRecents;
	private: System::Windows::Forms::MenuStrip^ menuMain;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiFile;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiExit;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiHelp;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiTools;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmiExternalTools;
	private: System::Windows::Forms::ToolStripMenuItem^ cmExternalTools;
	private: System::Windows::Forms::ToolStripMenuItem^ cmDummy;
	private: System::Windows::Forms::Button^ btnAnchor;





			 bool bSuspended_;

	protected:
		virtual void WndProc(Message% m) override = Control::WndProc;

		








	public:
		FormMain(System::Collections::Generic::List<String^>^ args);

	private:
		initonly System::Collections::Generic::List<String^>^ args_;
		initonly String^ orgShowErrorText_;


	private: System::Windows::Forms::TabControl^  tabMain;
	private: System::Windows::Forms::TabPage^  tpSettings;
	private: System::Windows::Forms::TabPage^  tbProgress;

	private: System::Windows::Forms::TextBox^  txtInDir;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::ContextMenuStrip^  cmList;
	private: System::Windows::Forms::ToolStripMenuItem^  explorerToolStripMenuItem;
	private: System::Windows::Forms::Button^  btnShowError;

	public: 

	private:
		List<ULL> groupI_;
	protected:
		/// <summary>
		/// 
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	protected: 

	protected: 

	protected: 


	private: System::Windows::Forms::ListView^  lvProgress;

	private: System::Windows::Forms::ColumnHeader^  chPath;
	private: System::Windows::Forms::ColumnHeader^  chSize;
	private: System::Windows::Forms::Button^  btnResume;
	private: System::Windows::Forms::Button^  btnPause;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// 
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// 
		/// </summary>
		void InitializeComponent(void);

#pragma endregion
	private:
		System::Collections::Generic::List<String^> recents_;

		void SetTitle(String^ addition);
		Miszou::ToolManager::Tools^ mTools;
		System::Void onIdle(System::Object^, System::EventArgs^);
		void AddtoDirs(... array<String^>^ folders);
		property bool IsThreadWorking
		{
			bool get();
		}
	protected:
		String^ ExpandToolMacros(String^ str);
		void BuildExternalToolMenu(ToolStripMenuItem^ item, int startindex);

	private: 
		System::Void FormMain_Load(System::Object^  sender, System::EventArgs^  e);

		System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void FormMain_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

		System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnResume_Click(System::Object^  sender, System::EventArgs^  e);



		 

		System::Void lvProgress_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e);
		System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void explorerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void btnShowError_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void tsbRemoveNonExistFiles_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void linkHomepage_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
		System::Void btnRecents_Click(System::Object^  sender, System::EventArgs^  e);

		void OnRecentItemClick(System::Object ^sender, System::EventArgs ^e);
		System::Void tsmiExit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void tsmiExternalTools_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void cmExternalTools_DropDownOpening(System::Object^ sender, System::EventArgs^ e);
		System::Void tpSettings_Resize(System::Object^ sender, System::EventArgs^ e);

};
	

}

