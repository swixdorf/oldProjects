//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TForm2 *Form2;


TTime CurrentTime;
String DbName = "bot_program";


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
 /*
MYSQL_RES *MakeQuery(String Query){
/*
MYSQL *mysql;
mysql=mysql_init(NULL);
MYSQL *Connection;
Connection=mysql_real_connect(mysql, "farmersbot.com", "bot_program", "201987", "bot_program", 3306, NULL, 0);
if (Connection) {
mysql_query(Connection,Query.c_str());

return mysql_use_result(Connection);

}else{
return false;
} *
} */
//---------------------------------------------------------------------------
BYTE CalculateDays(String Time){
if ((Time=="0")||Time=="") {
return 0  ;
}

//String yil,ay,gun,saat,dakika,saniye ;
//yil= Time.SubString(1,4);
//ay= Time.SubString(6,2);
//gun= Time.SubString(9,2);
//saat= Time.SubString(12,2);
//dakika= Time.SubString(15,2);
//saniye= Time.SubString(18,2);
//String Date = gun + "." + ay + "." +yil + " " + saat + ":" + dakika + ":" + saniye;

TDateTime ExpDate = StrToDateTime(Time);
TDateTime Current = Current.CurrentDateTime();
WORD aaa,bbb,ccc;
WORD aa1,bb1,cc1;

ExpDate.DecodeDate(&aaa,&bbb,&ccc);
Current.DecodeDate(&aa1,&bb1,&cc1);
int a = (bbb-bb1)*30+ccc-cc1+1 ;

if (ExpDate>Current) {
return a;
}else{
return 0;

}

}
void __fastcall ErrorLogla(TDataSet *DataSet, EDatabaseError *E,
		  TDataAction &Action){

		  }

bool AnsiStringTara(AnsiString a){
if (a=="") {
return false;
}
AnsiString asd="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.";
for (int i = 0; i < a.Length(); i++) {
if (asd.AnsiPos(a.SubString(i+1,1))==0) {
return false;
}
}
return true;
}

int LoginControl(String Username, String Password, String hdd, String Ip, BYTE *Time){

TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=DbName+"ses";
Q->OnPostError= Form1->Query1->OnPostError;
Q->SQL->Clear();
String Query;
try {
if (!(AnsiStringTara(Username)&&AnsiStringTara(Password)&&AnsiStringTara(hdd)&&AnsiStringTara(Ip)))
return 2;

Query ="SELECT * FROM users WHERE user_name = '";
Query+=Username+"' and user_pwd = '";
Query+=Password+"' and user_active = '1'";
Q->SQL->Add(Query) ;
Q->Open();
if (Q->RecordCount>0) {
*Time=CalculateDays(Q->FieldByName("user_expire_date")->Value);
Q->Close();

if (Time<=0) {
Q->Free();
return 1 ;
}
Q->SQL->Clear();
Query="UPDATE  users SET user_hdd='"+hdd+"', user_lastlogin = NOW() , user_ip = '"+Ip+"' WHERE user_name = '";
Query+=Username+"' and user_pwd = '";
Query+=Password+"' and user_active = '1'";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
Q->Free();
return 0 ;
}else{
Q->Close();
Q->Free();
return 2 ;
}
} catch (...) {
Form1->Memo2->Lines->Add("Login Error!!!");
Form1->Memo2->Lines->Add(Query);
return 2 ;
}

  /*
String Query ="SELECT * FROM users WHERE user_name = '";
Query+=Username+"' and user_pwd = '";
Query+=Password+"' and user_active = '1'";

MYSQL_RES *Result;
Result = MakeQuery(Query);
MYSQL_ROW Row;
Row = mysql_fetch_row(Result);


if (Row) {
if (CalculateDays(String(Row[7]))) {
Query="UPDATE  users SET user_hdd='"+hdd+"', user_ip = '"+Ip+"' WHERE user_name = '";
Query+=Username+"' and user_pwd = '";
Query+=Password+"' and user_active = '1'";
Form1->Memo1->Lines->Add(Query) ;
Result = MakeQuery(Query);
return 0 ;
}else{
return 1 ;
}


}else{
return 2 ;
}  */
}

int RegisterControl(String Username, String Password, String esn){
if ((Username==Password)||(Username.Length()<4)||(Password.Length()<2)||(esn.Length()<12)) {
return 3;
}
if (!(AnsiStringTara(Username)&&AnsiStringTara(Password)&&AnsiStringTara(esn)))
return 3;
TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=	DbName+"ses";
//Q->OnPostError= ErrorLogla;
Q->SQL->Clear();
String Query;
try {
Query ="SELECT * FROM users WHERE user_name = '"+Username+"'";
Q->SQL->Add(Query) ;
Q->Open();
if (Q->RecordCount>0) {
Q->Close();
Q->Free();
return 0 ;  //kullanici var
}else{
Q->Close();
Q->SQL->Clear();

Query ="SELECT * FROM codes WHERE code_esn = '"+esn+"' and code_active='1'";
Q->SQL->Add(Query) ;
Q->Open();

if (Q->RecordCount>0) {
String codeindex = Q->FieldByName("code_id")->Value;
String codetime	 = Q->FieldByName("code_time")->Value;

Q->Close();
Q->SQL->Clear();

Query ="UPDATE  codes SET code_active='0',code_load_time=NOW()   WHERE code_id = '"+ codeindex +"'";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
Q->SQL->Clear();

Query ="INSERT INTO  users (user_id ,reseller ,user_name ,user_pwd ,user_hdd ,user_active ,user_active_code, user_expire_date,user_ip,user_lastlogin,user_lastalive) VALUES (NULL ,  '0',  '"+Username+"',  '"+Password+"',  '0',  '1',  '"+codeindex+"',DATE_ADD(NOW(), INTERVAL "+codetime+" DAY),'1',NOW(),NOW() );";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
Q->SQL->Clear();

Query ="SELECT * FROM users WHERE user_name = '"+Username+"'";
Q->SQL->Add(Query) ;
Q->Open();
if (Q->RecordCount>0) {
String userid = Q->FieldByName("user_id")->Value;
Q->Close();
Q->SQL->Clear();

Query ="UPDATE  codes SET code_buyer='"+userid+"' WHERE code_id = '"+ codeindex +"'";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
Q->SQL->Clear();
}
Q->Free();
return 1 ;        //ok
}else{
Q->Close();
Q->Free();
return 2;         //kod hata
}
}
} catch (...) {
Form1->Memo2->Lines->Add("Register Error!!!");
Form1->Memo2->Lines->Add(Query);
return 2;
}
}



bool AliveControl(String Username,String hdd){
TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=	DbName+"ses";
Q->SQL->Clear();
String Query ="SELECT * FROM users WHERE user_name = '";
try{
if (!(AnsiStringTara(Username)&&AnsiStringTara(hdd)))
return 0;
Query+=Username+"' and user_hdd = '";
Query+=hdd+"' and user_active = '1'";
Q->SQL->Add(Query) ;
Q->Open();
if (Q->RecordCount>0) {
int Time=CalculateDays(Q->FieldByName("user_expire_date")->Value);
int userid = Q->FieldByName("user_id")->Value;


Q->Close();
Q->SQL->Clear();
Query="UPDATE  users SET  user_lastalive = NOW() WHERE user_id = '";
Query+=IntToStr(userid)+"';";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
if (Time<=0) {
Q->Free();
return 0 ;
}else{
Q->Free();
return 1 ;
}
}else{
Q->Free();
return 0 ;
}
} catch (...) {
Form1->Memo2->Lines->Add("Alive Error!!!");
Form1->Memo2->Lines->Add(Query);
return 1;
}



/*String Query ="SELECT * FROM users WHERE user_name = '";
Query+=Username+"' and user_pwd = '";
Query+=Password+"' and user_hdd = '";
Query+=hdd+"' and user_active = '1'";

MYSQL_RES *Result;
Result = MakeQuery(Query);
MYSQL_ROW Row;
Row = mysql_fetch_row(Result);


if (Row) {
if (CalculateDays(String(Row[7]))) {
return true ;
}else{
return false ;
}


}else{
return false ;
} */
}







DWORD Version;
String ByteToString(char *buf,int size)
{
String str="";
for(int i=0;i<size;i++)
{
str+=StringOfChar(buf[i],1);
}
return str;
}
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
BYTE MasterKey=122  ;
BYTE key=9;
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
BYTE PacketCoz(char *Buf,WORD Len)
{
BYTE Donen[1024];
WORD ULEN=(Len-7)/2;
memset(&Donen,0,1024);
BYTE MKey=Buf[0]+Buf[3]+Buf[Len-1];
BYTE key=Buf[4]+Buf[Len-2];
//if (Form1->Key->Lines->IndexOf(key)==-1) {
//return 0;
//}
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
return key;
}
BYTE Data1[128]={
0x4D,0x5A,0x50,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x0F,0x00,0xFF,0xFF,0x00,0x00,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0xBA,0x10,0x00,0x0E,0x1F,0xB4,0x09,0xCD,0x21,0xB8,0x01,0x4C,0xCD,0x21,0x90,0x90,0x54,0x68,0x69,0x73,0x20,0x70,0x72,0x6F,0x67,0x72,0x61,0x6D,0x20,0x6D,0x75,0x73,0x74,0x20,0x62,0x65,0x20,0x72,0x75,0x6E,0x20,0x75,0x6E,0x64,0x65,0x72,0x20,0x57,0x69,0x6E,0x33,0x32,0x0D,0x0A,0x24,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

BYTE Data2[128]={
0x69,0x00,0x19,0x53,0x12,0xDC,0xEA,0x76,0x6C,0xCB,0x1A,0x26,0x91,0x9B,0x71,0x76,0xF5,0x36,0x30,0x52,0x70,0x91,0x3A,0x26,0xAE,0x7C,0xF2,0xED,0xB1,0xFA,0x40,0xA1,0x89,0xAE,0xB8,0x8D,0xEC,0xAA,0x54,0x31,0x21,0x40,0x22,0x43,0x46,0xD6,0x9C,0xDE,0xC9,0x6B,0xE8,0x98,0xFF,0x7D,0xA9,0xCF,0xC6,0x83,0x36,0xF6,0xBD,0x69,0x11,0xA5,0x0A,0xD0,0x88,0xEB,0xED,0x96,0x34,0x2E,0xA3,0x9D,0xA1,0x2E,0x55,0x67,0x6E,0xF8,0xC9,0xDA,0x22,0x50,0xFA,0x66,0x00,0x90,0xFF,0xA4,0xE1,0xE4,0x18,0x10,0x87,0x37,0x6C,0x75,0xC8,0x1C,0x2F,0xF9,0x02,0xA3,0x1B,0xAD,0x31,0xB0,0xDF,0x3F,0x05,0x5F,0x25,0x1F,0xF7,0x94,0x95,0x02,0xFD,0xB0,0x54,0xBE,0xC2,0xF5,0xC8,0x42,0xF7,0xDE,
};

BYTE Data3[128]={
0xAD,0xC3,0x14,0xDD,0x86,0x21,0xA0,0x61,0x26,0x5F,0x35,0x83,0xA0,0x9E,0x34,0xEA,0xE0,0xC9,0x23,0x35,0xCD,0xDB,0xA3,0x89,0xAE,0x61,0xE6,0x31,0xA3,0x63,0xDC,0xAD,0xD2,0x61,0x0B,0x0F,0x35,0xCE,0x26,0x8D,0x6E,0x63,0xE6,0xD4,0xCB,0xA1,0x2E,0x97,0x32,0x1A,0x21,0x22,0xCD,0x63,0x0B,0x34,0xF6,0xE7,0x35,0x79,0x26,0xAD,0xD3,0xF4,0xDD,0x2D,0x53,0x62,0x15,0xED,0x16,0x73,0x06,0xB6,0xE7,0x5C,0x13,0x2E,0xC4,0x7A,0xE1,0x3B,0xE4,0x2D,0xCD,0xAB,0xA0,0x2F,0xED,0x3E,0x67,0x81,0x27,0x34,0xC7,0x27,0x94,0x33,0x67,0xDB,0x34,0x9B,0x0A,0xD4,0x5E,0x27,0x2F,0xA1,0xFE,0xE4,0x4A,0x36,0x5B,0xA6,0x8F,0x5D,0x1D,0xF9,0x06,0x12,0x82,0x7F,0x7A,0xC3,0x22,0xAF,0xBA,0x53,


};

BYTE Data4[128]={
0xD9,0x08,0xF2,0xD3,0xE7,0x0E,0x74,0x81,0xB5,0x37,0xD9,0x80,0x62,0xB1,0xC7,0x60,0x32,0xC7,0x48,0xB3,0x34,0xC1,0x3F,0x04,0x23,0x5C,0x13,0x3D,0xBE,0xA2,0x47,0x4B,0x03,0x3A,0x34,0x24,0xD9,0x84,0x67,0x70,0xDD,0xEC,0x67,0xB0,0x52,0xA8,0x35,0x22,0x99,0xB7,0x66,0xB6,0x04,0xB9,0xFD,0xEF,0x00,0xA2,0xE7,0x78,0xB6,0x1A,0x2D,0xD8,0x71,0x7A,0x35,0x00,0xED,0xC9,0xF4,0x2D,0x2E,0xE1,0xCB,0xB7,0x17,0xB8,0x38,0xB5,0x03,0xD9,0x9C,0x62,0xB7,0xC7,0x7C,0x32,0xC7,0xA4,0xB1,0x34,0xD5,0x3F,0x04,0x2C,0x5C,0x6F,0x3D,0xBB,0xA2,0x47,0xA7,0x01,0x3A,0x34,0x30,0xD9,0x90,0x67,0x76,0xDD,0xF8,0x67,0xB6,0x06,0xD1,0x61,0x2F,0x0A,0x35,0x83,0xB4,0xED,0xBA,0x53,0x04,0xFB,
};

BYTE Data5[128]={
0x9F,0x09,0x21,0x02,0x5E,0x4A,0x75,0x80,0x17,0x62,0x1E,0xFE,0xA1,0x8B,0x06,0xC0,0x43,0x50,0x63,0x61,0x0C,0x08,0x2D,0x29,0xF4,0x4A,0x1D,0xC3,0x83,0x51,0x6B,0x01,0xCA,0x41,0xF4,0x08,0xE9,0xB9,0x44,0x14,0xBE,0x12,0x90,0x62,0x3C,0xB8,0x89,0x28,0x09,0xC4,0x10,0xB3,0xC7,0x37,0x1E,0x78,0x4F,0xEB,0xC9,0x64,0x75,0xFC,0xD1,0xE9,0xD1,0xE6,0x62,0xD3,0x50,0x7C,0xD9,0x86,0xCA,0x25,0x6A,0xB0,0x05,0xF1,0x84,0x85,0x0D,0x73,0xD5,0xE7,0xFA,0x0B,0x19,0x51,0xE0,0xF8,0x5D,0x09,0x27,0x57,0x1C,0xDE,0x15,0x56,0xA1,0xC6,0x74,0x3B,0x31,0x4C,0x71,0x2C,0x80,0x27,0xC2,0x14,0x84,0x7F,0x1E,0x31,0xB5,0xB2,0xC0,0x5D,0x42,0xD6,0x81,0x99,0x8E,0x6C,0x21,0x2A,0x07,0x7D,

};

//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
if (ListBox1->Items->IndexOf(Socket->RemoteAddress)!=-1) {
Socket->Close();
return ;
}else{
    Memo1->Lines->Add(Socket->RemoteAddress);
}




}
//---------------------------------------------------------------------------




void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode=0;
}
//---------------------------------------------------------------------------










//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
int glnlen=	 Socket->ReceiveLength();
 BYTE KomutBuf[1024];
		 if(glnlen>1024)
		 {
			 return;
		 }
		 Socket->ReceiveBuf(KomutBuf,glnlen) ;

 // Memo1->Lines->Add(BufferToHex(KomutBuf,glnlen));

		  if(KomutBuf[0]+KomutBuf[3]+KomutBuf[glnlen-1]!=MasterKey)
		  {
		  Socket->Close();
			  return  ;
		  }
		 BYTE kkey=PacketCoz(KomutBuf,glnlen)  ;
		 if (key==0){
		  Socket->Close();
			  return  ;
		 }

		 switch(KomutBuf[2])
		 {
		 case 0x0: {
		 if (*(DWORD*)&KomutBuf[3]!=Version->Text.ToIntDef(0)) {
		 BYTE Komut[16] ;
			 Komut[0]=0;
			 Komut[1]=0;//Version yanlis
				PacketSifrele(&Komut[0],2,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
				Socket->Close();
		 }else{                                               
         		 BYTE Komut[16] ;
			 Komut[0]=0;
			 Komut[1]=1;//Version Ok
				PacketSifrele(&Komut[0],2,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 }
		 }break ;
		 case 0x1: {
		 BYTE userlen=KomutBuf[3];
		 String Username=ByteToString(&KomutBuf[4],userlen);
		 BYTE passwordlen= KomutBuf[4+userlen];
		 String Password=ByteToString(&KomutBuf[5+userlen],passwordlen);
		 BYTE hddlen= KomutBuf[5+userlen+passwordlen];
		 String Hdd=ByteToString(&KomutBuf[6+userlen+passwordlen],hddlen);

		 if (Form1->free->Checked) {
 BYTE Komut[1024];

				 Komut[0]=0xdd;
				 Komut[1]=199;
				PacketSifrele(&Komut[0],2,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;

				 Komut[0]=0x02;
				 Komut[1]=0x00;
				 memcpy(&Komut[2],&Data1,128);
				PacketSifrele(&Komut[0],130,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 }else if(Username =="onlinehile"){
		 WORD h,m,s,ms;
		 CurrentTime.DecodeTime(&h,&m,&s,&ms);
		 if (0) {
          BYTE Komut[1024];

				 Komut[0]=0xdd;
				 Komut[1]=199;
				PacketSifrele(&Komut[0],2,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;

				 Komut[0]=0x02;
				 Komut[1]=0x00;
				 memcpy(&Komut[2],&Data1,128);
				PacketSifrele(&Komut[0],130,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 }else{
         BYTE Komut[16]={0x01,0x00};//expire
		 PacketSifrele(&Komut[0],2,kkey);
		 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Socket->Close();
		}
		 }else{

		 BYTE a;

		 switch (LoginControl(Username,Password,Hdd,Socket->RemoteAddress,&a)) {
		 case 0 :{
		 if (a<1) {
         BYTE Komut[16]={0x01,0x00};//expire
		 PacketSifrele(&Komut[0],2,kkey);
		 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Socket->Close();
		 }else{
		 Form1->Memo1->Lines->Add(a) ;
		 BYTE Komut[1024];

				 Komut[0]=0xdd;
				 Komut[1]=a;
				PacketSifrele(&Komut[0],2,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;

				 Komut[0]=0x02;
				 Komut[1]=0x00;
				 memcpy(&Komut[2],&Data1,128);
				PacketSifrele(&Komut[0],130,kkey);
				Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
         }
		 }break;
		 case 1 :{
		 BYTE Komut[16]={0x01,0x00};//expire
		 PacketSifrele(&Komut[0],2,kkey);
		 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Socket->Close();
		 }break;
		 case 2 :{
		 BYTE Komut[16]={0x01,0x01};//User Yok
		 PacketSifrele(&Komut[0],2,kkey);
		 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Socket->Close();
		 }break;
         default:
			 ;
		 }
		 }break;
		 }

		 case 0x2: {
			switch (KomutBuf[3]) {
//			case 0x01:{
//				 BYTE Komut[1024];
//				 Komut[0]=0x02;
//				 Komut[1]=0x01;
//				 memcpy(&Komut[2],&Data2,128);
//				 PacketSifrele(&Komut[0],130,kkey);
//				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
//			}break;
//			case 0x02:{
//				 BYTE Komut[1024];
//				 Komut[0]=0x02;
//				 Komut[1]=0x02;
//				 memcpy(&Komut[2],&Data3,128);
//				 PacketSifrele(&Komut[0],130,kkey);
//				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
//			}break;
//			case 0x03:{
//				 BYTE Komut[1024];
//				 Komut[0]=0x02;
//				 Komut[1]=0x03;
//				 memcpy(&Komut[2],&Data4,128);
//				 PacketSifrele(&Komut[0],130,kkey);
//				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
//			}break;
//			case 0x04:{
//				 BYTE Komut[1024];
//				 Komut[0]=0x02;
//				 Komut[1]=0x04;
//				 memcpy(&Komut[2],&Data5,128);
//				 PacketSifrele(&Komut[0],130,kkey);
//				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
//			}break;
			case 0x01:{
			 BYTE Komut[16];
				 Komut[0]=0x02;
				 Komut[1]=5;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
			Memo1->Lines->Add("Client Done : "+IntToStr(Socket->SocketHandle));
            Socket->Close();
			}break;
			default:
				;
			}
		 }break;
		 case 0x3: {
		 BYTE userlen=KomutBuf[3];
		 String Username=ByteToString(&KomutBuf[4],userlen);
		 BYTE Komut[16]={0x03,0x01};//User Var
		 PacketSifrele(&Komut[0],2,kkey);
		 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 }break;
		 case 0x4: {
		 BYTE userlen=KomutBuf[3];
		 String Username=ByteToString(&KomutBuf[4],userlen);
		 BYTE passwordlen= KomutBuf[4+userlen];
		 String Password=ByteToString(&KomutBuf[5+userlen],passwordlen);
		 BYTE esnlen= KomutBuf[5+userlen+passwordlen];
		 String esn=ByteToString(&KomutBuf[6+userlen+passwordlen],esnlen);
		 BYTE Sonuc = RegisterControl(Username,Password,esn);
				 BYTE Komut[16];
				 Komut[0]=0x04;
				 Komut[1]=Sonuc;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 }break;
		 case 0xA: {
		 		 BYTE userlen=KomutBuf[3];
		 		String Username=ByteToString(&KomutBuf[4],userlen);
				 if (Form1->free->Checked) {
		 BYTE Komut[16];
				 Komut[0]=0xa;
				 Komut[1]=1;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
				 }
				 else if(Username =="onlinehile")
				 {
					WORD h,m,s,ms;
					CurrentTime.DecodeTime(&h,&m,&s,&ms);
					if (0)
					{
		 BYTE Komut[16];
				 Komut[0]=0xa;
				 Komut[1]=1;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
				 Memo1->Lines->Add("Alive Done : "+Username);
					}else{
		 BYTE Komut[16];
				 Komut[0]=0xa;
				 Komut[1]=0;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Memo1->Lines->Add("Alive Error : "+Username);
				   }
				 }


				 else{
		 BYTE userlen=KomutBuf[3];
		 String Username=ByteToString(&KomutBuf[4],userlen);
		 BYTE passwordlen= KomutBuf[4+userlen];
		 String hdd=ByteToString(&KomutBuf[5+userlen],passwordlen);
		 if (AliveControl(Username,hdd)) {
		 BYTE Komut[16];
				 Komut[0]=0xa;
				 Komut[1]=1;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Memo1->Lines->Add("Alive Done : "+Username);
		 }else{
		 BYTE Komut[16];
				 Komut[0]=0xa;
				 Komut[1]=0;
				 PacketSifrele(&Komut[0],2,kkey);
				 Socket->SendBuf(Komut,*(WORD*)&Komut[1])  ;
		 Memo1->Lines->Add("Alive Error : "+Username);
		 }
		 }

		 }break;

		 default:

							  break;



		 }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::FormDestroy(TObject *Sender)
{
Query1->Close();
Database1->Connected=false;
Session1->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Memo1->Lines->SaveToFile("log.txt");
}
//---------------------------------------------------------------------------

DWORD Time[0xffffffff];

void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
	  TCustomWinSocket *Socket)
{
if (ListBox1->Items->IndexOf(Socket->RemoteAddress)!=-1) {
Socket->Close();
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
ListBox1->Items->Add(Edit1->Text);
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button5Click(TObject *Sender)
{
if (!free->Checked) {

Session1->SessionName= DbName+"ses";
Database1->SessionName = DbName+"ses";
Query1->SessionName = DbName+"ses";
Database1->Connected=true;
Session1->Active=true;
}
ServerSocket1->Active=true;

Caption=DbName+" - Acik";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
Database1->Connected=false;
Session1->Active=false;
ServerSocket1->Active=false;
Caption=DbName+" - Kapali";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
for (int i = 0; i < Memo1->Lines->Count; i++) {
if (ListBox2->Items->IndexOf(Memo1->Lines->Strings[i])==-1) {
ListBox2->Items->Add(Memo1->Lines->Strings[i]) ;
ListBox3->Items->Add(1) ;
}else{
int a = ListBox2->Items->IndexOf(Memo1->Lines->Strings[i]);
ListBox3->Items->Strings[a]=ListBox3->Items->Strings[a].ToIntDef(1)+1;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
ListBox1->Items->SaveToFile("ipban");	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
ListBox1->Items->LoadFromFile("ipban");	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
for (int i = 0; i < ListBox3->Items->Count; i++) {
if (ListBox3->Items->Strings[i].ToIntDef(1)>20) {
if (ListBox1->Items->IndexOf(ListBox2->Items->Strings[i])==-1) {
    ListBox1->Items->Add(ListBox2->Items->Strings[i]);
}
}
}
ListBox2->Items->Clear();
ListBox3->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
CurrentTime = CurrentTime.CurrentTime();
Button7Click(0);
Button10Click(0);
Memo1->Lines->Clear();
for (int i = 0; i <  ServerSocket1->Socket->ActiveConnections; i++) {
	if (ListBox1->Items->IndexOf(ServerSocket1->Socket->Connections[i]->RemoteAddress)!=-1) {
		ServerSocket1->Socket->Connections[i]->Close();        
	}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
Memo2->Lines->SaveToFile("hatalog.txt");	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

Session1->NetFileDir=ExtractFilePath(Application->ExeName);
Session1->PrivateDir=ExtractFilePath(Application->ExeName);
CurrentTime=CurrentTime.CurrentTime();
if (FileExists("ver")) {
TStringList *a= new TStringList();
a->LoadFromFile("ver");
Version->Text=a->Strings[0];
a->Free();
}
}
//---------------------------------------------------------------------------







void __fastcall TForm1::VersionChange(TObject *Sender)
{
TStringList *a= new TStringList();
a->Add(Version->Text);
a->SaveToFile("ver");
a->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
for (int i = 0; i <  ServerSocket1->Socket->ActiveConnections; i++) {
	if (ListBox1->Items->IndexOf(ServerSocket1->Socket->Connections[i]->RemoteAddress)!=-1) {
		ServerSocket1->Socket->Connections[i]->Close();        
	}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
ServerSocket1->Port=Edit3->Text.ToIntDef(15333);	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Database1AfterConnect(TObject *Sender)
{
Memo3->Lines->Add("Database Baglandi");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Query1PostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action)
{
Memo3->Lines->Add("Query Hata");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Database1AfterDisconnect(TObject *Sender)
{
Memo3->Lines->Add("Database Disconnect");
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Edit2Change(TObject *Sender)
{
DbName=Edit2->Text ;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (Form2==NULL) {
Form2 = new TForm2(NULL);
}

Form2->Show();
}
//---------------------------------------------------------------------------




