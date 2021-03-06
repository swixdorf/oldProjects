//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>

#include "Unit1.h"
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused



int WINAPI MainThread(){
	Application->Initialize();

	Application->CreateForm(__classid(TForm1), &Form1);

	Form1->Show();

	Form1->BringToFront();
	SetForegroundWindow(Form1->Handle);
	Application->Run();
	Application->ProcessMessages();

}

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)MainThread,NULL,0,NULL);
		break;
		case DLL_PROCESS_DETACH:
		break;
	}
	return 1;


 /*
HANDLE a=0;


   AnsiString NameDll= "Flash10l.ocx";
if(!ListProcessModules(GetCurrentProcessId(),NameDll)) return 1;

a=GetModuleHandle(NameDll.c_str()) ;

if(a==0)
{
	return 1 ;
}

BuildImportTable((DWORD)a,(DWORD)MyRecv,"16","WS2_32.dll");
BuildImportTable((DWORD)a,(DWORD)MySend,"19","WS2_32.dll");
ShowMessage("done");
	return 1;   */
}
//---------------------------------------------------------------------------
