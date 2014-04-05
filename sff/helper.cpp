#include "stdafx.h"
#include "helper.h"
tstring GetLastErrorString(DWORD dwErrorNo, BOOL* pSeikou)
{
	LPVOID lpMsgBuf = NULL;
	tstring strRet;
 
	if( (0==FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_MAX_WIDTH_MASK,
		NULL,
		dwErrorNo,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL)) || lpMsgBuf==NULL )
	{
		if(pSeikou)
		{
			*pSeikou = FALSE;
		}
		return strRet;
	}
 
	strRet = (LPTSTR)lpMsgBuf;
	LocalFree(lpMsgBuf);
 
	if (pSeikou)
	{
		*pSeikou = TRUE;
	}
 
	return strRet;
}

std::string getStdString(System::String^ s)
{
	std::string ret;
	if ( s == nullptr )
		return ret;

	pin_ptr<const wchar_t> p = PtrToStringChars(s);
	size_t len = (s->Length+1) * sizeof(wchar_t);
	char* pT = (char*)malloc(len);
	size_t retutrnvalue;

	if ( 0 != wcstombs_s( &retutrnvalue, 
		pT,
		len,
		p,
		len ) )
	{
		DASSERT(false);
		free(pT);
		return ret;
	}
	ret = pT;
	free(pT);
	return ret;
}


std::wstring getStdWstring(System::String^ s)
{
	std::wstring ret;
	if ( s == nullptr )
		return ret;

	//System::IntPtr pp = System::Runtime::InteropServices::Marshal::StringToHGlobalUni(s);
	//ret = (const wchar_t*)pp.ToPointer() ;
	//System::Runtime::InteropServices::Marshal::FreeHGlobal(pp);
	pin_ptr<const wchar_t> p = PtrToStringChars(s);
	ret = p;
	return ret;
}

