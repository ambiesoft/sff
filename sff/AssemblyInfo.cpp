#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute("sff")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("Ambiesoft")];
[assembly:AssemblyProductAttribute("sff")];
[assembly:AssemblyCopyrightAttribute("Copyright (c) Ambiesoft 2020")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];


[assembly:AssemblyVersionAttribute("1.5.3.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

#if _MSC_VER < 1800
[assembly:SecurityPermission(SecurityAction::RequestMinimum, UnmanagedCode = true)];
#endif