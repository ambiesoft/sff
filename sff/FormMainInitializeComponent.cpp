#include "stdafx.h"
#include "FormMain.h"
#include "OptListView.h"

namespace sff {

	// this->lvResult = (gcnew OptListView());
	// this->lvResult = (gcnew System::Windows::Forms::ListView());

	void FormMain::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
		this->btnStart = (gcnew System::Windows::Forms::Button());
		this->spRoot = (gcnew System::Windows::Forms::SplitContainer());
		this->tabMain = (gcnew System::Windows::Forms::TabControl());
		this->tpSettings = (gcnew System::Windows::Forms::TabPage());
		this->cmbMinSize = (gcnew System::Windows::Forms::ComboBox());
		this->cmbNameReg = (gcnew System::Windows::Forms::ComboBox());
		this->txtInDir = (gcnew System::Windows::Forms::TextBox());
		this->btnAdd = (gcnew System::Windows::Forms::Button());
		this->tbResult = (gcnew System::Windows::Forms::TabPage());
		this->lvResult = (gcnew System::Windows::Forms::ListView());
		this->chPath = (gcnew System::Windows::Forms::ColumnHeader());
		this->chSize = (gcnew System::Windows::Forms::ColumnHeader());
		this->chFilename = (gcnew System::Windows::Forms::ColumnHeader());
		this->chDriveType = (gcnew System::Windows::Forms::ColumnHeader());
		this->cmList = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->explorerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
		this->tsbRemoveNonExistFiles = (gcnew System::Windows::Forms::ToolStripButton());
		this->spBottom = (gcnew System::Windows::Forms::SplitContainer());
		this->btnShowError = (gcnew System::Windows::Forms::Button());
		this->btnPause = (gcnew System::Windows::Forms::Button());
		this->btnResume = (gcnew System::Windows::Forms::Button());
		this->ssMain = (gcnew System::Windows::Forms::StatusStrip());
		this->slMain = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->slGroupCount = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->slItemCount = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->spRoot->Panel1->SuspendLayout();
		this->spRoot->Panel2->SuspendLayout();
		this->spRoot->SuspendLayout();
		this->tabMain->SuspendLayout();
		this->tpSettings->SuspendLayout();
		this->tbResult->SuspendLayout();
		this->cmList->SuspendLayout();
		this->toolStrip1->SuspendLayout();
		this->spBottom->Panel1->SuspendLayout();
		this->spBottom->Panel2->SuspendLayout();
		this->spBottom->SuspendLayout();
		this->ssMain->SuspendLayout();
		this->SuspendLayout();
		// 
		// btnStart
		// 
		this->btnStart->Location = System::Drawing::Point(3, 8);
		this->btnStart->Name = L"btnStart";
		this->btnStart->Size = System::Drawing::Size(114, 41);
		this->btnStart->TabIndex = 0;
		this->btnStart->Text = L"&Start";
		this->btnStart->UseVisualStyleBackColor = true;
		this->btnStart->Click += gcnew System::EventHandler(this, &FormMain::btnStart_Click);
		// 
		// spRoot
		// 
		this->spRoot->Dock = System::Windows::Forms::DockStyle::Fill;
		this->spRoot->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
		this->spRoot->IsSplitterFixed = true;
		this->spRoot->Location = System::Drawing::Point(0, 0);
		this->spRoot->Name = L"spRoot";
		this->spRoot->Orientation = System::Windows::Forms::Orientation::Horizontal;
		// 
		// spRoot.Panel1
		// 
		this->spRoot->Panel1->Controls->Add(this->tabMain);
		// 
		// spRoot.Panel2
		// 
		this->spRoot->Panel2->Controls->Add(this->spBottom);
		this->spRoot->Size = System::Drawing::Size(688, 389);
		this->spRoot->SplitterDistance = 330;
		this->spRoot->TabIndex = 2;
		// 
		// tabMain
		// 
		this->tabMain->Controls->Add(this->tpSettings);
		this->tabMain->Controls->Add(this->tbResult);
		this->tabMain->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tabMain->Location = System::Drawing::Point(0, 0);
		this->tabMain->Name = L"tabMain";
		this->tabMain->SelectedIndex = 0;
		this->tabMain->Size = System::Drawing::Size(688, 330);
		this->tabMain->TabIndex = 1;
		// 
		// tpSettings
		// 
		this->tpSettings->Controls->Add(this->cmbMinSize);
		this->tpSettings->Controls->Add(this->cmbNameReg);
		this->tpSettings->Controls->Add(this->txtInDir);
		this->tpSettings->Controls->Add(this->btnAdd);
		this->tpSettings->Location = System::Drawing::Point(4, 22);
		this->tpSettings->Name = L"tpSettings";
		this->tpSettings->Padding = System::Windows::Forms::Padding(3);
		this->tpSettings->Size = System::Drawing::Size(680, 304);
		this->tpSettings->TabIndex = 0;
		this->tpSettings->Text = L"Settings";
		this->tpSettings->UseVisualStyleBackColor = true;
		// 
		// cmbMinSize
		// 
		this->cmbMinSize->FormattingEnabled = true;
		this->cmbMinSize->Location = System::Drawing::Point(16, 219);
		this->cmbMinSize->Name = L"cmbMinSize";
		this->cmbMinSize->Size = System::Drawing::Size(145, 21);
		this->cmbMinSize->TabIndex = 2;
		// 
		// cmbNameReg
		// 
		this->cmbNameReg->FormattingEnabled = true;
		this->cmbNameReg->Location = System::Drawing::Point(16, 178);
		this->cmbNameReg->Name = L"cmbNameReg";
		this->cmbNameReg->Size = System::Drawing::Size(145, 21);
		this->cmbNameReg->TabIndex = 2;
		// 
		// txtInDir
		// 
		this->txtInDir->Location = System::Drawing::Point(16, 27);
		this->txtInDir->Multiline = true;
		this->txtInDir->Name = L"txtInDir";
		this->txtInDir->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->txtInDir->Size = System::Drawing::Size(269, 144);
		this->txtInDir->TabIndex = 1;
		// 
		// btnAdd
		// 
		this->btnAdd->Location = System::Drawing::Point(294, 41);
		this->btnAdd->Name = L"btnAdd";
		this->btnAdd->Size = System::Drawing::Size(81, 33);
		this->btnAdd->TabIndex = 0;
		this->btnAdd->Text = L"button1";
		this->btnAdd->UseVisualStyleBackColor = true;
		this->btnAdd->Click += gcnew System::EventHandler(this, &FormMain::btnAdd_Click);
		// 
		// tbResult
		// 
		this->tbResult->Controls->Add(this->lvResult);
		this->tbResult->Controls->Add(this->toolStrip1);
		this->tbResult->Location = System::Drawing::Point(4, 22);
		this->tbResult->Name = L"tbResult";
		this->tbResult->Padding = System::Windows::Forms::Padding(3);
		this->tbResult->Size = System::Drawing::Size(680, 297);
		this->tbResult->TabIndex = 1;
		this->tbResult->Text = L"Result";
		this->tbResult->UseVisualStyleBackColor = true;
		// 
		// lvResult
		// 
		this->lvResult->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->chPath, this->chSize, 
			this->chFilename, this->chDriveType});
		this->lvResult->ContextMenuStrip = this->cmList;
		this->lvResult->Dock = System::Windows::Forms::DockStyle::Fill;
		this->lvResult->FullRowSelect = true;
		this->lvResult->GridLines = true;
		this->lvResult->HideSelection = false;
		this->lvResult->Location = System::Drawing::Point(3, 28);
		this->lvResult->Name = L"lvResult";
		this->lvResult->Size = System::Drawing::Size(674, 266);
		this->lvResult->TabIndex = 0;
		this->lvResult->UseCompatibleStateImageBehavior = false;
		this->lvResult->View = System::Windows::Forms::View::Details;
		this->lvResult->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &FormMain::lvResult_ColumnClick);
		// 
		// chPath
		// 
		this->chPath->Text = L"FullPath";
		this->chPath->Width = 410;
		// 
		// chSize
		// 
		this->chSize->Text = L"Size";
		this->chSize->Width = 101;
		// 
		// chFilename
		// 
		this->chFilename->Text = L"Name";
		this->chFilename->Width = 135;
		// 
		// cmList
		// 
		this->cmList->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->explorerToolStripMenuItem});
		this->cmList->Name = L"cmList";
		this->cmList->Size = System::Drawing::Size(122, 26);
		// 
		// explorerToolStripMenuItem
		// 
		this->explorerToolStripMenuItem->Name = L"explorerToolStripMenuItem";
		this->explorerToolStripMenuItem->Size = System::Drawing::Size(121, 22);
		this->explorerToolStripMenuItem->Text = L"&Explorer...";
		this->explorerToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::explorerToolStripMenuItem_Click);
		// 
		// toolStrip1
		// 
		this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->tsbRemoveNonExistFiles});
		this->toolStrip1->Location = System::Drawing::Point(3, 3);
		this->toolStrip1->Name = L"toolStrip1";
		this->toolStrip1->Size = System::Drawing::Size(674, 25);
		this->toolStrip1->TabIndex = 1;
		this->toolStrip1->Text = L"toolStrip1";
		// 
		// tsbRemoveNonExistFiles
		// 
		this->tsbRemoveNonExistFiles->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->tsbRemoveNonExistFiles->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsbRemoveNonExistFiles.Image")));
		this->tsbRemoveNonExistFiles->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->tsbRemoveNonExistFiles->Name = L"tsbRemoveNonExistFiles";
		this->tsbRemoveNonExistFiles->Size = System::Drawing::Size(23, 22);
		this->tsbRemoveNonExistFiles->Text = L"Remove Non Exist Files";
		this->tsbRemoveNonExistFiles->Click += gcnew System::EventHandler(this, &FormMain::tsbRemoveNonExistFiles_Click);
		// 
		// spBottom
		// 
		this->spBottom->Dock = System::Windows::Forms::DockStyle::Fill;
		this->spBottom->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
		this->spBottom->IsSplitterFixed = true;
		this->spBottom->Location = System::Drawing::Point(0, 0);
		this->spBottom->Name = L"spBottom";
		// 
		// spBottom.Panel1
		// 
		this->spBottom->Panel1->Controls->Add(this->btnShowError);
		// 
		// spBottom.Panel2
		// 
		this->spBottom->Panel2->Controls->Add(this->btnPause);
		this->spBottom->Panel2->Controls->Add(this->btnResume);
		this->spBottom->Panel2->Controls->Add(this->btnStart);
		this->spBottom->Size = System::Drawing::Size(688, 55);
		this->spBottom->SplitterDistance = 392;
		this->spBottom->TabIndex = 4;
		// 
		// btnShowError
		// 
		this->btnShowError->Location = System::Drawing::Point(4, 8);
		this->btnShowError->Name = L"btnShowError";
		this->btnShowError->Size = System::Drawing::Size(75, 41);
		this->btnShowError->TabIndex = 2;
		this->btnShowError->Text = L"&Error";
		this->btnShowError->UseVisualStyleBackColor = true;
		this->btnShowError->Click += gcnew System::EventHandler(this, &FormMain::btnShowError_Click);
		// 
		// btnPause
		// 
		this->btnPause->Location = System::Drawing::Point(204, 8);
		this->btnPause->Name = L"btnPause";
		this->btnPause->Size = System::Drawing::Size(75, 41);
		this->btnPause->TabIndex = 2;
		this->btnPause->Text = L"&Pause";
		this->btnPause->UseVisualStyleBackColor = true;
		this->btnPause->Click += gcnew System::EventHandler(this, &FormMain::btnPause_Click);
		// 
		// btnResume
		// 
		this->btnResume->Location = System::Drawing::Point(123, 8);
		this->btnResume->Name = L"btnResume";
		this->btnResume->Size = System::Drawing::Size(75, 41);
		this->btnResume->TabIndex = 3;
		this->btnResume->Text = L"&Resume";
		this->btnResume->UseVisualStyleBackColor = true;
		this->btnResume->Click += gcnew System::EventHandler(this, &FormMain::btnResume_Click);
		// 
		// ssMain
		// 
		this->ssMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->slMain, this->slGroupCount, 
			this->slItemCount});
		this->ssMain->Location = System::Drawing::Point(0, 389);
		this->ssMain->Name = L"ssMain";
		this->ssMain->Size = System::Drawing::Size(688, 22);
		this->ssMain->TabIndex = 3;
		// 
		// slMain
		// 
		this->slMain->Name = L"slMain";
		this->slMain->Size = System::Drawing::Size(551, 17);
		this->slMain->Spring = true;
		// 
		// slGroupCount
		// 
		this->slGroupCount->Name = L"slGroupCount";
		this->slGroupCount->Size = System::Drawing::Size(50, 17);
		this->slGroupCount->Text = L"Groups : ";
		// 
		// slItemCount
		// 
		this->slItemCount->Name = L"slItemCount";
		this->slItemCount->Size = System::Drawing::Size(41, 17);
		this->slItemCount->Text = L"Items : ";
		// 
		// FormMain
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(688, 411);
		this->Controls->Add(this->spRoot);
		this->Controls->Add(this->ssMain);
		this->Name = L"FormMain";
		this->Text = L"FormMain";
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormMain::FormMain_FormClosing);
		this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
		this->spRoot->Panel1->ResumeLayout(false);
		this->spRoot->Panel2->ResumeLayout(false);
		this->spRoot->ResumeLayout(false);
		this->tabMain->ResumeLayout(false);
		this->tpSettings->ResumeLayout(false);
		this->tpSettings->PerformLayout();
		this->tbResult->ResumeLayout(false);
		this->tbResult->PerformLayout();
		this->cmList->ResumeLayout(false);
		this->toolStrip1->ResumeLayout(false);
		this->toolStrip1->PerformLayout();
		this->spBottom->Panel1->ResumeLayout(false);
		this->spBottom->Panel2->ResumeLayout(false);
		this->spBottom->ResumeLayout(false);
		this->ssMain->ResumeLayout(false);
		this->ssMain->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}


}