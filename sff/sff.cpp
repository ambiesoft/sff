
#include "stdafx.h"
#include "work.h"
#include "FormMain.h"

#include "../../lsMisc/CommandLineParser.h"

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


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


	Application::Run(gcnew FormMain(%args));
	return 0;
}
