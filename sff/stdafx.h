// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
#pragma once

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
#include <windows.h>
#include <tchar.h>

#include <stdlib.h>
#pragma warning (disable : 4996)
#pragma warning (disable : 4291)

#include <string>
#ifdef UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif
#include <map>
#include <set>


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


using namespace std;