//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
BYTE MasterKey=122  ;
BYTE key=9;
//---------------------------------------------------------------------------
PacketSifrele(BYTE *Buf,WORD Len,BYTE key)
{
BYTE Donen[1024];
memset(&Donen,0,1024);
BYTE K1,K2,K3,KEY1,KEY2;
K1=Random(MasterKey/2);
K2=Random(MasterKey/3);
K3=MasterKey-K1-K2;
KEY1=Random(key);
KEY2=key-KEY1;
Donen[0]=K1;
*(WORD*)&Donen[1]=Len*2+7;
Donen[3]=K2;
Donen[4]=KEY1;
Donen[Len*2+5]=KEY2;
Donen[Len*2+6]=K3;
int yer=0;
int tersyer=0;
for (int i = 0; i < Len; i++) {

int a=i/2;
a=a*2;
if (a==i) {
Donen[5+yer]=Random(Buf[i]);
Donen[5+yer+1]=Buf[i]-Donen[5+yer];
yer+=2;
}else{
Donen[5+yer]=Random(Buf[i]);

Donen[(Len*2+6)-(tersyer)-2]=Buf[i]-Donen[5+yer];
tersyer++;
yer++;
}
}
memcpy(Buf,&Donen[0],1024);
}
 /////////////////////////
PacketCoz(char *Buf,WORD Len)
{
BYTE Donen[1024];
WORD ULEN=(Len-7)/2;
memset(&Donen,0,1024);
BYTE MKey=Buf[0]+Buf[3]+Buf[Len-1];
BYTE key=Buf[4]+Buf[Len-2];
int yer=0;
int tersyer=0;
for (int i = 0; i < ULEN; i++) {
int a=i/2;
a=a*2;
if (i==a) {
Donen[i]=Buf[5+yer]+Buf[5+yer+1];
yer+=2;
}else{
Donen[i]=Buf[5+yer]+Buf[Len-tersyer-3];
yer++;
tersyer++;
}
}
*(WORD*)&Buf[0]=ULEN;
memcpy(&Buf[2],&Donen[0],ULEN);
}

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
if((Edit2->Text=="")||(Edit4->Text==""))
{
	ShowMessage("ID Veya KEY Girin Lutfen...!");
	return ;
}
  KOSocKay->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::KOSocKayConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
int KomutLen;
  BYTE KomutBuf[1024];

	 KomutLen=1;
	 KomutBuf[0]=0xD0;
	 KomutBuf[KomutLen]=Edit2->Text.Length();

	 memcpy(&KomutBuf[KomutLen+1],Edit2->Text.c_str(),KomutBuf[KomutLen]);
	 KomutLen+=KomutBuf[KomutLen]+1;

	 KomutBuf[KomutLen]=16;//Edit4->Text.Length();
	 memcpy(&KomutBuf[KomutLen+1],Edit4->Text.c_str(),KomutBuf[KomutLen]);
	 KomutLen+=KomutBuf[KomutLen]+1;

	 KomutBuf[KomutLen]=32;
	 memcpy(&KomutBuf[KomutLen+1],Kontrol.c_str(),KomutBuf[KomutLen]);
	 KomutLen+=KomutBuf[KomutLen]+1;


	 PacketSifrele(KomutBuf,KomutLen,key);

	Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::KOSocKayRead(TObject *Sender, TCustomWinSocket *Socket)
{
  int glnlen=	 Socket->ReceiveLength();
 BYTE KomutBuf[1024];
		 if(glnlen>1024)
		 {
			 return;
		 }
		 Socket->ReceiveBuf(KomutBuf,glnlen) ;

		  if(KomutBuf[0]+KomutBuf[3]+KomutBuf[glnlen-1]!=MasterKey)
		  {
		  Socket->Close();
			  return  ;
		  }

		 PacketCoz(KomutBuf,glnlen);
		 switch(KomutBuf[2])
		 {
		 case 0xD0:

		 Label6->Caption="KAYIT SURE: "+IntToStr(KomutBuf[3]);
							  break;
		 default:
		 Label6->Caption="KAYIT HATA: ";
							  break;



		 }

}
//---------------------------------------------------------------------------
