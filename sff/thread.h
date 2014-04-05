#pragma once
// typedef gcroot<System::Collections::Generic::List<System::String^>^> GCLIST;
struct THREADPASSDATA {
private:
	int curindex_;
public:
	DWORD thid_;
	HANDLE thisthread_;
	HWND hwnd_;

	int delay_;
	TSTRINGVECTOR dirs_;
	LPCTSTR curdir_;
	THREADPASSDATA(DWORD thid,HANDLE thisthread,
		HWND hwnd,
		int delay,
		const TSTRINGVECTOR& dirs)
	{
		thid_=thid;
		thisthread_=thisthread;
		hwnd_=hwnd;
		delay_=delay;
		dirs_=dirs;
		curdir_=NULL;
		curindex_=-1;
		//if(dirs->Count != 0)
		//{
		//	System::String^ t = dirs->default[0];
		//	pin_ptr<const wchar_t> pIn = PtrToStringChars(t);
		//	curdir_ = _tcsdup(pIn);
		//}
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
	~THREADPASSDATA()
	{
		
	}
};

extern volatile HANDLE gcurthread;
extern volatile DWORD gthid;
unsigned  __stdcall startOfSearch(void * p);

//ref class THREADBACK
//{
//public:
//	static System::String^ result_;
//};