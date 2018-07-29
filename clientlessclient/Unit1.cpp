//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                                                               
#pragma resource "*.dfm"
TForm1 *Form1;
BYTE  recvbuffer[24][4096] ;
WORD recvlen[24];
bool recvmod = true;
TTabSheet *tab[24];
TClientSocket *sock[24];
TCheckListBox *clbx[24];
TListBox *lb1x[24];
TListBox *lb2x[24];
bool f = false;
bool cevapgeldi=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TImage* Img[28];
TLabel* ItemAdet[28];
TLabel* ItemPlus[28];
String Path;
DWORD Itemler[24][255][28];
WORD  Countlar[24][255][28];
void __fastcall TForm1::Button1Click(TObject *Sender)
{
for (int i = 0; i < ComboBox1->Items->Count; i++) {
recvlen[i]=0;
recvmod = true;

ProgressBar1->Position=0;
Timer1->Enabled = true;
sock[i]->Active=false;
sock[i]->Active=true;

}
 /*
recvlen[0] =0;

if (ComboBox1->ItemIndex==-1)
{
	ShowMessage("Server Secimi Yapmalisiniz.");
	return;
}
String AnaBuffer = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
int ayrac = AnaBuffer.AnsiPos(":");
String buf1 = AnaBuffer.SubString(1,ayrac-1);
String buf2 = AnaBuffer.SubString(ayrac+1,AnaBuffer.Length()-ayrac);

	CheckListBox1->Items->Clear();
	ListBox1->Items->Clear();
	ClientSocket1->Active = false;
ClientSocket1->Host = buf1;
ClientSocket1->Port = buf2.ToInt();
	ClientSocket1->Active = true;
	while (!ClientSocket1->Socket->Connected){
	  Sleep(100);
	  Application->ProcessMessages();
	}
	BYTE Komut[1] = {0};
ClientSocket1->Socket->SendBuf(Komut,1);
recvmod = true;
for (int i = 0; i < 20; i++) {

	Sleep(100);
	Application->ProcessMessages();
}
recvmod = false;
	   Button10Click(0);
	   */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{
TClientSocket *sck = dynamic_cast<TClientSocket *>(Sender);

	int len  = Socket->ReceiveLength();
	BYTE Komut[4096];
	Socket->ReceiveBuf(Komut,len);
	switch (Komut[0])
	{
	  /*	case 0:
		{
			int yer=1;
			while (yer<len)
			{
				String a;
				char buf[100];
				memset(buf,0,100);
				memcpy(buf,&Komut[yer+1],Komut[yer]);
				yer +=Komut[yer];
				yer++;
				a = "["+IntToStr(CheckListBox1->Items->Count+1)+"] ";
				a+=String(buf);
				memset(buf,0,100);
				memcpy(buf,&Komut[yer+1],Komut[yer]);
				yer +=Komut[yer];
				yer++;
				a += " \t  |"+String(buf);
				CheckListBox1->Items->Add(a);
				ListBox1->Items->Add(0);
				CheckListBox1->Checked[CheckListBox1->Count-1]=Komut[yer];
				yer++;
			}
		}break;   */

		case 3:
		{
			ListBox1->Items->Clear();
			int yer =1;
			while (yer<len)
			{
				DWORD a = *(DWORD*)&Komut[yer];
				ListBox1->Items->Add(a);
				yer+=4;
			}
		}break;

		case 5:
		{
			Memo1->Lines->Clear();
			char buf[1024];
			memset(buf,0,1024);
			memcpy(buf,&Komut[6],*(DWORD*)&Komut[2]);
			Memo1->Text = String(buf) ;
		}break;
		case 0x99:
		{
			Memo3->Lines->Clear();
			char buf[1024];
			memset(buf,0,1024);
			memcpy(buf,&Komut[5],*(DWORD*)&Komut[1]);
			Memo3->Text = String(buf) ;
			ListBox2->Items->Clear();
			for (int i = 0; i < Memo3->Lines->Count; i++)
			{
				ListBox2->Items->Add(Memo3->Lines->Strings[i]);
			}
		}break;                               
		case 10:
		{
			switch (Komut[1])
			{
				/*case 0: //update position;
				{
					BYTE yer = Komut[2];
					WORD x,y;
					x=*(WORD*)&Komut[3];
					y=*(WORD*)&Komut[5];
					String buf = IntToStr(x)+","+IntToStr(y);
					ListBox2->Items->Strings[yer] = buf;
				}break; */

				case 1: //Item Drop;
				{
					BYTE yer = Komut[2];
					DWORD Itemid;
					Itemid=*(WORD*)&Komut[3];
					String buf = "["+IntToStr(yer)+"]ItemDrop : " += IntToStr(Itemid);
					Memo2->Lines->Add(buf);
				}break;

				case 2://connect dc close
				{
					BYTE yer = Komut[2];
					String buf = "[" + IntToStr(yer) + "] " ;
					if (Komut[3]==0) {
						buf+= "Disconnect";
					}else if (Komut[3]==1) {
						buf+= "Login";
					}else if (Komut[3]==2) {
						buf+= "Kapandi";
					}else if (Komut[3]==3) {
                        buf+= "Acildi";
					}else if (Komut[3]==4) {
						buf+= "GirisTamam";
					}else if (Komut[3]==5) {
						buf+= "MadenBasladi";
					}
					Memo2->Lines->Add(buf);
				}break;
			}
		}break;
			case 0x11:
		{
		//208.94.241.66

			int yer =2;
			int iyer = 0;
			while (yer<len)
			{
				if (iyer == 28) {
				GroupBox1->Caption = *(DWORD*)&Komut[yer];;
				break;
				}
				DWORD ItemId 	= *(DWORD*)&Komut[yer];
				WORD  ItemCount = *(WORD*)&Komut[yer+4];
				Itemler[sck->Tag][Komut[1]][iyer] = ItemId;
				Countlar[sck->Tag][Komut[1]][iyer] = ItemCount;

					for (int iyer = 0; iyer < 28; iyer++) {

				String buf = IntToStr(Itemler[sck->Tag][Komut[1]][iyer]);
				String itemm ="images/itemicon_";
				itemm+=buf.SubString(1,1);
				itemm+="_";
				itemm+=buf.SubString(2,4);
				itemm+="_";
				itemm+=buf.SubString(6,2);
				itemm+="_";
				itemm+=buf.SubString(8,1);
				itemm+="_thumb.jpg";
				if (!FileExists(itemm))
				{
					if (Itemler[sck->Tag][Komut[1]][iyer]==0) {
					itemm="images\\co_black_thumb.jpg";
					}else{
					itemm="images/itemicon_9_0005_60_0_thumb.jpg";
					}

				}
				Img[iyer]->Picture->LoadFromFile(itemm);
				ItemAdet[iyer]->Caption = Countlar[sck->Tag][Komut[1]][iyer];
				}
				
				yer+=6;
				iyer++;
			}
			cevapgeldi=true;
		}break;
	default:
	{
	if (recvmod) {

	 memcpy(&recvbuffer[sck->Tag][recvlen[sck->Tag]],&Komut,len);
	 recvlen[sck->Tag]+=len;
	}

	}
		;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
	BYTE Komut[2];
	Komut[0]=0x1;
	int pos = CheckListBox1->ItemIndex;
	Komut[1]=pos;
	Komut[2]=CheckListBox1->Checked[pos];
	sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,3);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
BYTE Komut[]={0x2,0x2};
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
BYTE Komut[]={0x2,0x3};
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
BYTE Komut[]={0x2,0x0};
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
BYTE Komut[]={0x2,0x1};
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
BYTE Komut[]={0x3};
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ayarlar1Click(TObject *Sender)
{
BYTE Komut[]={0x4,0,0};
Komut[2]=CheckListBox1->ItemIndex;
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::durdur1Click(TObject *Sender)
{
BYTE Komut[]={0x4,1,1};
Komut[2]=CheckListBox1->ItemIndex;
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ayarlar2Click(TObject *Sender)
{
Memo1->Clear();
BYTE Komut[]={0x5,1,2};
Komut[1]=CheckListBox1->ItemIndex;
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
						BYTE SendBuf[1024];
						SendBuf[0]=0x6;
						int yer = 1;
						SendBuf[1] = CheckListBox1->ItemIndex;
						yer++;
						*(DWORD*)&SendBuf[yer] = Memo1->Text.Length();
						yer+=4;
						memcpy(&SendBuf[yer],Memo1->Text.c_str(),Memo1->Text.Length());
						yer+=Memo1->Text.Length();
						sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(SendBuf,yer);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		BYTE Komut[256];
		Komut[0]=0x7;
		int yer = 1;
		Komut[1]=CheckListBox1->ItemIndex;
		Komut[2]=Edit1->Text.Length();
		yer+=2;
		memcpy(&Komut[yer],Edit1->Text.c_str(),Edit1->Text.Length());
		yer+=Edit1->Text.Length();
		sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,yer);
		Edit1->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
PageControl1->Height=  this->Height - Memo2->Height-80;;

CheckListBox1->Height = this->Height - Memo2->Height-120;
ListBox1->Height = this->Height - Memo2->Height-120;
ListBox2->Height = this->Height - Memo2->Height-120;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckListBox1Click(TObject *Sender)
{
Memo1->Clear();
BYTE Komut[]={0x5,1,2};
Komut[1]=CheckListBox1->ItemIndex;
sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,2);
ListBox1->ItemIndex = CheckListBox1->ItemIndex;
ListBox2->ItemIndex = CheckListBox1->ItemIndex;
ListBox1->TopIndex = CheckListBox1->TopIndex;
ListBox2->TopIndex = CheckListBox1->TopIndex;
	for (int iyer = 0; iyer < 28; iyer++) {

				String buf = IntToStr(Itemler[PageControl1->ActivePage->Tag][CheckListBox1->ItemIndex][iyer]);
				String itemm ="images/itemicon_";
				itemm+=buf.SubString(1,1);
				itemm+="_";
				itemm+=buf.SubString(2,4);
				itemm+="_";
				itemm+=buf.SubString(6,2);
				itemm+="_";
				itemm+=buf.SubString(8,1);
				itemm+="_thumb.jpg";
				if (!FileExists(itemm))
				{
					if (Itemler[PageControl1->ActivePage->Tag][CheckListBox1->ItemIndex][iyer]==0) {
					itemm="images\\co_black_thumb.jpg";
					}else{
					itemm="images/itemicon_9_0005_60_0_thumb.jpg";
					}

				}
				Img[iyer]->Picture->LoadFromFile(itemm);
				ItemAdet[iyer]->Caption = Countlar[PageControl1->ActivePage->Tag][CheckListBox1->ItemIndex][iyer];
				}

	}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
	  TCustomWinSocket *Socket)
{
TClientSocket *sck = dynamic_cast<TClientSocket *>(Sender);
Memo2->Lines->Add(IntToStr(sck->Tag)+  " : Giris Tamamlandi");
	BYTE Komut[1] = {0};
Socket->SendBuf(Komut,1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
TClientSocket *sck = dynamic_cast<TClientSocket *>(Sender);
Memo2->Lines->Add(IntToStr(sck->Tag)+  " : Cikis");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
TClientSocket *sck = dynamic_cast<TClientSocket *>(Sender);
String Buf = IntToStr(sck->Tag)+  " : Server Hata : " + IntToStr(ErrorCode);
Memo2->Lines->Add(Buf);
ErrorCode = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{


memset(Itemler,0,sizeof(Itemler));
Path = ExtractFilePath(Application->ExeName);
int x=0;
int y=20;
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 7; j++) {
Img[i*7+j]= new TImage(this);
Img[i*7+j]->Parent=GroupBox1;
Img[i*7+j]->Top=y;
Img[i*7+j]->Left=x;
Img[i*7+j]->Hint=i*7+j;
Img[i*7+j]->Height=45;
Img[i*7+j]->Width=45;
String a =Path+"images\\co_black_thumb.jpg";
Img[i*7+j]->Picture->LoadFromFile(a);
//Img[i*7+j]->OnClick=ItemIslem;
ItemAdet[i*7+j]= new TLabel(this);
ItemAdet[i*7+j]->Caption=0;
ItemAdet[i*7+j]->Font->Style=TFontStyles() << fsBold;
ItemAdet[i*7+j]->Font->Color=clWhite;
ItemAdet[i*7+j]->Top=y+30;
ItemAdet[i*7+j]->Left=x+10;
ItemAdet[i*7+j]->Height=20;
ItemAdet[i*7+j]->Width=35;
ItemAdet[i*7+j]->Parent=GroupBox1;

ItemPlus[i*7+j]= new TLabel(this);
ItemPlus[i*7+j]->Caption="+0";
ItemPlus[i*7+j]->Font->Style=TFontStyles() << fsBold;
ItemPlus[i*7+j]->Font->Color=clBlack;
ItemPlus[i*7+j]->Top=y;
ItemPlus[i*7+j]->Left=x;
ItemPlus[i*7+j]->Height=20;
ItemPlus[i*7+j]->Width=35;
ItemPlus[i*7+j]->Parent=GroupBox1;
x+=45;
}
x=0;
y+=45;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();	
}
//---------------------------------------------------------------------------
#define ITEM_BUS		   	379021000
#define ITEM_BLUE_CHEST		379156000
#define ITEM_GREEN_CHEST	379155000
#define ITEM_RED_CHEST	  	379154000

#define ITEM_FRAGMENT1		389160000
#define ITEM_FRAGMENT2      389161000
#define ITEM_FRAGMENT3      389162000
#define ITEM_FRAGMENT4      389163000
#define ITEM_FRAGMENT5      389164000
#define ITEM_FRAGMENT6      389165000
#define ITEM_FRAGMENT7      389166000
void __fastcall TForm1::Button8Click(TObject *Sender)
{
Memo1->Lines->Clear();
WORD ccc[10] ;
memset(ccc,0,sizeof(ccc));
for (int i = 0; i < 200; i++) {
for (int j = 0; j < 28; j++) {

DWORD itemid = Itemler[PageControl1->TabIndex][i][j];

int iyer = 11;
	if(	itemid==ITEM_BLUE_CHEST){
	iyer=7;
	ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];

	}else if (itemid==ITEM_GREEN_CHEST){
	iyer=8;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_RED_CHEST){

	}else if (itemid==ITEM_FRAGMENT1){
	iyer=0;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT2){
	iyer=1;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];;
	}else if (itemid==ITEM_FRAGMENT3){
	iyer=2;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT4){
	iyer=3;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT5){
	iyer=4;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT6){
	iyer=5;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT7){
	iyer=6;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_BUS){
	iyer=9;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	} else{
		continue;
	}
}
}
for (int i = 0; i < 10; i++) {
Memo1->Lines->Add(ccc[i]);
}

}
//---------------------------------------------------------------------------
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


void __fastcall TForm1::Button10Click(TObject *Sender)
{
int yer=1;
			/*while (yer<recvlen)
			{
				String a;
				char buf[100];
				memset(buf,0,100);
				memcpy(buf,&recvbuffer[yer+1],recvbuffer[yer]);
				yer +=recvbuffer[yer];
				yer++;
				a = "["+IntToStr(CheckListBox1->Items->Count+1)+"] ";
				a+=String(buf);
				memset(buf,0,100);
				memcpy(buf,&recvbuffer[yer+1],recvbuffer[yer]);
				yer +=recvbuffer[yer];
				yer++;
				a += " \t  |"+String(buf);
				CheckListBox1->Items->Add(a);
				ListBox1->Items->Add(0);
				CheckListBox1->Checked[CheckListBox1->Count-1]=recvbuffer[yer];
				yer++;
			}             */

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
if (f)
	return;
f=true;

for (int i = 0; i < Form1->ComboBox1->Items->Count; i++) {
sock[i] = new TClientSocket(NULL);
String AnaBuffer = ComboBox1->Items->Strings[i];
int ayrac = AnaBuffer.AnsiPos(":");
String buf1 = AnaBuffer.SubString(1,ayrac-1);
String buf2 = AnaBuffer.SubString(ayrac+1,AnaBuffer.Length()-ayrac);
sock[i]->Active = false;
sock[i]->Host = buf1;
sock[i]->Port = buf2.ToInt();
sock[i]->Tag=i;
sock[i]->OnConnect = ClientSocket1->OnConnect;
sock[i]->OnRead = ClientSocket1->OnRead;
sock[i]->OnDisconnect = ClientSocket1->OnDisconnect;
sock[i]->OnError = ClientSocket1->OnError;
	sock[i]->Active = true;


tab[i] = new TTabSheet(PageControl1);
tab[i]->Caption=i ;
tab[i]->Tag = i;
tab[i]->Hint =ComboBox1->Items->Strings[i];
tab[i]->ShowHint=true;
tab[i]->PageControl = PageControl1;
tab[i]->Visible=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PageControl1Change(TObject *Sender)
{

Form1->Caption = ComboBox1->Items->Strings[PageControl1->ActivePageIndex];
ListBox3->Items->Clear();
if (FileExists(ExtractFilePath(Application->ExeName)+ "itemloglar/"+ComboBox1->Items->Strings[PageControl1->ActivePageIndex])) {
ListBox3->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+ "itemloglar/"+ComboBox1->Items->Strings[PageControl1->ActivePageIndex]);
}

CheckListBox1->Items->Clear();
ListBox1->Items->Clear();
int yer=1;
			while (yer<recvlen[PageControl1->ActivePage->Tag])
			{
				String a;
				char buf[100];
				memset(buf,0,100);
				memcpy(buf,&recvbuffer[PageControl1->ActivePage->Tag][yer+1],recvbuffer[PageControl1->ActivePage->Tag][yer]);
				yer +=recvbuffer[PageControl1->ActivePage->Tag][yer];
				yer++;
				a = "["+IntToStr(CheckListBox1->Items->Count+1)+"] ";
				a+=String(buf);
				memset(buf,0,100);
				memcpy(buf,&recvbuffer[PageControl1->ActivePage->Tag][yer+1],recvbuffer[PageControl1->ActivePage->Tag][yer]);
				yer +=recvbuffer[PageControl1->ActivePage->Tag][yer];
				yer++;
				a += " \t  |"+String(buf);
				CheckListBox1->Items->Add(a);
				ListBox1->Items->Add(0);
				CheckListBox1->Checked[CheckListBox1->Count-1]=recvbuffer[PageControl1->ActivePage->Tag][yer];
				yer++;
			}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (ProgressBar1->Position>99) {
	Timer1->Enabled=false;
	recvmod=false;
}
ProgressBar1->StepBy(2);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
Timer2->Enabled= CheckBox1->Checked;
cevapgeldi=false;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
if (CheckListBox1->ItemIndex<CheckListBox1->Items->Count-1) {
if (CheckListBox1->Checked[CheckListBox1->ItemIndex])
{
if (cevapgeldi) {
CheckListBox1->ItemIndex++;
CheckListBox1Click(0);
cevapgeldi=false;
}else{

}
}else{
	CheckListBox1->ItemIndex++;
	CheckListBox1Click(0);
}
}else{
	CheckBox1->Checked=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	int pos = CheckListBox1->ItemIndex;
	int ii;
for (ii = 0; ii < Edit1->Text.ToIntDef(10); ii++)
{
	CheckListBox1->Checked[pos]=false;
	BYTE Komut[3];
	Komut[0]=0x1;

	Komut[1]=pos;

	Komut[2]=false;
	sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut,3);
	for (int j = 0; j < 5; j++)
	{
	   Sleep(100);
	   Application->ProcessMessages();
	}
		BYTE Komut2[256];
		Komut2[0]=0x7;
		int yer = 1;
		Komut2[1]=pos;
		Komut2[2]=lstrlen("gel");
		yer+=2;
		memcpy(&Komut2[yer],"gel",lstrlen("gel"));
		yer+=lstrlen("gel");
		sock[PageControl1->ActivePage->Tag]->Socket->SendBuf(Komut2,yer);

	for (int j = 0; j < 15; j++)
	{
	   Sleep(100);
	   Application->ProcessMessages();
	}
	if (pos >= CheckListBox1->Items->Count-1) {
	  break;
	}else{
	   pos++;
	}
}
CheckListBox1->ItemIndex=pos;
Button11->Caption = pos;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
WORD ccc[10] ;
memset(ccc,0,sizeof(ccc));
for (int i = 0; i < 200; i++) {
for (int j = 0; j < 28; j++) {

DWORD itemid = Itemler[PageControl1->TabIndex][i][j];

int iyer = 11;
	if(	itemid==ITEM_BLUE_CHEST){
	iyer=7;
	ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];

	}else if (itemid==ITEM_GREEN_CHEST){
	iyer=8;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_RED_CHEST){

	}else if (itemid==ITEM_FRAGMENT1){
	iyer=0;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT2){
	iyer=1;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];;
	}else if (itemid==ITEM_FRAGMENT3){
	iyer=2;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT4){
	iyer=3;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT5){
	iyer=4;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT6){
	iyer=5;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_FRAGMENT7){
	iyer=6;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	}else if (itemid==ITEM_BUS){
	iyer=9;
		ccc[iyer]+=Countlar[PageControl1->TabIndex][i][j];
	} else{
		continue;
	}
}
}
TDateTime a ;
a= a.CurrentDateTime();
String log;
log = a;
log+=" : ";
for (int i = 0; i < 10; i++) {
log+=IntToStr(ccc[i]) + " | ";
}
ListBox3->Items->Clear();
if (FileExists(ExtractFilePath(Application->ExeName)+ "itemloglar/"+ComboBox1->Items->Strings[PageControl1->ActivePageIndex])) {
ListBox3->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+ "itemloglar/"+ComboBox1->Items->Strings[PageControl1->ActivePageIndex]);
}
ListBox3->Items->Add(log);
ListBox3->Items->SaveToFile(ExtractFilePath(Application->ExeName)+ "itemloglar/"+ComboBox1->Items->Strings[PageControl1->ActivePageIndex]);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
Memo1->Visible = CheckBox2->Checked;	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
Dusur("188.132.161.223",Edit1->Text.c_str());	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
Dusur("188.132.161.226",Edit1->Text.c_str());	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
Dusur("188.132.161.221",Edit1->Text.c_str());	
}
//---------------------------------------------------------------------------

