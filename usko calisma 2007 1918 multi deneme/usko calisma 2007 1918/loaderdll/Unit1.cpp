//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <zlib.hpp>
#include "math.h"
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "ThemidaSDK.h"
#include "MemoryModule.cpp"
#include "Tlhelp32.h"
//#include "ProcScan.h"
 TForm1 *Form1;
  HMEMORYMODULE ModulAl;
  DWORD Version= 3 ;

  TIniFile *KoIni;
  DWORD LastAliveTime;
  int islem = 0 ;
  typedef bool (*DllRunDll)(char *path,void *dlladres,DWORD Param);
//---------------------------------------------------------------------------
#define nil 0
void  CompressStream(TStream *inpStream,TStream *outStream )
{
void  *InpBuf, *OutBuf;
int   OutBytes, sz,InpBytes;

  InpBuf = nil;
  OutBuf = nil;

	InpBuf=GetMemory(inpStream->Size);
	inpStream->Position = 0;
	InpBytes = inpStream->Read(InpBuf, inpStream->Size);
	CompressBuf(InpBuf, InpBytes, OutBuf, OutBytes);
	outStream->Write(OutBuf, OutBytes);

	if (InpBuf != nil)  FreeMemory(InpBuf);
	if (OutBuf != nil)  FreeMemory(OutBuf);
}


void DecompressStream(TStream *inpStream,TStream *outStream )
{
void  *InpBuf, *OutBuf;
int   OutBytes, sz;

  InpBuf = nil;
  OutBuf = nil;
  sz     = inpStream->Size - inpStream->Position;
  if (sz > 0 )
  {
	 InpBuf= GetMemory( sz);
	  inpStream->Read(InpBuf, sz);
	  DecompressBuf(InpBuf, sz, 0, OutBuf, OutBytes);
	  outStream->Write(OutBuf, OutBytes);


	  if (InpBuf != nil)   FreeMemory(InpBuf);
	  if (OutBuf != nil)   FreeMemory(OutBuf);
  }

  outStream->Position = 0;
}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
String Path ;
BYTE MasterKey=122  ;
BYTE key=9;
int keykontrol=99;
String HDDNO = 123;
//---------------------------------------------------------------------------
 BYTE Data1[128];
BYTE Data2[128];
BYTE Data3[128];
BYTE Data4[128];
BYTE Data5[128];
int WINAPI ExxitThread(int a ){
Sleep(5000);
TerminateProcess(GetCurrentProcess(),0) ;
}


HMEMORYMODULE Manueldll(AnsiString Resname,char *restype)
 {


 CODEREPLACE_START
Data1[128];
Data2[128];
Data3[128];
Data4[128];
Data5[128];


HANDLE hMem;

  TMemoryStream  *ms ;
TResourceStream   *rs;

rs = new TResourceStream((int)HInstance, Resname, restype);
ms = new TMemoryStream();


TMemoryStream *aaa ;
TMemoryStream *bbb ;
aaa = new TMemoryStream ;
bbb = new TMemoryStream ;

aaa->LoadFromStream(rs);
DecompressStream(aaa,bbb);


ms=bbb;
ms->Position = 0;
DWORD m_DllDataSize = ms->Size;

void *mp_DllData= GetMemory(m_DllDataSize);
ms->Read(mp_DllData,m_DllDataSize) ;

HMEMORYMODULE aa=MemoryLoadLibrary(mp_DllData);
FreeMemory(mp_DllData);
 rs->Free()  ;
 ms->Free();
CODEREPLACE_END

   return aa;
 }


String FileName;
	char buf[MAX_PATH];
	STARTUPINFO si;
PROCESS_INFORMATION pi;
String Calis,KoPath;
HINSTANCE hInst = NULL;
String DllPath;

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


 bool DllRunLancur(char *path,void *dlladres)
{
memset(buf,0,sizeof(buf));
GetModuleFileName(0,buf,MAX_PATH);
FileName= String(buf);
memset(buf,0,sizeof(buf));
//GetModuleFileName(hInst,buf,MAX_PATH);
DllPath= ExtractFilePath(String(path));
//ShowMessage(DllPath);
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
 KoPath=ExtractFilePath(FileName);
  FileName=KoPath+"KnightOnLine.exe"  ;
 // ShowMessage(FileName);
 Calis="\""+FileName+"\" "+IntToStr(GetCurrentProcessId());
 CreateProcess(FileName.c_str(),Calis.c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,KoPath.c_str(),&si,&pi);
 DllPath=DllPath+"loader.dll";//"loader.dll";
 DLLInject(DllPath);
 ResumeThread(pi.hThread);
 //ShowMessage("lancur yukle"+FileName);
 Sleep(1000);
 //TerminateProcess(pi.hProcess,0)  ;
}


bool   TipNe()
   {
	  char buf[MAX_PATH];
 GetModuleFileName(0,buf,MAX_PATH);
//FileName= String(buf);

String FileName=ExtractFileName(String(buf));
if(FileName!="KnightOnLine.exe")
{

//  ModulAl=  Manueldll("KODLL1","KODLLNAME1");
//  deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");

//deneme(DLLPATH,ModulAl) ;
 DllRunLancur(DLLPATH,0);
  return true;
}


 return false;
}


DllYukle()
  {



DllRunDll deneme;
ModulAl=  Manueldll("KODLL","KODLLNAME");

deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");

deneme(DLLPATH,ModulAl,278) ;
  }



void __fastcall TForm1::FormCreate(TObject *Sender)
{



Path=ExtractFilePath(String(DLLPATH));
//KoIni= new TIniFile(Path+"Settings\\Settings.ini");
////Username->Text=KoIni->ReadString("Login","Username","");
////Password->Text=KoIni->ReadString("Login","Password","");
//bool login=KoIni->ReadBool("Login","Auto",false);
//KoIni->Free();
//HANDLE hMem;
//String a = "keyta";
//DWORD KET;
//hMem=OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, a.c_str());
//DWORD pBuf = (DWORD) MapViewOfFile(hMem, FILE_MAP_ALL_ACCESS, 0, 0, 4);
//memcpy(&KET,(void*)(pBuf),4);
//if (KET!=1987) {
//TerminateProcess(GetCurrentProcess(),0);
//}
 char buf[MAX_PATH];
 GetModuleFileName(0,buf,MAX_PATH);
//FileName= String(buf);
DllRunDll deneme;
String FileName=ExtractFileName(String(buf));
 ModulAl=  Manueldll("KODLL","KODLLNAME");

deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");

deneme(DLLPATH,ModulAl,278) ;
/*
if(FileName=="KnightOnLine.exe")
{
ShowMessage("Koyukle"+String(buf));
ModulAl=  Manueldll("KODLL","KODLLNAME");

deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");

deneme(DLLPATH,ModulAl) ;
}
else
{
ShowMessage("lancur yukle"+String(buf));
  ModulAl=  Manueldll("KODLL1","KODLLNAME1");
}
	 */

}
//---------------------------------------------------------------------------













void __fastcall TForm1::Button3Click(TObject *Sender)
{
//DllRunDll deneme;
//ModulAl=  Manueldll("KODLL","KODLLNAME");
//
//deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");
//
//deneme(DLLPATH,ModulAl) ;
}
//---------------------------------------------------------------------------



             
