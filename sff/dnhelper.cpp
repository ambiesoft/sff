
#include "dnhelper.h"
using namespace System;

String^ dnGetCurrentDirectory()
{
	return System::IO::Directory::GetCurrentDirectory();
}

void dnSetCurrentDirectory(String^d)
{
	System::IO::Directory::SetCurrentDirectory(d);
}