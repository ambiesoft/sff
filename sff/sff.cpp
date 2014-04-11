// sff.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "work.h"
#include "FormMain.h"

using namespace sff;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	#if _DEBUG
	 _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
	#endif
	
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew FormMain());
	return 0;
}
