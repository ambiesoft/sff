// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。

// #include <checkaccess.h>
#include <windows.h>
#include <tchar.h>

#include <vcclr.h>
#include <stdlib.h>
#include <process.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 4291)
#include <map>
#include <set>
#include <string>
#include <vector>

#include <stlsoft/smartptr/scoped_handle.hpp>


#if _DEBUG
#include <crtdbg.h>
#define malloc(size) _malloc_dbg(size, _NORMAL_BLOCK, __FILE__, __LINE__ )
#define calloc(s1,s2) _calloc_dbg(s1, s2, _NORMAL_BLOCK, __FILE__, __LINE__ )
#define realloc(p,s) _realloc_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define free(p)  _free_dbg(p, _NORMAL_BLOCK)
inline void* operator new(size_t nSize, LPCSTR lpszFileName, int nLine)
{
 return _malloc_dbg(nSize, _NORMAL_BLOCK, lpszFileName, nLine);
}
inline void operator delete(void *p)
{
 _free_dbg(p, _NORMAL_BLOCK);
}
#define DEBUG_NEW new(__FILE__, __LINE__)
#define new DEBUG_NEW
#endif


#if defined(_DEBUG) || defined(_RELEASE)
#define DASSERT(s) System::Diagnostics::Debug::Assert(!!(s))
inline void DTRACE(System::Object^o) { System::Diagnostics::Debug::Print(o ? o->ToString() : L"NULL"); }
#define DTRACE_NUMBER(start) do { static int num = start; DTRACE(num.ToString()); ++num; } while(0);
#define DTRACE_NUMBERTEXT(start,text) do { static int num = start; DTRACE(num.ToString() + ":" + text); ++num; } while(0);
#define DVERIFY DASSERT
#define DVERIFY_IS(a,b)  DASSERT( (a)==(b) )
#define DVERIFY_NOT(a,b) DASSERT( (a)!=(b) )
#define DVERIFY_GL(a) do { DASSERT( (a) ); DWORD gle = GetLastError(); if ( gle!=0 ) { DASSERT(gle || 0); } } while(0)
#define DVERIFY_GL_NUM(a,n) do { DASSERT( (a) ); DWORD gle = GetLastError(); if ( gle!=n ) { DASSERT( gle || 0); } } while(0)
#define DVERIFY_GL_NUM2(a,n1, n2) do { DASSERT( (a) ); DWORD gle = GetLastError(); if ( gle!=n1 && gle!= n2) { DTRACE(gle.ToString()); DASSERT( gle || 0); } } while(0)
#define DASSERT_IS_CLASS(instance, clazz) DASSERT( ((instance)->GetType())==clazz::typeid ) 
#define DASSERT_IS_CLASS_OR_NULL(instance, clazz) DASSERT( instance==nullptr || ((instance)->GetType())==clazz::typeid ) 
inline bool isDerived(System::Object^ o, System::Type^ t)
	{
		if ( !o || !t )
			return false;

		System::Type^ ot = o->GetType(); 
		do
		{
			if ( ot == t )
				return true;

			ot = ot->BaseType;
		} while ( ot != System::Object::typeid );

		return false;
	}
#define DASSERT_IS_DERIVED(instance, clazz) DASSERT(isDerived(instance, clazz::typeid))
#else
#define DASSERT(s) ((void)0)
#define DTRACE(s) ((void)0)
#define DTRACE_NUMBER(start) ((void)0)
#define DTRACE_NUMBERTEXT(start,text) ((void)0)
#define DVERIFY(a) (a)
#define DVERIFY_IS(a,b)  (a)
#define DVERIFY_NOT(a,b) (a)
#define DVERIFY_GL(a) (a)
#define DVERIFY_GL_NUM(a,n) (a)
#define DVERIFY_GL_NUM2(a,n1, n2) (a)
#define DASSERT_IS_CLASS(instance, clazz) ((void)0)
#define DASSERT_IS_CLASS_OR_NULL(instance, clazz) ((void)0)
#define DASSERT_IS_DERIVED(instance, clazz) ((void)0)
#endif



#define MAKEULONGLONG(a,b) \
    ((ULONGLONG)((DWORD)(a) | ((DWORDLONG)(DWORD)(b)) << 32))

#define MAKEULONGLONGWFD(wfd) \
    ((ULONGLONG)((DWORD)((wfd).nFileSizeLow) | ((DWORDLONG)(DWORD)((wfd).nFileSizeHigh)) << 32))

enum {
	WM_APP_SEARCHDONE = WM_APP + 1,
	WM_APP_ADDLINE,
	WM_APP_ADDLINE2,
	WM_APP_ADDSEPARATOR,
	WM_APP_ADDPROGRESS,
	WM_APP_APIERROR,

};


#ifdef UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif
typedef ULONGLONG ULL;
typedef std::vector<tstring> TSTRINGVECTOR;


#define I18NLS(t) (t)

using namespace std;