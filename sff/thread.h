#pragma once
// typedef gcroot<System::Collections::Generic::List<System::String^>^> GCLIST;

struct THREADPASSDATA {
private:
	int curindex_;
	gcroot<System::Text::RegularExpressions::Regex^> reg_;

	std::set<std::wstring> dupset_;

public:
	DWORD thid_;
	HANDLE thisthread_;
	HWND hwnd_;

	int delay_;
	TSTRINGVECTOR dirs_;
	LPCTSTR curdir_;
	tstring regtxt_;
	ULL minsize_;
	bool difforigin_;
	THREADPASSDATA(
		DWORD thid,
		HANDLE thisthread,
		HWND hwnd,
		int delay,
		const TSTRINGVECTOR* pdirs,
		LPCTSTR pRegText,
		ULL minsize,
		bool difforigin)
	{
		thid_=thid;
		thisthread_=thisthread;
		hwnd_=hwnd;
		delay_=delay;
		dirs_=*pdirs;
		curdir_=NULL;
		curindex_=-1;
		regtxt_=pRegText;
		reg_=NULL;
		minsize_=minsize;
		difforigin_=difforigin;
	}
	bool MoveNext()
	{
		curindex_++;
		if((int)dirs_.size() <= curindex_)
		{
			// free((void*)curdir_);
			curdir_=NULL;
			return false;
		}

		//System::String^ t = 
		//pin_ptr<const wchar_t> pIn = PtrToStringChars(t);
		//free((void*)curdir_);
		curdir_ = dirs_[curindex_].c_str();
	
		return true;
	}
	bool match(LPCTSTR pName);
	~THREADPASSDATA();

	int getCurIndex() const {
		return curindex_;
	}

	bool isDiffOrigin() const {
		return difforigin_;
	}

	bool IsProcessedDir(LPCTSTR pDir) const;
	void SetProcessedDir(LPCTSTR pDir);
};

extern volatile HANDLE gcurthread;
extern volatile DWORD gthid;
unsigned  __stdcall startOfSearch(void * p);

//ref class THREADBACK
//{
//public:
//	static System::String^ result_;
//};