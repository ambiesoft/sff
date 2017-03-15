#include "stdafx.h"
#include "helper.h"

using namespace System;







String^ GetBytelenFormatText(System::UInt64 ull)
{
	return Ambiesoft::CppUtils::humanReadableByteCount(ull) + " (" + ull.ToString(L"N0") + L" bytes)";
}