//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "ProcScan.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


 int __stdcall MyRecv(SOCKET s, char *buf, int len, int flags)
  {
  Form2->OynSocket=s;
  String a;
  for (int i = 0; i < len; i++)
  {
   a+= AnsiString(buf[i]);
  }
   Form1->Memo1->Lines->Add(a); ;
	return Form2->orecv(s, buf,len,flags);

 }
 AnsiString GirisAktar="";
 int __stdcall MySend(SOCKET s, char *buf, int len, int flags)
 {
 Form2->OynSocket=s;

 if ( AnsiString(buf).Pos("<var n='roomId' t='n'>")) {
 Form1->Edit1->Text= AnsiString(buf).SubString(AnsiString(buf).Pos("<var n='roomId' t='n'>")+22,3);

 }

   return Form2->osend(s, buf,len,flags);
 }

void __fastcall TForm2::FormCreate(TObject *Sender)
{
WebBrowser1->Silent = true;


WebBrowser1->Navigate("https://www.facebook.com/");

   while( WebBrowser1->ReadyState != 4 )
   {
	  Application->ProcessMessages();
	  if(WebBrowser1->ReadyState ==3)
	  break;
   }
//DeleteIECache();
//  ClearInternetExplorerHistory();



osend         = (r_send) GetProcAddress(GetModuleHandle("ws2_32.dll"), "send"); //gets original address for send
orecv         = (r_recv) GetProcAddress(GetModuleHandle("ws2_32.dll"), "recv"); //for recv same as above
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
HANDLE a=0;
AnsiString NameDll= "Flash10l.ocx";
if(!ListProcessModules(GetCurrentProcessId(),NameDll)) return;

a=GetModuleHandle(NameDll.c_str()) ;

if(a==0)
{
	return;
}

BuildImportTable((DWORD)a,(DWORD)MyRecv,"16","WS2_32.dll");
BuildImportTable((DWORD)a,(DWORD)MySend,"19","WS2_32.dll");

//HookImportsOfImage(a,"WS2_32.dll","recv",MyRecv);
Timer1->Enabled=false;
//Memo1->Lines->Clear();
  return;
}
//---------------------------------------------------------------------------
