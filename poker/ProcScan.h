//---------------------------------------------------------------------------

#ifndef ProcScanH
#define ProcScanH
#include <tlhelp32.h>
//---------------------------------------------------------------------------
typedef BOOL (WINAPI *MODULEWALK)(HANDLE hSnapshot,
	LPMODULEENTRY32 lpme);
typedef BOOL (WINAPI *THREADWALK)(HANDLE hSnapshot, 
typedef BOOL (WINAPI *PROCESSWALK)(HANDLE hSnapshot,
typedef HANDLE (WINAPI *CREATESNAPSHOT)(DWORD dwFlags, 
DWORD ThreadScan(DWORD ProcID,DWORD Adress,TStrings *DurumYaz);
InitToolhelp32(void);

BOOL ListProcessModules( DWORD dwPID ,AnsiString &Name);
 int BuildImportTable(DWORD module,DWORD hookproc,char *Apiname,char *dllname);
 BOOL HookImportsOfImage(HMODULE hModule, PCHAR pchDllTarget, PCHAR pchFuncTarget, LPVOID lpvMineFunc);
 int BuildImportTable1(DWORD module,DWORD hookproc,char *Apiname,char *dllname);

#endif