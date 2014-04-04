// samefile.cpp : �R���\�[�� �A�v���P�[�V�����p�̃G���g�� �|�C���g�̒�`
//

#include "stdafx.h"
#include "FileData.h"
#include "thread.h"
#include "work.h"

using namespace System;





typedef map<ULL, CFileData*> THEM;
static THEM alcheck1;

typedef map<string, CFileData*> THEM2;
static THEM2 alcheck2;

typedef multimap<ULL, CFileData*> THEMM;
typedef THEMM::iterator THEMMIT;
typedef THEMM::value_type THEMMV;
static THEMM dups1;

typedef multimap<string, CFileData*> THEMM2;
typedef THEMM2::iterator THEMM2IT;
typedef THEMM2::value_type THEMM2V;
static THEMM dups2;

static set<CFileData*> atodel;
static LPTSTR credir(LPCTSTR pDir1, LPCTSTR pDir2)
{
	size_t nlen1 = _tcslen(pDir1);
	size_t nlen2 = _tcslen(pDir2);
	LPTSTR p = (LPTSTR)malloc((nlen1+nlen2+1+1)*sizeof(TCHAR));
	p[0] = 0;
	_tcscat(p,pDir1);
	_tcscat(p,_T("\\"));
	_tcscat(p,pDir2);
	return p;
}


static BOOL iswfdcurdir(WIN32_FIND_DATA* pD)
{
	if(pD->cFileName[0]!=_T('.'))
		return FALSE;
	
	if(pD->cFileName[1]==0)
		return TRUE;

	if(pD->cFileName[1]==_T('.') && pD->cFileName[2]==0)
		return TRUE;

	return FALSE;
}


static void processfound(THREADPASSDATA* pD, WIN32_FIND_DATA* pf, LPCTSTR pNext=NULL)
{
	if(pD->thid_ != gthid)
		return;

	if(iswfdcurdir(pf))
		return;

	LPCTSTR pDir = pNext?pNext:pD->dir_;
	if(pf->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		LPCTSTR p = credir(pDir, pf->cFileName);
		struct CRTFreer {
			void* p_;
			CRTFreer(void* p) {
				p_=p;
			}
			~CRTFreer() {
				free(p_);
			}
		} crtfreer((void*)p);

		if(!SendMessage(pD->hwnd_, WM_APP_ADDPROGRESS, pD->thid_, (LPARAM)p))
			return;

		dowork(pD,p);
		return;
	}

	ULL ull = MAKEULONGLONGWFD(*pf);
	
	//if(ull < (1024*100))
	//	return;

	CFileData* pFD = new CFileData(pDir, pf->cFileName,ull);
	atodel.insert(pFD);



	if(alcheck1[ull] != NULL)
	{
		dups1.insert(THEMMV(ull,alcheck1[ull] ));
		dups1.insert(THEMMV(ull,pFD ));

		string ss1 = alcheck1[ull]->GetCalculate1();
		string ss2 = pFD->GetCalculate1();
		if(ss1==ss2)
		{
			if(!alcheck2[ss1])
			{
				if(!SendMessage(pD->hwnd_, WM_APP_ADDLINE2, (WPARAM)pD->thid_, (LPARAM)alcheck1[ull]))
					return;

				alcheck2[ss1]=pFD;
			}

			if(!SendMessage(pD->hwnd_, WM_APP_ADDLINE2, (WPARAM)pD->thid_, (LPARAM)pFD))
				return;
			
			alcheck2[ss2] = pFD;
		}
	}
	else
	{
		alcheck1[ull] = pFD; // .insert(map<ULL, CFileData*>::value_type(ull,pFD ));
	}
}

static LPTSTR newforfff(LPCTSTR pDir)
{
	size_t olen = _tcslen(pDir);
	size_t nlen = olen + 16;
	LPTSTR pRet = (LPTSTR)malloc(nlen*sizeof(TCHAR));
	memcpy(pRet, pDir, olen*sizeof(TCHAR));
	pRet[olen] = _T('\\');
	pRet[olen+1] = _T('*');
	pRet[olen+2] = 0;
	return pRet;
}















void dowork(THREADPASSDATA* pD,LPCTSTR pNext)
{
	LPCTSTR pDir = pNext?pNext:pD->dir_;
	LPCTSTR pDirFFF = newforfff(pDir);
	WIN32_FIND_DATA wfd;
	HANDLE h = FindFirstFile(pDirFFF, &wfd);

	if(h != INVALID_HANDLE_VALUE )
	{
		processfound(pD,&wfd,pDir);
		while(FindNextFile(h, &wfd))
		{
			processfound(pD, &wfd,pDir);
		}
	}
	free((void*)pDirFFF);
}

void clearwork()
{
	for(set<CFileData*>::iterator it=atodel.begin(); it!=atodel.end();++it)
		delete *it;

	alcheck1.clear();
	alcheck2.clear();
	dups1.clear();
	dups2.clear();
	atodel.clear();
}

void processResult(THREADPASSDATA* pD)
{
	//HWND hwnd = pD->hwnd_;
	//if(dups.size() != 0)
	//{
	//	set<ULL> atta;
	//	THEMMIT it;

	//	for(it=dups.begin() ; it != dups.end() ; ++it)
	//	{
	//		atta.insert(it->first);
	//	}


	//	
	//	typedef map<ULL,set<CFileData*>* > TOPRO;
	//	TOPRO topro;
	//	for(set<ULL>::iterator its = atta.begin(); its != atta.end() ; ++its)
	//	{
	//		pair<THEMMIT, THEMMIT> range = dups.equal_range(*its);

	//		set<CFileData*>* psamesizes = new set<CFileData*>;
	//		for( THEMMIT itr=range.first; itr!=range.second; ++itr )
	//		{
	//			CFileData* pFD = (CFileData*)itr->second;
	//			psamesizes->insert(pFD);
	//		}
	//		DTRACE(*its);
	//		topro[*its] = (psamesizes);
	//	}


	//	{  // calculate1
	//		for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
	//		{
	//			for(set<CFileData*>::iterator itts = itp->second->begin(); itts != itp->second->end(); ++itts)
	//			{
	//				// same files
	//				CFileData* pFD = *itts;
	//				pFD->Calculate1();
	//				// sb.AppendLine(gcnew String((*itts)->GetName()));
	//			}
	//			// sb.AppendLine(L"============================");
	//		}
	//	}

	//	typedef map<string,set<CFileData*>* > TOPRO2;
	//	TOPRO2 topro2;
	//	{  // check calculate1
	//		for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
	//		{ // each size to CFs
	//			// check1
	//			map<string, CFileData*> kouhos;
	//			for(set<CFileData*>::iterator itts = itp->second->begin(); itts != itp->second->end(); ++itts)
	//			{
	//				// same files
	//				CFileData* pFD = *itts;
	//				
	//				string c1 = pFD->GetLengString();
	//				c1 += "-";
	//				c1 += pFD->GetCalculate1();

	//				if(kouhos[c1] != NULL)
	//				{
	//					 set<CFileData*>* tp = topro2[c1];
	//					 if(!tp)
	//						 tp = new set<CFileData*>;

	//					 tp->insert(kouhos[c1]);
	//					 tp->insert(pFD);
	//					 topro2[c1]=tp;
	//				}
	//				kouhos[c1] = pFD;
	//			}
	//			
	//		}
	//	}

	//	{ // check topro2
	//		for(TOPRO2::iterator it = topro2.begin(); it != topro2.end(); ++it)
	//		{
	//			string cal = it->first;
	//			set<CFileData*>* pSet = it->second;
	//			for(set<CFileData*>::iterator its=pSet->begin(); its != pSet->end(); ++its)
	//			{
	//				CFileData* pFD = *its;
	//				// sb.AppendLine(gcnew String(pFD->GetName()));
	//				SendMessage(hwnd, WM_APP_ADDLINE, (WPARAM)pD->thid_, (LPARAM)pFD->GetName());
	//			}
	//			// sb.AppendLine(L"============================");
	//			SendMessage(hwnd, WM_APP_ADDSEPARATOR, (WPARAM)pD->thid_, NULL);
	//		}
	//	}
	//	{ // cleanup
	//		for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
	//		{
	//			delete itp->second;
	//		}
	//	}

	//}

	
}