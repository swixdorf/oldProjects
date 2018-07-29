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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{           /*
if (Button2->Caption=="kapa")
{
	Button2->Caption = "ac";
	ServerSocket3->Active  = false;
}else{
	Button2->Caption = "kapa";
	ServerSocket3->Active = false;
	ServerSocket3->Active = true;
}           */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MinerServerClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	String buf = "Miner Connect : " + Socket->RemoteAddress ;
	Memo1->Lines->Add(buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CustomerServerClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	String buf = "Customer Connect : " + Socket->RemoteAddress ;
	Memo1->Lines->Add(buf);	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
int count = MinerServer->Socket->ActiveConnections;
for (int i = 0; i < count; i++) {
String buf = MinerServer->Socket->Connections[i]->RemoteAddress +":"+ IntToStr(MinerServer->Socket->Connections[i]->RemotePort);
ListBox1->Items->Add(buf);
/*
BYTE a[2];
MinerServer->Socket->Connections[i]->SendBuf(a,2);
  */
}
}
//---------------------------------------------------------------------------
