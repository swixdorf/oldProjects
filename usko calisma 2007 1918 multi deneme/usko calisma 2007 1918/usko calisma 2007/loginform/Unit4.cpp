//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//#include "Unit1.h"
#include "Unit4.h"
#include "ffrmBot.h"

#include "ThemidaSDK.h"
#include "keyuret.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

DWORD Version=278;
AnsiString host="www.kolebot.com";
int islem=0;
int deneme = 0 ;
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
AnsiString Path ;
BYTE MasterKey=122  ;
BYTE key=9;
int keykontrol=99;
AnsiString HDDNO = 123;
int socketdurum;
//---------------------------------------------------------------------------
int WINAPI ExxitThread(int a ){
Sleep(5000);
TerminateProcess(GetCurrentProcess(),0) ;
}
SocketIpUpdate(){
Form4->Button1->Enabled=false;
Form4->Button2->Enabled=false;
if (Form4->ClientSocket1->Active) {
Form4->ClientSocket1->Active=false;
Form4->ClientSocket2->Active=false;
Application->ProcessMessages();
Sleep(100);
Application->ProcessMessages();
Sleep(100);
}
int syer ;
if (socketdurum!=2) {
if ((Form4->ListBox1->ItemIndex +1)<Form4->ListBox1->Items->Count) {
syer = (Form4->ListBox1->ItemIndex +1);	
Form4->ListBox1->ItemIndex  = (Form4->ListBox1->ItemIndex +1);
}else{
syer = 0;
Form4->ListBox1->ItemIndex=0;
}

Form4->ClientSocket1->Host=Form4->ListBox1->Items->Strings[syer];
Form4->ClientSocket1->Port=Form4->ListBox2->Items->Strings[syer].ToIntDef(15333);

Form4->ClientSocket2->Host="31.210.68.131";
Form4->ClientSocket2->Port=15339;
}
Form4->ClientSocket1->Active=true;
Form4->ClientSocket2->Active=true;
}
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
if (key!=keykontrol) {
return false;
}
CODEREPLACE_START
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
CODEREPLACE_END
*(WORD*)&Buf[0]=ULEN;
memcpy(&Buf[2],&Donen[0],ULEN);

return true ;
}

bool AnsiStringTara(AnsiString a){
if (a=="") {
return false;
}
AnsiString asd="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
for (int i = 0; i < a.Length(); i++) {
if (asd.AnsiPos(a.SubString(i+1,1))==0) {
return false;
}
}
return true;
}

void __fastcall TForm4::Button1Click(TObject *Sender)
{
if(bAutoLogin)
{
	if (ListBox1->Items->Count<1)
	{
		while(ListBox1->Items->Count<1)
		{
			ClientSocket3->Active=false;
			host="www.onlinehile.org";
			ClientSocket3->Host=host;
			ClientSocket3->Active=true;
			Sleep(1000);
        }
	}
}
else
{
if (ListBox1->Items->Count<1) {
ShowMessage("Ip Listesi Alinamadi Tekrar Deneyin");
ClientSocket3->Active=false;
host="www.onlinehile.org";
ClientSocket3->Host=host;
ClientSocket3->Active=true;
return;
}
}

if (!AnsiStringTara(Edit1->Text)) {
ShowMessage("Kullanici adinda hatali karakterler var");
return;
}
if (!AnsiStringTara(Edit2->Text)) {
ShowMessage("Sifrede hatali karakterler var");
return;
}
islem=0;
socketdurum=0;
SocketIpUpdate();
Timer2->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm4::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
if (deneme>3) {
TerminateProcess(GetCurrentProcess(),0) ;
}
socketdurum=2;
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
			case 0x00:ShowMessage("Yeni Versiyonumuzu www.kolebot.com dan indirebilirsiniz");TerminateProcess(GetCurrentProcess(),0);break;
			case 0x01:{
			BYTE Send[1024];
			if (islem==0) {
			int Yer=0;
Send[Yer]=0x01;
Yer++;
Send[Yer]=Edit1->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit1->Text.c_str(),Edit1->Text.Length());
Yer+=Edit1->Text.Length();
Send[Yer]=Edit2->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit2->Text.c_str(),Edit2->Text.Length());
Yer+=Edit2->Text.Length();
Send[Yer]=HDDNO.Length();
Yer++;
memcpy(&Send[Yer],HDDNO.c_str(),HDDNO.Length());
Yer+=HDDNO.Length();

PacketSifrele(Send,Yer,keykontrol);
Socket->SendBuf(Send,*(WORD*)&Send[1]);
			}else if (islem==1) {
int Yer=0;
Send[Yer]=0x04;
Yer++;
Send[Yer]=Edit4->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit4->Text.c_str(),Edit4->Text.Length());
Yer+=Edit4->Text.Length();
Send[Yer]=Edit5->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit5->Text.c_str(),Edit5->Text.Length());
Yer+=Edit5->Text.Length();
Send[Yer]=Edit3->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit3->Text.c_str(),Edit3->Text.Length());
Yer+=Edit3->Text.Length();
PacketSifrele(Send,Yer,keykontrol);
Socket->SendBuf(Send,*(WORD*)&Send[1]);
			}else if (islem==2){
int Yer=0;
Send[Yer]=0xa;
Yer++;
Send[Yer]=Edit1->Text.Length();
Yer++;
memcpy(&Send[Yer],Edit1->Text.c_str(),Edit1->Text.Length());
Yer+=Edit1->Text.Length();

Send[Yer]=HDDNO.Length();
Yer++;
memcpy(&Send[Yer],HDDNO.c_str(),HDDNO.Length());
Yer+=HDDNO.Length();

PacketSifrele(Send,Yer,keykontrol);
Socket->SendBuf(Send,*(WORD*)&Send[1]);
            }else if (islem==3){
//int Yer=0;
//Send[Yer]=0x99;
//Yer++;
//Send[Yer]=Edit7->Text.Length();
//Yer++;
//memcpy(&Send[Yer],Edit7->Text.c_str(),Edit7->Text.Length());
//Yer+=Edit7->Text.Length();
//Send[Yer]=Edit8->Text.Length();
//Yer++;
//memcpy(&Send[Yer],Edit8->Text.c_str(),Edit8->Text.Length());
//Yer+=Edit8->Text.Length();
//Send[Yer]=Edit9->Text.Length();
//Yer++;
//memcpy(&Send[Yer],Edit9->Text.c_str(),Edit9->Text.Length());
//Yer+=Edit9->Text.Length();
//PacketSifrele(Send,Yer,keykontrol);
//Socket->SendBuf(Send,*(WORD*)&Send[1]);
			}

			}break;
			default:
				;
			}
		 }break;
		 case 0x1: {
			switch (KomutBuf[3]) {
			case 0x00:Button1->Enabled=true;Button2->Enabled=true;ShowMessage("Sureniz Dolmustur.");TerminateProcess(GetCurrentProcess(),0);break;
			case 0x01:Button1->Enabled=true;Button2->Enabled=true;deneme++;ShowMessage("Kullanici Adi Sifre Hatali");;break;
			case 0x02:Button1->Enabled=true;Button2->Enabled=true;TerminateProcess(GetCurrentProcess(),0);break;
			default:
				;
			}
		 }break;
				 case 0x2: {
			switch (KomutBuf[3]) {
			case 0x00:{

			 //	 memcpy(&Data1,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x01;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x01:{
			  //	 memcpy(&Data2,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x02;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x02:{
			 //	 memcpy(&Data3,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x03;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x03:{
			 //	 memcpy(&Data4,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x04;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x04:{
			//	 memcpy(&Data5,&KomutBuf[4],128);
				 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=0x05;
				 PacketSifrele(&Komut[0],2,keykontrol);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			}break;
			case 0x05:{

//DllRunDll deneme;
//ModulAl=  Manueldll("KODLL","KODLLNAME");
//
//deneme = (DllRunDll) MemoryGetProcAddress(ModulAl,"DllRun");
//
//deneme(DLLPATH,ModulAl) ;
//PageControl1->TabIndex=1;
//Form1->Visible=false;
//LastAliveTime=GetTickCount();
//Client.awuerde=true;
//if (!Client.AutoLogin) {
//
//Form1->Show();
//Form4->Hide();
//}			 bPacketKey = 0x31;
			 dwMyID = _CCharBase.GetID();
			 DWORD dwSockBase = *(DWORD*)(KO_SOCK);
			 DWORD dwSockHandle = *(DWORD*)(dwSockBase + 0x4);
			dwRecvdSockHandle = dwSockHandle;

			BYTE bSendAdd = (BYTE)((DWORD)&SendFunction % 10);
			__asm{NOT bSendAdd};
			dwSendPointerAdd = bSendAdd;

			frmBot = new TfrmBot(NULL);

			Application->CreateForm(__classid(TfrmBot), &frmBot);

			frmBot->Show();

			SetForegroundWindow(frmBot->Handle);
            Form4->Hide();
			}break;
			}
			}break;
case 0xdd:{
Form4->Timer3->Enabled=true;
int a=KomutBuf[3];
String mesaj = "Giris Tamam Kalan Gun : "+IntToStr(a);
if (a==199) {
mesaj = "18-21 ucretsiz saat";
}
//if (!Client.AutoLogin) {
if(bAutoLogin == false)
ShowMessage(mesaj);
//}
}break;
case 0x4:{
switch (KomutBuf[3])
{
case 0 : {
ShowMessage("Kullanici Adi Kullanimda") ;
Button1->Enabled=true;
Button2->Enabled=true;
}break;
case 1 : {
ShowMessage("Kayit Tamam Giris Yapabilirsiniz") ;
Button1->Enabled=true;
Button2->Enabled=true;
}break;
case 2 : {
deneme++;
ShowMessage("Hatali Kod") ;
Button1->Enabled=true;
Button2->Enabled=true;
}break;
case 3 : {
ShowMessage("Kullanici adi sifre min 4 karakter ve birbirine esit olmamalidir") ;
Button1->Enabled=true;
Button2->Enabled=true;
}break;
}
}break;
case 0xa:{
if (KomutBuf[3]==0) {
ClientSocket1->Active=false;
Timer4->Enabled=true;
//Form1->Hide();
//Form1->Enabled=false;
ShowMessage("Hesabiniza baska bilgisayardan giris yapildi. Knight OnLine 2 Dakika Icerisinde Town Atip Kapatilacaktir");
}else{
ClientSocket1->Active=false;
}
}break;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
		Timer1->Enabled = false;

			Edit1->Text = strBotID;
			Edit2->Text = strBotPW;
			this->Button1Click(NULL);

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
if (ListBox1->Items->Count<1) {
ShowMessage("Ip Listesi Alinamadi Tekrar Deneyin");
host="www.onlinehile.org";
ClientSocket3->Active=false;
ClientSocket3->Host=host;
ClientSocket3->Active=true;
return;
}
if (Edit6->Text!=Edit5->Text) {
ShowMessage("Sifreler Uyusmuyor");  
}else{
if (!AnsiStringTara(Edit4->Text)) {
ShowMessage("Kullanici adinda hatali karakterler var");
return;
}
if (!AnsiStringTara(Edit5->Text)) {
ShowMessage("Sifrede hatali karakterler var");
return;
}
islem=1;
SocketIpUpdate();
Timer2->Enabled=true;
}
}

//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{


HDDNO =KeyUret("13-08-2011");
Randomize();
AnsiString Path=ExtractFilePath(AnsiString(Application->ExeName));
Timer5Timer(0);
Form4->Height = 220;

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------




void __fastcall TForm4::ClientSocket1Error(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{

/////////////////////////
///////////////////////
if(bGameLoaded)	//zaaaaaa :D
{
	Socket->Close() ;
	ClientSocket1->Active=false;
	ErrorCode = 0 ;
	Timer2Timer(0);
	return;
}

if(bAutoLogin)
{
	//ShowMessage("server bağlantisinda sorun yasandi. oto login araliklarla bağlanmayi deneyecek...");
	Socket->Close() ;
	ClientSocket1->Active=false;
	ErrorCode = 0 ;
	Timer2Timer(0);
	Sleep(5000);
	this->Button1Click(NULL);
}
else
{
	ShowMessage("Server Hata. Bir Sure Sonra Tekrar Deneyin");
	Socket->Close() ;
	ClientSocket1->Active=false;
	ErrorCode = 0 ;
	Timer2Timer(0);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm4::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
socketdurum=1;
//islem=0;
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

void __fastcall TForm4::Timer2Timer(TObject *Sender)
{

if (socketdurum<2) {
ClientSocket1->Active=false;
ClientSocket1->Socket->Close();
Button1->Enabled=true;
Button2->Enabled=true;

Button1->Caption="Tekrar Baglan";
}
Timer2->Enabled=false;
}
//---------------------------------------------------------------------------





void __fastcall TForm4::Timer4Timer(TObject *Sender)
{
	StopBot();
	BYTE pSend[1] = {0x48};
	_CPacket.PSend(pSend,1);
	Sleep(2500);
	pSend[1] = 0x00;
	_CPacket.PSend(pSend,1);
TerminateProcess(GetCurrentProcess(),0);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer3Timer(TObject *Sender)
{
islem=2;
ClientSocket1->Active=false;
Application->ProcessMessages();
Sleep(100);
Application->ProcessMessages();
Sleep(100);

ClientSocket1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
Button3->Enabled=false;
GroupBox2->Visible=true;
Form4->Height=405;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::chloadClick(TObject *Sender)
{
	bLoadSettings = chload->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::chinterclientClick(TObject *Sender)
{
	bInterClient = chinterclient->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
	MakeCaption();
	//tmdebugger->Enabled = true;

	if(bAutoLogin == true)
	{
		Timer1->Enabled = true;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket2Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
Socket->Close();
ClientSocket2->Active=false;
ErrorCode=0;
Timer6->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::ClientSocket2Read(TObject *Sender, TCustomWinSocket *Socket)

{
String buf = Socket->ReceiveText();
if (buf == "Exit") {
	TerminateProcess(GetCurrentProcess(),0);
	return;
}
if (buf == "Town") {

	return;
}
if (buf == "Info") {
//String buffer = "usko "+Client.CharId +" "+Edit1->Text + "," + Client.Kmt1;
//Socket->SendText(buffer);
	return;
}

//WebBrowser1->Navigate(buf) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer6Timer(TObject *Sender)
{
Timer6->Enabled=false;

ClientSocket2->Active=false;
ClientSocket2->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket2Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{

ClientSocket2->Active=false;

Timer6->Enabled=true;
}
//---------------------------------------------------------------------------




void __fastcall TForm4::ClientSocket3Connect(TObject *Sender, TCustomWinSocket *Socket)

{
String a = "GET /ips.txt HTTP/1.1\r\n";
a += "Host: "+host+"\r\n\r\n";
Socket->SendText(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket3Read(TObject *Sender, TCustomWinSocket *Socket)

{
ListBox1->Items->Clear();
ListBox2->Items->Clear();
int len = Socket->ReceiveLength();
char gln[1024];
gln[len]=0;
Socket->ReceiveBuf(gln,len);


String v = String(gln);

AnsiString a = v;
for (int i = 0; i < 20; i++) {
int bas = a.AnsiPos("---");
int portbas = a.AnsiPos(":::");
int son = a.AnsiPos(";;;");
if ((bas<son)&&(portbas<son)&&(portbas>bas)) {
AnsiString ip = a.SubString(bas+3,portbas-bas-3);
AnsiString port = a.SubString(portbas+3,son-portbas-3);
a= a.SubString(son+3,a.Length()-son);
if ((ip!="")||(port!="")) {
ListBox1->Items->Add(ip);
ListBox2->Items->Add(port);
server->Items->Add("Server "+ IntToStr(i+1));
}
}
}

}
//---------------------------------------------------------------------------




void __fastcall TForm4::ClientSocket4Connect(TObject *Sender, TCustomWinSocket *Socket)

{
Randomize();
String txtx= "index.php?page=urunler&urun=" +IntToStr(Random(50));
String a = "GET /"+txtx+" HTTP/1.1\r\n";
a += "Host: www.gamecrea.com\r\n\r\n";
Socket->SendText(a);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer5Timer(TObject *Sender)
{
ClientSocket4->Active=false;

ClientSocket4->Active=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm4::serverChange(TObject *Sender)
{
ListBox1->ItemIndex=server->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket4Read(TObject *Sender, TCustomWinSocket *Socket)

{
Socket->ReceiveText();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket3Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode = 0 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ClientSocket4Error(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode = 0 ;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button4Click(TObject *Sender)
{
Button3->Enabled=true;
GroupBox2->Visible=false;
Form4->Height = 220;
}
//---------------------------------------------------------------------------

