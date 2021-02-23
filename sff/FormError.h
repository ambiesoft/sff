#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace sff {

	/// <summary>
	/// FormError
	///
	/// </summary>
	public ref class FormError : public System::Windows::Forms::Form
	{
	public:
		FormError(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
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

	internal:
		int getErrorCount()
		{
			if(!lvError)
				return 0;

			//if(!lvError->Created)
			//	return 0;

			//if(!lvError->IsDisposed)
			//	return 0;

			return lvError->Items->Count;
		}

	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
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
			this->lvError->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->chError, this->chFile });
			this->lvError->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lvError->HideSelection = false;
			this->lvError->Location = System::Drawing::Point(0, 0);
			this->lvError->Name = L"lvError";
			this->lvError->Size = System::Drawing::Size(668, 288);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(668, 288);
			this->Controls->Add(this->lvError);
			this->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
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
