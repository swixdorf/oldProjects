//---------------------------------------------------------------------------

#ifndef koclinetH
#define koclinetH
#include "KoThreadClass.h"
#include "keyuret.h"
#include <vector>
#include <math.h>
#include "Unit1.h"
//#include <windows.h>
//---------------------------------------------------------------------------
typedef struct{
	WORD Id;
	WORD X;
	WORD Y;
	   } Npc;
typedef struct{
	Npc Potion;
	Npc Sundress;
	Npc Inn;
	Npc Pitman;
	Npc Warp;
	   } ZoneYapi;

typedef struct{
	WORD Id;
	WORD Name;
	WORD X;
	WORD Y;
	BYTE Level;
	BYTE NpcType;
	DWORD Hp;
	String Isim ;
	   } Npcs;


typedef struct{

BYTE Sk[4][24];
BYTE SkSize[4];
BYTE SkType;
bool Active;
DWORD Timer;
DWORD LastUse;
String SkillName;
}SkillYapi;

typedef struct {
WORD PotMiktar;
DWORD PotId;
DWORD PotSkill;
WORD PotcuYer;
}pot;


typedef std::vector<Npcs>NpcVecList;
class KoClinet
{
	public:
	 KoThreadClass  *Ko_Threadsyn;
	KoClinet();
 //	~KoClinet();
	AnsiString Key_Uret(AnsiString prkey);

	 AddNpc(WORD NpcId,WORD X,WORD Y)
  {
//  Form1->log->Items->Add("NPC Add : "+ IntToStr(NpcId)+" : "+ IntToStr(X)+" : "+ IntToStr(Y));
   try{
  Npcs NpcAdd;
  NpcAdd.Id=NpcId;

  NpcAdd.X=X;
  NpcAdd.Y=Y;
  NpcVec.push_back(NpcAdd) ;
   }
	catch(...)
	{
	   return -1;
	}
	return 1 ;
  }


  IsAdded(WORD NpcId)
  {
  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=NpcVec.begin();it!=NpcVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
		return index;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }
  SetNpc(WORD NpcId,WORD X,WORD Y)
  {
  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=NpcVec.begin();it!=NpcVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
		it->X=X;
		it->Y=Y;
		return 1;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }

  DelNpc(WORD NpcId)
  {


  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=NpcVec.begin();it!=NpcVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
NpcVec.erase(it);
		return 1;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }
	NearNpc(WORD *messafe)
  {
  try{
   NpcVecList::iterator it;
		WORD mesafe=0xFFFF;
		WORD NearNpc=0xFFFF;
		int index=0;
	WORD x,y;
	if (RunToMob) {
	x=CenterX;
	y=CenterY;
	}else{
	x=Ko_Threadsyn->Socket_Bilgi1->X;
	y=Ko_Threadsyn->Socket_Bilgi1->Y;
	}
  for(it=NpcVec.begin();it!=NpcVec.end();it++,index++)

	{
	WORD mes=hypot(it->X-x,it->Y-y);
	//WORD mes=(int)sqrt(pow((it->X-x),2)+pow((it->Y-y),2));
	if (mes>100) {
	DelNpc(it->Id);
	}else{
	if (mes<mesafe) {
	mesafe=mes;
	NearNpc=it->Id;
	TargetX=it->X;
	TargetY=it->Y;

	}
	}
	}
	 *messafe=mesafe;
	return NearNpc ;
	}
	catch(...)
	{
	   return -1;
	}
  }









	 AddPlayer(WORD NpcId,WORD X,WORD Y,String Name,BYTE race )
  {

   try{
  Npcs NpcAdd;
  NpcAdd.Id=NpcId;

  NpcAdd.X=X;
  NpcAdd.Y=Y;
  NpcAdd.Isim=Name;
  NpcAdd.NpcType=race;
  PlayerVec.push_back(NpcAdd) ;
   }
	catch(...)
	{
	   return -1;
	}
	return 1 ;
  }


  IsPlayerAdded(WORD NpcId)
  {
  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=PlayerVec.begin();it!=PlayerVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
		return index;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }
  SetPlayer(WORD NpcId,WORD X,WORD Y)
  {
  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=PlayerVec.begin();it!=PlayerVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
		it->X=X;
		it->Y=Y;
		return 1;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }

  DelPlayer(WORD NpcId)
  {


  try{
   NpcVecList::iterator it;
		int aranan=NpcId;
		int index=0;

  for(it=PlayerVec.begin();it!=PlayerVec.end();it++,index++)

	{
	  WORD a= it->Id;
		if(a==aranan)
		{
PlayerVec.erase(it);
		return 1;
		}
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }
	NearPlayer(WORD *messafe)
  {
  try{
   NpcVecList::iterator it;
		WORD mesafe=0xFFFF;
		WORD NearNpc=0xFFFF;
		String Name;
		int index=0;
	WORD x,y;
	if (RunToMob) {
	x=CenterX;
	y=CenterY;
	}else{
	x=Ko_Threadsyn->Socket_Bilgi1->X;
	y=Ko_Threadsyn->Socket_Bilgi1->Y;
	}
  for(it=PlayerVec.begin();it!=PlayerVec.end();it++,index++)

	{
	WORD mes=hypot(it->X-x,it->Y-y);
	//WORD mes=(int)sqrt(pow((it->X-x),2)+pow((it->Y-y),2));
	if (mes>150) {
	DelPlayer(it->Id);
	}else{
	if (true) {

	}
	if (mes<mesafe) {
	int myrace;
	if (CharHuman) {
	myrace=2;
	}else{
	myrace=1;
	}
	if (it->NpcType!=myrace) {


	mesafe=mes;
	NearNpc=it->Id;
	TargetX=it->X;
	TargetY=it->Y;
	Name = it->Isim;
	}
	}
	}
	}
	 *messafe=mesafe;
	return NearNpc ;
	}
	catch(...)
	{
	   return -1;
	}
  }




















	LogPlayer(int soc)
  {
  try{
   NpcVecList::iterator it;
		int index=0;

  for(it=PlayerVec.begin();it!=PlayerVec.end();it++,index++)

	{
	int id= it->Id;
//Ko_Threadsyn->Log->Add(IntToStr(id));// Log->Add(IntToStr(int)it->Id);

Form1->ListBox44->Items->Add(it->Name);
//Form1->ListBox2->Items->Add(it->X);
//Form1->ListBox3->Items->Add(it->Y);
//WORD mes=(int)sqrt(pow((it->X-Ko_Thread[soc]->Socket_Bilgi1->X),2)+pow((it->Y-Ko_Thread[soc]->Socket_Bilgi1->Y),2));
//Form1->ListBox4->Items->Add(mes);
	}
	return -1 ;
	}
	catch(...)
	{
	   return -1;
	}
  }
AnsiString BufferToHex(char *buf,int size)
{
AnsiString str;
for(int i=0;i<size;i++)
{
BYTE a=buf[i];
str+="0x"+IntToHex(a,2)+",";
}
return str;
}

AnsiString ByteToString(char *buf,int size)
{
String str="";
for(int i=0;i<size;i++)
{
str+=StringOfChar(buf[i],1);
}
return str;
}

int FindItem(DWORD ItemId){
for (int i = 0; i < 28; i++) {
	   if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[i].Id==ItemId) {
		 return i;
	   }
}
return -1 ;
}

MesajYolla(int Tip,String Mesaj)
{
BYTE PmKomut[255];
BYTE Komut[]={0x10,0x02};
Komut[1]=Tip;
BYTE GidecekMesaj[250];
int topuzunluk=2;
int mesajuzunluk=Mesaj.Length();
memcpy(GidecekMesaj,&mesajuzunluk,2);
memcpy(&GidecekMesaj[2],Mesaj.c_str(),mesajuzunluk);
topuzunluk+=mesajuzunluk+2;
memcpy(&PmKomut[0],&Komut,sizeof(Komut));
memcpy(&PmKomut[2],&GidecekMesaj,sizeof(GidecekMesaj));
KomutYolla(PmKomut,topuzunluk);
}

PmYolla(String CharName,String Mesaj) {
BYTE PmKomut[100];
memset(PmKomut,0,100);
BYTE Komut[]={0x35,0x01};
*(WORD*)&PmKomut[0]=*(WORD*)&Komut[0];
*(WORD*)&PmKomut[2]=CharName.Length();
memcpy(&PmKomut[4],CharName.c_str(),CharName.Length());
KomutYolla(PmKomut,CharName.Length()+4);
BYTE PmKomut1[255];
memset(PmKomut1,0,255);
BYTE Komut1[]={0x10,0x02};
*(WORD*)&PmKomut1[0]=*(WORD*)&Komut1[0];
*(WORD*)&PmKomut1[2]=Mesaj.Length();
memcpy(&PmKomut1[4],Mesaj.c_str(),Mesaj.Length());
KomutYolla(PmKomut1,Mesaj.Length()+4);
 return 0;
}
bool ZoneChange(BYTE nZone){
ZoneId=nZone;
switch (ZoneId) {
case 0x01 :
Zone.Potion.Id=0x37c6;
Zone.Potion.X=470;
Zone.Potion.Y=1665;

Zone.Sundress.Id=0x3a6f;
Zone.Sundress.X=450;
Zone.Sundress.Y=1686;

Zone.Pitman.Id=14932;
Zone.Pitman.X=468;
Zone.Pitman.Y=1625;

Zone.Inn.Id=0x37c9;
Zone.Inn.X=368;
Zone.Inn.Y=1687;

Zone.Warp.Id=0;
Zone.Warp.X=446;
Zone.Warp.Y=1619;

ZoneName="Luferson";
;break;
case 0x02 :
Zone.Potion.Id=0x2af1;
Zone.Potion.X=1600;
Zone.Potion.Y=395;

Zone.Sundress.Id=0x2af6;
Zone.Sundress.X=1619;
Zone.Sundress.Y=365;

Zone.Inn.Id=0x2ab6;
Zone.Inn.X=1688;
Zone.Inn.Y=369;

Zone.Pitman.Id=0x2cee;
Zone.Pitman.X=1648;
Zone.Pitman.Y=571;

Zone.Warp.Id=0;
Zone.Warp.X=1589;
Zone.Warp.Y=415;

ZoneName="El Morad Castle";
;break;
case 0x15 :
Zone.Potion.Id=0x2f69;
Zone.Potion.X=752;
Zone.Potion.Y=555;

Zone.Sundress.Id=0x2f59;
Zone.Sundress.X=760;
Zone.Sundress.Y=523;

Zone.Inn.Id=0x2f56;
Zone.Inn.X=866;
Zone.Inn.Y=649;

Zone.Pitman.Id=0x2f3f;
Zone.Pitman.X=666;
Zone.Pitman.Y=413;

Zone.Warp.Id=0;
Zone.Warp.X=834;
Zone.Warp.Y=527;


ZoneName="Moradon";
;break;

case 0x1F :
Zone.Potion.Id=0x4C2A;
Zone.Potion.X=75;
Zone.Potion.Y=719;

Zone.Sundress.Id=0x2884;
Zone.Sundress.X=86;
Zone.Sundress.Y=723;

Zone.Inn.Id=0x4c29;
Zone.Inn.X=79;
Zone.Inn.Y=721;

Zone.Pitman.Id=0x3ab0;
Zone.Pitman.X=79;
Zone.Pitman.Y=721;

Zone.Warp.Id=0;
Zone.Warp.X=834;
Zone.Warp.Y=527;

ZoneName="Bifrost";
;break;

case 85 :
Zone.Potion.Id=0x4C2A;
Zone.Potion.X=75;
Zone.Potion.Y=719;

Zone.Sundress.Id=0x2884;
Zone.Sundress.X=86;
Zone.Sundress.Y=723;

Zone.Inn.Id=0x4c29;
Zone.Inn.X=79;
Zone.Inn.Y=721;

Zone.Pitman.Id=0x3ab0;
Zone.Pitman.X=79;
Zone.Pitman.Y=721;

Zone.Warp.Id=0;
Zone.Warp.X=834;
Zone.Warp.Y=527;

ZoneName="Chaos";
chaosgir=2;
;break;

default:
memset(&Zone,sizeof(Zone),0);
ZoneName="Unknown Zone : "+IntToStr(ZoneId);
	;
}


}
bool Town(){
 BYTE Komut[]={0x48,0x00};
KomutYolla(Komut,sizeof(Komut));
TownState=false;
while (!TownState)
{
Application->ProcessMessages() ;
Sleep(100);
}

return 1 ;
}

bool InventoryRefresh(){
 BYTE Komut[]={0x6a,0x02};
KomutYolla(Komut,sizeof(Komut));
Sleep(2000);


return 1 ;
}


WORD ItemCountInc(BYTE Yer){
Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet++;
return Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet;
}
WORD ItemCountDec(BYTE Yer){
if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet<2) {
Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet=0;
Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Id=0;
}
return Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet;     
}
WORD GetItemCount(BYTE Yer){
return Ko_Threadsyn->Socket_Bilgi1->Item_Table[Yer].Adet; 
}

BYTE intlen(DWORD buf){
BYTE len = log10(buf)+1;
return len;
}
int intsub(DWORD buf,BYTE index,BYTE count){
BYTE len = intlen(buf);
DWORD buf1 = buf/pow10(len-(index+count));
DWORD buf2 = buf1/pow10(count);
buf2=buf2*pow10(count);
buf1=buf1-buf2;
return buf1;
}

bool SkillKodDuzenle(BYTE *Skill){
int SkillCode=*(DWORD*)&Skill[2];
DWORD sk;
if (CharMaster) {
sk = Ko_Threadsyn->Socket_Bilgi1->CharClass;
}else{
sk = Ko_Threadsyn->Socket_Bilgi1->CharClass-1;
}
if (CharHuman) {
sk+=100;
}
sk = sk*1000+intsub(SkillCode,3,3);
*(DWORD*)&Skill[2]=sk;
return 1;
}


bool KomutYolla(BYTE *Komut,DWORD KomutUzunluk){


if (Komut[0]==0x31) {
SkillKodDuzenle(Komut) ;
//Form1->log->Items->Add(BufferToHex(Komut,KomutUzunluk));
}
Ko_Threadsyn->Extern_KomutYolla(Komut,KomutUzunluk);

return true;

}

PotionIc(DWORD PotKod)
{
BYTE POT[]={0x31, 0x3,
0x0, 0x0, 0x0, 0x0,
0x0,
0x5, 0x0,
0x5, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
*(DWORD*)&POT[2]=PotKod;
*(WORD*)&POT[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
*(WORD*)&POT[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
Ko_Threadsyn->Extern_KomutYolla(POT,sizeof(POT));
 return 1;
}


PartyChatYolla(AnsiString Message)
{
BYTE GidecekMesaj[250];
GidecekMesaj[0]=0x10;
GidecekMesaj[1]=0x03;
*(WORD*)&GidecekMesaj[2]=Message.Length();
memcpy(&GidecekMesaj[4],Message.c_str(),Message.Length());
KomutYolla(GidecekMesaj,sizeof(GidecekMesaj));
return 1 ;
}


WORD GetItemAdet(DWORD ItemId){
for (int i = 0; i < 28; i++) {
if(Ko_Threadsyn->Socket_Bilgi1->Item_Table[i].Id==ItemId){
return Ko_Threadsyn->Socket_Bilgi1->Item_Table[i].Adet;
}
}
return 0;
}
KutuAc(DWORD KutuId) {
 BYTE Komut[]={0x24,0x00,0x00,0x00,0x00};
 *(DWORD*)&Komut[1]=KutuId;
 KomutYolla(Komut,sizeof(Komut));

//DelKutu(&Kutum,KutuId);
KutuNumarasi=KutuId;
 return 0;
}

bool ItemKontrol(DWORD List[255],BYTE Count,DWORD ItemId,bool PlusSensitive){
if (Count>0) {
if (!PlusSensitive) {
DWORD IdEdit=ItemId/1000;
ItemId=IdEdit*1000;
}
for (int i = 0; i < Count; i++) {
if(ItemId==List[i]){
return true;
}
}
}
return false ;
}
ItemTopla(DWORD item,BYTE *Komut )
{

		 *(DWORD*)&Komut[5]=item;
KomutYolla(Komut,9);
return 1;
}



ItemAl(BYTE *gelen24) {

 BYTE Komut[]={0x26,0x5C,0x05,0x0A,0x00,0x00,0xE9,0xA4,0x35};
	 *(DWORD*)&Komut[1]=KutuNumarasi;


			ItemTopla(*(DWORD*)&gelen24[1],Komut);
			ItemTopla(*(DWORD*)&gelen24[7],Komut);
			ItemTopla(*(DWORD*)&gelen24[13],Komut);
			ItemTopla(*(DWORD*)&gelen24[19],Komut);
			ItemTopla(*(DWORD*)&gelen24[25],Komut);
			ItemTopla(*(DWORD*)&gelen24[31],Komut);
			KutuNumarasi=0;

return 0;
}


HareketEt(float X,float Y){
BYTE Skill[]={0x6, 0xED, 0xD, 0xFA, 0x43, 0x90, 0x0, 0x2D, 0x0, 0x3};
float carp=1.0e1;
float aktar=0;
WORD Prm1=0;
WORD Prm3=0;


	Prm1=X;
	aktar=Prm1*carp;
	Prm1=aktar;

	Prm3=Y;
	aktar=Prm3*carp;
	Prm3=aktar;

   memcpy(&Skill[1],&Prm1,2);
   memcpy(&Skill[3],&Prm3,2);
   KomutYolla(Skill,10);

   Skill[7]=0;
   Skill[9]=0;

   KomutYolla(Skill,10) ;
	Ko_Threadsyn->Socket_Bilgi1->X=X;
	Ko_Threadsyn->Socket_Bilgi1->Y=Y;
return 0;
}

CharacterMove(WORD X,WORD Y, int Arrive){
Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
Ko_Threadsyn->Socket_Bilgi1->AdresX=X;
Ko_Threadsyn->Socket_Bilgi1->AdresY=Y;
Ko_Threadsyn->Socket_Bilgi1->Arrive=Arrive;
Ko_Threadsyn->Socket_Bilgi1->Go=true;
 return 1 ;
};
int CrashListControl(DWORD Id){
if (Id==0) {
return -1 ;    
}
for (int i = 0; i < 255; i++) {
if (CrashItemList[i]==Id) {
return 1 ;
}else if (CrashItemList[i]==0) {
return -1 ;
	  }
}
return -1 ;
}
int SellListControl(DWORD Id){
if (Id==0) {
return -1 ;    
}
for (int i = 0; i < 255; i++) {
if (SellItemList[i]==Id) {
return 1 ;
}else if (SellItemList[i]==0) {
return -1 ;
	  }  
}
return -1 ;
}
int TradeListControl(DWORD Id){
if (Id==0) {
return -1 ;    
}
for (int i = 0; i < 255; i++) {
if (TradeItemList[i]==Id) {
return 1 ;
}else if (TradeItemList[i]==0) {
return -1 ;
	  }  
}
return -1 ;
}
Arrive(){
switch (Ko_Threadsyn->Socket_Bilgi1->Arrive) {
case 0:{
//Client[Ko_Threadsyn->tsocketno].InventoryRefresh();
}break;
case 1://Kaz
{
Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
CharacterMove(MineX,MineY,4);
} break;
case 2://Kir
{
for (int j = 0; j < 28; j++) {
if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0x2faf8cd0) {
BYTE Komut1[]={0x31,0x03,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut1[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
*(WORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;

BYTE Komut2[]={0x31,0x06,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*(WORD*)&Komut2[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
*(WORD*)&Komut2[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
for (int i = 0; i < 3; i++) {
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1));
Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
}
}else if (CrashListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1) {
BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
Komut1[2]=j ;
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
}
}

 BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[27].Id ;
Komut1[2]=27 ;
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;




for (int a = 0; a < 28; a++) {
Sleep(50);
if ((Ko_Threadsyn->Socket_Bilgi1->LoginOk)/*&&(!Ko_Threadsyn->Terminated)*/) {
BYTE Komut0[]={0x20,0x01,0xB0,0x3A,0xFF,0xFF,0xFF,0xFF,};
*(WORD*)&Komut0[2]=Zone.Pitman.Id;
Ko_Threadsyn->Extern_KomutYolla(Komut0,sizeof(Komut0)) ;
BYTE Komut[]={0x64,0x07,0x54,0x4E,0x00,0x00};
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut)) ;
BYTE Komut2[]={0x55,0x00,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
BYTE Komut3[]={0x55,0x01,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
Ko_Threadsyn->Extern_KomutYolla(Komut3,sizeof(Komut3));
}
}

//Client[Ko_Threadsyn->tsocketno].InventoryRefresh();
for (int j = 0; j < 28; j++) {
if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0x2faf8cd0) {
BYTE Komut1[]={0x31,0x03,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
*(WORD*)&Komut1[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
*(WORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;

BYTE Komut2[]={0x31,0x06,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
*(WORD*)&Komut2[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
*(WORD*)&Komut2[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
for (int i = 0; i < 3; i++) {
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1));
Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
}
}else if (CrashListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1) {
BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
Komut1[2]=j ;
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
}
}
InventoryRefresh();

if ((TradeListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id))==-1&&(Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id!=0)) {
for (int j = 0; j < 28; j++) {
if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0) {
BYTE Komut[]={0x1F,0x03,0x00,0x4F,0xCB,0x17,0x04,0x05};
*(DWORD*)&Komut[2]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id;
Komut[6]=25;
Komut[7]=j;
Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
}
}
}

if ((Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id!=0)||(Ko_Threadsyn->Socket_Bilgi1->Gear_Table[6].Durability<500)) {
CharacterMove(Zone.Sundress.X,Zone.Sundress.Y,3);
}else {
Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
CharacterMove(MineX,MineY,4);
}

} break;
case 3://Sund
{
InventoryRefresh();
for (int j = 0; j < 28; j++) {
if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id!=0) {
if (SellListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1) {
Sleep(50);
BYTE Komut1[]={0x21,0x02,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x38,0xD0,0x30,0x17,0x04,0x03,0x00};
*(WORD*)&Komut1[6]=Zone.Sundress.Id;
*(DWORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
*(WORD*)&Komut1[13]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Adet ;
Komut1[12]=j ;
Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
}




}
}

BYTE Komut0[]={0x3B,0x01,0x06,0xDB,0x3A,0xE0,0xAE,0x31,0x17};
*(WORD*)&Komut0[3]=Zone.Sundress.Id;
*(DWORD*)&Komut0[5]=Ko_Threadsyn->Socket_Bilgi1->Gear_Table[6].Id;
Ko_Threadsyn->Extern_KomutYolla(Komut0,sizeof(Komut0)) ;

InventoryRefresh();

if (AutoMine) {
CharacterMove(MineX,MineY,4);
}else{
PartyChatYolla("TTT Tp")    ;
//CharacterMove(Ko_Threadsyn->tsocketno,DonulecekX,DonulecekY,0);
}

} break;
case 4:{   //kazmaya basla
Ko_Threadsyn->Socket_Bilgi1->Kaz=true;
Ko_Threadsyn->Socket_Bilgi1->Arrive=0;
}break;
case 5:{ //potcu
SellItems(1);
PotBuy();
//Client[Ko_Threadsyn->tsocketno].PartyChatYolla(Form1->spcode->Text + " Tp")    ;
CharacterMove(Zone.Sundress.X,Zone.Sundress.Y,10);
//CharacterMove(Ko_Threadsyn->tsocketno,Client[Ko_Threadsyn->tsocketno].DonulecekX,Client[Ko_Threadsyn->tsocketno].DonulecekY,0);



}break;
case 6:{ //dolas

}break;
case 7:{

Ko_Threadsyn->Socket_Bilgi1->Arrive=0;
}break;
case 8 : {  //buy armor
BYTE Komut[]={0x21,0x01,0x11,0x15,0x03,0x00,0xED,0x2A,0x69,0xD1,0x9D,0x0F,0x01,0x01,0x00,0x01,0x0C,};
*(DWORD*)&Komut[8]=201001001+PaperArmor*1000000+PaperItem*1000;
switch (PaperClass) {
case 0 :;break;

case 1 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+40000000;break;
case 2 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+60000000;break;
case 3 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+80000000;break;
default:
	;
}
Komut[15]=  PaperArmor;
Komut[16]=  PaperItem+6*PaperClass;
//Form1->log->Items->Add(BufferToHex(Komut,sizeof(Komut)));
for (int i = 0; i < 28; i++) {
Komut[12]= i ;
KomutYolla(Komut,sizeof(Komut));
}
Komut[0]=0x6a;
Komut[1]=0x2;
KomutYolla(Komut,2);
}break;
case 9:{ //inn

}break;

case 10:{ //sund
SellItems(0);
ItemRepair();
PartyChatYolla("TTT SlotTp")    ;
//CharacterMove(Ko_Threadsyn->tsocketno,Client[Ko_Threadsyn->tsocketno].DonulecekX,Client[Ko_Threadsyn->tsocketno].DonulecekY,0);



}break;
case 11:{ //matock al
BYTE Komut1[]={0x20,0x01,0xB0,0x3A,0xFF,0xFF,0xFF,0xFF};
*(WORD*)&Komut1[2]=Zone.Pitman.Id;
BYTE Komut2[]={0x64,0x07,0x4D,0x4E,0x00,0x00};
BYTE Komut3[]={0x55,0x00,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
KomutYolla(Komut1,sizeof(Komut1));
KomutYolla(Komut2,sizeof(Komut2));
KomutYolla(Komut3,sizeof(Komut3));
}break;
case 12:{ //gobif
BYTE Komut1[]={0x20,0x01,0x1B,0x32,0xFF,0xFF,0xFF,0xFF};
BYTE Komut2[]={0x55,0x00,0x0F,0x36,0x30,0x32,0x5F,0x42,0x69,0x66,0x6D,0x6F,0x76,0x65,0x2E,0x6C,0x75,0x61};
KomutYolla(Komut1,sizeof(Komut1));
KomutYolla(Komut2,sizeof(Komut2));
}break;
case 13:{ //buybow
switch (BuyBowIndex) {
case 0 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xA1,0xEE,0x8A,0x09,0x0F,0x01,0x00,0x02,0x06};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
case 1 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x51,0x9C,0x8C,0x09,0x0F,0x01,0x00,0x02,0x07};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
case 2 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x91,0xA9,0x8F,0x09,0x10,0x01,0x00,0x02,0x08};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
case 3 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xD1,0xB6,0x92,0x09,0x12,0x01,0x00,0x02,0x09};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
case 4 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xB1,0x27,0x05,0x0A,0x14,0x01,0x00,0x02,0x0A};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
case 5 : {
BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x51,0xAE,0x06,0x0A,0x15,0x01,0x00,0x02,0x0B};
Komut1[12]=FindItem(0);
KomutYolla(Komut1,sizeof(Komut1));
}break;
default:
	;
}
}break;
case 14:{ //1stjob
BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
KomutYolla(Komut1,sizeof(Komut1));
KomutYolla(Komut2,sizeof(Komut2));
KomutYolla(Komut3,sizeof(Komut3));
}break;

case 15:{ //inn
BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
KomutYolla(Komut1,sizeof(Komut1));
KomutYolla(Komut2,sizeof(Komut2));
KomutYolla(Komut3,sizeof(Komut3));
}break;
case 16:{ //chaos al
BYTE Komut1[]={0x20,0x01,0x86,0x2f,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut2[]={0x55,0x01,0x0F,0x33,0x31,0x35,0x32,0x36,0x5F,0x43,0x68,0x61,0x6F,0x73,0x2E,0x6C,0x75,0x61,};
BYTE Komut3[]={0x55,0x00,0x0F,0x33,0x31,0x35,0x32,0x36,0x5F,0x43,0x68,0x61,0x6F,0x73,0x2E,0x6C,0x75,0x61,};
KomutYolla(Komut1,sizeof(Komut1));
KomutYolla(Komut2,sizeof(Komut2));
KomutYolla(Komut3,sizeof(Komut3));
KomutYolla(Komut3,sizeof(Komut3));
CharacterMove(955,502,0);
}break;
default:
	;
}
  }


Move(){


if ((Ko_Threadsyn->Socket_Bilgi1->AdresX==0)||(Ko_Threadsyn->Socket_Bilgi1->AdresY==0)) {
return 0;	
}
float fx=Ko_Threadsyn->Socket_Bilgi1->AdresX-Ko_Threadsyn->Socket_Bilgi1->X;
float fy=Ko_Threadsyn->Socket_Bilgi1->AdresY-Ko_Threadsyn->Socket_Bilgi1->Y;
float distance = hypot(fx,fy);
if ((distance>500)&&(!NoJail)) {
return 0;    
}
float myNewX,myNewY;
if (distance>(Speed+4)) {
myNewX=(Speed/distance)*fx;
myNewY=(Speed/distance)*fy;
WORD NewX=Ko_Threadsyn->Socket_Bilgi1->X+myNewX  ;
WORD NewY=Ko_Threadsyn->Socket_Bilgi1->Y+myNewY;
HareketEt(NewX,NewY);
Sleep(300); //700
}else if (distance<2){
Ko_Threadsyn->Socket_Bilgi1->Go=false;
Arrive();

}else{
WORD NewX=Ko_Threadsyn->Socket_Bilgi1->AdresX;
WORD NewY=Ko_Threadsyn->Socket_Bilgi1->AdresY;
HareketEt(NewX,NewY);
Sleep(700);
}
}



SkillKullan(WORD TargetId){

Again:
int i=-1;
for (int s = 0; s < 10; s++) {
if (Skill[s].Active) {
if (((GetTickCount()-Skill[s].LastUse)>Skill[s].Timer)) {
if (i!=-1) {
if (Skill[s].Timer>Skill[i].Timer) {
i=s;
}
}else{
i=s;
}
}
}
}
if (i==-1) {
return 0 ;    
}


if (*(WORD*)&Skill[i].Sk[0][8]	!=	0) {
if (*(WORD*)&Skill[i].Sk[0][6]==*(WORD*)&Skill[i].Sk[0][8]){
*(WORD*)&Skill[i].Sk[0][8]	=	Id;
}else if (*(WORD*)&Skill[i].Sk[0][8]==0xffff){

}else{
*(WORD*)&Skill[i].Sk[0][8]	=TargetId;
}
}
if (*(WORD*)&Skill[i].Sk[0][6]	!=	0){*(WORD*)&Skill[i].Sk[0][6]	=	Id;}
if (*(WORD*)&Skill[i].Sk[0][10]	!=	0) {*(WORD*)&Skill[i].Sk[0][10]	=	TargetX;}
if (*(WORD*)&Skill[i].Sk[0][12]	!=	0) {*(WORD*)&Skill[i].Sk[0][12]	=	0;}
if (*(WORD*)&Skill[i].Sk[0][14]	!=	0) {*(WORD*)&Skill[i].Sk[0][14]	=	TargetY;}


if (*(WORD*)&Skill[i].Sk[1][8]	!=	0) {
if (*(WORD*)&Skill[i].Sk[1][6]==*(WORD*)&Skill[i].Sk[1][8]){
*(WORD*)&Skill[i].Sk[1][8]	=	Id;
}else if (*(WORD*)&Skill[i].Sk[1][8]==0xffff){

}else{
*(WORD*)&Skill[i].Sk[1][8]	=	TargetId;
}}
if (*(WORD*)&Skill[i].Sk[1][6]	!=	0) {*(WORD*)&Skill[i].Sk[1][6]	=	Id;}
if (*(WORD*)&Skill[i].Sk[1][10]	!=	0) {*(WORD*)&Skill[i].Sk[1][10]	=	TargetX;}
if (*(WORD*)&Skill[i].Sk[1][12]	!=	0) {*(WORD*)&Skill[i].Sk[1][12]	=	0;}
if (*(WORD*)&Skill[i].Sk[1][14]	!=	0) {*(WORD*)&Skill[i].Sk[1][14]	=	TargetY;}


if (*(WORD*)&Skill[i].Sk[2][8]	!=	0) {
if (*(WORD*)&Skill[i].Sk[2][6]==*(WORD*)&Skill[i].Sk[2][8]){
*(WORD*)&Skill[i].Sk[2][8]	=	Id;
}else if (*(WORD*)&Skill[i].Sk[2][8]==0xffff){

}else{
*(WORD*)&Skill[i].Sk[2][8]	=	TargetId;
}}
if (*(WORD*)&Skill[i].Sk[2][6]	!=	0) {*(WORD*)&Skill[i].Sk[2][6]	=	Id;}
if (*(WORD*)&Skill[i].Sk[2][10]	!=	0) {*(WORD*)&Skill[i].Sk[2][10]	=	TargetX;}
if (*(WORD*)&Skill[i].Sk[2][12]	!=	0) {*(WORD*)&Skill[i].Sk[2][12]	=	0;}
if (*(WORD*)&Skill[i].Sk[2][14]	!=	0) {*(WORD*)&Skill[i].Sk[2][14]	=	TargetY;}


if (*(WORD*)&Skill[i].Sk[3][8]	!=	0) {
if (*(WORD*)&Skill[i].Sk[3][6]==*(WORD*)&Skill[i].Sk[3][8]){
*(WORD*)&Skill[i].Sk[3][8]	=	Id;
}else if (*(WORD*)&Skill[i].Sk[3][8]==0xffff){

}else{
*(WORD*)&Skill[i].Sk[3][8]	=	TargetId;
}}
if (*(WORD*)&Skill[i].Sk[3][6]	!=	0) {*(WORD*)&Skill[i].Sk[3][6]	=	Id;}
if (*(WORD*)&Skill[i].Sk[3][10]	!=	0) {*(WORD*)&Skill[i].Sk[3][10]	=	TargetX;}
if (*(WORD*)&Skill[i].Sk[3][12]	!=	0) {*(WORD*)&Skill[i].Sk[3][12]	=	0;}
if (*(WORD*)&Skill[i].Sk[3][14]	!=	0) {*(WORD*)&Skill[i].Sk[3][14]	=	TargetY;}
if (Skill[i].SkSize[0]	!=	0){KomutYolla(Skill[i].Sk[0],Skill[i].SkSize[0]);}
if (Skill[i].SkSize[1]	!=	0){KomutYolla(Skill[i].Sk[1],Skill[i].SkSize[1]);}
if (Skill[i].SkSize[2]	!=	0){KomutYolla(Skill[i].Sk[2],Skill[i].SkSize[2]);}
if (Skill[i].SkSize[3]	!=	0){KomutYolla(Skill[i].Sk[3],Skill[i].SkSize[3]);}
if (CharTipi==0) {
if (intsub(*(DWORD*)&Skill[i].Sk[1][2],3,3)==515) {
if (Skill[i].SkSize[2]	!=	0){KomutYolla(Skill[i].Sk[2],Skill[i].SkSize[2]);}
if (Skill[i].SkSize[3]	!=	0){KomutYolla(Skill[i].Sk[3],Skill[i].SkSize[3]);}
if (Skill[i].SkSize[2]	!=	0){KomutYolla(Skill[i].Sk[2],Skill[i].SkSize[2]);}
if (Skill[i].SkSize[3]	!=	0){KomutYolla(Skill[i].Sk[3],Skill[i].SkSize[3]);}
if (Skill[i].SkSize[2]	!=	0){KomutYolla(Skill[i].Sk[2],Skill[i].SkSize[2]);}
if (Skill[i].SkSize[3]	!=	0){KomutYolla(Skill[i].Sk[3],Skill[i].SkSize[3]);}
}
}
Skill[i].LastUse=GetTickCount();
GeneralCooldown=GetTickCount();

goto Again;

}
ItemRepair(){
for (int i = 0; i < 15; i++) {
if (Ko_Threadsyn->Socket_Bilgi1->Gear_Table[i].Id!=0) {
BYTE Komut0[]={0x3B,0x01,0x06,0xDB,0x3A,0xE0,0xAE,0x31,0x17};
*(WORD*)&Komut0[3]=Zone.Sundress.Id;
Komut0[2]=i;
*(DWORD*)&Komut0[5]=Ko_Threadsyn->Socket_Bilgi1->Gear_Table[i].Id;
KomutYolla(Komut0,sizeof(Komut0)) ;
}

}

 return 1 ;
}

SellItems(BYTE Shop){
//Shop 0 Sund
//Shop 1 Potion
DWORD ShopId[2]={255000,253000};
WORD NpcId[2]={Zone.Sundress.Id,Zone.Potion.Id};
for (int j = 0; j < 28; j++) {
Form1->log->Items->Add(0) ;
if ((Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id!=0)) {
BYTE Komut1[]={0x21,0x02,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x38,0xD0,0x30,0x17,0x04,0x03,0x00};
for (int ii = 0; ii < 4; ii++) {
if ((TradeListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)==1)||(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==HpPot[ii].PotId)||(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==MpPot[ii].PotId)) {
Form1->log->Items->Add(1) ;
goto son ;
}
}



*(DWORD*)&Komut1[2]=ShopId[Shop];
*(WORD*)&Komut1[6]=NpcId[Shop];
*(DWORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
*(WORD*)&Komut1[13]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Adet ;
Komut1[12]=j ;
KomutYolla(Komut1,sizeof(Komut1)) ;

Form1->log->Items->Add(BufferToHex(Komut1,sizeof(Komut1)));
//0x21,0x01,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x38,0x78,0x98,0x16,0x05,0x02,0x00,0x01,0x02,trans gem

}

son:
}
if (CharTipi==0) {


if (Shop==0) {
InventoryRefresh();
int yer = -1 ;
if (FindItem(0x174e56d0)==-1) {
yer=FindItem(0);
}else{
yer=FindItem(0x174e56d0);
}//
BYTE Komut12[]={0x21,0x01,0x18,0xE4,0x03,0x00,0xDB,0x3A,0xD0,0x56,0x4E,0x17,0x02,0x64,0x00,0x00,0x00};
*(WORD*)&Komut12[6]=Zone.Sundress.Id;
Komut12[12]=yer;
*(WORD*)&Komut12[13]=4000;
KomutYolla(Komut12,sizeof(Komut12)) ;
*(WORD*)&Komut12[13]=2000;
KomutYolla(Komut12,sizeof(Komut12)) ;
*(WORD*)&Komut12[13]=1000;
KomutYolla(Komut12,sizeof(Komut12)) ;
//
//
if (FindItem(0x160dd020)==-1) {
yer=FindItem(0);
}else{
yer=FindItem(0x160dd020);
}
BYTE Komut13[]={0x21,0x01,0x18,0xE4,0x03,0x00,0xDB,0x3A,0x20,0xD0,0x0D,0x16,0x04,0x32,0x00,0x00,0x07,};
*(WORD*)&Komut13[6]=Zone.Sundress.Id;
Komut13[12]=yer;
*(WORD*)&Komut13[13]=100;
KomutYolla(Komut13,sizeof(Komut13)) ;

}

}

 return 1 ;
}
PotBuy(){
InventoryRefresh();
if (FindItem(HpPot[HpPotIndex].PotId)!=-1) {
if (GetItemCount(FindItem(HpPot[HpPotIndex].PotId))<HpAl) {
HpAl = HpAl - GetItemCount(FindItem(HpPot[HpPotIndex].PotId));
BYTE Komut1[]={0x21,0x01,0x48,0xDC,0x03,0x00,0xEB,0x3A,0x50,0xD2,0x2F,0x17,0x10,0x01,0x00,0x00,0x00};
*(WORD*)&Komut1[6]=Zone.Potion.Id;
*(DWORD*)&Komut1[8]=HpPot[HpPotIndex].PotId;
Komut1[12]=FindItem(HpPot[HpPotIndex].PotId);
*(WORD*)&Komut1[13]=HpAl;
Komut1[16]=HpPot[HpPotIndex].PotcuYer;
KomutYolla(Komut1,sizeof(Komut1)) ;
}
}else{
BYTE Komut1[]={0x21,0x01,0x48,0xDC,0x03,0x00,0xEB,0x3A,0x50,0xD2,0x2F,0x17,0x10,0x01,0x00,0x00,0x00};
*(WORD*)&Komut1[6]=Zone.Potion.Id;
*(DWORD*)&Komut1[8]=HpPot[HpPotIndex].PotId;
Komut1[12]=FindItem(0);
*(WORD*)&Komut1[13]=HpAl;
Komut1[16]=HpPot[HpPotIndex].PotcuYer;
KomutYolla(Komut1,sizeof(Komut1)) ;
}
InventoryRefresh();

if (FindItem(MpPot[MpPotIndex].PotId)!=-1) {
if (GetItemCount(FindItem(MpPot[MpPotIndex].PotId))<MpAl) {
MpAl = MpAl - GetItemCount(FindItem(MpPot[MpPotIndex].PotId));
BYTE Komut1[]={0x21,0x01,0x48,0xDC,0x03,0x00,0xEB,0x3A,0x50,0xD2,0x2F,0x17,0x10,0x01,0x00,0x00,0x00};
*(WORD*)&Komut1[6]=Zone.Potion.Id;
*(DWORD*)&Komut1[8]=MpPot[MpPotIndex].PotId;
Komut1[12]=FindItem(MpPot[MpPotIndex].PotId);
*(WORD*)&Komut1[13]=MpAl;
Komut1[16]=MpPot[MpPotIndex].PotcuYer;
KomutYolla(Komut1,sizeof(Komut1)) ;
}
}else{
BYTE Komut1[]={0x21,0x01,0x48,0xDC,0x03,0x00,0xEB,0x3A,0x50,0xD2,0x2F,0x17,0x10,0x01,0x00,0x00,0x00};
*(WORD*)&Komut1[6]=Zone.Potion.Id;
*(DWORD*)&Komut1[8]=MpPot[MpPotIndex].PotId;
Komut1[12]=FindItem(0);
*(WORD*)&Komut1[13]=MpAl;
Komut1[16]=MpPot[MpPotIndex].PotcuYer;
KomutYolla(Komut1,sizeof(Komut1)) ;
//Form1->log->Items->Add(BufferToHex(Komut1,sizeof(Komut1)));
}
InventoryRefresh();
 return 1 ;
}





public:
bool IlkLogin;
bool AutoLogin;
bool AutoPotion;
bool AutoRepair;
bool AutoLoot;
bool AutoMine;
bool AutoPressOk;
bool AutoHeal;
bool AutoBuff;
bool ProxyEnable;
bool RunToMob;
bool Dolas;
NpcVecList NpcVec;
NpcVecList PlayerVec;
 WORD CenterX,CenterY;
  WORD TargetX;
 WORD TargetY;
 DWORD KutuNumarasi;

 DWORD LastHpUseTime,LastMpUseTime;
 int LastSkillUseTime;
int timer22;

SkillYapi   Skill[10];
WORD 		Id;
DWORD		GeneralCooldown;
bool		CharHuman;
bool		CharMaster;
WORD 		CharTipi;
INT64 		CurrExp;
INT64 		NeedExp;
BYTE		Str;
BYTE		StrP;
BYTE		Hp;
BYTE		HpP;
BYTE		Dex;
BYTE		DexP;
BYTE		Mp;
BYTE		MpP;
BYTE		Int;
BYTE		IntP;
WORD		AP;
WORD		DEF;
WORD		Point;
BYTE 		Skill0;
BYTE 		Skill1;
BYTE 		Skill2;
BYTE 		Skill3;
WORD		SkillPoint;
DWORD		DeathTime;
bool		Dead;
bool		PartiBaskan;
bool 		ItemVerilecek;
WORD		DonulecekX;
WORD		DonulecekY;
WORD		FollowId;
bool		InventoryRefreshState;
DWORD		InventoryRefreshTime;
bool		HealSkills[5];
bool		BuffSkills[16];
DWORD		LastPriTime;
DWORD 		Buff;
ZoneYapi	Zone;
bool		AutoAtack;
bool		AutoSell;
DWORD       SpeCode;
bool 		TownState;
bool 		RAtack;
DWORD		LastRUseTime;
bool		Loaded;
bool		AutoBuy;
bool		AutoParty;
BYTE		ZoneId;
WORD		Distance;
WORD		MineX;
WORD		MineY;
String		ZoneName;
DWORD		LastItemGainTime;
int			PaperItem;
int			PaperClass;
int			PaperArmor;
bool		Updurum  ;
bool		Upgrade;
DWORD		SellItemList[255];
DWORD		TradeItemList[255];
DWORD		CrashItemList[255];
BYTE 		Speed;
WORD		SupportId;
BYTE		AtackType;
bool		trademode;
bool		NoJail;
BYTE		BuyBowIndex;
bool		Chat ;
String 		ChatSay;
DWORD		LastChatTime;
BYTE		ChatType;
DWORD		ChatTimer;

DWORD		LastFollowTime;
pot HpPot[4];
pot MpPot[4];
WORD HpAl;
WORD MpAl;

BYTE HpPotIndex;
BYTE MpPotIndex;
BYTE  chaosgir;

WORD ChaosX;
WORD ChaosY;

};
#endif
