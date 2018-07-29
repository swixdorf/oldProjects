//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "ffrmBot.h"
#include "DBK32functions.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;






typedef struct
{
 DWORD Par1 ;
 BYTE  Data[2048];
 DWORD DataUzunluk;
 DWORD Par3 ;
 DWORD RetNe;
}MyDataStruct;

  TFileStream * dosyakitle;
  HANDLE Myfile;
  unsigned long  aFileSize  ;
  char ExePath[MAX_PATH] ;
  

int WINAPI Bekle(PVOID Event);

 AnsiString BufferToHex(char *buf,int size)
{
String str;
for(int i=0;i<size;i++)
{
BYTE a=buf[i];
str+="0x"+IntToHex(a,2)+",";
}
return str;
}

const DWORD Kontrol=0x0093C1B0;//0x008CD0FA;//0x008CD06A;
const DWORD KotrolDeger=0xFFF9FBE8;//E8 61 E4 FF//0xFFE461E8;
//const DWORD Kontrol=0x0097F2C2 ;//0x008CD0FA;//0x008CD06A;
//const DWORD KotrolDeger=0xfbcd79E8;//E8 79 CD FB FF  //E8 61 E4 FF//0xFFE461E8;



const DWORD Calisupdate=0x93BBB0;//0X8CB560;//0x8CB4D0;

DWORD HSDriver1=0x0092EDB0;//0x8BE270;
DWORD HSDriver2=0x0092EEB0;//0x8BABB0;
DWORD HSDriver3=0x0092EEF0;//0x8BABF0;



const DWORD KODEVAM= 0x0093C2B1;//0x008CD1D7 ;

const DWORD Dllbase=0x00C54D18;//0xD1CA60;


const DWORD DllProc10=0x00C54D2C;//0xD1CA70;

const DWORD DllKon=0xC54D20;

const HSDCALL   =0x00976708;//0x9C6FF8 ;

const PencereName=0x00A8B404;//0x00A8FD80;
BYTE ORJCODE[10];

 //char DLLPATH[MAX_PATH];

 STARTUPINFO si;
PROCESS_INFORMATION pi;

DLLInject( String DllName)
 {
BYTE *Paramaters=NULL;                   //00797640
HANDLE Thread=NULL;
DWORD    ThreadId;
DWORD bytes=NULL;
DWORD   ExitCodeAdres=NULL;
//DWORD  ExitKOAdres=0x007E4144;//1474 0x007E3138;
WORD PrmNop=0xE990;
BYTE Dallan=0xEB;
unsigned char ExitCode[12] = {
	0x55, 0x8B, 0xEC, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x5D, 0xC2, 0x08, 0x00
};
     //006E4270       //prm
	// 0F 8C 19 01 00 00
	// 90 E9 19 01 00 00
// String path= ExtractFilePath(Application->ExeName);
 unsigned char DLL[MAX_PATH];
 String path=DllName;
 strcpy(DLL,path.c_str());
 Paramaters  =(BYTE *) VirtualAllocEx(pi.hProcess, NULL,1024, MEM_COMMIT, PAGE_READWRITE);
              WriteProcessMemory(pi.hProcess, Paramaters, DLL, sizeof(DLL), &bytes);
              ExitCodeAdres=(DWORD)Paramaters;
			  ExitCodeAdres+=500;
            // WriteProcessMemory(pi.hProcess,(void*)ExitCodeAdres , ExitCode, sizeof(ExitCode), &bytes);
             // WriteProcessMemory(pi.hProcess,(void*)0x006E4270 ,&PrmNop,2, &bytes);
		   //   WriteProcessMemory(pi.hProcess,(void*)ExitKOAdres , &ExitCodeAdres, 4, &bytes);
          //    WriteProcessMemory(pi.hProcess,(void*)0x006E416D ,&Dallan,1, &bytes);
		  //	WriteProcessMemory(pi.hProcess,(void*)0x006E420A ,&PrmNop,2, &bytes);
			Thread = CreateRemoteThread(pi.hProcess,0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("KERNEL32.DLL"), "LoadLibraryA"), (LPVOID)Paramaters, 0, &ThreadId);
            WaitForSingleObject(Thread, INFINITE);
            VirtualFreeEx(pi.hProcess, Paramaters, 0, MEM_RELEASE);
			CloseHandle(Thread);
}


 bool DllRunLancur(String KoPathNe,String DllBotName)
{
char buf[MAX_PATH] ;

//GetModuleFileName(hInst,buf,MAX_PATH);
String DllPath= ExtractFilePath(DLLPATH);
//ShowMessage(DllPath);
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
 String KoPath=KoPathNe;
  String FileName=KoPath+"KnightOnLine.exe"  ;
 // ShowMessage(FileName);
 String Calis="\""+FileName+"\" "+IntToStr(GetCurrentProcessId());
 CreateProcess(FileName.c_str(),Calis.c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,KoPath.c_str(),&si,&pi);
 DllPath=DllPath+DllBotName;//"hsdur.dll";//"loader.dll";
 DLLInject(DllPath);

 //ShowMessage("lancur yukle"+FileName);

 //TerminateProcess(pi.hProcess,0)  ;
}
 inline void ErasePEHeaderFromMemory()
{
    DWORD OldProtect = 0;
    
    // Get base address of module
    char *pBaseAddr = (char*)GetModuleHandle(NULL);

    // Change memory protection
	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
            PAGE_READWRITE, &OldProtect);

    // Erase the header
    ZeroMemory(pBaseAddr, 4096);
}

void EraseHeaders(HINSTANCE hModule)
{
	PIMAGE_DOS_HEADER pDoH;
	PIMAGE_NT_HEADERS pNtH;
	DWORD i, ersize, protect;

	if (!hModule) return;

	pDoH = (PIMAGE_DOS_HEADER)(hModule);

	pNtH = (PIMAGE_NT_HEADERS)((LONG)hModule + ((PIMAGE_DOS_HEADER)hModule)->e_lfanew);

	ersize = sizeof(IMAGE_DOS_HEADER);
	if ( VirtualProtect(pDoH, ersize, PAGE_READWRITE, &protect) )
	{
		for ( i=0; i < ersize; i++ )
			*(BYTE*)((BYTE*)pDoH + i) = 0;
			ShowMessage("CalisMesaj1");
	}

	ersize = sizeof(IMAGE_NT_HEADERS);
	if ( pNtH && VirtualProtect(pNtH, ersize, PAGE_READWRITE, &protect) )
	{
		for ( i=0; i < ersize; i++ )
			*(BYTE*)((BYTE*)pNtH + i) = 0;
			ShowMessage("CalisMesaj1");
	}
	return;
}


void MemWrite(void *adr, void *ptr, int size)
{
DWORD OldProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &OldProtection);
memcpy(adr,ptr,size);
 //ShowMessage("1");
VirtualProtect(adr,size,OldProtection, &OldProtection);
}


	void __fastcall CalisMesaj()
{          //00C57000
		//   Timer1
		  MemWrite((void*)Kontrol,ORJCODE,10);
	   //	  EraseHeaders((HINSTANCE)0X400000 );

	//   ErasePEHeaderFromMemory();
  //	VirtualUnlock((void*)0X00C57000,0);

  //	VirtualUnlock((void*)0X00C57000,0x17000);
//	VirtualFree((void*)0X00C57000,15000, MEM_RELEASE);
//Form2->Memo1->Lines->Add(IntToStr(GetLastError()))  ;
//	VirtualFree((void*)0X00C57000,15000, MEM_RELEASE);
//Form2->Memo1->Lines->Add(IntToStr(GetLastError()))  ;


  //	VirtualProtect((void*)0X00C57000, 0x17000, // Assume x86 page size
	 //		PAGE_READWRITE, 0);

		 //	UnmapViewOfFile((void*)0X00C57000);
   //	free((void*)0X00C57000);
           char szModule[MAX_PATH];
//GetModuleFileName( NULL, szModule, MAX_PATH );
//DeleteFile( szModule )  ;
    // Erase the header
 //ZeroMemory((void*)0X00C57000, 0x17000);
	//VirtualFree((void*)0X00C57000, 0x17000, MEM_RELEASE);
  //	RunDdk(DLLPATH);
  //	ProtectMe(GetCurrentProcessId(),0,0,0,0);
//	  ShowMessage("CalisMesaj dur");
//
//		  Form1->Memo1->Lines->Add("Calisti" );
//		 *(DWORD*)Dllbase =(DWORD)hInstance ;
//		 *(DWORD*)DllProc10 =(DWORD)_10;
//
//		 *(DWORD*)DllKon =0;
//
		 String IDNE=IntToHex((int)GetCurrentProcessId(),8);

		 //strcpy((char*)PencereName,IDNE.c_str());

		 strcpy((char*)0x00A8B454,IDNE.c_str());

		 HANDLE v5; // esi@1

  v5 = CreateEventA(0, 1, 0, "Global\\EF81BA4B-4163-44f5-90E2-F05C1E49C12D");
  SetEvent(v5);
  CloseHandle(v5);
 

	 //RunBoot();


}

__declspec(naked)Dondur1()
{
asm{
	pusha
	call CalisMesaj
	popa
	mov eax,0x0093C1BD//KODEVAM
	mov [esp+0],eax

	RET

	
}

}

BYTE responseserver[0x194];
char ResponsePacket[2048];
 int ResponsePacketsize=0;
SenPacket(int size,BYTE *Giden)
{
    return 1;
}

   int WINAPI RunKoMulti(int x)
   {
   DllRunLancur(ExtractFilePath(Application->ExeName),"koyukledll.dll");
   //ShowMessage("ko calisti");
 
  //  aFileSize =   GetFileSize(Myfile,0);

  // LockFile(Myfile,0,0,aFileSize,0);
	ResumeThread(pi.hThread);
   HWND hWND;
   MyDataStruct HSPar,HSPar1;
   String prncrne=IntToStr(pi.dwProcessId+20000) ;
   hAra:

	hWND=FindWindowA(0,prncrne.c_str()) ;

if(!hWND)
{
	goto  hAra;
}
//ShowMessage("RunKoMulti gelen 1");
		   Form2->HSClinet->Port=pi.dwProcessId+20000;
		   Form2->HSClinet->Active=true;
		   memset(&HSPar,0,sizeof(MyDataStruct));

		   HSPar.Par1=0xD;
			HSPar.DataUzunluk =ResponsePacketsize;
			memcpy(&HSPar.Data,(char*) ResponsePacket,ResponsePacketsize);

			Form2->HSClinet->Socket->SendBuf(&HSPar,sizeof(MyDataStruct));


			int len=Form2->HSClinet->Socket->ReceiveBuf(&HSPar1,sizeof(MyDataStruct));
			memcpy( responseserver,HSPar1.Data,0x194);
			Form2->HSClinet->Active=false;

			//ShowMessage("RunKoMulti gelen dur2");

			BYTE Komut[1024];
		Komut[0]=0xb0;
		Komut[1]=1;
	  //	ShowMessage("RunKoMulti gelen dur3");
		DWORD count= *(DWORD*)&responseserver[0x190];
	   *(WORD*)	 &Komut[2]=(WORD)count;
	   
		ShowMessage("RunKoMulti=  "+IntToStr(count));
		memcpy(&Komut[4],responseserver,count);
		_CPacket.PSend(Komut,count+4);
         //aFileSize =   GetFileSize(Myfile,0);

//UnlockFile(Myfile,0,0,aFileSize,0);
	  //  MessageBox(0,"respose kon 1","giiti!1",0);

   }
WINAPI ResponseThreadAc(int respacket,int respacsize)
   {
	  memcpy((void*)ResponsePacket,(void*)respacket,respacsize);
	 ResponsePacketsize=respacsize ;

	// String size=StrToInt(size);

	// MessageBox(0,size.c_str(),size.c_str(),0);
   //	ShowMessage("ResponseThreadAc "+IntToHex(respacsize,8));
  //	ShowMessage("ResponseThreadAc1 "+IntToHex(respacket,8));
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)RunKoMulti,NULL,0,0);

   }

 __declspec(naked)ReponseGelen()
 {
	 asm{
		   mov     ecx, [esp+8]
		   mov     edx, [esp+4]
		   push ecx
		   push edx
		   call ResponseThreadAc
		   ret    8

	 }
 }
	  yedek_ReponsePach[6];
void WINAPI ReponsePach()
{
	DWORD adr = 0x92F390 ;//(DWORD)GetProcAddress(GetModuleHandleA("kernel32"),"CreateThread");

	ReadProcessMemory((void*)-1,(void*)adr,(void*)ReponsePach,6,0);

	BYTE yama[] = {0x68,0,0,0,0,0xC3};
	*(DWORD*)(yama+1) = (DWORD)ReponseGelen;

	WriteProcessMemory((void*)-1,(void*)adr,(void*)yama,6,0);
}
 yedek_createThread[6];
HANDLE WINAPI myFileCreateFile(
  __in      LPCTSTR lpFileName,
  __in      DWORD dwDesiredAccess,
  __in      DWORD dwShareMode,
  __in_opt  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  __in      DWORD dwCreationDisposition,
  __in      DWORD dwFlagsAndAttributes,
  __in_opt  HANDLE hTemplateFile
);


void WINAPI hookyap_FileCreateFile()
{
	DWORD adr = (DWORD)GetProcAddress(GetModuleHandleA("kernel32"),"CreateFileA");

	ReadProcessMemory((void*)-1,(void*)adr,(void*)yedek_createThread,6,0);

	BYTE yama[] = {0x68,0,0,0,0,0xC3};
	*(DWORD*)(yama+1) = (DWORD)myFileCreateFile;

	WriteProcessMemory((void*)-1,(void*)adr,(void*)yama,6,0);
}
void hookboz_FileCreateFile()
{
	DWORD adr = (DWORD)GetProcAddress(GetModuleHandleA("kernel32"),"CreateFileA");
	WriteProcessMemory((void*)-1,(void*)adr,(void*)yedek_createThread,6,0);
}


HANDLE WINAPI myFileCreateFile(
  __in      LPCTSTR lpFileName,
  __in      DWORD dwDesiredAccess,
  __in      DWORD dwShareMode,
  __in_opt  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  __in      DWORD dwCreationDisposition,
  __in      DWORD dwFlagsAndAttributes,
  __in_opt  HANDLE hTemplateFile
)
{
	String dosyaname=String(lpFileName);


HANDLE ret;
if(dosyaname==String(ExePath))
{
	 dosyaname= ExtractFilePath(ExePath)+"KnightOnLine.exe";
	 MessageBoxA(0,ExePath,ExePath,0)   ;
 //  ShowMessage(dosyaname);

}
	  hookboz_FileCreateFile();
	 ret= CreateFile(dosyaname.c_str(),
		dwDesiredAccess,
  dwShareMode,
lpSecurityAttributes,
dwCreationDisposition,
dwFlagsAndAttributes,
hTemplateFile);
hookyap_FileCreateFile();
   return ret;

}

void procbekle()
{
Don:
	  if (*(DWORD*)(Kontrol)!=KotrolDeger) {
		  goto Don;
	  }

	memcpy(ORJCODE,(void*)Kontrol,10);
	 DWORD d=(DWORD)  Dondur1;
d=(d-Kontrol);
d-=5;
*(DWORD*)(Kontrol+1)=d;


GetModuleFileName(0,ExePath,MAX_PATH);

//dosyakitle = new TFileStream(ExePath,fmShareDenyRead);

//Myfile= CreateFile(buf,GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
//aFileSize =   GetFileSize(Myfile,0);
//LockFile(Myfile,0,0,aFileSize,0);

//hookyap_FileCreateFile();

//dosyakitle->
//ReponsePach();
}



//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
//	 procbekle();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::HSServerClientError(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	 ErrorCode=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::HSClinetError(TObject *Sender, TCustomWinSocket *Socket,
	  TErrorEvent ErrorEvent, int &ErrorCode)
{
     ErrorCode=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
DllRunLancur(ExtractFilePath(Application->ExeName),"koyukledll.dll");
//   ShowMessage("ko calisti");
	ResumeThread(pi.hThread);	
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{

LockFile(Myfile,0,0,aFileSize,0);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{

aFileSize =   GetFileSize(Myfile,0);

UnlockFile(Myfile,0,0,aFileSize,0);
}
//---------------------------------------------------------------------------
BYTE GelenCode[2048];
GelenHazirla1()
{
ShowMessage(IntToHex((int)&GelenCode[0],8));
  memcpy(GelenCode,(void*)(DWORD)0x0917820  ,2048);
  DWORD Adress=(DWORD)&GelenCode[0x0091784A- 0x0917820];
  DWORD caldeger=((DWORD)0x47D4A0-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;

Adress=(DWORD)&GelenCode[0x0091788A- 0x0917820];
caldeger=((DWORD)0xA238CC-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;

Adress=(DWORD)&GelenCode[0x009178A3- 0x0917820];
caldeger=((DWORD)0xA238CC-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;


 Adress=(DWORD)&GelenCode[0x00917925- 0x0917820];
caldeger=((DWORD)0x461650-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;

 Adress=(DWORD)&GelenCode[0x0091798A- 0x0917820];
caldeger=((DWORD)0xA238CC-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;


  Adress=(DWORD)&GelenCode[0x009179A3- 0x0917820];
caldeger=((DWORD)0xA238CC-Adress)-5;
  Adress++;
 *(DWORD*)Adress=caldeger;

BYTE *gelenyolla=&GelenCode[0x009178FB - 0x0917820];
memset(gelenyolla,0x90,14);
gelenyolla[0]=0x8d;
gelenyolla[1]=0x54;
gelenyolla[2]=0x24;
gelenyolla[3]=0x14;
gelenyolla[4]=0x52;
gelenyolla[5]=0x50;

gelenyolla[6]=0x90;
gelenyolla[7]=0x90;
gelenyolla[8]=0x90;
gelenyolla[9]=0xb8;
*(DWORD*)&gelenyolla[10]=(DWORD)ProcessRecva;



gelenyolla=&GelenCode[0x009179C3- 0x0917820];
memset(gelenyolla,0x90,10);
gelenyolla[0]=0x52;
gelenyolla[1]=0x90;
gelenyolla[2]=0x90;
gelenyolla[3]=0x90;
gelenyolla[4]=0xb8;
*(DWORD*)&gelenyolla[5]=(DWORD)ProcessRecva;

}
DWORD IndexAl( DWORD *IndexNe)
{



asm{



				push    IndexNe
				push    4
				push    0xD74DEC
				push    1
			   mov eax,0x47D4A0
				call eax
				add     esp, 10h

}

}
DWORD RcevCallAdress()
{
DWORD IndexNe[8];

IndexAl(&IndexNe[0]);
DWORD retaddr=IndexNe[0];
 ShowMessage(IntToHex((int)retaddr,8));
DWORD dwProcessAddr =0;
asm{
mov     ecx, ds:0xD74D40
mov     edx, retaddr

mov     eax, [ecx+edx*4+24h]

mov    dwProcessAddr ,eax
}
 ShowMessage(IntToHex((int)dwProcessAddr,8));
return dwProcessAddr ;
}

void __fastcall TForm2::Button4Click(TObject *Sender)
{
RcevCallAdress();
return;

//GelenHazirla1();
}
//---------------------------------------------------------------------------

