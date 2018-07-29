//---------------------------------------------------------------------------


#pragma hdrstop

#include "apihook.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

 BYTE *RegOpenKeyExAcopyala;
DWORD aRegOpenKeyExAcopyala;
DWORD cRegOpenKeyExAcopyala;


 BYTE *CreateFileAcopyala;
DWORD aCreateFileAcopyala;
DWORD cCreateFileAcopyala;

BYTE *DeviceIoControlcopyala;//[500];
DWORD aDeviceIoControlcopyala;
DWORD cDeviceIoControlcopyala;



BYTE *CreateServiceAcopyala;
DWORD aCreateServiceAcopyala;
DWORD cCreateServiceAcopyala;

 BYTE *StartServiceAcopyala;
DWORD aStartServiceAcopyala;
DWORD cStartServiceAcopyala;

BYTE *ControlServicecopyala;
DWORD aControlServicecopyala;
DWORD cControlServicecopyala;

BYTE *DeleteServicecopyala;
DWORD aDeleteServicecopyala;
DWORD cDeleteServicecopyala;

BYTE *CloseServiceHandlecopyala;
DWORD aCloseServiceHandlecopyala;
DWORD cCloseServiceHandlecopyala;

BYTE *CloseHandlecopyala;
DWORD aCloseHandlecopyala;
DWORD cCloseHandlecopyala;


BYTE NtDeviceIoControlFilecopyala[500];
DWORD aNtDeviceIoControlFilecopyala;
DWORD cNtDeviceIoControlFilecopyala;

BYTE *Process32Nextcopyala;
DWORD aProcess32Nextcopyala;
DWORD cProcess32Nextcopyala;

BYTE ShellExecuteAcopyala[500];
DWORD aShellExecuteAcopyala;
DWORD cShellExecuteAcopyala;

BYTE IsDebuggerPresentcopyala[500];
DWORD aIsDebuggerPresentcopyala;
DWORD cIsDebuggerPresentcopyala;

BYTE FtpPutFileAcopyala[500];
DWORD aFtpPutFileAcopyala;
DWORD cFtpPutFileAcopyala;

BYTE SetThreadAffinityMaskcopyala[500];
DWORD aSetThreadAffinityMaskcopyala;
DWORD cSetThreadAffinityMaskcopyala;

BYTE *NtQuerySystemInformationcopyala;
DWORD aNtQuerySystemInformationcopyala;
DWORD cNtQuerySystemInformationcopyala;

BYTE *NtOpenProcesscopyala;
DWORD aNtOpenProcesscopyala;
DWORD cNtOpenProcesscopyala;

BYTE NtQueryInformationProcesscopyala[500];
DWORD aNtQueryInformationProcesscopyala;
DWORD cNtQueryInformationProcesscopyala;

BYTE NtClosecopyala[500];
DWORD aNtClosecopyala;
DWORD cNtClosecopyala;


NtQueryInformationProcessMy NtQueryInformationProcessCall;
NtCloseMy NtCloseCall;

BYTE ProcImage[MAX_PATH];


Exefilter ExeEkle[]={{"knightonline.exe"},{"ko_yukle.exe"},{"Cheat Engine.exe"}};
DWORD ExeEklesize=sizeof(ExeEkle)/sizeof(Exefilter);
CreateServiceALog(DWORD *pushlar)
  {
  char aprkon[]="APR";
   if(!lstrcmpiA((char*)pushlar[3],aprkon))
	  {
		return aprhandleservice;
	  }
	 return 0;
  }

  RegOpenKeyExALog(DWORD *pushlar)
  {
	  char aprkon[]="System\\CurrentControlSet\\Services\\SymEvent";
	   if(!lstrcmpiA((char*)pushlar[2],aprkon))
	  {
		return 0;
	  }
	  return 1;
  }

  CreateFileALog(DWORD *pushlar)
  {
	  char aprkon[]="\\\\.\\Apr";
	  if(!lstrcmpiA((char*)pushlar[1],aprkon))
	  {
		return aprhandle;
	  }
	  return 0;

  }

 NtDeviceIoControlFileLog(DWORD *pushlar)
 {


HANDLE FileHandle =(HANDLE)    pushlar[1];
HANDLE Event=  (HANDLE)  pushlar[2];
PIO_APC_ROUTINE ApcRoutine=(PIO_APC_ROUTINE)pushlar[3];
PVOID ApcContext=(PVOID)pushlar[4];
PIO_STATUS_BLOCK IoStatusBlock= (PIO_STATUS_BLOCK )pushlar[5];
ULONG IoControlCode= pushlar[6];
PVOID InputBuffer= (PVOID)pushlar[7];
ULONG InputBufferLength= pushlar[8];
PVOID OutputBuffer= (PVOID)pushlar[9];
ULONG OutputBufferLength= pushlar[10];
NtDeviceIoControlFileMy     CallAdress=(NtDeviceIoControlFileMy ) &NtDeviceIoControlFilecopyala[13+7];

   //0x4022c3
if((DWORD)FileHandle!= aprhandle)
{
	  return CallAdress(FileHandle,
  Event,
  ApcRoutine,
ApcContext,
IoStatusBlock,
IoControlCode,
 InputBuffer,
 InputBufferLength,
OutputBuffer,
 OutputBufferLength
);

}
/* if(*(DWORD*)&pushlar[0x18]==0x88112023)
{
  *(DWORD*)& pushlar[0x24]=	(DWORD)GetCurrentProcessId();
   return 0;
}     */

if(IoControlCode==0x88112003)
{
  *(DWORD*)& pushlar[9]=	(DWORD)GetCurrentProcessId();
   return 0;
}

if(IoControlCode==0x8811200B)
{
   *(DWORD*)&	pushlar[9]=0;
	return 0;
}
else
{
/*
String a;
int code= IoControlCode;
a=IntToHex(code,8);
MessageBoxExA(0,a.c_str(),a.c_str(),0,0);  */
return 0;
}


return 0;
 }
 /////////////////



  StartServiceALog(DWORD *pushlar)
  {
	  //  return 0;
	 if(pushlar[1]== aprhandleservice)
	 {
		 return 1;
	 }

	if(pushlar[1]== aprhandle)
	 {
		 return 1;
	 }


	 return 0;
  }

  CloseServiceHandleTest()
  {
	   int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("advapi32.dll"),"CloseServiceHandle");

   CloseServiceHandlecopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
  //	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)CloseServiceHandlecopyala,500);
   HOOKHazirla1(StartServiceALog,
   cCloseServiceHandlecopyala,
   (void*)a,
   Faketopla,
   CloseServiceHandlecopyala,
   6+2,
   size,
   aCloseServiceHandlecopyala,(PBYTE)"\x8b\xFF",0x4,(PBYTE)"\x74\5");

  }

  DeleteServiceTest()
  {

  int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("advapi32.dll"),"DeleteService");

   DeleteServicecopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
  //	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)DeleteServicecopyala,500);
   HOOKHazirla1(StartServiceALog,
   cDeleteServicecopyala,
   (void*)a,
   Faketopla,
   DeleteServicecopyala,
   6+2,
   size,
   aDeleteServicecopyala,(PBYTE)"\x8b\xFF",0x4,(PBYTE)"\x74\5");

  }

 ControlServiceTest()
 {
		int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("advapi32.dll"),"ControlService");

   ControlServicecopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
  //	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)ControlServicecopyala,500);
   HOOKHazirla1(StartServiceALog,
   cControlServicecopyala,
   (void*)a,
   Faketopla,
   ControlServicecopyala,
   6+2,
   size,
   aControlServicecopyala,(PBYTE)"\x8b\xFF",0xc,(PBYTE)"\x74\5");

 }

  ///////////////


  StartServiceATest()
  {
	int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("advapi32.dll"),"StartServiceA");

   StartServiceAcopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
  //	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)StartServiceAcopyala,500);
   HOOKHazirla1(StartServiceALog,
   cStartServiceAcopyala,
   (void*)a,
   Faketopla,
   StartServiceAcopyala,
   6+2,
   size,
   aStartServiceAcopyala,(PBYTE)"\x8b\xFF",0xc,(PBYTE)"\x74\5");

  }
 //////////////////////////////////
 CreateServiceATest()
 {

  int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("advapi32.dll"),"CreateServiceA");

   CreateServiceAcopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
  //	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)CreateServiceAcopyala,500);
   HOOKHazirla1(CreateServiceALog,
   cCreateServiceAcopyala,
   (void*)a,
   Faketopla,
   CreateServiceAcopyala,
   6+2,
   size,
   aCreateServiceAcopyala,(PBYTE)"\x8b\xFF",0x34,(PBYTE)"\x74\5");

 }
 ///////////////////////////


 RegOpenKeyExATest()
 {
   int cops;
 BYTE *oku= (BYTE*)Faketopla;

  BYTE *a= (BYTE *)GetProcAddress(LoadLibraryA("advapi32.dll"),"RegOpenKeyExA");

   RegOpenKeyExAcopyala =  (BYTE *)malloc(500);;

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)RegOpenKeyExAcopyala,500);
   HOOKHazirla1(RegOpenKeyExALog,
   cRegOpenKeyExAcopyala,
   (void*)a,
   Faketopla,
   RegOpenKeyExAcopyala,
   6+2,
   size,
   aRegOpenKeyExAcopyala,(PBYTE)"\x8b\xFF",0x14,(PBYTE)"\x75\5");

 }
  ////////////////
  FtpPutFileATest()
  {
	   BYTE *a= (BYTE *)GetProcAddress(LoadLibraryA("wininet.dll"),"FtpPutFileA");
   MEMwrite(a,(void*)	(PBYTE)"\x8b\xFF" ,2);
  MEMwrite(&a[2],(void*)(PBYTE)"\xB8\x01\00\00\00\xC2\x14",7);
  }

 ////////////////////////////
  IsDebuggerPresentTest()
  {

   BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("kernel32.dll"),"IsDebuggerPresent");
   MEMwrite(a,(void*)	(PBYTE)"\x8b\xFF" ,2);
  MEMwrite(&a[2],(void*)(PBYTE)"\x33\xc0\xc3",3);
  }
  ///////////////////
 typedef BOOL WINAPI (*Process32NextMy)(
  HANDLE hSnapshot,
   LPPROCESSENTRY32 lppe
);
  Process32NextLog(DWORD *pushlar)
  {

	bool ret;
    char aprkon[]="knightonline.exe";
  HANDLE hSnapshot = (HANDLE) pushlar[1];
  LPPROCESSENTRY32 tara = (LPPROCESSENTRY32) pushlar[2];

  Process32NextMy CallAdress=(Process32NextMy)&Process32Nextcopyala[13+7];
   Devam:
   ret =CallAdress(hSnapshot,tara);
		 if(ret)
   {

	  if(!FilterName(tara->szExeFile,&ExeEkle[0],ExeEklesize))
	  {
		 goto Devam;
	  }
  }

	  return ret;
  }

  Process32NextTest()
 {
	int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("kernel32.dll"),"Process32Next");

   Process32Nextcopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)Process32Nextcopyala,500);
   HOOKHazirla1(Process32NextLog,
   cProcess32Nextcopyala,
   (void*)a,
   Faketopla,
   Process32Nextcopyala,
   6+2,
   size,
   aProcess32Nextcopyala,(PBYTE)"\x8b\xFF",0x8,(PBYTE)"\x90\x90");

 }

 ///////////////////////////
 typedef   BOOL
WINAPI
(*CloseHandleMy)(
	DWORD Handle
	)  ;
  CloseHandleLog(DWORD *pushlar)
  {
	BOOL       ret;
  CloseHandleMy     CallAdress=(CloseHandleMy ) &CloseHandlecopyala[13+7];
	 if(pushlar[1]== aprhandleservice)
	 {
		 return 1;
	 }

	if(pushlar[1]== aprhandle)
	 {
		 return 1;
	 }
			 try
	  {

	  ret=	 CallAdress( pushlar[1]);

	  }
		catch(...)
	  {
	  return 1;
	  }
	 return ret;
  }
   CloseHandleTest()
 {
	int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("kernel32.dll"),"CloseHandle");

   CloseHandlecopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)CloseHandlecopyala,500);
   HOOKHazirla1( CloseHandleLog,
   cCloseHandlecopyala,
   (void*)a,
   Faketopla,
   CloseHandlecopyala,
   6+2,
   size,
   aCloseHandlecopyala,(PBYTE)"\x8b\xFF",0x4,(PBYTE)"\x90\0x90");

 }



 CreateFileATest()
 {
	int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("kernel32.dll"),"CreateFileA");

   CreateFileAcopyala = (BYTE *)malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)CreateFileAcopyala,500);
   HOOKHazirla1(CreateFileALog,
   cCreateFileAcopyala,
   (void*)a,
   Faketopla,
   CreateFileAcopyala,
   6+2,
   size,
   aCreateFileAcopyala,(PBYTE)"\x8b\xFF",0x1c,(PBYTE)"\x74\5");

 }
 bool  WINAPI  ProcKontRolEt(HANDLE ProcId)
  {
	HANDLE phandle;
    char *pname;
   char aprkon[]="knightonline.exe";
ACCESS_MASK DesiredAccess;
OBJECT_ATTRIBUTES ObjectAttributes;
CLIENT_ID ClientId  ;
  BYTE *ProcPathNe= (BYTE *)malloc(MAX_PATH);
memset(&ObjectAttributes,0, sizeof(ObjectAttributes));
memset(&ClientId,0,sizeof(CLIENT_ID));
ObjectAttributes.Length=sizeof(ObjectAttributes);
bool ret;
							ClientId.UniqueProcess=  ProcId;
						  NtOpenProcessMy(&phandle,0x400,&ObjectAttributes,&ClientId);
						//phandle= OpenProcess(0x400,0,(ULONG)ProcID)  ;
						GetProcessImageFileNameA(phandle,ProcPathNe,MAX_PATH);
					 pname=	GetFileName(ProcPathNe);
				CloseHandle(phandle);
   ret= lstrcmpiA(pname,aprkon)   ;
  free( ProcPathNe);
  return ret;
  }

  DWORD WINAPI myNtQuerySystemInformation(DWORD d1, PDWORD pd1, DWORD d2, PDWORD p1)
{
     NtQuerySystemInformationMy CallAdress=(NtQuerySystemInformationMy)&NtQuerySystemInformationcopyala[13+7];
  /*
 LONG ret=	CallAdress( SystemInformationClass,
 SystemInformation,
 SystemInformationLength ,
 ReturnLength)   ; */
	DWORD ret =CallAdress(d1, pd1, d2, p1);

	int err=GetLastError();

	if(d1 ==5)
	{
		char fname[128];
		PROCESS_INFO *p1, *p2, *p =(PROCESS_INFO *)pd1;
		
		p1 =p;
		p2 =NULL;

		while(((DWORD)p-(DWORD)pd1 <(DWORD)d2) && p1->NextEntryDelta !=0)
		{     try{
			if(p->ProcessName.Buffer !=NULL)
			{
				int len =WideCharToMultiByte( CP_ACP, 0, p->ProcessName.Buffer, -1, fname, 128,NULL,NULL);
				fname[len] =0;

				//WriteLog("NtQuery:fname=%s", fname);
			  //	if(!lstrcmpiA(fname,"knightonline.exe") )
					 if((!FilterName(fname,&ExeEkle[0],ExeEklesize)) ||(p->ProcessId==GetCurrentProcessId() ))
				{
					if(p2) p2->NextEntryDelta +=p->NextEntryDelta;
					else
					{
						//if(p->NextEntryDelta)
						p1->NextEntryDelta += p->NextEntryDelta;
						p2 =p1;
					}
					//WriteLog("*********NtQuery:fname=%s", fname);
				}
				else p2 =NULL;
				//WriteLog("NtQuery:fname=%s", fname);
			}
         }
   catch(...) {goto DevamEtProc;}
		   DevamEtProc:
			p1 =p;
			p =(PROCESS_INFO *)((char *)p+p->NextEntryDelta);
		}
		if(p2)
			p2->NextEntryDelta =0;
		//WriteLog("okkkkkkkkkkkkkkkkkkkkkkkkkkkkkk,p2=%x", p2);
	}
	SetLastError(err);

	return ret;
}

  NtQuerySystemInformationLog(DWORD *pushlar)
 {

 /* SYSTEM_INFORMATION_CLASS SystemInformationClass=(SYSTEM_INFORMATION_CLASS)pushlar[1];
 PVOID SystemInformation= (PVOID) pushlar[2];
ULONG SystemInformationLength= pushlar[3];
 PULONG ReturnLength = (PULONG)pushlar[4];
  SYSTEM_PROCESS_INFORMATION *oldp;
 SYSTEM_PROCESS_INFORMATION *psys;
 SYSTEM_PROCESS_INFORMATION *csys;
  ULONG ProcID ;              */

   return	myNtQuerySystemInformation((DWORD)pushlar[1],(PDWORD)pushlar[2],(DWORD)pushlar[3],(PDWORD)pushlar[4]);


// ZwOpenProcessMy OpenProcessMy=(ZwOpenProcessMy)&NtOpenProcesscopyala[13+7];


	/*
  NtQuerySystemInformationMy CallAdress=(NtQuerySystemInformationMy)&NtQuerySystemInformationcopyala[13+7];

 LONG ret=	CallAdress( SystemInformationClass,
 SystemInformation,
 SystemInformationLength ,
 ReturnLength)   ;
	if(ret!=STATUS_SUCCESS)
  {
	   return ret;
  }
  if( SystemInformationClass!=5)
  {
	 return ret;
  }
			PROCESS_INFO *pp;

			SYSTEM_PROCESS_INFORMATION *curr = (SYSTEM_PROCESS_INFORMATION *)SystemInformation;
			SYSTEM_PROCESS_INFORMATION *prev = NULL;

			while(curr)

			{

			pp =  (PROCESS_INFO*)curr;

			try{
						ProcID =(ULONG) curr->UniqueProcessId;

						}
						catch(...)
						{
						  goto ProcDevam;
						}
						  if((ProcID==4)||( ProcID==0))
						  {goto ProcDevam;}


			   if(!ProcKontRolEt(curr->UniqueProcessId))
				 {

						if(prev)
						{
							if(curr->NextEntryOffset)
							{
								prev->NextEntryOffset += curr->NextEntryOffset;
							}
							else
							{
								prev->NextEntryOffset = 0;
							}
						}
						else
						{
							if(curr->NextEntryOffset)
							{
								(char *)SystemInformation += curr->NextEntryOffset;
							}
							else
							{
								SystemInformation = NULL;
							}
						}


				}

				 ProcDevam:
				 try{
				prev = curr;
				if(curr->NextEntryOffset)
				{

				(char *)curr += curr->NextEntryOffset;

				 }
				else
			   {
			   	curr = NULL;}
				}
				 catch(...)
				   {
				 curr = prev;
                     break;
				   }
			}


return  ret; */
}


NtQuerySystemInformationTest()
{

   int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("ntdll.dll"),"NtQuerySystemInformation");

	 NtQuerySystemInformationcopyala =(BYTE*) malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)NtQuerySystemInformationcopyala,500);
   HOOKHazirla1(NtQuerySystemInformationLog,
   cNtQuerySystemInformationcopyala,
   (void*)a,
   Faketopla,
   NtQuerySystemInformationcopyala,
   6+2,
   size,
   aNtQuerySystemInformationcopyala,(PBYTE)"\x8b\xFF",0x10,(PBYTE)"\x90\x90");



}

 long WINAPI ImageControl(HANDLE ProcessHandle,long ret)
  {

 // UNICODE_STRING image;
//  NtQueryInformationProcessCall = (NtQueryInformationProcessMy) GetProcAddress(GetModuleHandle("ntdll.dll"),"NtQueryInformationProcess");
//  NtCloseCall = (NtCloseMy) GetProcAddress(GetModuleHandle("ntdll.dll"),"NtClose");
 // NtQueryInformationProcessCall(ProcessHandle,0x1b,&image,0x800,0);
   char aprkon[]="knightonline.exe";
   GetProcessImageFileNameA(ProcessHandle,ProcImage,MAX_PATH);
	char *pname=	GetFileName(ProcImage);

if(!lstrcmpiA(pname,aprkon))
{
CloseHandle(ProcessHandle);

  return 0x0C000000D;
}
  return ret;

  }

  NtOpenProcessLog(DWORD *pushlar)
  {


PHANDLE ProcessHandle=(PHANDLE)pushlar[1]  ;
ACCESS_MASK DesiredAccess=(ACCESS_MASK)pushlar[2];
POBJECT_ATTRIBUTES ObjectAttributes=(POBJECT_ATTRIBUTES)pushlar[3];
PCLIENT_ID ClientId  =(PCLIENT_ID)pushlar[4];


// ZwOpenProcessMy CallAdress=(ZwOpenProcessMy)&NtOpenProcesscopyala[13+7];

	long ret= NtOpenProcessMy(ProcessHandle,DesiredAccess,ObjectAttributes, ClientId);   // CallAdress(ProcessHandle,DesiredAccess,ObjectAttributes, ClientId);



		   ret=	 ImageControl(ProcessHandle[0],ret);

  return ret;
}
 NtOpenProcessTest()
{

   int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("ntdll.dll"),"NtOpenProcess");

	 NtOpenProcesscopyala =(BYTE*) malloc(500);
	 MEMwrite((void*)NtOpenProcessMy,a,(int)((DWORD)NtOpenProcessMyNop-(DWORD)NtOpenProcessMy));
	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)NtOpenProcesscopyala,500);
   HOOKHazirla1(NtOpenProcessLog,
  cNtOpenProcesscopyala,
   (void*)a,
   Faketopla,
   NtOpenProcesscopyala,
   6+2,
   size,
   aNtOpenProcesscopyala,(PBYTE)"\x8b\xFF",0x10,(PBYTE)"\x90\x90");



}


DeviceIoControlTest()
{
int cops;
 BYTE *oku= (BYTE*)Faketopla;
  BYTE *a= (BYTE *)GetProcAddress(GetModuleHandle("ntdll.dll"),"NtDeviceIoControlFile");

	 DeviceIoControlcopyala = (BYTE*) malloc(500);

	int size=(int)(DWORD)Nopla-(DWORD)Faketopla;
	  MakeMemoryWritable( (DWORD)Faketopla,size);
	   MakeMemoryWritable( (DWORD)DeviceIoControlcopyala,500);
   HOOKHazirla1(NtDeviceIoControlFileLog,
   cNtDeviceIoControlFilecopyala,
   (void*)a,
   Faketopla,
   NtDeviceIoControlFilecopyala,
   6+2,
   size,
   aNtDeviceIoControlFilecopyala,(PBYTE)"\x8b\xFF",0x28,(PBYTE)"\x90\x90");
}

