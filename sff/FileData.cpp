#include "stdafx.h"
#include "FileData.h"
#include <sys/stat.h>
#include <sys/types.h>
DWORD CALC1::calcitt(LPCTSTR pName)
{
	HANDLE h = CreateFile(pName,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_READONLY | FILE_FLAG_RANDOM_ACCESS,
		NULL);
	if(h==INVALID_HANDLE_VALUE)
		return GetLastError();

	FILETIME la;
	la.dwHighDateTime = 0xFFFFFFFF;
	la.dwLowDateTime =  0xFFFFFFFF;
	SetFileTime(h, NULL, &la, NULL);

	struct FILECLOSERwin {
		HANDLE h_;
		FILECLOSERwin(HANDLE h) {
			h_ = h;
		}
		~FILECLOSERwin() {
			CloseHandle(h_);
		}
	} hc(h);

	DWORD high = 0;
	DWORD low = GetFileSize(h, &high);
	if(low==INVALID_FILE_SIZE && GetLastError()!=NO_ERROR)
		return GetLastError();

	ULL len = MAKEULONGLONG(low,high);

	if(INVALID_SET_FILE_POINTER==SetFilePointer(h, 0, NULL, FILE_BEGIN))
		return GetLastError();

	DWORD readed=0;
	if(high==0 && low < 20)
	{
		ZeroMemory(bf, sizeof(bf));
		if(!ReadFile(h, bf, sizeof(bf), &readed, NULL))
			return GetLastError();

		DASSERT(sizeof(bf)==sizeof(bc));
		DASSERT(sizeof(bf)==sizeof(bl));
		memcpy(bc, bf, sizeof(bf));
		memcpy(bl, bf, sizeof(bf));

		fSuc=TRUE;
		return NO_ERROR;
	}

	if(!ReadFile(h, bf, sizeof(bf), &readed, NULL) && readed != sizeof(bf))
		return GetLastError();


	ULL halfsize = len/2;
	
	LONG halflow = (LONG)(halfsize & 0xFFFFFFFF);
	LONG halfhigh = (LONG)(halfsize>>32);
	if(INVALID_SET_FILE_POINTER==SetFilePointer(h, halflow, &halfhigh, FILE_BEGIN) &&
		GetLastError() != NO_ERROR)
		return GetLastError();

	if(!ReadFile(h, bc, sizeof(bc), &readed, NULL) && readed != sizeof(bc))
		return GetLastError();

	ULL lenm10 = len - 10;
	halflow = (ULONG)(lenm10 & 0xFFFFFFFF);
	halfhigh = (ULONG)(lenm10>>32);
	if(INVALID_SET_FILE_POINTER==SetFilePointer(h, halflow, &halfhigh, FILE_BEGIN) &&
		GetLastError() != NO_ERROR)
		return GetLastError();

	if(!ReadFile(h, bl, sizeof(bl), &readed, NULL) && readed != sizeof(bl))
		return GetLastError();

	fSuc = TRUE;
	return NO_ERROR;
}


string CALC1::getCalc(ULL leng)
{
	if(!fSuc)
		return "";
	string ret;
	
	
	char szT[128];
	_ui64toa(leng, szT, 10);
	ret = szT;
	ret += "-";

	sprintf(szT, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		bf[0],
		bf[1],
		bf[2],
		bf[3],
		bf[4],
		bf[5],
		bf[6],
		bf[7],
		bf[8],
		bf[9]);
	DASSERT(strlen(szT)==(10*2));
	ret += szT;

	sprintf(szT, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		bc[0],
		bc[1],
		bc[2],
		bc[3],
		bc[4],
		bc[5],
		bc[6],
		bc[7],
		bc[8],
		bc[9]);
	DASSERT(strlen(szT)==(10*2));
	ret += szT;

	sprintf(szT, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		bl[0],
		bl[1],
		bl[2],
		bl[3],
		bl[4],
		bl[5],
		bl[6],
		bl[7],
		bl[8],
		bl[9]);
	DASSERT(strlen(szT)==(10*2));
	ret += szT;

	return ret;
}


CFileData::CFileData(LPCTSTR pDir, LPCTSTR pN, ULL leng)
{
	c1_ = NULL;
	name_ = pDir;
	name_ += _T("\\");
	name_ += pN;

	//TCHAR* p = _tcsdup(name_.c_str());
	//tstring aaa=name_;
	//aaa=name_.c_str();
	//aaa=p;
	//System::Windows::Forms::MessageBox::Show(gcnew System::String(name_.c_str()));
	leng_ = leng;
}

string CFileData::GetLengString() const
{
	char szT[128];
	_ui64toa(leng_, szT, 10);
	return string(szT);
}


DWORD CFileData:: GetCalculate1(string& ret)
{
	if(!c1_)
	{
		c1_ = new CALC1;
		DWORD dw = c1_->calcitt(name_.c_str());
		if(NO_ERROR != dw)
			return dw;
	}
	ret= c1_->getCalc(leng_);
	return NO_ERROR;
}