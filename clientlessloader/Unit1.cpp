//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <iostream>
#include <fstream>
#include <ostream>
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
WORD ids[3];
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


	
typedef struct
{
	DWORD Id;
	WORD Count;
	WORD Durability;
}item_yapisi;
typedef struct {
char command[20];
WORD CharID,Hp,MaxHp,Mana,MaxMana;
	BYTE Level,CharClass,CharTipi;
	BYTE Zone;
	DWORD Para;
	bool CharMaster,CharHuman,LoginOk,AutoMine,AutoRepair;
	WORD FollowId;
	item_yapisi Gear_Table[14];
	item_yapisi Item_Table[28];
	WORD X,Y,goX,goY,moveSpeed,moveSleep;
	INT64 NeedExp;
	INT64 CurrExp;	
	char name[20];
    char member[16][20];

}my_struct;
my_struct strler[255];
HANDLE exeler[255];
DWORD LaunchTime[255];
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (FileExists(Edit1->Text))
{
	CheckListBox1->Items->Add(Edit1->Text);
	CheckListBox1->Items->SaveToFile("exeler.txt");
	ListBox2->Items->Add(100000);
}
else
{
	ShowMessage("girdiginiz konumda dosya yok");
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if (FindWindowA(NULL,"Project3.exe")){
HWND hwnd=FindWindowA(NULL,"Project3.exe");
SendMessage(hwnd, WM_CLOSE, NULL, NULL);
/*
DWORD pid;
DWORD dwThreadId = ::GetWindowThreadProcessId(hwnd, &pid);
TerminateProcess(OpenProcess(NULL,NULL,pid),0);          */
}



for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
ReadProcessMemory(exeler[i],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[i],sizeof(my_struct),0);
/*for (int index = 0; index < 16; index++)
{
my_struct *str = (my_struct*)Form1->Edit3->Text.ToIntDef(0x40100);
WriteProcessMemory(exeler[index],(LPVOID)(str->member[i]),ListBox1->Items->Strings[i].c_str(),20,0);
} */
if (strler[i].Level>83)
{
strler[i].Level = 0;
		STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
int i = CheckListBox1->ItemIndex;
		TerminateProcess(exeler[i],0);

		 CreateProcess(CheckListBox1->Items->Strings[i].c_str(),CheckListBox1->Items->Strings[i].c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,ExtractFilePath(CheckListBox1->Items->Strings[i]).c_str(),&si,&pi);
		exeler[i]= pi.hProcess;
		LaunchTime[i]= GetTickCount();
		ResumeThread(pi.hThread);
		ListBox2->Items->Strings[i]= 0;
}
ListBox3->Items->Strings[i]=IntToStr(strler[i].Level)+"|"+IntToStr(strler[i].Zone)+"|"+ListBox1->Items->Strings[i];
ListBox1->Items->Strings[i] = strler[i].name;
	if (FileExists(ExtractFilePath(CheckListBox1->Items->Strings[i])+"reiz"))
	{
	if (DeleteFileA(ExtractFilePath(CheckListBox1->Items->Strings[i])+"reiz")) {
		ListBox2->Items->Strings[i]= 0;
	}else{
	  ListBox2->Items->Strings[i]= 100000;
	  TerminateProcess(exeler[i],0);
	  DeleteFileA(ExtractFilePath(CheckListBox1->Items->Strings[i])+"reiz");
	}
	}
	else
	{
		ListBox2->Items->Strings[i]= ListBox2->Items->Strings[i].ToIntDef(0)+Timer1->Interval;
	}
	//ListBox1->Items->Strings[i] = GetTickCount()- LaunchTime[i];
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
int counter = 0;
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
if (CheckListBox1->Checked[i]) {
ReadProcessMemory(exeler[i],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[i],sizeof(my_struct),0);
ListBox3->Items->Strings[i]=IntToStr(strler[i].Zone);
	if (ListBox2->Items->Strings[i].ToIntDef(0)>Edit2->Text.ToIntDef(0))
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si,sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi,sizeof(pi));
		TerminateProcess(exeler[i],0);

		CreateProcess(CheckListBox1->Items->Strings[i].c_str(),CheckListBox1->Items->Strings[i].c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,ExtractFilePath(CheckListBox1->Items->Strings[i]).c_str(),&si,&pi);
		counter++;
		exeler[i]= pi.hProcess;
		LaunchTime[i]= GetTickCount();
		ResumeThread(pi.hThread);
		ListBox2->Items->Strings[i]= 0;
		if (counter>5) {
        return;
		}
	}
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
String exename = ExtractFileName(Application->ExeName);
exename = exename.SubString(1,exename.AnsiPos(".")-1);
ServerSocket1->Port 	= exename.ToIntDef(2587);
ServerSocket1->Active 	= true;
Caption = exename;
memset(exeler,0,sizeof(exeler));
if (FileExists("exeler.txt")) {
CheckListBox1->Items->LoadFromFile("exeler.txt");
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
	ListBox2->Items->Add("90000");
	ListBox3->Items->Add("0,0");
	ListBox1->Items->Add("0");
	ComboBox1->Items->Add(i);
		ComboBox2->Items->Add(i);
}
}
Memo2->Lines->Clear();
if (FileExists("exedurum.txt")) {
Memo2->Lines->LoadFromFile("exedurum.txt");
for (int i = 0; i < CheckListBox1->Items->Count; i++) {
CheckListBox1->Checked[i] =Memo2->Lines->Strings[i].ToIntDef(0);
}

}

if (FileExists((ExtractFilePath(CheckListBox1->Items->Strings[0]) + "ver.ini")))
{
AnsiString bufer = ExtractFilePath(CheckListBox1->Items->Strings[0]) + "ver.ini";
ifstream fLoad;

fLoad.open(bufer.c_str());
char a[10];
memset(a,0,10);
fLoad.getline(a,10);
fLoad.close();
Edit3->Text = "0x0"+ String(a);
}

}
bool KomutVer(int index,char* komut){
char cmd[20];
memset(cmd,0,20);
strcpy(cmd,komut);
WriteProcessMemory(exeler[index],(LPVOID)(Form1->Edit3->Text.ToIntDef(0x40100)),&cmd,20,0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Timer2->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Timer2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
for (int i = 0; i < 255; i++) {
	if (exeler[i]!=0) {
	 TerminateProcess(exeler[i],0);
	}

}
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
if (CheckListBox1->Checked[i]) {
CheckListBox1->ItemIndex = i;
CheckListBox1Click(0);
Dusur(Memo1->Lines->Strings[2],Memo1->Lines->Strings[0]);
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
if (CheckListBox1->Checked[i]) {
CheckListBox1->ItemIndex = i;
CheckListBox1Click(0);
Dusur(Memo1->Lines->Strings[2],Memo1->Lines->Strings[0]);
	STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
TerminateProcess(exeler[i],0);
CreateProcess(CheckListBox1->Items->Strings[i].c_str(),CheckListBox1->Items->Strings[i].c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,ExtractFilePath(CheckListBox1->Items->Strings[i]).c_str(),&si,&pi);
exeler[i]= pi.hProcess;
LaunchTime[i]= GetTickCount();
ResumeThread(pi.hThread);
ListBox2->Items->Strings[i]= 0;

}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
String filee = ExtractFilePath(Application->ExeName) + "project3.exe";
if (FileExists(filee)) {
for  (int i = 0; i < CheckListBox1->Items->Count; i++)
{
if (!CopyFileA(filee.c_str(),CheckListBox1->Items->Strings[i].c_str(),false)) {
  ShowMessage(i);
}

}
}

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button7Click(TObject *Sender)
{
	String Path =ExtractFilePath(CheckListBox1->Items->Strings[CheckListBox1->ItemIndex]);
	Path = Path + "ayar.txt";
	Memo1->Lines->SaveToFile(Path);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
CheckListBox1->Height = this->Height-80-GroupBox2->Height;
ListBox2->Height = this->Height-80-GroupBox2->Height;
ListBox3->Height = this->Height-80-GroupBox2->Height;
ListBox1->Height = this->Height-80-GroupBox2->Height;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
Memo2->Lines->Clear();
for (int i = 0; i < CheckListBox1->Items->Count; i++) {
Memo2->Lines->Add(IntToStr(CheckListBox1->Checked[i]));
}
Memo2->Lines->SaveToFile("exedurum.txt");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckListBox1Click(TObject *Sender)
{
	String Path =ExtractFilePath(CheckListBox1->Items->Strings[CheckListBox1->ItemIndex]);
	String ItemPath = Path + "item";
	String CountPath = Path + "count";
	String infoPath = Path + "info";
	Path = Path + "ayar.txt";
	if (FileExists(Path))
	{
	Memo1->Lines->LoadFromFile(Path);
	}
		if (FileExists(ItemPath))
	{
		Form2->ListBox1->Items->LoadFromFile(ItemPath);
	}
		if (FileExists(CountPath))
	{
		Form2->ListBox2->Items->LoadFromFile(CountPath);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckListBox1DblClick(TObject *Sender)
{
		STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si,sizeof(si));
si.cb = sizeof(si);
ZeroMemory(&pi,sizeof(pi));
int i = CheckListBox1->ItemIndex;
		TerminateProcess(exeler[i],0);

		 CreateProcess(CheckListBox1->Items->Strings[i].c_str(),CheckListBox1->Items->Strings[i].c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,ExtractFilePath(CheckListBox1->Items->Strings[i]).c_str(),&si,&pi);
		exeler[i]= pi.hProcess;
		LaunchTime[i]= GetTickCount();
		ResumeThread(pi.hThread);
		ListBox2->Items->Strings[i]= 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
if (Form2 == NULL)Form2 = new TForm2(NULL);
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
if (Memo3->Lines->IndexOf(Socket->RemoteAddress)==-1)
	{
		Socket->Close();
		return;
	}
	int len  = Socket->ReceiveLength();
	BYTE Komut[4096];
	Socket->ReceiveBuf(Komut,len);
	switch (Komut[0])
	{
		case 0:
		{
		BYTE SendBuf[1024];
		int Position = 0;
		SendBuf[Position]=0;
        Position++;
		for (int i = 0; i < CheckListBox1->Items->Count; i++)
		{
			//SendBuf[Position]=i;Position++;
            String path = ExtractFilePath(CheckListBox1->Items->Strings[i]);
			path = path + "ayar.txt";
			ifstream fLoad;
			fLoad.open(path.c_str());
			char bf[100];
			memset(bf,0,100);
			fLoad.getline(bf,100);
			SendBuf[Position]=strlen(bf);Position++;
			memcpy(&SendBuf[Position],bf,strlen(bf));
			Position+=strlen(bf);
			fLoad.getline(bf,100);
			memset(bf,0,100);
			fLoad.getline(bf,100);
			SendBuf[Position]=strlen(bf);Position++;
			memcpy(&SendBuf[Position],bf,strlen(bf));
			Position+=strlen(bf);
			fLoad.close();
			SendBuf[Position]=CheckListBox1->Checked[i];
			Position++;
		}
		Socket->SendBuf(SendBuf,Position);
		}break;
		case 1:
		{
			CheckListBox1->Checked[Komut[1]]=Komut[2];
			Memo2->Lines->Clear();
			for (int i = 0; i < CheckListBox1->Items->Count; i++)
			{
				Memo2->Lines->Add(IntToStr(CheckListBox1->Checked[i]));
			}
			Memo2->Lines->SaveToFile("exedurum.txt");
		}break;
		case 2:
		{
			switch (Komut[1])
			{
				case 0:
					Button2Click(0);
				break;
				case 1:
					Button3Click(0);
				break;
				case 2:
					Button4Click(0);
				break;
				case 3:
					Button5Click(0);
				break;
			}
		}break;
		case 3:
		{
			BYTE SendBuf[1024];
			SendBuf[0]=0x03;
			int len =1;
			for (int i = 0; i < ListBox2->Items->Count; i++)
			{
				*(DWORD*)&SendBuf[1+i*4]=ListBox2->Items->Strings[i].ToIntDef(0);
				len+=4;
			}
			Socket->SendBuf(SendBuf,len);
				  Memo2->Lines=ListBox3->Items;
						SendBuf[0]=0x99;
						int yer = 1;
						*(DWORD*)&SendBuf[yer] = Memo2->Text.Length();
						yer+=4;
						memcpy(&SendBuf[yer],Memo2->Text.c_str(),Memo2->Text.Length());
						yer+=Memo2->Text.Length();
						Socket->SendBuf(SendBuf,yer);
		}break;
		case 4:
		{
 			switch (Komut[1])
			{
				case 0:{
				STARTUPINFO si;
				PROCESS_INFORMATION pi;
				ZeroMemory(&si,sizeof(si));
				si.cb = sizeof(si);
				ZeroMemory(&pi,sizeof(pi));
				int i = Komut[2];
				TerminateProcess(exeler[i],0);
				CheckListBox1->ItemIndex = i;
				CheckListBox1Click(0);
				Dusur(Memo1->Lines->Strings[2],Memo1->Lines->Strings[0]);
				CreateProcess(CheckListBox1->Items->Strings[i].c_str(),CheckListBox1->Items->Strings[i].c_str(),NULL ,NULL,0,CREATE_SUSPENDED,NULL,ExtractFilePath(CheckListBox1->Items->Strings[i]).c_str(),&si,&pi);
				exeler[i]= pi.hProcess;
                 LaunchTime[i]= GetTickCount();
				ResumeThread(pi.hThread);
				ListBox2->Items->Strings[i]= 0;
				}break;
				case 1:
				{
					int i = Komut[2];
					TerminateProcess(exeler[i],0);
				}break;

			}
		}break;
		case 5:
				{
					String Path =ExtractFilePath(CheckListBox1->Items->Strings[Komut[1]]);
					String ItemPath = Path + "item";
					String CountPath = Path + "count";
					Path = Path + "ayar.txt";

					if (FileExists(Path))
					{
						Memo1->Lines->LoadFromFile(Path);
						BYTE SendBuf[1024];
						SendBuf[0]=0x5;
						int yer = 1;
						SendBuf[1]= Komut[1];
						yer++;
						*(DWORD*)&SendBuf[yer] = Memo1->Text.Length();
						yer+=4;
						memcpy(&SendBuf[yer],Memo1->Text.c_str(),Memo1->Text.Length());
						yer+=Memo1->Text.Length();
						Socket->SendBuf(SendBuf,yer);
					}
					if (exeler[Komut[1]]!=NULL)
					{
						BYTE SendBuf[1024];
						SendBuf[0]=0x11;
						int yer = 1;
						SendBuf[1]= Komut[1];
						yer++;
						/*ifstream iitem,ccount;
						iitem.open(ItemPath.c_str());
						ccount.open(CountPath.c_str());
						char buf[128],buf2[128];    */
						ReadProcessMemory(exeler[Komut[1]],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[Komut[1]],sizeof(my_struct),0);
						for (int i = 0; i < 28; i++)
						{
							*(DWORD*)&SendBuf[yer] =  strler[Komut[1]].Item_Table[i].Id;
							*(WORD*)&SendBuf[yer+4] =  strler[Komut[1]].Item_Table[i].Count;
							yer+=6;
						}

						*(DWORD*)&SendBuf[yer] =  strler[Komut[1]].Para;
						yer+=6;
						Socket->SendBuf(SendBuf,yer);
					}
		}break;
		case 6:
				{
					String Path =ExtractFilePath(CheckListBox1->Items->Strings[Komut[1]]);
					Path = Path + "ayar.txt";
					char buf[1024];
					memset(buf,0,1024);
					int yer = *(DWORD*)&Komut[2];
					memcpy(buf,&Komut[6],yer);
					Memo1->Text = String(buf);
					Memo1->Lines->SaveToFile(Path);
				}break;
		case 7:
				{
					char tmp[20];	memset(tmp,0,20);
					memcpy(tmp,&Komut[3],Komut[2]);
					KomutVer(Komut[1],tmp);
				}break;
	
		default:
		;
	}
}

//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode = 0;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
if (FindWindowA(NULL,"Project3.exe")){
ShowMessage("Buldu");
HWND hwnd=FindWindowA(NULL,"Project3.exe");
SendMessage(hwnd, WM_CLOSE, NULL, NULL);
DWORD pid;
DWORD dwThreadId = ::GetWindowThreadProcessId(hwnd, &pid);
TerminateProcess(OpenProcess(NULL,NULL,pid),0);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
Memo1->Lines->Clear();
for (int i = 0; i < 0xff; i++) {


Memo1->Lines->Add(GetProcessId(exeler[i]));

}
Memo1->Lines->SaveToFile("handleler.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
Memo1->Lines->Clear();
Memo1->Lines->LoadFromFile("handleler.txt");
for (int i = 0; i < Memo1->Lines->Count; i++) {
exeler[i] =OpenProcess(PROCESS_ALL_ACCESS,NULL,Memo1->Lines->Strings[i].ToIntDef(0)) ;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
String strPath;
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
String dirName_in = ExtractFilePath(CheckListBox1->Items->Strings[i]);
if (FileExists(CheckListBox1->Items->Strings[i])) {
continue;
}
/*  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
	continue;   // this is a directory!  */
	CreateDirectoryA(dirName_in.c_str(),NULL);
String filee = ExtractFilePath(Application->ExeName) + "project3.exe";
if (FileExists(filee)) {
String f1 = dirName_in + "project3.exe";
String f2 = dirName_in + "cc3280.dll";
String f3 = dirName_in + "ClassMorphineeDll.dll";
String f4 = dirName_in + "ayar.txt";
String f11 = ExtractFilePath(Application->ExeName) + "project3.exe";
String f22 = ExtractFilePath(Application->ExeName) + "cc3280.dll";
String f33 = ExtractFilePath(Application->ExeName) + "ClassMorphineeDll.dll";
String f44 = ExtractFilePath(Application->ExeName) + "ayar.txt";

CopyFileA(f11.c_str(),f1.c_str(),false);
CopyFileA(f22.c_str(),f2.c_str(),false);
CopyFileA(f33.c_str(),f3.c_str(),false);
CopyFileA(f44.c_str(),f4.c_str(),false);
}
}
}



//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	for (int i = 0; i < Memo1->Lines->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		list->Strings[0]=Memo1->Lines->Strings[i];
		list->SaveToFile(path);
		list->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	for (int i = 0; i < Memo1->Lines->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		if (Memo1->Lines->Strings[i]==0) {
		list->Strings[4]="0";
		}else{
		list->Strings[4]="1";
        }
		list->Strings[5]=Memo1->Lines->Strings[i];
		list->SaveToFile(path);
		list->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	for (int i = 0; i < Memo1->Lines->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		list->Strings[6]=Memo1->Lines->Strings[i];
		list->SaveToFile(path);
		list->Free();
	}	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button17Click(TObject *Sender)
{
	for (int i = 0; i < Memo1->Lines->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		list->Strings[1]=Memo1->Lines->Strings[i];
		list->SaveToFile(path);
		list->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
Memo1->Lines->Clear();
	for (int i = 0; i < CheckListBox1->Items->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		for (int j = 0; j < list->Count; j++)
		{
			Memo1->Lines->Add(list->Strings[j]);
		}
		list->Free();
	}
	Memo1->Lines->SaveToFile("Export.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
if (!FileExists("Export.txt")){
ShowMessage("dosya bulunamadi.");
return;
}
Memo1->Lines->Clear();
Memo1->Lines->LoadFromFile("Export.txt");
int satir;
int sira=-1;
TStringList *list;
list = new TStringList();
String path;
for (int i = 0; i < Memo1->Lines->Count; i++)
{
satir = i%13;
if (satir == 0)
{
if (sira!=-1) {
list->SaveToFile(path);
}
sira++;
list->Clear();
path = ExtractFilePath(CheckListBox1->Items->Strings[sira])+"ayar.txt";
}
list->Add(Memo1->Lines->Strings[i]);


}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	for (int i = 0; i < CheckListBox1->Items->Count; i++)
	{
		TStringList *list;
		list = new TStringList();
		String path = ExtractFilePath(CheckListBox1->Items->Strings[i])+"ayar.txt";
		list->LoadFromFile(path);
		Memo1->Lines->Add(list->Strings[5]);
		list->SaveToFile(path);
		list->Free();
	}
    Memo1->Lines->SaveToFile("pxlist.txt");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button21Click(TObject *Sender)
{

	BYTE test[1] = { 0x00 };

		ReadProcessMemory(exeler[0],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[0],sizeof(my_struct),0);
		ShowMessage(strler[0].CharID);
		ShowMessage(strler[0].name);
	//ShowMessage(test[0]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
for (int i = 0; i < CheckListBox1->Items->Count; i++)
{
 if ((ids[0]==0||ids[1]==0||ids[2]==0)&&CheckListBox1->Checked[i])
 {
	ReadProcessMemory(exeler[i],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[i],sizeof(my_struct),0);
	switch (strler[i].Zone)
	{
		case 0x15:
		if(ids[0]==0)
			ids[0]==i;
		else
		{
			String a =  IntToStr(strler[ids[0]].CharID);
			KomutVer(i,a.c_str());
		}

		break;
		case 1:
		if (ids[1]==0)
			ids[1]==i;
		else
		{
			String a =  IntToStr(strler[ids[1]].CharID);
			KomutVer(i,a.c_str());
		}
		break;
		case 2:
		if (ids[2]==0)
			ids[2]==i;
		else
		{
			String a =  IntToStr(strler[ids[2]].CharID);
			KomutVer(i,a.c_str());
		}
		break;
	default:
		;
	}
 }
}
Memo1->Lines->Clear();
for (int i = 0; i < 3; i++) {
	Memo1->Lines->Add(ids[i]);
}
/*
ReadProcessMemory(exeler[ComboBox1->ItemIndex],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[ComboBox1->ItemIndex],sizeof(my_struct),0);
ReadProcessMemory(exeler[ComboBox2->ItemIndex],(LPVOID)Edit3->Text.ToIntDef(0x40100),&strler[ComboBox2->ItemIndex],sizeof(my_struct),0);
if (strler[ComboBox1->ItemIndex].Zone==strler[ComboBox2->ItemIndex].Zone) {

String a =  IntToStr(strler[ComboBox1->ItemIndex].CharID);

KomutVer(ComboBox2->ItemIndex,a.c_str());
Sleep(2000);
KomutVer(ComboBox1->ItemIndex,"alan");
KomutVer(ComboBox2->ItemIndex,"veren");
}else{
    ComboBox2->ItemIndex++;
}   */
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button23Click(TObject *Sender)
{
Dusur(Memo1->Lines->Strings[2],Memo1->Lines->Strings[0]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ptkur1Click(TObject *Sender)
{
    KomutVer(ListBox1->ItemIndex,"pt_kur");
}
//---------------------------------------------------------------------------

