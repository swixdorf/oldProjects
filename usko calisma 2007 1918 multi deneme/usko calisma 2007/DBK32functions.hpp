// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dbk32functions.pas' rev: 11.00

#ifndef Dbk32functionsHPP
#define Dbk32functionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Winsvc.hpp>	// Pascal unit
#include <Psapi.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbk32functions
{
//-- type declarations -------------------------------------------------------
typedef BOOL __stdcall (*TDeviceIoControl)(unsigned hDevice, unsigned dwIoControlCode, void * lpInBuffer, unsigned nInBufferSize, void * lpOutBuffer, unsigned nOutBufferSize, unsigned &lpBytesReturned, Windows::POverlapped lpOverlapped);

struct thandlelist
{
	
public:
	unsigned processhandle;
	unsigned processid;
	bool validhandle;
} ;

struct TClient_ID
{
	
public:
	unsigned processid;
	unsigned threadid;
} ;

typedef TClient_ID *PClient_ID;

class DELPHICLASS THookIDTThread;
class PASCALIMPLEMENTATION THookIDTThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
public:
	Byte cpunr;
	bool done;
	bool succeeded;
	virtual void __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TThread.Create */ inline __fastcall THookIDTThread(bool CreateSuspended) : Classes::TThread(CreateSuspended) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~THookIDTThread(void) { }
	#pragma option pop
	
};


class DELPHICLASS THookIDTConstantly;
class PASCALIMPLEMENTATION THookIDTConstantly : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
public:
	virtual void __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TThread.Create */ inline __fastcall THookIDTConstantly(bool CreateSuspended) : Classes::TThread(CreateSuspended) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~THookIDTConstantly(void) { }
	#pragma option pop
	
};


typedef DynamicArray<unsigned >  DBK32functions__3;

class DELPHICLASS TGetIDTThread;
class PASCALIMPLEMENTATION TGetIDTThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
public:
	Byte cpunr;
	bool done;
	virtual void __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TThread.Create */ inline __fastcall TGetIDTThread(bool CreateSuspended) : Classes::TThread(CreateSuspended) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TGetIDTThread(void) { }
	#pragma option pop
	
};


typedef DynamicArray<thandlelist >  DBK32functions__5;

typedef BOOL __stdcall (*TIsWow64Process)(unsigned processhandle, BOOL &isWow);

//-- var, const, procedure ---------------------------------------------------
static const int currentversion = 0x1e8489;
static const Shortint FILE_ANY_ACCESS = 0x0;
static const Shortint FILE_SPECIAL_ACCESS = 0x0;
static const Shortint FILE_READ_ACCESS = 0x1;
static const Shortint FILE_WRITE_ACCESS = 0x2;
static const Shortint FILE_RW_ACCESS = 0x3;
static const Shortint METHOD_BUFFERED = 0x0;
static const Shortint METHOD_IN_DIRECT = 0x1;
static const Shortint METHOD_OUT_DIRECT = 0x2;
static const Shortint METHOD_NEITHER = 0x3;
static const Shortint FILE_DEVICE_UNKNOWN = 0x22;
static const Shortint IOCTL_UNKNOWN_BASE = 0x22;
static const int IOCTL_CE_READMEMORY = 0x22e000;
static const int IOCTL_CE_WRITEMEMORY = 0x22e004;
static const int IOCTL_CE_OPENPROCESS = 0x22e008;
static const int IOCTL_CE_QUERY_VIRTUAL_MEMORY = 0x22e00c;
static const int IOCTL_CE_TEST = 0x22e010;
static const int IOCTL_CE_GETPEPROCESS = 0x22e014;
static const int IOCTL_CE_READPHYSICALMEMORY = 0x22e018;
static const int IOCTL_CE_WRITEPHYSICALMEMORY = 0x22e01c;
static const int IOCTL_CE_GETPHYSICALADDRESS = 0x22e020;
static const int IOCTL_CE_PROTECTME = 0x22e024;
static const int IOCTL_CE_GETCR3 = 0x22e028;
static const int IOCTL_CE_SETCR3 = 0x22e02c;
static const int IOCTL_CE_GETSDT = 0x22e030;
static const int IOCTL_CE_INITIALIZE = 0x22e034;
static const int IOCTL_CE_DONTPROTECTME = 0x22e038;
static const int IOCTL_CE_GETIDT = 0x22e03c;
static const int IOCTL_CE_HOOKINTS = 0x22e040;
static const int IOCTL_CE_DEBUGPROCESS = 0x22e044;
static const int IOCTL_CE_RETRIEVEDEBUGDATA = 0x22e048;
static const int IOCTL_CE_STARTPROCESSWATCH = 0x22e04c;
static const int IOCTL_CE_GETPROCESSEVENTS = 0x22e050;
static const int IOCTL_CE_GETTHREADEVENTS = 0x22e054;
static const int IOCTL_CE_GETVERSION = 0x22e058;
static const int IOCTL_CE_GETCR4 = 0x22e05c;
static const int IOCTL_CE_OPENTHREAD = 0x22e060;
static const int IOCTL_CE_MAKEWRITABLE = 0x22e064;
static const int IOCTL_CE_DEBUGPROCESS_CHANGEREG = 0x22e068;
static const int IOCTL_CE_STOPDEBUGGING = 0x22e06c;
static const int IOCTL_CE_STOP_DEBUGPROCESS_CHANGEREG = 0x22e070;
static const int IOCTL_CE_USEALTERNATEMETHOD = 0x22e074;
static const int IOCTL_CE_ISUSINGALTERNATEMETHOD = 0x22e078;
static const int IOCTL_CE_ALLOCATEMEM = 0x22e07c;
static const int IOCTL_CE_CREATEAPC = 0x22e080;
static const int IOCTL_CE_GETPETHREAD = 0x22e084;
static const int IOCTL_CE_SUSPENDTHREAD = 0x22e088;
static const int IOCTL_CE_RESUMETHREAD = 0x22e08c;
static const int IOCTL_CE_SUSPENDPROCESS = 0x22e090;
static const int IOCTL_CE_RESUMEPROCESS = 0x22e094;
static const int IOCTL_CE_ALLOCATEMEM_NONPAGED = 0x22e098;
static const int IOCTL_CE_GETPROCADDRESS = 0x22e09c;
static const int IOCTL_CE_SETSDTADDRESS = 0x22e0a0;
static const int IOCTL_CE_GETSDTADDRESS = 0x22e0a4;
static const int IOCTL_CE_GETGDT = 0x22e0a8;
static const int IOCTL_CE_SETCR4 = 0x22e0ac;
static const int IOCTL_CE_VMXCONFIG = 0x22e0b4;
extern PACKAGE DynamicArray<unsigned >  cpuidt;
extern PACKAGE unsigned hdevice;
extern PACKAGE DynamicArray<thandlelist >  handlelist;
extern PACKAGE AnsiString driverloc;
extern PACKAGE bool iamprotected;
extern PACKAGE unsigned SDTShadow;
extern PACKAGE unsigned debugport;
extern PACKAGE unsigned processname;
extern PACKAGE unsigned ThreadsProcess;
extern PACKAGE unsigned ThreadListEntry;
extern PACKAGE AnsiString processeventname;
extern PACKAGE AnsiString threadeventname;
extern PACKAGE unsigned processevent;
extern PACKAGE unsigned threadevent;
extern PACKAGE unsigned ownprocess;
extern PACKAGE bool Successfullyloaded;
extern PACKAGE bool usealternatedebugmethod;
extern PACKAGE THookIDTConstantly* hooker;
extern PACKAGE unsigned kernel32dll;
extern PACKAGE bool ioctl;
extern PACKAGE TIsWow64Process IsWow64Process;
extern PACKAGE AnsiString applicationPath;
extern PACKAGE bool __stdcall GetLoadedState(void);
extern PACKAGE void __stdcall useIOCTL(bool use);
extern PACKAGE bool __stdcall test(void);
extern PACKAGE unsigned __stdcall GetGDT(PWORD limit);
extern PACKAGE unsigned __stdcall GetIDTCurrentThread(void);
extern PACKAGE int __stdcall GetIDTs(void * idtstore, int maxidts);
extern PACKAGE int __stdcall GetProcessNameFromPEProcess(unsigned peprocess, char * buffer, unsigned buffersize);
extern PACKAGE unsigned __stdcall GetCR4(void);
extern PACKAGE unsigned __fastcall GetDriverVersion(void);
extern PACKAGE int __stdcall GetProcessNameFromID(unsigned processid, void * buffer, unsigned buffersize);
extern PACKAGE unsigned __stdcall GetThreadsProcessOffset(void);
extern PACKAGE unsigned __stdcall GetThreadListEntryOffset(void);
extern PACKAGE unsigned __stdcall GetProcessnameOffset(void);
extern PACKAGE unsigned __stdcall GetDebugportOffset(void);
extern PACKAGE unsigned __stdcall GetSDTShadow(void);
extern PACKAGE unsigned __stdcall GetSDT(void);
extern PACKAGE BOOL __stdcall GetCR3(unsigned hProcess, unsigned &CR3);
extern PACKAGE BOOL __stdcall SetCR3(unsigned hProcess, unsigned CR3);
extern PACKAGE BOOL __stdcall ProtectMe(unsigned ProtectedProcessID, BOOL denylist, BOOL globaldenylist, char * list, unsigned listsize);
extern PACKAGE BOOL __stdcall UnprotectMe(void);
extern PACKAGE bool __stdcall DBKSuspendThread(unsigned ThreadID);
extern PACKAGE bool __stdcall DBKResumeThread(unsigned ThreadID);
extern PACKAGE bool __stdcall DBKSuspendProcess(unsigned ProcessID);
extern PACKAGE bool __stdcall DBKResumeProcess(unsigned ProcessID);
extern PACKAGE BOOL __stdcall GetPhysicalAddress(unsigned hProcess, void * lpBaseAddress, __int64 &Address);
extern PACKAGE BOOL __stdcall WritePhysicalMemory(unsigned hProcess, void * lpBaseAddress, void * lpBuffer, unsigned nSize, unsigned &NumberOfBytesWritten);
extern PACKAGE BOOL __stdcall ReadPhysicalMemory(unsigned hProcess, void * lpBaseAddress, void * lpBuffer, unsigned nSize, unsigned &NumberOfBytesRead);
extern PACKAGE unsigned __stdcall GetPEThread(unsigned Threadid);
extern PACKAGE unsigned __stdcall GetPEProcess(unsigned ProcessID);
extern PACKAGE BOOL __stdcall IsValidHandle(unsigned hProcess);
extern PACKAGE BOOL __stdcall RPM(unsigned hProcess, void * lpBaseAddress, void * lpBuffer, unsigned nSize, unsigned &NumberOfBytesRead);
extern PACKAGE BOOL __stdcall WPM(unsigned hProcess, void * lpBaseAddress, void * lpBuffer, unsigned nSize, unsigned &NumberOfBytesWritten);
extern PACKAGE unsigned __stdcall OT(unsigned dwDesiredAccess, BOOL bInheritHandle, unsigned dwThreadId);
extern PACKAGE unsigned __stdcall OP(unsigned dwDesiredAccess, BOOL bInheritHandle, unsigned dwProcessId);
extern PACKAGE unsigned __stdcall NtOT(unsigned &Handle, unsigned AccessMask, void * objectattributes, PClient_ID clientid);
extern PACKAGE unsigned __stdcall NOP(unsigned &Handle, unsigned AccessMask, void * objectattributes, PClient_ID clientid);
extern PACKAGE unsigned __stdcall VQE(unsigned hProcess, void * address, _MEMORY_BASIC_INFORMATION &mbi, unsigned bufsize);
extern PACKAGE void * __stdcall VAE(unsigned hProcess, void * lpAddress, unsigned dwSize, unsigned flAllocationType, unsigned flProtect);
extern PACKAGE unsigned __stdcall CreateRemoteAPC(unsigned threadid, void * lpStartAddress);
extern PACKAGE BOOL __stdcall setAlternateDebugMethod(unsigned &int1apihook, unsigned &OriginalInt1handler);
extern PACKAGE BOOL __stdcall getAlternateDebugMethod(void);
extern PACKAGE BOOL __stdcall StopRegisterChange(int regnr);
extern PACKAGE BOOL __stdcall StopDebugging(void);
extern PACKAGE BOOL __stdcall DebugProcess(unsigned processid, unsigned address, Byte size, Byte debugtype);
extern PACKAGE bool __stdcall ChangeRegOnBP(unsigned Processid, unsigned address, int debugreg, bool changeEAX, bool changeEBX, bool changeECX, bool changeEDX, bool changeESI, bool changeEDI, bool changeEBP, bool changeESP, bool changeEIP, bool changeCF, bool changePF, bool changeAF, bool changeZF, bool changeSF, bool changeOF, unsigned newEAX, unsigned newEBX, unsigned newECX, unsigned newEDX, unsigned newESI, unsigned newEDI, unsigned newEBP, unsigned newESP, unsigned newEIP, bool newCF, bool newPF, bool newAF, bool newZF, bool newSF, bool newOF);
extern PACKAGE int __stdcall RetrieveDebugData(void * Buffer);
extern PACKAGE unsigned __stdcall WaitForProcessListData(void * processpointer, void * threadpointer, unsigned timeout);
extern PACKAGE BOOL __stdcall StartProcessWatch(void);
extern PACKAGE bool __stdcall MakeWritable(unsigned Address, unsigned Size, bool copyonwrite);
extern PACKAGE void * __stdcall KernelAlloc(unsigned size);
extern PACKAGE void * __stdcall GetKProcAddress(WideChar * s);
extern PACKAGE bool __stdcall GetSDTEntry(int nr, PDWORD address, System::PByte paramcount);
extern PACKAGE bool __stdcall SetSDTEntry(int nr, unsigned address, Byte paramcount);
extern PACKAGE bool __stdcall GetSSDTEntry(int nr, PDWORD address, System::PByte paramcount);
extern PACKAGE bool __stdcall SetSSDTEntry(int nr, unsigned address, Byte paramcount);
extern PACKAGE bool __stdcall RewriteKernel32(void);
extern PACKAGE bool __stdcall RestoreKernel32(void);
extern PACKAGE int __fastcall CTL_CODE(int DeviceType, int Func, int Method, int Access);
extern PACKAGE BOOL __stdcall InitializeDriver(unsigned Address, unsigned size);
extern PACKAGE bool __fastcall GetWin32KAddress(unsigned &address, unsigned &size);
extern PACKAGE unsigned __stdcall RunDdk(char * patth);

}	/* namespace Dbk32functions */
using namespace Dbk32functions;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dbk32functions
