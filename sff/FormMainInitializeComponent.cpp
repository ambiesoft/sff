#include "stdafx.h"
#include "FormMain.h"

namespace sff {

	// this->lvResult = (gcnew OptListView());
	// this->lvResult = (gcnew System::Windows::Forms::ListView());

	void FormMain::InitializeComponent(void)
	{
		this->btnStart = (gcnew System::Windows::Forms::Button());
		this->spRoot = (gcnew System::Windows::Forms::SplitContainer());
		this->lvResult = (gcnew System::Windows::Forms::ListView());
		this->chPath = (gcnew System::Windows::Forms::ColumnHeader());
		this->chSize = (gcnew System::Windows::Forms::ColumnHeader());
		this->btnResume = (gcnew System::Windows::Forms::Button());
		this->btnPause = (gcnew System::Windows::Forms::Button());
		this->lblProgress = (gcnew System::Windows::Forms::Label());
		this->spRoot->Panel1->SuspendLayout();
		this->spRoot->Panel2->SuspendLayout();
		this->spRoot->SuspendLayout();
		this->SuspendLayout();
		// 
		// btnStart
		// 
		this->btnStart->Location = System::Drawing::Point(400, 7);
		this->btnStart->Name = L"btnStart";
		this->btnStart->Size = System::Drawing::Size(114, 38);
		this->btnStart->TabIndex = 0;
		this->btnStart->Text = L"&Start";
		this->btnStart->UseVisualStyleBackColor = true;
		this->btnStart->Click += gcnew System::EventHandler(this, &FormMain::btnStart_Click);
		// 
		// spRoot
		// 
		this->spRoot->Dock = System::Windows::Forms::DockStyle::Fill;
		this->spRoot->Location = System::Drawing::Point(0, 0);
		this->spRoot->Name = L"spRoot";
		this->spRoot->Orientation = System::Windows::Forms::Orientation::Horizontal;
		// 
		// spRoot.Panel1
		// 
		this->spRoot->Panel1->Controls->Add(this->lvResult);
		// 
		// spRoot.Panel2
		// 
		this->spRoot->Panel2->Controls->Add(this->btnResume);
		this->spRoot->Panel2->Controls->Add(this->btnPause);
		this->spRoot->Panel2->Controls->Add(this->lblProgress);
		this->spRoot->Panel2->Controls->Add(this->btnStart);
		this->spRoot->Size = System::Drawing::Size(688, 379);
		this->spRoot->SplitterDistance = 320;
		this->spRoot->TabIndex = 2;
		// 
		// lvResult
		// 
		this->lvResult->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->chPath, this->chSize});
		this->lvResult->Dock = System::Windows::Forms::DockStyle::Fill;
		this->lvResult->Location = System::Drawing::Point(0, 0);
		this->lvResult->Name = L"lvResult";
		this->lvResult->Size = System::Drawing::Size(688, 320);
		this->lvResult->TabIndex = 0;
		this->lvResult->UseCompatibleStateImageBehavior = false;
		this->lvResult->View = System::Windows::Forms::View::Details;
		this->lvResult->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &FormMain::lvResult_ColumnClick);
		// 
		// chPath
		// 
		this->chPath->Text = L"Path";
		this->chPath->Width = 410;
		// 
		// chSize
		// 
		this->chSize->Text = L"Size";
		this->chSize->Width = 183;
		// 
		// btnResume
		// 
		this->btnResume->Location = System::Drawing::Point(520, 7);
		this->btnResume->Name = L"btnResume";
		this->btnResume->Size = System::Drawing::Size(75, 38);
		this->btnResume->TabIndex = 3;
		this->btnResume->Text = L"&Resume";
		this->btnResume->UseVisualStyleBackColor = true;
		this->btnResume->Click += gcnew System::EventHandler(this, &FormMain::btnResume_Click);
		// 
		// btnPause
		// 
		this->btnPause->Location = System::Drawing::Point(601, 7);
		this->btnPause->Name = L"btnPause";
		this->btnPause->Size = System::Drawing::Size(75, 38);
		this->btnPause->TabIndex = 2;
		this->btnPause->Text = L"&Pause";
		this->btnPause->UseVisualStyleBackColor = true;
		this->btnPause->Click += gcnew System::EventHandler(this, &FormMain::btnPause_Click);
		// 
		// lblProgress
		// 
		this->lblProgress->AutoSize = true;
		this->lblProgress->Location = System::Drawing::Point(12, 18);
		this->lblProgress->Name = L"lblProgress";
		this->lblProgress->Size = System::Drawing::Size(0, 12);
		this->lblProgress->TabIndex = 1;
		// 
		// FormMain
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(688, 379);
		this->Controls->Add(this->spRoot);
		this->Name = L"FormMain";
		this->Text = L"FormMain";
		this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormMain::FormMain_FormClosing);
		this->spRoot->Panel1->ResumeLayout(false);
		this->spRoot->Panel2->ResumeLayout(false);
		this->spRoot->Panel2->PerformLayout();
		this->spRoot->ResumeLayout(false);
		this->ResumeLayout(false);

	}


}