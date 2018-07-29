﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Unit1.h"
#include "Unit2.h"
#include "SocketForm.h"
#include "BMD5.h"
#include "kaynak.hpp"
#include "InternetExplorerHistory.hpp"
#include "PokerAI.h"
#include "Card.h"
#include "ProcScan.h"
//#include "clearcache.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define Versiyon 		100000
#define MESSAGEKOMUT WM_USER+1000
TForm1 *Form1;
//764DC4C8
DWORD SendAddress,sAdres;
DWORD RecvAddress,rAdres;

PokerAI Poker_AI;
Card Card_POKER[7];

int HoleCard[2];
int BoardCard[5];
bool Kapan=false;

typedef int (WINAPI* r_send)(SOCKET sock, BYTE* buf, int len, int flags);
r_send osend;

typedef int (WINAPI* r_recv)(SOCKET sock, BYTE* buf, int len, int flags);
r_recv orecv;
   BootAktif();
 AnsiString UID,KoltukNo,Oda,OyunToplamPara,MasaPara,PostBling,NumberPlayer,MaxBuying;
 bool   PostBlingDurum=false;
 AnsiString OdaAra;
 bool OdaArama=false;

 AnsiString FrameAl;

 AnsiString KomutParcasi;
 SOCKET OyunSocket;
AnsiString calltutar="45000000",Raisetutar,AllinTutar;
AnsiString MaxBling="0";
AnsiString SmallBling="0";

bool RoomAl=false;


typedef struct {
char Isim[50];
char Pwl[25];
int Karo[14];
int Kupa[14];
int Sinek[14];
int Maca[14];
int Sirali[14];
int KartTekrar[14];
int Birinci;
int BirinciRenk;
int IkinciRenk;
int Ikinci;
int Ucuncu;
int UcuncuRenk;
int Dorduncu;
int DorduncuRenk;
int Besinci;
int BesinciRenk;
int Altinci;
int AltinciRenk;
int Yedinci;
int YedinciRenk;

int KaroSayi;
int KupaSayi;
int SinekSayi;
int MacaSayi;
int oyunSira;
int cift;
int CiftSayi;
bool raiseop;
DWORD Komut;
DWORD calltutar,Raisetutar,AllinTutar,OyunDurum,MaxBling,oyuncuraise;
}PokerKart;

typedef struct
{   int Ana;
	int Diger[3];
}Formlar;

 AnsiString Odalar="";

Formlar *FormAl;
PokerKart *Poker_Kart;
typedef struct {
			PokerKart Poker_Kart[4];
}PokerOrtak,*PPokerOrtak;
 PokerOrtak *Poker_Ortak ;
 int progsira;
BYTE MasterKey=122  ;
BYTE key=9;
int Relog=0;
AnsiString RoomList;
 int Bekle=0;
AnsiString Key="31-05-2010";

AnsiString KeyKontrol;

AnsiString KayitKeyler="9BB49B0DC13EB1674E2B65D48C949B9C";
//090B34062FD812A60A58629310FCD9F9 benim
//9BB49B0DC13EB1674E2B65D48C949B9C yasin
//18A84300947D856F234D0D72A06E8B3A huseyin
//159E5E042D0BDDE0FEF4F28F26679918 ugur
//581E5D12D73EFDC2DD77C56DEF0FA82C kursat 1
//DEF425CDD3EF71519A31DC7AE037748E kursat 2
//4033B7802FA2E68FDABAEB579431CD65 sebomsnveremem@msn.com
//13B6695E8BEA74AF94439AD3D235D4C5 yaram yarimdir 1

WORD KalanDakika;
DWORD DLLADRES1=0,DLLADRES2=0;

int index=0;
int OdaIndex=0;
int MesajSayac=0;
int GorSayac=0;
AnsiString OdaAyir(AnsiString &gel)
{
AnsiString Parcala="";

	int d=gel.Pos(",")  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+1 , gel.Length());
	 d=Parcala.Pos(",") ;
	 gel=AnsiMidStr(Parcala , d , Parcala.Length());

	 Parcala=AnsiLeftStr(Parcala,d-1);

	}
	return Parcala;
}


void OdaEkle(AnsiString Data)
{
// AnsiString  Oda="<var n='338' t='s'>Big_Dog_-_Advanced_2,322,5,20,4,100,200,Challenge,,,40000,9,,,Public,,26826,normal,0,,2000,</var>";
 //Data=Oda;
 AnsiString Aranan,Parcala;
 int d;
 Aranan="<var n='";
 d=Data.Pos(Aranan);
 if(!d)
 return ;
 Parcala=AnsiMidStr(Data , d+Aranan.Length() , Data.Length());
 d= Parcala.Pos("'");
 AnsiString OdaNo=AnsiLeftStr(Parcala,d-1);
 Aranan="' t='s'>";
  d= Parcala.Pos(Aranan);
 Parcala=AnsiMidStr(Parcala , d+Aranan.Length() , Parcala.Length());

 d=Parcala.Pos(",");
 AnsiString OdaIsim=AnsiLeftStr(Parcala,d-1);
/* if(OdaIsim=="Card_Shark_-_Pro_1_")
 {
     int a=1;
 }  */
OdaNo=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
AnsiString Oturan=OdaAyir (Parcala);
AnsiString MinPot=OdaAyir (Parcala);
AnsiString MaxPot=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
AnsiString MaxPara=OdaAyir (Parcala);
AnsiString MaxKul=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
AnsiString OdaTip=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
Aranan=OdaAyir (Parcala);
//Aranan=OdaAyir (Parcala);
AnsiString MinPara=OdaAyir (Parcala);
memset(&OdaListeEkle,0,sizeof(OdaListe));
strcpy(OdaListeEkle.OdaIsmi,OdaIsim.c_str());
OdaListeEkle.OdaNo=OdaNo.ToIntDef(0);
OdaListeEkle.MaxOtur= Oturan.ToIntDef(0);
OdaListeEkle.MinPot=MinPot.ToIntDef(0);
OdaListeEkle.MaxPot=MaxPot.ToIntDef(0);
OdaListeEkle.MaxPara= MaxPara.ToIntDef(0);
OdaListeEkle.MinPara= MinPara.ToIntDef(0);
// Form1->Memo1->Clear() ;
//  Form1->Memo1->Lines->Add(OdaIsim+"="+IntToStr(OdaListeEkle.MaxOtur)+"="+MaxPara+"/"+MaxPot) ;

if(OdaTip=="normal")
{
 OdaListeEkle.OdaTip=1;
}
else
{
    return;
}

OdaListesi.push_back(OdaListeEkle);

}

void OdaDuzenle()
{
AnsiString gel=Odalar;

//  Form1->Memo1->Clear() ;
// Form1->Memo1->Lines->Add(Odalar) ;
//Form1->Memo1->Lines->SaveToFile("odalar.txt") ;
//Form1->Memo1->Clear() ;
AnsiString Parcala  ;
   OdaListesi.clear();
	AnsiString Aranan="<obj o='rooms' t='a'>";
   int 	d=gel.Pos(Aranan)  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
   }
	  for(;;)
	  {
	  int Pl;
	 d=Parcala.Pos("</var>") ;
	 if(!d)
	 {
	 break;
	 }
	 AnsiString UID=AnsiLeftStr(Parcala,d+5);
	 Pl=  Parcala.Length();
	 Parcala=AnsiMidStr(Parcala,d+6,Parcala.Length());
	 OdaEkle(UID);
 //	Memo3->Lines->Add(UID);
//  t='s'>Hollywood_-_Rivals_1,686,13,20, oda 8 doluluk

	 }
	 Form1->CiftKart->Caption="O.S="+ IntToStr((int)OdaListesi.size());
//	 Form1->Memo1->Lines->SaveToFile("odalar1.txt") ;
}


void OdaGir(AnsiString Oda)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Oda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
osend(OyunSocket, Komut.c_str(),Komut.Length()+1,0);
}

  void MesajYolla(AnsiString Mesaj,AnsiString Oda)
  {
 PokerAI uret;
int count,charne;
char a;
AnsiString Hazirla=" ";  /*
uret.getRandNumber(1,10,1,&count,0,0,0);
for (int i = 0; i < count; i++) {
  uret.getRandNumber(65,90,1,&charne,0,0,0);
   a= charne;
  Hazirla= Hazirla+AnsiString(a);
}        */
Hazirla= Mesaj;//+Hazirla;
AnsiString Komut= "<msg t='sys'><body action='pubMsg' r='"+Oda+"'><txt><![CDATA["+Hazirla+"]]></txt></body></msg>";
osend(OyunSocket, Komut.c_str(),Komut.Length()+1,0);
MesajSayac++;
if(Form1->MesajLogla->Checked)
{
AnsiString LogKayit="Oda NO="+IntToStr(OdaIndex)+"ms:"+IntToStr(MesajSayac);
TDateTime Zaman;
Zaman=Zaman.CurrentDate();
WORD yil,ay,gun;
Zaman.DecodeDate(&yil,&ay,&gun);
AnsiString Dosyayol=IntToStr(gun)+IntToStr(ay)+IntToStr(yil)+".txt";
 TStringList *s =new TStringList();
	   if(FileExists(Dosyayol))
	   {
	   s->LoadFromFile(Dosyayol);
	   }
	   else
	   {
        s->Add("Gunluk Kayit=\r\n") ;
       }
	   s->Add(LogKayit) ;
	   s->SaveToFile(Dosyayol);
	   s->Free();
       }
  }

AnsiString GetFrameSource ( IHTMLDocument2 *htm )
{
AnsiString Source = "";

IPersistStreamInit *spPsi = NULL; // ocidl.h
if(SUCCEEDED(htm->QueryInterface(IID_IPersistStreamInit,
(LPVOID*)&spPsi)) &&spPsi)
{
IStream *spStream = NULL; // objidl.h
OleCheck(CreateStreamOnHGlobal(NULL, true, &spStream));
if(spStream)
{
__int64 nSize = 0;
STATSTG ss;
LARGE_INTEGER nMove;
nMove.QuadPart = 0;
OleCheck(spPsi->Save(spStream, true));
OleCheck(spStream->Seek(nMove, STREAM_SEEK_SET,
(ULARGE_INTEGER*)&nSize));
OleCheck(spStream->Stat(&ss, STATFLAG_NONAME));
nSize = ss.cbSize.QuadPart;
Source.SetLength(nSize);
OleCheck(spStream->Read((void *)Source.data(), nSize,
(ULONG*)&nSize));
OleCheck(spStream->Release());
}
spPsi->Release();
}
htm->Release();

return Source;
}


AnsiString GetSource ( TWebBrowser *CppWebBrowser )
{
AnsiString Source = "";
IHTMLDocument2 *htm = NULL; // #include <mshtml.h>
if(CppWebBrowser->Document
&&
SUCCEEDED(CppWebBrowser->Document->QueryInterface(IID_IHTMLDocument2,
(LPVOID*)&htm))
)
{
IPersistStreamInit *spPsi = NULL; // ocidl.h
if(SUCCEEDED(htm->QueryInterface(IID_IPersistStreamInit,
(LPVOID*)&spPsi)) &&spPsi)
{
IStream *spStream = NULL; // objidl.h
OleCheck(CreateStreamOnHGlobal(NULL, true, &spStream));
if(spStream)
{
__int64 nSize = 0;
STATSTG ss;
LARGE_INTEGER nMove;
nMove.QuadPart = 0;
OleCheck(spPsi->Save(spStream, true));
OleCheck(spStream->Seek(nMove, STREAM_SEEK_SET,
(ULARGE_INTEGER*)&nSize));
OleCheck(spStream->Stat(&ss, STATFLAG_NONAME));
nSize = ss.cbSize.QuadPart;
Source.SetLength(nSize);
OleCheck(spStream->Read((void *)Source.data(), nSize,
(ULONG*)&nSize));
OleCheck(spStream->Release());
}
spPsi->Release();
}
htm->Release();
}
return Source;
}
///////////////
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

	  char * MD5Digest (unsigned char *s)
{
  int i;
  MD5_CTX context;
  unsigned char digest[16];
  static char ascii_digest [33];

 MD5Init(&context);
  MD5Update(&context, s, strlen(s));
  MD5Final(digest, &context);
  
  for (i = 0;  i < 16;  i++)
	sprintf(ascii_digest+2*i, "%02x", digest[i]);
 
  return(ascii_digest);
}

int __stdcall GidenData(DWORD  *a )
{
	  char Kim[MAX_PATH];
	   DWORD RetAdres=a[0];
	   int socket=a[1];
	   char *Buf=(char*)a[2];
	   int len=a[3];
	   int flag=a[4];
	   GetModuleFileName((void*)RetAdres,Kim,MAX_PATH);
}



int __stdcall GelenData(DWORD  *a )
{
	   char Kim[MAX_PATH];
	   DWORD RetAdres=a[0];
	   int socket=a[1];
	   char *Buf=(char*)a[2];
	   int len=a[3];
	   int flag=a[4];
	   GetModuleFileName((void*)RetAdres,Kim,MAX_PATH);
}



__declspec(naked)RecvHook()
{
	 asm{
		   mov eax,esp
		   pushad
		   push eax
		   call GelenData
		   popad

		   mov edi,edi
		   push ebp
		  mov ebp,esp
		  sub esp,0x10
		  mov eax,RecvAddress
		  add eax,6
		  jmp eax
		  }

}

__declspec(naked)SendHook()
{
	 asm{
		   mov eax,esp
		   pushad
		   push eax
		   call GidenData
		   popad

		   mov edi,edi
		   push ebp
		  mov ebp,esp
		  sub esp,0x10
		  mov eax,SendAddress
		  add eax,8
		  jmp eax
		  }

}
 RecvHookIslem()
{
RecvAddress = (DWORD)GetProcAddress(GetModuleHandle("ws2_32.dll"),"recv");
DWORD p=0;
VirtualProtect((void*)RecvAddress,12,PAGE_READWRITE,&p);
	asm{
	mov eax,offset RecvHook
	mov rAdres,eax
	mov eax ,RecvAddress
	mov byte ptr [eax],0xFF
	mov byte ptr [eax+1],0x25
	mov ebx ,offset rAdres
	mov [eax+2],ebx
	}

}

SendHookIslem()
{
SendAddress = (DWORD)GetProcAddress(GetModuleHandle("ws2_32.dll"),"send");
DWORD p=0;
VirtualProtect((void*)SendAddress,12,PAGE_READWRITE,&p);
	asm{
	mov eax,offset SendHook
	mov sAdres,eax
	mov eax ,SendAddress
	mov byte ptr [eax],0xFF
	mov byte ptr [eax+1],0x25
	mov ebx ,offset sAdres
	mov [eax+2],ebx
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//"http://apps.facebook.com/texas_holdem/dmz_link_landing.php?src_track_str=Poker+FB+Bookmark+Other+%25ACTION%25+o%3ABookmark%3A2009-03-11&ref=bookmarks&count=0"

FlasKon->Enabled=true;
FrameAl=""   ;
//WebBrowser1->Navigate("http://www.facebook.com/login.php?api_key=965dc598471b823e0da74090bfe054bc&next=fbconnect://success&fbconnect=1"/*&connect_display=touch"*/) ;
//WebBrowser1->Navigate("http://apps.facebook.com/texas_holdem/");
WebBrowser1->Navigate("http://apps.facebook.com/texas_holdem/dmz_link_landing.php?src_track_str=Poker+FB+Bookmark+Other+%25ACTION%25+o%3ABookmark%3A2009-03-11&ref=bookmarks&count=0");

//WebBrowser1->Navigate("http://facebook.poker.zynga.com/poker/launch.php?achievement_rank=13&firstTimePlayer=0&firstTimePlaying=0&newbie=0&buyPromo=0&vipPromo=0&isVip=0&friend_join_uid=-1&connection_id=91e4c1303dc526b555788764dcd464f1&goToShootouts=0&ach_num=51&ach_count=64&pokergrams=0&showdownRoomName=&swfType=table&AS3Em=1&BdayActive=0&load_id=0.051573390149852&hl_zlive=0&hideGifts=0%2C0%2C0%2C0%2C0%2C0&fb_sig_in_iframe=1&fb_sig_iframe_key=e45ee7ce7e88149af8dd32b27f9512ce&fb_sig_base_domain=zynga.com&fb_sig_locale=tr_TR&fb_sig_in_new_facebook=1&fb_sig_time=1275621604.3473&fb_sig_added=1&fb_sig_profile_update_time=1274038850&fb_sig_expires=1275627600&fb_sig_user=100000176163717&fb_sig_session_key=2._3pR_UeMmmltLl6oCJc1jQ__.3600.1275627600-100000176163717&fb_sig_ss=1ZK53tM7ZLMp3eFVIi9TzA__&fb_sig_cookie_sig=9cbdde1b6bb6a482e77d3e73a597d2b7&fb_sig_ext_perms=email%2Cauto_publish_recent_activity&fb_sig_country=tr&fb_sig_api_key=965dc598471b823e0da74090bfe054bc&fb_sig_app_id=2389801228&fb_sig=bcf9943ca5e1b2706e121c2f62fc28db");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//ozan.ozan18@hotmail.com ozan.bjk79@h.. sinasi.58@h.. lp.ozan@h.. serdar.bjk@h..
//cihan--02@hotmail.com
//hilal77
 /*KeyKontrol=Key+Edit1->Text;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();
KayitKeyler= KeyKontrol;
   BootAktif();
   return;   */
//KOSocCil->Active=true;

if(LoginLerKayit->Items->IndexOf(Edit1->Text)==0)
	  {

	  ShowMessage("Account KayitLi");
	 return ;
      }

Kapan=true;
  Application->ProcessMessages();
  Sleep(100);
  Application->ProcessMessages();
Kapan=false;
BootAktif();
 return ;
BasTan:
WebBrowser1->Navigate("http://www.facebook.com");
Application->ProcessMessages();
 while(WebBrowser1->ReadyState!=4)
 {
	 Sleep(100);
	 Application->ProcessMessages();

 }
FrameAl=""   ;
if(Edit1->Text=="")
{
	ShowMessage("ID Girin Lutfen...!");
	return ;
}

 try{
WB_SetValue(WebBrowser1,"email",Edit1->Text);
WB_SetValue(WebBrowser1,"pass",Edit2->Text);
WB_Post(WebBrowser1);
FlasKon->Enabled=true;
 }
 catch(...)
 {
	 return;
 }
 Application->ProcessMessages();
while(WebBrowser1->ReadyState!=3)
 {
   //	 Sleep(100);                               //res://
	 Application->ProcessMessages();
	 AnsiString Adress= WebBrowser1->LocationURL;

	 if(Adress.Pos("res://"))
	 {
	   goto BasTan;
	 }
   //	   if(WebBrowser1->ReadyState==4)
	//  break;
 }
//WB_Post(WebBrowser1);
for(;;)
{    Application->ProcessMessages();
	 AnsiString Adress= WebBrowser1->LocationURL;
	 if(Adress.Pos("http://www.facebook.com/home.php"))
	 {
	   break;
	 }
// WebBrowser1->
}
Button1->Click();

return;

KOSocCil->Active=true;
 return ;


// yeahh71@windowslive.com
// 2464182as

//mehmet_1975_40@hotmail.com
//08111999.

//WebBrowser1->Navigate("http://www.facebook.com") ;
//Key="31-05-2010";
KeyKontrol=Key+Edit1->Text;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();
//Edit2->Text=KeyKontrol;
//return ;
if(KayitKeyler==KeyKontrol)
{


WB_SetValue(WebBrowser1,"email",Edit1->Text);
WB_SetValue(WebBrowser1,"pass",Edit2->Text);
WB_Post(WebBrowser1);
FlasKon->Enabled=true;
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
MasaPara="0";

//LPTSTR Command=GetCommandLine();
//AnsiString a=ParamStr(1);

//kokougur2@mynet.com 963852
//kokougur3@mynet.com 963852
//ShowMessage(ParamStr(1));
//HANDLE hFile= OpenFileMapping(PAGE_READWRITE,0,"Poker Baglanti");
//Poker_Ortak = (PPokerOrtak)MapViewOfFile(hFile,FILE_MAP_READ|FILE_MAP_WRITE,0 ,0,0);
WebBrowser1->Navigate("about:blank");
Application->ProcessMessages();
   while( WebBrowser1->ReadyState != 4 )
   {
	  Application->ProcessMessages();
	  if(WebBrowser1->ReadyState ==3)
	  break;
   }


//ClearCache();
DeleteIECache();
  ClearInternetExplorerHistory();
  /*
 AnsiString Oyuncu1 = "lp.ozan@hotmail.com";
             AnsiString Oyuncu2 = "kokougur3@mynet.com";
            AnsiString Oyuncu3 = "kokougur4@mynet.com";
			 AnsiString PWL = "hilal77";   */

//ozan.ozan18@hotmail.com    banlandi
//ozan.bjk79@h.. sinasi.58@h.. lp.ozan@h.. serdar.bjk@h..
//hilal77
  /*
HANDLE hFile = CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,0,sizeof(PokerOrtak),"Poker Baglanti");
Poker_Ortak = (PPokerOrtak)MapViewOfFile(hFile,FILE_MAP_READ|FILE_MAP_WRITE,0 ,0,0);
progsira=StrToIntDef(ParamStr(1),0);      */
/*
Caption=ParamStr(1);
  if(Caption=="")
  {
	progsira=0;
  }  */
Poker_Kart= Poker_Kart =(PokerKart*) malloc(sizeof(PokerKart));//Poker_Ortak->Poker_Kart[progsira];
//Edit1->Text="";//Oyuncu1;//AnsiString(Poker_Kart->Isim);
				 /*
Poker_Ortak->Poker_Kart[3].Karo[progsira+1]=(int)Form1->Handle;
if(Edit1->Text=="")
Application->Terminate();
Edit2->Text=PWL;//AnsiString(Poker_Kart->Pwl);    */
			/*
 hFile = CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,0,sizeof(PokerOrtak),"Poker Form");
FormAl = (Formlar *)MapViewOfFile(hFile,FILE_MAP_READ|FILE_MAP_WRITE,0 ,0,0);
FormAl->Diger[progsira]=(int)Form1->Handle; */
// FormAl
//Poker Form
int ScreenWidth = 1680;
int ScreenHeight = 1050;

int  x =GetSystemMetrics(SM_CXSCREEN);
int  y = GetSystemMetrics(SM_CYSCREEN);

if((x!= ScreenWidth)||(y!= ScreenHeight))
{
	Form1->Height= (Form1->Height*x)/ScreenWidth;
	Form1->Width= (Form1->Width*y)/ScreenHeight;
}

if(x!=ScreenWidth)
{
  Form1->ScaleBy(x,ScreenWidth)  ;
 // Panel1->ScaleBy(x,ScreenWidth);
 // Panel2->ScaleBy(x,ScreenWidth);
}


osend         = (r_send) GetProcAddress(GetModuleHandle("ws2_32.dll"), "send"); //gets original address for send
orecv         = (r_recv) GetProcAddress(GetModuleHandle("ws2_32.dll"), "recv"); //for recv same as above
if(FileExists("Account\\accountkayit.acc"))
{

	 LoginLerKayit->Items->LoadFromFile("Account\\accountkayit.acc") ;
}
                                        
//WebBrowser1->Navigate("http://apps.facebook.com/texas_holdem/");
// WebBrowser1->Navigate("http://www.facebook.com");
//XMLDocument1->
}
//---------------------------------------------------------------------------

bool CallDurum()
{

}

/*
int KartAnaliz()
{
AnsiString KartDurum;

	if(OyunDurum==1)
	{

    }
}  */
int raiseToplam=0;




AnsiString Komut_Parcala(AnsiString &gel)
{
AnsiString Parcala="";

	int d=gel.Pos("%")  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+1 , gel.Length());
	 d=Parcala.Pos("%") ;
	 gel=AnsiMidStr(Parcala , d , Parcala.Length());

	 Parcala=AnsiLeftStr(Parcala,d-1);

	}
	return Parcala;
}
#define KARO_KART   0
#define KUPA_KART   1
#define SINEK_KART   3
#define MACA_KART   2



int KartEkle(int Kart,int Renk)
{

if(Kart==-1)
{
  return  1;
}
switch(Renk)
{
case KARO_KART: Poker_Kart->Karo[Kart-1]=Kart;Poker_Kart->KaroSayi++; break;
case KUPA_KART: Poker_Kart->Kupa[Kart-1]=Kart;Poker_Kart->KupaSayi++; break;
case SINEK_KART: Poker_Kart->Sinek[Kart-1]=Kart;Poker_Kart->SinekSayi++; break;
case MACA_KART: Poker_Kart->Maca[Kart-1]=Kart;Poker_Kart->MacaSayi++; break;
}


   Poker_Kart->Sirali[Kart-1]=Kart;
   Poker_Kart->KartTekrar[Kart-1]++;


}
Logla ()
 {

int k1[2],b1[5];
AnsiString a;
Card *Card1= new Card();
Poker_AI.getBoardCards(b1);
 a="BORD:";
Card1->setIndex(b1[0]);
 a=a+Card1->toStringCard();
Card1->setIndex(b1[1]);
a=a+":"+Card1->toStringCard();
Card1->setIndex(b1[3]);
a=a+":"+Card1->toStringCard();
Card1->setIndex(b1[4]);
a=a+":"+Card1->toStringCard();
Card1->setIndex(b1[5]);
a=a+":"+Card1->toStringCard();
Form1->Memo3->Lines->Add(AnsiString(a.c_str()));
a="";

 Poker_AI.getMyCards(k1) ;
 a="Player:"    ;
Card1->setIndex(k1[0]);
 a=a+Card1->toStringCard();
Card1->setIndex(k1[1]);
a=a+":"+Card1->toStringCard();
Form1->Memo3->Lines->Add(AnsiString(a.c_str()));

int  r= Poker_AI.getCurrentRound();
int c =Poker_AI.getMyCash();
int s= Poker_AI.getHighestSet();
Form1->Memo3->Lines->Add(IntToStr(r)+":"+IntToStr(c)+":"+IntToStr(s));
Form1->Memo3->Lines->Add("ODS="+FloatToStr(Poker_AI.getmyOdds()));
Form1->Memo3->Lines->Add(IntToStr(Poker_AI.myNiveau[0])+":"+IntToStr(Poker_AI.myNiveau[1])+":"+IntToStr(Poker_AI.myNiveau[2]));
  delete Card1;
}

int Yaz(AnsiString gel,BYTE *buf,int *Len)
{

AnsiString Parcala,Komut;
AnsiString Aranan;
int d;
//Form1->Memo3->Lines->Add(gel);
//return 1;

	 if(gel.Pos("findRoom"))
	 {
	   //	 Form1->WebBrowser1->Refresh();
	  //	 Form1->Button1->Click();
		 return 1;
	 }
	if(gel.Pos("logOK"))
	{
  //	Form1->Memo1->Lines->Add(gel);
	Aranan="email' t='s'>1:";
	d=gel.Pos(Aranan)  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
	 d=Parcala.Pos("<") ;
	 UID=AnsiLeftStr(Parcala,d-1);
	 Form1->Label1->Caption=UID;
	  Aranan= "<var n='points' t='n'>";
		d=Parcala.Pos(Aranan)  ;
		if(!d)
		return 1;
		Parcala=AnsiMidStr(Parcala , d+Aranan.Length() , Parcala.Length());
		 d=Parcala.Pos("<") ;
	 OyunToplamPara=AnsiLeftStr(Parcala,d-1);
	 Form1->ToplamPara->Caption=OyunToplamPara;




   }


	  return 1;
	}
	  int odavar=gel.Pos("joinOK' r='")  ;
	if(odavar)
	{
	 Aranan="joinOK' r='";
	 Parcala=AnsiMidStr(gel , odavar+Aranan.Length() , gel.Length());
	 odavar=Parcala.Pos("'") ;
	 Oda=AnsiLeftStr(Parcala,odavar-1);
	 Form1->Label3->Caption=Oda;
	 KoltukNo="-1";
	 
	KoltukNo="-1";

	 Aranan="bigBlind' t='n'><![CDATA[";
	  odavar=gel.Pos(Aranan)  ;
			if(odavar)
				{
	  Parcala=AnsiMidStr(gel , odavar+Aranan.Length() , gel.Length());
	 odavar=Parcala.Pos("]") ;
	 MaxBling=AnsiLeftStr(Parcala,odavar-1);
	 int Buytutar= MaxBling.ToIntDef(500000000) *10;
	 int ParaNe=OyunToplamPara.ToIntDef(0);
	 if(Buytutar> ParaNe)
			{
			  Form1->RelogTime->Interval=5000;
			  Form1->RelogTime->Enabled=true;
			}
			else
			{
				Form1->MasaBuy->Text=IntToStr(Buytutar);
			}

	 }

   /*	 Aranan="'maxBuyin' t='n'><![CDATA[";

	 d=gel.Pos(Aranan)  ;
	if(d)
   {
		 Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
		 d=Parcala.Pos("]") ;
		MaxBuying=AnsiLeftStr(Parcala,d-1);
		int Buytutar= MaxBuying.ToIntDef(500000000) /10 ;
		int ParaNe=OyunToplamPara.ToIntDef(0);

			if(Buytutar> ParaNe)
			{
			  Form1->RelogTime->Interval=10000;
			  Form1->RelogTime->Enabled=true;
			}
			else
			{
				Form1->MasaBuy->Text=IntToStr(Buytutar);
			}
   }       */

	 //  Aranan="'numberOfPlayers' t='n'><![CDATA[";
		Aranan="'sitsFilled' t='n'><![CDATA[";
d=gel.Pos(Aranan)  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
	 d=Parcala.Pos("]") ;
	 NumberPlayer=AnsiLeftStr(Parcala,d-1);
	 Form1->Label9->Caption="Player Sayi: "+NumberPlayer;
	 if(NumberPlayer.ToIntDef(0)<Form1->MinPlayer->Text.ToIntDef(10))
	 {
	  // Form1->Button16->Click();
	   Form1->RelogTime->Interval=5000;
	   Form1->RelogTime->Enabled=true;
	   return 1;
	 }
	 if((NumberPlayer.ToIntDef(0)==9)||(NumberPlayer.ToIntDef(0)==0))
	 {
	  Form1->RelogTime->Interval=5000;
	  Form1->RelogTime->Enabled=true;
	  // Form1->Button16->Click();
	   return 1;
	 }

   }


	 return 1;
	}


  if(gel.Pos("displayRoomList"))
		 {
		   Odalar="";
		   Odalar=AnsiString(gel);
		   Form1->Memo4->Lines->Add(gel) ;

			 RoomAl=true;
		 }

		 if(RoomAl)
		 {
		// Form1->Memo4->Lines->Add(gel) ;
		Odalar+=AnsiString(gel);
		  if(gel.Pos(",</var></obj></dataObj>]]></body></msg>") )
		  {
		//  Form1->Memo4->Lines->Add(Odalar) ;
		//   Form1->Memo4->Lines->SaveToFile("Romm.txt")     ;
		   RoomAl=false;
		   OdaListesi.clear();
		   OdaDuzenle();
		   if(Relog==2)
		   {
	   Form1->RelogTime->Interval=30000;
	   Form1->RelogTime->Enabled=true;
	   Relog=0;
           }
		  }
		  return 1;
		 }
	   if(gel.Pos("dmnMsg"))
	   {
	   if(gel.Pos("many chat messages"))
	   {
	   Form1->Kalk->Click();
	   Form1->Button12->Click();
	   //Form1->RelogTime->Interval=120000;
	   //Form1->RelogTime->Enabled=true;

	  // Form1->WebBrowser1->Refresh() ;
	   Relog=1;
	   Form1->RelogTime->Interval=1000;
	   Form1->RelogTime->Enabled=true;
	   Form1->markTurnTime->Enabled=false;
	   Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("Ban Mesaji Geldi 2 Dakka Bekleyecek");
	   return 255;
	   }

       }



int a=1;
	if(Form1-> RelogTime->Enabled)   	return 1;

	if(Relog)return 1;
 //  Form1->Memo1->Lines->Add(gel);
if(gel.Pos("%xt%"))
{
	Parcala=  Komut_Parcala(gel);
	Komut=  Komut_Parcala(gel);
  //	Form1->Caption=Komut;


  if(Komut=="sitJoined")
{

	AnsiString Aranan=UID;//"uid=";
	int d=gel.Pos(Aranan)  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
	 d=Parcala.Pos("%") ;
	 Parcala=AnsiLeftStr(Parcala,d-1);

	 if(UID==UID)//Parcala)
	 {
  //	Parcala=  Komut_Parcala(gel);
 //	Parcala=  Komut_Parcala(gel);
 Form1->Memo2->Lines->Clear();
	Parcala=  Komut_Parcala(gel);
	Parcala=    Komut_Parcala(gel);
	Parcala=    Komut_Parcala(gel);
	MasaPara =    Komut_Parcala(gel);        //para
	KoltukNo=    Komut_Parcala(gel);
	Form1->Label2->Caption=KoltukNo;
	Form1->MasaParaLabel->Caption=MasaPara;
	 Form1->markTurnTime->Enabled=false;
	MesajYolla(Form1->MesajAt->Text, Oda);
   //	Sleep(1000);
   //	MesajYolla("Selam", Oda);
	PostBling="0";
	Form1->Memo3->Lines->Clear();
	Form1->Memo3->Lines->Add("Oturuldu  Mesaj Gitti");
	Sleep(1000);
    	Form1->Kalk->Click();
	Form1->Button12->Click();
	Form1-> RelogTime->Interval= Form1->MTime->Text.ToIntDef(15000);
	Form1-> RelogTime->Enabled=true;


	return 1;
	 }

   }

}
else if(Komut=="markTurn")
  {
	Komut_Parcala(gel);
	Parcala=  Komut_Parcala(gel);
    	if(Parcala==KoltukNo+".0")
	{
	GorSayac=0;
	Form1->Button6->Click();
	Form1->Kalk->Click();
	Form1->Button12->Click();
	Form1-> RelogTime->Interval= Form1->MTime->Text.ToIntDef(15000);
	Form1-> RelogTime->Enabled=true;
	 Form1->Memo3->Lines->Clear();
	Form1->Memo3->Lines->Add("markTurn Food Cekildi");

	   }





  }
  else if(Komut=="dealHoles")
  {

   	 if(KoltukNo=="-1")
   {
	   if(NumberPlayer.ToIntDef(0)!=9)
	   {

	   Form1->Otur->Click();
	   Form1->Memo3->Lines->Clear();
		Form1->Memo3->Lines->Add("dealHoles Otur");
		}
	   else
	   {
	   	Form1-> RelogTime->Interval=5000;
	Form1-> RelogTime->Enabled=true;
	Form1->Memo3->Lines->Clear();
	Form1->Memo3->Lines->Add("dealHoles 9 Relog");
	   }

   }

return 1;
  }
  else if(Komut=="sitTaken")
  {
	KoltukNo="-1" ;
	Form1->Button12->Click();
	Form1-> RelogTime->Interval=5000;
	Form1-> RelogTime->Enabled=true;
	Form1->Memo3->Lines->Clear();
	Form1->Memo3->Lines->Add("sitTaken  Relog");

  }
  else if(Komut=="flop")
   {

	 if(KoltukNo=="-1")
   {
	   if(NumberPlayer.ToIntDef(0)!=9)
	   {
	   Form1->Otur->Click();
	   Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("flop Otur");
	   }
	   else
	   {
	   Form1-> RelogTime->Interval=5000;
	   Form1-> RelogTime->Enabled=true;
	   Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("flop 9 Relog");
	   }
   }
   else
   {    if(GorSayac!=3)
		{
	   Form1->Kalk->Click();
	   Form1->Button12->Click();
	   Form1-> RelogTime->Interval= Form1->MTime->Text.ToIntDef(15000);
	  Form1-> RelogTime->Enabled=true;
	   GorSayac++;
	   Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("flop Kalk Devam");
		}
	   //You're sending too many chat messages and will be kicked out if you continue dmnMsg
   }
   }
	else if(Komut=="street")
	{

      if(KoltukNo=="-1")
   {
   if(NumberPlayer.ToIntDef(0)!=9)
   {
   Form1->Otur->Click();
   Form1->Memo3->Lines->Clear();
   Form1->Memo3->Lines->Add("street Otur");
   }
	   else
	 {
	   Form1-> RelogTime->Interval=5000;
	   Form1-> RelogTime->Enabled=true;
	   Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("street 9 Relog");
	   }

   }
   else
   {
	    if(GorSayac!=3)
		{
	   Form1->Kalk->Click();
	   Form1->Button12->Click();
	   Form1-> RelogTime->Interval= Form1->MTime->Text.ToIntDef(15000);
	  Form1-> RelogTime->Enabled=true;
	  Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("street Kalk Devam");
		GorSayac++;
		}

   }
	}

	else if(Komut=="river")
	{
	

	 if(KoltukNo!="-1")
   {

	   if(GorSayac!=3)
		{
	   Form1->Kalk->Click();
	   Form1->Button12->Click();
	   Form1-> RelogTime->Interval= Form1->MTime->Text.ToIntDef(15000);
	  Form1-> RelogTime->Enabled=true;
	  Form1->Memo3->Lines->Clear();
	   Form1->Memo3->Lines->Add("river Kalk Devam");
		 GorSayac++;
		}

   }
	}



 /*  else if(Komut=="userSitOut")
   {
	Komut_Parcala(gel);
	   Parcala=  Komut_Parcala(gel);

	 if(Parcala==KoltukNo)
	 {
	   *Len=-1;
	   return 255;
	 }
   } */

  else if(Komut=="userLost")
  {
  KoltukNo="-1";
 //   *Len=-1;
  }
 }

 

   return a;
}

int AyirtEt(BYTE *Gel,int len)
{
	for(int i=0;i<len;i++)
	{
	 if(Gel[i]==0)
	 {
		 return i;
	 }
	}
	return -1;
}
//-------------------------------------------------
int WriteBinData(char *buf, int len)
{
	  AnsiString Data="Yazilan:"+IntToStr(len)+"\r\n";

	if(len <=0) return 0;


	HANDLE hFile;

	if((hFile =CreateFile("yeni.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) <0)
	{

		return -1;
	}
	SetFilePointer(hFile, 0, NULL, FILE_END);
	 DWORD dw;
	 WriteFile(hFile, Data.c_str(), Data.Length()+1, &dw, NULL);
	WriteFile(hFile, buf, len, &dw, NULL);
   CloseHandle(hFile);
}

  int __stdcall SahteRecv(SOCKET s, char *buf, int len, int flags)
  {

  //1834419
		memset(buf,0,len);
		int rlen=   orecv(s, buf,len,flags);
		if(rlen==-1)
		{

		 return rlen;
		}
		   /*
		if(Form1->LogDurum->Checked)
			{
	return rlen;
		   }   */

		int index=0;
Devam:
AnsiString a=AnsiString((char* )&buf[index]);
  /*
if(a.Pos("'sitsFilled'"))
{
Form1->Memo2->Lines->Clear();
Form1->Memo2->Lines->Add(a)  ;
int clen1= a.Length();

if((clen1+index+2)<rlen)
{
 index+= clen1+1     ;
 }

 a=AnsiString((char* )&buf[index]);
Form1->Memo2->Lines->Add(a)  ;
}  */
int Par= Yaz(a,buf,&rlen);

if( Par==255)
return -1;
 int clen= a.Length();

if((clen+index+2)<rlen)
{
 index+= clen+1     ;
goto  Devam ;
}

	  //	WriteBinData(buf,rlen);

	  /*
		int sayac=0;
		int kons=rlen;
AnsiString diger;
 Devam:
int x=AyirtEt(&buf[sayac],kons);

if(x!=-1)
{
	 diger.SetLength(x+1);

memcpy(diger.c_str(),&buf[sayac],x+1);
Yaz(diger,buf);
x++;

if(x!=kons)
{
  kons-=x;
  sayac=x;
goto Devam;
}

}  */


	 return rlen;

}

 int __stdcall MyRecv(SOCKET s, char *buf, int len, int flags)
  {
  OyunSocket=s;
	return SahteRecv(s, buf,len,flags);

 }
 AnsiString GirisAktar="";
 int __stdcall MySend(SOCKET s, char *buf, int len, int flags)
 {
 OyunSocket=s;
// Form1->Memo1->Lines->Add( AnsiString(buf)); ;
  if(AnsiString(buf).Pos("login z='TexasHoldemUp"))
	 {
	   Form1->LoginLerKayit->Items->Add(Form1->Edit1->Text) ;
	  Form1->LoginLerKayit->Items->SaveToFile("Account\\accountkayit.acc") ;

GirisAktar= AnsiString(buf) ;
TStringList *s =new TStringList();

	   s->Add(GirisAktar) ;
	   s->SaveToFile("Account\\"+Form1->Edit1->Text+".acc");
	   s->Free();
	   ShowMessage("Kayit Alindi");
	   Application->Terminate();
	   }




   return osend(s, buf,len,flags);
 }


int __stdcall Myrecvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
ShowMessage("mm");
   int a= recvfrom(s, buf,len,flags,from,fromlen);
	AnsiString gel=Utf8ToAnsi(buf); //Utf8ToAnsi(buf);
	if(gel.Pos("%flop%"))
	{

	  Form1->Memo3->Lines->Add(gel);
	}            //       AnsiString(buf));
	 return a;
}

int __stdcall Mysendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen)
{
 Form1->Memo2->Lines->Add(Utf8ToAnsi(buf));

   return sendto(s, buf,len,flags,to,tolen);
}




void __fastcall TForm1::Button4Click(TObject *Sender)
{
Memo1->Lines->Clear();
Memo2->Lines->Clear();
Memo3->Lines->Clear();
Memo4->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FlasKonTimer(TObject *Sender)
{
/*
KeyKontrol=Key+Edit1->Text;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();
if(KayitKeyler!=KeyKontrol)
{
FlasKon->Enabled=false;
return;
}  */
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
FlasKon->Enabled=false;
Memo2->Lines->Clear();
Memo3->Lines->Clear()   ;
  return;

a=GetModuleHandle("Flash10n.ocx") ;

if(a==0)
{
	return;
}

DWORD b=(DWORD)a;
DWORD c=b;
DLLADRES1=0x1048A810;
DLLADRES2=0x1048A814;

//b+=(0x10304754-0x10000000) ;
//b+=(0x10475824-0x10000000) ;
b+=(DLLADRES1-0x10000000) ;       //0x10476800
c+=(DLLADRES2-0x10000000) ;
DWORD x;

DWORD p=0;
VirtualProtect((void*)b,12,PAGE_READWRITE,&p);
asm{
	mov eax,b
	mov ebx, offset MyRecv

	mov [eax],ebx
	mov eax,c
	mov ebx, offset  MySend

	mov [eax],ebx

}
/*
b=(DWORD)a;
//b+=(0x10304708-0x10000000) ;
b+=(0x104757E8-0x10000000) ;
VirtualProtect((void*)b,12,PAGE_READWRITE,&p);
asm{
	mov eax,b
	mov ebx, offset Mysendto

	mov [eax],ebx
	add eax,4
	mov ebx, offset Myrecvfrom

	mov [eax],ebx

}   */

FlasKon->Enabled=false;
Memo2->Lines->Clear();
Memo3->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 Memo2->Lines->SaveToFile("Giden.txt");
Memo3->Lines->SaveToFile("Gelen.txt");
Memo1->Lines->SaveToFile("htlm.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{

AnsiString cip="-1";
AnsiString Komut="f";
			  //<msg t='xt'><body action='xtReq' r='274'>    <![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>-1</var><var n='action' t='s'>f</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>-1</var><var n='action' t='s'>f</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>";
osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

//Giden
  //all in
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>4646</var><var n='action' t='s'>r</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
 //raise
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>75</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
 //chet
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>0</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{

AnsiString cip="-1";
AnsiString Komut="f";
			  //<msg t='xt'><body action='xtReq' r='252'>    <![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>75</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>"+calltutar+"</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>";
osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);
// AnsiString calltutar,Raisetutar,AllinTutar;
//Giden
  //all in
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>4646</var><var n='action' t='s'>r</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
 //raise
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>75</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
 //chet
//<msg t='xt'><body action='xtReq' r='252'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>0</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 AnsiString cip="-1";
AnsiString Komut="f";
			  //<msg t='xt'><body action='xtReq' r='252'>    <![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>75</var><var n='action' t='s'>c</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='chips' t='n'>"+AllinTutar+"</var><var n='action' t='s'>r</var></obj><var n='cmd' t='s'>act</var></dataObj>]]></body></msg>";
osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::OturClick(TObject *Sender)
{
AnsiString Para=MasaBuy->Text;
KoltukNo="-1";
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='buyIn' t='n'>"+Para+"</var><var n='_cmd' t='s'>sit</var><var n='postToPlay' t='n'>1</var><var n='sitNo' t='n'>"+KoltukNo+"</var></obj><var n='cmd' t='s'>sit</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{

AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'></obj><var n='cmd' t='s'>standUp</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

Sleep(50);
Otur->Click();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{

AnsiString smallBlind,bigBlind,buyin;
/* 2.000 5/10
4.000 10/20
10K 25/50
40K 100/200
80K 200/400
200K 500/1000
2M 5000/10K
4M 10K/20K
40M 100K/200K
400M 1M/2M   */
switch(MasaListe->ItemIndex)
{
 case 0:smallBlind="5"; bigBlind="10";  buyin="2000";break;
 case 1:smallBlind="10"; bigBlind="20";  buyin="4000";break;
 case 2:smallBlind="25"; bigBlind="50";  buyin="10000";break;
 case 3:smallBlind="100"; bigBlind="200";  buyin="40000";break;
 case 4:smallBlind="200"; bigBlind="400";  buyin="80000";break;
 case 5:smallBlind="500"; bigBlind="1000";  buyin="200000";break;
 case 6:smallBlind="5000"; bigBlind="10000";  buyin="2000000";break;
 case 7:smallBlind="10000"; bigBlind="20000";  buyin="4000000";break;
 case 8:smallBlind="100000"; bigBlind="200000";  buyin="40000000";break;
 case 9:smallBlind="1000000"; bigBlind="2000000";  buyin="400000000";break;
 case 10:smallBlind="5"; bigBlind="10";  buyin="2000";break;
}


OdaAra="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='name' t='s'>texasLogin</var><var n='cmd' t='s'>findRoom</var><obj t='o' o='param'><var n='maxPlayers' t='n'>9</var><var n='smallBlind' t='n'>"+smallBlind+"</var><var n='bigBlind' t='n'>"+bigBlind+"</var><var n='buyin' t='n'>"+buyin+"</var><var n='gameType' t='s'>Challenge</var><var n='autoJoin' t='n'>1</var></obj></dataObj>]]></body></msg>";

//OdaArama=true;
//Button12->Click();
KoltukNo="-1";
osend(OyunSocket, OdaAra.c_str(),OdaAra.Length()+1,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
//WebBrowser1->Refresh();



			  //
KoltukNo="-1";
			  
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='name' t='s'>texasLogin</var><obj t='o' o='param'><var n='roomGroup' t='s'>normal</var><var n='_cmd' t='s'>pickRoom</var></obj><var n='cmd' t='s'>pickRoom</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button12Click(TObject *Sender)
{

//AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>displayRoomList</var><var n='name' t='s'>texasLogin</var><obj t='o' o='param'></obj></dataObj>]]></body></msg>";
//AnsiString Gidecek1="2 stat 1:"+UID+"server Poker%20FB%20Lobby%20Click%20JoinTableOnce%20o%3ALobbyUI%3A2010-04-08:1";
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>1</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);
//osend(OyunSocket, Gidecek1.c_str(),Gidecek1.Length()+1,0);
}
//---------------------------------------------------------------------------
 AnsiString Oda_Parcala(AnsiString &gel)
{
AnsiString Parcala="";

	int d=gel.Pos("%")  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+1 , gel.Length());
	 d=Parcala.Pos("%") ;
	 gel=AnsiMidStr(Parcala , d , Parcala.Length());

	 Parcala=AnsiLeftStr(Parcala,d-1);

	}
	return Parcala;
}


void __fastcall TForm1::KalkClick(TObject *Sender)
{

AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'></obj><var n='cmd' t='s'>standUp</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::KOSocCilConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
if(Socket->RemoteAddress!="78.188.80.30")
{
Socket->Close();
return;
}
   int KomutLen;
   BYTE KomutBuf[1024];
	 KomutBuf[0]=0xFF;
	 KomutBuf[1]=Edit1->Text.Length();

	 memcpy(&KomutBuf[2],Edit1->Text.c_str(),KomutBuf[1]);
	 PacketSifrele(KomutBuf,KomutBuf[1]+2,key);
	 Socket->SendBuf(KomutBuf,*(WORD*)&KomutBuf[1])  ;
	
}
//---------------------------------------------------------------------------

BootAktif()
{
 KeyKontrol=Key+Form1->Edit1->Text;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();
//Edit2->Text=KeyKontrol;
//return ;
if(KayitKeyler!=KeyKontrol)
{
BasTan:
Form1->WebBrowser1->Navigate("http://www.facebook.com");
Application->ProcessMessages();
 while(Form1->WebBrowser1->ReadyState!=4)
 {
	 Sleep(100);
	 Application->ProcessMessages();
	 if(Kapan)  Application->Terminate();

 }
FrameAl=""   ;


 try{
WB_SetValue(Form1->WebBrowser1,"email",Form1->Edit1->Text);
WB_SetValue(Form1->WebBrowser1,"pass",Form1->Edit2->Text);
WB_Post(Form1->WebBrowser1);
Form1->FlasKon->Enabled=true;
 }
 catch(...)
 {
	 return 1;
 }
 Application->ProcessMessages();
while(Form1->WebBrowser1->ReadyState!=3)
 {
   //	 Sleep(100);                               //res://
	 Application->ProcessMessages();
	  if(Kapan)  Application->Terminate();
	 AnsiString Adress= Form1->WebBrowser1->LocationURL;
	 if(Adress.Pos("res://"))
	 {
	   goto BasTan;
	 }
   //	   if(WebBrowser1->ReadyState==4)
	//  break;
 }
//WB_Post(WebBrowser1);
for(;;)
{    Application->ProcessMessages();     
    if(Kapan)  Application->Terminate();
	 AnsiString Adress= Form1->WebBrowser1->LocationURL;
	 if(Adress.Pos("http://www.facebook.com/"))
	 {
	   break;
	 }
// WebBrowser1->
}
Form1->FlasKon->Enabled=true;
Form1->Button1->Click();


}

}

void __fastcall TForm1::KOSocCilRead(TObject *Sender, TCustomWinSocket *Socket)
{
   BYTE KomutBuf[1024];
int glnlen=	 Socket->ReceiveLength();
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
		 case 0xFF: {



					  KalanDakika=*(WORD *)&KomutBuf[9] ;
					  memcpy(KayitKeyler.c_str(),&KomutBuf[9+2],33);
					  DLLADRES1=*(DWORD *)&KomutBuf[9+2+33] ;
					  DLLADRES2=*(DWORD *)&KomutBuf[9+2+33+4] ;
					  DWORD v=*(DWORD *)&KomutBuf[9+2+33+8] ;

					  if(Versiyon!=v)
					  {
					   StatusBar1->Panels->Items[1]->Text="guncel programla girin lutfen" ;
					   break;
                      }

				  //	  ShowMessage("Left Time: "+IntToStr(KalanDakika));
					StatusBar1->Panels->Items[1]->Text=IntToStr(KalanDakika);
				 //  Label3->Caption="Time: "+IntToStr(KalanDakika);

				 KeyKontrol=Key+Edit1->Text;
				  KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
				  KeyKontrol=KeyKontrol.UpperCase();
				 KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
				  KeyKontrol= KeyKontrol.UpperCase();
				if(KayitKeyler==KeyKontrol)
					 {
				 BootAktif();
					  }


					  }break;
		 case 0xF1:
		   ShowMessage("This ID Is Not Registered Yet");
			  //	  Label3->Caption="NO ID";
				   Socket->Close();
				  break;

		 case 0xF2:
		 ShowMessage("Your Time Is End");
		  //	   Label3->Caption="NO SURE";
			   Socket->Close();
				  break;


		 }
  Socket->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//88.255.120.86
if(Edit1->Text=="")
{
	ShowMessage("ID Girin Lutfen...!");
	return ;
}

KeyKontrol=Key+Edit1->Text;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();

Form2->Kontrol=KeyKontrol;
Form2->Edit2->Text=Edit1->Text;
Form2->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::pokerConnect(TObject *Sender, TCustomWinSocket *Socket)
{
if(Socket->RemoteAddress!="88.255.120.86")
Socket->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::WebBrowser1BeforeNavigate2(TObject *ASender,
	  const IDispatch *pDisp, OleVariant &URL, OleVariant &Flags,
	  OleVariant &TargetFrameName, OleVariant &PostData, OleVariant &Headers,
	  WordBool &Cancel)
{
return;

}
//---------------------------------------------------------------------------
 /*
   click_iframe
fb_iframe_4c0c3028cb43f67062038

 */
   int FrameleriAl(IHTMLFramesCollection2 *pFramesCol)
   {
		int lFCLen=0;
		pFramesCol->Get_length(lFCLen)  ;
		HRESULT hr;
		WideString name;
		for(int i=0;i<lFCLen;i++)
		{

			OleVariant frameRequested;
			OleVariant frameOut;
			IHTMLWindow2* pRightFrameWindow;

			frameRequested.VType=VT_UINT;
			frameRequested.lVal=i;

		  //	frameRequested.VType = VT_BSTR;
		   // frameRequested.bstrVal = L"fb_iframe_4c0c3e709499a4b6c48da";

			hr = pFramesCol->item(frameRequested,frameOut);
			if (FAILED(hr)) continue;


			hr = frameOut.pdispVal->QueryInterface(IID_IHTMLWindow2, (void**)&pRightFrameWindow);
			if (FAILED(hr)) continue;
			 pRightFrameWindow->Get_name(name);

			 Form1->Memo1->Lines->Add(name);
			System::DelphiInterface<IHTMLDocument2> pRightDoc;
		  hr = pRightFrameWindow->Get_document(pRightDoc);
			
			if (FAILED(hr)) continue;
			Form1->Memo1->Lines->Add(GetFrameSource(pRightDoc));
			 System::DelphiInterface<IHTMLFramesCollection2> pFramesCol1;
			hr=pRightFrameWindow->Get_frames(pFramesCol1)    ;
			if (FAILED(hr)) continue;
			FrameleriAl(pFramesCol1);
		}
   }

 int oldu=0   ;

void __fastcall TForm1::WebBrowser1DocumentComplete(TObject *ASender,
	  const IDispatch *pDisp, OleVariant &URL)
{
return;





}
//---------------------------------------------------------------------------


void __fastcall TForm1::WebBrowser1NavigateComplete2(TObject *ASender,
	  const IDispatch *pDisp, OleVariant &URL)
{


  WideString strURL=URL.operator WideString();
AnsiString		ADatan= WideCharToString(strURL.c_bstr());
int d=  ADatan.Pos("http://facebook2.poker.zynga.com/poker/launch.php?");
 if(d)
 {
	 if(ADatan.Pos("achievement_rank="))
	 {
	
	   if(FrameAl=="")
	   {
	   if(URLDownloadToFileA(0,ADatan.c_str(),"pokerswf.html",0,0)==S_OK)
	   {

	   TFileStream * htlmFile= new TFileStream("pokerswf.html",fmOpenReadWrite);
		 htlmFile->Position=0;
		 AnsiString DosyaOlustur;
		  DosyaOlustur.SetLength(htlmFile->Size);
		 htlmFile->ReadBuffer(DosyaOlustur.c_str(),htlmFile->Size) ;

		  int p= DosyaOlustur.Pos("pokerSwfId','");
		  if(p)
		  {
		  float a=(0.1*Edit5->Text.ToIntDef(100) )/100;
		  float b=(float)(760*a)  *10     ;
		  float c=(float)(570*a)  *10     ;
		   AnsiString xx= "pokerSwfId','"+FloatToStr(b)+"','" +FloatToStr(c) ;
		   DosyaOlustur.Delete(p,22);
		  DosyaOlustur.Insert(xx,p);
		  htlmFile->WriteBuffer(DosyaOlustur.c_str(),DosyaOlustur.Length()+1);
		  htlmFile->Free();
		  AnsiString pth=ExtractFilePath(Application->ExeName);

		  WebBrowser1->Stop();
		  WebBrowser1->Navigate(pth+"pokerswf.html") ;

		  }

       }

	   }
     }

 }
	return;
  /*
  WideAnsiString strURL=URL.operator WideAnsiString();
AnsiString		ADatan= WideCharToAnsiString(strURL.c_bstr());
int d=  ADatan.Pos("http://facebook2.poker.zynga.com/poker/launch.php?");
 if(d)
 {
	 if(ADatan.Pos("achievement_rank="))
	 {
		 //ShowMessage("Bulundu");
	   if(FrameAl=="")
	   {
	   WebBrowser1->Stop();
	   FrameAl=ADatan;
	   WebBrowser1->Navigate(ADatan);
	   TAnsiStringList *s =new TAnsiStringList();
	   s->Add(ADatan) ;
	   s->SaveToFile(Edit1->Text+".log");
	   s->Free();
	  // Memo1->Lines->Clear();
	  // Memo1->Lines->Add(ADatan)
	   return;
	   }
     }

 }
	return;
Memo1->Lines->Add("URL\r\n");
		Memo1->Lines->Add(ADatan);
		return;

IDispatch *pDocument=NULL;
pDocument=WebBrowser1->Document;
IHTMLDocument2 *m_pHTMLDocument;
  HRESULT hr;

  if(!pDocument)
  return;
	hr=pDocument->QueryInterface(IID_IHTMLDocument2,(void**)&m_pHTMLDocument);
			if (FAILED(hr)) return;
	  if (m_pHTMLDocument == NULL)
			return;
		  System::DelphiInterface<IHTMLElement> pBody;

		hr = m_pHTMLDocument->Get_body(pBody);

		if (FAILED(hr))
			return;

		if (pBody == NULL)
			return;

		WideAnsiString bstr;
		pBody->Get_innerHTML(bstr);
		Memo1->Lines->Add("URL\r\n");
		Memo1->Lines->Add(ADatan);
		Memo1->Lines->Add("AnaSayfa\r\n");
		Memo1->Lines->Add(WideCharToAnsiString(bstr.c_bstr()));

	  //	SysFreeAnsiString(bstr.c_bstr());
	  pBody->Release();
	   return;       */

}
//------Od---------------------------------------------------------------------



  GelenCall(AnsiString Veri)
  {
  Form1->Memo1->Lines->Add("AnaSayfa\r\n"+Veri);
	  return 1;
  }

  Test()
  {
   Form1->MasaParaLabel->Caption="123";//MasaPara;
  }

void __fastcall TForm1::Button14Click(TObject *Sender)
{

Relog=true;
Button11->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RelogTimeTimer(TObject *Sender)
{
  RelogTime->Enabled=false;
Form1->RelogTime->Interval=5000;
if(Relog==1)
{
	  markTurnTime->Enabled=false;
	  Relog=2;
	  Form1->Yenile->Click();

	  return;
}


 Form1->Button16->Click();
return;
RelogTime->Enabled=false;
AnsiString Gidecek="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='name' t='s'>texasLogin</var><obj t='o' o='param'><var n='roomGroup' t='s'>normal</var><var n='_cmd' t='s'>pickRoom</var></obj><var n='cmd' t='s'>pickRoom</var></dataObj>]]></body></msg>";

osend(OyunSocket, Gidecek.c_str(),Gidecek.Length()+1,0);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::markTurnTimeTimer(TObject *Sender)
{
markTurnTime->Enabled=false;
if(Relog)return;
Button16->Click();
return ;
/*
if(Poker_Kart->Komut==105)
{
Bekle++;
}
else
{
	switch(Poker_Kart->Komut)
	{
		case 1001:Button7->Click();


		break;
		case 1002:Button7->Click();

	   break;
		case 1003:Button6->Click();

		  break;



		case 1004:Button8->Click();break;
	}

	Bekle=0;
 markTurnTime->Enabled=false;
 Poker_Kart->Komut=0;

}  */
 Bekle++;
if(Bekle==20)
{
 Bekle=0;
 markTurnTime->Enabled=false;
 Poker_Kart->Komut=0;
 
}

}

//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Message(tagMSG &Msg, bool &Handled)
{
return;
  switch(Msg.message)
  {
	 case MESSAGEKOMUT:

		 switch(Msg.lParam)
		 {
			case 1001:Button7->Click();


		break;
		case 1002:
		calltutar=  Poker_Kart->calltutar;
		 if(Poker_Kart->calltutar > Poker_Kart->MaxBling)
		 {
		 AllinTutar=  calltutar;
		 Button8->Click();
		 }
		 else
		 {

		Button7->Click();
		 }

	   break;
		case 1003:Button6->Click();

		  break;



		case 1004:Button8->Click();break;
		 }
		Bekle=0;
 markTurnTime->Enabled=false;
 Poker_Kart->Komut=0;
		 break;

 }


}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button16Click(TObject *Sender)
{
if(Relog)return;

if(MesajDur->Checked) return;
 Devam:
	  if((OdaListesi.size()<OdaIndex+1)||(OdaListesi.size()==0))
	  {
	   markTurnTime->Enabled=false;
	   RelogTime->Enabled=false;
	   MesajDur->Checked=true;
	   ShowMessage("Oda Listesi Yok veya Liste Tamam");

		  return ;
	  }
	if(OdaListesi.at(OdaIndex).MaxPara/10 > OyunToplamPara)
	{
	  OdaIndex++  ;
	  goto Devam;
	}

	int sayi=  OdaListesi.at(OdaIndex).MaxOtur;
		if(sayi<1)
	{
	  OdaIndex++  ;
	  goto Devam;
	}


	MasaBuy->Text =IntToStr(OdaListesi.at(OdaIndex).MaxPara/10);
	OdaGir(OdaListesi.at(OdaIndex).OdaNo);


	Form1->Memo3->Lines->Clear();
	Form1->Memo3->Lines->Add("Odaya Giriliyor OdaNo="+IntToStr(OdaListesi.at(OdaIndex).OdaNo));
	Form1->Memo3->Lines->Add("MinPra="+IntToStr(OdaListesi.at(OdaIndex).MaxPara/10) );
	Form1->Memo3->Lines->Add("MinPot="+IntToStr(OdaListesi.at(OdaIndex).MinPot) );
	Form1->Memo3->Lines->Add("MaxPot="+IntToStr(OdaListesi.at(OdaIndex).MaxPot) );
	CiftKart->Caption=IntToStr(OdaIndex)+":"+ IntToStr((int)OdaListesi.size())+"ms:"+IntToStr(MesajSayac);
	OdaIndex++;
	markTurnTime->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
//   WebBrowser1-
WebBrowser1->Navigate("http://www.facebook.com");
Application->ProcessMessages();
 while(WebBrowser1->ReadyState!=4)
 {
	 Sleep(100);
	 Application->ProcessMessages();

 }
//WB_Post(WebBrowser1);
try{
WB_PostFormName(WebBrowser1,"logout_form");
}
catch(...)
{
	return;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::YenileClick(TObject *Sender)
{
//if(DLLADRES1==0)return;
//HANDLE a=0;
//
//a=GetModuleHandle("Flash10l.ocx") ;
//
//if(a!=0)
//{
//DWORD b=(DWORD)a;
//DWORD c=b;
////b+=(0x10304754-0x10000000) ;
////b+=(0x10475824-0x10000000) ;
//b+=(DLLADRES1-0x10000000) ;       //0x10476800
//c+=(DLLADRES2-0x10000000) ;
//DWORD x;
//
//DWORD p=0;
//VirtualProtect((void*)b,12,PAGE_READWRITE,&p);
//asm{
//	mov eax,b
//	mov ebx, offset MyRecv
//
//	mov [eax],ebx
//	mov eax,c
//	mov ebx, offset  MySend
//
//	mov [eax],ebx
//}
//
//}
 WebBrowser1->Navigate("http://www.facebook.com");
Application->ProcessMessages();
 while(WebBrowser1->ReadyState!=4)
 {
  //	 Sleep(100);
	 Application->ProcessMessages();

 }
 FlasKon->Enabled=true;
 int don=0;
 for(;;)
 {      if(don==6)
	   break;
	 Sleep(500);
	 Application->ProcessMessages();
	 don++;
 }
  Memo3->Lines->Add("Home bekleniyor");
/* for(;;)
{    Application->ProcessMessages();
	 AnsiString Adress= WideCharToAnsiString(WebBrowser1->LocationURL);
	 if(Adress.Pos("http://www.facebook.com/"))
	 {
	   break;
	 }
// WebBrowser1->
}   */

Button1->Click();
/*
Form1->Button17->Click();
WebBrowser1->Navigate("about:blank");
Application->ProcessMessages();
   while( WebBrowser1->ReadyState != 4 )
   {
	  Application->ProcessMessages();

   }


//ClearCache();
DeleteIECache();
ClearInternetExplorerHistory();

Form1->Button3->Click();
*/
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button13Click(TObject *Sender)
{
//if(GirisAktar=="")
// {
//	 return;
// }
//
// markTurnTime->Enabled=false;
// RelogTime->Enabled=false;
//Form3->GirisData=  GirisAktar;
//closesocket(OyunSocket);
//
//Form3->IdlerList->Items->Assign(LoginLerKayit->Items)  ;
//Form3->Show();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Kapan=true;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
Kapan=true;	
}
//---------------------------------------------------------------------------

