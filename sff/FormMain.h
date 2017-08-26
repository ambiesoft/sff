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
	/// FormMain の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	private:
		void CloseThread();
		void ThreadOn(bool on);
		
		System::Windows::Forms::FolderBrowserDialog fbd_;
	private: System::Windows::Forms::StatusStrip^  ssMain;
	private: System::Windows::Forms::ToolStripStatusLabel^  slMain;
	private: System::Windows::Forms::ColumnHeader^  chFilename;
	private: System::Windows::Forms::ComboBox^  cmbNameReg;
	private: System::Windows::Forms::ComboBox^  cmbMinSize;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  tsbRemoveNonExistFiles;
	private: System::Windows::Forms::ColumnHeader^  chDriveType;

	private: System::Windows::Forms::ToolStripStatusLabel^  slGroupCount;
	private: System::Windows::Forms::ToolStripStatusLabel^  slItemCount;



		FormError frmError;
	private: System::Windows::Forms::TabPage^  tbAbout;
	private: System::Windows::Forms::LinkLabel^  linkHomepage;
	private: System::Windows::Forms::Label^  lblVersion;
	private: System::Windows::Forms::CheckBox^  chkEachFolder;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
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
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// 必要なデザイナ変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void);

#pragma endregion
	private:
		void SetTitle(String^ addition);
	private:
		System::Void onIdle(System::Object^, System::EventArgs^);
		

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

};
	

}

