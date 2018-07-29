//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <IniFiles.hpp>
#include "Unit1.h"
#include "kaynak.hpp"
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define Versiyon 		100000
//#define MuteX			0x0089EB2A  //1735
DWORD Adresler[32];


DWORD KOYUKLEOFSET = 0x0041C5D5;
WORD KoYukleKontrol  =	0xF981;      //1751

TForm1 *Form1;
DWORD  ThreadId;
TIniFile *SwxIni;
STARTUPINFO si;
PROCESS_INFORMATION pi;
String Path;
BYTE a;
BYTE b;
BYTE orjinal[6];
BYTE VerKontrol=0;
String KoPath;
String KoName,Calis,PrmPath,KOFileName,RenameDosya;

String Durum;
bool cikis=false;

BYTE MasterKey=122  ;
BYTE key=9;
DWORD SpecialOffsetCryptKey=0x22185299;

WORD KalanDakika;

//-------------------------------------------------------------------
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


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BootServerClientRead(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	 BYTE KomutBuf[1024];
	  int glnlen=	 Socket->ReceiveLength();
	  TDateTime Zaman;
   char IDNE[60];

			 try{
		 if(glnlen>1024)
		 {
				goto BootServerCikis;
		 }
		 Socket->ReceiveBuf(KomutBuf,glnlen) ;

		  if(KomutBuf[0]+KomutBuf[3]+KomutBuf[glnlen-1]!=MasterKey)
		  {
		  Socket->Close();
			goto BootServerCikis;
		  }

		 PacketCoz(KomutBuf,glnlen);
		 switch(KomutBuf[2])
		 {
		 case 0xFF:
		 if(*(WORD*)&KomutBuf[0]>glnlen)
		 {
			Socket->Close();
			goto BootServerCikis;
		 }
		 CharTable->Filtered=false;
		 memset(IDNE,0,60);
				memcpy(IDNE,&KomutBuf[4],KomutBuf[3]);
				CharTable->Filter="[ID]='"+String(IDNE)+"'";
				CharTable->Filtered=true;

				if(CharTable->RecordCount)
				{
				 if(CharTableKALANGUN->Value>0)//&&(!CharTableBAGLI->Value))
				 {
			  CharTable->Edit();
			  CharTableBAGLI->Value=1;
			  CharTableZAMAN->Value=GetTickCount();
			  CharTableSOCKETNO->Value=(DWORD) Socket;
			  CharTable->Post();
	  *(WORD *)&KomutBuf[0]=MasterKey;
	  KomutBuf[0]=0xFF;
	 *(DWORD *)&KomutBuf[1]=0;
	 *(WORD *)&KomutBuf[5] =0;
	 *(WORD *)&KomutBuf[7]= CharTableKALANGUN->Value;
	  memcpy(&KomutBuf[7+2],CharTableIDKON->Value.c_str(),33);
	 *(DWORD *) &KomutBuf[7+2+33]=0x1048A810;//0x10476800;
	 *(DWORD *) &KomutBuf[7+2+33+4]=0x1048A814 ;
	 *(DWORD *) &KomutBuf[7+2+33+8]=Versiyon  ;

	 PacketSifrele(KomutBuf,70,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;
	 Socket->Close();


				 }
				 else
				 {
	   KomutBuf[0]=0xF2;
	   *(DWORD *)&KomutBuf[1]=0xFFFFFFFF;
	   PacketSifrele(KomutBuf,5,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;;
	   Socket->Close();
				 }


				}
				else
				{

			/*
				 *(WORD *)&KomutBuf[0]=SifreMaster;

	   KomutBuf[3]=0xF1;
	   *(DWORD *)&KomutBuf[4]=0xFFFFFFFF;
	   PacketSifre(&KomutBuf[3],5,SifreMaster);
	   Socket->SendBuf(KomutBuf,KomutBuf[2]+3)  ;
	   Socket->Close();   */

	   //trial
//				CharTable->Filtered=false;
//				 CharTable->Append();
//				 CharTableID->Value=IDNE;
//				 CharTableKAYITZAMAN->Value= Zaman.CurrentDate();
//				 CharTableSURE->Value=3;
//				 CharTableKEY->Value=0;
//				 CharTableBAGLI->Value=1;
//				 CharTableZAMAN->Value=GetTickCount();
//				 CharTableSOCKETNO->Value=(DWORD) Socket;
//				 CharTable->Post();
//
//				  *(WORD *)&KomutBuf[0]=MasterKey;
//
//	 KomutBuf[0]=0xFF;
//	 *(DWORD *)&KomutBuf[1]=KOYUKLEOFSET+SpecialOffsetCryptKey;
//	 *(WORD *)&KomutBuf[5] =KoYukleKontrol+SpecialOffsetCryptKey;
//	 *(WORD *)&KomutBuf[7]= CharTableKALANGUN->Value;
//	 for (int i = 0; i < 32; i++) {
//	 *(DWORD *)&KomutBuf[9+i*4]=Adresler[i]+SpecialOffsetCryptKey;
//	 }
//	 PacketSifrele(&KomutBuf[0],137,key);
//	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;
//	 Socket->Close();

	   KomutBuf[0]=0xF2;
	   *(DWORD *)&KomutBuf[1]=0xFFFFFFFF;
	   PacketSifrele(KomutBuf,5,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;;
	   Socket->Close();

				}



					  break;
		 case 0xF1:

				  Label3->Caption="NO ID";
				  Socket->Close();
				  break;

		 case 0xF2:
			   Label3->Caption="NO SURE";
			   Socket->Close();
				  break;


		 }

		 }
		  catch(...)
		 {
		  Socket->Close();
		 }
		 BootServerCikis:
		 Socket->Close();
		 CharTable->Filtered=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{



String Path=ExtractFilePath(Application->ExeName);

if(!Session->IsAlias("PokerServerGiris"))
{
  Session->AddStandardAlias("PokerServerGiris",Path,"PARADOX");
  Session->SaveConfigFile();
}
/*
String Path=ExtractFilePath(Application->ExeName);
   */
CharTable->DatabaseName ="PokerServerGiris";// Path ;
CharTable->TableName="ServerGiris.DB";
CharTable->Active=true;

KeyIsle->DatabaseName ="PokerServerGiris";// Path ;
KeyIsle->TableName="KEYBILGI.DB";
KeyIsle->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CharTableCalcFields(TDataSet *DataSet)
{

TDateTime Zaman,Zaman1;
//Zaman= CharTableKAYITZAMAN->Value;
/*
WORD Yil,Ay,Gun;
 Zaman.DecodeDate(&Yil,&Ay,&Gun);
 int ToplamgunKayit=(Yil*365)+ (Ay*30)+Gun;
 Zaman= Zaman.CurrentDate();
 Zaman.DecodeDate(&Yil,&Ay,&Gun);
 int ToplamgunSimdi=(Yil*365)+ (Ay*30)+Gun;
CharTableKALANGUN->Value=CharTableSURE->Value-( ToplamgunSimdi-ToplamgunKayit);

	   */
  Zaman1= Zaman1.CurrentDate();
	int x=CompareDate(CharTableKAYITZAMAN->Value+(CharTableSURE->Value+1),Zaman1)  ;
if(x>0)
{

CharTableKALANGUN->Value=DaysBetween(CharTableKAYITZAMAN->Value+CharTableSURE->Value,Zaman1);


}
else
{
 CharTableKALANGUN->Value=0;
}

}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormDestroy(TObject *Sender)
{
DbiSaveChanges(CharTable->Handle);
DbiSaveChanges(KeyIsle->Handle);
Form1->Hide();
Sleep(2500);
CharTable->Close();
KeyIsle->Close();
}
//---------------------------------------------------------------------------
Sifrelechar(BYTE *fileData,int len, int rndmod)
{
int modWord =rndmod; // 0x0816;
			for (int i = 0; i < len; i++)
			{
				byte encodedByte = fileData[i];
				int tmpModWord = modWord;
				byte decodedByte = 0;

				tmpModWord &= 0xff00;
				tmpModWord = tmpModWord >> 8;
				decodedByte = (byte)(tmpModWord ^ encodedByte);
			  /*	tmpModWord = encodedByte;
				tmpModWord += modWord;
				tmpModWord = tmpModWord & 0xffff; //eliminate overflow
				tmpModWord = tmpModWord * 0x6081;
				tmpModWord = tmpModWord & 0xffff; //eliminate overflow
				tmpModWord += 0x1608;
				tmpModWord = tmpModWord & 0xffff; //eliminate overflow
				modWord = tmpModWord;     */

				fileData[i] = decodedByte;
			}
}

void __fastcall TForm1::URETClick(TObject *Sender)
{
TDateTime Zaman;
for (int i = 0; i < Form1->Edit2->Text.ToIntDef(1); i++) {
    
 Sleep(25);

Zaman= Zaman.CurrentDateTime();
WORD Yil,Ay,Gun;
WORD S,SN,SNS,SNC;

Zaman.DecodeDate(&Yil,&Ay,&Gun);
Zaman.DecodeTime(&S,&SN,&SNS,&SNC);
WORD gun;
switch(RadioGroup1->ItemIndex)
{
	case 0: gun=1;break;
	case 1: gun=5;break;
	case 2: gun=10;break;
	case 3: gun=20;break;
	case 4: gun=30;break;
	case 5: gun=60;break;
	case 6: gun=120;break;
	case 7: gun=200;break;
	case 8: gun=255;break;
}

WORD Keysif[10];
String KEY="";
//KEY=IntToHex(gun,2);
Keysif[0]=S +(rand() % 35000 + 1);
Keysif[1]=SN+(rand() % 35000 + 1);
Keysif[2]=SNS+(rand() % 35000 + 1);
Keysif[3]=SNC+(rand() % 35000 + 1);
Keysif[4]=Yil+(rand() % 35000 + 1);
Keysif[5]=Ay+(rand() % 35000 + 1);
Keysif[6]=Gun+(rand() % 35000 + 1);
//memcpy((char *)Keysif,KEY.c_str(),KEY.Length());
//PacketSifre((char *)Keysif,12,(int)SNC);

int a = rand() % 100000 + 1;
Sifrelechar((BYTE *)Keysif,sizeof(Keysif),a);

KEY="";
//KEY=IntToHex(gun,2);
KEY+=IntToHex(Keysif[0],2);
KEY+=IntToHex(Keysif[1],2);
KEY+=IntToHex(Keysif[2],2);
KEY+=IntToHex(Keysif[3],2);
KEY+=IntToHex(Keysif[4],2);
KEY+=IntToHex(Keysif[5],2);
KEY+=IntToHex(Keysif[6],2);
 KeyIsle->Append();

 KeyIsleBAYIID->Value=Edit1->Text;
 KeyIsleSURE->Value= gun;
KeyIsleKEY->Value=KEY;
KeyIsleKAYITZAMAN->Value=Zaman.CurrentDate();
KeyIsleSATILDI->Value=0;
KeyIsleSATILDIZAMAN->Value=0;//Zaman.CurrentDate();
KeyIsle->Post();

Memo2->Lines->Add("BAYII: "+Edit1->Text) ;
Memo2->Lines->Add("GUN: "+IntToStr(gun)) ;
Memo2->Lines->Add(KEY) ;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Memo2->Lines->SaveToFile("Keyler.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BootServerKayitClientRead(TObject *Sender,
	  TCustomWinSocket *Socket)
{
   BYTE KomutBuf[1024];
	  int glnlen=	 Socket->ReceiveLength();
   char IDNE[60];
   char IDKO[40];
   char KEYNE[40];
   int index=0;
   TDateTime Zaman;
   try{
		 if(glnlen>1024)
		 {
			 goto BootServerCikis;
		 }
		 Socket->ReceiveBuf(KomutBuf,glnlen) ;



		  if(KomutBuf[0]+KomutBuf[3]+KomutBuf[glnlen-1]!=MasterKey)
		  {
		  Socket->Close();
		 goto BootServerCikis;
		  }

		 PacketCoz(KomutBuf,glnlen);

		 switch(KomutBuf[2])
		 {
		 case 0xD0:
		 index=3;
		 if(KomutBuf[index]>glnlen)
		 {
			Socket->Close();
			 goto BootServerCikis;
		 }
		  memset(IDNE,0,60);
			memcpy(IDNE,&KomutBuf[index+1],KomutBuf[index]);
		 index+=KomutBuf[index]+1 ;

		  if(KomutBuf[index]>glnlen)
		 {
			Socket->Close();
			  goto BootServerCikis;
		 }

		  memset(KEYNE,0,40);
		  memcpy(KEYNE,&KomutBuf[index+1],KomutBuf[index]);
		  index+=KomutBuf[index]+1 ;

		  memset(IDKO,0,40);
		  memcpy(IDKO,&KomutBuf[index+1],KomutBuf[index]);

		  CharTable->Filtered=false;
		  KeyIsle->Filtered=false;

		  KeyIsle->Filter="[KEY]='"+String(KEYNE)+"'";
		  KeyIsle->Filtered=true;

			if(KeyIsle->RecordCount)
				{
				if(KeyIsleSATILDI->Value==1)
				{

			  //	  Socket->Close();
			  //	 goto BootServerCikis;
				CharTable->Filter="[KEY]='"+String(KEYNE)+"'";
				CharTable->Filtered=true;

				if(CharTable->RecordCount)
				{
					  if(CharTableKALANGUN->Value>0)
					  {
				  CharTable->Edit();
				   CharTableID->Value=String(IDNE);
				 //CharTableKAYITZAMAN->Value= Zaman.CurrentDate();
				 //CharTableSURE->Value=KeyIsleSURE->Value;
				// CharTableKEY->Value=KeyIsleKEY->Value;
			   //CharTableBAYIID->Value=KeyIsleBAYIID->Value;
				CharTableIDKON->Value=String(IDKO) ;
				CharTable->Post();
				CharTable->Filtered=false;
				goto KayitMesaj;
					  }
					  else
					  {
					   Socket->Close();
					   goto BootServerCikis;
                      }
				}
				else
				{
                    Socket->Close();
					goto BootServerCikis;
                }


				}
		   KeyIsle->Edit();
		   KeyIsleSATILDI->Value=1;
		   KeyIsleSATILDIZAMAN->Value=Zaman.CurrentDate();
		   KeyIsle->Post();
				CharTable->Filter="[ID]='"+String(IDNE)+"'";
				CharTable->Filtered=true;

				if(CharTable->RecordCount)
				{

				CharTable->Edit();
				 CharTableKAYITZAMAN->Value= Zaman.CurrentDate();
				CharTableSURE->Value+=KeyIsleSURE->Value;
				CharTableKEY->Value=KeyIsleKEY->Value;
				CharTableBAYIID->Value=KeyIsleBAYIID->Value;
				CharTable->Post();
				CharTable->Filtered=false;
				}
				else
				{
				 CharTable->Filtered=false;
				 CharTable->Append();
				 CharTableID->Value=String(IDNE);
				 CharTableKAYITZAMAN->Value= Zaman.CurrentDate();
				 CharTableSURE->Value=KeyIsleSURE->Value;
				 CharTableKEY->Value=KeyIsleKEY->Value;
				CharTableBAYIID->Value=KeyIsleBAYIID->Value;
				CharTableIDKON->Value=String(IDKO) ;
				 CharTable->Post();

				}
		   KayitMesaj:
	   KomutBuf[0]=0xD0;
		   *(DWORD *)&KomutBuf[1]=KeyIsleSURE->Value;
	   PacketSifrele(KomutBuf,5,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;
	   Socket->Close();

				}
				else
				{
	   KomutBuf[0]=0xD1;
	   *(DWORD *)&KomutBuf[1]=0xFFFFFFFF;
	   PacketSifrele(KomutBuf,5,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;
	   Socket->Close();

				}


		 break;
	   default:
		Socket->Close();

	   }
		 }
		 catch(...)
		 {
		  Socket->Close();
		 }
	BootServerCikis:
	Socket->Close();
   CharTable->Filtered=false;
  KeyIsle->Filtered=false;

}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button3Click(TObject *Sender)
{
Memo2->Lines->Clear();	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ApplicationEvents1Exception(TObject *Sender,
      Exception *E)
{
BootServerKayit->Active=false;
BootServer->Active=false;
BootServerKayit->Active=true;
BootServer->Active=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CharTableAfterPost(TDataSet *DataSet)
{
DbiSaveChanges(CharTable->Handle);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeyIsleAfterPost(TDataSet *DataSet)
{
DbiSaveChanges(KeyIsle->Handle);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{



	   KeyIsle->First();
		  while(!KeyIsle->Eof)
		  {

		   if(KeyIsleBAYIID->Value==Edit1->Text)
		   {


			  KeyIsle->Edit();
			  KeyIsleSATILDI->Value=1;
			  // KeyIsle->Delete()   ;
				KeyIsle->Post();

				 /*
			  CharTable->Filter="[KEY]='"+KeyIsleKEY->Value+"'";
				CharTable->Filtered=true;

					if(CharTable->RecordCount)
				{

				CharTable->Edit();
				CharTableBAYIID->Value=KeyIsleBAYIID->Value;
				CharTable->Post();
				CharTable->Filtered=false;
				}  */
		   }
		  KeyIsle->Next();
		  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
BYTE x[10];
memset(x,1,10);
x[9]='a';
AnsiString a;
String b="bbbkkkk";
a=b;
}
//---------------------------------------------------------------------------


