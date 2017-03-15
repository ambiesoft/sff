#include "stdafx.h"
#include "FormMain.h"
#include "OptListView.h"

namespace sff {

	// this->lvProgress = (gcnew OptListView());
	// this->lvProgress = (gcnew System::Windows::Forms::ListView());

	void FormMain::InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
		this->btnStart = (gcnew System::Windows::Forms::Button());
		this->tabMain = (gcnew System::Windows::Forms::TabControl());
		this->tpSettings = (gcnew System::Windows::Forms::TabPage());
		this->cmbMinSize = (gcnew System::Windows::Forms::ComboBox());
		this->cmbNameReg = (gcnew System::Windows::Forms::ComboBox());
		this->txtInDir = (gcnew System::Windows::Forms::TextBox());
		this->btnAdd = (gcnew System::Windows::Forms::Button());
		this->tbProgress = (gcnew System::Windows::Forms::TabPage());
		this->lvProgress = (gcnew System::Windows::Forms::ListView());
		this->chPath = (gcnew System::Windows::Forms::ColumnHeader());
		this->chSize = (gcnew System::Windows::Forms::ColumnHeader());
		this->chFilename = (gcnew System::Windows::Forms::ColumnHeader());
		this->chDriveType = (gcnew System::Windows::Forms::ColumnHeader());
		this->cmList = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->explorerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
		this->tsbRemoveNonExistFiles = (gcnew System::Windows::Forms::ToolStripButton());
		this->tbAbout = (gcnew System::Windows::Forms::TabPage());
		this->linkHomepage = (gcnew System::Windows::Forms::LinkLabel());
		this->lblVersion = (gcnew System::Windows::Forms::Label());
		this->btnShowError = (gcnew System::Windows::Forms::Button());
		this->btnPause = (gcnew System::Windows::Forms::Button());
		this->btnResume = (gcnew System::Windows::Forms::Button());
		this->ssMain = (gcnew System::Windows::Forms::StatusStrip());
		this->slMain = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->slGroupCount = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->slItemCount = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->chkEachFolder = (gcnew System::Windows::Forms::CheckBox());
		this->tabMain->SuspendLayout();
		this->tpSettings->SuspendLayout();
		this->tbProgress->SuspendLayout();
		this->cmList->SuspendLayout();
		this->toolStrip1->SuspendLayout();
		this->tbAbout->SuspendLayout();
		this->ssMain->SuspendLayout();
		this->SuspendLayout();
		// 
		// btnStart
		// 
		this->btnStart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->btnStart->Location = System::Drawing::Point(408, 316);
		this->btnStart->Name = L"btnStart";
		this->btnStart->Size = System::Drawing::Size(114, 38);
		this->btnStart->TabIndex = 0;
		this->btnStart->Text = L"&Start";
		this->btnStart->UseVisualStyleBackColor = true;
		this->btnStart->Click += gcnew System::EventHandler(this, &FormMain::btnStart_Click);
		// 
		// tabMain
		// 
		this->tabMain->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->tabMain->Controls->Add(this->tpSettings);
		this->tabMain->Controls->Add(this->tbProgress);
		this->tabMain->Controls->Add(this->tbAbout);
		this->tabMain->Location = System::Drawing::Point(4, 5);
		this->tabMain->Name = L"tabMain";
		this->tabMain->SelectedIndex = 0;
		this->tabMain->Size = System::Drawing::Size(684, 305);
		this->tabMain->TabIndex = 1;
		// 
		// tpSettings
		// 
		this->tpSettings->Controls->Add(this->chkEachFolder);
		this->tpSettings->Controls->Add(this->label2);
		this->tpSettings->Controls->Add(this->label1);
		this->tpSettings->Controls->Add(this->cmbMinSize);
		this->tpSettings->Controls->Add(this->cmbNameReg);
		this->tpSettings->Controls->Add(this->txtInDir);
		this->tpSettings->Controls->Add(this->btnAdd);
		this->tpSettings->Location = System::Drawing::Point(4, 21);
		this->tpSettings->Name = L"tpSettings";
		this->tpSettings->Padding = System::Windows::Forms::Padding(3);
		this->tpSettings->Size = System::Drawing::Size(676, 280);
		this->tpSettings->TabIndex = 0;
		this->tpSettings->Text = L"Settings";
		this->tpSettings->UseVisualStyleBackColor = true;
		// 
		// cmbMinSize
		// 
		this->cmbMinSize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->cmbMinSize->FormattingEnabled = true;
		this->cmbMinSize->Location = System::Drawing::Point(54, 202);
		this->cmbMinSize->Name = L"cmbMinSize";
		this->cmbMinSize->Size = System::Drawing::Size(145, 20);
		this->cmbMinSize->TabIndex = 2;
		// 
		// cmbNameReg
		// 
		this->cmbNameReg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->cmbNameReg->FormattingEnabled = true;
		this->cmbNameReg->Location = System::Drawing::Point(54, 176);
		this->cmbNameReg->Name = L"cmbNameReg";
		this->cmbNameReg->Size = System::Drawing::Size(145, 20);
		this->cmbNameReg->TabIndex = 2;
		// 
		// txtInDir
		// 
		this->txtInDir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->txtInDir->Location = System::Drawing::Point(6, 6);
		this->txtInDir->Multiline = true;
		this->txtInDir->Name = L"txtInDir";
		this->txtInDir->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->txtInDir->Size = System::Drawing::Size(568, 164);
		this->txtInDir->TabIndex = 1;
		// 
		// btnAdd
		// 
		this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->btnAdd->Location = System::Drawing::Point(592, 6);
		this->btnAdd->Name = L"btnAdd";
		this->btnAdd->Size = System::Drawing::Size(81, 30);
		this->btnAdd->TabIndex = 0;
		this->btnAdd->Text = L"button1";
		this->btnAdd->UseVisualStyleBackColor = true;
		this->btnAdd->Click += gcnew System::EventHandler(this, &FormMain::btnAdd_Click);
		// 
		// tbProgress
		// 
		this->tbProgress->Controls->Add(this->lvProgress);
		this->tbProgress->Controls->Add(this->toolStrip1);
		this->tbProgress->Location = System::Drawing::Point(4, 21);
		this->tbProgress->Name = L"tbProgress";
		this->tbProgress->Padding = System::Windows::Forms::Padding(3);
		this->tbProgress->Size = System::Drawing::Size(676, 280);
		this->tbProgress->TabIndex = 1;
		this->tbProgress->Text = L"Progress";
		this->tbProgress->UseVisualStyleBackColor = true;
		// 
		// lvProgress
		// 
		this->lvProgress->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->chPath, this->chSize, 
			this->chFilename, this->chDriveType});
		this->lvProgress->ContextMenuStrip = this->cmList;
		this->lvProgress->Dock = System::Windows::Forms::DockStyle::Fill;
		this->lvProgress->FullRowSelect = true;
		this->lvProgress->GridLines = true;
		this->lvProgress->HideSelection = false;
		this->lvProgress->Location = System::Drawing::Point(3, 28);
		this->lvProgress->Name = L"lvProgress";
		this->lvProgress->Size = System::Drawing::Size(670, 249);
		this->lvProgress->TabIndex = 0;
		this->lvProgress->UseCompatibleStateImageBehavior = false;
		this->lvProgress->View = System::Windows::Forms::View::Details;
		this->lvProgress->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &FormMain::lvProgress_ColumnClick);
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
		this->cmList->Size = System::Drawing::Size(119, 26);
		// 
		// explorerToolStripMenuItem
		// 
		this->explorerToolStripMenuItem->Name = L"explorerToolStripMenuItem";
		this->explorerToolStripMenuItem->Size = System::Drawing::Size(118, 22);
		this->explorerToolStripMenuItem->Text = L"&Explorer...";
		this->explorerToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::explorerToolStripMenuItem_Click);
		// 
		// toolStrip1
		// 
		this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->tsbRemoveNonExistFiles});
		this->toolStrip1->Location = System::Drawing::Point(3, 3);
		this->toolStrip1->Name = L"toolStrip1";
		this->toolStrip1->Size = System::Drawing::Size(670, 25);
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
		// tbAbout
		// 
		this->tbAbout->Controls->Add(this->linkHomepage);
		this->tbAbout->Controls->Add(this->lblVersion);
		this->tbAbout->Location = System::Drawing::Point(4, 21);
		this->tbAbout->Name = L"tbAbout";
		this->tbAbout->Size = System::Drawing::Size(680, 160);
		this->tbAbout->TabIndex = 2;
		this->tbAbout->Text = L"About";
		this->tbAbout->UseVisualStyleBackColor = true;
		// 
		// linkHomepage
		// 
		this->linkHomepage->AutoSize = true;
		this->linkHomepage->Location = System::Drawing::Point(8, 25);
		this->linkHomepage->Name = L"linkHomepage";
		this->linkHomepage->Size = System::Drawing::Size(88, 12);
		this->linkHomepage->TabIndex = 1;
		this->linkHomepage->TabStop = true;
		this->linkHomepage->Text = L"Go to homepage";
		this->linkHomepage->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormMain::linkHomepage_LinkClicked);
		// 
		// lblVersion
		// 
		this->lblVersion->AutoSize = true;
		this->lblVersion->Location = System::Drawing::Point(8, 13);
		this->lblVersion->Name = L"lblVersion";
		this->lblVersion->Size = System::Drawing::Size(64, 12);
		this->lblVersion->TabIndex = 0;
		this->lblVersion->Text = L"SFF ver 0.1";
		// 
		// btnShowError
		// 
		this->btnShowError->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->btnShowError->Location = System::Drawing::Point(4, 316);
		this->btnShowError->Name = L"btnShowError";
		this->btnShowError->Size = System::Drawing::Size(75, 38);
		this->btnShowError->TabIndex = 2;
		this->btnShowError->Text = L"&Error";
		this->btnShowError->UseVisualStyleBackColor = true;
		this->btnShowError->Click += gcnew System::EventHandler(this, &FormMain::btnShowError_Click);
		// 
		// btnPause
		// 
		this->btnPause->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->btnPause->Location = System::Drawing::Point(609, 316);
		this->btnPause->Name = L"btnPause";
		this->btnPause->Size = System::Drawing::Size(75, 38);
		this->btnPause->TabIndex = 2;
		this->btnPause->Text = L"&Pause";
		this->btnPause->UseVisualStyleBackColor = true;
		this->btnPause->Click += gcnew System::EventHandler(this, &FormMain::btnPause_Click);
		// 
		// btnResume
		// 
		this->btnResume->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->btnResume->Location = System::Drawing::Point(528, 316);
		this->btnResume->Name = L"btnResume";
		this->btnResume->Size = System::Drawing::Size(75, 38);
		this->btnResume->TabIndex = 3;
		this->btnResume->Text = L"&Resume";
		this->btnResume->UseVisualStyleBackColor = true;
		this->btnResume->Click += gcnew System::EventHandler(this, &FormMain::btnResume_Click);
		// 
		// ssMain
		// 
		this->ssMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->slMain, this->slGroupCount, 
			this->slItemCount});
		this->ssMain->Location = System::Drawing::Point(0, 357);
		this->ssMain->Name = L"ssMain";
		this->ssMain->Size = System::Drawing::Size(688, 22);
		this->ssMain->TabIndex = 3;
		// 
		// slMain
		// 
		this->slMain->Name = L"slMain";
		this->slMain->Size = System::Drawing::Size(548, 17);
		this->slMain->Spring = true;
		this->slMain->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// slGroupCount
		// 
		this->slGroupCount->Name = L"slGroupCount";
		this->slGroupCount->Size = System::Drawing::Size(51, 17);
		this->slGroupCount->Text = L"Groups : ";
		// 
		// slItemCount
		// 
		this->slItemCount->Name = L"slItemCount";
		this->slItemCount->Size = System::Drawing::Size(43, 17);
		this->slItemCount->Text = L"Items : ";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(14, 179);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(34, 12);
		this->label1->TabIndex = 3;
		this->label1->Text = L"&Filter:";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(14, 205);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(28, 12);
		this->label2->TabIndex = 4;
		this->label2->Text = L"&Size:";
		// 
		// chkEachFolder
		// 
		this->chkEachFolder->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->chkEachFolder->AutoSize = true;
		this->chkEachFolder->Location = System::Drawing::Point(16, 237);
		this->chkEachFolder->Name = L"chkEachFolder";
		this->chkEachFolder->Size = System::Drawing::Size(131, 16);
		this->chkEachFolder->TabIndex = 5;
		this->chkEachFolder->Text = L"Find from &each entry";
		this->chkEachFolder->UseVisualStyleBackColor = true;
		// 
		// FormMain
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(688, 379);
		this->Controls->Add(this->tabMain);
		this->Controls->Add(this->btnResume);
		this->Controls->Add(this->btnPause);
		this->Controls->Add(this->btnShowError);
		this->Controls->Add(this->btnStart);
		this->Controls->Add(this->ssMain);
		this->Name = L"FormMain";
		this->Text = L"FormMain";
		this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormMain::FormMain_FormClosing);
		this->tabMain->ResumeLayout(false);
		this->tpSettings->ResumeLayout(false);
		this->tpSettings->PerformLayout();
		this->tbProgress->ResumeLayout(false);
		this->tbProgress->PerformLayout();
		this->cmList->ResumeLayout(false);
		this->toolStrip1->ResumeLayout(false);
		this->toolStrip1->PerformLayout();
		this->tbAbout->ResumeLayout(false);
		this->tbAbout->PerformLayout();
		this->ssMain->ResumeLayout(false);
		this->ssMain->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}


}