#pragma once
class CALC1
{
	BOOL fSuc;
	BYTE bf[10];
	BYTE bc[10];
	BYTE bl[10];


public:
	CALC1()
	{
		ZeroMemory(this, sizeof(this));
	}

	DWORD calcitt(LPCTSTR pName);
	string getCalc(ULL leng);
};
class CALC2
{
};
class CFileData
{
	tstring name_;
	ULL leng_;
	CALC1* c1_;
public:
	CFileData(LPCTSTR pDir, LPCTSTR pN, ULL leng);
	~CFileData()
	{
		delete c1_;
	}

	ULL GetLeng() const {
		return leng_;
	}
	LPCTSTR GetName() const {
		return name_.c_str();
	}
	string GetLengString() const ;

	DWORD GetCalculate1(string& ret);
};
