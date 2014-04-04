#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace sff {

	/// <summary>
	/// FormError の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class FormError : public System::Windows::Forms::Form
	{
	public:
		FormError(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
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
