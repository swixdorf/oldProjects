//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <vector>
#include "ProcScan.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TClientSocket *socs[9];
TMemo *memo[9];
String Para = "200000";
String OyunToplamPara;
String Oda;
 SOCKET OyunSocket;
 int otur(int NO)
{
String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><obj t='o' o='param'><var n='autoTopOff' t='n'>0</var><var n='sitNo' t='n'>"+IntToStr(NO)+"</var><var n='hsmStatus' t='n'>0</var><var n='buyIn' t='n'>"+Para+"</var><var n='postToPlay' t='n'>1</var><var n='rakeEnable' t='n'>0</var><var n='autoRebuy' t='n'>0</var><var n='_cmd' t='s'>sit</var></obj><var n='name' t='s'>gameRoom</var><var n='cmd' t='s'>sit</var></dataObj>]]></body></msg>";
socs[NO]->Socket->SendBuf( Gidecek.c_str(),Gidecek.Length()+1);
}
int kalk(int NO)
{
	String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><obj t='o' o='param'></obj><var n='cmd' t='s'>standUp</var><var n='name' t='s'>gameRoom</var></dataObj>]]></body></msg>";
	socs[NO]->Socket->SendBuf( Gidecek.c_str(),Gidecek.Length()+1);
}
int call (int NO)
{
	String calltutar="45000000";
	String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><var n='cmd' t='s'>act</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='action' t='s'>c</var><var n='chips' t='n'>"+calltutar+"</var></obj></dataObj>]]></body></msg>";
	socs[NO]->Socket->SendBuf( Gidecek.c_str(),Gidecek.Length()+1);
}
int fold(int NO)
{
	String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><var n='cmd' t='s'>act</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='action' t='s'>f</var><var n='chips' t='n'>-1</var></obj></dataObj>]]></body></msg>";
		socs[NO]->Socket->SendBuf( Gidecek.c_str(),Gidecek.Length()+1);
	}
int raise(int NO,String Tutar)
{
	String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><var n='cmd' t='s'>act</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='action' t='s'>f</var><var n='chips' t='n'>-1</var></obj></dataObj>]]></body></msg>";
		socs[NO]->Socket->SendBuf( Gidecek.c_str(),Gidecek.Length()+1);
}


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
// Form1->Memo1->Lines->Add( AnsiString(buf)); ;
  if(AnsiString(buf).Pos("login z='TexasHoldemUp"))
	 {

GirisAktar= AnsiString(buf) ;
TStringList *s =new TStringList();

	   s->Add(GirisAktar) ;
	   s->SaveToFile("Account\\asd.acc");
	   s->Free();
	   ShowMessage("Kayit Alindi");
	   Application->Terminate();
	   }




   return osend(s, buf,len,flags);
 }
String GirisDatalar[9];
String GirisData1 = "<msg t='sys'><body action='login' r='0'><login z='TexasHoldemUp'><nick><![CDATA[%7B%22pic_url%22%3A%22https%3A//zynga1-a.akamaihd.net/poker/poker/img/ladder_default_user.png%22%2C%22sn_id%22%3A18%2C%22clientId%22%3A6%2C%22clientType%22%3A%22flash%22%2C%22rank%22%3A0%2C%22capabilities%22%3A0%2C%22user%22%3A%2218%3A36391295717%22%2C%22pic_lrg_url%22%3A%22%22%2C%22autoRoom%22%3A1%2C%22tourneyState%22%3A%220%22%2C%22lobbyList%22%3A1%2C%22PGIBuyAndSend%22%3A1%2C%22PGIViewAndDisplay%22%3A1%2C%22newUserInstall%22%3A0%2C%22protoVersion%22%3A10%2C%22phpToSfxVars%22%3A%7B%22smartfoxData%22%3A%7B%22LuckyHandEnabled%22%3Afalse%2C%22badLossEnabled%22%3A1%2C%22mgfwP1Reward%22%3A1%2C%22bustOutMonetization%22%3Afalse%2C%22userPowerTourneyType%22%3A%22repricedBuyinTable%22%2C%22platform%22%3A104%2C%22HSMTestFG%22%3A-1%7D%2C%22LuckyHandEnabled%22%3Afalse%2C%22badLossEnabled%22%3A1%2C%22mgfwP1Reward%22%3A1%2C%22enabled%22%3Atrue%2C%22bustOutMonetization%22%3Afalse%2C%22userPowerTourneyType%22%3A%22repricedBuyinTable%22%2C%22skipLostCollectibleShout%22%3Atrue%2C%22platform%22%3A104%2C%22HSMTestFG%22%3A-1%7D%2C%22profile_url%22%3A%22%22%2C%22autoJoin%22%3A1%2C%22emailSubscribed%22%3A1%2C%22hideGifts%22%3A1%2C%22buildVersion%22%3A1%2C%22locale%22%3A%22en%22%2C%22UnreachableProtect%22%3A1%7D]]></nick><pword><![CDATA[2075e424c3e169e6c9b3b8ec085ae645:1369927246:A9B560B8CF3FF1EE621779CC3E0F08BA]]></pword></login></body></msg>";
void __fastcall TForm2::gir(TObject *Sender)
{
for (int i = 0; i < 9; i++)
{

	int pos = CheckListBox1->Items->Strings[i].AnsiPos(":");

		socs[i]->Host = "184.75.174.110";//ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex];
		socs[i]->Port = 9339;


	//socs[i]->Host = ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex];
	socs[i]->Active = true;
}
 // socs[0]->Active = true;
//ClientSocket1->Active = true;


}


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
 bool RoomAl[9];
 AnsiString UID;
 AnsiString KoltukNo;

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
	if(Form2->CheckBox1->Checked )
	{
		Form2->MasaList->Items->Add("[" + Oturan +"/"+ MaxKul +  "]" + "[" + MinPot + "/" + MaxPot + "]" + Utf8ToAnsi(OdaListeEkle.OdaIsmi)+"%"+OdaNo);
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
	//Form1->MasaListNo->Items->Clear();
	Form2->MasaList->Items->Clear();
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
		UID=AnsiLeftStr(Parcala,d+5);
		Pl=  Parcala.Length();
		Parcala=AnsiMidStr(Parcala,d+6,Parcala.Length());
		OdaEkle(UID);
	 }
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

//---------------------------------------------------------------------------
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
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	if(URLDownloadToFileA(0,"http://facebook2.poker.zynga.com/poker/server_status.php","pokerserverler.txt",0,0)==S_OK)
	{
    	ServerlerListe->Items->Clear();
		ServerlerListeIp->Items->Clear();
		TStringList *Serverler;
		Serverler= new   TStringList();
		Serverler->LoadFromFile("pokerserverler.txt");
		for (int i = 0; i < Serverler->Count ; i++)
		{
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
}
//---------------------------------------------------------------------------
bool called[9];
int VeriGeldi(AnsiString buf,int socno)
{
    String Parcala,Komut;
	String Aranan;
	int d;


	if(buf.Pos("findRoom"))
	{
		d= buf.Pos(",");
		String Parcala=AnsiMidStr(buf , d+1 , buf.Length());
		d=Parcala.Pos(",") ;
		String Oda=AnsiLeftStr(Parcala,d-1);
	}
		if(buf.Pos("clear"))
	{
		for (int i = 0; i < 9; i++) {
		 called[i]=false;
		}

	}
	if(buf.Pos("markTurn"))
	{

		if (buf.Pos("%"+IntToStr(socno)+".0%"))
		{
			/*if (Form2->CheckListBox1->Checked[socno])
			{
				call(socno);
				return 0;
			}
			if (called[socno])
			{
				fold(socno);
			}
			else
			{ */
				called[socno]=true;
				call(socno);
		   /*	*}  */
		}
	}
	if(buf.Pos("updateChips")==5)
	{
		if (socno!=0)
		{
			return false;
		}
		for (int i = 0; i < 9; i++)
		{
			int pos = buf.Pos("%"+IntToStr(i)+"%");
			int pos2;
			String a =  "";
			if (i==8)
			{
				pos2 = buf.Pos("%"+IntToStr(i+1)+"%");
			}
			else
			{
				pos2 = buf.Length()-1;
			}
			a=buf.SubString(pos+3,13);
			Form2->ListBox1->Items->Strings[i] = a;

		}
		call(socno);
	}
	if(buf.Pos("logOK"))
	{
		Aranan="email' t='s'>1:";
		d=buf.Pos(Aranan)  ;
		if(d)
		{
			Parcala=AnsiMidStr(buf , d+Aranan.Length() , buf.Length());
			d=Parcala.Pos("<") ;
			String UID=AnsiLeftStr(Parcala,d-1);
			Aranan= "<var n='points' t='n'>";
			d=Parcala.Pos(Aranan)  ;
			if(!d)
			return 1;
			Parcala=AnsiMidStr(Parcala , d+Aranan.Length() , Parcala.Length());
			d=Parcala.Pos("<") ;
			OyunToplamPara=AnsiLeftStr(Parcala,d-1);
			Form2->ListBox1->Items->Strings[socno] = OyunToplamPara;
		}
		return 1;
	}
	int odavar=buf.Pos("joinOK' r='")  ;
	if(odavar)
	{
		Aranan="joinOK' r='";
		Parcala=AnsiMidStr(buf , odavar+Aranan.Length() , buf.Length());
		odavar=Parcala.Pos("'") ;
		Oda=AnsiLeftStr(Parcala,odavar-1);
		String KoltukNo="-1";
		Aranan="bigBlind' t='n'><![CDATA[";
		odavar=buf.Pos(Aranan)  ;
		if(odavar)
		{
			Parcala=AnsiMidStr(buf , odavar+Aranan.Length() , buf.Length());
			odavar=Parcala.Pos("]") ;
			String MaxBling=AnsiLeftStr(Parcala,odavar-1);
			int Buytutar= MaxBling.ToIntDef(500000000) *10;
			int ParaNe=OyunToplamPara.ToIntDef(0);
			if(Buytutar> ParaNe)
			{
			  //	Form3->RelogTime->Interval=5000;
			 //	Form3->RelogTime->Enabled=true;
			}
			else
			{
			 //	Form3->MasaBuy->Text=IntToStr(Buytutar);
			}

		}
	}


    	if(buf.Pos("displayRoomList"))
	{

		RoomAl[socno]=true;
		if (socno==0) {
		Odalar="";
		Odalar=AnsiString(buf);
		OdaListesi.clear();
		}
	}
	if(RoomAl[socno])
	{
		if (socno==0) {
		Odalar+=AnsiString(buf);
        }
		if(buf.Pos(",</var></obj></dataObj>]]></body></msg>") )
		{
			Form2->Memo1->Lines->Add("Girildi : " + IntToStr(socno));
			if (socno==0) {
			OdaDuzenle();
			int odasayi= OdaListesi.size();

			Form2->Memo1->Lines->Add("Odalar Alindi "+IntToStr(odasayi));
			}
			RoomAl[socno]=false;
		}
		return 1;
	}
}

 AnsiString a[9];
void __fastcall TForm2::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{

TClientSocket *Item = dynamic_cast<TClientSocket *>(Sender);


a[Item->Tag] += Socket->ReceiveText();
/*if (CheckListBox1->Checked[Item->Tag]) {
if (a[Item->Tag].Pos("established"))
{
	Memo1->Lines->Add(IntToStr(Item->Tag)+" : Proxy OK..");
	Socket->SendBuf(GirisDatalar[Item->Tag].c_str(),GirisDatalar[Item->Tag].Length() +1);
	a[Item->Tag]="";
}
}            */

	if(a[Item->Tag].Pos("</cross-domain-policy>"))
	{
		Form2->Memo1->Lines->Add("Giriliyor : " + IntToStr(Item->Tag));
	}
if ((a[Item->Tag].Pos("</msg>"))||((a[Item->Tag].SubString(1,1)=="%")&&(a[Item->Tag].SubString(a[Item->Tag].Length()-1,1)=="%"))) {
String buf =  IntToStr(Item->Tag) + " : " + a[Item->Tag];
memo[Item->Tag]->Lines->Add(buf);
//Memo2->Lines->Add(buf);
VeriGeldi(a[Item->Tag],Item->Tag);
a[Item->Tag] = "";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{

TClientSocket *Item = dynamic_cast<TClientSocket *>(Sender);
Memo1->Lines->Add(IntToStr(Item->Tag));
/*if (CheckListBox1->Checked[Item->Tag]) {
String a = "CONNECT ";
a+=ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex];
a+=":9339 \r\nProxy-Authorization: Basic aaaa\r\n\r\n";
Socket->SendBuf(a.c_str(),a.Length()+1);
}
else
{   */
	Socket->SendBuf(GirisDatalar[Item->Tag].c_str(),GirisDatalar[Item->Tag].Length() +1);


//
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ServerlerListeIpChange(TObject *Sender)
{
//ServerlerListe->ItemIndex = ServerlerListeIp->ItemIndex ;
}
//---------------------------------------------------------------------------

void OdaGir(int index,AnsiString Oda)
{
AnsiString Komut= "<msg t='xt'><body action='xtReq' r='1'><![CDATA[<dataObj><obj t='o' o='param'><var n='autoRoom' t='n'>1</var><var n='roomId' t='n'>"+Oda+"</var><var n='pass' t='s'></var></obj><var n='name' t='s'>texasLogin</var><var n='cmd' t='s'>superJoin</var></dataObj>]]></body></msg>";
socs[index]->Socket->SendBuf( Komut.c_str(),Komut.Length()+1);
}


void __fastcall TForm2::MasaListDblClick(TObject *Sender)
{
String Masano = MasaList->Items->Strings[MasaList->ItemIndex];
int yer = Masano.Pos("%");
if (yer!=0) {
  Masano = Masano.SubString(yer+1,Masano.Length()-yer);
}
for (int i = 0; i < 9; i++) {
OdaGir(i,Masano);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
memo[0]=Memo2;
memo[1]=Memo3;
memo[2]=Memo4;
memo[3]=Memo5;
memo[4]=Memo6;
memo[5]=Memo7;
memo[6]=Memo8;
memo[7]=Memo9;
memo[8]=Memo10;
CheckListBox1->Checked[0]=true;
	for (int i = 0; i < 9; i++)
	{
		socs[i] = new TClientSocket(NULL);
		socs[i]->Tag = i;
		socs[i]->Host = ClientSocket1->Host;
		socs[i]->Port = ClientSocket1->Port;
		socs[i]->ClientType = ClientSocket1->ClientType;
		socs[i]->OnConnect = ClientSocket1->OnConnect;
		socs[i]->OnRead = ClientSocket1->OnRead;
	}
	if(FileExists("pokerserverler.txt"))
	{
		TStringList *Serverler;
		Serverler= new   TStringList();
		Serverler->LoadFromFile("pokerserverler.txt");
		for (int i = 0; i < Serverler->Count ; i++)
		{
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
		TStringList *g_d;
		g_d= new   TStringList();

	for (int i = 0; i < 9; i++)
	{
		if (FileExists(IntToStr(i+1)+".acc"))
		{
			g_d->LoadFromFile(IntToStr(i+1)+".acc");
			GirisDatalar[i] = g_d->Strings[0];
		}
	}
        g_d->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ServerlerListeClick(TObject *Sender)
{
/*for (int i = 0; i < 8; i++) {
socs[i]->Host = ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex];
}   */
}
//---------------------------------------------------------------------------



void __fastcall TForm2::MasaBuyChange(TObject *Sender)
{
Para = MasaBuy->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{
for (int i = 0; i < 9; i++)
{
	otur(i);
}
Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{

for (int i = 0; i < 9; i++) {
	otur(i);
//socs[i]->Socket->SendBuf(Gidecek.c_str(),Gidecek.Length() +1);
}
}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button4Click(TObject *Sender)
{
String Masano = Edit1->Text;

for (int i = 0; i < 9; i++) {
OdaGir(i,Masano);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button5Click(TObject *Sender)
{
Memo2->Lines->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button6Click(TObject *Sender)
{
for (int i = 0; i < 9; i++)
{
	socs[i]->Host = Edit2->Text;
	socs[i]->Active = true;
}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button7Click(TObject *Sender)
{
	int pos = CheckListBox1->Items->Strings[0].AnsiPos(":");

		socs[0]->Host = "184.75.174.34";//ServerlerListeIp->Items->Strings[ServerlerListe->ItemIndex];
		socs[0]->Port = 9339;

	socs[0]->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
socs[Edit4->Text.ToIntDef(0)]->Socket->SendText(Edit3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
for (int i = 0; i < 9; i++)
{
	kalk(i);
}
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button10Click(TObject *Sender)
{
for (int i = 1; i < 9; i++) {
call(i);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{
for (int i = 1; i < 9; i++) {
fold(i);    
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click(TObject *Sender)
{
String Gidecek="<msg t='xt'><body action='xtReq' r='"+Oda+"'><![CDATA[<dataObj><var n='name' t='s'>gameRoom</var><var n='cmd' t='s'>act</var><obj t='o' o='param'><var n='_cmd' t='s'>act</var><var n='action' t='s'>r</var><var n='chips' t='n'>"+Edit5->Text+"</var></obj></dataObj>]]></body></msg>";
socs[0]->Socket->SendBuf(Gidecek.c_str(),Gidecek.Length() +1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
call(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)
{
for (int i = 0; i < 9; i++)
{
    memo[i]->Lines->SaveToFile(IntToStr(i)+".txt");
}
}
//---------------------------------------------------------------------------

