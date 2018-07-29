//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <windows.h>
#include <d3d9.h>
#include "ffrmLogin.h"
#include "Unit4.h"
#include "Unit2.h"
#include "fdlgParty.h"
#include "multi.h"
USEFORM("Unit2.cpp", Form2);
char DLLPATH[MAX_PATH];
bool WINAPI  FormOlustur( void );
HINSTANCE hInstance  ;
String loddll;
//=====================================================================================

typedef HRESULT (WINAPI* CreateDevice_Prototype)        (LPDIRECT3D9, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE9*);
typedef HRESULT (WINAPI* Reset_Prototype)               (LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
typedef HRESULT (WINAPI* EndScene_Prototype)            (LPDIRECT3DDEVICE9);
typedef HRESULT (WINAPI* DrawIndexedPrimitive_Prototype)(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);

CreateDevice_Prototype         CreateDevice_Pointer         = NULL;
Reset_Prototype                Reset_Pointer                = NULL;
EndScene_Prototype             EndScene_Pointer             = NULL;
DrawIndexedPrimitive_Prototype DrawIndexedPrimitive_Pointer = NULL;

HRESULT WINAPI Direct3DCreate9_VMTable    (VOID);
HRESULT WINAPI CreateDevice_Detour        (LPDIRECT3D9, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE9*);
HRESULT WINAPI Reset_Detour               (LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
HRESULT WINAPI EndScene_Detour            (LPDIRECT3DDEVICE9);
HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);

DWORD WINAPI VirtualMethodTableRepatchingLoopToCounterExtensionRepatching(LPVOID);
PDWORD Direct3D_VMTable = NULL;

//=====================================================================================
HRESULT WINAPI Direct3DCreate9_VMTable(VOID)
{
   // ShowMessage("dx create");
  LPDIRECT3D9 Direct3D_Object;// = Direct3DCreate9(D3D_SDK_VERSION);
__asm{
	push D3D_SDK_VERSION
	mov eax,orj_cDevice
	call eax
	mov Direct3D_Object,eax

}
  if(Direct3D_Object == NULL)
  return D3DERR_INVALIDCALL;
  
  Direct3D_VMTable = (PDWORD)*(PDWORD)Direct3D_Object;
  Direct3D_Object->Release();

  DWORD dwProtect;

  if(VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
  {
    *(PDWORD)&CreateDevice_Pointer = Direct3D_VMTable[16];
    *(PDWORD)&Direct3D_VMTable[16] = (DWORD)CreateDevice_Detour;

    if(VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), dwProtect, &dwProtect) == 0)
    return D3DERR_INVALIDCALL;
  }
  else
  return D3DERR_INVALIDCALL;

  return D3D_OK;
}

//=====================================================================================

HRESULT WINAPI CreateDevice_Detour(LPDIRECT3D9 Direct3D_Object, UINT Adapter, D3DDEVTYPE DeviceType, HWND FocusWindow, 
                    DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* PresentationParameters, 
                    LPDIRECT3DDEVICE9* Returned_Device_Interface)
{
  HRESULT Returned_Result = CreateDevice_Pointer(Direct3D_Object, Adapter, DeviceType, FocusWindow, BehaviorFlags,
                                              PresentationParameters, Returned_Device_Interface);
   
  DWORD dwProtect;

  if(VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
  {
    *(PDWORD)&Direct3D_VMTable[16] = *(PDWORD)&CreateDevice_Pointer;
    CreateDevice_Pointer           = NULL;

    if(VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), dwProtect, &dwProtect) == 0)
    return D3DERR_INVALIDCALL;
  }
  else
  return D3DERR_INVALIDCALL;

  if(Returned_Result == D3D_OK)
  {
    Direct3D_VMTable = (PDWORD)*(PDWORD)*Returned_Device_Interface;

    *(PDWORD)&Reset_Pointer                = (DWORD)Direct3D_VMTable[16];
    *(PDWORD)&EndScene_Pointer             = (DWORD)Direct3D_VMTable[42];
    *(PDWORD)&DrawIndexedPrimitive_Pointer = (DWORD)Direct3D_VMTable[82];

    if(CreateThread(NULL, 0, VirtualMethodTableRepatchingLoopToCounterExtensionRepatching, NULL, 0, NULL) == NULL)
    return D3DERR_INVALIDCALL;
  }
    
  return Returned_Result;
}

//=====================================================================================

HRESULT WINAPI Reset_Detour(LPDIRECT3DDEVICE9 Device_Interface, D3DPRESENT_PARAMETERS* PresentationParameters)
{
  return Reset_Pointer(Device_Interface, PresentationParameters);
}

//=====================================================================================

HRESULT WINAPI EndScene_Detour(LPDIRECT3DDEVICE9 Device_Interface)
{
  return EndScene_Pointer(Device_Interface);
}

//=====================================================================================

HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE9 Device_Interface, D3DPRIMITIVETYPE Type, INT BaseIndex, 
                                           UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
  LPDIRECT3DVERTEXBUFFER9 Stream_Data;
  UINT Offset = 0;
  UINT Stride = 0;

  if(Device_Interface->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK)
  Stream_Data->Release();

  if(Stride == 0)
  {
  }

  return DrawIndexedPrimitive_Pointer(Device_Interface, Type, BaseIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}

//=====================================================================================

DWORD WINAPI VirtualMethodTableRepatchingLoopToCounterExtensionRepatching(LPVOID Param)
{
  UNREFERENCED_PARAMETER(Param); 

  while(1)
  {
    Sleep(100);

    *(PDWORD)&Direct3D_VMTable[16] = (DWORD)Reset_Detour;
    *(PDWORD)&Direct3D_VMTable[42] = (DWORD)EndScene_Detour;
    *(PDWORD)&Direct3D_VMTable[82] = (DWORD)DrawIndexedPrimitive_Detour;
  }

  return 1;
}

//=====================================================================================
HMODULE GetMyModuleHandle()
{
	static int s_somevar = 0;
    MEMORY_BASIC_INFORMATION mbi;
	if(!::VirtualQuery(&s_somevar, &mbi, sizeof(mbi)))
	{
		return NULL;
	}

	return mbi.AllocationBase;
}
long WINAPI FormThread(long lParam)
{

	//*(DWORD*)cDisplaySetting = (DWORD)swxChangeDisplaySettingsA;

	//	*(DWORD*)(stamaskaddr) = (DWORD)swxSetThreadAffinityMask ;
//Sleep(150000);
//WTerminateThread(hDLLThread,0);

my_tid = GetCurrentThreadId();
	//DisableThreadLibraryCalls(GetMyModuleHandle());

	/*if(Direct3DCreate9_VMTable() == D3D_OK){
	Sleep(1);
	}          */
	baypas();

  
	if(!FreeLibrary(GetModuleHandleA(loddll.c_str())))
	{
		ShowMessage("hatavar");
	}
	Sleep(3000);
	WaitForInputIdle((void*)-1,INFINITE);
	SetUnhandledExceptionFilter( MyExceptionFilter );
	dwMyPID = GetCurrentProcessId();
	DWORD dwHWNDTick = GetTickCount();
	while( !hGameHWND )
	{
		if( GetTickCount() - dwHWNDTick > 30000 )
			break;
		hGameHWND = (HWND)*(DWORD*)KO_HWND;
		Sleep(500);
	}
	if(!hGameHWND)
	{
		MessageBox(0,"hGAMEHWND == NULL","Hata!",0);
		ExitProcess(0);
	}
	MakeTerminateFunc();
	RandomizeFunction();
	dwCheckFunctionVal = *(DWORD*) (DWORD)&CheckFunction;

	memset(strGameID,0,25);
	memset(strGamePW,0,25);
	memset(strBotID,0,25);
	memset(strBotPW,0,25);
	memset(strCheckFile,0,256);

/*	char strLoginFile[256]; memset(strLoginFile,0,256);
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
	}         */

  //	memset(strTrialID,0,22);



   //	if(bAutoLogin)DeleteFileA("C:\\loginmutex.kole");

	Application->Initialize();

	Application->CreateForm(__classid(TForm4), &Form4);

	Form4->Show();

	Form4->BringToFront();
	SetForegroundWindow(Form4->Handle);
	Form4->Path = loddll ;
	//Application->CreateForm(__classid(TForm2), &Form2);
	while (loddll=="")
	{
		Sleep(250);
	}
	//Form2->Path = loddll;
	Application->Run();
	Application->ProcessMessages();
	return 1;
}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			GetModuleFileNameA(hinst,DLLPATH,MAX_PATH);
		break;
		case DLL_PROCESS_DETACH:
		break;
	}
	return 1;
}

//---------------------------------------------------------------------------


extern "C" __declspec(dllexport) WINAPI bool DllRun(char *path,void *dlladres,DWORD Param)
{

	memcpy(&DLLPATH,&path[0],MAX_PATH);
	loddll=String(path);
  	hDLLThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)FormThread,NULL,0,&dwDLLThread);
}

