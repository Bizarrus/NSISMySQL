#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>

#ifdef _UNICODE
	#include "nsis\unicode\pluginapi.h"
#else
	#include "nsis\ansi\pluginapi.h"
#endif