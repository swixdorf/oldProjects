//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString BufferToHex(char *buf,int size)
{
String str;
for(int i=0;i<size;i++)
{
BYTE a=buf[i];
str+="0x"+IntToHex(a,2)+",";
}
return str;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoginServerClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
int len  = Socket->ReceiveLength();
BYTE Komut[1024];
Socket->ReceiveBuf(&Komut,len);
log->Lines->Add("r: "+BufferToHex(Komut,len));
switch (Komut[4]) {
	case 0x2b:
	{
	BYTE Komut[]={0xAA,0x55,0x03,0x00,0x2b,0x01,0x45,0x55,0xAA};
	Socket->SendBuf(Komut,sizeof(Komut));
	}break;
	case 0x1:
	{
	BYTE Komut[]={0xAA,0x55,0x02,0x00,0x01,0x02,0x55,0xAA};
	Socket->SendBuf(Komut,sizeof(Komut));
	}break;
	case 0xc:
	{
	BYTE Komut[1024];
	int yer = 4;
	Komut[0]=0xaa;
	Komut[1]=0x55;
	Komut[yer]= 0x0c;
	yer++;
	Komut[yer] = 0x01;
	yer++;
	AnsiString id = "comolokko" ;
	for (int i = 0; i < 3; i++) {
	*(WORD*)&Komut[yer]=id.Length();
	yer+=2;
	memcpy(&Komut[yer],id.c_str(),id.Length());
	yer+=id.Length();
	Komut[yer]=0x01;
	yer++;
	*(WORD*)&Komut[yer]=101;
	yer+=2;
	Komut[yer]=0x01;
	yer++;
	Komut[yer]=0x01;
	yer++;
	Komut[yer]=0x01;
	yer++;
	Komut[yer]=0x01;
	yer++;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	*(DWORD*)&Komut[yer]=0;
	yer+=4;
	*(WORD*)&Komut[yer]=0;
	yer+=2;
	}
	Komut[yer]=0x55;
	yer++;
	Komut[yer]=0xaa;
	yer++;
	*(WORD*)&Komut[2]=yer-6 ;
	Socket->SendBuf(Komut,yer);
	}break;
	case 0x4:
	{
	BYTE Komut[]={0xAA,0x55,0x0A,0x00,0x04,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0xAA};
	Socket->SendBuf(Komut,sizeof(Komut));
	}break;
default:
	;
}

//		m_pMain->m_DBProcess.LoadUserCountList();		// 기범이가 ^^;
//		SetByte( buff, LS_SERVERLIST, send_index );
//		SetByte( buff, m_pMain->m_nServerCount, send_index );
//		for(i=0; i<m_pMain->m_ServerList.size(); i++) {
//			SetShort( buff, strlen(m_pMain->m_ServerList[i]->strServerIP), send_index );
//			SetString( buff, m_pMain->m_ServerList[i]->strServerIP, strlen(m_pMain->m_ServerList[i]->strServerIP), send_index );
//			SetShort( buff, strlen(m_pMain->m_ServerList[i]->strServerName), send_index );
//			SetString( buff, m_pMain->m_ServerList[i]->strServerName, strlen( m_pMain->m_ServerList[i]->strServerName ), send_index );
//			SetShort( buff, m_pMain->m_ServerList[i]->sUserCount, send_index);   // 기범이가 ^^;
//		}
  //		Send( buff, send_index );

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoginServerClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
AnsiString Buf = "Client Connected : " + Socket->RemoteAddress ;
log->Lines->Add(Buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoginServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
AnsiString Buf = "Client Disconnected : " + Socket->RemoteAddress ;
log->Lines->Add(Buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int len ;
BYTE komut[1024];
len = Edit1->Text.Length()/2;
int yer =1;
for (int i = 0; i < len; i++) {
int bayt = StrToInt("0x"+Edit1->Text.SubString(yer,2));
komut[(yer-1)/2]=bayt;
yer+=2;
}
for (int i = 0; i < LoginServer->Socket->ActiveConnections; i++) {
	LoginServer->Socket->Connections[i]->SendBuf(komut,len);
}
}
//---------------------------------------------------------------------------


