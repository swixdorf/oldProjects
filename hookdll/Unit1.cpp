//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <ScktComp.hpp>
#include "ProcScan.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
 SOCKET OyunSocket;
typedef int (WINAPI* r_send)(SOCKET sock, BYTE* buf, int len, int flags);
r_send osend;

typedef int (WINAPI* r_recv)(SOCKET sock, BYTE* buf, int len, int flags);
r_recv orecv;

  int __stdcall SahteRecv(SOCKET s, char *buf, int len, int flags)
  {
		memset(buf,0,len);
		int rlen=   orecv(s, buf,len,flags);
		if(rlen==-1)
		{

		 return rlen;
		}

		int index=0;
Devam:
AnsiString a=AnsiString((char* )&buf[index]);
int Par;//= Yaz(a,buf,&rlen);

if( Par==255)
return -1;
 int clen= a.Length();

if((clen+index+2)<rlen)
{
 index+= clen+1     ;
goto  Devam ;
}
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
 char buffer[4096];
 memset(buffer,4096,0);

 strncpy(buffer,buf,len);

Form1->Memo1->Lines->Add( buffer); ;

  if(AnsiString(buf).Pos("login z='TexasHoldemUp"))
	 {

GirisAktar= AnsiString(buf) ;
TStringList *s =new TStringList();

	   s->Add(GirisAktar) ;
	   TDateTime a ;
		a = a.CurrentDateTime();
	   String name = a.DateTimeString();
	   String buf;
	   for (int i = 0; i < name.Length(); i++)
	   {
		if (name.SubString(i,1)!=":"&&name.SubString(i,1)!="."&&name.SubString(i,1)!=" ") {
			buf +=name.SubString(i,1);
		}
	   }
	   s->SaveToFile("c:\\"+buf+".acc");
	   s->Free();
	   //ShowMessage("Kayit Alindi");

	   }




   return osend(s, buf,len,flags);
 }

 
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
osend         = (r_send) GetProcAddress(GetModuleHandle("ws2_32.dll"), "send"); //gets original address for send
orecv         = (r_recv) GetProcAddress(GetModuleHandle("ws2_32.dll"), "recv"); //for recv same as above
HANDLE a=0;


   AnsiString NameDll= "Flash10l.ocx";
if(!ListProcessModules(GetCurrentProcessId(),NameDll)) return ;

a=GetModuleHandle(NameDll.c_str()) ;

if(a==0)
{
	return  ;
}

BuildImportTable((DWORD)a,(DWORD)MyRecv,"16","WS2_32.dll");
BuildImportTable((DWORD)a,(DWORD)MySend,"19","WS2_32.dll");
ShowMessage("done");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
String a[7] ={
"4 stat 18:36392551061 server Poker%20SN%20Lobby%20Other%20FeedDataLoadTimeout%20o%3ASmartfox%3A2010-08-30:1",
"4 stat 18:36392551061 server Poker%20SN%20Canvas%20Other%20Click%20o%3ASideNav%3ALuckyBonus%3A2012-05-15:1",
"<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><obj t='o' o='param'><var n='messageName' t='s'>saveUserPrefsMsg</var><var n='_cmd' t='s'>javascriptToSmartfoxMsg</var><var n='prefs' t='s'>%7B%22normalFilterValue%22%3A%22All%22%7D</var></obj><var n='name' t='s'>texasLogin</var><var n='cmd' t='s'>javascriptToSmartfoxMsg</var></dataObj>]]></body></msg>",
"4 stat 18:36392551061 server Poker%20SN%20Canvas%20Other%20Impression%20o%3ACDNTest%3AAKAMAI%3AFailed%3AJS2SWF%3A2012-03-23:1",
"4 stat 18:36392551061 server Poker%20SN%20Canvas%20Other%20Impression%20o%3ACDNTest%3AZGNCDN%3AFailed%3AJS2SWF%3A2012-03-23:1",
"4 stat 18:36392551061 server Poker%20SN%20Canvas%20Other%20Click%20o%3ASideNav%3AScratchers%3A2012-07-16:1",
"4 stat 18:36392551061 server Poker%20SN%20Canvas%20Other%20Impression%20o%3AScratchers%3A2012-07-16:1"
};
for (int i = 0; i < 7; i++) {
osend(OyunSocket,a[i].c_str(),a[i].Length() +1,0) ;

}

}
//---------------------------------------------------------------------------



