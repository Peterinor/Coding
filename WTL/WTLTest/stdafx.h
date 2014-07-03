// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0500
#define _WIN32_WINNT	0x0501
//#define _WIN32_IE	0x0501
#define _RICHEDIT_VER	0x0200
#define _WIN32_WINNT	0x0600

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include <atlmisc.h>

//#include <dwmapi.h>
//#pragma comment(lib, "Dwmapi.lib")

#include <atltheme.h>
#include <atldwm.h>

#include <atlcrack.h>