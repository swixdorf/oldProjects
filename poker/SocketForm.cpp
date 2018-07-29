//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Strutils.hpp>
#include "SocketForm.h"
#include "PokerAI.h"
//#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <vector>
//---------------------------------------------------------------------------
typedef struct{
			char OdaIsmi[35];
			int  OdaNo;
			int MinPot;
			int MaxPot;
			int MaxPara;
			int MaxOtur;
			int MinPara;
			int OdaTip;
}OdaListe;
OdaListe OdaListeEkle;
std::vector<OdaListe> OdaListesi;
 AnsiString Odalar="";
 int OdaIndex=0;

SocketThread *Socket_Thread;
TForm3 *Form3;
TStringList *Serverler;
 String UID,KoltukNo,Oda,OyunToplamPara,MasaPara,PostBling,NumberPlayer,MaxBuying;
 String MaxBling="0";
String SmallBling="0";
bool RoomAl=false;
int Relog=0;
int MesajSayac=0;
int GorSayac=0;
int ServerSayac=0;
  DWORD *AccountMesajSayi;


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

//Form3->MasaListNo->Items->Add(OdaNo);
if(Form3->CheckBox1->Checked )
{
Form3->MasaList->Items->Add(Utf8ToAnsi(OdaListeEkle.OdaIsmi)+"%"+OdaNo);
}

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
Form3->MasaListNo->Items->Clear();
Form3->MasaList->Items->Clear();

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
	// Form1->CiftKart->Caption="O.S="+ IntToStr((int)OdaListesi.size());
//	 Form1->Memo1->Lines->SaveToFile("odalar1.txt") ;
}


void OdaGir(AnsiString Oda)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Oda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
Form3->GirisServer1->SendBuf( Komut.c_str(),Komut.Length()+1);
}


void OdaRefres()
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><obj t='o' o='param'></obj><var n='name' t='s'>texasLogin</var><var n='cmd' t='s'>displayRoomList</var></dataObj>]]></body></msg>";
Form3->GirisServer1->SendBuf( Komut.c_str(),Komut.Length()+1);
}



bool MesajYolla(String Mesaj,String Oda)
  {
  PokerAI uret;
int count,charne;
char a;
String Hazirla=" ";
uret.getRandNumber(1,3,1,&count,0,0,0);
for (int i = 0; i < count; i++) {
  uret.getRandNumber(65,90,1,&charne,0,0,0);
  int randomchar = charne;
  Hazirla= Hazirla+IntToHex(randomchar,2);//String(a);
}
Hazirla= Mesaj+Hazirla;
//UTF8String dondur;
String Komut= "<msg t='sys'><body action='pubMsg' r='"+Oda+"'><txt><![CDATA["+Hazirla+"]]></txt></body></msg>";
//osend(OyunSocket, Komut.c_str(),Komut.Length()+1,0);
Form3->GirisServer1->SendBuf(Komut.c_str(),Komut.Length()+1);
MesajSayac++;
Form3->Label13->Caption="Ms="+ IntToStr(MesajSayac);
if(Form3->MesajLogla->Checked)
{
TDateTime Zaman;
String LogKayit="Oda NO="+Oda+"ms:"+IntToStr(MesajSayac)+"saat:"+Zaman.CurrentDateTime().TimeString();;

Zaman=Zaman.CurrentDate();
WORD yil,ay,gun;
Zaman.DecodeDate(&yil,&ay,&gun);
String Dosyayol=IntToStr(gun)+IntToStr(ay)+IntToStr(yil)+".txt";

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
   AccountMesajSayi[Form3->IdlerList->ItemIndex]++;
	   int LimitMesaj= Form3->MesajSayiLimit->Text.ToIntDef(20);

if( AccountMesajSayi[Form3->IdlerList->ItemIndex]>= LimitMesaj)
{
   return true;
}

return false;
  }

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
int SocketYaz(AnsiString gel,BYTE *buf,int *Len)
{

String Parcala,Komut;
String Aranan;
int d;
//Form1->Memo3->Lines->Add(gel);
//return 1;
		if(gel.Pos("</cross-domain-policy>"))
	  {
	//	Form1->GirisServer->Socket->SendBuf(Giris.c_str(),Giris.Length()+1);
	Form3->Memo3->Lines->Add("Giriliyor");
		  return 1001;
	  }
	 if(gel.Pos("findRoom"))
	 {
	   //	 Form1->WebBrowser1->Refresh();
	  //	 Form1->Button1->Click();
	  //{ "<msg t='xt'><body action='xtRes' r='-1'><![CDATA[<dataObj><var n='_cmd' t='s'>findRoom</var><obj o='rooms' t='a'><var n='0' t='s'>Short_Stack_-_Rivals_1,157,6,20,4,5,10,Challenge,,,2000,9,,,Public,,2638,normal,0,,100,</var></obj></dataObj>]]></body></msg>" }
	   d= gel.Pos(",");
	  String Parcala=AnsiMidStr(gel , d+1 , gel.Length());
	 d=Parcala.Pos(",") ;
	 Oda=AnsiLeftStr(Parcala,d-1);
		  if(Form3->ArananOda==Oda)
		  {
			  Form3->Button10->Click();
			 return 1;
		  }

	 Form3->ArananOda=Oda;
   return 1002;

	 }
	if(gel.Pos("logOK"))
	{
	Aranan="email' t='s'>1:";
	d=gel.Pos(Aranan)  ;
	if(d)
   {
	   Parcala=AnsiMidStr(gel , d+Aranan.Length() , gel.Length());
	 d=Parcala.Pos("<") ;
	 UID=AnsiLeftStr(Parcala,d-1);
	 Form3->Label1->Caption=UID;
	  Aranan= "<var n='points' t='n'>";
		d=Parcala.Pos(Aranan)  ;
		if(!d)
		return 1;
		Parcala=AnsiMidStr(Parcala , d+Aranan.Length() , Parcala.Length());
		 d=Parcala.Pos("<") ;
	 OyunToplamPara=AnsiLeftStr(Parcala,d-1);
	 Form3->ToplamPara->Caption=OyunToplamPara;




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
	 Form3->Label3->Caption=Oda;
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
			  Form3->RelogTime->Interval=5000;
			  Form3->RelogTime->Enabled=true;
			}
			else
			{
				Form3->MasaBuy->Text=IntToStr(Buytutar);
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
	 Form3->Label9->Caption="Player Sayi: "+NumberPlayer;
	 if(NumberPlayer.ToIntDef(0)<Form3->MinPlayer->Text.ToIntDef(10))
	 {
	  // Form1->Button16->Click();
	   Form3->RelogTime->Interval=5000;
	   Form3->RelogTime->Enabled=true;
	   return 1;
	 }
	 if((NumberPlayer.ToIntDef(0)==9)||(NumberPlayer.ToIntDef(0)==0))
	 {
	  Form3->RelogTime->Interval=5000;
	  Form3->RelogTime->Enabled=true;
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
		 //  Form1->Memo4->Lines->Add(gel) ;
			 RoomAl=true;
			 OdaListesi.clear();
		 }

		 if(RoomAl)
		 {
			 Odalar+=AnsiString(gel);
		  if(gel.Pos(",</var></obj></dataObj>]]></body></msg>") )
		  {
		//  Form1->Memo4->Lines->Add(Odalar) ;
		//   Form1->Memo4->Lines->SaveToFile("Romm.txt")     ;

		   Form3->Memo3->Lines->Add("Girildi");



		   OdaDuzenle();
		   	int odasayi= OdaListesi.size();
			RoomAl=false;
			 Form3->Memo3->Lines->Add("Odalar Alindi "+IntToStr(odasayi));
		   if(Relog==2)
		   {
	   Form3->RelogTime->Interval=10000;
	   Form3->RelogTime->Enabled=true;
	   Relog=0;
           }
		  }
		  return 1;
		 }
	   if(gel.Pos("dmnMsg"))
	   {
	   if(gel.Pos("many chat messages"))
	   {
	   Form3->Kalk->Click();
	   Form3->Button12->Click();
	   //Form1->RelogTime->Interval=120000;
	   //Form1->RelogTime->Enabled=true;

	  // Form1->WebBrowser1->Refresh() ;
	   Relog=1;
	   Form3->RelogTime->Interval=3000;
	   Form3->RelogTime->Enabled=true;
	   Form3->markTurnTime->Enabled=false;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("Ban Mesaji Geldi 2 Dakka Bekleyecek "+IntToStr(AccountMesajSayi[Form3->IdlerList->ItemIndex]));
	   return 255;
	   }

	   }


GorSayac=0;
int a=1;
	if(Form3-> RelogTime->Enabled)   	return 1;

	if(Relog)return 1;

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
// Form1->Memo2->Lines->Clear();
	Parcala=  Komut_Parcala(gel);
	Parcala=    Komut_Parcala(gel);
	Parcala=    Komut_Parcala(gel);
	MasaPara =    Komut_Parcala(gel);        //para
	KoltukNo=    Komut_Parcala(gel);
	Form3->Label2->Caption=KoltukNo;
	Form3->MasaParaLabel->Caption=MasaPara;
	 Form3->markTurnTime->Enabled=false;
			if (MesajYolla(Form3->MesajAt->Text, Oda)  )
			  {

                 Form3->Kalk->Click();
	   Form3->Button12->Click();
	   //Form1->RelogTime->Interval=120000;
	   //Form1->RelogTime->Enabled=true;

	  // Form1->WebBrowser1->Refresh() ;
	   Relog=1;
	   Form3->RelogTime->Interval=1000;
	   Form3->RelogTime->Enabled=true;
	   Form3->markTurnTime->Enabled=false;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("Mesaj Limit doldu Kullanici Degistir");
			  }
   //	Sleep(1000);
   //	MesajYolla("Selam", Oda);
	PostBling="0";
	Form3->Memo3->Lines->Clear();
	Form3->Memo3->Lines->Add("Oturuldu  Mesaj Gitti");
	Sleep(1000);
	if(Form3->CiftMesaj->Checked)
	{
	 MesajYolla(Form3->MesajAt1->Text, Oda);
	 Sleep(1000);
    }


		Form3->Kalk->Click();
	Form3->Button12->Click();
	Form3-> RelogTime->Interval= Form3->MTime->Text.ToIntDef(15000);
	Form3-> RelogTime->Enabled=true;


	return 1;
	 }

   }

}
else if(Komut=="roomPicked")
{
   Parcala=	Komut_Parcala(gel);
	Oda=  Komut_Parcala(gel);
	 if(Form3->ArananOda==Oda)
		  {
			  Form3->Button10->Click();
			 return 1;
		  }
	Form3->ArananOda=Oda;
   //	Oda=  Komut_Parcala(gel);

   return 1002;
   
}
else if(Komut=="markTurn")
  {
	Komut_Parcala(gel);
	Parcala=  Komut_Parcala(gel);
    	if(Parcala==KoltukNo+".0")
	{
	GorSayac=0;
	Form3->Button6->Click();
	Form3->Kalk->Click();
	Form3->Button12->Click();
	Form3-> RelogTime->Interval= Form3->MTime->Text.ToIntDef(15000);
	Form3-> RelogTime->Enabled=true;
	 Form3->Memo3->Lines->Clear();
	Form3->Memo3->Lines->Add("markTurn Food Cekildi");

	   }
		 if( Form3->HizliOtur->Checked)
		 {

      if(NumberPlayer.ToIntDef(0)!=9)
	   {
	   Form3->Otur->Click();
	   KoltukNo="1";
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("H�zl� Otur");
	   }

	   }


	  return 1;
  }
  else if(Komut=="dealHoles")
  {

	 if(KoltukNo=="-1")
   {
	   if(NumberPlayer.ToIntDef(0)!=9)
	   {

	   Form3->Otur->Click();
	   Form3->Memo3->Lines->Clear();
		Form3->Memo3->Lines->Add("dealHoles Otur");
		}
	   else
	   {
		Form3-> RelogTime->Interval=5000;
	Form3-> RelogTime->Enabled=true;
	Form3->Memo3->Lines->Clear();
	Form3->Memo3->Lines->Add("dealHoles 9 Relog");
	   }

   }

return 1;
  }
  else if(Komut=="sitTaken")
  {
	KoltukNo="-1" ;
	Form3->Button12->Click();
	Form3-> RelogTime->Interval=5000;
	Form3-> RelogTime->Enabled=true;
	Form3->Memo3->Lines->Clear();
	Form3->Memo3->Lines->Add("sitTaken  Relog");

  }
  else if(Komut=="flop")
   {

	 if(KoltukNo=="-1")
   {
	   if(NumberPlayer.ToIntDef(0)!=9)
	   {
	   Form3->Otur->Click();
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("flop Otur");
	   }
	   else
	   {
	   Form3-> RelogTime->Interval=5000;
	   Form3-> RelogTime->Enabled=true;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("flop 9 Relog");
	   }
   }
   else
   {    if(GorSayac!=3)
		{
	   Form3->Kalk->Click();
	   Form3->Button12->Click();
	   Form3-> RelogTime->Interval= Form3->MTime->Text.ToIntDef(15000);
	  Form3-> RelogTime->Enabled=true;
	   GorSayac++;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("flop Kalk Devam");
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
   Form3->Otur->Click();
   Form3->Memo3->Lines->Clear();
   Form3->Memo3->Lines->Add("street Otur");
   }
	   else
	 {
	   Form3-> RelogTime->Interval=5000;
	   Form3-> RelogTime->Enabled=true;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("street 9 Relog");
	   }

   }
   else
   {
		if(GorSayac!=3)
		{
	   Form3->Kalk->Click();
	   Form3->Button12->Click();
	   Form3-> RelogTime->Interval= Form3->MTime->Text.ToIntDef(15000);
	  Form3-> RelogTime->Enabled=true;
	  Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("street Kalk Devam");
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
	   Form3->Kalk->Click();
	   Form3->Button12->Click();
	   Form3-> RelogTime->Interval= Form3->MTime->Text.ToIntDef(15000);
	  Form3-> RelogTime->Enabled=true;
	  Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("river Kalk Devam");
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
String Server_Parcala(String &gel)
{
String Parcala="";

	int d=gel.Pos("=")  ;
	if(d)
   {
	Parcala=AnsiMidStr(gel , d+1 , gel.Length());
	 d=Parcala.Pos(",") ;
	 gel=AnsiMidStr(Parcala , d , Parcala.Length());

	 Parcala=AnsiLeftStr(Parcala,d-1);

	}
	return Parcala;
}
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	   if(URLDownloadToFileA(0,"http://facebook2.poker.zynga.com/poker/server_status.php","pokerserverler.txt",0,0)==S_OK)
	   {
		  //
Serverler= new   TStringList();
 Serverler->LoadFromFile("pokerserverler.txt");
 for (int i = 0; i < Serverler->Count ; i++) {
	 String a=Serverler->Strings[i];
	   String Ip=	Server_Parcala(a);
	String Name = Server_Parcala(a);
	ServerlerListeIp->Items->Add(Ip);
	ServerlerListe->Items->Add(Name)  ;
 }
 Serverler->Free();
 ServerlerListeIp->ItemIndex=0;
 ServerlerListe->ItemIndex=0;

 
 }
 else
 {
	 return;
 }
if(FileExists("serversec.dat"))
{
	ServerlerGezilecek->Items->LoadFromFile("serversec.dat") ;
	ServerlerListeGezilcekIp->Items->LoadFromFile("serversecip.dat") ;
	 ServerSayacList->Items->LoadFromFile("serversayac.dat") ;
}


if(FileExists("potfiltre.txt"))  PotList->Items->LoadFromFile("potfiltre.txt");

    Form3->GirisData="";

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
//ServerSayac

//if(Form3->GirisData=="")
//{
//	ShowMessage("Accoun Kayit Yapin");
//	return;
//}

if (IdlerList->ItemIndex==-1)
{
IdlerList->ItemIndex=0;

 String Dosyayol=  "Account\\"+IdlerList->Items->Strings[IdlerList->ItemIndex]+".acc"  ;
	   if(FileExists(Dosyayol))
	   {


		 TStringList *Accoundosya =new TStringList();
	   Accoundosya->LoadFromFile(Dosyayol);
	   Form3->GirisData= Accoundosya->Text;
	   Accoundosya->Free();

	  // MesajAt->Lines->Add(GirisData);
	   }
	   else
	   {
		   ShowMessage("Account Kayit Dosya yok");
		   return;
	   }

}
else
{

int LimitMesaj= MesajSayiLimit->Text.ToIntDef(20);

	 if( AccountMesajSayi[IdlerList->ItemIndex]>= LimitMesaj)
       {
		AccountMesajSayi[IdlerList->ItemIndex]=0;
		
  if(IdlerList->ItemIndex==IdlerList->Items->Count-1)
			  IdlerList->ItemIndex=0 ;
			  else
			  IdlerList->ItemIndex++;


   String Dosyayol=  "Account\\"+IdlerList->Items->Strings[IdlerList->ItemIndex]+".acc"  ;
	   if(FileExists(Dosyayol))
	   {


		 TStringList *Accoundosya =new TStringList();
	   Accoundosya->LoadFromFile(Dosyayol);
	   Form3->GirisData= Accoundosya->Text;
	   Accoundosya->Free();

	  // MesajAt->Lines->Add(GirisData);
	   }
	   else
	   {
		   ShowMessage("Account Kayit Dosya yok");
		   return;
	   }


	  }
}
Servergir:

// AccountMesajSayi[IdlerList->ItemIndex]=0;
Memo3->Lines->Clear();
Memo3->Lines->Add("Baglaniliyor");
int servercount= ServerlerGezilecek->Items->Count;
if(servercount <= ServerSayac+1)
  {
  ServerSayac=0;
  ServerlerGezilecek->ItemIndex=0;
  }
  else
  {
   ServerlerGezilecek->ItemIndex=ServerSayac;
  }

  ServerSayac++;
  GirisServer1->RemoteHost=  ServerlerListeGezilcekIp->Items->Strings[ServerlerGezilecek->ItemIndex];
if(GirisServer1->Connected)
{
  GirisServer1->Active=false;
}
while(GirisServer1->Connected)
{
Application->ProcessMessages();
Sleep(0);

}

  Sleep(1000);
 GirisServer1->Active=true;

}
//---------------------------------------------------------------------------



void __fastcall TForm3::GirisServerConnect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
Caption="Baglandi";
}
//---------------------------------------------------------------------------

__fastcall SocketThread::SocketThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall SocketThread::Execute()
{
BYTE Gel[25000];
Form3->Memo3->Lines->Add("Bekleniyor");
Form3->GirisTime->Enabled=true;
String a;
	while(!Terminated)
	{
	//Form3->GirisServer1->Receiveln(a) ;
    
	Form3->GirisServer1->ReceiveBuf(Gel,25000);
	}
Form3->Memo3->Lines->Add("Cikildi");
}
//---------------------------------------------------------------------------


void __fastcall TForm3::GirisServerRead(TObject *Sender,
	  TCustomWinSocket *Socket)
{
//Form1->OyunSocket=Socket->SocketHandle;

int index=0;
int rlen= Socket->ReceiveLength();
BYTE buf[15000];// = new BYTE(rlen);
Socket->ReceiveBuf(buf,rlen)    ;
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
int Par= SocketYaz(a,buf,&rlen);

if( Par==255)
{
// delete[] buf;
 return;
}
else if(Par==1001)
{
Socket->SendBuf(Form3->GirisData.c_str(),Form3->GirisData.Length() +1);
delete[] buf;
 return;
}
else if(Par==1002)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Form3->ArananOda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
Socket->SendBuf( Komut.c_str(),Komut.Length()+1);
//delete[] buf;
 return;
}


 int clen= a.Length();

if((clen+index+2)<rlen)
{
 index+= clen+1     ;
goto  Devam ;
}

// delete[] buf;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Form3->GirisTime->Enabled=false;
if(GirisServer1->Active)
{
  GirisServer1->Active=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button12Click(TObject *Sender)
{
if( Form3->HizliOtur->Checked)
		 {
return;
         }
String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>1</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
GirisServer1->SendBuf(Gidecek.c_str(),Gidecek.Length()+1) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::KalkClick(TObject *Sender)
{
String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'></obj><var n='cmd' t='s'>standUp</var></dataObj>]]></body></msg>";
GirisServer1->SendBuf(Gidecek.c_str(),Gidecek.Length()+1) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::markTurnTimeTimer(TObject *Sender)
{
	markTurnTime->Enabled=false;
if(Relog)return;
Button16->Click();
return ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::OturClick(TObject *Sender)
{
	    String Para=MasaBuy->Text;
KoltukNo="-1";
String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><obj t='o' o='param'><var n='buyIn' t='n'>"+Para+"</var><var n='_cmd' t='s'>sit</var><var n='postToPlay' t='n'>1</var><var n='sitNo' t='n'>"+KoltukNo+"</var></obj><var n='cmd' t='s'>sit</var></dataObj>]]></body></msg>";
GirisServer1->SendBuf(Gidecek.c_str(),Gidecek.Length()+1) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button16Click(TObject *Sender)
{
if(Relog)return;

if(MesajDur->Checked) return;




 if(OdaGirisSekli->ItemIndex==0)
 {
	 Button11->Click();
 }
 else if(OdaGirisSekli->ItemIndex==1)
 {
   Button10->Click();
 }

  else if(OdaGirisSekli->ItemIndex==2)
 {
 int odasize= OdaListesi.size();
if( odasize<20)

{
OdaListesi.clear();
 OdaRefres();
Form3-> RelogTime->Interval=10000;
Form3-> RelogTime->Enabled=true;
Form3->Memo3->Clear();
Form3->Memo3->Lines->Add("OdaRefres");
markTurnTime->Enabled=false;
}
else
{
  Button13->Click();
}


 }


 markTurnTime->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm3::Button2Click(TObject *Sender)
{
ServerlerGezilecek->Items->Add(ServerlerListe->Items->Strings[ ServerlerListe->ItemIndex]);
ServerlerListeGezilcekIp->Items->Add(ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex]);
ServerlerGezilecek->Items->SaveToFile("serversec.dat") ;
ServerlerListeGezilcekIp->Items->SaveToFile("serversecip.dat") ;
ServerSayacList->Items->Add("0");
ServerSayacList->Items->SaveToFile("serversayac.dat") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
  if(ServerlerGezilecek->ItemIndex!=-1)
  {
   ServerlerListeGezilcekIp->Items->Delete(ServerlerGezilecek->ItemIndex) ;
   ServerlerGezilecek->Items->Delete(ServerlerGezilecek->ItemIndex);
   ServerlerGezilecek->Items->SaveToFile("serversec.dat") ;
   ServerlerListeGezilcekIp->Items->SaveToFile("serversecip.dat") ;

   ServerSayacList->Items->Delete(ServerlerGezilecek->ItemIndex);
   ServerSayacList->Items->SaveToFile("serversayac.dat") ;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RelogTimeTimer(TObject *Sender)
{
  RelogTime->Enabled=false;
RelogTime->Interval=5000;
if(Relog==1)
{
	  markTurnTime->Enabled=false;
	  Relog=2;
	  Button1->Click();

	  return;
}


Button16->Click();
return;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button10Click(TObject *Sender)
{
String smallBlind,bigBlind,buyin;
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


String OdaAra="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='name' t='s'>texasLogin</var><var n='cmd' t='s'>findRoom</var><obj t='o' o='param'><var n='maxPlayers' t='n'>9</var><var n='smallBlind' t='n'>"+smallBlind+"</var><var n='bigBlind' t='n'>"+bigBlind+"</var><var n='buyin' t='n'>"+buyin+"</var><var n='gameType' t='s'>Challenge</var><var n='autoJoin' t='n'>1</var></obj></dataObj>]]></body></msg>";

//OdaArama=true;
//Button12->Click();
KoltukNo="-1";
GirisServer1->SendBuf(OdaAra.c_str(),OdaAra.Length()+1);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button11Click(TObject *Sender)
{
KoltukNo="-1";
			  
String Gidecek="<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='name' t='s'>texasLogin</var><obj t='o' o='param'><var n='roomGroup' t='s'>normal</var><var n='_cmd' t='s'>pickRoom</var></obj><var n='cmd' t='s'>pickRoom</var></dataObj>]]></body></msg>";

GirisServer1->SendBuf(Gidecek.c_str(),Gidecek.Length()+1);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::GirisServer1Connect(TObject *Sender)
{
Caption="Baglandi";
Memo3->Lines->Add("Baglandi");
Socket_Thread = new SocketThread(false);

}
//---------------------------------------------------------------------------
 AnsiString a="";
void __fastcall TForm3::GirisServer1Receive(TObject *Sender, PChar Buf, int &DataLen)
{
int rlen= DataLen;
int index=0;
BYTE *x;
Devam:
x=&Buf[index];

if((Buf[DataLen-1] ==0) &&(a==""))
{
    
a=AnsiString((char*)x);
  int Par= SocketYaz(a,Buf,&rlen);
  a="";



  if( Par==255)
{
// delete[] buf;
 return;
}
else if(Par==1001)
{
GirisServer1->SendBuf(Form3->GirisData.c_str(),Form3->GirisData.Length() +1);
 Form3->GirisTime->Enabled=false;
 return;
}
else if(Par==1002)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Form3->ArananOda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
GirisServer1->SendBuf( Komut.c_str(),Komut.Length()+1);
//delete[] buf;
 return;
}
}
else
{
	for (int i = 0; i < DataLen; i++) {
		if(Buf[i]==0)
		{
		int Par= SocketYaz(a,Buf,&rlen);
		  a="";

		  if( Par==255)
					{
			  return;
			 }
		  else if(Par==1001)
		   {
		  GirisServer1->SendBuf(Form3->GirisData.c_str(),Form3->GirisData.Length() +1);
		  Form3->GirisTime->Enabled=false;
		 return;
		   }
		 else if(Par==1002)
			  {
		   AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Form3->ArananOda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
		  GirisServer1->SendBuf( Komut.c_str(),Komut.Length()+1);
//delete[] buf;
		 return;
		 }
          continue;
		}
		if(a=="")
		 a=Buf[i]   ;
		 else
		 a+=Buf[i];


	}
}


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
//int Par= SocketYaz(a,Buf,&rlen);
//
//if( Par==255)
//{
//// delete[] buf;
// return;
//}
//else if(Par==1001)
//{
//GirisServer1->SendBuf(Form3->GirisData.c_str(),Form3->GirisData.Length() +1);
// Form3->GirisTime->Enabled=false;
// return;
//}
//else if(Par==1002)
//{
//AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Form3->ArananOda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
//GirisServer1->SendBuf( Komut.c_str(),Komut.Length()+1);
////delete[] buf;
// return;
//}
//
//
// int clen= a.Length();
//
//if((clen+index+2)<rlen)
//{
// index+= clen+1     ;
//goto  Devam ;
//}
	 /*
int index=0;
int rlen= Socket->ReceiveLength();
BYTE buf[15000];// = new BYTE(rlen);
Socket->ReceiveBuf(buf,rlen)    ;
Devam:
AnsiString a=AnsiString((char* )&buf[index]);

int Par= SocketYaz(a,buf,&rlen);

if( Par==255)
{
// delete[] buf;
 return;
}
else if(Par==1001)
{
Socket->SendBuf(Form3->GirisData.c_str(),Form3->GirisData.Length() +1);
delete[] buf;
 return;
}
else if(Par==1002)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><var n='cmd' t='s'>superJoin</var><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='pass' t='s'></var><var n='roomId' t='n'>"+Form3->ArananOda+"</var></obj><var n='name' t='s'>texasLogin</var></dataObj>]]></body></msg>";
Socket->SendBuf( Komut.c_str(),Komut.Length()+1);
//delete[] buf;
 return;
}


 int clen= a.Length();

if((clen+index+2)<rlen)
{
 index+= clen+1     ;
goto  Devam ;
}
*/

}
//---------------------------------------------------------------------------

void __fastcall TForm3::GirisServer1Disconnect(TObject *Sender)
{
Memo3->Lines->Add("Dc Oldu");
Socket_Thread->Terminate();
Socket_Thread->WaitFor();
Socket_Thread->Free();
Memo3->Lines->Add("Dc Cikildi");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::GirisTimeTimer(TObject *Sender)
{
Memo3->Lines->Clear();
Memo3->Lines->Add("Giris Relog");
Form3->GirisTime->Enabled=false;
GirisServer1->Active=false;

if(ServerSayac!=0)
{
  ServerSayac--;
}
Button1->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button13Click(TObject *Sender)
{


 OdaIndex=StrToInt(ServerSayacList->Items->Strings[ServerlerGezilecek->ItemIndex]) ;
Devam:
//		   if(RoomAl)
//			{
//Form3-> RelogTime->Interval=5000;
//Form3-> RelogTime->Enabled=true;
// markTurnTime->Enabled=false;
// return;
//
//            }
  //  Application->ProcessMessages();
   int odasize= OdaListesi.size();


	  if(odasize<OdaIndex+1)
	  {
		ServerSayacList->Items->Strings[ServerlerGezilecek->ItemIndex]="0";
	   ServerSayacList->Items->SaveToFile("serversayac.dat") ;

	   Relog=1;
	   Form3->RelogTime->Interval=1000;
	   Form3->RelogTime->Enabled=true;
	   Form3->markTurnTime->Enabled=false;
	   Form3->Memo3->Lines->Clear();
	   Form3->Memo3->Lines->Add("Masalar dolu Server Degis");
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

	if(PotList->Items->Count)
	  {
		  if (PotList->Items->IndexOf(IntToStr(OdaListesi.at(OdaIndex).MaxPara)+"$")!=0)
		  {
			if(PotList->Items->IndexOf(IntToStr(OdaListesi.at(OdaIndex).MinPara)+"$")!=0)
			{
		   OdaIndex++  ;
			 goto Devam;
			}
		  }
	  }


	MasaBuy->Text =IntToStr(OdaListesi.at(OdaIndex).MaxPara/10);
	OdaGir(OdaListesi.at(OdaIndex).OdaNo);
	AnsiString OdaNe="                                                    ";
					 OdaNe=	 Utf8ToAnsi(OdaListesi.at(OdaIndex).OdaIsmi);
   //	strcpy(OdaNe.c_str(),OdaListesi.at(OdaIndex).OdaIsmi );
	Label5->Caption=OdaNe;
	Label10->Caption=IntToStr(OdaListesi.at(OdaIndex).MinPara)+"/"+IntToStr(OdaListesi.at(OdaIndex).MaxPara);
	Label11->Caption=IntToStr(OdaIndex);

	OdaIndex++;

	ServerSayacList->Items->Strings[ServerlerGezilecek->ItemIndex]=IntToStr(OdaIndex);
 ServerSayacList->Items->SaveToFile("serversayac.dat") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button15Click(TObject *Sender)
{

PotList->Items->Add(Edit1->Text+"$") ;
PotList->Items->SaveToFile("potfiltre.txt") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button17Click(TObject *Sender)
{
PotList->Items->Delete( PotList->ItemIndex );

PotList->Items->SaveToFile("potfiltre.txt") ;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
if(FileExists("Account\\accountkayit.acc"))
{

	 IdlerList->Items->LoadFromFile("Account\\accountkayit.acc") ;
	 IdlerList->ItemIndex=-1;



      AccountMesajSayi = (DWORD*)malloc(sizeof(DWORD)* IdlerList->Items->Count);
	  memset(AccountMesajSayi,0, sizeof(DWORD)* IdlerList->Items->Count) ;



}

}
//---------------------------------------------------------------------------






void __fastcall TForm3::MasaListClick(TObject *Sender)
{
String Masano=MasaList->Items->Strings[MasaList->ItemIndex];
Komut_Parcala(Masano);
//MasaList->Items->Strings[MasaList->ItemIndex] ;
Label15->Caption="Masalar:"+Masano;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button19Click(TObject *Sender)
{
 String Masano=MasaList->Items->Strings[MasaList->ItemIndex];
Komut_Parcala(Masano)  ;
	OdaGir(Masano);	
}
//---------------------------------------------------------------------------

