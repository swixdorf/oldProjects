//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <windows.h>
#include "ffrmLogin.h"
#include "Unit4.h"
#include "Unit2.h"
#include "fdlgParty.h"

  USEFORM("Unit2.cpp", Form2);
char DLLPATH[MAX_PATH];
bool WINAPI  FormOlustur( void );
HINSTANCE hInstance  ;
	String loddll;




//bool baypas(){
//	 Don:
//	 Sleep(200);
//	  if (*(DWORD*)(Kontrol)!=KotrolDeger) {
//		  goto Don;
//	  }
//
//	  ListProcessThreadsSuspend(GetCurrentProcessId());
//	char tmp[25];	memset(tmp,0,25);
//Sleep(2000);
//	 ReadProcessMemory(GetCurrentProcess(),(LPVOID)KO_WNDA,tmp,20,NULL);
//
//
//if (String(tmp)!="Knight OnLine Client") {
//
//memset(name,0,MAX_PATH);
//GetModuleFileNameA(0,name,MAX_PATH);
//ff= new TFileStream(name,fmShareDenyRead);
//
//
//memcpy(ORJCODE,(void*)Kontrol,10);
//	 DWORD d=(DWORD)  dondon;
//d=(d-Kontrol);
//d-=5;
//
//*(DWORD*)(Kontrol+1)=d;
//
//DWORD d2=(DWORD)  cfhook;
//d2=(d2-Kontrol2);
//d2-=5;
//
//*(DWORD*)(Kontrol2+1)=d2;
//}
//ListProcessThreadsResume(GetCurrentProcessId());
//}
long WINAPI FormThread(long lParam)
{
// Application->Initialize();
//Application->CreateForm(__classid(TForm2), &Form2);
//Application->Run();
//Application->ProcessMessages();

//MessageBox(0,"dll load",0,0);
//
//	 ShowMessage(loddll);
if(!FreeLibrary(GetModuleHandleA(loddll.c_str())))
{
 ShowMessage("hata");
}
	Sleep(3000);

	WaitForInputIdle((void*)-1,INFINITE);

	SetUnhandledExceptionFilter( MyExceptionFilter );



	dwMyPID = GetCurrentProcessId();

	//hGameHWND = FindWindowA(NULL,(LPSTR)KO_WNDA);

	DWORD dwHWNDTick = GetTickCount();

	while( !hGameHWND )
	{
		if( GetTickCount() - dwHWNDTick > 15000 )
			break;

		hGameHWND = (HWND)*(DWORD*)KO_HWND;

		Sleep(1000);
	}

	if(!hGameHWND)
	{
		MessageBox(0,"hGAMEHWND == NULL","Hata!",0);
		ExitProcess(0);
	}


//Form4 = new TForm4(NULL);
//Application->Initialize();
//Application->CreateForm(__classid(TForm4), &Form4);
//Application->Run();
//Application->ProcessMessages();


	//GetAPIChecks();
	//GetFuncChecks();


	MakeTerminateFunc();

	//CheckLoader();	//loader kontrol

	RandomizeFunction();	//randomize

//	__asm
//	{
//		LEA EAX,&dwDLLCheckPointer
//		PUSH EAX
//		PUSH iDLLCheckFuncIndex
//		SHL [ESP],2
//		POP EAX
//		ADD [ESP],EAX
//		POP EAX
//		PUSH [EAX]
//		POP EAX
//		PUSH [EAX]
//		CALL [ESP]
//		POP EAX
//		CALL CheckDLLName
//		CALL CheckModule
//	}


//	*(DWORD*)KO_APRA = 0;	// APR
//	*(DWORD*)KO_APRB = 0;	// APR
	//*(DWORD*)KO_APRC = 0;	// APR



	dwCheckFunctionVal = *(DWORD*) (DWORD)&CheckFunction;

//	if(Make0x54Byte() - (int)dwSendPointerAdd != 1)
//		OwnTerminate();


	//dwServerARG += GetServerARG();

	memset(strGameID,0,25);
	memset(strGamePW,0,25);
	memset(strBotID,0,25);
	memset(strBotPW,0,25);

	memset(strCheckFile,0,256);

	char strLoginFile[256]; memset(strLoginFile,0,256);
	GetCurrentDirectoryA(255,strLoginFile);
	GetCurrentDirectoryA(255,strCheckFile);
	strcat(strLoginFile,"\\autologin.kole");
	strcat(strCheckFile,"\\loginstatus.kole");
	ifstream fCheck;
	fCheck.open(strLoginFile);
	if(fCheck.is_open())
	{
		char tmp[4]; *(DWORD*)tmp = 0;
		fCheck.getline(tmp,4);
		bool bRet = (bool)atoi(tmp);
		if(bRet)
		{
			bReLogin = true;
			if( ( *(DWORD*)KO_CHAR == 0 || *(DWORD*)(*(DWORD*)(KO_CHAR) + KO_MYID) == 0 ) && *(DWORD*)KO_INTR == 0 )
			{
				bAutoLogin = true;
				*(DWORD*)tmp = 0;
				fCheck.getline(tmp,4);
				bTrialLogin = (bool)atoi(tmp);

//				fCheck.getline(strGameID,24);
				fCheck.getline(strGamePW,24);
				fCheck.getline(strBotID,24);
				fCheck.getline(strBotPW,24);

				StrDecrypt(strGameID);
				//StrDecrypt(strGamePW);
				StrDecrypt(strBotID);
				StrDecrypt(strBotPW);

				*(DWORD*)tmp = 0;
				fCheck.getline(tmp,4);
				iServerIndex = atoi(tmp);

				*(DWORD*)tmp = 0;
				fCheck.getline(tmp,4);
				iServerNo = atoi(tmp);

				*(DWORD*)tmp = 0;
				fCheck.getline(tmp,4);
				iCharSlot = atoi(tmp);

				dwLoginFuncPointer = (DWORD)&LoginFunction;

				CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)LoginCall,NULL,0,0);
			}
		}

		fCheck.close();
		DeleteFileA(strLoginFile);
	}

	memset(strTrialID,0,22);

	while( *(DWORD*)KO_CHAR == 0 || *(DWORD*)(*(DWORD*)(KO_CHAR) + KO_MYID) == 0 || CheckLoading() == true )
	{

		//*(DWORD*)KO_APRA = 0;	// APR
		//*(DWORD*)KO_APRB = 0;	// APR
		//*(DWORD*)KO_APRC = 0;	// APR


		if( *(DWORD*)KO_INTR == 1 )
		{
			if(bHookPatched == false)
			{
				InitializeCriticalSection(&csSendFunc);
				//TestPatch();
				//PatchTPT();
				
			   //	_CPacket.PatchHooked();
				bHookPatched = true;
			}
		}

		Sleep(1000);
	}

	Sleep(1000);

	bGameLoaded = true;

	_CCharBase = *(DWORD*)(KO_CHAR);

	if(!_CCharBase.GetBase())
	{
		TerminateGame(1);
		MessageBox(0,"_CharBase == NULL","Hata!",0);
		ExitProcess(0);
	}

	//PatchGameAPIs();


	//*(DWORD*)KO_APRA = 0;	// APR
	//*(DWORD*)KO_APRB = 0;	// APR
   //	*(DWORD*)KO_APRC = 0;	// APR

	if(bAutoLogin)DeleteFileA("C:\\loginmutex.kole");
//Form4 = new TForm4(NULL);
Application->Initialize();
Application->CreateForm(__classid(TForm4), &Form4);
Application->Run();
Application->ProcessMessages();

Form4->Show();
Form4->BringToFront();
SetForegroundWindow(Form4->Handle);
return 1;
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:

		GetModuleFileNameA(hinst,DLLPATH,MAX_PATH);
		//EditDbgBreakPoint();

	//	FormOlustur();

		break;
		case DLL_PROCESS_DETACH:
		break;
	}
	return 1;
}

//---------------------------------------------------------------------------

int WINAPI FormThread1(PVOID Event)
{
 
 //	GetModuleFileNameA(hInstance,DLLPATH,MAX_PATH);
   //	ShowMessage("çaliþti");
	Form2 =new   TForm2(NULL);
	Form2->Show();
	while(1)
	{
	Sleep(25);
	Application->ProcessMessages();
	if(GetKeyState(VK_F12)& 0x80000000)
	{
TerminateProcess(GetCurrentProcess(),NULL);
	Sleep(100);
	}

	 }
delete Form2;
	return true;
}


bool WINAPI  FormOlustur( void )
{

CreateThread(0,0,(LPTHREAD_START_ROUTINE)FormThread1,0,0,0);
}


extern "C" __declspec(dllexport) WINAPI bool DllRun(char *path,void *dlladres,DWORD Param)
{
memcpy(&DLLPATH,&path[0],MAX_PATH);
loddll=String(path);

   hDLLThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)FormThread,NULL,0,&dwDLLThread);

//TerminateThread(GetCurrentThread(),0)   ;

}

