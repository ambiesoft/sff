#pragma once


namespace sff {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FormMain �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnDoIT;
	protected: 

	protected: 
	private: System::Windows::Forms::TextBox^  txtResult;
	private: System::Windows::Forms::SplitContainer^  spRoot;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnDoIT = (gcnew System::Windows::Forms::Button());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->spRoot = (gcnew System::Windows::Forms::SplitContainer());
			this->spRoot->Panel1->SuspendLayout();
			this->spRoot->Panel2->SuspendLayout();
			this->spRoot->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnDoIT
			// 
			this->btnDoIT->Location = System::Drawing::Point(562, 5);
			this->btnDoIT->Name = L"btnDoIT";
			this->btnDoIT->Size = System::Drawing::Size(114, 38);
			this->btnDoIT->TabIndex = 0;
			this->btnDoIT->Text = L"button1";
			this->btnDoIT->UseVisualStyleBackColor = true;
			this->btnDoIT->Click += gcnew System::EventHandler(this, &FormMain::button1_Click);
			// 
			// txtResult
			// 
			this->txtResult->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtResult->Location = System::Drawing::Point(0, 0);
			this->txtResult->Multiline = true;
			this->txtResult->Name = L"txtResult";
			this->txtResult->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtResult->Size = System::Drawing::Size(688, 320);
			this->txtResult->TabIndex = 1;
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
			this->spRoot->Panel1->Controls->Add(this->txtResult);
			// 
			// spRoot.Panel2
			// 
			this->spRoot->Panel2->Controls->Add(this->btnDoIT);
			this->spRoot->Size = System::Drawing::Size(688, 379);
			this->spRoot->SplitterDistance = 320;
			this->spRoot->TabIndex = 2;
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 379);
			this->Controls->Add(this->spRoot);
			this->Name = L"FormMain";
			this->Text = L"FormMain";
			this->spRoot->Panel1->ResumeLayout(false);
			this->spRoot->Panel1->PerformLayout();
			this->spRoot->Panel2->ResumeLayout(false);
			this->spRoot->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	};
}

