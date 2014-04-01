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

void CFileData::Calculate1()
{
	c1_ = new CALC1;
	c1_->calcit(name_.c_str());

}
LONGLONG CFileData::GetCalculate1()
{
	return c1_->GetCalculate1();
}