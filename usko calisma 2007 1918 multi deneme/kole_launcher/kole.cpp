//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	char strDir[256]; memset(strDir,0,256);
	GetCurrentDirectoryA(255,strDir);
	strcat(strDir,"//dat");

	bool bProcess = CreateProcess("dat//klauncher.dat"," kojd",NULL,NULL,true,NULL,NULL,strDir,&si,&pi);

	if(!bProcess)
	{
		MessageBoxA(NULL,"'klauncher.dat' failed","Error",MB_ICONSTOP);
		Application->Terminate();
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	Application->Terminate();
	return false;
}
//---------------------------------------------------------------------------
