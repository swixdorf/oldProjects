//---------------------------------------------------------------------------

#ifndef codehookH
#define codehookH
#include <vcl.h>
#include <Winternl.h>
#include <Tlhelp32.h>
#include <psapi.h>
#include "disassembler.hpp"
//---------------------------------------------------------------------------
  typedef struct _CLIENT_ID
{
	 PVOID UniqueProcess;
	 PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;
typedef struct {
	char exename[260];
}Exefilter ;

void MakeMemoryWritable(unsigned long ulAddress, unsigned long ulSize);
void MEMwrite(void *adr, void *ptr, int size);
DWORD HOOKHazirla1(void *Logadres,DWORD &logjmp, void *hookProc,void *faceProc,BYTE *code,int cpysize,int fakesize,
DWORD &jmpadres ,BYTE *fmove ,BYTE retvalue ,BYTE *callkonrol

);
int WINAPI FilterName(char *name,Exefilter *filter,DWORD m_nFilterInfoCount);
__declspec(naked)Faketopla(DWORD x);
__declspec(naked)Nopla();
char *GetFileName(char *path);
__declspec(naked)NtOpenProcessMy(PHANDLE ProcessHandle,
ACCESS_MASK DesiredAccess,
POBJECT_ATTRIBUTES ObjectAttributes,
PCLIENT_ID ClientId  );
__declspec(naked)NtOpenProcessMyNop();
typedef struct {
	ULONG NextEntryDelta;
	ULONG ThreadCount;
	ULONG Reserved1[6];
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ProcessName;
	ULONG BasePriority;
	ULONG ProcessId;
}PROCESS_INFO;


#endif
