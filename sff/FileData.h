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

	void calcit(LPCTSTR pName);
	string getCalc();
};
class CALC2
{
};
class CFileData
{
	tstring name_;
	ULONGLONG leng_;
	CALC1* c1_;
public:
	CFileData(LPCTSTR pDir, LPCTSTR pN, ULONGLONG leng)
	{
		c1_ = NULL;
		name_ = pDir;
		name_ += _T("\\");
		name_ += pN;
		leng_ = leng;
	}
	~CFileData()
	{
		delete c1_;
	}

	LPCTSTR GetName() const {
		return name_.c_str();
	}

	void Calculate1();
	string GetCalculate1();
};
