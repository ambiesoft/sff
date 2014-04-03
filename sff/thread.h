#pragma once
struct THREADPASSDATA {
	DWORD thid_;
	HANDLE thisthread_;
	HWND hwnd_;

	int delay_;
	LPCTSTR dir_;

	THREADPASSDATA(DWORD thid,HANDLE thisthread,
		HWND hwnd,
		int delay,
		LPCTSTR dir)
	{
		thid_=thid;
		thisthread_=thisthread;
		hwnd_=hwnd;
		delay_=delay;
		dir_=dir;
	}
	~THREADPASSDATA()
	{
		free((void*)dir_);
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