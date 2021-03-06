#include "stdafx.h"
#include "NSISMySQL.h"
#include <string>

HWND hWnd = ::GetActiveWindow();
#define NSISFUNC(name) extern "C" void __declspec(dllexport) name(HWND hwndParent, int string_size, TCHAR* variables, stack_t** stacktop, extra_parameters* extra)

BOOL WINAPI DllMain(HANDLE hInst, ULONG ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		
		break;
	}

	return TRUE;
}

#ifdef _UNICODE
	LPTSTR server = NULL, database = NULL, username = NULL, password = NULL, query = NULL;
#else
	char *server = NULL, *database = NULL, *username = NULL, *password = NULL, *query = NULL;
#endif
int port = 0;

#ifdef _UNICODE
LPTSTR getString(int string_size) {
	LPTSTR temp = (LPTSTR) GlobalAlloc(GPTR, string_size);
#else
char *getString(int string_size) {
	char *temp = (char *) GlobalAlloc(GPTR, string_size);
#endif
	popstring(temp);
	return temp;
}

NSISFUNC(SetCredentials) {
	EXDLL_INIT();

	server		= getString(string_size);
	port		= myatoi(getString(string_size));
	database	= getString(string_size);
	username	= getString(string_size);
	password	= getString(string_size);

	#ifdef NSISMySQL_DEBUG
		if(server) {
			MessageBox(hWnd, server, TEXT("SERVER"), MB_OK);
		}

		if(port) {
			MessageBox(hWnd, TEXT("" + port), TEXT("PORT"), MB_OK);
		}

		if(database) {
			MessageBox(hWnd, database, TEXT("DATABASE"), MB_OK);
		}

		if(username) {
			MessageBox(hWnd, username, TEXT("USER"), MB_OK);
		}

		if(password) {
			MessageBox(hWnd, password, TEXT("PASSWORD"), MB_OK);
		}
	#endif
}

NSISFUNC(Query) {
	EXDLL_INIT();

	query = getString(string_size);
	
	#ifdef NSISMySQL_DEBUG
		if(query) {
			MessageBox(hWnd, query, TEXT("QUERY"), MB_OK);
		}
	#endif
}