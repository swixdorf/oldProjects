//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (FindWindowA(NULL,"Knight Online")) {
	HWND wnd = FindWindowA(NULL,"Knight Online") ;

	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
if(!FindWindowA(NULL,"initialization")&&!FindWindowA(NULL,"Knight Online")){
Timer1->Enabled=false;

Timer2->Enabled=true;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	char strDir[256]; memset(strDir,0,256);
	GetCurrentDirectoryA(255,strDir);
	strcat(strDir,"//dat");
	bool bProcess = CreateProcess("dat//klauncher.dat"," kojd",NULL,NULL,true,NULL,NULL,strDir,&si,&pi);
	Timer4->Enabled = false;
    Timer4->Enabled = true;
	if(!bProcess)
	{
		MessageBoxA(NULL,"'klauncher.dat' failed","Error",MB_ICONSTOP);
		Application->Terminate();

	}

}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Timer1->Enabled=true;
Timer2->Enabled=false;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
if (FileExists("c:\\nttgame\\knightonlineen\\log.klg"))
{
DeleteFileA("c:\\nttgame\\knightonlineen\\log.klg");
}
if (FileExists("c:\\nttgame\\knightonlineen\\hshield\\hshield.log"))
{
DeleteFileA("c:\\nttgame\\knightonlineen\\hshield\\hshield.log");
}
if (FindWindowA(NULL,"Error")) {
	HWND wnd = FindWindowA(NULL,"Error") ;
//CloseWindow(wnd) ;
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
if (FindWindowA(NULL,"KnightOnline HackShield")) {
	HWND wnd = FindWindowA(NULL,"KnightOnline HackShield") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
/*
if (FindWindowA(NULL,"Knight Online Client")) {
	HWND wnd = FindWindowA(NULL,"Knight Online Client") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}   */
if (FindWindowA(NULL,"Knight Online")) {
	HWND wnd = FindWindowA(NULL,"Knight Online") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
}
//---------------------------------------------------------------------------

	SOCKET myGameSocket[10];
	WSADATA wsaGameData[10];
	sockaddr_in myGameAddress[10];


void __fastcall TForm1::FormCreate(TObject *Sender)
{
if (FileExists("ipler.txt")) {
ListBox1->Items->LoadFromFile("ipler.txt");
}
if (FileExists("portlar.txt")) {
ListBox2->Items->LoadFromFile("portlar.txt");
}
for (int i = 0; i < ListBox1->Items->Count; i++)
{   /*
	myGameAddress[i].sin_family = AF_INET;

	myGameAddress[i].sin_addr.s_addr = inet_addr( ListBox1->Items->Strings[i].c_str() );
	myGameAddress[i].sin_port = htons(atoi(ListBox2->Items->Strings[i].c_str()) );

	if( WSAStartup( MAKEWORD(2, 2), &wsaGameData[i] ) != NO_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		continue;
	}
	myGameSocket[i] = socket( AF_INET, SOCK_STREAM, 0 );

	if ( myGameSocket[i] == INVALID_SOCKET || myGameSocket[i] == SOCKET_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return;
	}

	if ( connect( myGameSocket[i], (SOCKADDR*) &myGameAddress[i], sizeof( myGameAddress[i] ) ) == SOCKET_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return;
	}
	else
	{
		//send(myGameSocket,(char*)szData,lstrlen(szData),0);

		//int len=recv(myGameSocket,kKomut_Al,1024,0);

		closesocket(myGameSocket[i]);

		WSACleanup();
	}



ListBox3->Items->Add("bekleme");
		 */
}
}


//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (FindWindowA(NULL,"initializatione")) {
	HWND wnd = FindWindowA(NULL,"initialization") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
if (FindWindowA(NULL,"Error")) {
	HWND wnd = FindWindowA(NULL,"Error") ;
CloseWindow(wnd) ;
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);
	  ButtonHandle = FindWindowEx(wnd, 0, NULL, "Tamam");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);
}
if (FindWindowA(NULL,"KnightOnline HackShield")) {
	HWND wnd = FindWindowA(NULL,"KnightOnline HackShield") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}
/*
if (FindWindowA(NULL,"Knight Online Client")) {
	HWND wnd = FindWindowA(NULL,"Knight Online Client") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}      */
if (FindWindowA(NULL,"Knight Online")) {
	HWND wnd = FindWindowA(NULL,"Knight Online") ;
//CloseWindow(wnd);
	  HWND ButtonHandle = FindWindowEx(wnd, 0, NULL, "OK");
   SendMessage(wnd, WM_COMMAND, MAKEWORD(GetDlgCtrlID(ButtonHandle), BN_CLICKED ), (LPARAM)ButtonHandle);

}	
}
//---------------------------------------------------------------------------

