#ifndef ___NSIS_PLUGIN__H___
	#define ___NSIS_PLUGIN__H___
	#define NSIS_MAX_STRLEN 1024

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "api.h"
		#include "nsis_tchar.h"

		#ifndef NSISCALL
			#define NSISCALL __stdcall
		#endif

		#define EXDLL_INIT() { \
			g_stringsize=string_size; \
			g_stacktop=stacktop; \
			g_variables=variables; \
		}

		typedef struct _stack_t {
			struct _stack_t *next;

			WCHAR text[NSIS_MAX_STRLEN];
		} stack_t;

		enum {
			INST_0,         // $0
			INST_1,         // $1
			INST_2,         // $2
			INST_3,         // $3
			INST_4,         // $4
			INST_5,         // $5
			INST_6,         // $6
			INST_7,         // $7
			INST_8,         // $8
			INST_9,         // $9
			INST_R0,        // $R0
			INST_R1,        // $R1
			INST_R2,        // $R2
			INST_R3,        // $R3
			INST_R4,        // $R4
			INST_R5,        // $R5
			INST_R6,        // $R6
			INST_R7,        // $R7
			INST_R8,        // $R8
			INST_R9,        // $R9
			INST_CMDLINE,   // $CMDLINE
			INST_INSTDIR,   // $INSTDIR
			INST_OUTDIR,    // $OUTDIR
			INST_EXEDIR,    // $EXEDIR
			INST_LANG,      // $LANGUAGE
			__INST_LAST
		};

		extern unsigned int g_stringsize;
		extern stack_t **g_stacktop;
		extern LPCTSTR g_variables;

		int NSISCALL popstring(LPCTSTR str);				// 0 on success, 1 on empty stack
		int NSISCALL popstringn(LPCTSTR str, int maxlen);	// with length limit, pass 0 for g_stringsize
		int NSISCALL popint();								// pops an integer
		int NSISCALL popint_or();							// with support for or'ing (2|4|8)
		int NSISCALL myatoi(const LPCTSTR s);				// converts a string to an integer
		unsigned NSISCALL myatou(const LPCTSTR s);			// converts a string to an unsigned integer, decimal only
		int NSISCALL myatoi_or(const LPCTSTR s);			// with support for or'ing (2|4|8)
		void NSISCALL pushstring(const LPCTSTR str);
		void NSISCALL pushint(int value);
		LPCTSTR NSISCALL getuservariable(const int varnum);
		void NSISCALL setuservariable(const int varnum, const LPCTSTR var);

		#define PopStringW(x) popstring(x)
		#define PushStringW(x) pushstring(x)
		#define SetUserVariableW(x,y) setuservariable(x,y)

		int  NSISCALL PopStringA(LPSTR ansiStr);
		void NSISCALL PushStringA(LPCSTR ansiStr);
		void NSISCALL GetUserVariableW(const int varnum, LPWSTR wideStr);
		void NSISCALL GetUserVariableA(const int varnum, LPSTR ansiStr);
		void NSISCALL SetUserVariableA(const int varnum, const LPCSTR ansiStr);
	#ifdef __cplusplus
		}
	#endif
#endif