#include "stdafx.h"
#include "thread.h"
#include "work.h"

using namespace System;

volatile HANDLE gcurthread;
volatile DWORD gthid;




unsigned  __stdcall startOfSearch(void * p)
{
	THREADPASSDATA* pD = (THREADPASSDATA*)p;
	UINT oldmode = SetErrorMode(SEM_FAILCRITICALERRORS);

	while(pD->MoveNext())
	{
		dowork(pD);
	}
	
	SetErrorMode(oldmode);

	processResult(pD);
	clearwork();
	SendMessage(pD->hwnd_, WM_APP_SEARCHDONE, 0,0);

	DTRACE(String::Format("Last Thread {0} is exiting : ", (UINT64)pD->thisthread_));
	DVERIFY(CloseHandle(pD->thisthread_));
	DTRACE(String::Format("wwwwwwwww CloseHandle({0}) getlasterror() = {1}", (UINT64)pD->thisthread_, GetLastError()));

	delete pD;
	_endthreadex(0);

	return 0;
}