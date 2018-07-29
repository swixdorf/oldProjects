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
DWORD HSThreadid;

typedef struct{
//TCustomWinSocket *Socket;
HANDLE ghWriteEvent;
TMemo *log;
}hsgelenyapi;

 #define socketoku WM_USER+100
int WINAPI threadoku(){
hsgelenyapi *gelenhs;
Form1->Memo1->Lines->Add("Thread Start");
 MSG msg;
while(::GetMessage( &msg, NULL, 0, 0 ))
 {

 switch (msg.message) {
 case socketoku:{

 gelenhs= (hsgelenyapi*)msg.wParam;
 // gelenhs->log->Lines->Add("Thread oku");
 //hscoz(gelenhs->Socket);
 if (! SetEvent(gelenhs->ghWriteEvent) )
	{
		gelenhs->log->Lines->Add("SetEvent failed : "+IntToStr( GetLastError()));
	}else {
	   gelenhs->log->Lines->Add("SetEvent ok");
	}
 }break;

 default:
	 ;
 }
 }
gelenhs->log->Lines->Add("Thread cik");
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  CreateThread(0,0,(LPTHREAD_START_ROUTINE)threadoku,0,0,&HSThreadid);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::postClick(TObject *Sender)
{
hsgelenyapi *readgln= (hsgelenyapi*)malloc(sizeof(hsgelenyapi));
Form1->Memo1->Lines->Add("msg geldi");
readgln->log=Form1->Memo1;
   readgln->ghWriteEvent = CreateEvent(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
        FALSE,              // initial state is nonsignaled
		""  // object name
		);
		readgln->log->Lines->Add("event create");
PostThreadMessage(HSThreadid,socketoku,(WPARAM)readgln,0);
readgln->log->Lines->Add("postmsg");
Sleep(1000);
	DWORD dwWaitResult = WaitForSingleObject(
		readgln->ghWriteEvent, // event handle
		INFINITE);    // indefinite wait
		readgln->log->Lines->Add("bitti");
		CloseHandle(readgln->ghWriteEvent);
		free(readgln);
		Form1->Memo1->Lines->Add("free ok");
}
//---------------------------------------------------------------------------
