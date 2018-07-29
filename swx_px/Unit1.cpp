//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
TServerSocket *Servers[255];
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AcClick(TObject *Sender)
{

	srvList->Enabled = false;
	for (int i = 0; i < srvList->Items->Count; i++)
	{
		if (srvList->Checked[i])
		{
			int pos 	= srvList->Items->Strings[i].AnsiPos(":");
			String ip 	= srvList->Items->Strings[i].SubString(1,pos-1);
			String port = srvList->Items->Strings[i].SubString(pos+1,srvList->Items->Strings[i].Length());
			Servers[i] 	= new TServerSocket(NULL);
			Servers[i]->Port 				= StrToInt(port);
			Servers[i]->Tag 				= i;
			Servers[i]->OnClientConnect 	= ServerSocket1->OnClientConnect;
			Servers[i]->OnClientRead		= ServerSocket1->OnClientRead;
			Servers[i]->OnClientError		= ServerSocket1->OnClientError;
			Servers[i]->OnClientDisconnect	= ServerSocket1->OnClientDisconnect;
			Servers[i]->Active 				= true;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::KapatClick(TObject *Sender)
{
	srvList->Enabled = true;
	for (int i = 0; i < srvList->Items->Count; i++)
	{
		if (srvList->Checked[i])
		{
			Servers[i]->Active = false;
			Servers[i]->Free();
		}

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
TServerSocket *Item = dynamic_cast<TServerSocket *>(Sender);
ShowMessage(Item->Tag);
Memo1->Lines->Add(IntToStr(Item->Tag)+" : Connected Client : "+ Socket->RemoteAddress);
}
//---------------------------------------------------------------------------
