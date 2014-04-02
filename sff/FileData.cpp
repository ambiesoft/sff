#include "stdafx.h"
#include "FileData.h"
#include <sys/stat.h>
#include <sys/types.h>
void CALC1::calcit(LPCTSTR pName)
{


	FILE* f = _tfopen(pName, _T("rb"));
	if(!f)
		return;

	struct FILECLOSER {
		FILE* f_;
		FILECLOSER(FILE* f) {
			f_ = f;
		}
		~FILECLOSER() {
			fclose(f_);
		}
	} fc(f);

	struct _stat64 st;
	if(0 != _fstati64(_fileno(f), &st))
		return;

	LONGLONG len = st.st_size;
	
	
	if(0!=_fseeki64(f, 0, SEEK_SET))
		return;

	if(sizeof(bf) != fread(bf, sizeof(BYTE), sizeof(bf), f))
		return;



	__int64 halfsize = st.st_size / 2;
	if(0!=_fseeki64(f, halfsize, SEEK_SET))
		return;
	
	if(sizeof(bc) != fread(bc, sizeof(BYTE), sizeof(bc), f))
		return;



	if(0!=_fseeki64(f, st.st_size-10, SEEK_SET))
		return;
	
	if(sizeof(bl) != fread(bl, sizeof(BYTE), sizeof(bl), f))
		return;

	fSuc = TRUE;
}


string CALC1::getCalc()
{
	if(!fSuc)
		return "";
	string ret;
	
	char szT[128];

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

void CFileData::Calculate1()
{
	c1_ = new CALC1;
	c1_->calcit(name_.c_str());

}
string CFileData::GetCalculate1()
{
	return c1_->getCalc();
}