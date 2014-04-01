// samefile.cpp : コンソール アプリケーション用のエントリ ポイントの定義
//

#include "stdafx.h"
#include "FileData.h"

using namespace System;
void dowork(LPCTSTR pDir);



#define MAKEULONGLONG(wfd) \
    ((ULONGLONG)((DWORD)((wfd).nFileSizeLow) | ((DWORDLONG)(DWORD)((wfd).nFileSizeHigh)) << 32))

typedef map<ULONGLONG, CFileData*> THEM;
THEM alcheck;

typedef multimap<ULONGLONG, CFileData*> THEMM;
typedef THEMM::iterator THEMMIT;
typedef THEMM::value_type THEMMV;
THEMM dups;

set<CFileData*> atodel;
LPTSTR credir(LPCTSTR pDir1, LPCTSTR pDir2)
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


BOOL iswfdcurdir(WIN32_FIND_DATA* pD)
{
	if(pD->cFileName[0]!=_T('.'))
		return FALSE;
	
	if(pD->cFileName[1]==0)
		return TRUE;

	if(pD->cFileName[1]==_T('.') && pD->cFileName[2]==0)
		return TRUE;

	return FALSE;
}


void processfound(LPCTSTR pDir, WIN32_FIND_DATA* pf)
{
	if(iswfdcurdir(pf))
		return;

	if(pf->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		LPCTSTR p = credir(pDir, pf->cFileName);
		dowork(p);
		free((void*)p);
		return;
	}

	ULONGLONG ull = MAKEULONGLONG(*pf);
	if(ull < (1024*100))
		return;

	CFileData* pFD = new CFileData(pDir, pf->cFileName,ull);
	atodel.insert(pFD);
	if(alcheck[ull] != NULL)
	{
		dups.insert(THEMMV(ull,alcheck[ull] ));
		dups.insert(THEMMV(ull,pFD ));
	}
	else
	{
		alcheck[ull] = pFD; // .insert(map<ULONGLONG, CFileData*>::value_type(ull,pFD ));
	}
}

LPTSTR newforfff(LPCTSTR pDir)
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

void dowork(LPCTSTR pDir)
{
	LPCTSTR pDirFFF = newforfff(pDir);
	WIN32_FIND_DATA wfd;
	HANDLE h = FindFirstFile(pDirFFF, &wfd);

	if(h != INVALID_HANDLE_VALUE )
	{
		processfound(pDir, &wfd);
		while(FindNextFile(h, &wfd))
		{
			processfound(pDir, &wfd);
		}
	}
	free((void*)pDirFFF);
}

void clearwork()
{
	for(set<CFileData*>::iterator it=atodel.begin(); it!=atodel.end();++it)
		delete *it;

	alcheck.clear();
	dups.clear();
	atodel.clear();
}

String^ getResult()
{
	System::Text::StringBuilder sb;
	if(dups.size() != 0)
	{
		set<ULONGLONG> atta;
		THEMMIT it;

		for(it=dups.begin() ; it != dups.end() ; ++it)
		{
			atta.insert(it->first);
		}


		
		typedef map<ULONGLONG,set<CFileData*>* > TOPRO;
		TOPRO topro;
		for(set<ULONGLONG>::iterator its = atta.begin(); its != atta.end() ; ++its)
		{
			pair<THEMMIT, THEMMIT> range = dups.equal_range(*its);

			set<CFileData*>* psamesizes = new set<CFileData*>;
			for( THEMMIT itr=range.first; itr!=range.second; ++itr )
			{
				CFileData* pFD = (CFileData*)itr->second;
				psamesizes->insert(pFD);
			}
			topro[*its] = (psamesizes);
		}


		{  // calculate1
			for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
			{
				sb.AppendLine(itp->first.ToString());
				for(set<CFileData*>::iterator itts = itp->second->begin(); itts != itp->second->end(); ++itts)
				{
					// same files
					CFileData* pFD = *itts;
					pFD->Calculate1();
					sb.AppendLine(gcnew String((*itts)->GetName()));
				}
				sb.AppendLine(L"============================");
			}
		}

		TOPRO topro2;
		{  // check calculate1
			for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
			{
				map<ULONGLONG, CFileData*> kouhos;
				for(set<CFileData*>::iterator itts = itp->second->begin(); itts != itp->second->end(); ++itts)
				{
					// same files
					CFileData* pFD = *itts;
					ULONGLONG ret = pFD->GetCalculate1();

					if(kouhos[ret] != NULL)
					{
						 set<CFileData*>* tp = topro2[ret];
						 if(!tp)
						 {
							 tp = new set<CFileData*>;
							 tp->insert(kouhos[ret]);
							 tp->insert(pFD);
						 }
					}
					kouhos[ret] = pFD;
				}
				sb.AppendLine(L"============================");
			}
		}

		{ // cleanup
			for(TOPRO::iterator itp = topro.begin(); itp != topro.end(); ++itp)
			{
				delete itp->second;
			}
		}

	}

	return sb.ToString();
}