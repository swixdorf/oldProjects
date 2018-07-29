//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <IniFiles.hpp>
#include "ThemidaSDK.h"
#include "apihook.h"
#include "eklentiler\packet.h"
#include "eklentiler\MemoryModule.cpp"
#include "koclinet.h"
#include "eklentiler\tanimlamalar.h"
KoThreadClass *Ko_Thread[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
String u,p;
bool otologinnext;
#define msg_deneme 0x90111111
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
TShape *sMenu[20];
KoClinet Client[20] ;
String GetMyTime()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	String asd = IntToStr(st.wHour)+":"+IntToStr(st.wMinute);
	return asd;
}

String cryptstr(String buf){
String a = "abcdefghijklmnopqrstuvwxyz0123456789";
String b = "*-r,.<e!@V4U5b)L{[a}]/7?jkARv|8F'~Q_P";
String ret;
for (int i = 0; i < buf.Length(); i++) {
	ret+=b.SubString(a.AnsiPos(buf.SubString(i+1,1)),1);
}
return ret;
}

String decryptstr(String buf){
String a = "*-r,.<e!@V4U5b)L{[a}]/7?jkARv|8F'~Q_P";
String b = "abcdefghijklmnopqrstuvwxyz0123456789";
String ret;
for (int i = 0; i < buf.Length(); i++) {
	ret+=b.SubString(a.AnsiPos(buf.SubString(i+1,1)),1);
}
return ret;
}

int WINAPI ProcessT(){
while (1){
Application->ProcessMessages();
Sleep(200);
}

}



//---------------------------------------------------------------------------
PacketSifrele(BYTE *Buf,WORD Len,BYTE key)
{
	CODEREPLACE_START
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
	for (int i = 0; i < Len; i++)
	{
		int a=i/2;
		a=a*2;
		if (a==i)
		{
			Donen[5+yer]=Random(Buf[i]);
			Donen[5+yer+1]=Buf[i]-Donen[5+yer];
			yer+=2;
		}
		else
		{
			Donen[5+yer]=Random(Buf[i]);
			Donen[(Len*2+6)-(tersyer)-2]=Buf[i]-Donen[5+yer];
			tersyer++;
			yer++;
		}
	}
	memcpy(Buf,&Donen[0],1024);
	CODEREPLACE_END
	return 1 ;
}

bool PacketCoz(char *Buf,WORD Len)
{
	CODEREPLACE_START
	BYTE Donen[1024];
	WORD ULEN=(Len-7)/2;
	memset(&Donen,0,1024);
	//BYTE MKey=Buf[0]+Buf[3]+Buf[Len-1];
	BYTE key=Buf[4]+Buf[Len-2];
	CODEREPLACE_END
	if (key!=keykontrol)
	{
		return false;
	}
	CODEREPLACE_START
	int yer=0;
	int tersyer=0;
	for (int i = 0; i < ULEN; i++)
	{
		int a=i/2;
		a=a*2;
		if (i==a)
		{
			Donen[i]=Buf[5+yer]+Buf[5+yer+1];
			yer+=2;
		}
		else
		{
			Donen[i]=Buf[5+yer]+Buf[Len-tersyer-3];
			yer++;
			tersyer++;
		}
	}
	CODEREPLACE_END
	*(WORD*)&Buf[0]=ULEN;
	memcpy(&Buf[2],&Donen[0],ULEN);
	return true ;
}

HMEMORYMODULE Manueldll(AnsiString Resname,char *restype)
{
	CODEREPLACE_START
	Data1[128];
	Data2[128];
	Data3[128];
	Data4[128];
	Data5[128];
	TMemoryStream  *ms ;
	TResourceStream   *rs;
	rs = new TResourceStream((int)HInstance, Resname, restype);
	ms = new TMemoryStream();
	ms->LoadFromStream(rs);
	ms->Position = 0;
	DWORD m_DllDataSize = ms->Size;
	void *mp_DllData= GetMemory(m_DllDataSize);
	ms->Read(mp_DllData,m_DllDataSize) ;
	//memcpy(mp_DllData,&Data1,128);
	//memcpy((void*)((int)mp_DllData+95000),&Data2,128);
	//memcpy((void*)((int)mp_DllData+750666),&Data3,128);
	//memcpy((void*)((int)mp_DllData+1789520),&Data4,128);
	//memcpy((void*)((int)mp_DllData+3000000),&Data5,128);
	HMEMORYMODULE a=MemoryLoadLibrary(mp_DllData);
	rs->Free()  ;
	ms->Free();
	CODEREPLACE_END
	return a;
 }







DurumYaz(int No,String Message){
if (Message=="") {
MemoLog[No]->Clear();

}else{
MemoLog[No]->Add(Message);
}
 return 1 ;
}
KoordinatYaz(int No){

SocketForm[No].cX->Text=Ko_Thread[No]->Socket_Bilgi1->X;
SocketForm[No].cY->Text=Ko_Thread[No]->Socket_Bilgi1->Y;
 return 1 ;
}


                                       


String SkillToImage(int sok,String SkillCode){
String buf;
buf =Path+"images/skills/skillicon_";
buf+=SkillCode.SubString(2,2);;
buf+="_";
buf+=IntToStr(Ko_Thread[sok]->Socket_Bilgi1->CharClass)+SkillCode.SubString(1,1);
buf+="_thumb.bmp";
return buf;
}
skillgirisgetir(int sock){

}
int Connect(int No);
 int WINAPI GirisDc(int Param){
		   Sleep(1500);
	   //		KoThreadClass *Ko_Threadsyn=(KoThreadClass *) Param;
//int scno41= (int)Ko_Threadsyn->tsocketno  ;
EnterCriticalSection(&CriticalSection);
//Ko_Thread[Param]->Terminate();
//Ko_Thread[Param]->~KoThreadClass();
//Ko_Thread[Param] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
//Client[Param].Ko_Threadsyn=Ko_Thread[Param];
Connect(Param);
LeaveCriticalSection(&CriticalSection);

return 1;
	   }


int __fastcall SocketGelenVeriHepsi(BYTE *GelenBuf,int len,
						TCustomWinSocket *AktifSocket,
						SocketBilgi *SocketGiris,
						LoginBilgileri *Login_Bilgi,
						int socketno,
						TStrings *DurumYaz ,
						void *ths
						)
{
KoThreadClass *Ko_Threadsyn=(KoThreadClass *) ths;


if(len==0)
{

if(SocketGiris->SocketDurum==0x15000)
 {
// EnterCriticalSection(&CriticalSection);
 Client[socketno].Loaded=false;
 //
	DeleteThreadAll(socketno);
	Client[socketno].IlkLogin=true;
	SocketGiris->TekrarLogin=true;
 SocketGiris->LoginOk=false;
 try {
  Ko_Threadsyn->KoSocket1->Close();
 Ko_Threadsyn->KoSocket1->Active=false;
 } catch (...) {
 }


// Dusur(ServerIps[28],DusurCharId[socketno]);
// LeaveCriticalSection(&CriticalSection);

	if(Client[socketno].AutoLogin)
	{
//	Dusur(ServerIps[28],DusurCharI

	ThreadOlustur((LPTHREAD_START_ROUTINE)GirisDc,(void*)socketno,socketno,"GirisDc");
 //
	}

 }

  return 1;
}


switch(GelenBuf[0])
{

case N3_GAME_SERVER_LOGIN:
{
	if (GelenBuf[1]==0x02) {
	Client[socketno].CharHuman=true;
	BYTE asd[]={0x0C,0x01};
	Ko_Threadsyn->Extern_KomutYolla(asd,sizeof(asd));
	}else if (GelenBuf[1]==0x01){
	Client[socketno].CharHuman=false;
	BYTE asd[]={0x0C,0x01};
	Ko_Threadsyn->Extern_KomutYolla(asd,sizeof(asd));
	}else if (GelenBuf[1]==0x15){
	Form1->log->Items->Add("Server Full Relog Atioz dai : "+IntToStr(socketno));
	Disconnect(socketno);
	}else{

if (SocketForm[socketno].Race->ItemIndex==1) {
BYTE Komut[]={0x05,0x01};
Ko_Threadsyn->Extern_KomutYolla(Komut,2);
Form1->log->Items->Add("Nation Selected : Karus : \["+IntToStr(socketno)+"\]");
}else{
BYTE Komut[]={0x05,0x02};
Ko_Threadsyn->Extern_KomutYolla(Komut,2);
Form1->log->Items->Add("Nation Selected : Human : \["+IntToStr(socketno)+"\]");
}
}

//Ko_Threadsyn->Extern_KomutYolla(Login_Bilgi->SlectGirisCode,Login_Bilgi->SlectGirisUz);
} break;
case 0x64:
{
	if (GelenBuf[1]==0x09)
	{
			if (GelenBuf[2]==0x01)
		{
try {
switch (*(WORD*)&GelenBuf[3]) {
case 8000 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Worm");
Form1->log->Items->Add("Bandicoot");
Form1->log->Items->Add("Kecoon");
Form1->log->Items->Add("Bulcan");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8001 :{ 
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Bandicoot");
Form1->log->Items->Add("Kecoon");
Form1->log->Items->Add("Bulcan");
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8002 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Kecoon");
Form1->log->Items->Add("Bulcan");
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8003 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Bulcan");
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8004 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Bulcan");
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8005 :{
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8006 :{ 
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Gavolt");
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8007 :{ 
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8008 :{ Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Bulture");
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8009 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8010 :{ Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Werewolf");
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8011 :{ Form1->log->Items->Add(socketno);
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add("Zombie");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8012 :{ 
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("silan");
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add("Zombie");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8013 :{ 
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add("Zombie");
Form1->log->Items->Add("Skeleton");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
case 8014 :{
Form1->log->Items->Add(socketno);
Form1->log->Items->Add("Gloomwing");
Form1->log->Items->Add("Scorpion");
Form1->log->Items->Add("Zombie");
Form1->log->Items->Add("Skeleton");
Form1->log->Items->Add(*(WORD*)&GelenBuf[5]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[7]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[9]);
Form1->log->Items->Add(*(WORD*)&GelenBuf[11]);
}break;
default:
	;
}
} catch (...) {
}

}
if (GelenBuf[6]==10) {
Form1->Edit15->Text=    Form1->Edit15->Text.ToIntDef(0)+1;
}
DurumYaz->Add("Gorev:" + IntToStr(GelenBuf[6]));
	}


}break;


case 0x5:{
// BYTE Komut[32]={0x02,0x00};
//Komut[1]=cyer;
//*(WORD*)&Komut[2]=a.Length();
//memcpy(&Komut[4],a.c_str(),a.Length());
//BYTE Komut2[]={0x0D,0xCB,0x00,0x00,0xC6,0x25,0x6D,0x00,0x32,0x32,0x46,0x46,0x3C};
//memcpy(&Komut[4+a.Length()],&Komut2,sizeof(Komut2));
//Ko_Threadsyn->Extern_KomutYolla(Komut,17+a.Length())  ;

BYTE asd[]={0x0C,0x01};
Ko_Threadsyn->Extern_KomutYolla(asd,sizeof(asd));
}break;
  case 0x2:
{
switch (GelenBuf[1]) {
case 0 : {Form1->log->Items->Add("Character Create Done : "+ IntToStr(socketno));}break;
case 3 : {Form1->log->Items->Add("Character Name Error  : "+ IntToStr(socketno));}break;
case 0x11 : {Form1->log->Items->Add("Character Unknown Error : "+ IntToStr(socketno));}break;
default:
	;
}
}break;
  case 0x2b:
{

Ko_Threadsyn->Extern_KomutYolla(Login_Bilgi->ServerGiris,Login_Bilgi->ServerGirisLen);
}break;
  case 0xC:
{
String Character[3];
BYTE Zone[3];
int Yer=2;
Character[0]=ByteToString(&GelenBuf[Yer+2],GelenBuf[Yer]);
Yer+=GelenBuf[Yer];
Zone[0]=GelenBuf[Yer+11];
Yer+=60;
Character[1]=ByteToString(&GelenBuf[Yer+2],GelenBuf[Yer]);
Yer+=GelenBuf[Yer];
Zone[1]=GelenBuf[Yer+11];
Yer+=60;
Character[2]=ByteToString(&GelenBuf[Yer+2],GelenBuf[Yer]);
Yer+=GelenBuf[Yer];
Zone[2]=GelenBuf[Yer+11];
int cyer=loc[socketno];
if (Character[cyer].Length()==0) {
 if (Form1->AutoExp->Checked) {


		 AnsiString a;
//		 for (int i = 0; i < 10; i++) {
//		 char b =97+random(25);
//		 a+=String(b);
//		 }
SocketForm[socketno].Name->Text="";
String baf= "qwertyuiopasdfghjklzxcvbnm1234567890";
for (int i = 0; i < 13; i++) {

	SocketForm[socketno].Name->Text=SocketForm[socketno].Name->Text+baf.SubString(Random(36),1);
}


a=SocketForm[socketno].Name->Text ;
BYTE Komut[32]={0x02,0x00};
Komut[1]=cyer;

*(WORD*)&Komut[2]=SocketForm[socketno].Name->Text.Length();
memcpy(&Komut[4],SocketForm[socketno].Name->Text.c_str(),SocketForm[socketno].Name->Text.Length());



switch (SocketForm[socketno].Type->ItemIndex) {
case 0:{
BYTE Komut2[]={0x0D,0xC9,0x00,0x00,0x03,0x17,0x26,0x00,0x4B,0x41,0x3C,0x32,0x32};
BYTE Komut3[]={0x01,0x65,0x00,0x00,0x21,0x88,0xFA,0x00,0x4B,0x41,0x3C,0x32,0x32};
if (SocketForm[socketno].Race->ItemIndex==1) {
memcpy(&Komut[4+a.Length()],&Komut3,sizeof(Komut3));
}else{
memcpy(&Komut[4+a.Length()],&Komut2,sizeof(Komut2));
}


//Komut[4+a.Length()]=1;
//Komut[5+a.Length()]=0x65;
//Komut[6+a.Length()]=0;
//Komut[7+a.Length()]=100;
//Komut[8+a.Length()]=100;
//Komut[9+a.Length()]=100;
//Komut[10+a.Length()]=0;
//Komut[11+a.Length()]=1;
//Komut[12+a.Length()]=75;
//Komut[13+a.Length()]=65;
//Komut[14+a.Length()]=60;
//Komut[15+a.Length()]=50;
//Komut[16+a.Length()]=50;
}break;
case 1:{
BYTE Komut2[]={0x0D,0xCA,0x00,0x00,0x7F,0x27,0xDB,0x00,0x3C,0x3C,0x50,0x32,0x32};
BYTE Komut3[]={0x02,0x66,0x00,0x00,0x62,0x81,0x42,0x00,0x3C,0x3C,0x50,0x32,0x32,};
if (SocketForm[socketno].Race->ItemIndex==1) {
memcpy(&Komut[4+a.Length()],&Komut3,sizeof(Komut3));
}else{
memcpy(&Komut[4+a.Length()],&Komut2,sizeof(Komut2));
}
//Komut[4+a.Length()]=2;
//Komut[5+a.Length()]=0x66;
//Komut[6+a.Length()]=0;
//Komut[7+a.Length()]=100;
//Komut[8+a.Length()]=100;
//Komut[9+a.Length()]=100;
//Komut[10+a.Length()]=0;
//Komut[11+a.Length()]=1;
//Komut[12+a.Length()]=60;
//Komut[13+a.Length()]=60;
//Komut[14+a.Length()]=80;
//Komut[15+a.Length()]=50;
//Komut[16+a.Length()]=50;
}break;
case 2:{
BYTE Komut2[]={0x0D,0xCB,0x00,0x00,0xCE,0x35,0x4D,0x00,0x32,0x32,0x46,0x46,0x3C};
BYTE Komut3[]={0x03,0x67,0x00,0x00,0x35,0x26,0x31,0x00,0x32,0x32,0x46,0x46,0x3C};
if (SocketForm[socketno].Race->ItemIndex==1) {
memcpy(&Komut[4+a.Length()],&Komut3,sizeof(Komut3));
}else{
memcpy(&Komut[4+a.Length()],&Komut2,sizeof(Komut2));
}


//Komut[4+a.Length()]=3;
//Komut[5+a.Length()]=0x67;
//Komut[6+a.Length()]=0;
//Komut[7+a.Length()]=100;
//Komut[8+a.Length()]=100;
//Komut[9+a.Length()]=100;
//Komut[10+a.Length()]=0;
//Komut[11+a.Length()]=1;
//Komut[12+a.Length()]=50;
//Komut[13+a.Length()]=50;
//Komut[14+a.Length()]=70;
//Komut[15+a.Length()]=70;
//Komut[16+a.Length()]=60;
}break;
case 3:{
BYTE Komut2[]={0x0D,0xCC,0x00,0x00,0xA1,0xB0,0x8F,0x00,0x32,0x46,0x3C,0x46,0x32};
BYTE Komut3[]={0x04,0x68,0x00,0x00,0xF7,0xDE,0x4C,0x00,0x32,0x46,0x3C,0x46,0x32};
if (SocketForm[socketno].Race->ItemIndex==1) {
memcpy(&Komut[4+a.Length()],&Komut3,sizeof(Komut3));
}else{
memcpy(&Komut[4+a.Length()],&Komut2,sizeof(Komut2));
}
//Komut[4+a.Length()]=4;
//Komut[5+a.Length()]=0x68;
//Komut[6+a.Length()]=0;
//Komut[7+a.Length()]=100;
//Komut[8+a.Length()]=100;
//Komut[9+a.Length()]=100;
//Komut[10+a.Length()]=0;
//Komut[11+a.Length()]=1;
//Komut[12+a.Length()]=50;
//Komut[13+a.Length()]=70;
//Komut[14+a.Length()]=60;
//Komut[15+a.Length()]=70;
//Komut[16+a.Length()]=50;


}break;
default:
	;
}

Ko_Threadsyn->Extern_KomutYolla(Komut,17+SocketForm[socketno].Name->Text.Length())  ;
Form1->log->Items->Add(BufferToHex(Komut,17+SocketForm[socketno].Name->Text.Length()));
Form1->log->Items->Add("Character Created : " +a+  " : \["+IntToStr(socketno)+"\]");
Sleep(3000);
Ko_Threadsyn->KoSocket1->Close();
Ko_Threadsyn->CikHepsi=true;
Ko_Threadsyn->Terminated=true;

break;
} else {
Form1->log->Items->Add("Character Not Created In This Server : : \["+IntToStr(socketno)+"\]");
}
}

// AnsiString GelenHex;
//	 GelenHex=BufferToHex(GelenBuf,len);
//	 Form1->Memo2->Lines->Add(GelenHex);
//KoIni = new TIniFile(Path+"KOEMU.ini");

//SwxIni->WriteString("Giris","Account",Form1->AccEkle->Text);
//KoIni->WriteString(Form1->AccountList->Items->Strings[Login_Bilgi->scno],"Char1",Character[0]);
//KoIni->WriteString(Form1->AccountList->Items->Strings[Login_Bilgi->scno],"Char2",Character[1]);
//KoIni->WriteString(Form1->AccountList->Items->Strings[Login_Bilgi->scno],"Char3",Character[2]);

//KoIni->WriteInteger(Form1->AccountList->Items->Strings[Login_Bilgi->scno],"Server",Form1->Serverlar->ItemIndex);
//KoIni->WriteInteger(Form1->AccountList->Items->Strings[Login_Bilgi->scno],"charno",Form1->CharYer->ItemIndex);



//KoIni->Free();

 DurumYaz->Add("Char İsim Alindi Kayıt Yapildi: "+IntToStr(socketno));
otologinnext=true;

//LoginBilgi_Isle->SlectGirisUz=1;
//LoginBilgi_Isle->SlectGirisCode[0]=0x4;
//memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],&Idlen,2);
//LoginBilgi_Isle->SlectGirisUz+=2;
//memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],ID,Idlen);
//LoginBilgi_Isle->SlectGirisUz+=Idlen;

*(WORD*)&Login_Bilgi->SlectGirisCode[Login_Bilgi->SlectGirisUz]=Character[loc[socketno]].Length() ;    //sadece orta car sokar bu amk

Login_Bilgi->SlectGirisUz+=2;
memcpy(&Login_Bilgi->SlectGirisCode[Login_Bilgi->SlectGirisUz],Character[loc[socketno]].c_str(),Character[loc[socketno]].Length());
Login_Bilgi->SlectGirisUz+=Character[loc[socketno]].Length();
Login_Bilgi->SlectGirisCode[Login_Bilgi->SlectGirisUz] =01;
Login_Bilgi->SlectGirisUz++;
Login_Bilgi->SlectGirisCode[Login_Bilgi->SlectGirisUz] =0x15;
Login_Bilgi->SlectGirisUz++;

strcpy(Login_Bilgi->CharId,Character[loc[socketno]].c_str());
Client[socketno].ZoneId=Zone[loc[socketno]];
Ko_Threadsyn->Extern_KomutYolla(Login_Bilgi->SlectGirisCode,Login_Bilgi->SlectGirisUz);
//			  SocketGiris->DcOl=true;
//
//			  AktifSocket->Close();



}
 break;
 case 0xF3:
if (Client[socketno].ProxyEnable) {
 Ko_Threadsyn->ServerIp = ProxyIps[srv[socketno]];//
}else{
 Ko_Threadsyn->ServerIp = ServerIps[srv[socketno]];//
}


 Dusur(Ko_Threadsyn->ServerIp ,Login_Bilgi->CharId);
break;

case 0xE:
{
BYTE K[32];
K[0]=1 ;
K[1]=socketno;
*(WORD*)&K[2]=*(WORD*)&GelenBuf[1];
K[4]= String(Login_Bilgi->CharId).Length();
memcpy(&K[5],String(Login_Bilgi->CharId).c_str(),K[4]);
//Form1->ClientSocket2->Socket->SendBuf(K,K[2]+3);
DurumYaz->Clear();






			  memcpy(&SocketGiris->CharID,&GelenBuf[1],2) ;
              Client[socketno].Id=SocketGiris->CharID ;
			int GidenLen=0;
			GidenLen=GelenBuf[3]; //Login_Bilgi->CharId.Length();
			int ServerLen=0;
			ServerLen=GelenBuf[GidenLen+0x36];//0x2B]; // 33-2b=8
			 char ServerName [25];
			memset(ServerName,0,25);
				if(ServerLen==0)
			{
				ServerLen=0;
			}
			else
			{


			memcpy(ServerName,&GelenBuf[GidenLen+0x36+1],ServerLen);
			}
			 SocketGiris->Level=GelenBuf[21+GidenLen];
			 SocketGiris->CharClass=GelenBuf[12+GidenLen];

			 Client[socketno].Point=*(WORD*)&GelenBuf[22+GidenLen];


			 Client[socketno].SkillPoint=GelenBuf[0x70+ServerLen+GidenLen];
			 Client[socketno].Skill0=GelenBuf[0x75+ServerLen+GidenLen];
			 Client[socketno].Skill1=GelenBuf[0x76+ServerLen+GidenLen];
			 Client[socketno].Skill2=GelenBuf[0x77+ServerLen+GidenLen];
			 Client[socketno].Skill3=GelenBuf[0x78+ServerLen+GidenLen];
			 Client[socketno].NeedExp=*(INT64*)&GelenBuf[24+GidenLen];
			 Client[socketno].CurrExp=*(INT64*)&GelenBuf[32+GidenLen];
			 Client[socketno].Str=GelenBuf[0x55+ServerLen+GidenLen];
			 Client[socketno].StrP=GelenBuf[0x56+ServerLen+GidenLen];
			 Client[socketno].Hp=GelenBuf[0x57+ServerLen+GidenLen];
			 Client[socketno].HpP=GelenBuf[0x58+ServerLen+GidenLen];
			 Client[socketno].Dex=GelenBuf[0x59+ServerLen+GidenLen];
			 Client[socketno].DexP=GelenBuf[0x5A+ServerLen+GidenLen];
			 Client[socketno].Int=GelenBuf[0x5B+ServerLen+GidenLen];
			 Client[socketno].IntP=GelenBuf[0x5C+ServerLen+GidenLen];
			 Client[socketno].Mp=GelenBuf[0x5D+ServerLen+GidenLen];
			 Client[socketno].MpP=GelenBuf[0x5E+ServerLen+GidenLen];
			 Client[socketno].AP=*(DWORD*)&GelenBuf[0x5F+ServerLen+GidenLen];
			 Client[socketno].DEF=*(DWORD*)&GelenBuf[0x61+ServerLen+GidenLen];



		   memcpy(&SocketGiris->Para,&GelenBuf[0x5E+8+3+ServerLen+GidenLen],4) ;
		   memcpy(&SocketGiris->MaxMana,&GelenBuf[0x3E+8+3+ServerLen+GidenLen],2) ;
		   memcpy(&SocketGiris->Mana,&GelenBuf[0x3E+8+3+ServerLen+GidenLen+2],2) ;
		   memcpy(&SocketGiris->MaxHp,&GelenBuf[0x3E+4+3+ServerLen+GidenLen],2) ;
		   memcpy(&SocketGiris->Hp,&GelenBuf[0x3E+4+3+ServerLen+GidenLen+2],2) ;

			  for (int i = 0; i < 14; i++) {
			  SocketGiris->Gear_Table[i].Id=*(DWORD*)&GelenBuf[0x79+ServerLen+GidenLen+i*19];
			  SocketGiris->Gear_Table[i].Durability=*(WORD*)&GelenBuf[0x79+4+ServerLen+GidenLen+i*19];
			  }
			  for (int i = 0; i < 28; i++) {
			  SocketGiris->Item_Table[i].Id=*(DWORD*)&GelenBuf[0x79+ServerLen+GidenLen+i*19+19*14];
			  SocketGiris->Item_Table[i].Durability=*(WORD*)&GelenBuf[0x79+4+ServerLen+GidenLen+i*19+19*14];
			  }
			  if (Form1->AutoExp->Checked) {
			  if (SocketGiris->Gear_Table[6].Id==0) {
			BYTE Komut[]={0x1F,0x01,0x51,0x9C,0x8C,0x09,0x00,0x06};
			   *(DWORD*)&Komut[2]=SocketGiris->Item_Table[0].Id;
			   Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
			  }
			  }


			SocketGiris->CharName=Login_Bilgi->CharId;
String YazilacakClass;
if (Client[socketno].CharHuman) {
SocketGiris->CharClass-=100;
}
if (SocketGiris->CharClass==106||SocketGiris->CharClass==108||SocketGiris->CharClass==110||SocketGiris->CharClass==112) {
Client[socketno].CharMaster=true;
YazilacakClass="Master ";
}else{
SocketGiris->CharClass++;
Client[socketno].CharMaster=false;
}
switch (SocketGiris->CharClass) {
case 108:Client[socketno].CharTipi=0;YazilacakClass+="Rogue";break;
case 112:Client[socketno].CharTipi=1;YazilacakClass+="Priest";break;
case 106:Client[socketno].CharTipi=2;YazilacakClass+="Warrior";break;
case 110:Client[socketno].CharTipi=3;YazilacakClass+="Mage";break;
case 103:Client[socketno].CharTipi=0;YazilacakClass+="Noob Rogue";break;
case 105:Client[socketno].CharTipi=1;YazilacakClass+="Noob Priest";break;
case 102:Client[socketno].CharTipi=2;YazilacakClass+="Noob Warrior";break;
case 104:Client[socketno].CharTipi=3;YazilacakClass+="Noob Mage";break;


default:

	;
}
skillgirisgetir(socketno);



Client[socketno].ZoneChange(Client[socketno].ZoneId);
			DurumYaz->Add("Clan  : " +String(ServerName));
			DurumYaz->Add("Level : "+IntToStr(SocketGiris->Level));
			DurumYaz->Add("Name  : "+String(Login_Bilgi->CharId));
			DurumYaz->Add("Money : " +IntToStr(SocketGiris->Para));
			DurumYaz->Add("Class : "+YazilacakClass);
			DurumYaz->Add("Zone : "+Client[socketno].ZoneName);
			DurumYaz->Add("Coord : "+IntToStr(SocketGiris->X)+","+IntToStr(SocketGiris->Y));

			GidenLen+=379+ServerLen+8;//382;   larfowide65 398
			SocketGiris->LoginOk=true;


			SocketForm[socketno].SocketGroup->Caption=String(Login_Bilgi->CharId);
			//SocketForm[socketno].Menu->Caption=String(Login_Bilgi->CharId);
			BYTE Kmt[]={0x6a,0x02};
			Ko_Threadsyn->Extern_KomutYolla(Kmt,sizeof(Kmt));


		 ThreadOlustur((LPTHREAD_START_ROUTINE)Thread41,(void*)Ko_Threadsyn,socketno,"Thread41");
		 ThreadOlustur((LPTHREAD_START_ROUTINE)AnaThread,(void*)Ko_Threadsyn,socketno,"AnaThread");
		 if (Client[socketno].AutoAtack) {
		 ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)socketno,socketno,"AtackThread");
		 }


						Sleep(2000);
			if (Client[socketno].AutoMine) {

			Client[socketno].CharacterMove(Client[socketno].Zone.Pitman.X,Client[socketno].Zone.Pitman.Y,2) ;
//				if ((Client[socketno].AutoRepair)&&(SocketGiris->Gear_Table[6].Durability<500)) {
//				DurumYaz->Add("Goto Rpr");
//
//				Client[socketno].CharacterMove(Client[socketno].Zone.Sundress.X,Client[socketno].Zone.Sundress.Y,3);
//				}else{
//				Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
//				Client[socketno].CharacterMove(Form1->MineX->Text.ToIntDef(0),Form1->MineY->Text.ToIntDef(0),4);
//
//				}
			}else if (Client[socketno].Dolas){
			   Client[socketno].CharacterMove(SocketForm[0].ListX->Items->Strings[0].ToIntDef(0),SocketForm[0].ListY->Items->Strings[0].ToIntDef(0),6);
}
if (Form1->CheckBox19->Checked) {
 Client[socketno].CharacterMove(Client[socketno].ChaosX,Client[socketno].ChaosY,0);
}else if (Form1->mapal->Checked) {
Client[socketno].CharacterMove(866,531,16);
}else if (Form1->matokal->Checked) {
Client[socketno].CharacterMove(Client[socketno].Zone.Pitman.X,Client[socketno].Zone.Pitman.Y,11);
}
Form1->log->Items->Add("Character Login : "+SocketGiris->CharName+"\["+ IntToStr(socketno)+"\] Level : "+IntToStr(SocketGiris->Level)) ;

WORD MaxHp =SocketGiris->MaxHp;
if (MaxHp>1500) {
Client[socketno].HpPotIndex =3;
}else if (MaxHp>700) {
Client[socketno].HpPotIndex =2;
} else if (MaxHp>350) {
Client[socketno].HpPotIndex =1;
}else{
Client[socketno].HpPotIndex =0;
}


WORD MaxMp =SocketGiris->MaxMana;

if (MaxMp>2500) {
Client[socketno].MpPotIndex =3;
}else if (MaxMp>1500) {
Client[socketno].MpPotIndex =2;
} else if (MaxMp>700) {
Client[socketno].MpPotIndex =1;
}else{
Client[socketno].MpPotIndex =0;
}




 if (Client[socketno].PartiBaskan) {
  BYTE Komut[]={0x2F,0x05};
for (int i = 0; i < 8; i++) {
Client[i].KomutYolla(Komut,sizeof(Komut));
}
int  a=1;
for (int i = 0; i < 8; i++) {
if (i!=socketno) {
String Kodd=Ko_Thread[i]->Socket_Bilgi1->CharName;
BYTE PtKomut[50];
memset(&PtKomut,0,50);
PtKomut[0]=0x2f;
PtKomut[1]=a;
a=3;
PtKomut[2]=Kodd.Length();
memcpy(&PtKomut[4],Kodd.c_str(),Kodd.Length());
Ko_Threadsyn->Extern_KomutYolla(PtKomut,Kodd.Length()+4)  ;
Client[i].PartiBaskan=false;
}else{
//PartiKuran=Ko_Thread[i]->Socket_Bilgi1->CharName;
Client[i].PartiBaskan=true;
}
}
}else{
for (int i = 0; i < 8; i++) {
if (Client[i].PartiBaskan) {
BYTE PtKomut[50];
memset(&PtKomut,0,50);
PtKomut[0]=0x2f;
PtKomut[1]=0x3;
PtKomut[2]=SocketGiris->CharName.Length();
memcpy(&PtKomut[4],SocketGiris->CharName.c_str(),SocketGiris->CharName.Length());
Client[i].KomutYolla(PtKomut,SocketGiris->CharName.Length()+4)  ;
Client[socketno].DeathTime=GetTickCount();
Client[socketno].Dead=true;
}
}
}



Client[socketno].Updurum=true;;
}	break;




case 0x30:
{
if (GelenBuf[1]==0x2) {
if (GelenBuf[2]==1) {
DurumYaz->Add("Trade Opened:"+ IntToStr(*(WORD*)&GelenBuf[2]));
if (Client[socketno].ItemVerilecek) {
DurumYaz->Add("Trade GiveList:"+ IntToStr(*(WORD*)&GelenBuf[2]));
	 for (int i = 0; i < 28; i++) {
	 if (Form1->TradeList->Items->IndexOf(SocketGiris->Item_Table[i].Id)!=-1) {
BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
VerKomut[2]=i;
*(DWORD*)&VerKomut[3]=SocketGiris->Item_Table[i].Id;
*(WORD*)&VerKomut[7]=SocketGiris->Item_Table[i].Adet;
Ko_Threadsyn->Extern_KomutYolla(VerKomut,sizeof(VerKomut));
	 }
	 }

 if (Form1->paraver->Checked) {
BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
*(DWORD*)&Komut[7]=Ko_Threadsyn->Socket_Bilgi1->Para-100000;
Client[socketno].KomutYolla(Komut,sizeof(Komut));
}
BYTE TKomut2[]={0x30,0x05};
Ko_Threadsyn->Extern_KomutYolla(TKomut2,sizeof(TKomut2));
Client[socketno].ItemVerilecek=false;
}
//if (ParaVerilecek) {
//BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
//*(DWORD*)&Komut[7]=Form1->Edit6->Text.ToIntDef(0);
//KomutYolla(Komut,sizeof(Komut),0);
// BYTE TradeqKomut[]={0x30,5};
//KomutYolla(TradeqKomut,2,0);
//ParaVerilecek=false;
//}
//if (ItemVerilecek) {
//BYTE ItemSayisi=0;
//for (int i = 0; i < 9; i++) {
//GetInvertoryList(i,&InvertoryItemList[i],1);
//if (InvertoryItemList[i].ItemID!=0) {
//ItemSayisi++;
//BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
//VerKomut[2]=i;
//*(DWORD*)&VerKomut[3]=InvertoryItemList[i].ItemID;
//*(WORD*)&VerKomut[7]=InvertoryItemList[i].ItemSayi;
//KomutYolla(VerKomut,sizeof(VerKomut),0);
//}
//if (ItemSayisi>9) {
//goto Sonn;
//}
//}
//Sonn:
// BYTE TradeqKomut[]={0x30,5};
//KomutYolla(TradeqKomut,2,0);
//ItemVerilecek=false;
//}}
}
//if (Komut[1]==0x6) {
//BYTE Komut[]={0x5B,0x05,0xB8,0x2A,0x28,0x20,0x32,0x17,0x00};
////GetInvertoryList(0,&InvertoryItemList[0],1);
////*(DWORD*)&Komut[4]=InvertoryItemList[0].ItemID;
//*(DWORD*)&Komut[4]=0x1732a8e0  ;
//KomutYolla(Komut,sizeof(Komut),0);
//}
if (GelenBuf[1]==0x1) {
DurumYaz->Add("Trade Req:"+ IntToStr(*(WORD*)&GelenBuf[2]));

for (int i = 0; i < 20; i++) {
if(*(WORD*)&GelenBuf[2]==Ko_Thread[i]->Socket_Bilgi1->CharID){
BYTE TKomut[]={0x30,0x02,0x01};
Ko_Threadsyn->Extern_KomutYolla(TKomut,sizeof(TKomut));
BYTE TKomut2[]={0x30,0x05};
Ko_Threadsyn->Extern_KomutYolla(TKomut2,sizeof(TKomut2));
}
}
if (Form1->Trade->ItemIndex==1) {
BYTE TKomut[]={0x30,0x02,0x01};
Ko_Threadsyn->Extern_KomutYolla(TKomut,sizeof(TKomut));
BYTE TKomut2[]={0x30,0x05};
Ko_Threadsyn->Extern_KomutYolla(TKomut2,sizeof(TKomut2));
}


if (Form1->Trade->ItemIndex==3) {
BYTE TKomut[]={0x30,0x02,0x01};
Ko_Threadsyn->Extern_KomutYolla(TKomut,sizeof(TKomut));

}
if (Form1->Trade->ItemIndex==2) {
BYTE TKomut[]={0x30,0x02,0x00};
Ko_Threadsyn->Extern_KomutYolla(TKomut,sizeof(TKomut));

}
}
}break;



case 0x23:{
if (!Client[socketno].AutoMine) {
Client[socketno].DelNpc(*(WORD*)&GelenBuf[1]);
//DelItem(&Yaratiklarim[socketno],*(WORD*)&GelenBuf[1]);
 if (Client[socketno].AutoLoot) {
Client[socketno].KutuAc(*(DWORD*)&GelenBuf[3]);
 }
 }
	}break;
case 0x24:{
		   Client[socketno].ItemAl(GelenBuf);
	}break;
case 0x1c:{
GelenBuf[0]=0x1d;
Ko_Threadsyn->Extern_KomutYolla(GelenBuf,len);
	}break;

case 0x17:{
if (SocketGiris->MaxHp!=*(WORD*)&GelenBuf[1]) {
if (SocketGiris->MaxHp>*(WORD*)&GelenBuf[1]) {
Client[socketno].Buff=0;
}
WORD MaxHp =Ko_Threadsyn->Socket_Bilgi1->MaxHp;
if (MaxHp>1500) {
Client[socketno].HpPotIndex =3;
}else if (MaxHp>700) {
Client[socketno].HpPotIndex =2;
} else if (MaxHp>350) {
Client[socketno].HpPotIndex =1;
}else{
Client[socketno].HpPotIndex =0;
}
}
SocketGiris->MaxHp=*(WORD*)&GelenBuf[1];
SocketGiris->Hp=*(WORD*)&GelenBuf[3];




}break;
case 0x18:{
if (SocketGiris->MaxMana!=*(WORD*)&GelenBuf[1]) {
WORD MaxMp =Ko_Threadsyn->Socket_Bilgi1->MaxMana;

if (MaxMp>2500) {
Client[socketno].MpPotIndex =3;
}else if (MaxMp>1500) {
Client[socketno].MpPotIndex =2;
} else if (MaxMp>700) {
Client[socketno].MpPotIndex =1;
}else{
Client[socketno].MpPotIndex =0;
}
}
SocketGiris->MaxMana=*(WORD*)&GelenBuf[1];
SocketGiris->Mana=*(WORD*)&GelenBuf[3];
}break;
case 0x86:{
if (*(WORD*)&GelenBuf[4]==SocketGiris->CharID) {
if (GelenBuf[1]==0x03) {
if (Ko_Threadsyn->Socket_Bilgi1->Kaz) {
Client[socketno].CharacterMove(Client[socketno].Zone.Pitman.X,Client[socketno].Zone.Pitman.Y,2);
}
}
 AnsiString GelenHex;
	 GelenHex=BufferToHex(GelenBuf,2);
	 DurumYaz->Add("r-"+GelenHex) ;

}

}break;
case 0x3b:{
SocketGiris->Gear_Table[6].Durability=4000;

}break;
case 0x4:
{
SocketGiris->X=*(WORD*)&GelenBuf[3]/10;
SocketGiris->Y=*(WORD*)&GelenBuf[5]/10;
//KoordinatYaz(socketno);
char IDAl[255];//{0x53, 0x70, 0x6D, 0x65, 0x65, 0x72};
memset(IDAl,0,255);



DurumYaz->Add("Bilgi Gtiitti");
IDAl[0]=0xD;
IDAl[1]=0x1;
IDAl[2]=Ko_Threadsyn->oyuncahar.Length();

memcpy(&IDAl[3],Ko_Threadsyn->oyuncahar.c_str(),IDAl[2]);
int GidLen=IDAl[2]+3;

 Ko_Threadsyn->Extern_KomutYolla(IDAl,GidLen)  ;

 ::Sleep(100);


IDAl[1]=0x2;

 Ko_Threadsyn->Extern_KomutYolla(IDAl,GidLen)  ;


}    break;

case 0x6A:{
Client[socketno].InventoryRefreshState=true;
if (GelenBuf[1]==0x05&&GelenBuf[2]==0x02&&GelenBuf[3]==0x01) {
Form1->LetterItem->Items->Clear();
Form1->LetterAdet->Items->Clear();
Form1->LetterId->Items->Clear();
for (int i = 0; i <GelenBuf[4] ; i++) {
Form1->LetterId->Items->Add(*(DWORD*)&GelenBuf[36*i+5]);
Form1->LetterItem->Items->Add(*(DWORD*)&GelenBuf[36*i+9]);
Form1->LetterAdet->Items->Add(*(WORD*)&GelenBuf[36*i+13]);
}
}



if (GelenBuf[1]==0x02){

WORD Yer=2;
memset(SocketGiris->Item_Table,sizeof(SocketGiris->Item_Table),0);
for(int i=0;i<28;i++){
SocketGiris->Item_Table[i].Id=*(DWORD*)&GelenBuf[Yer];

Yer+=4;
//InvertoryItemList[i].ItemTip=*(WORD*)&Komut[Yer];
Yer+=2;
SocketGiris->Item_Table[i].Adet=*(WORD*)&GelenBuf[Yer];
Yer+=5;
}

	}
	}break;

case 0x5b:{
//BufferToHex(Komut,Param2,&GelenHex);
//Form1->Memo2->Lines->Add("R-"+IntToStr(GetTickCount())+"-"+GelenHex);
if (GelenBuf[3]==2) {
Client[socketno].Updurum=false;
Disconnect(socketno);
}
}break;
case 0x10:{
if (!Client[socketno].AutoMine) {
  WORD YollayanID=*(WORD*)&GelenBuf[3];
  BYTE IsimUzunluk=*(BYTE*)&GelenBuf[5];
  AnsiString Isim;
  Isim=ByteToString(&GelenBuf[6],IsimUzunluk);
  WORD MesajUzunluk=*(WORD*)&GelenBuf[IsimUzunluk+6];
  AnsiString Mesaj;
  if (*(DWORD*)&GelenBuf[IsimUzunluk+8]!=Client[socketno].SpeCode) {
  return 0;
  }

  Mesaj=ByteToString(&GelenBuf[IsimUzunluk+12],MesajUzunluk-4);
  DurumYaz->Add(Mesaj);
  if (Mesaj=="UsEr1") {
  String Gitcek="Id:"+IntToStr(SocketGiris->CharID) +"Coor: " +IntToStr((int)SocketGiris->X) +"--"+IntToStr((int)SocketGiris->Y);
// PmYolla(Isim,Gitcek);
  }
if (Mesaj=="UsEr2") {
//BYTE DC[]={0x00,0x00};
//KomutYolla(DC,2,0);

}
if (Mesaj=="Tp") {

BYTE Tp1[]={0x31,0x01,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,};
BYTE Tp3[]={0x31,0x03,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0xCF,0x01,0x90,0x00,0x6B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Tp1[6] =SocketGiris->CharID;
*(WORD*)&Tp3[6] =SocketGiris->CharID;
*(WORD*)&Tp1[8] =YollayanID;
*(WORD*)&Tp3[8] =YollayanID;
String SkillCode=*(DWORD*)&Tp1[2];
String sk;
if (Client[socketno].CharMaster) {
sk = Ko_Thread[socketno]->Socket_Bilgi1->CharClass;
}else{
sk = Ko_Thread[socketno]->Socket_Bilgi1->CharClass-1;
}
sk+=SkillCode.SubString(4,3);
*(DWORD*)&Tp1[2]=sk.ToIntDef(0);
*(DWORD*)&Tp3[2]=sk.ToIntDef(0);
Client[socketno].KomutYolla(Tp1,sizeof(Tp1));
Client[socketno].KomutYolla(Tp3,sizeof(Tp3));
}
if (Mesaj=="SlotTp") {

BYTE Tp1[]={0x31,0x01,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,};
BYTE Tp3[]={0x31,0x03,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0xCF,0x01,0x90,0x00,0x6B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Tp1[6] =SocketGiris->CharID;
*(WORD*)&Tp3[6] =SocketGiris->CharID;
*(WORD*)&Tp1[8] =YollayanID;
*(WORD*)&Tp3[8] =YollayanID;
String SkillCode=*(DWORD*)&Tp1[2];
String sk;
if (Client[socketno].CharMaster) {
sk = Ko_Thread[socketno]->Socket_Bilgi1->CharClass;
}else{
sk = Ko_Thread[socketno]->Socket_Bilgi1->CharClass-1;
}
sk+=SkillCode.SubString(4,3);
*(DWORD*)&Tp1[2]=sk.ToIntDef(0);
*(DWORD*)&Tp3[2]=sk.ToIntDef(0);

float mes=hypot((Ko_Thread[socketno]->Socket_Bilgi1->X-Client[socketno].CenterX),(Ko_Thread[socketno]->Socket_Bilgi1->Y-Client[socketno].CenterY));
if (mes<200) {
Client[socketno].KomutYolla(Tp1,sizeof(Tp1));
Client[socketno].KomutYolla(Tp3,sizeof(Tp3));
}
}


if (Mesaj=="YuzdeBes") {
//SkillBas(108610,4,0,0x10);
}
if (Mesaj=="YuzdeOn") {
//SkillBas(108650,4,0,0x10);
}
if (Mesaj.SubString(1,6)=="Follow") {
String Kodd;
Kodd=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));
if (Kodd=="On") {

//SocketGiris->AdamFollow=YollayanID;
Client[socketno].FollowId=YollayanID;
SocketGiris->FollowAktif =true;
}else if (Kodd=="Off") {
SocketGiris->FollowAktif=false;
}
}
if (Mesaj=="Town") {
BYTE Komut[]={0x48,0x00};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
}

if (Mesaj=="Ts") {
BYTE Komut[]={0x31,0x03,0xEC,0x2F,0x07,0x00,0x6D,0x04,0x6D,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*(WORD*)&Komut[6]=SocketGiris->CharID;
*(WORD*)&Komut[8]=SocketGiris->CharID;
//KomutYolla(Komut,sizeof(Komut),0);
}
if (Mesaj=="ExitParty") {
BYTE Komut[3]={0x2F,0x05};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
}

if (Mesaj.SubString(1,10)=="Support") {

String Target;
Target=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));
Client[socketno].SupportId=StrToInt(Target);
}
if (Mesaj.SubString(1,2)=="Go") {
SocketGiris->AdresX=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.AnsiPos(",")-Mesaj.AnsiPos(" ")-1).ToIntDef(SocketGiris->X);
SocketGiris->AdresY=Mesaj.SubString(Mesaj.AnsiPos(",")+1,Mesaj.Length()-Mesaj.AnsiPos(",")).ToIntDef(SocketGiris->Y)   ;
SocketGiris->Go=true;

}
if (Mesaj.SubString(1,3)=="Set") {
for (int i = 0; i < 20; i++) {
Client[i].CenterX=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.AnsiPos(",")-Mesaj.AnsiPos(" ")-1).ToIntDef(SocketGiris->X);
Client[i].CenterY=Mesaj.SubString(Mesaj.AnsiPos(",")+1,Mesaj.Length()-Mesaj.AnsiPos(",")).ToIntDef(SocketGiris->Y)   ;
}
}

if (Mesaj.SubString(1,5)=="Atack") {
String Kodd;
Kodd=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));
if (Kodd=="On") {
TerminateThread(AtackThreadHandle[socketno],1);
Client[socketno].CenterX=Ko_Thread[0]->Socket_Bilgi1->X;
Client[socketno].CenterY=Ko_Thread[0]->Socket_Bilgi1->Y;
Client[socketno].AutoAtack=true;
Client[socketno].AutoSell=true;
 ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)socketno,socketno,"AtackThread");

}else if (Kodd=="Off") {
TerminateThread(AtackThreadHandle[socketno],1);
Client[socketno].AutoAtack=false ;
}
}
if (Mesaj.SubString(1,5)=="Potion") {
Client[socketno].CharacterMove(Client[socketno].Zone.Potion.X,Client[socketno].Zone.Potion.Y,5);
}


if (Mesaj.SubString(1,3)=="Add") {
String Kodd;
Kodd=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));


BYTE PtKomut[50];
memset(&PtKomut,0,50);
PtKomut[0]=0x2f;
if (Ko_Thread[socketno]->Socket_Bilgi1->Party) {
PtKomut[1]=0x3;
} else {
PtKomut[1]=0x1;
Ko_Thread[socketno]->Socket_Bilgi1->Party=true;
}

PtKomut[2]=Kodd.Length();
memcpy(&PtKomut[4],Kodd.c_str(),Kodd.Length());
Client[socketno].KomutYolla(PtKomut,Kodd.Length()+4)  ;

}
if (Mesaj.SubString(1,3)=="Sit") {
String Kodd;
Kodd=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));
if (Kodd=="On") {
BYTE Komut[]={0x29,0x01,0x02,0x00,0x00,0x00,0x00,0x00};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
}else{
BYTE Komut[]={0x29,0x01,0x01,0x00,0x00,0x00,0x00,0x00};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
}


}
if (Mesaj.SubString(1,7)=="Support") {
//SupportId=YollayanID;
//SocketGiris->AdamFollow=YollayanID;
SocketGiris->FollowAktif =true;

}
if (Mesaj.SubString(1,4)=="Send") {
String Kodd;
Kodd=Mesaj.SubString(Mesaj.AnsiPos(" ")+1,Mesaj.Length()-Mesaj.AnsiPos(" "));
//KodYolla(Kodd);

}
}
}break;
 case 0x4b:{
if (GelenBuf[1]==0x01) {
Form1->ListBoxtt->Items->Clear();
int Yer=4;
for (int i = 0; i < *(WORD*)&GelenBuf[2]; i++) {
Gate[i]= *(WORD*)&GelenBuf[Yer];
Yer+=2;
Form1->ListBoxtt->Items->Add(ByteToString(&GelenBuf[Yer+2],*(WORD*)&GelenBuf[Yer])) ;
Yer+= *(WORD*)&GelenBuf[Yer];
Yer+=2;
Yer+= *(WORD*)&GelenBuf[Yer];
Yer+=2;
Yer+=8;
}
}
}break;

case 0x06:{
if (*(WORD*)&GelenBuf[1]==SocketGiris->CharID) {
//if (SocketForm[socketno].Dolas->Checked) {
//
//}else{
//	SocketGiris->X=*(WORD*)&GelenBuf[3]/10;
//	SocketGiris->Y=*(WORD*)&GelenBuf[5]/10;
//	KoordinatYaz(socketno);
//}
}else{
for (int i = 0; i < 20; i++) {
if (Client[i].Ko_Threadsyn->Socket_Bilgi1->CharID==*(WORD*)&GelenBuf[1]) {
	if (SocketForm[socketno].List->Items->IndexOf(*(WORD*)&GelenBuf[1])==-1) {
		SocketForm[socketno].List->Items->Strings[i]=(*(WORD*)&GelenBuf[1]);
	}
}
}    


if (Client[socketno].AtackType!=2) {
if (Client[socketno].IsPlayerAdded(*(WORD*)&GelenBuf[1])!=-1) {
Client[socketno].SetPlayer(*(WORD*)&GelenBuf[1],*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10) ;
}else{
if (!Client[socketno].AutoMine) {
BYTE DKomut[]={0x16,0x01,0x00,0x94,0x2A};

*(WORD*)&DKomut[3]=*(WORD*)&GelenBuf[1];
Client[socketno].KomutYolla(DKomut,sizeof(DKomut));
}
}
if (SocketGiris->FollowAktif) {
	if (*(WORD*)&GelenBuf[1]==Client[socketno].FollowId) {
	for (int i = 0; i < 20; i++) {
	if ((GetTickCount()-Client[i].LastFollowTime>1000)) {
    Client[i].LastFollowTime=GetTickCount();
	Client[i].CharacterMove(*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10,0);
	}
	}
}
}

}
}
}break;
case 0x1e:{
SocketGiris->X=*(WORD*)&GelenBuf[1]/10;
SocketGiris->Y=*(WORD*)&GelenBuf[3]/10;
Client[socketno].TownState=true;
}break;
case 0x27:{
if ( GelenBuf[1]==0x03) {
SocketGiris->X=*(WORD*)&GelenBuf[4]/10;
SocketGiris->Y=*(WORD*)&GelenBuf[6]/10;
Client[socketno].ZoneChange(GelenBuf[2]) ;
DurumYaz->Add("Zone Change : " + Client[socketno].ZoneName) ;;
if (GelenBuf[2]==0x15) {
BYTE Komut[]= {0x12,0x01};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
Disconnect(socketno);

}else if (GelenBuf[2]==85) {

//Client[socketno].chaosgir=false;

}else if (GelenBuf[2]==92) {
for (int i = 0; i < 20; i++) {
Client[i].AutoLogin=false;
BYTE Komut[]= {0x0};
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
BYTE Komut[]={0,0} ;
Komut[0]=0x68;
Komut[1]=0x08;

Ko_Threadsyn->Extern_KomutYolla(Komut,2);
Komut[0]=0x3c;
Komut[1]=0x41;

Ko_Threadsyn->Extern_KomutYolla(Komut,2);
Komut[0]=0x27;
Komut[1]=0x1;

Ko_Threadsyn->Extern_KomutYolla(Komut,2);
//KoordinatYaz(socketno);
}else if ( GelenBuf[1]==0x02){

Ko_Threadsyn->Extern_KomutYolla(GelenBuf,sizeof(GelenBuf));
}

}break;
  case 0x2f:
{
switch (GelenBuf[1]) {
case 2:{
 String CharName=ByteToString(&GelenBuf[6],GelenBuf[4]);
 DurumYaz->Add("Party Requested : "+CharName)   ;
 if (Client[socketno].AutoParty) {
BYTE Komut[3]={0x2F,0x02,0x01};
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
 }
 }
break;
case 3:{
SocketGiris->Party=true;
int MemberYer=0;
if (GelenBuf[4]!=0x64) {
MemberYer=GelenBuf[4];
}else{
Client[socketno].FollowId=*(WORD*)&GelenBuf[2];
SocketGiris->FollowAktif =true;
}
SocketGiris->PartyMember[MemberYer].Id=*(WORD*)&GelenBuf[2];

String CharName=ByteToString(&GelenBuf[7],GelenBuf[5]);
//SocketGiris->PartyMember[MemberYer].Name=CharName;

DurumYaz->Add("Party Added : "+CharName)   ;
SocketGiris->PartyMember[MemberYer].Hp=GelenBuf[GelenBuf[5]+7];
SocketGiris->PartyMember[MemberYer].MaxHp=GelenBuf[GelenBuf[5]+9];
SocketGiris->PartyMember[MemberYer].Mp=GelenBuf[GelenBuf[5]+11];
SocketGiris->PartyMember[MemberYer].MaxMp=GelenBuf[GelenBuf[5]+13];
SocketGiris->Party=true;
}break;
//case 4:{
//if (*(WORD*)&GelenBuf[2]==SocketGiris->CharID) {
//SocketGiris->Party=false;
//for (int i = 0; i < 8; i++) {
//SocketGiris->PartyMember[i].Id=0;
//}
//}else{
//for (int i = 0; i < 8; i++) {
//if (SocketGiris->PartyMember[i].Id==*(WORD*)&GelenBuf[2]) {
//SocketGiris->PartyMember[i].Id=0;
//}
//}
//}
//
//
//}break;
//case 5:{
//
//for (int i = 0; i < 8; i++) {
//SocketGiris->PartyMember[i].Id=0;
//

//}
//SocketGiris->Party=false;
//}break;
default:

	;
}


// AnsiString GelenHex;
//	 GelenHex=BufferToHex(GelenBuf,len);
//	 DurumYaz->Add("r-"+GelenHex) ;
}break;
case 0xB:{
if (Client[socketno].IsAdded(*(WORD*)&GelenBuf[1])!=-1) {
Client[socketno].SetNpc(*(WORD*)&GelenBuf[1],*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10) ;
}else{
BYTE DKomut[]={0x1D,0x01,0x00,0x94,0x2A};
*(WORD*)&DKomut[3]=*(WORD*)&GelenBuf[1];
Client[socketno].KomutYolla(DKomut,sizeof(DKomut));
//AddNpc(socketno,*(WORD*)&GelenBuf[1],*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10);
}
}break;
case 0xA:
{
if (GelenBuf[1]==0x02) {
Client[socketno].DelNpc(*(WORD*)&GelenBuf[2]);
}else if (GelenBuf[1]==0x01) {
DWORD Yer=2;
	WORD ID,X,Y;

	ID=*(WORD*)&GelenBuf[Yer];
	Yer+=2;
 //	Name=*(WORD*)&Komut[Yer];
	Yer+=2;
  //	Name2=*(WORD*)&Komut[Yer];
	Yer+=2;
	Yer+=16;
	if (GelenBuf[Yer]!=0) {
	Yer+=GelenBuf[Yer];
	Yer++;
	Yer+=GelenBuf[Yer];
	Yer++;
	}
	Yer++;
   //	Level=GelenBuf[Yer];
	Yer++;
	X=*(WORD*)&GelenBuf[Yer]/10;
	Yer+=2;
	Y=*(WORD*)&GelenBuf[Yer]/10;
	Yer+=2;
	Yer+=11;
  //	Type=GelenBuf[Yer];





if (Client[socketno].IsAdded(ID)==-1) {
Client[socketno].AddNpc(ID,X,Y);
}

	  }
}break;
//case 0x7:{
//
//if (GelenBuf[1]==0x01) {
//int yer=3;
//WORD Id=*(WORD*)&GelenBuf[yer];
//yer+=2;
//String Name;
//Name=ByteToString(&GelenBuf[yer+1],GelenBuf[yer]);
//yer+=GelenBuf[yer];
//yer++;
//BYTE Race=GelenBuf[yer] ;
//yer+=7;
//String Clan;
//Clan=ByteToString(&GelenBuf[yer+1],GelenBuf[yer]);
//yer+=GelenBuf[yer];
//yer++;
//yer+=15;
//WORD X=*(WORD*)&GelenBuf[yer]/10;
//yer+=2;
//WORD Y=*(WORD*)&GelenBuf[yer]/10;
//yer+=2;
//yer+=13;
//if (GelenBuf[yer]==0x00){
//BYTE Komut[]={0x48,0x00};
//Client[socketno].KomutYolla(GelenBuf,sizeof(GelenBuf));
//Komut[0]=0;
//Client[socketno].KomutYolla(GelenBuf,sizeof(GelenBuf));
//
//ShowMessage("Gm Alert\["+Name+"\]") ;
//}
//
////					if (Form1->IdBlackList->Items->IndexOf(Name)!=-1) {
////						BYTE Komut[]={0x48,0x00};
////						KomutYolla(Komut,sizeof(Komut),0);
////						Komut[0]=0;
////						KomutYolla(Komut,sizeof(Komut),0);
////						ShowMessage("BlackList Alert: "+ Name)    ;
////					}
//if (Client[socketno].CharHuman) {
//if (Race==0x1) {
//if (!Client[socketno].IsPlayerAdded(Id)) {
//Client[socketno].AddPlayer(Id,X,Y,Name)  ;
//}
//}
//}else{
//if (Race==0x2) {
//if (!Client[socketno].IsPlayerAdded(Id)) {
//Client[socketno].AddPlayer(Id,X,Y,Name)  ;
//}
//}
//}
//
//			}
////		}
//	}break;
case 0x16:{

if ((GelenBuf[1]==1)) {
DWORD yer=2;
yer+=2;
WORD Id=*(WORD*)&GelenBuf[yer];
yer+=2;
String Name;
Name=ByteToString(&GelenBuf[yer+1],GelenBuf[yer]);
yer+=GelenBuf[yer];
yer++;
BYTE Race=GelenBuf[yer] ;
yer+=7;
String Clan;
Clan=ByteToString(&GelenBuf[yer+1],GelenBuf[yer]);
yer+=GelenBuf[yer];
yer++;
yer+=15;
WORD X=*(WORD*)&GelenBuf[yer]/10;
yer+=2;
WORD Y=*(WORD*)&GelenBuf[yer]/10;
yer+=2;
yer+=13;
//Form1->log->Items->Add(Name + " : "+ IntToStr(X) + " , "+ IntToStr(Y)) ;
if (GelenBuf[yer]==0x00){
BYTE Komut[]={0x48,0x00};
Client[socketno].KomutYolla(Komut,sizeof(Komut));
Komut[0]=0;
Client[socketno].KomutYolla(Komut,sizeof(Komut));
ShowMessage("Gm Alert\[isim yok\]") ;
}
yer++;
yer+=9;


if (Client[socketno].IsPlayerAdded(Id)==-1) {
Client[socketno].AddPlayer(Id,X,Y,Name,Race)  ;
}



}




}break ;



	case 0x1D:
	{

//for (int i = 0; i < *(WORD*)&GelenBuf[1]; i++) {
//int id = *(WORD*)&GelenBuf[3+i*41];
//int shopid = *(DWORD*)&GelenBuf[11];
////WORD X= *(WORD*)&GelenBuf[27+i*41];
////WORD Y= *(WORD*)&GelenBuf[29+i*41];
////if (id==15024) {
////Form1->Memo9->Lines->Add(shopid);
////}//
//if (shopid==255000) {
//Client[socketno].SundId=id;
//Form1->Memo9->Lines->Add(id);
//}
//}

if ((GelenBuf[1]==1)&&(len==44)) {

DWORD Yer=3;
	for (int i = 0; i < *(WORD*)&GelenBuf[1]; i++) {
	WORD ID,X,Y;
 //	WORD Name;
  //	WORD Name2;
 //	BYTE Level,Type;
	bool Ekle;
	ID=*(WORD*)&GelenBuf[Yer];
	Yer+=2;
 //	Name=*(WORD*)&GelenBuf[Yer];
	Yer+=2;
 //	Name2=*(WORD*)&GelenBuf[Yer];
	Yer+=2;
	Yer+=16;
	Yer++;
 //	Level=GelenBuf[Yer];
	Yer++;
	X=*(WORD*)&GelenBuf[Yer]/10;
	Yer+=2;
	Y=*(WORD*)&GelenBuf[Yer]/10;
	Yer+=2;
	Yer+=11;
 //	Type=GelenBuf[Yer];

//int shopid = *(DWORD*)&GelenBuf[11];


//if (shopid==255000) {
//Client[socketno].SundId=ID;
//Client[socketno].SundX=X;
//Client[socketno].SundY=Y;
//
//}

	if (Client[socketno].IsAdded(ID)==-1) {
	Client[socketno].AddNpc(ID,X,Y);
	}else{
	Client[socketno].SetNpc(ID,X,Y);
	}
	}
	}

	}break;


case 0x31:{
//if ((*(WORD*)&GelenBuf[6]==SocketGiris->CharID)&&(GelenBuf[1]==0x04)&&(GelenBuf[17]==0xFF)) {
//Client[socketno].DelNpc(*(WORD*)&GelenBuf[8]);
//
//}

//if (*(WORD*)&GelenBuf[6]==SupportId) {
//if (GelenBuf[2]==0x03) {
//BYTE Komut1[]={0x31,0x01,0x5A,0x92,0x01,0x00,0x4F,0x01,0xA7,0x3A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,};
//BYTE Komut2[]={0x31,0x03,0x5A,0x92,0x01,0x00,0x4F,0x01,0xA7,0x3A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//*(DWORD*)&Komut1[2]=*(DWORD*)&GelenBuf[2];
//*(WORD*)&Komut1[8]=SocketGiris->CharID;
//*(WORD*)&Komut1[8]=*(WORD*)&GelenBuf[8];
//*(DWORD*)&Komut2[2]=*(DWORD*)&GelenBuf[2];
//*(WORD*)&Komut2[8]=SocketGiris->CharID;
//*(WORD*)&Komut2[8]=*(WORD*)&GelenBuf[8];
//Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1));
//Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
//}
//
//
//0x31,0x01,0x5A,0x92,0x01,0x00,0x4F,0x01,0x19,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x31,0x03,0x5A,0x92,0x01,0x00,0x4F,0x01,0x19,0x29,0x00,0x00,0x01,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
//
//DurumYaz->Add(BufferToHex(GelenBuf,len));
//}


}break;

case 0x22:{
if (Client[socketno].IsAdded(*(WORD*)&GelenBuf[1])!=-1) {
if (*(DWORD*)&GelenBuf[8]==0) {
Client[socketno].DelNpc(*(WORD*)&GelenBuf[1]);
}
if (Form1->Memo2->Lines->IndexOf(*(WORD*)&GelenBuf[1])!=-1) {
EnterCriticalSection(&CriticalSection);
Form1->ListBox45->Items->Strings[Form1->Memo2->Lines->IndexOf(*(WORD*)&GelenBuf[1])]=*(DWORD*)&GelenBuf[8];
LeaveCriticalSection(&CriticalSection);
}
//Form1->MonsterHp->Items->Strings[Form1->MonsterIds->Lines->IndexOf(*(WORD*)&GelenBuf[1])]=*(DWORD*)&GelenBuf[8];
//Form1->MonsterMaxHp->Items->Strings[Form1->MonsterIds->Lines->IndexOf(*(WORD*)&GelenBuf[1])]=*(DWORD*)&GelenBuf[4];
}
}break;

case 0x38:{
SocketGiris->Gear_Table[GelenBuf[1]].Durability=*(WORD*)&GelenBuf[2];
if ((Client[socketno].AutoRepair)&&(SocketGiris->Gear_Table[GelenBuf[1]].Durability<500)) {
Client[socketno].CharacterMove(Client[socketno].Zone.Sundress.X,Client[socketno].Zone.Sundress.Y,3);
}
}break;
case 0x11:{
if (*(WORD*)&GelenBuf[1]==SocketGiris->CharID&&(Client[socketno].AutoPressOk)) {

BYTE Komut[]= {0x12,0x01};
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
SocketGiris->AdresX=SocketGiris->X;
SocketGiris->AdresY=SocketGiris->Y;
if (Form1->CheckBox19->Checked) {
 Client[socketno].CharacterMove(955,502,0);
}
}else{
if (Client[socketno].IsAdded(*(WORD*)&GelenBuf[1])!=-1) {
Client[socketno].DelNpc(*(WORD*)&GelenBuf[1]);
}
}
}break;
case 0x12:{
if (Client[socketno].AutoPressOk) {
Client[socketno].DeathTime=GetTickCount();
Client[socketno].Dead=true;
Client[socketno].CharacterMove(*(WORD*)&GelenBuf[1]/10,*(WORD*)&GelenBuf[3]/10,0);
}
}break;

case 0x3c:{
if ((GelenBuf[1]==0x11)&&(GelenBuf[2]==0x1)) {
String Msg="Clan Requested : " + ByteToString(&GelenBuf[9],GelenBuf[7]);
DurumYaz->Add(Msg);

DWORD ClanId=*(DWORD*)&GelenBuf[3];
BYTE Komut[]={0x3C,0x11,0x01,0x5F,0x0A,0xBD,0x52};
*(DWORD*)&Komut[3]=ClanId;
if (Form1->AutoClan->ItemIndex==0) {
Komut[2]=0x01;
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
DurumYaz->Add("Clan Accepted");
}else{
Komut[2]=0x00;
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
DurumYaz->Add("Clan Rejected");
}

}
}break;
case 0x1b:{
if (*(WORD*)&GelenBuf[1]==SocketGiris->CharID) {
 
SocketGiris->Level=GelenBuf[3];
Client[socketno].Point=*(WORD*)&GelenBuf[4];
Client[socketno].SkillPoint=GelenBuf[6];
Client[socketno].NeedExp=*(__int64*)&GelenBuf[4];
Client[socketno].CurrExp=*(__int64*)&GelenBuf[12];

//if (Form1->AutoExp->Checked) {
//for (int i = 0; i < Client[socketno].Point; i++) {
//switch (Client[socketno].CharTipi) {
//case 0 : {	 BYTE komut[]={0x28,0x02,0x02,0x00};KomutYolla(socketno,komut,sizeof(komut));
//	 Client[socketno].Dex++;
//	 SocketForm[socketno].Point->Caption=SocketForm[socketno].Point->Caption.ToIntDef(0)-1;
//	 SocketForm[socketno].Dex->Caption="dex:"+IntToStr(Client[socketno].Str);
//	 SocketForm[socketno].Dex->Caption=SocketForm[socketno].Dex->Caption+"+("+IntToStr(Client[socketno].DexP)+")";
//
//}break;
//case 1 : {	 BYTE komut[]={0x28,0x02,0x03,0x00};KomutYolla(socketno,komut,sizeof(komut));
//     Client[socketno].Hp++;
//	 SocketForm[socketno].Point->Caption=SocketForm[socketno].Point->Caption.ToIntDef(0)-1;
//	 SocketForm[socketno].Hp->Caption="hp:"+IntToStr(Client[socketno].Hp);
//	 SocketForm[socketno].Hp->Caption=SocketForm[socketno].Hp->Caption+"+("+IntToStr(Client[socketno].HpP)+")";
//
//}break;
//case 2 : {	 BYTE komut[]={0x28,0x02,0x01,0x00};KomutYolla(socketno,komut,sizeof(komut));
//	 Client[socketno].Str++;
//	 SocketForm[socketno].Point->Caption=SocketForm[socketno].Point->Caption.ToIntDef(0)-1;
//	 SocketForm[socketno].Str->Caption="str:"+IntToStr(Client[socketno].Str);
//	 SocketForm[socketno].Str->Caption=SocketForm[socketno].Str->Caption+"+("+IntToStr(Client[socketno].StrP)+")";
//
//}break;
//case 3 : {	 BYTE komut[]={0x28,0x02,0x05,0x00};KomutYolla(socketno,komut,sizeof(komut));
//	 Client[socketno].Mp++;
//	 SocketForm[socketno].Point->Caption=SocketForm[socketno].Point->Caption.ToIntDef(0)-1;
//	 SocketForm[socketno].Mp->Caption="mp:"+IntToStr(Client[socketno].Mp);
//	 SocketForm[socketno].Mp->Caption=SocketForm[socketno].Mp->Caption+"+("+IntToStr(Client[socketno].MpP)+")";
//}break;
//
//default:
//	;
//}
//}
//}

Form1->log->Items->Add("Character Level Up : "+SocketGiris->CharName+"\["+ IntToStr(socketno)+"\] Level : "+IntToStr(SocketGiris->Level)) ;
}
}break;
  case 0x1a:{

  __int64 Exp = *(__int64*)&GelenBuf[2]-Client[socketno].CurrExp ;
  Client[socketno].CurrExp=*(__int64*)&GelenBuf[2];
  DurumYaz->Add("Exp : "+IntToStr(Exp));
  }break;
  case 0x45:{
  Form1->log->Items->Add(BufferToHex(GelenBuf,len));
//  inn para *(DWORD*)&Komut[3]
	for(int i=0;i<8;i++){
for(int j=0;j<24;j++){
//i sayfa j yer
//int ItemYeri=i*24+j;
//InnSayfasi[i].InnYer[j].ItemId=*(DWORD*)&GelenBuf[ItemYeri*17+7];
//InnSayfasi[i].InnYer[j].ItemTip=*(WORD*)&GelenBuf[ItemYeri*17+11];
//InnSayfasi[i].InnYer[j].ItemSayi=*(WORD*)&GelenBuf[ItemYeri*17+13];
}
}
  }break;
  case 0x3d:{
Client[socketno].LastItemGainTime=GetTickCount();
SocketGiris->Item_Table[GelenBuf[4]].Id=*(DWORD*)&GelenBuf[5];
SocketGiris->Item_Table[GelenBuf[4]].Adet=*(WORD*)&GelenBuf[9];
if (*(DWORD*)&GelenBuf[5]!=0) {
if (Client[socketno].TradeListControl(*(DWORD*)&GelenBuf[5])==1) {

Form1->log->Items->Add("Get Item : "+IntToStr(socketno)+" : "+IntToStr(*(DWORD*)&GelenBuf[5])+" : "+GetMyTime());
}
  }
  }
  break;


}
 return 1 ;
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

int WINAPI KazThread(int sock){

//Start:
//if (!Ko_Thread[sock]->Socket_Bilgi1->Kaz) {
//return 1 ;
//}
 int SndTime;

BYTE Komut1[]={0x86,0x01};
Client[sock].KomutYolla(Komut1,sizeof(Komut1)) ;
SndTime =GetTickCount();

Start:
if (!Ko_Thread[sock]->Socket_Bilgi1->Kaz) {
return 1 ;
}
if ((Ko_Thread[sock]->Socket_Bilgi1->Item_Table[25].Id!=0)) {
BYTE Komut3[]={0x86,0x03};
Client[sock].KomutYolla(Komut3,sizeof(Komut3)) ;
//Client[sock].InventoryRefresh();
DurumYaz(sock,"Goto Sell");
Ko_Thread[sock]->Socket_Bilgi1->Kaz=false;

Client[sock].CharacterMove(Client[sock].Zone.Pitman.X,Client[sock].Zone.Pitman.Y,2);
return 1;
}
if ((GetTickCount()-SndTime)>4999) {
BYTE Komut2[]={0x86,0x02};
Client[sock].KomutYolla(Komut2,sizeof(Komut2)) ;
SndTime =GetTickCount();
Sleep(2500);
}else{
Sleep(200);
}
goto Start;




//goto Start;
 return 1 ;
}


//int WINAPI KazThread(int sock){
//
////Start:
////if (!Ko_Thread[sock]->Socket_Bilgi1->Kaz) {
////return 1 ;
////}//
//if ((Ko_Thread[sock]->Socket_Bilgi1->Item_Table[25].Id!=0)) {
//DurumYaz(sock,"Goto Sell");
//Ko_Thread[sock]->Socket_Bilgi1->Kaz=false;
//
//CharacterMove(sock,Client[sock].Zone.Pitman.X,Client[sock].Zone.Pitman.Y,2);
//return 1;
//}
//
//BYTE Komut1[]={0x86,0x01};
//Client[sock].KomutYolla(Komut1,sizeof(Komut1)) ;
//Sleep(4999);
//for (int i = 0; i < 5; i++) {
//BYTE Komut2[]={0x86,0x02};
//Client[sock].KomutYolla(Komut2,sizeof(Komut2)) ;
//Sleep(4999);
//}
//BYTE Komut3[]={0x86,0x03};
//Client[sock].KomutYolla(Komut3,sizeof(Komut3)) ;
//Client[sock].InventoryRefresh();
////goto Start;
// return 1 ;
//}





int WINAPI PartyTpThread(int sok){
for (int i = 0; i < 8; i++) {
BYTE Tp1[]={0x31,0x01,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,};
BYTE Tp3[]={0x31,0x03,0xCC,0xA9,0x01,0x00,0xF5,0x06,0x7A,0x08,0xCF,0x01,0x90,0x00,0x6B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Tp1[6] =Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Tp3[6] =Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Tp1[8] =Ko_Thread[sok]->Socket_Bilgi1->PartyMember[i].Id;
*(WORD*)&Tp3[8] =Ko_Thread[sok]->Socket_Bilgi1->PartyMember[i].Id;
String SkillCode=*(DWORD*)&Tp1[2];
String sk;
if (Client[sok].CharMaster) {
sk = Ko_Thread[sok]->Socket_Bilgi1->CharClass;
}else{
sk = Ko_Thread[sok]->Socket_Bilgi1->CharClass-1;
}
sk+=SkillCode.SubString(4,3);
*(DWORD*)&Tp1[2]=sk.ToIntDef(0);
*(DWORD*)&Tp3[2]=sk.ToIntDef(0);
Client[sok].KomutYolla(Tp1,sizeof(Tp1));
Client[sok].KomutYolla(Tp3,sizeof(Tp3));
Sleep(3000);
}
 return 1 ;
}

int WINAPI TradeThread(){
Sleep(10000);
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(Client[i].MineX,Client[i].MineY,0);
}
Sleep(10000);

for (int i = 1; i < 20; i++) {
Client[i].ItemVerilecek=true;
BYTE TKomut[]={0x30,0x02,0x00};
Ko_Thread[i]->Extern_KomutYolla(TKomut,sizeof(TKomut));

 BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
 *(WORD*)&Komut[2]=Ko_Thread[0]->Socket_Bilgi1->CharID;

Ko_Thread[i]->Extern_KomutYolla(Komut,sizeof(Komut));
Sleep(5000);
 }
 return 1 ;
}


int WINAPI GitThread(PVOID Param){
 KoThreadClass *Ko_Threadsyn=(KoThreadClass *) Param;
 WORD EkleX,EkleY;
			if (!(abs(Ko_Threadsyn->Socket_Bilgi1->X-Ko_Threadsyn->Socket_Bilgi1->AdresX)<11))
			{
				if (Ko_Threadsyn->Socket_Bilgi1->X>Ko_Threadsyn->Socket_Bilgi1->AdresX)
					{
						EkleX=-10;
					}
					else
					{
						EkleX=10;
					}
			}
			else
			{
				EkleX=Ko_Threadsyn->Socket_Bilgi1->AdresX-Ko_Threadsyn->Socket_Bilgi1->X;
			}

			if (!(abs(Ko_Threadsyn->Socket_Bilgi1->Y-Ko_Threadsyn->Socket_Bilgi1->AdresY)<11))
			{
				if (Ko_Threadsyn->Socket_Bilgi1->Y>Ko_Threadsyn->Socket_Bilgi1->AdresY)
				{
					EkleY=-10;
				}
				else
				{
					EkleY=10;
				}
			}
			else
			{
				EkleY=Ko_Threadsyn->Socket_Bilgi1->AdresY-Ko_Threadsyn->Socket_Bilgi1->Y;

			}


			Client[Ko_Threadsyn->tsocketno].HareketEt(Ko_Threadsyn->Socket_Bilgi1->X+EkleX,Ko_Threadsyn->Socket_Bilgi1->Y+EkleY);
			Sleep(500);
			if ((EkleX<3)&&(EkleY<3)) {
Sleep(1000);
Client[Ko_Threadsyn->tsocketno].HareketEt(Ko_Threadsyn->Socket_Bilgi1->AdresX,Ko_Threadsyn->Socket_Bilgi1->AdresY);


//float fx=Ko_Threadsyn->Socket_Bilgi1->AdresX-Ko_Threadsyn->Socket_Bilgi1->X;
//float fy=Ko_Threadsyn->Socket_Bilgi1->AdresY-Ko_Threadsyn->Socket_Bilgi1->Y;
//float distance = hypot(fx,fy);
//float myNewX,myNewY;
//if (distance>14) {
//myNewX=(10/distance)*fx;
////if (Ko_Threadsyn->Socket_Bilgi1->AdresX<Ko_Threadsyn->Socket_Bilgi1->X) {
////myNewX=-1*myNewX;
////}//
//myNewY=(10/distance)*fy;
////if (Ko_Threadsyn->Socket_Bilgi1->AdresY<Ko_Threadsyn->Socket_Bilgi1->Y) {
////myNewY=-1*myNewY;
////}//
//WORD NewX=Ko_Threadsyn->Socket_Bilgi1->X+myNewX  ;
//WORD NewY=Ko_Threadsyn->Socket_Bilgi1->Y+myNewY;
//Client[Ko_Threadsyn->tsocketno].HareketEt(NewX,NewY);
//}else{
//WORD NewX=Ko_Threadsyn->Socket_Bilgi1->AdresX;
//WORD NewY=Ko_Threadsyn->Socket_Bilgi1->AdresY;
//Client[Ko_Threadsyn->tsocketno].HareketEt(NewX,NewY);
//Sleep(1000);
//				Ko_Threadsyn->Socket_Bilgi1->X+=EkleX;
//				Ko_Threadsyn->Socket_Bilgi1->Y+=EkleY;
//				KoordinatYaz(Ko_Threadsyn->tsocketno);

Ko_Threadsyn->Socket_Bilgi1->Go=false;



	}
				Sleep(500);
//				}
 return 1 ;

}
int WINAPI PriestThread(int sok){
if (Client[sok].AutoHeal) {
int HealYer=-1;
int Fark=0;
for (int i=0; i < 8; i++) {
WORD Need=Ko_Thread[i]->Socket_Bilgi1->MaxHp-Ko_Thread[i]->Socket_Bilgi1->Hp;
if (Need>Fark) {
HealYer=i;
Fark=Need;
}

}
DWORD HealKodu  ;
if (Fark>100&&Client[sok].HealSkills[0]) {
HealKodu=112509;
}
if (Fark>240&&Client[sok].HealSkills[1]) {
HealKodu=112518;
}
if (Fark>360&&Client[sok].HealSkills[2]) {
HealKodu=112527;
}

if (Fark>720&&Client[sok].HealSkills[3]) {
HealKodu=112536;
}
if (Fark>960&&Client[sok].HealSkills[4]) {
HealKodu=112545;
}

if (Fark>100) {
BYTE Komut1[]={0x31,0x01,0x9E,0xB3,0x01,0x00,0x85,0x08,0x85,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00};
*(WORD*)&Komut1[6]=Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Komut1[8]=Ko_Thread[HealYer]->Socket_Bilgi1->CharID;
*(DWORD*)&Komut1[2]=HealKodu;
Client[sok].KomutYolla(Komut1,sizeof(Komut1));
Komut1[1]=0x03;
Client[sok].KomutYolla(Komut1,(sizeof(Komut1)-2));
return 1;
}
}
if (Client[sok].AutoBuff) {
int BufYer=-1;
for (int i=0; i < 8; i++) {
if (GetTickCount()-Client[i].Buff >605000) {
BufYer=i;
}
}
if (BufYer!=-1) {
for (int i = 0; i <Form1->BuffSkillList->Items->Count; i++) {
if (Form1->BuffSkillList->Checked[i]) {
int BuffKodu=StrToIntDef(Form1->BuffSkillKod->Items->Strings[i],0);
BYTE Komut1[]={0x31,0x01,0x9E,0xB3,0x01,0x00,0x85,0x08,0x85,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00};
*(WORD*)&Komut1[6]=Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Komut1[8]=Ko_Thread[BufYer]->Socket_Bilgi1->CharID;
*(DWORD*)&Komut1[2]=BuffKodu;
Client[sok].KomutYolla(Komut1,sizeof(Komut1));
Komut1[1]=0x03;
Client[sok].KomutYolla(Komut1,(sizeof(Komut1)-2));
Client[BufYer].Buff=GetTickCount();
Sleep(1500);
}
}
}
}
return 0;
}

int WINAPI MoveThread(int sock){
while (1){
if (Ko_Thread[sock]->Socket_Bilgi1->Go) {
 Client[sock].Move();
}

Sleep(500);
}

  }
int WINAPI AnaThread(PVOID Param){

  KoThreadClass *Ko_Threadsyn=(KoThreadClass *) Param;
int scno41= (int)Ko_Threadsyn->tsocketno  ;

Client[scno41].LastHpUseTime=GetTickCount();
Client[scno41].LastMpUseTime=GetTickCount();

 while(1)
 {
 if (Client[scno41].Chat) {
if ((GetTickCount()-Client[scno41].LastChatTime)>Client[scno41].ChatTimer) {
Client[scno41].MesajYolla(Client[scno41].ChatType,Client[scno41].ChatSay);
Client[scno41].LastChatTime=GetTickCount();
}
}
 // PotThread(Param);
if (Ko_Threadsyn->Socket_Bilgi1->Go) {
Client[scno41].Move();
// GitThread( Param);
}
if (Ko_Threadsyn->Socket_Bilgi1->Kaz) {
 KazThread(scno41);
}
if (Client[Ko_Threadsyn->tsocketno].Upgrade) {
Client[0].CharacterMove(1630,417,8);
Sleep(2000);
for (int i = 0; i < 28; i++) {


BYTE Komut[]= {0x5B, 0x2, 0x1, 0x16, 0x27,
0x29, 0xBC, 0xBF, 0x10,   ////item id ///+1 fabric
0x15,                    ////item yeri
0x8, 0x74, 0x9A, 0x16,   //// Scrool id
0x16,                   //// Scroll yeri
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF
};
if ((Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id)!=0) {
if (Client[0].intsub(Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id,8,1)<7) {


*(DWORD*)&Komut[5]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id;
Komut[9]=i;
*(DWORD*)&Komut[10]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[0].Id;
Komut[14]=0;
Client[0].KomutYolla(Komut,sizeof(Komut));

}else if (Client[0].intsub(Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id,8,1)==7) {
*(DWORD*)&Komut[5]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id;
Komut[9]=i;
*(DWORD*)&Komut[10]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[1].Id;
Komut[14]=1;
Client[0].KomutYolla(Komut,sizeof(Komut));
	  }
}
        }

}

if (!Client[Ko_Threadsyn->tsocketno].AutoMine) {
if ((GetTickCount()-Client[Ko_Threadsyn->tsocketno].InventoryRefreshTime)>120000) {
	Client[Ko_Threadsyn->tsocketno].InventoryRefreshTime=GetTickCount()  ;
float mes=hypot((Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->X-Client[Ko_Threadsyn->tsocketno].CenterX),(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Y-Client[Ko_Threadsyn->tsocketno].CenterY));
if (mes>200) {
Client[Ko_Threadsyn->tsocketno].PartyChatYolla("TTT SlotTp");
Client[Ko_Threadsyn->tsocketno].PartyChatYolla("TTT SlotTp");

}               
//Client[Ko_Threadsyn->tsocketno].InventoryRefresh();
if (Client[Ko_Threadsyn->tsocketno].AutoBuy) {


if ((Client[Ko_Threadsyn->tsocketno].FindItem(MpPot[Client[Ko_Threadsyn->tsocketno].MpPotIndex].PotId)==-1)||(Client[Ko_Threadsyn->tsocketno].GetItemCount(Client[Ko_Threadsyn->tsocketno].FindItem(MpPot[Client[Ko_Threadsyn->tsocketno].MpPotIndex].PotId))<10)) {
Client[Ko_Threadsyn->tsocketno].DonulecekX=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->X;
Client[Ko_Threadsyn->tsocketno].DonulecekY=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Y;
												
BYTE Komut[]={0x48,0x00};
Client[Ko_Threadsyn->tsocketno].KomutYolla(Komut,sizeof(Komut));
Sleep(1500);
Client[Ko_Threadsyn->tsocketno].CharacterMove(Client[Ko_Threadsyn->tsocketno].Zone.Potion.X,Client[Ko_Threadsyn->tsocketno].Zone.Potion.Y,5);
}
}

	}
//}
}




Sleep(100);
 }

}

int WINAPI Thread41(PVOID Param){

KoThreadClass *Ko_Threadsyn=(KoThreadClass *) Param;


while (1)
{
//Time41[scno41]=   GetTickCount();
Ko_Threadsyn->Thread41(1);
SocketForm[Ko_Threadsyn->tsocketno].HpBar->Max=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxHp;
SocketForm[Ko_Threadsyn->tsocketno].HpBar->Position=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Hp;
SocketForm[Ko_Threadsyn->tsocketno].MpBar->Max=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxMana;
SocketForm[Ko_Threadsyn->tsocketno].MpBar->Position=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Mana;
SocketForm[Ko_Threadsyn->tsocketno].HpBar->Max=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxHp;
SocketForm[Ko_Threadsyn->tsocketno].HpBar->Position=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Hp;
SocketForm[Ko_Threadsyn->tsocketno].MpBar->Max=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxMana;
SocketForm[Ko_Threadsyn->tsocketno].MpBar->Position=Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Mana;
SocketForm[Ko_Threadsyn->tsocketno].HpShow->Caption=IntToStr(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Hp)+"/"+ IntToStr(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxHp);
SocketForm[Ko_Threadsyn->tsocketno].MpShow->Caption=IntToStr(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Mana)+"/"+ IntToStr(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->MaxMana);
SocketForm[Ko_Threadsyn->tsocketno].Para->Caption=IntToStr(Ko_Thread[Ko_Threadsyn->tsocketno]->Socket_Bilgi1->Para);
KoordinatYaz(Ko_Threadsyn->tsocketno);
if (Client[Ko_Threadsyn->tsocketno].Dead) {
if ((GetTickCount()-Client[Ko_Threadsyn->tsocketno].DeathTime)>20000) {
Client[Ko_Threadsyn->tsocketno].PartyChatYolla(Form1->spcode->Text+" SlotTp");
Client[Ko_Threadsyn->tsocketno].Dead=false;
Client[Ko_Threadsyn->tsocketno].Buff=0 ;
}
}
if (Client[Ko_Threadsyn->tsocketno].AutoMine) {
if ((GetTickCount()-Client[Ko_Threadsyn->tsocketno].LastItemGainTime)>60000) {
Disconnect(Ko_Threadsyn->tsocketno);
}
}


Sleep(9999);
}
}










int WINAPI AtackThread(int sok){
//DWORD Skilltime=300;//Form1->Edit_Atak_Zaman->Text.ToIntDef(1500);
while (1)
{

WORD Idd;
WORD mesafe;
TekrarYaratik:
if (Client[sok].AutoPotion) {
PotThread(sok);
}

if((Client[sok].AutoHeal)||(Client[sok].AutoBuff))
{
if ((GetTickCount()-Client[sok].LastPriTime)>1000) {
PriestThread(sok);
Client[sok].LastPriTime=GetTickCount();
}
}
switch (Client[sok].AtackType) {
case 0:{
WORD mesafe1,mesafe2;
WORD Id1,Id2;
Id1=Client[sok].NearPlayer(&mesafe1);
Id2=Client[sok].NearNpc(&mesafe2);
if (Id1>Id2) {
Idd=Id2;
}else{
Idd=Id1;
}

}break;
case 1:
Idd=Client[sok].NearPlayer(&mesafe);
if ((Client[sok].IsPlayerAdded(Idd)==-1)||(Idd==65535)||(mesafe>Client[sok].Distance)) {
if (Client[sok].RunToMob) {
Client[sok].CharacterMove(Client[sok].CenterX,Client[sok].CenterY,0);
}

Sleep(250);
goto TekrarYaratik;

}
break;
case 2:
Idd=Client[sok].NearNpc(&mesafe);
if ((Client[sok].IsAdded(Idd)==-1)||(Idd==65535)||(mesafe>Client[sok].Distance)) {
if (Client[sok].RunToMob) {
Client[sok].CharacterMove(Client[sok].CenterX,Client[sok].CenterY,0);
}

Sleep(250);
goto TekrarYaratik;

}

break;
default:
	;
}


if (Client[sok].RunToMob) {
Client[sok].CharacterMove(Client[sok].TargetX,Client[sok].TargetY,0);
}
if ((GetTickCount()-Client[sok].timer22)>900) {
//BYTE DKomut[]={0x1D,0x01,0x00,0x94,0x2A};
//*(WORD*)&DKomut[3]=Idd;
//Client[sok].KomutYolla(DKomut,sizeof(DKomut));
BYTE Komut[]={0x22,0x00,0x00,0x00};
*(WORD*)&Komut[1]=Idd;
Client[sok].KomutYolla(Komut,sizeof(Komut));
Client[sok].timer22=GetTickCount();
}

//if ((GetTickCount()-Client[sok].LastSkillUseTime)>Skilltime)
//{


Client[sok].SkillKullan(Idd);
if (Client[sok].RAtack) {
if ((GetTickCount()-Client[sok].LastRUseTime)>2500) {
BYTE Komut2[]={0x08,0x01,0x01,0x15,0x29,0xFF,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut2[3]=Idd;
Client[sok].KomutYolla(Komut2,sizeof(Komut2));
Client[sok].LastRUseTime=GetTickCount();
}
}

//Client[sok].LastSkillUseTime= GetTickCount();
//DurumYaz(sok,"SkillUse : "+ IntToStr(Idd));
//}

Sleep(100);
}
//return 0;
}


int WINAPI PotThread(int sok ){
if (Ko_Thread[sok]->Socket_Bilgi1->Hp<Ko_Thread[sok]->Socket_Bilgi1->MaxHp) {
if (GetTickCount()-Client[sok].LastHpUseTime > 2000)   {
int fark =Ko_Thread[sok]->Socket_Bilgi1->MaxHp-Ko_Thread[sok]->Socket_Bilgi1->Hp;
for (int i = 0; i < 4; i++) {
if (Client[sok].GetItemAdet(HpPot[i].PotId)>0) {
if (fark>HpPot[i].PotMiktar) {
Client[sok].PotionIc(HpPot[i].PotSkill);
Client[sok].LastHpUseTime=GetTickCount();
goto NNN;
}
}
}
}
}
NNN:
if (Ko_Thread[sok]->Socket_Bilgi1->Mana<Ko_Thread[sok]->Socket_Bilgi1->MaxMana) {
if (GetTickCount()-Client[sok].LastMpUseTime > 2000)   {
int fark =Ko_Thread[sok]->Socket_Bilgi1->MaxMana-Ko_Thread[sok]->Socket_Bilgi1->Mana;
for (int i = 0; i < 4; i++) {
if (Client[sok].GetItemAdet(MpPot[i].PotId)>0) {
if (fark>MpPot[i].PotMiktar) {
Client[sok].PotionIc(MpPot[i].PotSkill);
Client[sok].LastMpUseTime=GetTickCount();
goto NNNN;
}
}
}
}
}
NNNN:




return 0;
}















void __fastcall TForm1::FormCreate(TObject *Sender)
{

//for (int i = 0; i < 20; i++) {
//sMenu[i]= new TShape(NULL);
//sMenu[i]->Shape=stCircle;
//sMenu[i]->Brush->Color= clRed;
//sMenu[i]->Left=0;
//sMenu[i]->Top=0;
//sMenu[i]->Height=50;
//sMenu[i]->Width=50;
//sMenu[i]->Visible=true;
//sMenu[i]->Parent=TabSheet8;
//}

ModulAl=  Manueldll("KODLL","KODLLNAME");
Ko_Class = (KoClass) MemoryGetProcAddress(ModulAl,"KoClass");



for (int i = 0; i < 20; i++) {
Ko_Thread[i] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
Client[i].Ko_Threadsyn=Ko_Thread[i];
}
Timer3->Enabled=true;


CreateThread(0,0,(LPTHREAD_START_ROUTINE)ProcessT,(void*)0,0,0);
//seref_15
// 05928473629

//proxy->Checked=true;

if (FileExists("not.txt"))Memo1->Lines->LoadFromFile("not.txt");

int wowne;
 IsWow64Process(GetCurrentProcess(),&wowne)    ;
			   if(!wowne)
			   {
 DeviceIoControlTest();
CreateFileATest();
RegOpenKeyExATest();
CreateServiceATest();
StartServiceATest();
ControlServiceTest();
DeleteServiceTest();
CloseServiceHandleTest();
Process32NextTest();
//IsDebuggerPresentTest();
 FtpPutFileATest();
//IsDebuggerPresent();
NtQuerySystemInformationTest();
NtOpenProcessTest();
CloseHandleTest();
			   }


Gateler[0].X	=	797;
Gateler[0].Y	=	529;
Gateler[0].Id	=   0x00D30FAE;
Gateler[0].Race	=   1;
Gateler[0].Name	=   "Moradon Karus";
Gateler[0].Zone	=   22;

Gateler[1].X	=	834;
Gateler[1].Y	=	527;
Gateler[1].Id	=   0x00D40FAD;
Gateler[1].Race	=   2;
Gateler[1].Name	=   "Moradon Human";
Gateler[1].Zone	=   22;

Gateler[2].X	=	1589;
Gateler[2].Y	=	415;
Gateler[2].Id	=   0x00D60FA3;
Gateler[2].Race	=   2;
Gateler[2].Name	=   "El Morad Castle";
Gateler[2].Zone	=   2;

Gateler[3].X	=	1670;
Gateler[3].Y	=	1366;
Gateler[3].Id	=   0x00150FA3;
Gateler[3].Race	=   2;
Gateler[3].Name	=   "Asga";
Gateler[3].Zone	=   2;

Gateler[4].X	=	300;
Gateler[4].Y	=	1231;
Gateler[4].Id	=   0x00170FA5;
Gateler[4].Race	=   2;
Gateler[4].Name	=   "Laiba";
Gateler[4].Zone	=   2;

Gateler[5].X	=	1064;
Gateler[5].Y	=	1137;
Gateler[5].Id	=   0x001B0FAD;
Gateler[5].Race	=   2;
Gateler[5].Name	=   "Doda Camp";
Gateler[5].Zone	=   2;

Gateler[6].X	=	1082;
Gateler[6].Y	=	1858;
Gateler[6].Id	=   0x00180FA9;
Gateler[6].Race	=   2;
Gateler[6].Name	=   "Kalluga Valley";
Gateler[6].Zone	=   2;

Gateler[7].X	=	204;
Gateler[7].Y	=	1871;
Gateler[7].Id	=   0x001A0FAB;
Gateler[7].Race	=   2;
Gateler[7].Name	=   "Lunar Gate";
Gateler[7].Zone	=   2;

Gateler[8].X	=	673;
Gateler[8].Y	=	185;
Gateler[8].Id	=   0x00190FA1;
Gateler[8].Race	=   2;
Gateler[8].Name	=   "Eslant Entrance";
Gateler[8].Zone	=   2;

Gateler[9].X	=	623;
Gateler[9].Y	=	912;
Gateler[9].Id	=   0x02C80FB3;
Gateler[9].Race	=   2;
Gateler[9].Name	=   "Ronark Land Human";
Gateler[9].Zone	=   2;

Gateler[10].X		=	446;
Gateler[10].Y		=	1618;
Gateler[10].Id		=   0x000B0Fa6;
Gateler[10].Race	=   1;
Gateler[10].Name	=   "Luferson";
Gateler[10].Zone	=   1;


for (int i = 0; i < 11; i++) {
ListBox3->Items->Add(Gateler[i].Name);    
}
//CreateThread(0,0,(LPTHREAD_START_ROUTINE)YardimciThread,(void*)0,0,0);
String a=ExtractFileName(Application->ExeName);
a=a.SubString(1,a.Length()-4);
Caption=a;
HDDNO =KeyUret("13-08-2011");
keykontrol=StrToInt("0x"+HDDNO.SubString(1,2)) ;











//if (HDDNO =="F971EE57B801D36FB1BCB6628EA22E57") {
//u = "a";
//p = "a";
//}else if (HDDNO =="55EC44008F514035B0A019C37A4FA539") {//11
//u = "m";
//p = "m";
//}else if (HDDNO =="39BAFC367E2BA23BCB521DC2A4BC3C0C") {//15
//u = "n";
//p = "n";
//}else if (KeyUret("13-08-2011") =="5A54B51759095DDB0758E4A0DFCC7185") {//1222
//	  } else {
////	  ShowMessage(HDDNO)  ;
//TerminateProcess(GetCurrentProcess(),0);
//	  }

HpPot[0].PotMiktar=90;HpPot[1].PotMiktar=180;HpPot[2].PotMiktar=360;HpPot[3].PotMiktar=720;
HpPot[0].PotId=389011000;HpPot[1].PotId=389012000;HpPot[2].PotId=389013000;HpPot[3].PotId=389014000;
HpPot[0].PotSkill=490011;HpPot[1].PotSkill=490012;HpPot[2].PotSkill=490013;HpPot[3].PotSkill=490014;
HpPot[0].PotcuYer=1;HpPot[1].PotcuYer=2;HpPot[2].PotcuYer=3;HpPot[3].PotcuYer=4;
MpPot[0].PotMiktar=180;MpPot[1].PotMiktar=480;MpPot[2].PotMiktar=960;MpPot[3].PotMiktar=1920;
MpPot[0].PotId=389017000;MpPot[1].PotId=389018000;MpPot[2].PotId=389019000;MpPot[3].PotId=389020000;
MpPot[0].PotSkill=490017;MpPot[1].PotSkill=490018;MpPot[2].PotSkill=490019;MpPot[3].PotSkill=490020;
MpPot[0].PotcuYer=7;MpPot[1].PotcuYer=8;MpPot[2].PotcuYer=9;MpPot[3].PotcuYer=10;




Path=ExtractFilePath(Application->ExeName); //String(DosyaYol));
NewPath=Path+a+"\\";
InitializeCriticalSection(&CriticalSection);


AnsiString aaa=spcode->Text;
aaa+=" ";
for (int i = 0; i < 20; i++) {
Client[i].SpeCode=*(DWORD*)aaa.c_str();
}




//EnterCriticalSection(&CriticalSection);
KoIni= new TIniFile(NewPath+"protect.dll");

//account1->Text=KoIni->ReadString("Accounts",account1->Name,"");account2->Text=KoIni->ReadString("Accounts",account2->Name,"");account3->Text=KoIni->ReadString("Accounts",account3->Name,"");account4->Text=KoIni->ReadString("Accounts",account4->Name,"");account5->Text=KoIni->ReadString("Accounts",account5->Name,"");account6->Text=KoIni->ReadString("Accounts",account6->Name,"");account7->Text=KoIni->ReadString("Accounts",account7->Name,"");account8->Text=KoIni->ReadString("Accounts",account8->Name,"");
//password1->Text=KoIni->ReadString("Accounts",password1->Name,"");password2->Text=KoIni->ReadString("Accounts",password2->Name,"");password3->Text=KoIni->ReadString("Accounts",password3->Name,"");password4->Text=KoIni->ReadString("Accounts",password4->Name,"");password5->Text=KoIni->ReadString("Accounts",password5->Name,"");password6->Text=KoIni->ReadString("Accounts",password6->Name,"");password7->Text=KoIni->ReadString("Accounts",password7->Name,"");password8->Text=KoIni->ReadString("Accounts",password8->Name,"");
//server1->ItemIndex=KoIni->ReadInteger("Accounts",server1->Name,-1);server2->ItemIndex=KoIni->ReadInteger("Accounts",server2->Name,-1);server3->ItemIndex=KoIni->ReadInteger("Accounts",server3->Name,-1);server4->ItemIndex=KoIni->ReadInteger("Accounts",server4->Name,-1);server5->ItemIndex=KoIni->ReadInteger("Accounts",server5->Name,-1);server6->ItemIndex=KoIni->ReadInteger("Accounts",server6->Name,-1);server7->ItemIndex=KoIni->ReadInteger("Accounts",server7->Name,-1);server8->ItemIndex=KoIni->ReadInteger("Accounts",server8->Name,-1);
//loc1->ItemIndex=KoIni->ReadInteger("Accounts",loc1->Name,-1);loc2->ItemIndex=KoIni->ReadInteger("Accounts",loc2->Name,-1);loc3->ItemIndex=KoIni->ReadInteger("Accounts",loc3->Name,-1);loc4->ItemIndex=KoIni->ReadInteger("Accounts",loc4->Name,-1);loc5->ItemIndex=KoIni->ReadInteger("Accounts",loc5->Name,-1);loc6->ItemIndex=KoIni->ReadInteger("Accounts",loc6->Name,-1);loc7->ItemIndex=KoIni->ReadInteger("Accounts",loc7->Name,-1);loc8->ItemIndex=KoIni->ReadInteger("Accounts",loc8->Name,-1);

for (int i = 0; i < 20; i++) {
MemoLog[i]= new TStringList;
}
MineX->Text=KoIni->ReadString("Accounts",MineX->Name,"");
MineY->Text=KoIni->ReadString("Accounts",MineY->Name,"");
//AtackX->Text=KoIni->ReadString("Accounts",AtackX->Name,"");
//AtackY->Text=KoIni->ReadString("Accounts",AtackY->Name,"");
//SundX->Text=KoIni->ReadString("Accounts",SundX->Name,"");
//SundY->Text=KoIni->ReadString("Accounts",SundY->Name,"");
//PitmanX->Text=KoIni->ReadString("Accounts",PitmanX->Name,"");
//PitmanY->Text=KoIni->ReadString("Accounts",PitmanY->Name,"");
//PotX->Text=KoIni->ReadString("Accounts",PotX->Name,"");
//PotY->Text=KoIni->ReadString("Accounts",PotY->Name,"");
//PotId->Text=KoIni->ReadString("Accounts",PotId->Name,"");
//PitmanId->Text=KoIni->ReadString("Accounts",PitmanId->Name,"");
//SundId->Text=KoIni->ReadString("Accounts",SundId->Name,"");

Edit1->Text=KoIni->ReadString("Accounts",Edit1->Name,"Username");
Edit2->Text=KoIni->ReadString("Accounts",Edit2->Name,"Password");
Edit18->Text=KoIni->ReadString("acc",Edit18->Name,955);
Edit19->Text=KoIni->ReadString("acc",Edit19->Name,502);
for (int i = 0; i < 20; i++) {
Client[i].ChaosX=Edit18->Text.ToIntDef(955);
Client[i].ChaosY=Edit19->Text.ToIntDef(502);
}

for (int i = 0; i < BuffSkillList->Items->Count; i++) {
BuffSkillList->Checked[i]=KoIni->ReadBool("Buff",i,0);
for (int j = 0; j < 8; j++) {
Client[j].BuffSkills[i]= BuffSkillList->Checked[i];
}

}
for (int i = 0; i < HealList->Items->Count; i++) {
HealList->Checked[i]=KoIni->ReadBool("Heal",i,0);
for (int j = 0; j < 8; j++) {
Client[j].HealSkills[i]= HealList->Checked[i];
}
}

KoIni->Free();
//LeaveCriticalSection(&CriticalSection);
SellList->Items->LoadFromFile(NewPath+"SellList.txt");
CrashList->Items->LoadFromFile(NewPath+"CrashList.txt");
TradeList->Items->LoadFromFile(NewPath+"TradeList.txt");
UpdateTrade(Sender);
UpdateSell(Sender);
UpdateCrash(Sender);
SettingsLoaded=true;





SocketForm[0].SkillKod=ListBox4;
SocketForm[1].SkillKod=ListBox9;
SocketForm[2].SkillKod=ListBox14;
SocketForm[3].SkillKod=ListBox19;
SocketForm[4].SkillKod=ListBox24;
SocketForm[5].SkillKod=ListBox29;
SocketForm[6].SkillKod=ListBox34;
SocketForm[7].SkillKod=ListBox39;

SocketForm[0].SkillList=ListBox5;
SocketForm[1].SkillList=ListBox10;
SocketForm[2].SkillList=ListBox15;
SocketForm[3].SkillList=ListBox20;
SocketForm[4].SkillList=ListBox25;
SocketForm[5].SkillList=ListBox30;
SocketForm[6].SkillList=ListBox35;
SocketForm[7].SkillList=ListBox40;

SocketForm[0].SkillTime=ListBox6;
SocketForm[1].SkillTime=ListBox11;
SocketForm[2].SkillTime=ListBox16;
SocketForm[3].SkillTime=ListBox21;
SocketForm[4].SkillTime=ListBox26;
SocketForm[5].SkillTime=ListBox31;
SocketForm[6].SkillTime=ListBox36;
SocketForm[7].SkillTime=ListBox41;

SocketForm[0].SelectedSkillList=ListBox7;
SocketForm[1].SelectedSkillList=ListBox12;
SocketForm[2].SelectedSkillList=ListBox17;
SocketForm[3].SelectedSkillList=ListBox22;
SocketForm[4].SelectedSkillList=ListBox27;
SocketForm[5].SelectedSkillList=ListBox32;
SocketForm[6].SelectedSkillList=ListBox37;
SocketForm[7].SelectedSkillList=ListBox42;

SocketForm[0].SelectedSkillIdList=ListBox8;
SocketForm[1].SelectedSkillIdList=ListBox13;
SocketForm[2].SelectedSkillIdList=ListBox18;
SocketForm[3].SelectedSkillIdList=ListBox23;
SocketForm[4].SelectedSkillIdList=ListBox28;
SocketForm[5].SelectedSkillIdList=ListBox33;
SocketForm[6].SelectedSkillIdList=ListBox38;
SocketForm[7].SelectedSkillIdList=ListBox43;

SocketForm[0].SelectedSkillTime=Memo9;
SocketForm[1].SelectedSkillTime=Memo10;
SocketForm[2].SelectedSkillTime=Memo11;
SocketForm[3].SelectedSkillTime=Memo12;
SocketForm[4].SelectedSkillTime=Memo13;
SocketForm[5].SelectedSkillTime=Memo14;
SocketForm[6].SelectedSkillTime=Memo15;
SocketForm[7].SelectedSkillTime=Memo16;



PageControl1->TabIndex=0;
String baf= "qwertyuiopasdfghjklzxcvbnm1234567890";
for (int j = 0; j < 8; j++) {
SocketForm[j].Name->Text="";
}
for (int i = 0; i < 12; i++) {
for (int j = 0; j < 8; j++) {
Randomize();
	SocketForm[j].Name->Text=SocketForm[j].Name->Text+baf.SubString(Random(36),1);
}
}
//ClientSocket2->Active=true;
Button5Click(0);
}






//---------------------------------------------------------------------------



void GirisBilgiIsle(BYTE *ID,
					int Idlen ,
					BYTE *CharID,
					int CharLen,
					int Server,
					LoginBilgileri *LoginBilgi_Isle,
					BYTE *GirisPW,
					int GirPWLen,
                    BYTE *ServerCode,
					int  ServerCodeLen
					
					)
{

  memset(LoginBilgi_Isle->Giris,0,255);

  LoginBilgi_Isle->GirisLen=1;
  LoginBilgi_Isle->Giris[0]=0xF3;
  LoginBilgi_Isle->Giris[1]=Idlen;
  LoginBilgi_Isle->GirisLen+=2;
  memcpy(&LoginBilgi_Isle->Giris[LoginBilgi_Isle->GirisLen],ID,Idlen);

  LoginBilgi_Isle->GirisLen+=Idlen;

  memcpy(&LoginBilgi_Isle->Giris[LoginBilgi_Isle->GirisLen],GirisPW,GirPWLen);
   LoginBilgi_Isle->GirisLen+=GirPWLen;

  memcpy(LoginBilgi_Isle->ServerGiris,LoginBilgi_Isle->Giris,LoginBilgi_Isle->GirisLen);
  LoginBilgi_Isle->ServerGirisLen=LoginBilgi_Isle->GirisLen;
  LoginBilgi_Isle->ServerGiris[0]=1;
  LoginBilgi_Isle->ServerGiris[0]=1;
  memcpy(&LoginBilgi_Isle->ServerGiris[LoginBilgi_Isle->GirisLen],ServerCode,ServerCodeLen);
//  LoginBilgi_Isle->ServerGiris[LoginBilgi_Isle->GirisLen]=Server;
  LoginBilgi_Isle->ServerGirisLen+=ServerCodeLen;


LoginBilgi_Isle->SlectGirisUz=1;
LoginBilgi_Isle->SlectGirisCode[0]=0x4;
memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],&Idlen,2);
LoginBilgi_Isle->SlectGirisUz+=2;
memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],ID,Idlen);
LoginBilgi_Isle->SlectGirisUz+=Idlen;
//memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],&CharLen,2);
//LoginBilgi_Isle->SlectGirisUz+=2;
//memcpy(&LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz],CharID,CharLen);
//LoginBilgi_Isle->SlectGirisUz+=CharLen;
//LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz] =01;
//LoginBilgi_Isle->SlectGirisUz++;
//LoginBilgi_Isle->SlectGirisCode[LoginBilgi_Isle->SlectGirisUz] =0x15;
//LoginBilgi_Isle->SlectGirisUz++;
//strcpy(LoginBilgi_Isle->CharId,CharID);

//LoginBilgi_Isle->CharId=String((char *)CharID);
}


















LoginIslem(int soket){

String CharId;
String CharPassword;
int Server;
int Loc;
//ShowMessage("166");
//EnterCriticalSection(&CriticalSection);
CharId=SocketForm[soket].Account->Text;
CharPassword=SocketForm[soket].Password->Text;
srv[soket]=SocketForm[soket].Server->ItemIndex;
loc[soket]=SocketForm[soket].Loc->ItemIndex;


//LeaveCriticalSection(&CriticalSection);
DusurCharId[soket]=CharId;

Dusur(ServerIps[28],CharId);//28cw

 //ShowMessage("16");

BYTE OyunPassword[33];
String CharNe;
String PWL= CharPassword  ;
//CharNe= KoIni->ReadString(Form1->AccountList->Items->Strings[soket],"Char"+IntToStr(Form1->CharYer->ItemIndex+1),0);

char MD5[50];
 memset(MD5,0,50);
// int sLen=0;
 Ko_Thread[0]->SifreToMD5(MD5,PWL.c_str());
// sLen=strlen(MD5);
 PWL=String(MD5);
int PassUzunluk=PWL.Length() ;
if(!PassUzunluk)
{

 return 0;
}
*(WORD*)&OyunPassword=PassUzunluk;
memcpy(&OyunPassword[2],PWL.c_str(),PassUzunluk);
PassUzunluk+=2;

BYTE CodePW[]={0x01,0x00,0x01,0x00,0x00,0x00};

GirisBilgiIsle(CharId.c_str(),
			CharId.Length(),
			CharNe.c_str(),
			CharNe.Length(),
			Server,
			&LoginBilgilerip[soket],
			OyunPassword,
			PassUzunluk,
			CodePW,
			sizeof(CodePW)

			);



// LoginBilgilerip[soket].charisim=Form1->CharIsim->Checked;
 LoginBilgilerip[soket].StartVer=true;
// Form1->Bekle->Enabled=true;
 /*	 if(Ko_Thread[soket]->Threadcikis==0)
	 {
	 Ko_Thread[soket]->Terminate();
	 Sleep(3000);
	 }*/

 LoginBilgilerip[soket].scno=soket;
 LoginBilgilerip[soket].tip=0;
 //LoginBilgilerip[soket].port=port1;

 if (Client[soket].ProxyEnable) {
strcpy(LoginBilgilerip[soket].lgIp,ProxyIps[srv[soket]].c_str());
strcpy(LoginBilgilerip[soket].lgIp,LoginServerProxyAdres.c_str());
 }else{
 strcpy(LoginBilgilerip[soket].lgIp,ServerIps[srv[soket]].c_str());
strcpy(LoginBilgilerip[soket].lgIp,"kologin.knightonlineworld.com");
}
 return 1 ;
  //ShowMessage("17");
}

/////////////////////////////////////////////
int    DeleteThreadAll(int scno)
  {
   TerminateThread(Komut41Thread[scno],1);
	  TerminateThread(AnaThreadHandle[scno],1);
   TerminateThread(AtackThreadHandle[scno],1);
	return 1 ;
  }
int    SuspendThreadAll(int scno)
  {
   SuspendThread(Komut41Thread[scno]);
	  SuspendThread(AnaThreadHandle[scno]);
   SuspendThread(AtackThreadHandle[scno]);
	return 1 ;
  }
int    ResumeThreadAll(int scno)
  {
   ResumeThread(Komut41Thread[scno]);
	  ResumeThread(AnaThreadHandle[scno]);
   ResumeThread(AtackThreadHandle[scno]);
	return 1 ;
  }

HANDLE ThreadOlustur(LPTHREAD_START_ROUTINE Calladres,void* par,int scno,String Name)
 {
   if("KazThread"== Name)
   TerminateThread(KazThreadHandle[scno],0);
   if("GitThread"== Name)
   TerminateThread(GitThreadHandle[scno],0);
   if("Thread41"== Name)
   TerminateThread(Komut41Thread[scno],0);
   if("PotThread"== Name)
   TerminateThread(PotThreadHandle[scno],0);
   if("PriestThread"== Name)
   TerminateThread(PriestThreadHandle[scno],0);
   if("AtackThread"== Name)
   TerminateThread(PriestThreadHandle[scno],0);
	if("AnaThread"== Name)
   TerminateThread(AnaThreadHandle[scno],0);
   if("GirisDc"== Name)
   TerminateThread(GirisDcHandle[scno],0);
   //	//EnterCriticalSection(&CriticalSection);
	DWORD tid;
   //	ThreadListe Thread_Liste;
	HANDLE thandle=CreateThread(0,0,(LPTHREAD_START_ROUTINE)Calladres,par,0,&tid);
   /*	Thread_Liste.thandle= thandle;
	Thread_Liste.tid= tid;
	Thread_Liste.scno= scno;
	Thread_Liste.Calladres= Calladres;
	ThreadListeVec.push_back(Thread_Liste) ;
	Form1->Memo9->Lines->Add(Name+":"+IntToStr(scno)) ;
	//LeaveCriticalSection(&CriticalSection); */
   if("Thread41"== Name)
	 Komut41Thread[scno]= thandle;
   else if("GitThread"== Name)
	 GitThreadHandle[scno]= thandle;
   else if("KazThread"== Name)
	 KazThreadHandle[scno]= thandle;
   else if("PotThread"== Name)
	 PotThreadHandle[scno]= thandle;
   else if("PriestThread"== Name)
	 PriestThreadHandle[scno]= thandle;
   else if("AtackThread"== Name)
	 AtackThreadHandle[scno]= thandle;
   else if("AnaThread"== Name)
	 AnaThreadHandle[scno]= thandle;
		else if("GirisDc"== Name)
	 GirisDcHandle[scno]= thandle;
	return  thandle;
 }
 //////////////////////////////////////////////////////////////////
int Disconnect(int No)
{
DeleteThreadAll(No);
if(Ko_Thread[No]->Threadcikis==0)
{
 try {
  Ko_Thread[No]->KoSocket1->Close();
 Ko_Thread[No]->KoSocket1->Active=false;



 Ko_Thread[No]->Terminate();
Ko_Thread[No]->~KoThreadClass();
Ko_Thread[No] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
Client[No].Ko_Threadsyn=Ko_Thread[No];
 } catch (...) {
 }

return 1;
}
return 0;
}

//////////////////////////////
int Connect(int No){
Disconnect(No);
Ko_Thread[No]->ProxyVar=Client[No].ProxyEnable;
LoginIslem(No);
Ko_Thread[No]->KoThreadIsle(true, 0,
MemoLog[No],
LoginBilgilerip[No],
SocketGelenVeriHepsi)  ;
ThreadDurum=1;
return 1;
}






void __fastcall TForm1::AllPtOkClick(TObject *Sender)
{
BYTE Komut[3]={0x2F,0x02,0x01};
for (int i = 0; i < 20; i++) {
Client[i].KomutYolla(Komut,sizeof(Komut)) ;
}

}
//---------------------------------------------------------------------------




void __fastcall TForm1::AllPtQuitClick(TObject *Sender)
{
BYTE Komut[]={0x2F,0x05};
for (int i = 0; i < 20; i++) {
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AllPressOkClick(TObject *Sender)
{

for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
BYTE Komut[]= {0x12,0x01};
Client[i].KomutYolla(Komut,sizeof(Komut));
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::AllTownClick(TObject *Sender)
{
BYTE Komut[]={0x48,0x00};
for (int i = 0; i < 20; i++) {
Client[i].KomutYolla(Komut,sizeof(Komut));
Application->ProcessMessages();
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::KazBaslaClick(TObject *Sender)
{

for (int i = 0; i < 20; i++) {
if ((Ko_Thread[i]->Socket_Bilgi1->LoginOk)) {
Ko_Thread[i]->Socket_Bilgi1->Kaz=false;
Client[i].CharacterMove(MineX->Text.ToIntDef(0),MineY->Text.ToIntDef(0),4);
}
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::KazDurClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Ko_Thread[i]->Socket_Bilgi1->Kaz=false;
}
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Button3Click(TObject *Sender)
{
SellList->Items->SaveToFile(NewPath+"SellList.txt");
CrashList->Items->SaveToFile(NewPath+"CrashList.txt");
TradeList->Items->SaveToFile(NewPath+"TradeList.txt");
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
void __fastcall TForm1::CreatePtClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
int  a=1;
for (int i = 0; i < 8; i++) {
if (i!=pComponent->Tag) {
String Kodd=Ko_Thread[i]->Socket_Bilgi1->CharName;
BYTE PtKomut[50];
memset(&PtKomut,0,50);
PtKomut[0]=0x2f;
PtKomut[1]=a;
a=3;
PtKomut[2]=Kodd.Length();
memcpy(&PtKomut[4],Kodd.c_str(),Kodd.Length());
Client[pComponent->Tag].KomutYolla(PtKomut,Kodd.Length()+4)  ;
Client[i].PartiBaskan=false;
}else{
//PartiKuran=Ko_Thread[i]->Socket_Bilgi1->CharName;
Client[i].PartiBaskan=true;
}
}


}

void __fastcall TForm1::AddPtClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
String Deger;
bool Onay=InputQuery("Party Request ","Write Name of Character to request ",Deger);
if (Onay) {
BYTE PtKomut[50];
memset(&PtKomut,0,50);
PtKomut[0]=0x2f;
if (Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Party) {
PtKomut[1]=0x3;
} else {
PtKomut[1]=0x1;
Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Party=true;
}

PtKomut[2]=Deger.Length();
memcpy(&PtKomut[4],Deger.c_str(),Deger.Length());
Client[pComponent->Tag].KomutYolla(PtKomut,Deger.Length()+4)  ;

}
}
void __fastcall TForm1::QuitPtClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
BYTE Komut[4]={0x2F,0x04,0x00,0x00};
*(WORD*)&Komut[2]=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->CharID ;
Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));
}

void __fastcall TForm1::SellItem2Click(TObject *Sender)
{

  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);

BYTE Komut1[]={0x21,0x02,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x38,0xD0,0x30,0x17,0x04,0x03,0x00};
*(DWORD*)&Komut1[8]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id ;
*(WORD*)&Komut1[13]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Adet ;
Komut1[12]=ItemYer ;
Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1)) ;

  }
  else
	MessageBeep(0);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::SellAll1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
for (int j = 0; j < 28; j++) {
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Id!=0) {
if (Form1->SellList->Items->IndexOf(IntToStr(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Id))!=-1) {

Sleep(50);
BYTE Komut1[]={0x21,0x02,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x38,0xD0,0x30,0x17,0x04,0x03,0x00};
*(DWORD*)&Komut1[8]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Id ;
*(WORD*)&Komut1[13]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Adet ;
Komut1[12]=j ;
Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1)) ;
}else if (Form1->CrashList->Items->IndexOf(IntToStr(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Id))!=-1) {
BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
*(DWORD*)&Komut1[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[j].Id ;
Komut1[2]=j ;
Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1)) ;
	  }




}
}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SellItem1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 Client[sok].CharacterMove(Client[sok].Zone.Sundress.X,Client[sok].Zone.Sundress.Y,0);

  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrashItem1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id==0x2faf8cd0) {
BYTE Komut1[]={0x31,0x03,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut1[6]=Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Komut1[8]=Ko_Thread[sok]->Socket_Bilgi1->CharID;

BYTE Komut2[]={0x31,0x06,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*(WORD*)&Komut2[6]=Ko_Thread[sok]->Socket_Bilgi1->CharID;
*(WORD*)&Komut2[8]=Ko_Thread[sok]->Socket_Bilgi1->CharID;
for (int i = 0; i < 30; i++) {
Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1));
Client[pComponent->Tag].KomutYolla(Komut2,sizeof(Komut2));
}


}else{

	 BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
*(DWORD*)&Komut1[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id ;
Komut1[2]=ItemYer ;
Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1)) ;

	 }
  }
  else
	MessageBeep(0);

}
//---------------------------------------------------------------------------


 class KoThreadToll
{

	public:

	DWORD Komut55AAIsle(BYTE *Decode_Komut,BYTE *Gidecek_Komut,WORD DecodeLen)
{
DWORD *TempDWord;
WORD  *TempWord;
TempWord = (WORD* ) Decode_Komut;
TempWord[0]=0x55AA;
TempWord[1]=DecodeLen;
TempWord= (WORD*)&Decode_Komut[DecodeLen+4];
TempWord[0]=0xAA55;
memcpy(&Decode_Komut[4],Gidecek_Komut,DecodeLen);
 return 1 ;
}
int	Dusur(String Ip,String Name)
	{
	  int GidenLen;
	 BYTE ServerKomut[55];
				 BYTE Aski[50]={0x51,0x08,0x00,0x6D,0x61,0x6B,0x69,0x6E,0x31,0x35,0x36};
				  Aski[0]=0x51;
				  Aski[1]=Name.Length();//Form1->AccEkle->Text.Length();
				  GidenLen=Aski[1];
				  GidenLen+=3;
				  memcpy(&Aski[3],Name.c_str(),Aski[1]);
				  Komut55AAIsle(ServerKomut,Aski,GidenLen);
				 GidenLen+=6;


 TClientSocket *KoSocket1= new TClientSocket(0) ;
	  KoSocket1->ClientType= ctBlocking;
	  KoSocket1->Port=15001;
	  KoSocket1->Host=Ip;
				try{
				  KoSocket1->Active=true;
				  KoSocket1->Socket->SendBuf(ServerKomut,GidenLen);
				  return 1     ;
				}
				catch(...)
				{
					return 0;
				}
	}


};


int sira=0;
void __fastcall TForm1::ConnectAll1Click(TObject *Sender)
{
//for (int i = 0; i < 20; i++) {
//if (SocketForm[i].Account!="") {
//Connect(i);
//Application->ProcessMessages();
//}
//}
otologinnext=true;
  sira = 0 ;  Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DisconnectAll1Click(TObject *Sender)
{
for(int i=0;i<20;i++)
{
Disconnect(i);
DeleteThreadAll(i);
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ConClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;

	Connect(pComponent->Tag) ;
}
//---------------------------------------------------------------------------





Town(int No){
BYTE Komut[]={0x48,0x00};
Client[No].KomutYolla(Komut,sizeof(Komut));
 return 1 ;
}

void __fastcall TForm1::TownClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;

	Town(pComponent->Tag) ;
}
void __fastcall TForm1::CoordinateClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
String Deger;
bool Onay=InputQuery("Coordinate ","Write Coordinate Like X,Y ",Deger);
if (Onay) {
Client[pComponent->Tag].CharacterMove(Deger.SubString(Deger.AnsiPos(","),-1).ToIntDef(0),Deger.SubString(Deger.AnsiPos(",")+1,Deger.Length()-Deger.AnsiPos(",")).ToIntDef(0),0);
}

}




void __fastcall TForm1::Exit1Click(TObject *Sender)
{
try{
DisconnectAll1Click(0);
				}
				catch(...)
				{

				}
Sleep(1000);
TerminateProcess(GetCurrentProcess(),0);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ListClick(TObject *Sender)
{
	int sok = (dynamic_cast<TListBox *>(Sender))->Tag ;
	for (int i = 0; i < 20; i++)
	{
		if ((((dynamic_cast<TListBox *>(Sender))->Items->IndexOf(Client[i].Ko_Threadsyn->Socket_Bilgi1->CharID)!=-1)||(i==sok))&&(Client[i].Ko_Threadsyn->Socket_Bilgi1->CharID!=0))
		{
			SocketForm[i].SocketGroup->Color=clYellow;
		}
		else
		{
			SocketForm[i].SocketGroup->Color=clBtnFace;
		}
	}
}
void __fastcall TForm1::Button5Click(TObject *Sender)
{
allsrv->Items->LoadFromFile("server.txt");
TIniFile *aIni=new TIniFile(NewPath+"protect.dll");;

int x,y;
x=0;
y=0;
int x1,y1;
x1=0;
y1=0;

for (int i = 0; i < 20; i++) {
if (i == 5 ||i == 10 || i == 15) {
y= y+130;
x=0;
}
SocketForm[i].SocketGroup = new TGroupBox(this);
SocketForm[i].SocketGroup->Tag=i;
SocketForm[i].SocketGroup->Parent=TabSheet1;
SocketForm[i].SocketGroup->Visible=true;
SocketForm[i].SocketGroup->Left=x;
SocketForm[i].SocketGroup->Top=y;
SocketForm[i].SocketGroup->Height=127;
SocketForm[i].SocketGroup->Width=193;
SocketForm[i].SocketGroup->OnClick=SocketIslem;


SocketForm[i].SocketGroup->Caption= "Socket "+ IntToStr(i);




SocketForm[i].Memo = new TMemo(this);
SocketForm[i].Memo->Tag=i;
SocketForm[i].Memo->Parent=SocketForm[i].SocketGroup;
SocketForm[i].Memo->Visible=true;
SocketForm[i].Memo->Left=3;
SocketForm[i].Memo->Top=13;
SocketForm[i].Memo->Height=90;
SocketForm[i].Memo->Width=135;

SocketForm[i].List = new TListBox(this);
SocketForm[i].List->Tag=i;
SocketForm[i].List->Parent=SocketForm[i].SocketGroup;
SocketForm[i].List->Visible=true;
SocketForm[i].List->Left=138;
SocketForm[i].List->Top=13;
SocketForm[i].List->Height=90;
SocketForm[i].List->Width=50;
SocketForm[i].List->OnClick=ListClick;
for (int j = 0; j < 20; j++) {
if (i==j) {
SocketForm[i].List->Items->Add("0000");
}else{
SocketForm[i].List->Items->Add("0");
}

}


SocketForm[i].HpBar = new TProgressBar(this);
SocketForm[i].HpBar->Tag=i;
SocketForm[i].HpBar->Parent=SocketForm[i].SocketGroup;
SocketForm[i].HpBar->Visible=true;
SocketForm[i].HpBar->Left=3;
SocketForm[i].HpBar->Top=102;
SocketForm[i].HpBar->Height=10;
SocketForm[i].HpBar->Width=100;
SocketForm[i].HpBar->Min=0;
SocketForm[i].HpBar->Max=100;

SocketForm[i].MpBar = new TProgressBar(this);
SocketForm[i].MpBar->Tag=i;
SocketForm[i].MpBar->Parent=SocketForm[i].SocketGroup;
SocketForm[i].MpBar->Visible=true;
SocketForm[i].MpBar->Left=3;
SocketForm[i].MpBar->Top=113;
SocketForm[i].MpBar->Height=10;
SocketForm[i].MpBar->Width=100;
SocketForm[i].MpBar->Min=0;
SocketForm[i].MpBar->Max=100;

SocketForm[i].HpShow = new TLabel(this);
SocketForm[i].HpShow->Tag=i;
SocketForm[i].HpShow->Parent=SocketForm[i].SocketGroup;
SocketForm[i].HpShow->Visible=true;
SocketForm[i].HpShow->Left=106;
SocketForm[i].HpShow->Top=102;
SocketForm[i].HpShow->Height=10;
SocketForm[i].HpShow->Width=11;
SocketForm[i].HpShow->Caption="0/0";
SocketForm[i].HpShow->Font->Height= -8;

SocketForm[i].MpShow = new TLabel(this);
SocketForm[i].MpShow->Tag=i;
SocketForm[i].MpShow->Parent=SocketForm[i].SocketGroup;
SocketForm[i].MpShow->Visible=true;
SocketForm[i].MpShow->Left=106;
SocketForm[i].MpShow->Top=113;
SocketForm[i].MpShow->Height=10;
SocketForm[i].MpShow->Width=11;
SocketForm[i].MpShow->Caption="0/0";
SocketForm[i].MpShow->Font->Height= -8;

SocketForm[i].cX = new TEdit(this);
SocketForm[i].cX->Tag=i;
SocketForm[i].cX->Parent=SocketForm[i].SocketGroup;
SocketForm[i].cX->Visible=true;
SocketForm[i].cX->Left=149;
SocketForm[i].cX->Top=102;
SocketForm[i].cX->Height=18;
SocketForm[i].cX->Width=20;
SocketForm[i].cX->Font->Height= -8;

SocketForm[i].cY = new TEdit(this);
SocketForm[i].cY->Tag=i;
SocketForm[i].cY->Parent=SocketForm[i].SocketGroup;
SocketForm[i].cY->Visible=true;
SocketForm[i].cY->Left=168;
SocketForm[i].cY->Top=102;
SocketForm[i].cY->Height=18;
SocketForm[i].cY->Width=20;
SocketForm[i].cY->Font->Height= -8;


SocketForm[i].CreateGroup = new TGroupBox(this);
SocketForm[i].CreateGroup->Tag=i;
SocketForm[i].CreateGroup->Parent=TabSheet3;
SocketForm[i].CreateGroup->Visible=true;
SocketForm[i].CreateGroup->Left=x1;
SocketForm[i].CreateGroup->Top=y1;
SocketForm[i].CreateGroup->Height=36;
SocketForm[i].CreateGroup->Width=705;


SocketForm[i].CreateGroup->Caption= "Account "+ IntToStr(i);

SocketForm[i].Account = new TEdit(this);
SocketForm[i].Account->Tag=i;
SocketForm[i].Account->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Account->Visible=true;
SocketForm[i].Account->Left=3;
SocketForm[i].Account->Top=11;
SocketForm[i].Account->Height=21;
SocketForm[i].Account->Width=120;
SocketForm[i].Account->Name = "dyn_acc_"+ IntToStr(i) ;
SocketForm[i].Account->OnChange=EditSave;

SocketForm[i].Account->Text=aIni->ReadString("acc",SocketForm[i].Account->Name,"");

SocketForm[i].Password = new TEdit(this);
SocketForm[i].Password->Tag=i;
SocketForm[i].Password->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Password->Visible=true;
SocketForm[i].Password->Left=123;
SocketForm[i].Password->Top=11;
SocketForm[i].Password->Height=21;
SocketForm[i].Password->Width=120;
SocketForm[i].Password->Name = "dyn_pwd_"+ IntToStr(i) ;
SocketForm[i].Password->OnChange=EditSave;
SocketForm[i].Password->Text=aIni->ReadString("acc",SocketForm[i].Password->Name,"");

SocketForm[i].Server = new TComboBox(this);
SocketForm[i].Server->Tag=i;
SocketForm[i].Server->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Server->Visible=true;
SocketForm[i].Server->Text="Server";
SocketForm[i].Server->Left=243;
SocketForm[i].Server->Top=11;
SocketForm[i].Server->Height=21;
SocketForm[i].Server->Width=90;
SocketForm[i].Server->Items->LoadFromFile("server.txt");
SocketForm[i].Server->Name = "dyn_srv_"+ IntToStr(i) ;
SocketForm[i].Server->OnChange=ComboSave;
KoIni= new TIniFile(NewPath+"protect.dll");
SocketForm[i].Server->ItemIndex=aIni->ReadInteger("acc",SocketForm[i].Server->Name,-1);

SocketForm[i].Loc = new TComboBox(this);
SocketForm[i].Loc->Tag=i;
SocketForm[i].Loc->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Loc->Visible=true;
SocketForm[i].Loc->Text="Location";
SocketForm[i].Loc->Left=333;
SocketForm[i].Loc->Top=11;
SocketForm[i].Loc->Height=21;
SocketForm[i].Loc->Width=90;
SocketForm[i].Loc->Items->Add("Center");
SocketForm[i].Loc->Items->Add("Left");
SocketForm[i].Loc->Items->Add("Right");
SocketForm[i].Loc->Name = "dyn_loc_"+ IntToStr(i) ;
SocketForm[i].Loc->OnChange=ComboSave;
SocketForm[i].Loc->ItemIndex=aIni->ReadInteger("acc",SocketForm[i].Loc->Name,-1);

SocketForm[i].Race = new TComboBox(this);
SocketForm[i].Race->Tag=i;
SocketForm[i].Race->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Race->Visible=true;
SocketForm[i].Race->Left=460;
SocketForm[i].Race->Top=11;
SocketForm[i].Race->Height=21;
SocketForm[i].Race->Width=64;
SocketForm[i].Race->Items->Add("Human");
SocketForm[i].Race->Items->Add("Karus");
SocketForm[i].Race->ItemIndex=0;
SocketForm[i].Race->Name = "dyn_race_"+ IntToStr(i) ;
SocketForm[i].Race->OnChange=ComboSave;
SocketForm[i].Race->ItemIndex=aIni->ReadInteger("acc",SocketForm[i].Race->Name,-1);

SocketForm[i].Type = new TComboBox(this);
SocketForm[i].Type->Tag=i;
SocketForm[i].Type->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Type->Visible=true;
SocketForm[i].Type->Left=524;
SocketForm[i].Type->Top=11;
SocketForm[i].Type->Height=21;
SocketForm[i].Type->Width=64;
SocketForm[i].Type->Items->Add("Warrior");
SocketForm[i].Type->Items->Add("Rogue");
SocketForm[i].Type->Items->Add("Mage");
SocketForm[i].Type->Items->Add("Priest");
SocketForm[i].Type->ItemIndex=1;
SocketForm[i].Type->Name = "dyn_type_"+ IntToStr(i) ;
SocketForm[i].Type->OnChange=ComboSave;
SocketForm[i].Type->ItemIndex=aIni->ReadInteger("acc",SocketForm[i].Type->Name,-1);

SocketForm[i].Name = new TEdit(this);
SocketForm[i].Name->Tag=i;
SocketForm[i].Name->Parent=SocketForm[i].CreateGroup;
SocketForm[i].Name->Visible=true;
SocketForm[i].Name->Left=590;
SocketForm[i].Name->Top=11;
SocketForm[i].Name->Height=21;
SocketForm[i].Name->Width=100;
SocketForm[i].Name->Name = "dyn_createname_"+ IntToStr(i) ;
SocketForm[i].Name->OnChange=EditSave;
SocketForm[i].Name->Text=aIni->ReadString("acc",SocketForm[i].Name->Name,"");








SocketForm[i].ItemGroup = new TGroupBox(this);
SocketForm[i].ItemGroup->Tag=i;
SocketForm[i].ItemGroup->Parent=TabSheet6;
SocketForm[i].ItemGroup->Visible=true;
SocketForm[i].ItemGroup->Left=x;
SocketForm[i].ItemGroup->Top=y;
SocketForm[i].ItemGroup->Height=127;
SocketForm[i].ItemGroup->Width=193;
//SocketForm[i].ItemGroup->OnClick=SocketIslem;
SocketForm[i].ItemGroup->Caption= "Item "+ IntToStr(i);


SocketForm[i].Para= new TLabel(this);
SocketForm[i].Para->Caption=0;
SocketForm[i].Para->Font->Style=TFontStyles() << fsBold;
SocketForm[i].Para->Font->Color=clBlack;
SocketForm[i].Para->Top=0;
SocketForm[i].Para->Left=100;
SocketForm[i].Para->Height=20;
SocketForm[i].Para->Width=100;
SocketForm[i].Para->Parent=SocketForm[i].ItemGroup;

int xa=10;
int ya=13;
for (int ii = 0; ii < 4; ii++) {
for (int j = 0; j < 7; j++) {
Img[i][ii*7+j]= new TImage(this);
Img[i][ii*7+j]->Parent=SocketForm[i].ItemGroup;
Img[i][ii*7+j]->Top=ya;
Img[i][ii*7+j]->Left=xa;
Img[i][ii*7+j]->Tag=i;
Img[i][ii*7+j]->Hint=ii*7+j;
Img[i][ii*7+j]->Height=25;
Img[i][ii*7+j]->Width=25;
String a ="images/co_black_thumb.jpg";
Img[i][ii*7+j]->Picture->LoadFromFile(a);
Img[i][ii*7+j]->OnMouseDown=ItemIslem;


ItemAdet[i][ii*7+j]= new TLabel(this);
ItemAdet[i][ii*7+j]->Caption=0;
ItemAdet[i][ii*7+j]->Font->Style=TFontStyles() << fsBold;
ItemAdet[i][ii*7+j]->Font->Color=clBlack;
ItemAdet[i][ii*7+j]->Font->Height=-8;
ItemAdet[i][ii*7+j]->Top=ya+15;
ItemAdet[i][ii*7+j]->Left=xa+10;
ItemAdet[i][ii*7+j]->Height=10;
ItemAdet[i][ii*7+j]->Width=35;
ItemAdet[i][ii*7+j]->Parent=SocketForm[i].ItemGroup;
//
ItemPlus[i][ii*7+j]= new TLabel(this);
//ItemPlus[s][i*7+j]->Caption="+0";
//ItemPlus[s][i*7+j]->Font->Style=TFontStyles() << fsBold;
//ItemPlus[s][i*7+j]->Font->Color=clBlack;
//ItemPlus[s][i*7+j]->Top=y;
//ItemPlus[s][i*7+j]->Left=x;
//ItemPlus[s][i*7+j]->Height=20;
//ItemPlus[s][i*7+j]->Width=35;
//ItemPlus[s][i*7+j]->Parent=TabSheet6;

Img[i][ii*7+j]->Visible=false;
ItemAdet[i][ii*7+j]->Visible=false;
ItemPlus[i][ii*7+j]->Visible=false;
xa+=25;
}
xa=10;
ya+=25;
}


//if (s==3) {
//yy=0;
//xx=325;
//}else{
//yy+=200;
//}

















x+=200;
y1+=30;


}
aIni->Free();













}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
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

		 if (!PacketCoz(KomutBuf,glnlen)){
			Application->Terminate();
		 }
		 switch(KomutBuf[2])
		 {
		 case 0x0: {
		 switch (KomutBuf[3]) {
			case 0x00:ShowMessage("Version Error");TerminateProcess(GetCurrentProcess(),0);break;
			case 0x01:{
			BYTE Send[1024];
int Yer=0;
Send[Yer]=0x01;
Yer++;
Send[Yer]=1;
Yer++;
memcpy(&Send[Yer],u.c_str(),u.Length());
Yer+=u.Length();
Send[Yer]=p.Length();
Yer++;
memcpy(&Send[Yer],p.c_str(),p.Length());
Yer+=p.Length();
Send[Yer]=HDDNO.Length();
Yer++;
memcpy(&Send[Yer],HDDNO.c_str(),HDDNO.Length());
Yer+=HDDNO.Length();

PacketSifrele(Send,Yer,keykontrol);
Socket->SendBuf(Send,*(WORD*)&Send[1]);
			};break;
			default:
				;
			}
		 }break;
		 case 0x1: {
			switch (KomutBuf[3]) {
			case 0x00:ShowMessage("Username Error");TerminateProcess(GetCurrentProcess(),0);break;
			case 0x01:ShowMessage("Password Error");TerminateProcess(GetCurrentProcess(),0);break;
			case 0x02:TerminateProcess(GetCurrentProcess(),0);break;
			default:
				;
			}
		 }break;
				 case 0x2: {
			switch (KomutBuf[3]) {
			case 0x00:{

				 memcpy(&Data1,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x01;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x01:{
				 memcpy(&Data2,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x02;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x02:{
				 memcpy(&Data3,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x03;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x03:{
				 memcpy(&Data4,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x04;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x04:{
				 memcpy(&Data5,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x05;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x05:{
ModulAl=  Manueldll("KODLL","KODLLNAME");
Ko_Class = (KoClass) MemoryGetProcAddress(ModulAl,"KoClass");



for (int i = 0; i < 20; i++) {
Ko_Thread[i] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
Client[i].Ko_Threadsyn=Ko_Thread[i];
}
ClientSocket3->Active=true;
Sleep(2000);
Form1->Timer3->Enabled=true;
if (Form1->ototo->Checked) {
sira = 0 ;
Timer2->Enabled=true;
}
PageControl1->TabIndex=1;
			}break;
			default:
				;
			}
		 }break;
		 default:

							  break;



		 }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::SeciliLCekClick(TObject *Sender)
{
if (Form1->LetterId->Count>0) {
BYTE Komut[]={0x6A,0x05,0x04,0x38,0xEA,0x46,0x00};
*(DWORD*)&Komut[3]=Form1->LetterId->Items->Strings[0].ToIntDef(0);
//Ko_Thread[0]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[1]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[2]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[3]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[4]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[5]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[6]->Extern_KomutYolla(Komut,sizeof(Komut));
//Ko_Thread[7]->Extern_KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboSave(TObject *Sender){

if (SettingsLoaded) {
TComboBox *Item = dynamic_cast<TComboBox *>(Sender);
//EnterCriticalSection(&CriticalSection);
KoIni = new TIniFile(NewPath+"protect.dll");
KoIni->WriteInteger("acc",Item->Name,Item->ItemIndex);
KoIni->Free();
//LeaveCriticalSection(&CriticalSection);
}
}

		void __fastcall TForm1::EditSave(TObject *Sender)
{

if (SettingsLoaded) {
TEdit *Item = dynamic_cast<TEdit *>(Sender);
//EnterCriticalSection(&CriticalSection);
KoIni = new TIniFile(NewPath+"protect.dll");
KoIni->WriteString("acc",Item->Name,Item->Text);
KoIni->Free();
//LeaveCriticalSection(&CriticalSection);
}


}

void __fastcall TForm1::MemoSave(TObject *Sender)
{
//TMemo *Item = dynamic_cast<TMemo *>(Sender);
//Item->Lines->SaveToFile(Item->Name+".txt");

}

		void __fastcall TForm1::ListSave(TObject *Sender)
{
if (SettingsLoaded) {
TListBox *Item = dynamic_cast<TListBox *>(Sender);
Item->Items->SaveToFile(NewPath+Item->Name+".txt");
}
}







void __fastcall TForm1::LeftHandClick(TObject *Sender)
{
 TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x08};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightHandClick(TObject *Sender)
{
 TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x06};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }

}
void __fastcall TForm1::MoveItemClick(TObject *Sender)
{
 TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TListBox *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TListBox *>(pComponent))->ItemIndex;
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x06};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }

}



GoRpr(int sock){
Ko_Thread[sock]->Socket_Bilgi1->AdresX=Client[sock].Zone.Sundress.X;
Ko_Thread[sock]->Socket_Bilgi1->AdresY=Client[sock].Zone.Sundress.Y;
Ko_Thread[sock]->Socket_Bilgi1->Arrive=3;
Ko_Thread[sock]->Socket_Bilgi1->Go=true;
 return 1 ;
}

void __fastcall TForm1::GoRepairClick(TObject *Sender)
{
TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
GoRpr(ClickedItem->Tag) ;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::radeConfirm1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
BYTE TKomut2[]={0x30,0x05};
Client[pComponent->Tag].KomutYolla(TKomut2,sizeof(TKomut2));

  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddThisItem1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id!=0) {
BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
VerKomut[2]=ItemYer;
*(DWORD*)&VerKomut[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
*(WORD*)&VerKomut[7]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Adet;
Client[pComponent->Tag].KomutYolla(VerKomut,sizeof(VerKomut));

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddMoney1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;

BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
String Deger;
bool Onay=InputQuery("Trade Money ","Write Amount of Money",Deger);
if (Onay) {
*(DWORD*)&Komut[7]=Deger.ToIntDef(0);
Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::GiveList1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 for (int i = 0; i < 28; i++) {
	 if (Form1->TradeList->Items->IndexOf(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Id)!=-1) {
BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
VerKomut[2]=i;
*(DWORD*)&VerKomut[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Id;
*(WORD*)&VerKomut[7]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Adet;
Client[pComponent->Tag].KomutYolla(VerKomut,sizeof(VerKomut));
	 }
	 }

if (paraver->Checked) {
BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
*(DWORD*)&Komut[7]=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Para-100000;
Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));
}
BYTE TKomut2[]={0x30,0x05};
Client[pComponent->Tag].KomutYolla(TKomut2,sizeof(TKomut2));
}
//---------------------------------------------------------------------------




















void __fastcall TForm1::ItemIslem(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
		TImage *ClickedItem = dynamic_cast<TImage *>(Sender);
		int sok=ClickedItem->Tag;
		int Yer =ClickedItem->Hint.ToIntDef(0);
switch (Button) {
	case mbLeft:
	{
		tagPOINT MousePosition;
		GetCursorPos(&MousePosition);
		PopupMenu2->PopupComponent= ClickedItem;
		PopupMenu2->Tag=Yer;
		PopupMenu2->Popup(MousePosition.x,MousePosition.y);
    }
	break;
	case mbRight:
	{
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[Yer].Id!=0) {
BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
VerKomut[2]=Yer;
*(DWORD*)&VerKomut[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[Yer].Id;
*(WORD*)&VerKomut[7]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[Yer].Adet;
Client[sok].KomutYolla(VerKomut,sizeof(VerKomut));

}
	}
	break;
    case mbMiddle: break;
default:
	;
}




}

void __fastcall TForm1::SocketIslem(TObject *Sender)
{
//TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
 TComponent *ClickedItem = dynamic_cast<TComponent *>(Sender);


tagPOINT MousePosition;
GetCursorPos(&MousePosition);

PopupMenu1->PopupComponent= ClickedItem;
PopupMenu1->Tag=ClickedItem->Tag;
PopupMenu1->Popup(MousePosition.x,MousePosition.y);
}






void __fastcall TForm1::Sell2Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id!=0) {
	 if (Form1->SellList->Items->IndexOf(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id)==-1) {
	 Form1->SellList->Items->Add(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id);
UpdateSell(Sender);
	 }

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Crash2Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id!=0) {
	 if (Form1->CrashList->Items->IndexOf(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id)==-1) {
	 Form1->CrashList->Items->Add(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id);
UpdateCrash(Sender);

	 }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rade2Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id!=0) {
	 if (Form1->TradeList->Items->IndexOf(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id)==-1) {
	 Form1->TradeList->Items->Add(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id);
UpdateTrade(Sender);

	 }
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SellListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==46) {
SellList->Items->Delete(SellList->ItemIndex);
UpdateSell(Sender);
TListBox *Item = dynamic_cast<TListBox *>(Sender);
Item->Items->SaveToFile(NewPath+Item->Name+".txt");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrashListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key==46) {
CrashList->Items->Delete(CrashList->ItemIndex);
UpdateCrash(Sender);

TListBox *Item = dynamic_cast<TListBox *>(Sender);
Item->Items->SaveToFile(NewPath+Item->Name+".txt");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TradeListKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
if (Key==46) {
TradeList->Items->Delete(TradeList->ItemIndex);
UpdateTrade(Sender);

TListBox *Item = dynamic_cast<TListBox *>(Sender);
Item->Items->SaveToFile(NewPath+Item->Name+".txt");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckClick(TObject *Sender)
{

if (SettingsLoaded) {
TCheckBox *Item = dynamic_cast<TCheckBox *>(Sender);
switch (Item->Hint.ToIntDef(0)) {
case 0 :{Client[Item->Tag].AutoLogin=Item->Checked;}break;
case 1 :{Client[Item->Tag].AutoLoot=Item->Checked;}break;
case 2 :{Client[Item->Tag].AutoPressOk=Item->Checked;}break;
case 3 :{Client[Item->Tag].AutoMine=Item->Checked;}break;
case 4 :{Client[Item->Tag].AutoRepair=Item->Checked;}break;
case 5 :{Client[Item->Tag].AutoPotion=Item->Checked;}break;
case 6 :{Client[Item->Tag].AutoHeal=Item->Checked;}break;
case 7 :{Client[Item->Tag].AutoBuff=Item->Checked;
for (int i = 0; i < 8; i++) {
Client[i].Buff=0;
}

}break;
case 8 :{Client[Item->Tag].ProxyEnable=Item->Checked;}break;
case 9 :{Client[Item->Tag].Dolas=Item->Checked;}break;
default:
	;
}
//EnterCriticalSection(&CriticalSection);
KoIni = new TIniFile(NewPath+"protect.dll");
KoIni->WriteBool("Settings"+IntToStr(Item->Tag),Item->Hint,Item->Checked);
KoIni->Free();
//LeaveCriticalSection(&CriticalSection);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::giveskill(TObject *Sender)
{
	 int sok=       (dynamic_cast<TButton *>(Sender))->Tag ;
	 int SkillYer= (dynamic_cast<TButton *>(Sender))->Hint.ToIntDef(0);
	 BYTE komut[]={0x32,0x05};
	 komut[1]=SkillYer;
	 Client[sok].KomutYolla(komut,sizeof(komut));



		 if (Client[sok].SkillPoint>0) {
	 switch (SkillYer) {
	 case 5:{
	 if (Client[sok].Skill0<Ko_Thread[sok]->Socket_Bilgi1->Level) {
	 Client[sok].Skill0++;
	 Client[sok].SkillPoint--;
	 }
	 }break;
	 case 6:{
	 if (Client[sok].Skill1<Ko_Thread[sok]->Socket_Bilgi1->Level) {
	 Client[sok].Skill1++;
	 Client[sok].SkillPoint--;
	 }
	 }break;
		 case 7:{
		 if (Client[sok].Skill2<Ko_Thread[sok]->Socket_Bilgi1->Level) {
	 Client[sok].Skill2++;
	 Client[sok].SkillPoint--;

		 }
	 }break;
	 case 8:{
	 if (Client[sok].Skill3<Ko_Thread[sok]->Socket_Bilgi1->Level) {
	 Client[sok].Skill3++;
	 Client[sok].SkillPoint--;

	 }
	 }break;
	 default:
		 ;
	 }
	 }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::givestatall(TObject *Sender)
{
	 int sok=       (dynamic_cast<TButton *>(Sender))->Tag ;
	 int StatYer= (dynamic_cast<TButton *>(Sender))->Hint.ToIntDef(0);
	 BYTE komut[]={0x28,0x01,0x01,0x00};
	 komut[1]=StatYer;
	 Client[sok].KomutYolla(komut,sizeof(komut));

	 if (Client[sok].Point>0) {
	 for (int i = 0; i < Client[sok].Point; i++) {
	 Sleep(30);
	 Application->ProcessMessages() ;
	 switch (StatYer) {
	 case 1:{
	 Client[sok].Str++;
	 Client[sok].Point--;
	 }break;
	 case 2:{
	 Client[sok].Hp++;
	 Client[sok].Point--;
	 }break;
	 case 3:{
	 Client[sok].Dex++;
	 Client[sok].Point--;
	 }break;
	 case 4:{
	 Client[sok].Int++;
	 Client[sok].Point--;
	 }break;
	 case 5:{
	 Client[sok].Mp++;
	 Client[sok].Point--;
	 }break;
	 default:
         ;
	 }
	 }
	 }
}
void __fastcall TForm1::givestat(TObject *Sender)
{
	 int sok=       (dynamic_cast<TButton *>(Sender))->Tag ;
	 int StatYer= (dynamic_cast<TButton *>(Sender))->Hint.ToIntDef(0);
	 BYTE komut[]={0x28,0x01,0x01,0x00};
	 komut[1]=StatYer;
	 Client[sok].KomutYolla(komut,sizeof(komut));

	 if (Client[sok].Point>0) {
	 switch (StatYer) {
	 case 1:{
	 Client[sok].Str++;
	 Client[sok].Point--;
	 }break;
	 case 2:{
	 Client[sok].Hp++;
	 Client[sok].Point--;
	 }break;
	 case 3:{
	 Client[sok].Dex++;
	 Client[sok].Point--;
	 }break;
	 case 4:{
	 Client[sok].Int++;
	 Client[sok].Point--;
	 }break;
	 case 5:{
	 Client[sok].Mp++;
	 Client[sok].Point--;
	 }break;
	 default:
         ;
	 }
	 }




}
void __fastcall TForm1::st1jobClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(815,708,14)   ;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
int index=-1;
float mesafe=999999;
for (int i = 0; i < 10; i++) {
if (Gateler[i].Zone==Client[RadioGroup2->ItemIndex].ZoneId) {
float mes = hypot((Ko_Thread[RadioGroup2->ItemIndex]->Socket_Bilgi1->X-Gateler[i].X),(Ko_Thread[RadioGroup2->ItemIndex]->Socket_Bilgi1->Y-Gateler[i].Y));
if (mes<mesafe) {
mesafe=mes;
index = i ;
}
}
}
ListBox3->ItemIndex=index;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button86Click(TObject *Sender)
{
int r  =Edit20->Text.ToIntDef(30);
SocketForm[0].ListX->Items->Clear();
SocketForm[0].ListY->Items->Clear();
int x = Ko_Thread[0]->Socket_Bilgi1->X;
int y = Ko_Thread[0]->Socket_Bilgi1->Y;
SocketForm[0].ListX->Items->Add(x);
SocketForm[0].ListY->Items->Add(y);
int newx = x+r;
int newy = y;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x+2*r/2;
newy = y+2*r/2;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x;
newy = y+r;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x-2*r/3;
newy = y+2*r/3;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x-r;
newy = y;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x-2*r/3;
newy = y-2*r/3;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x;
newy = y-r;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
newx = x+2*r/3;
newy = y-2*r/3;
SocketForm[0].ListX->Items->Add(newx);
SocketForm[0].ListY->Items->Add(newy);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DolasClick(TObject *Sender)
{
if (SocketForm[0].ListX->ItemIndex==(SocketForm[0].ListX->Items->Count-1)) {
	SocketForm[0].ListX->ItemIndex=1;
	SocketForm[0].ListY->ItemIndex=1;
}else{
	SocketForm[0].ListX->ItemIndex=SocketForm[0].ListX->ItemIndex+1;
	SocketForm[0].ListY->ItemIndex=SocketForm[0].ListY->ItemIndex+1;
}
for (int sok = 0; sok < 8; sok++) {

if (Client[sok].Dolas){
Ko_Thread[sok]->Socket_Bilgi1->AdresX=SocketForm[0].ListX->Items->Strings[SocketForm[0].ListX->ItemIndex].ToIntDef(0);
Ko_Thread[sok]->Socket_Bilgi1->AdresY=SocketForm[0].ListY->Items->Strings[SocketForm[0].ListY->ItemIndex].ToIntDef(0);
Ko_Thread[sok]->Socket_Bilgi1->Arrive=6;
Ko_Thread[sok]->Socket_Bilgi1->Go=true;
}
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ListBoxttDblClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {

BYTE Komut[]={0x4B,0xAE,0x0F,0x3F,0x08};
*(WORD*)&Komut[1]=*(WORD*)&Gateler[GateId].Id;
*(WORD*)&Komut[3]=Gate[ListBoxtt->ItemIndex];

Ko_Thread[i]->Extern_KomutYolla(Komut,sizeof(Komut));
//Komut[0]=0x3c;
//Komut[1]=0x41;
//
//Ko_Thread[i]->Extern_KomutYolla(Komut,2);
//Komut[0]=0x27;
//Komut[1]=0x1;

//Ko_Thread[i]->Extern_KomutYolla(Komut,2);

}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::PartyYp1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;

if (Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Party) {
CreateThread(0,0,(LPTHREAD_START_ROUTINE)PartyTpThread,(void*)pComponent->Tag,0,0);
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::toSocketClick(TObject *Sender)
{
TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
int atilacakid =ClickedItem->Tag;
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
Client[sok].ItemVerilecek=true;

BYTE TKomut[]={0x30,0x02,0x00};
Ko_Thread[sok]->Extern_KomutYolla(TKomut,sizeof(TKomut));

 BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
 *(WORD*)&Komut[2]=Ko_Thread[atilacakid]->Socket_Bilgi1->CharID;

Ko_Thread[sok]->Extern_KomutYolla(Komut,sizeof(Komut));
}
//---------------------------------------------------------------------------







void __fastcall TForm1::BuffSkillListClickCheck(TObject *Sender)
{
KoIni= new TIniFile(NewPath+"protect.dll");
for (int i = 0; i < BuffSkillList->Items->Count; i++) {
KoIni->WriteBool("Buff",i,BuffSkillList->Checked[i]);
for (int s = 0; s < 8; s++) {
Client[s].BuffSkills[i]=BuffSkillList->Checked[i];
}
}
KoIni->Free();
}
//---------------------------------------------------------------------------




int WINAPI LevelThread(int sok){
//while (1){
//if (Ko_Thread[sok]->Socket_Bilgi1->Level<5) {
//
//}else if (Ko_Thread[sok]->Socket_Bilgi1->Level<10) {
//if (Ko_Thread[sok]->Socket_Bilgi1->Gear_Table[6]==0) {
//s-0x1F,0x01,0xD0,0x3A,0x8F,0x06,0x00,0x06,  s-0x55,0x00,0x0B,0x30,0x31,0x5F,0x6D,0x61,0x69,0x6E,0x2E,0x6C,0x75,0x61,
//s-0x08,0x01,0x01,0xA0,0x3A,0x77,0x00,0x04,0x00,0x00,
//
//s-0x08,0x01,0x01,0xA0,0x3A,0x77,0x00,0x03,0x00,0x00,
//
//
//0x55,0x00,0x11,0x31,0x36,0x30,0x37,0x39,0x5F,0x4D,0x65,0x6E,0x69,0x73,0x69,0x61,0x2E,0x6C,0x75,0x61,
//
//0x31,0x03,0x11,0x15,0x03,0x00,0x2A,0x07,0x63,0x28,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//
//level 5
//0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x51,0x9C,0x8C,0x09,0x00,0x01,0x00,0x02,0x07,//bow
//s-0x1F,0x01,0x51,0x9C,0x8C,0x09,0x00,0x08,
//s-0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xB1,0x42,0xBC,0x0A,0x07,0x01,0x00,0x02,0x0C, //wood staff
//0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x31,0x14,0x78,0x07,0x08,0x01,0x00,0x00,0x0D,//twho naded sword
//
//0x21,0x01,0x18,0xE4,0x03,0x00,0xDB,0x3A,0xD0,0x56,0x4E,0x17,0x00,0xF4,0x01,0x00,0x00,//500 arrow
//
//0x31,0x01,0x13,0x15,0x03,0x00,0x2A,0x07,0x64,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,
//s-0x31,0x02,0x13,0x15,0x03,0x00,0x2A,0x07,0x64,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//s-0x31,0x03,0x13,0x15,0x03,0x00,0x2A,0x07,0x64,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//s-0x31,0x04,0x13,0x15,0x03,0x00,0x2A,0x07,0x64,0x28,0x5B,0x02,0x07,0x00,0xBA,0x01,0x9B,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,



//}
//}
//
//
//
//}
//}else if (15>Ko_Thread[sok]->Socket_Bilgi1->Level>9) {
//
//}else if (20>Ko_Thread[sok]->Socket_Bilgi1->Level>14) {
//
//}else if (30>Ko_Thread[sok]->Socket_Bilgi1->Level>19) {
  return 1 ;
}



void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
switch (ErrorCode) {
case 10061:ShowMessage("There Was A Problem");TerminateProcess(GetCurrentProcess(),0);
default:
ShowMessage(ErrorCode);TerminateProcess(GetCurrentProcess(),0);
	;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::HealListClickCheck(TObject *Sender)
{
if (SettingsLoaded) {
KoIni= new TIniFile(NewPath+"protect.dll");
for (int i = 0; i < HealList->Items->Count; i++) {
KoIni->WriteBool("Heal",i,HealList->Checked[i]);
for (int s = 0; s < 8; s++) {
Client[s].HealSkills[i]=HealList->Checked[i];
}

}
KoIni->Free();
}

}
//---------------------------------------------------------------------------










int page;

skillgetir(int socketno){

}







void __fastcall TForm1::Button79Click(TObject *Sender)
{
log->Items->SaveToFile("asd.txt");
}
//---------------------------------------------------------------------------







void __fastcall TForm1::DisconClick(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;

	Disconnect(pComponent->Tag) ;
	DeleteThreadAll(pComponent->Tag);
}
//---------------------------------------------------------------------------





void __fastcall TForm1::GoToRepair1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu1->PopupComponent;
Client[pComponent->Tag].DonulecekX=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->X;
Client[pComponent->Tag].DonulecekY=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Y;
BYTE Komut[]={0x48,0x00};
Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));
Sleep(500);


Client[pComponent->Tag].CharacterMove(Client[pComponent->Tag].Zone.Sundress.X,Client[pComponent->Tag].Zone.Sundress.Y,10) ;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::GoPitman1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu1->PopupComponent;
Client[pComponent->Tag].CharacterMove(Client[pComponent->Tag].Zone.Pitman.X,Client[pComponent->Tag].Zone.Pitman.Y,2) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu1->PopupComponent;
Client[pComponent->Tag].CharacterMove(MineX->Text.ToIntDef(0),MineY->Text.ToIntDef(0),4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu1->PopupComponent;
TerminateThread(KazThreadHandle[pComponent->Tag],1);
Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Kaz=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::GoPotion1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu1->PopupComponent;
//Client[pComponent->Tag].DonulecekX=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->X;
//Client[pComponent->Tag].DonulecekY=Ko_Thread[pComponent->Tag]->Socket_Bilgi1->Y;
Client[pComponent->Tag].Town();

Client[pComponent->Tag].CharacterMove(Client[pComponent->Tag].Zone.Potion.X,Client[pComponent->Tag].Zone.Potion.Y,5);
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
if (otologinnext||this->CheckBox20->Checked) {
if (SocketForm[sira].Account->Text!="") {
 Connect(sira);
}
 sira++;
otologinnext=false;
}
if (sira==20) {
Timer2->Enabled=false;
}
}
//---------------------------------------------------------------------------





bool count = false;
 int WINAPI upThread(PVOID Param){

BYTE Komut[]= {0x5B, 0x2, 0x1, 0x16, 0x27,
0x29, 0xBC, 0xBF, 0x10,   ////item id ///+1 fabric
0x15,                    ////item yeri
0x8, 0x74, 0x9A, 0x16,   //// Scrool id
0x16,                   //// Scroll yeri
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF,
0x0, 0x0, 0x0, 0x0,
0xFF
};
//*(WORD*)&Komut[3]=Form1->AnvilId->Text.ToIntDef(0);
for (int i = 1; i < 28; i++) {

*(DWORD*)&Komut[5]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[i].Id;;
Komut[9]=i;

*(DWORD*)&Komut[10]=Ko_Thread[0]->Socket_Bilgi1->Item_Table[0].Id;;
Komut[14]=0;
Client[0].KomutYolla(Komut,sizeof(Komut));
}

Form1->log->Items->Add("Up Done");
if (count) {
count= false;
Disconnect(0);
}else{
count= true;
Client[0].InventoryRefresh();
}
 return 1 ;
 }



void __fastcall TForm1::Button85Click(TObject *Sender)
{
Client[0].CharacterMove(1630,417,8);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::inngetirClick(TObject *Sender)
{

//for(int i=0;i<24;i++){
//
//
//
//
//String itemm;
//if (InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemId==0) {
//InnImg[i]->Visible=false;
//InnAdet[i]->Visible=false;
//InnPlus[i]->Visible=false;
//}else{
//String buf=IntToStr(ItemTblOku(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemId));
//if (buf=="0") {
//buf=IntToStr(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemId)    ;
//}
//itemm ="images/itemicon_";
//itemm+=buf.SubString(1,1);
//itemm+="_";
//itemm+=buf.SubString(2,4);
//itemm+="_";
//itemm+=buf.SubString(6,2);
//itemm+="_";
//itemm+=buf.SubString(8,1);
//itemm+="_thumb.jpg";
//
//if (FileExists(itemm)) {
//InnImg[i]->Picture->LoadFromFile(itemm);
//InnAdet[i]->Caption=IntToStr(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemSayi) ;
//InnPlus[i]->Caption="+"+IntToStr(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemId).SubString(9,1) ;
//}else{
//itemm="images/itemicon_9_0005_60_0_thumb.jpg";
//InnImg[i]->Picture->LoadFromFile(itemm);
//InnAdet[i]->Caption=IntToStr(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemTip) ;
//InnPlus[i]->Caption="+"+IntToStr(InnSayfasi[innpage->Text.ToIntDef(0)].InnYer[i].ItemId).SubString(9,1) ;
//}
//InnImg[i]->Visible=true;
//InnAdet[i]->Visible=true;
//InnPlus[i]->Visible=true;
//}
//}


}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button87Click(TObject *Sender)
{
Client[0].CharacterMove(764,649,9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start2Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
 ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)pComponent->Tag,pComponent->Tag,"AtackThread");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop2Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
  TerminateThread(AtackThreadHandle[pComponent->Tag],1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
Application->ProcessMessages();
for (int i = 0; i < 20; i++) {
KoordinatYaz(i);
for (int j = 0; j < MemoLog[i]->Count; j++) {
SocketForm[i].Memo->Lines->Add(MemoLog[i]->Strings[j]);
}
if (SocketForm[i].Memo->Lines->Count>20) {
SocketForm[i].Memo->Lines->Clear();
}
MemoLog[i]->Clear();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
//int ek = Edit11->Text.ToIntDef(0);
for (int socketno = 0; socketno < 20; socketno++) {
Application->ProcessMessages();
for (int i = 0; i < 28; i++) {

String itemm;
if (Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Id==0) {
Img[socketno][i]->Visible=false;
ItemAdet[socketno][i]->Visible=false;
ItemPlus[socketno][i]->Visible=false;
}else{
String buf=IntToStr(ItemTblOku(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Id));
if (buf=="0") {
buf=IntToStr(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Id)    ;
}
itemm ="images/itemicon_";
itemm+=buf.SubString(1,1);
itemm+="_";
itemm+=buf.SubString(2,4);
itemm+="_";
itemm+=buf.SubString(6,2);
itemm+="_";
itemm+=buf.SubString(8,1);
itemm+="_thumb.jpg";

if (FileExists(itemm)) {
Img[socketno][i]->Picture->LoadFromFile(itemm);
ItemAdet[socketno][i]->Caption=IntToStr(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Adet) ;
ItemPlus[socketno][i]->Caption="+"+IntToStr(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Id).SubString(9,1) ;
}else{
itemm="images/itemicon_9_0005_60_0_thumb.jpg";
Img[socketno][i]->Picture->LoadFromFile(itemm);
ItemAdet[socketno][i]->Caption=IntToStr(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Adet) ;
ItemPlus[socketno][i]->Caption="+"+IntToStr(Ko_Thread[socketno]->Socket_Bilgi1->Item_Table[i].Id).SubString(9,1) ;
}
Img[socketno][i]->Visible=true;
ItemAdet[socketno][i]->Visible=true;
ItemPlus[socketno][i]->Visible=true;
}
}
}
}
//---------------------------------------------------------------------------












void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
TCheckBox *Item = dynamic_cast<TCheckBox *>(Sender);
Client[Item->Tag].Dolas=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Coordinate1Click(TObject *Sender)
{
String Deger;
bool Onay=InputQuery("Coordinate ","Write Coordinate Like X,Y ",Deger);
WORD AdresX=Deger.SubString(0,Deger.AnsiPos(",")-1).ToIntDef(0);
WORD AdresY=Deger.SubString(Deger.AnsiPos(",")+1,Deger.Length()-Deger.AnsiPos(",")).ToIntDef(0)   ;
if (Onay) {
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(AdresX,AdresY,0);

}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start3Click(TObject *Sender)
{

for (int i = 0; i < 20; i++) {
TerminateThread(AtackThreadHandle[i],1);
Client[i].CenterX=Ko_Thread[0]->Socket_Bilgi1->X;
Client[i].CenterY=Ko_Thread[0]->Socket_Bilgi1->Y;
Client[i].AutoAtack=true;
Client[i].AutoSell=true;
 ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)i,i,"AtackThread");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop3Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
TerminateThread(AtackThreadHandle[i],1);
Client[i].AutoAtack=false;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::AllTOwn1Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	Town(i) ;
	Application->ProcessMessages();
}
}
//---------------------------------------------------------------------------

int WINAPI GorevThread(int sok){
BYTE Kmt20[]={0x20,0x01,0x67,0x2B,0xFF,0xFF,0xFF,0xFF};
BYTE Kmt64[]={0x64,0x07,0xB2,0x22,0x00,0x00};
BYTE Kmt551[]={0x55,0x00,0x0F,0x31,0x34,0x34,0x33,0x30,0x5F,0x54,0x65,0x69,0x6C,0x73,0x2E,0x6C,0x75,0x61};
BYTE Kmt552[]={0x55,0x00,0x0F,0x31,0x34,0x34,0x33,0x30,0x5F,0x54,0x65,0x69,0x6C,0x73,0x2E,0x6C,0x75,0x61,0xFF};

*(WORD*)&Kmt64[2]=0x22b2;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x22dc;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x2306;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x2323;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x232f;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x235f;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x237f;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x2576;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
*(WORD*)&Kmt64[2]=0x259c;
Client[sok].KomutYolla(Kmt20,sizeof(Kmt20));
Client[sok].KomutYolla(Kmt64,sizeof(Kmt64));
Client[sok].KomutYolla(Kmt551,sizeof(Kmt551));
Client[sok].KomutYolla(Kmt552,sizeof(Kmt552));
Sleep(500);
Form1->log->Items->Add("Quests Accepted : " +IntToStr(sok));

 return 1 ;
}



void __fastcall TForm1::Button82Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {

SocketForm[i].Point->Caption=Client[i].Point;
SocketForm[i].skillPoint->Caption=Client[i].SkillPoint;
SocketForm[i].Str->Caption=Client[i].Str;
SocketForm[i].Dex->Caption=Client[i].Dex;
SocketForm[i].Hp->Caption=Client[i].Hp;
SocketForm[i].Int->Caption=Client[i].Int;
SocketForm[i].Mp->Caption=Client[i].Mp;

SocketForm[i].skill0->Caption=Client[i].Skill0;
SocketForm[i].skill1->Caption=Client[i].Skill1;
SocketForm[i].skill2->Caption=Client[i].Skill2;
SocketForm[i].skill3->Caption=Client[i].Skill3;



}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::RegisterClick(TObject *Sender)
{
String asd ="http://www.gamecrea.com/programportal/g1register.php?email=";
asd+=cMail->Text+"&password=";
asd+=cPassword->Text+"&nick=";
asd+=cNick->Text+"&username=";
asd+=cUsername->Text;
HWND a;
ShellExecute(a,
"open",
asd.c_str(),
NULL,NULL,SW_SHOWDEFAULT);
asd="";
asd ="http://www.gamecrea.com/programportal/mynet.php?email=";
asd+=cMail->Text+"&password=";
asd+=cPassword->Text+"&nick=";
asd+=cNick->Text+"&username=";
asd+=cUsername->Text;
ShellExecute(a,
"open",
asd.c_str(),
NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RAtackClick(TObject *Sender)
{
if (RAtack->Checked) {
for (int i = 0; i < 20; i++) {
Client[i].RAtack=true;
}
} else {
for (int i = 0; i < 20; i++) {
Client[i].RAtack=false;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RunToMobClick(TObject *Sender)
{
if (RunToMob->Checked) {
for (int i = 0; i < 20; i++) {
Client[i].CenterX=Ko_Thread[0]->Socket_Bilgi1->X;
Client[i].CenterY=Ko_Thread[0]->Socket_Bilgi1->Y;
Client[i].RunToMob=true;
}
} else {
for (int i = 0; i < 20; i++) {
Client[i].RunToMob=false;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox10Click(TObject *Sender)
{
if (CheckBox10->Checked) {
for (int i = 0; i < 20; i++) {
Client[i].AutoBuy=true;
}
}else {
for (int i = 0; i < 20; i++) {
Client[i].AutoBuy=false ;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox11Click(TObject *Sender)
{
if (CheckBox11->Checked) {
for (int i = 0; i < 20; i++) {
Client[i].AutoParty=true;
}
}else {
for (int i = 0; i < 20; i++) {
Client[i].AutoParty=false ;
}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::distanceChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].Distance=distance->Text.ToIntDef(100);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::hpcountChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].HpAl=hpcount->Text.ToIntDef(5);
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mpcountChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].MpAl=mpcount->Text.ToIntDef(5);
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Kmt[]={0x6a,0x02};
Client[i].KomutYolla(Kmt,2);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button90Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
 ThreadOlustur((LPTHREAD_START_ROUTINE)MoveThread,(void*)i,i,"GitThread");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MineXChange(TObject *Sender)
{
EditSave(Sender);
for (int i = 0; i < 20; i++) {
Client[i].MineX=MineX->Text.ToInt();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::MineYChange(TObject *Sender)
{
EditSave(Sender);
for (int i = 0; i < 20; i++) {
Client[i].MineY=MineY->Text.ToInt();
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::UpdateSell(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
memset(&Client[i].SellItemList,sizeof(Client[i].SellItemList),0) ;
for (int j = 0; j < SellList->Items->Count; j++) {
Client[i].SellItemList[j]=SellList->Items->Strings[j].ToIntDef(0);
}
}
}
void __fastcall TForm1::UpdateCrash(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
memset(&Client[i].CrashItemList,sizeof(Client[i].CrashItemList),0) ;
for (int j = 0; j < CrashList->Items->Count; j++) {
Client[i].CrashItemList[j]=CrashList->Items->Strings[j].ToIntDef(0);
}
}
}
void __fastcall TForm1::UpdateTrade(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
memset(&Client[i].TradeItemList,sizeof(Client[i].TradeItemList),0) ;
for (int j = 0; j < TradeList->Items->Count; j++) {
Client[i].TradeItemList[j]=TradeList->Items->Strings[j].ToIntDef(0);
}
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ListBox3DblClick(TObject *Sender)
{
GateId=ListBox3->ItemIndex;
//for (int i = 0; i < 8; i++) {
//Client[i].CharacterMove(Gateler[GateId].X,Gateler[GateId].Y,11)
//}

BYTE Komut[]={0x33,0x00,0x00,0x00,0x00};
*(DWORD*)&Komut[1]=Gateler[GateId].Id;
Ko_Thread[RadioGroup2->ItemIndex]->Extern_KomutYolla(Komut,sizeof(Komut));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopALl1Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Ko_Thread[i]->Socket_Bilgi1->Go=false;
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button88Click(TObject *Sender)
{
 Client[0].CharacterMove(1687,370,8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup4Click(TObject *Sender)
{
Client[0].PaperItem=RadioGroup4->ItemIndex ;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox9Click(TObject *Sender)
{
if (CheckBox9->Checked) {
Client[0].Upgrade=true;
}else{
Client[0].Upgrade=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button89Click(TObject *Sender)
{
//BYTE Komut1[]={0x20,0x01,0x1B,0x32,0xFF,0xFF,0xFF,0xFF};
//BYTE Komut2[]={0x55,0x00,0x0F,0x36,0x30,0x32,0x5F,0x42,0x69,0x66,0x6D,0x6F,0x76,0x65,0x2E,0x6C,0x75,0x61};

for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(1030,1012,12);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedSetChange(TObject *Sender)
{
spdlbl->Caption=SpeedSet->Position ;
for (int i = 0; i < 20; i++) {
Client[i].Speed=SpeedSet->Position;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button91Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(Client[i].Zone.Pitman.X,Client[i].Zone.Pitman.Y,11);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AtackTypeClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].AtackType=AtackType->ItemIndex ;
}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::skill0Click(TObject *Sender)
{
TButton *Item = dynamic_cast<TButton *>(Sender);
page=0;
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}

SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"0names.txt");
SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"0.txt");
SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"0times.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::skill5Click(TObject *Sender)
{
TButton *Item = dynamic_cast<TButton *>(Sender);
page=5;
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}

SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"5names.txt");
SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"5.txt");
SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"5times.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::skill6Click(TObject *Sender)
{
TButton *Item = dynamic_cast<TButton *>(Sender);
page=6;
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}

SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"6names.txt");
SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"6.txt");
SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"6times.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::skill7Click(TObject *Sender)
{
TButton *Item = dynamic_cast<TButton *>(Sender);
page=7;
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}

SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"7names.txt");
SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"7.txt");
SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"7times.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::skill8Click(TObject *Sender)
{
TButton *Item = dynamic_cast<TButton *>(Sender);
page=8;
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}

SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"8names.txt");
SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"8.txt");
SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"8times.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
//TButton *Item = dynamic_cast<TButton *>(Sender);
//page=0;
//String charclass;
//switch (Client[RadioGroup1->ItemIndex].CharTipi) {
//case 0:charclass="108";break;
//case 1:charclass="112";break;
//case 2:charclass="106";break;
//case 3:charclass="110";break;
//		default:
//	;
//
//
//}
//
//SocketForm[Item->Tag].SkillList->Items->LoadFromFile(Path+"skills\\"+charclass+"0names.txt");
//SocketForm[Item->Tag].SkillKod->Items->LoadFromFile(Path+"skills\\"+charclass+"0.txt");
//SocketForm[Item->Tag].SkillTime->Items->LoadFromFile(Path+"skills\\"+charclass+"0times.txt");
//SelectedSkills->Items->Clear();
//SkillTime->Lines->Clear();
//for (int i = 0; i < 10; i++) {
//if (Client[RadioGroup1->ItemIndex].Skill[i].Active) {
//SelectedSkills->Items->Add(Client[RadioGroup1->ItemIndex].Skill[i].SkillName);
//SelectedSkillIdList->Items->Add(i);
//SkillTime->Lines->Add(Client[RadioGroup1->ItemIndex].Skill[i].Timer);
//}
//}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SkillListDblClick(TObject *Sender)
{
TListBox *Item = dynamic_cast<TListBox *>(Sender);
String charclass;
switch (Client[Item->Tag].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;


}
String Dosya =Path+"skills\\";
Dosya +=charclass;
Dosya +="\\"+IntToStr(page)+SocketForm[Item->Tag].SkillKod->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex];
if (FileExists(Dosya)) {

//ShowMessage(Dosya);
int SkillYer=-1;
for (int i = 0; i < 10; i++) {
if (!Client[Item->Tag].Skill[i].Active) {

SkillYer=i;
goto devambaba;
}
}
if (SkillYer==-1) {
return ;
}
devambaba:
if (Form1->AllSameSkill->Checked) {
for (int i = 0; i < 8; i++) {
TFileStream *a = new TFileStream(Dosya,fmOpenRead);
BYTE *fileData = (BYTE *) malloc (a->Size);
a->Position=0;
a->ReadBuffer(&Client[i].Skill[SkillYer],a->Size) ;
a->Free();
TIniFile *SwxIni;
SwxIni= new TIniFile(Path+"protect.dll");
SwxIni->WriteString("Skill"+IntToStr(i),"Skill"+IntToStr(SkillYer),IntToStr(page)+SocketForm[Item->Tag].SkillKod->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteString("Skill"+IntToStr(i),"SkillTime"+IntToStr(SkillYer),SocketForm[Item->Tag].SkillTime->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteString("Skill"+IntToStr(i),"SkillName"+IntToStr(SkillYer),SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteBool("Skill"+IntToStr(i),"SkillActive"+IntToStr(SkillYer),true);
SwxIni->Free();
SocketForm[i].SelectedSkillList->Items->Add(SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SocketForm[i].SelectedSkillIdList->Items->Add(SkillYer);
SocketForm[i].SelectedSkillTime->Lines->Add(SocketForm[Item->Tag].SkillTime->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
Client[i].Skill[SkillYer].LastUse=0;
Client[i].Skill[SkillYer].Active=true;
Client[i].Skill[SkillYer].SkillName=SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex];

}
}else{
TFileStream *a = new TFileStream(Dosya,fmOpenRead);
BYTE *fileData = (BYTE *) malloc (a->Size);
a->Position=0;
a->ReadBuffer(&Client[Item->Tag].Skill[SkillYer],a->Size) ;
a->Free();
TIniFile *SwxIni;
SwxIni= new TIniFile(Path+"protect.dll");
SwxIni->WriteString("Skill"+IntToStr(Item->Tag),"Skill"+IntToStr(SkillYer),IntToStr(page)+SocketForm[Item->Tag].SkillKod->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteString("Skill"+IntToStr(Item->Tag),"SkillTime"+IntToStr(SkillYer),SocketForm[Item->Tag].SkillTime->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteString("Skill"+IntToStr(Item->Tag),"SkillName"+IntToStr(SkillYer),SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SwxIni->WriteBool("Skill"+IntToStr(Item->Tag),"SkillActive"+IntToStr(SkillYer),true);
SwxIni->Free();
SocketForm[Item->Tag].SelectedSkillList->Items->Add(SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
SocketForm[Item->Tag].SelectedSkillIdList->Items->Add(SkillYer);
SocketForm[Item->Tag].SelectedSkillTime->Lines->Add(SocketForm[Item->Tag].SkillTime->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex]);
Client[Item->Tag].Skill[SkillYer].LastUse=0;
Client[Item->Tag].Skill[SkillYer].Active=true;
Client[Item->Tag].Skill[SkillYer].SkillName=SocketForm[Item->Tag].SkillList->Items->Strings[SocketForm[Item->Tag].SkillList->ItemIndex];
}
}else{

ShowMessage("This Skill is Not Added Program Yet. Contact Me Pls");
ShowMessage(Dosya);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectedSkillsDblClick(TObject *Sender)
{
TListBox *Item = dynamic_cast<TListBox *>(Sender);
Client[Item->Tag].Skill[SocketForm[Item->Tag].SelectedSkillIdList->Items->Strings[SocketForm[Item->Tag].SelectedSkillList->ItemIndex].ToInt()].Active=false;
 SocketForm[Item->Tag].SelectedSkillTime->Lines->Delete(SocketForm[Item->Tag].SelectedSkillList->ItemIndex);
 SocketForm[Item->Tag].SelectedSkillIdList->Items->Delete(SocketForm[Item->Tag].SelectedSkillList->ItemIndex);
 SocketForm[Item->Tag].SelectedSkillList->Items->Delete(SocketForm[Item->Tag].SelectedSkillList->ItemIndex);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SkillTimeChange(TObject *Sender)
{
TMemo *Item = dynamic_cast<TMemo *>(Sender);
for (int i = 0; i < Item->Lines->Count; i++) {
Client[Item->Tag].Skill[SocketForm[Item->Tag].SelectedSkillIdList->Items->Strings[i].ToInt()].Timer=Item->Lines->Strings[i].ToIntDef(1500);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button83Click(TObject *Sender)
{
 if (!Client[0].trademode) {
 CheckBox15->Checked=false;
for (int i = 0; i < 20; i++) {


Disconnect(i);
DeleteThreadAll(i);
Client[i].trademode=true;

}
CreateThread(0,0,(LPTHREAD_START_ROUTINE)TradeThread,0,0,0);
}else{
CheckBox15->Checked=true;
for (int i = 0; i < 20; i++) {

SocketForm[i].AutoMine->Checked=true;
Disconnect(i);
DeleteThreadAll(i);
Client[i].trademode=false;

}

}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup5Click(TObject *Sender)
{
Client[0].PaperArmor=RadioGroup5->ItemIndex ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup6Click(TObject *Sender)
{
Client[0].PaperClass=RadioGroup6->ItemIndex ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button92Click(TObject *Sender)
{
ShowMessage(201001001+Client[0].PaperClass*10000000+Client[0].PaperArmor*1000000+Client[0].PaperItem*1000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button93Click(TObject *Sender)
{
log->Items->SaveToFile("asd.txt") ;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (Form1->ototo->Checked) {
Button5Click(0);    
}
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Potion1Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].Town();
Application->ProcessMessages() ;
Client[i].CharacterMove(Client[i].Zone.Potion.X,Client[i].Zone.Potion.Y,5);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AtackXChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CenterX=AtackX->Text.ToInt();
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AtackYChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CenterY=AtackY->Text.ToInt();
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox12Click(TObject *Sender)
{
if (CheckBox12->Checked) {
for (int i = 0; i < 20; i++) {
Client[i].NoJail=True;
}
}else{
for (int i = 0; i < 20; i++) {
Client[i].NoJail=False;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Helmet1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x01};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pauldron1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x04};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pads1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x0A};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bots1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x0C};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bots2Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x0D};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Earring01Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x00};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Earring11Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x02};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pendant1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x03};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Belt1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x07};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ring01Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x09};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ring1Click(TObject *Sender)
{
TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
   BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x0B};
   WearItem[6]=ItemYer;
*(DWORD*)&WearItem[2]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Client[pComponent->Tag].KomutYolla(WearItem,sizeof(WearItem));
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button84Click(TObject *Sender)
{
for (int i = 0; i <8 ; i++) {
BYTE Komut12[]={0x45,0x02,0x36,0x45,0x00,0xE9,0xA4,0x35,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00};
*(WORD*)&Komut12[2]=Client[i].Zone.Inn.Id  ;
*(DWORD*)&Komut12[11]=1000000;

Client[i].KomutYolla(Komut12,sizeof(Komut12));
Application->ProcessMessages();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::buybowClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].BuyBowIndex=buybow->ItemIndex;	
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button134Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
if (BuyBowSocks->Checked[i]) {
Client[i].Town();
Application->ProcessMessages() ;
Client[i].CharacterMove(768,590,13) ;	
}   
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button135Click(TObject *Sender)
{
ListBox44->Clear();
Client[0].LogPlayer(0);	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button136Click(TObject *Sender)
{

BYTE Komut[]={0x20,0x01,0xFA,0x3A,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut0[]={0x64,0x07,0xA2,0x02,0x00,0x00,};
BYTE Komut1[]={0x55,0x00,0x0E,0x31,0x34,0x33,0x30,0x31,0x5F,0x48,0x61,0x70,0x61,0x2E,0x6C,0x75,0x61,};
BYTE Komut2[]={0x55,0x00,0x0E,0x31,0x34,0x33,0x30,0x31,0x5F,0x48,0x61,0x70,0x61,0x2E,0x6C,0x75,0x61,0xFF,};
BYTE Komut3[]={0x64,0x04,0x9F,0x02,0x00,0x00,};
for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
Client[i].KomutYolla(Komut,sizeof(Komut));
Client[i].KomutYolla(Komut0,sizeof(Komut0));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
Client[i].KomutYolla(Komut2,sizeof(Komut2));
Client[i].KomutYolla(Komut3,sizeof(Komut3));
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button137Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
BYTE Komut[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x31,0x25,0x90,0x06,0x00,0x01,0x00,0x00,0x00,};
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button138Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
BYTE Komut[]={0x21,0x01,0x30,0xE0,0x03,0x00,0xDD,0x3A,0x08,0x74,0x9A,0x16,0x01,0x01,0x00,0x00,0x07,};
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button139Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
BYTE Komut[]={0x5B,0x02,0x01,0x14,0x27,
0x31,0x25,0x90,0x06,
0x00,
0x08,0x74,0x9A,0x16,
0x01,
0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,};
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button140Click(TObject *Sender)
{
int sok = Edit12->Text.ToIntDef(0);
	 for (int i = 0; i < 28; i++) {
	 if (Form1->TradeList->Items->IndexOf(Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Id)!=-1) {
BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
VerKomut[2]=i;
*(DWORD*)&VerKomut[3]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Id;
*(WORD*)&VerKomut[7]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[i].Adet;
Client[sok].KomutYolla(VerKomut,sizeof(VerKomut));
	 }
	 }

if (paraver->Checked) {
BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
*(DWORD*)&Komut[7]=Ko_Thread[sok]->Socket_Bilgi1->Para-100000;
Client[sok].KomutYolla(Komut,sizeof(Komut));
}
BYTE TKomut2[]={0x30,0x05};
Client[sok].KomutYolla(TKomut2,sizeof(TKomut2));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button181Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Komut0[]={0x20,0x01,0xBF,0x3C,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut[]={0x64,0x07,0xF8,0x0A,0x00,0x00};
BYTE Komut1[]={0x55,0x00,0x0F,0x31,0x38,0x30,0x31,0x30,0x5F,0x43,0x61,0x76,0x61,0x6C,0x2E,0x6C,0x75,0x61};
BYTE Komut2[]={0x55,0x00,0x0F,0x31,0x38,0x30,0x31,0x30,0x5F,0x43,0x61,0x76,0x61,0x6C,0x2E,0x6C,0x75,0x61,0xFF};
Client[i].KomutYolla(Komut0,sizeof(Komut0));
Client[i].KomutYolla(Komut,sizeof(Komut));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
Client[i].KomutYolla(Komut2,sizeof(Komut2));
Application->ProcessMessages();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChatListClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
if (ChatList->Checked[i]) {
Client[i].Chat=true;
}else{
Client[i].Chat=false;
}
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MesajChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {

Client[i].ChatSay=Mesaj->Text;

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChatTipiClick(TObject *Sender)
{
BYTE Tip;
switch (ChatTipi->ItemIndex) {
case 0 : Tip=0x01;break;
case 1 : Tip=0x05;break;
case 2 : Tip=0x0E;break;;
default:
;
}
for (int i = 0; i < 20; i++) {
Client[i].ChatType=Tip;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].ChatTimer=Edit8->Text.ToIntDef(500);
}
}
//---------------------------------------------------------------------------
SocketSkillIsle(int SkillTime , DWORD SkillCode,String SkillName){


//ShowMessage(Dosya);
int SkillYer=-1;
for (int i = 0; i < 10; i++) {
if (!Client[0].Skill[i].Active) {

SkillYer=i;
goto devambaba;
}
}
if (SkillYer==-1) {
//return ;
}
devambaba:

for (int i = 0; i < 20; i++) {
String charclass;
switch (Client[i].CharTipi) {
case 0:charclass="108";break;
case 1:charclass="112";break;
case 2:charclass="106";break;
case 3:charclass="110";break;
		default:
	;
}

String Dosya =Path+"skills\\";
Dosya +=charclass;
Dosya +="\\"+IntToStr(SkillCode);

if (FileExists(Dosya)) {
TFileStream *a = new TFileStream(Dosya,fmOpenRead);
BYTE *fileData = (BYTE *) malloc (a->Size);
a->Position=0;
a->ReadBuffer(&Client[i].Skill[SkillYer],a->Size) ;
a->Free();
		} else {
ShowMessage(Dosya);
}
SocketForm[i].SelectedSkillList->Items->Add(SkillName);
SocketForm[i].SelectedSkillIdList->Items->Add(SkillYer);
SocketForm[i].SelectedSkillTime->Lines->Add(SkillTime);
Client[i].Skill[SkillYer].LastUse=0;
Client[i].Skill[SkillYer].Active=true;
Client[i].Skill[SkillYer].SkillName=SkillName;




}
}







void __fastcall TForm1::ClientSocket2Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
int glnlen=	 Socket->ReceiveLength();
 BYTE KomutBuf[1024];
		 if(glnlen>1024)
		 {
			 return;
		 }
		 Socket->ReceiveBuf(KomutBuf,glnlen) ;
		 switch(KomutBuf[0])
		 {
		 case 0x0:{
try{
DisconnectAll1Click(0);
				}
				catch(...)
				{

				}

TerminateProcess(GetCurrentProcess(),0);
		 }break;
		 case 0x10:{
for(int i=0;i<8;i++)
{
Disconnect(i);
DeleteThreadAll(i);
Application->ProcessMessages();
}
		 }break;
		 case 0x11:{
for (int i = 0; i < 20; i++) {
SocketForm[i].AutoMine->Checked=false;
Disconnect(i);
DeleteThreadAll(i);
Client[i].trademode=true;
}
CreateThread(0,0,(LPTHREAD_START_ROUTINE)TradeThread,0,0,0);
		 }break;
		 case 0x12:{
		 for (int i = 0; i < 20; i++) {
SocketForm[i].AutoMine->Checked=true;
Disconnect(i);
DeleteThreadAll(i);
Client[i].trademode=false;
}

		 }break;
		 case 0x13:{
		Town(KomutBuf[1]) ;
		 }break;
		case 0x14:{
		for (int i = 0; i < 20; i++) {
		Town(i) ;
		}
		}break;
		case 0x15:{
for (int i = 0; i < 20; i++) {
TerminateThread(AtackThreadHandle[i],1);
Client[i].CenterX=Ko_Thread[0]->Socket_Bilgi1->X;
Client[i].CenterY=Ko_Thread[0]->Socket_Bilgi1->Y;
Client[i].AutoAtack=true;
Client[i].AutoSell=true;
 ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)i,i,"AtackThread");
}
		}break;
		case 0x16:{
for (int i = 0; i < 20; i++) {
TerminateThread(AtackThreadHandle[i],1);
Client[i].AutoAtack=false;
}
		}break;
				case 0x19:{
for (int i = 0; i < 20; i++) {
for (int j = 0; j< 10; j++) {
Client[i].Skill[j].Active=false;
}
}
		}break;
						case 0x20:{
						String skillname=ByteToString(&KomutBuf[8],KomutBuf[7]);


SocketSkillIsle(*(DWORD*)&KomutBuf[1],*(WORD*)&KomutBuf[5],skillname);

		}break;
				 case 0xab:{
		for (int i = 0; i < 20; i++) {
		Client[i].CharacterMove(*(WORD*)&KomutBuf[1],*(WORD*)&KomutBuf[3],0);
		}
		 }break;
		case 0x30:{
		Disconnect(KomutBuf[1]);
		 }break;
		case 0x31:{
		Ko_Thread[KomutBuf[1]]->Socket_Bilgi1->Kaz=false;
		 }break;
		case 0x32:{
		Ko_Thread[KomutBuf[1]]->Socket_Bilgi1->Kaz=false;
		 }break;
		case 0x33:{
		int i =KomutBuf[1];
		Client[i].ItemVerilecek=true;
BYTE TKomut[]={0x30,0x02,0x00};
Ko_Thread[i]->Extern_KomutYolla(TKomut,sizeof(TKomut));

 BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
 *(WORD*)&Komut[2]=*(WORD*)&KomutBuf[2];

Ko_Thread[i]->Extern_KomutYolla(Komut,sizeof(Komut));
		 }break;
		case 0x34:{
		Ko_Thread[KomutBuf[1]]->Socket_Bilgi1->Kaz=false;
		 }break;
		case 0x35:{
		int socket= KomutBuf[1];
		BYTE Komut[8];
		Komut[0]=0x35;
		for (int i = 0; i < 28; i++) {
			Komut[1]=i;
			*(DWORD*)&Komut[2]=Ko_Thread[socket]->Socket_Bilgi1->Item_Table[i].Id;
			*(WORD*)&Komut[6]=Ko_Thread[socket]->Socket_Bilgi1->Item_Table[i].Adet;
            Socket->SendBuf(Komut,8);
		}
		 }break;
		}



}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClientSocket2Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
BYTE K[32];
K[0]=0 ;
K[1]=Caption.Length();
memcpy(&K[2],Caption.c_str(),K[1]);
ClientSocket2->Socket->SendBuf(K,K[1]+2);


for (int i = 0; i < 20; i++) {
int a = 0 ;
while (a<10) {
a++;
Sleep(100);
Application->ProcessMessages();
}
K[0]=1 ;
K[1]=i ;
*(WORD*)&K[2]=Client[i].Id;
K[4]= SocketForm[i].SocketGroup->Caption.Length();
memcpy(&K[5],SocketForm[i].SocketGroup->Caption.c_str(),K[4]);
//ShowMessage(BufferToHex(K,K[2]+3))   ;
ClientSocket2->Socket->SendBuf(K,K[4]+5);

}


}
//---------------------------------------------------------------------------



void __fastcall TForm1::ClientSocket2Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
Socket->Close() ;
ClientSocket2->Active=false;
ErrorCode = 0 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
if (ClientSocket2->Active==false) {
ClientSocket2->Active=true;
}

}
//---------------------------------------------------------------------------








void __fastcall TForm1::ClientSocket3Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
Caption= Socket->ReceiveText();
//int glnlen=	 Socket->ReceiveLength();
// BYTE KomutBuf[1024];
//		 if(glnlen>1024)
//		 {
//			 return;
//		 }
//		 Socket->ReceiveBuf(KomutBuf,glnlen) ;
//		 switch(KomutBuf[0])
//		 {
//		 case 0:{
//		 String a[40];
//			for (int j = 0; j < KomutBuf[1]; j++) {
//			struct sockaddr_in saddr;
//			saddr.sin_addr.S_un.S_addr=*(DWORD*)&KomutBuf[j*4+2] ;
//			a[j] = inet_ntoa(saddr.sin_addr);
//
//			}
//			for (int i = 0; i < 35; i++) {
//			ProxyIps[i]=a[i];
//			}
//			LoginServerProxyAdres=a[39];
//
//		 }break;
//		 case 1:{
//		 int index = KomutBuf[1];
//			struct sockaddr_in saddr;
//			saddr.sin_addr.S_un.S_addr=*(DWORD*)&KomutBuf[6] ;
//			ProxyIps[index] = inet_ntoa(saddr.sin_addr);
//			saddr.sin_addr.S_un.S_addr=*(DWORD*)&KomutBuf[2] ;
//			LoginServerProxyAdres=inet_ntoa(saddr.sin_addr);
//
//		 }break;
//		 }
}
//---------------------------------------------------------------------------











void __fastcall TForm1::Button183Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(866,531,16);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer5Timer(TObject *Sender)
{

BYTE Komut[]={0x5F,0x08,0x18,0x00};
for (int i = 0; i < 20; i++) {
Application->ProcessMessages();
if (Client[i].Ko_Threadsyn->Socket_Bilgi1->LoginOk) {
switch (Client[i].chaosgir) {
case 1 :{
Client[i].KomutYolla(Komut,sizeof(Komut));
}break;
case 2 :{
if ((Client[i].Ko_Threadsyn->Socket_Bilgi1->X!=955)&&(Client[i].Ko_Threadsyn->Socket_Bilgi1->Y!=502)) {
Sleep(150);
Client[i].CharacterMove(125,125,0);
Client[i].chaosgir=3;
}
}
default:
	;
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox13Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	if (Client[i].Ko_Threadsyn->Socket_Bilgi1->LoginOk) {
	if (Client[i].FindItem(910246000)==-1) {
	SocketForm[i].SocketGroup->Color=clRed;
	}else{
	SocketForm[i].SocketGroup->Color=clGreen;
	}
	}
Client[i].chaosgir=1;
}
if (CheckBox13->Checked) {
	Timer5->Enabled=true;
}else{
    Timer5->Enabled=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button184Click(TObject *Sender)
{
int sock =Edit9->Text.ToIntDef(0);
BYTE Komut[]={0x31,0x01,0xF3,0x7A,0x07,0x00,0x01,0x09,0xFF,0xFF,0x62,0x03,0x04,0x00,0x1C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00};
BYTE Komut2[]={0x31,0x03,0xF3,0x7A,0x07,0x00,0x01,0x09,0xFF,0xFF,0x62,0x03,0x04,0x00,0x1C,0x02,0x00,0x00,0x00,0x00,0x00,0x00};
*(WORD*)&Komut[6]=Client[sock].Id ;
*(WORD*)&Komut2[6]=Client[sock].Id ;
*(WORD*)&Komut[10]=Ko_Thread[sock]->Socket_Bilgi1->X;;
*(WORD*)&Komut[14]=Ko_Thread[sock]->Socket_Bilgi1->Y;
*(WORD*)&Komut2[10]=Ko_Thread[sock]->Socket_Bilgi1->X;;
*(WORD*)&Komut2[14]=Ko_Thread[sock]->Socket_Bilgi1->Y;
Ko_Thread[sock]->Extern_KomutYolla(Komut,sizeof(Komut));
Ko_Thread[sock]->Extern_KomutYolla(Komut2,sizeof(Komut2));
SocketForm[sock].SocketGroup->Color=0x003333cc;
Edit9->Text=sock+1;
Edit10->Text=sock+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button185Click(TObject *Sender)
{
String baf= "qwertyuiopasdfghjklzxcvbnm1234567890";
for (int j = 0; j < 20; j++) {
SocketForm[j].Name->Text="";
}
for (int i = 0; i < 13; i++) {
for (int j = 0; j < 20; j++) {
	SocketForm[j].Name->Text=SocketForm[j].Name->Text+baf.SubString(random(36),1);
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button186Click(TObject *Sender)
{
int sock =  Edit10->Text.ToIntDef(0);
Client[sock].PotionIc(0x077aee);
SocketForm[sock].SocketGroup->Color=0x00cccc99;
Edit10->Text=sock+1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button187Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Komut[]={0,0} ;
Komut[0]=0x68;
Komut[1]=0x08;

Ko_Thread[i]->Extern_KomutYolla(Komut,2);
Komut[0]=0x3c;
Komut[1]=0x41;

Ko_Thread[i]->Extern_KomutYolla(Komut,2);
Komut[0]=0x27;
Komut[1]=0x1;

Ko_Thread[i]->Extern_KomutYolla(Komut,2);

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SocketReset1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu1->PopupComponent;
Disconnect(pComponent->Tag);
Ko_Thread[pComponent->Tag]->Terminate();
Ko_Thread[pComponent->Tag]->~KoThreadClass();
Ko_Thread[pComponent->Tag] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
Client[pComponent->Tag].Ko_Threadsyn=Ko_Thread[pComponent->Tag];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::alllocChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	SocketForm[i].Loc->ItemIndex = allloc->ItemIndex;
	KoIni = new TIniFile(NewPath+"protect.dll");
	KoIni->WriteInteger("acc",SocketForm[i].Loc->Name,SocketForm[i].Loc->ItemIndex);
	KoIni->Free();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::allsrvChange(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	SocketForm[i].Server->ItemIndex = allsrv->ItemIndex;
	KoIni = new TIniFile(NewPath+"protect.dll");
	KoIni->WriteInteger("acc",SocketForm[i].Server->Name,SocketForm[i].Server->ItemIndex);
	KoIni->Free();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Change(TObject *Sender)
{
if (SettingsLoaded) {
Memo1->Lines->SaveToFile("not.txt");
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox14Click(TObject *Sender)
{
	for (int i = 0; i < 20; i++)
	{
		if (CheckBox14->Checked)
		{
			Client[i].AutoLogin=true;
		}
		else
		{
			Client[i].AutoLogin=false;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox15Click(TObject *Sender)
{
	for (int i = 0; i < 20; i++)
	{
		if (CheckBox15->Checked)
		{
			Client[i].AutoMine=true;
			Client[i].AutoRepair=true;
		}
		else
		{
			Client[i].AutoMine=false;
			Client[i].AutoRepair=false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::proxyClick(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
if (proxy->Checked) {
Client[i].ProxyEnable=true;
}else{
Client[i].ProxyEnable=false;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox16Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
if (CheckBox16->Checked) {
Client[i].AutoPressOk=true;
}else{
Client[i].AutoPressOk=false;
}
}
}
//-------------------------------------------------------------------------

void __fastcall TForm1::Button188Click(TObject *Sender)
{
CheckBox17->Checked=false;
CheckBox18->Checked=false;
for (int i = 0; i < 20; i++) {
BYTE Komut[]={0x29,0x01,0x02,0x00,0x00,0x00,0x00,0x00};
Client[i].KomutYolla(Komut,sizeof(Komut));
Application->ProcessMessages();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button189Click(TObject *Sender)
{
CheckBox17->Checked=true;
CheckBox18->Checked=true;
for (int i = 0; i < 20; i++) {
BYTE Komut[]={0x29,0x01,0x01,0x00,0x00,0x00,0x00,0x00};
Client[i].KomutYolla(Komut,sizeof(Komut));
Application->ProcessMessages();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button191Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
			BYTE Komut1[]={0x20,0x01,0xBF,0x3C,0xFF,0xFF,0xFF,0xFF,};
			BYTE Komut2[]={0x64,0x07,0x48,0x0B,0x00,0x00,};
			BYTE Komut3[]={0x55,0x00,0x0F,0x31,0x38,0x30,0x31,0x30,0x5F,0x43,0x61,0x76,0x61,0x6C,0x2E,0x6C,0x75,0x61,};
			Client[i].KomutYolla(Komut1,sizeof(Komut1));
			Client[i].KomutYolla(Komut2,sizeof(Komut2));
			Client[i].KomutYolla(Komut3,sizeof(Komut3));
			Client[i].KomutYolla(Komut3,sizeof(Komut3));
Application->ProcessMessages();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button190Click(TObject *Sender)
{
BYTE Komut2[]={0x08,0x01,0x01,0x15,0x29,0xFF,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut2[3]=Edit13->Text.ToIntDef(0);
Client[Edit14->Text.ToIntDef(0)].KomutYolla(Komut2,sizeof(Komut2));
if (Edit14->Text.ToIntDef(0)>18) {
Edit14->Text=0;

}else{
  Edit14->Text=Edit14->Text.ToIntDef(0)+1;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer6Timer(TObject *Sender)
{
bool var = false;
for (int i = 0; i < 5; i++) {
if (ListBox45->Items->Strings[i].ToIntDef(0)>2) {
Edit13->Text=Memo2->Lines->Strings[i];
var = true;
}
}

    

BYTE Komut2[]={0x08,0x01,0x01,0x15,0x29,0xFF,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut2[3]=Edit13->Text.ToIntDef(0);
if ((var)&&Edit15->Text!=Edit14->Text) {
Client[Edit14->Text.ToIntDef(0)].KomutYolla(Komut2,sizeof(Komut2));
}
if (Edit14->Text.ToIntDef(0)>18) {
Edit14->Text=0;

}else{
  Edit14->Text=Edit14->Text.ToIntDef(0)+1;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox17Click(TObject *Sender)
{
if (CheckBox17->Checked) {
	Timer6->Enabled=true;
}else{
        Timer6->Enabled=false;
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button192Click(TObject *Sender)
{
BYTE Komut2[]={0x08,0x01,0x01,0x15,0x29,0xFF,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut2[3]=Edit16->Text.ToIntDef(0);
Client[Edit15->Text.ToIntDef(0)].KomutYolla(Komut2,sizeof(Komut2));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox18Click(TObject *Sender)
{
if (CheckBox18->Checked) {
	 Timer7->Enabled=true;
}else{
     Timer7->Enabled=false;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer7Timer(TObject *Sender)
{
for (int i = 0; i < 5; i++) {
BYTE Komut[]={0x22,0x00,0x00,0x00};
*(WORD*)&Komut[1]=Memo2->Lines->Strings[i].ToIntDef(0);;
Client[0].KomutYolla(Komut,sizeof(Komut));
}
bool var = false;
for (int i = 0; i < 5; i++) {
if ((ListBox45->Items->Strings[i].ToIntDef(0)<3)&&(ListBox45->Items->Strings[i].ToIntDef(0)>0)) {
Edit16->Text=Memo2->Lines->Strings[i];
var = true;
}
}

    

BYTE Komut2[]={0x08,0x01,0x01,0x15,0x29,0xFF,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut2[3]=Edit16->Text.ToIntDef(0);
if (var) {
Client[Edit15->Text.ToIntDef(0)].KomutYolla(Komut2,sizeof(Komut2));
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button194Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Komut0[]={0x20,0x01,0xBF,0x3C,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut[]={0x64,0x07,0xF7,0x0A,0x00,0x00};
BYTE Komut1[]={0x55,0x00,0x0F,0x31,0x38,0x30,0x31,0x30,0x5F,0x43,0x61,0x76,0x61,0x6C,0x2E,0x6C,0x75,0x61,0xFF};
BYTE Komut2[]={0x55,0x00,0x0F,0x31,0x38,0x30,0x31,0x30,0x5F,0x43,0x61,0x76,0x61,0x6C,0x2E,0x6C,0x75,0x61,0xFF};
Client[i].KomutYolla(Komut0,sizeof(Komut0));
Client[i].KomutYolla(Komut,sizeof(Komut));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
//Client[i].KomutYolla(Komut2,sizeof(Komut2));
Application->ProcessMessages();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button193Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(113,173,0);

}
Form1->Memo2->Clear();
Form1->Memo2->Lines->Add(15516);
Form1->Memo2->Lines->Add(15517);
Form1->Memo2->Lines->Add(15518);
Form1->Memo2->Lines->Add(15519);
Form1->Memo2->Lines->Add(15520);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button195Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(143,173,0);

}
Form1->Memo2->Clear();
Form1->Memo2->Lines->Add(15521);
Form1->Memo2->Lines->Add(15522);
Form1->Memo2->Lines->Add(15523);
Form1->Memo2->Lines->Add(15524);
Form1->Memo2->Lines->Add(15525);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button196Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(114,91,0);

}
Form1->Memo2->Clear();
Form1->Memo2->Lines->Add(15541);
Form1->Memo2->Lines->Add(15542);
Form1->Memo2->Lines->Add(15543);
Form1->Memo2->Lines->Add(15544);
Form1->Memo2->Lines->Add(15545);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button197Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(134,159,0);

}
Form1->Memo2->Clear();
Form1->Memo2->Lines->Add(15511);
Form1->Memo2->Lines->Add(15512);
Form1->Memo2->Lines->Add(15513);
Form1->Memo2->Lines->Add(15514);
Form1->Memo2->Lines->Add(15515);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button198Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(125,78,0);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button199Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Komut[]={0x1F,0x01,0xA0,0x57,0xAA,0x35,0x06,0x06};
Komut[6]=Client[i].FindItem(900356000);
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------






void __fastcall TForm1::ClientSocket3Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket3Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
ShowMessage("asd");	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button200Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {

Client[i].CharacterMove(125,125,0);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N20yever1Click(TObject *Sender)
{
int atilacakid =19;
  TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
Client[sok].ItemVerilecek=true;

BYTE TKomut[]={0x30,0x02,0x00};
Ko_Thread[sok]->Extern_KomutYolla(TKomut,sizeof(TKomut));

 BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
 *(WORD*)&Komut[2]=Ko_Thread[atilacakid]->Socket_Bilgi1->CharID;

Ko_Thread[sok]->Extern_KomutYolla(Komut,sizeof(Komut));
}
//---------------------------------------------------------------------------






void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
if (RadioButton1->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
     LoginServerProxyAdres="66.199.239.2";
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
if (RadioButton2->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps1[i];
		LoginServerProxyAdres="66.199.241.3";
}
}else{
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
		LoginServerProxyAdres="66.199.239.2";
}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::check1Click(TObject *Sender)
{
//ModulAl=  Manueldll("KODLL","KODLLNAME");
//Ko_Class = (KoClass) MemoryGetProcAddress(ModulAl,"KoClass");
//
//
//
//for (int i = 0; i < 20; i++) {
//Ko_Thread[i] =static_cast< KoThreadClass* > ( Ko_Class(HDDNO.c_str()));
//Client[i].Ko_Threadsyn=Ko_Thread[i];
//}
//ClientSocket3->Active=true;
//Sleep(2000);
//Form1->Timer3->Enabled=true;
//if (Form1->ototo->Checked) {
//sira = 0 ;
//Timer2->Enabled=true;
//}
//PageControl1->TabIndex=1;
//return;
 BYTE Send[1024];
int Yer=0;
Send[Yer]=0x00;
Yer++;
*(DWORD*)&Send[Yer]=Version;
Yer+=4;

PacketSifrele(Send,Yer,keykontrol);
ClientSocket1->Socket->SendBuf(Send,*(WORD*)&Send[1])  ;	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
ClientSocket4->Active=false;
ClientSocket4->Address = "31.210.81.2";
ClientSocket4->Port	   = 16000 ;
ClientSocket4->Active=false;
ClientSocket4->Active=true;
if (RadioButton3->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps2[i];
	LoginServerProxyAdres="31.210.81.2";
}
}else{
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
	LoginServerProxyAdres="66.199.239.2";
}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button201Click(TObject *Sender)
{
String adr="mgid=";
adr+=SocketForm[RadioGroup1->ItemIndex].Account->Text;
adr+="&mgmc=";
//adr+="fbfgakblboam";   //osra78
adr+="fofjfifiamaeajahaibdboan";  //duranga
adr+="&param=" ;

adr+=IntToStr(Form1->Serverlar->ItemIndex+1);
adr+=",";
adr+=IntToStr(Form1->Karakter->ItemIndex);
adr+=",15,1";
 WebBrowser1->Navigate("https://k2shop.knightonlineworld.com/default.asp?"+adr) ;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button202Click(TObject *Sender)
{
  WebBrowser1->Navigate("https://k2shop.knightonlineworld.com/ESN/form.asp") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button203Click(TObject *Sender)
{
  WebBrowser1->Navigate("http://www.gamersfirst.com/redeemcode/process_code.php") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button204Click(TObject *Sender)
{
for (int i = 0; i < Memo3->Lines->Count; i++) {
 SocketForm[i].Account->Text=Form1->Memo3->Lines->Strings[i];    
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button205Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
BYTE Komut[]={0x1F,0x01,0xA0,0x57,0xAA,0x35,0x06,0x06};
*(DWORD*)&Komut[2]=389132000;
Komut[6]=Client[i].FindItem(389132000);
Client[i].KomutYolla(Komut,sizeof(Komut));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pitman1Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].Town();
Application->ProcessMessages() ;
Client[i].CharacterMove(Client[i].Zone.Pitman.X,Client[i].Zone.Pitman.Y,2) ;
}	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
ClientSocket4->Active=false;
ClientSocket4->Address = "31.210.81.130";
ClientSocket4->Port	   = 16000 ;
ClientSocket4->Active=false;
ClientSocket4->Active=true;
if (RadioButton4->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps3[i];
	LoginServerProxyAdres="31.210.81.130";
}
}else{
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
	LoginServerProxyAdres="66.199.239.2";
}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
ClientSocket4->Active=false;
ClientSocket4->Address = "31.210.82.2";
ClientSocket4->Port	   = 16000 ;
ClientSocket4->Active=false;
ClientSocket4->Active=true;
if (RadioButton5->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps4[i];
	LoginServerProxyAdres="31.210.82.2";
}
}else{
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
	LoginServerProxyAdres="66.199.239.2";
}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OpenBuy1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	BYTE Komut[] ={0x68,0x21};
	BYTE Komut1[] ={0x68,0x22,0x03,0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,0x38,0x72,0x99,0x16,0xB0,0x00,0x00,0x00,0x00,0x00,0x50,0x6E,0x99,0x16,0xAF,0x00,0x00,0x00,0x00,0x00,};
	Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));
	Client[pComponent->Tag].KomutYolla(Komut1,sizeof(Komut1));
		Edit17->Text=Client[pComponent->Tag].Id;

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button206Click(TObject *Sender)
{
BYTE Komut[]={0x68,0x23,0xC3,0x03,};
//*(WORD*)&Komut[2]=Client[19].Id;
*(WORD*)&Komut[2]=Edit17->Text.ToIntDef(0);
BYTE Komut1[]={0x68,0x24,0x05,0x00,0x01,0x00,};

BYTE Komut2[]={0x68,0x27,};
for (int i = 0; i < 18; i++) {
if ((Client[i].FindItem(379156000)!=-1)||(Client[i].FindItem(379155000))||(Client[i].FindItem(379154000))) {


Application->ProcessMessages();

Client[i].KomutYolla(Komut,sizeof(Komut));
if (Client[i].FindItem(379156000)!=-1) {
Komut1[2]=Client[i].FindItem(379156000);
Komut1[3]=0;
*(WORD*)&Komut1[4]=Client[i].GetItemCount(Client[i].FindItem(379156000));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
}
if (Client[i].FindItem(379155000)!=-1) {
Komut1[2]=Client[i].FindItem(379155000);
Komut1[3]=1;
*(WORD*)&Komut1[4]=Client[i].GetItemCount(Client[i].FindItem(379155000));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
}
if (Client[i].FindItem(379154000)!=-1) {
Komut1[2]=Client[i].FindItem(379154000);
Komut1[3]=2;
*(WORD*)&Komut1[4]=Client[i].GetItemCount(Client[i].FindItem(379154000));
Client[i].KomutYolla(Komut1,sizeof(Komut1));
}
Client[i].KomutYolla(Komut2,sizeof(Komut2));
Application->ProcessMessages();
Sleep(250);
Application->ProcessMessages();
Sleep(250);
SocketForm[i].Memo->Lines->Add("BuyBirak Ok");





  }else{
SocketForm[i].Memo->Lines->Add("BuyBirak Fail!!!");
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
ClientSocket4->Active=false;
ClientSocket4->Address = "31.210.68.140";
ClientSocket4->Port	   = 16000 ;
ClientSocket4->Active=false;
ClientSocket4->Active=true;
if (RadioButton6->Checked) {
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps5[i];
	LoginServerProxyAdres="31.210.68.140";
}
}else{
for (int i = 0; i < 40; i++) {
	ProxyIps[i]=ProxyIps0[i];
	LoginServerProxyAdres="66.199.239.2";
}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ClientSocket4Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
BYTE Komut[8];
int glnlen=	 Socket->ReceiveLength();
 BYTE KomutBuf[1024];
		 if(glnlen>8)
		 {
			 return;
		 }
		 Socket->ReceiveBuf(Komut,glnlen) ;
DWORD x,y;
x=*(DWORD*)&Komut[0];
y=*(DWORD*)&Komut[4];
if (RadioButton4->Checked) {
RadioButton4->Caption = IntToStr(x)+"/"+IntToStr(y);
}else if (RadioButton5->Checked) {
RadioButton5->Caption = IntToStr(x)+"/"+IntToStr(y);
}else if (RadioButton6->Checked) {
RadioButton6->Caption = IntToStr(x)+"/"+IntToStr(y);
}else if (RadioButton3->Checked) {
RadioButton3->Caption = IntToStr(x)+"/"+IntToStr(y);
}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::CheckBox20Click(TObject *Sender)
{
if (this->CheckBox20->Checked) {
Timer2->Interval=500;
}else{
 Timer2->Interval=2500;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SendToInn01Click(TObject *Sender)
{
 TComponent *pComponent = PopupMenu2->PopupComponent;
	 int sok=       (dynamic_cast<TImage *>(pComponent))->Tag ;
	 int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id!=0) {
BYTE Komut[] = {0x45,0x02,0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff};
*(WORD*)&Komut[2]=Client[sok].Zone.Inn.Id;
*(DWORD*)&Komut[4]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Komut[8]=0;
Komut[9]= ItemYer;
Komut[10]=0;
*(DWORD*)&Komut[11]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Adet;

Client[pComponent->Tag].KomutYolla(Komut,sizeof(Komut));

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button207Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].CharacterMove(Client[i].Zone.Inn.X,Client[i].Zone.Inn.Y,0);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button208Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	 int sok=    i;
	 int ItemYer= 27;

BYTE Komut[] = {0x45,0x03,0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff};
*(WORD*)&Komut[2]=Client[sok].Zone.Inn.Id;
*(DWORD*)&Komut[4]=379156000;
Komut[8]=0;
Komut[9]= 0;
Komut[10]=ItemYer;
*(DWORD*)&Komut[11]=1;
Client[sok].KomutYolla(Komut,sizeof(Komut));

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button209Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
	 int sok=    i;
	 int ItemYer= 27;
for (ItemYer= 0; ItemYer < 28; ItemYer++) {
Application->ProcessMessages();
if (Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id==379156000) {
BYTE Komut[] = {0x45,0x02,0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0xff,0xff};
*(WORD*)&Komut[2]=Client[sok].Zone.Inn.Id;
*(DWORD*)&Komut[4]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Id;
Komut[8]=0;
Komut[9]= ItemYer;
Komut[10]=0;
*(DWORD*)&Komut[11]=Ko_Thread[sok]->Socket_Bilgi1->Item_Table[ItemYer].Adet;
Client[sok].KomutYolla(Komut,sizeof(Komut));
}
}
}
}

//---------------------------------------------------------------------------


void __fastcall TForm1::Edit18Change(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].ChaosX=Edit18->Text.ToIntDef(955);
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit19Change(TObject *Sender)
{

for (int i = 0; i < 20; i++) {
Client[i].ChaosY=Edit19->Text.ToIntDef(502);
}
EditSave(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button210Click(TObject *Sender)
{
	BYTE Komut[] ={0x68,0x21};
	BYTE Komut1[] ={0x68,0x22,0x03,0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,0x38,0x72,0x99,0x16,0xB0,0x00,0x00,0x00,0x00,0x00,0x50,0x6E,0x99,0x16,0xAF,0x00,0x00,0x00,0x00,0x00,};
	Client[19].KomutYolla(Komut,sizeof(Komut));
	Client[19].KomutYolla(Komut1,sizeof(Komut1));
		Edit17->Text=Client[19].Id;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button211Click(TObject *Sender)
{
allsrv->ItemIndex=allsrv->ItemIndex+2;
for (int i = 0; i < 20; i++) {
	SocketForm[i].Server->ItemIndex = allsrv->ItemIndex;
	KoIni = new TIniFile(NewPath+"protect.dll");
	KoIni->WriteInteger("acc",SocketForm[i].Server->Name,SocketForm[i].Server->ItemIndex);
	KoIni->Free();
}
DisconnectAll1Click(0);
ConnectAll1Click(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button212Click(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
Client[i].chaosgir=3;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer8Timer(TObject *Sender)
{
int count = 0;
int x=0;
int y=0;
for (int i = 0; i < 20; i++) {
	if (Client[i].Ko_Threadsyn->Socket_Bilgi1->LoginOk) {
	if (Client[i].FindItem(910246000)==-1) {
	SocketForm[i].SocketGroup->Color=clRed;
	}else{
	SocketForm[i].SocketGroup->Color=clGreen;
	count++;
	x=x+ Client[i].Ko_Threadsyn->Socket_Bilgi1->X;
		y=y+ Client[i].Ko_Threadsyn->Socket_Bilgi1->Y;
	}
	}
}
if ((count==18)&&(x==18*955)&&(y==18*502)) {
Button211Click(0);
Client[0].Ko_Threadsyn->Socket_Bilgi1->X=0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mapalClick(TObject *Sender)
{
if (mapal->Checked) {
	Timer8->Enabled=true;
}else{
            Timer8->Enabled=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenSell1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	int sock = pComponent->Tag;
BYTE Komut0[]={0x68,0x01};
Client[sock].KomutYolla(Komut0,sizeof(Komut0));
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddToSell1Click(TObject *Sender)
{
  TComponent *pComponent = PopupMenu2->PopupComponent;
  if (pComponent)
  {
	int sock = pComponent->Tag;
	int ItemYer= (dynamic_cast<TImage *>(pComponent))->Hint.ToIntDef(0);
BYTE Komut1[]={
0x68,0x03,
0x90,0xF1,0x2F,0x17, //item id
0x01,0x00,//adet
0x10,0x00,0x00,0x00,//fiat
0x00, //inv yer
0x03,//merc yer
};


*(DWORD*)&Komut1[2]=Client[sock].Ko_Threadsyn->Socket_Bilgi1->Item_Table[ItemYer].Id;
tek:
String ItemAdet;
if(InputQuery("Sell Merchant","Satilacak Adeti Giriniz",ItemAdet))
{
	if (ItemAdet>Client[sock].Ko_Threadsyn->Socket_Bilgi1->Item_Table[ItemYer].Adet)
	{
		ShowMessage("Ustunuzde Bu Kadar Mal Yok Amk!!!");
		goto tek;
	}
*(WORD*)&Komut1[6]=ItemAdet.ToIntDef(1);
String ItemFiat;
if(InputQuery("Sell Merchant","Satis Fiyatini Giriniz!!!",ItemFiat))
{
*(DWORD*)&Komut1[8]=ItemFiat.ToIntDef(999999999);
Komut1[12]=0;
Komut1[13]=ItemYer;
Client[sock].KomutYolla(Komut1,sizeof(Komut1));
}
}
}




}
//---------------------------------------------------------------------------


void __fastcall TForm1::clockTimer(TObject *Sender)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	now_time_h->Text = IntToStr(st.wHour);
		now_time_m->Text = IntToStr(st.wMinute);
			if ((will_time_h->Text.ToIntDef(99)==st.wHour)&&(will_time_m->Text.ToIntDef(99)==st.wMinute))
			{
				will_time_h->Text=99;
				will_time_m->Text=99;
				ConnectAll1Click(0);
			}
			if ((will2_time_h->Text.ToIntDef(99)==st.wHour)&&(will2_time_m->Text.ToIntDef(99)==st.wMinute))
			{
				will2_time_h->Text=99;
				will2_time_m->Text=99;
                CheckBox13->Checked=true;
			}
}
//---------------------------------------------------------------------------




