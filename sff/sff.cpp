// sff.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "work.h"
#include "FormMain.h"

#include "../../MyUtility/CommandLineParser.h"

using namespace sff;
using namespace Ambiesoft;

using namespace System;

[STAThreadAttribute]
int main()
{
	#if _DEBUG
	 _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
	#endif
	
	CCommandLineParser parser;

	// default argument (without option like -- or /)
	COption opMain;
	parser.AddOption(&opMain);

	parser.Parse();

	// create args to pass FormMain
	System::Collections::Generic::List<String^> args;
	if(opMain.hadValue())
	{
		for(size_t i=0; i < opMain.getValueCount() ; ++i)
		{
			args.Add(gcnew String(opMain.getValue(i).c_str() ));
		}
	}

	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew FormMain(%args));
	return 0;
}
