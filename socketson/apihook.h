//---------------------------------------------------------------------------

#ifndef apihookH
#define apihookH
//---------------------------------------------------------------------------
#include "codehook.h"
#define STATUS_SUCCESS					((NTSTATUS)0x00000000L)

 const DWORD aprhandle=0x0FFFFF850;
 const DWORD aprhandleservice=0x0FFFFF851;

  typedef NTSTATUS WINAPI (*NtQuerySystemInformationMy)(
 SYSTEM_INFORMATION_CLASS SystemInformationClass,
 PVOID SystemInformation,
 ULONG SystemInformationLength,
 PULONG ReturnLength
);


  typedef NTSTATUS (*ZwOpenProcessMy)(
PHANDLE ProcessHandle,
ACCESS_MASK DesiredAccess,
POBJECT_ATTRIBUTES ObjectAttributes,
PCLIENT_ID ClientId
);

typedef NTSTATUS WINAPI (*NtQueryInformationProcessMy)(
  __in       HANDLE ProcessHandle,
  __in       PROCESSINFOCLASS ProcessInformationClass,
  __out      PVOID ProcessInformation,
  __in       ULONG ProcessInformationLength,
  __out_opt  PULONG ReturnLength
);

typedef NTSTATUS WINAPI (*NtCloseMy)(
   HANDLE Handle
);

typedef NTSTATUS WINAPI (*NtDeviceIoControlFileMy)(
  __in   HANDLE FileHandle,
  __in   HANDLE Event,
  __in   PIO_APC_ROUTINE ApcRoutine,
  __in   PVOID ApcContext,
  __out  PIO_STATUS_BLOCK IoStatusBlock,
  __in   ULONG IoControlCode,
  __in   PVOID InputBuffer,
  __in   ULONG InputBufferLength,
  __out  PVOID OutputBuffer,
  __in   ULONG OutputBufferLength
);

DeviceIoControlTest();
CreateFileATest();
RegOpenKeyExATest();
CreateServiceATest();
StartServiceATest();
ControlServiceTest();
DeleteServiceTest();
CloseServiceHandleTest();
Process32NextTest();
IsDebuggerPresentTest();
FtpPutFileATest();
//IsDebuggerPresent();
NtQuerySystemInformationTest();
 NtOpenProcessTest();
 CloseHandleTest();
#endif
