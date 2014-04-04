#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace sff {

	/// <summary>
	/// FormError �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class FormError : public System::Windows::Forms::Form
	{
	public:
		FormError(void)
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
		~FormError()
		{
			if (components)
			{
				delete components;
			}
		}
	internal: System::Windows::Forms::ListView^  lvError;
	protected: 

	protected: 
	private: System::Windows::Forms::ColumnHeader^  chError;
	private: System::Windows::Forms::ColumnHeader^  chFile;

	protected: 

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
			this->lvError = (gcnew System::Windows::Forms::ListView());
			this->chError = (gcnew System::Windows::Forms::ColumnHeader());
			this->chFile = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// lvError
			// 
			this->lvError->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->chError, this->chFile});
			this->lvError->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lvError->Location = System::Drawing::Point(0, 0);
			this->lvError->Name = L"lvError";
			this->lvError->Size = System::Drawing::Size(668, 266);
			this->lvError->TabIndex = 0;
			this->lvError->UseCompatibleStateImageBehavior = false;
			this->lvError->View = System::Windows::Forms::View::Details;
			// 
			// chError
			// 
			this->chError->Text = L"Error";
			this->chError->Width = 238;
			// 
			// chFile
			// 
			this->chFile->Text = L"File";
			this->chFile->Width = 407;
			// 
			// FormError
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 266);
			this->Controls->Add(this->lvError);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormError";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"FormError";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormError::FormError_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FormError_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 e->Cancel=true;
				 Visible=false;
			 }
	};
}
