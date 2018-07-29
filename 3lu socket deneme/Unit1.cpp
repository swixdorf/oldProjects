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
void __fastcall TForm1::ServerSocket3ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	switch (Socket->LocalPort)
	{
		case 18001:
			Memo1->Lines->Add("Connect");
		break;
		case 18002:
			Memo2->Lines->Add("Connect");
		break;
		case 18003:
			Memo3->Lines->Add("Connect");
		break;
	default:
	;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket3ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	switch (Socket->LocalPort)
	{
		case 18001:
			Memo1->Lines->Add("DC");
		break;
		case 18002:
			Memo2->Lines->Add("DC");
		break;
		case 18003:
			Memo3->Lines->Add("DC");
		break;
	default:
	;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket3ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	switch (Socket->LocalPort)
	{
		case 18001:
			Memo1->Lines->Add("read");
		break;
		case 18002:
			Memo2->Lines->Add("read");
		break;
		case 18003:
			Memo3->Lines->Add("read");
		break;
	default:
    ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket3ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    ErrorCode = 0;
	switch (Socket->LocalPort)
	{
		case 18001:
			Memo1->Lines->Add("Err");
		break;
		case 18002:
			Memo2->Lines->Add("Err");
		break;
		case 18003:
			Memo3->Lines->Add("Err");
		break;
	default:
	;
	}
}
//---------------------------------------------------------------------------
