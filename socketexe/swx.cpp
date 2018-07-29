#include "swx.h"
#include <iostream>
#include <fstream>
#include <ostream>


swxClientClass::swxClientClass()
{
	memset(&Skill,0,sizeof(Skill));
	SundId		= 29663;                                                                                
	PitmanId	= 11494;
	MaxNpcId    = 0;
	MinNpcId	= 0xFFFF;
	memset(&NPCS,0,sizeof(NPCS));
	moveSpeed	= 6;
	moveSleep	= 75;
	MadenAktif  = false;
	memset(&baskanNick,0,20);
	strcpy(baskanNick ,"1");

	lItemList[0]	=	ITEM_HP45;			bStackable[0] = true;
	lItemList[1]	=	ITEM_HP90;			bStackable[1] = true;
	lItemList[2]	=	ITEM_HP180;         bStackable[2] = true;
	lItemList[3]	=	ITEM_HP360;         bStackable[3] = true;
	lItemList[4]	=	ITEM_HP720;         bStackable[4] = true;
	lItemList[5]	=	ITEM_MP120;         bStackable[5] = true;
	lItemList[6]	=	ITEM_MP240;         bStackable[6] = true;
	lItemList[7]	=	ITEM_MP480;         bStackable[7] = true;
	lItemList[8]	=	ITEM_MP960;         bStackable[8] = true;
	lItemList[9]	=	ITEM_MP1920;        bStackable[9] = true;
	lItemList[10]	=	ITEM_ROCK;          bStackable[10] = true;
	lItemList[11]	=	ITEM_ACID;          bStackable[11] = true;
	lItemList[12]	=	ITEM_BEZOAR;        bStackable[12] = true;
	lItemList[13]	=	ITEM_GLUTINOUS;     bStackable[13] = true;
	lItemList[14]	=	ITEM_FIRECRACKER;   bStackable[14] = true;
	lItemList[15]	=	ITEM_FLOWERFC;      bStackable[15] = true;
	lItemList[16]	=	ITEM_UP_LOWCLASS;   bStackable[16] = true;
	lItemList[17]	=	ITEM_CRYSTAL;       bStackable[17] = true;
	lItemList[18]	=	ITEM_OPAL;          bStackable[18] = true;
	lItemList[19]	=	ITEM_SAPPHIRE;      bStackable[19] = true;
	lItemList[20]	=	ITEM_CALLINGSC;     bStackable[20] = true;
	lItemList[21]	=	ITEM_TS_SCROLL;     bStackable[21] = true;
	lItemList[22]	=	ITEM_BUS;           bStackable[22] = true;
	lItemList[23]	=	ITEM_UP_SC;         bStackable[23] = true;
	lItemList[24]	=	ITEM_ABYSS;         bStackable[24] = true;
	lItemList[25]	=	ITEM_MP_RICE;       bStackable[25] = false;
	lItemList[26]	=	ITEM_MS;            bStackable[26] = false;
	lItemList[27]	=	ITEM_BLUE_CHEST;    bStackable[27] = true;
	lItemList[28]	=	ITEM_GREEN_CHEST;   bStackable[28] = true;
	lItemList[29]	=	ITEM_RED_CHEST;     bStackable[29] = true;
	lItemList[30]	=	ITEM_BRONZE_COIN;   bStackable[30] = false;
	lItemList[31]	=	ITEM_SILVER_COIN;  	bStackable[31] = false;
	lItemList[32]	=	ITEM_GOLD_COIN;   	bStackable[32] = false;

	strItemList[0] = "HP Pot(45)";
	strItemList[1] = "HP Pot(90)";
	strItemList[2] = "HP Pot(180)";
	strItemList[3] = "HP Pot(360)";
	strItemList[4] = "HP Pot(720)";
	strItemList[5] = "MP Pot(120)";
	strItemList[6] = "MP Pot(240)";
	strItemList[7] = "MP Pot(480)";
	strItemList[8] = "MP Pot(960)";
	strItemList[9] = "MP Pot(1920)";
	strItemList[10] = "Sling";
	strItemList[11] = "Acid potion";
	strItemList[12] = "Bezoar";
	strItemList[13] = "Glutinous";
	strItemList[14] = "Firecracker";
	strItemList[15] = "Flower Firecracker";
	strItemList[16] = "Low scroll";
	strItemList[17] = "Crystal";
	strItemList[18] = "Opal";
	strItemList[19] = "Sapphire";
	strItemList[20] = "Calling Friend Sc";
	strItemList[21] = "Transformation Scroll";
	strItemList[22] = "BUS";
	strItemList[23] = "Upgrade Scroll";
	strItemList[24] = "Abyss Gem";
	strItemList[25] = "MP Rice Cake";
	strItemList[26] = "Monster Stone";
	strItemList[27] = "Mavi kutu";
	strItemList[28] = "Yesil kutu";
	strItemList[29] = "Kirmizi kutu";
	strItemList[30] = "Bronze coin";
	strItemList[31] = "Silver coin";
	strItemList[32] = "Gold coin";

	lFragmentList[0] = ITEM_FRAGMENT1;
	lFragmentList[1] = ITEM_FRAGMENT2;
	lFragmentList[2] = ITEM_FRAGMENT3;
	lFragmentList[3] = ITEM_FRAGMENT4;
	lFragmentList[4] = ITEM_FRAGMENT5;
	lFragmentList[5] = ITEM_FRAGMENT6;
	lFragmentList[6] = ITEM_FRAGMENT7;

	strFragmentList[0] = "F.Arrogance";
	strFragmentList[1] = "F.Avarice";
	strFragmentList[2] = "F.Gluttony";
	strFragmentList[3] = "F.Jealousy";
	strFragmentList[4] = "F.Lechery";
	strFragmentList[5] = "F.Rage";
	strFragmentList[6] = "F.Sloth";


	iItemActionList[0]	=	ACT_REMOVE;
	iItemActionList[1]	=	ACT_REMOVE;
	iItemActionList[2]	=	ACT_REMOVE;
	iItemActionList[3]	=	ACT_REMOVE;
	iItemActionList[4]	=	ACT_REMOVE;
	iItemActionList[5]	=	ACT_REMOVE;      
	iItemActionList[6]	=	ACT_REMOVE;      
	iItemActionList[7]	=	ACT_REMOVE;      
	iItemActionList[8]	=	ACT_REMOVE;
	iItemActionList[9]	=	ACT_REMOVE;
	iItemActionList[10]	=	ACT_REMOVE;        
	iItemActionList[11]	=	ACT_SELL;
	iItemActionList[12]	=	ACT_REMOVE;
	iItemActionList[13]	=	ACT_REMOVE;   
	iItemActionList[14]	=	ACT_REMOVE; 
	iItemActionList[15]	=	ACT_REMOVE;
	iItemActionList[16]	=	ACT_SELL; 
	iItemActionList[17]	=	ACT_SELL;
	iItemActionList[18]	=	ACT_SELL;
	iItemActionList[19]	=	ACT_SELL;
	iItemActionList[20]	=	ACT_REMOVE;   
	iItemActionList[21]	=	ACT_SELL;
	iItemActionList[22]	=	ACT_NOP;
	iItemActionList[23]	=	ACT_SELL;       
	iItemActionList[24]	=	ACT_SELL;
	iItemActionList[25]	=	ACT_REMOVE;
	iItemActionList[26]	=	ACT_REMOVE;
	iItemActionList[27]	=	ACT_NOP;
	iItemActionList[28]	=	ACT_NOP;
	iItemActionList[29]	=	ACT_NOP;   
	iItemActionList[30]	=	ACT_SELL;  
	iItemActionList[31]	=	ACT_SELL;  
	iItemActionList[32]	=	ACT_SELL;

	HpPot[0].PotMiktar=90;HpPot[1].PotMiktar=180;HpPot[2].PotMiktar=360;HpPot[3].PotMiktar=720;
	HpPot[0].PotId=389011000;HpPot[1].PotId=389012000;HpPot[2].PotId=389013000;HpPot[3].PotId=389014000;
	HpPot[0].PotSkill=490011;HpPot[1].PotSkill=490012;HpPot[2].PotSkill=490013;HpPot[3].PotSkill=490014;
	HpPot[0].PotcuYer=1;HpPot[1].PotcuYer=2;HpPot[2].PotcuYer=3;HpPot[3].PotcuYer=4;
	MpPot[0].PotMiktar=180;MpPot[1].PotMiktar=480;MpPot[2].PotMiktar=960;MpPot[3].PotMiktar=1920;
	MpPot[0].PotId=389017000;MpPot[1].PotId=389018000;MpPot[2].PotId=389019000;MpPot[3].PotId=389020000;
	MpPot[0].PotSkill=490017;MpPot[1].PotSkill=490018;MpPot[2].PotSkill=490019;MpPot[3].PotSkill=490020;
	MpPot[0].PotcuYer=7;MpPot[1].PotcuYer=8;MpPot[2].PotcuYer=9;MpPot[3].PotcuYer=10;

}

swxClientClass::SetClass(KnightOnline_CLASS_Interface * cc){
myclass = cc;
return true;
}
bool swxClientClass::TradeKoy(BYTE slot,WORD count)
{
	if (Item_Table[slot].Id==0)
		return false;
	BYTE VerKomut[]={0x30,0x03,0x00,0xE0,0xA8,0x32,0x17,0x01,0x00,0x00,0x00};
	VerKomut[2]=slot;
	*(DWORD*)&VerKomut[3]=Item_Table[slot].Id;
	if (count == 0 ) count = Item_Table[slot].Count ;
	*(WORD*)&VerKomut[7]=count;
	pSend(VerKomut,sizeof(VerKomut));
}
bool swxClientClass::TradeAccept()
{
	BYTE Komut[]={0x30,0x02,0x01};
	pSend(Komut,sizeof(Komut));
}
bool swxClientClass::TradeConfirm()
{
	BYTE Komut[]={0x30,0x05};
	pSend(Komut,sizeof(Komut));
}
bool swxClientClass::TradeCancel()
{
	BYTE Komut[]={0x30,0x02,0x00};
	pSend(Komut,sizeof(Komut));
}
swxClientClass::UpdatePos(WORD Xx,WORD Yy){
printf("update pos x : %d y : %d -> x : %d y : %d \n",X,Y ,Xx,Yy);
X = Xx;
Y = Yy;

return true;
}
WORD swxClientClass::Vur(WORD targetid)
{
return true;
}
WORD swxClientClass::FindNearNpc(WORD Xx,WORD Yy,float *dist,int lvllimit)
{
	float neardist	= 2000;
	WORD nearid		= 0;
	for (int i = MinNpcId ; i <= MaxNpcId; i++)
	{
		if (NPCS[i].Id!=0)
		{

		if (NPCS[i].Level<=lvllimit)
		{
			float distbuf	= sqrt(pow((NPCS[i].X - Xx) ,2) +  pow((NPCS[i].Y - Yy),2));
			if (distbuf<neardist||nearid==0)
			{
				neardist	= distbuf;
				nearid		= i;
			}
			if (distbuf>100)
			{
				memset(&NPCS[i],0,sizeof(NPCS[i]));
			}
			}
		}
	}
	*dist	= neardist;
	return	nearid;
}
bool swxClientClass::GoZone(BYTE id)
{
	GoTown();
	if (Zone == id)
		return true;

	ZoneState = false;
	switch (id)
	{
		case 0x15:
		{
			if (Zone == 2)
			{
				Move(1588,415);
				BYTE Komut[]={0x4B,0xA3,0x0F,0xD3,0x00};
				pSend(Komut,sizeof(Komut));
			}
			else if (Zone == 1)
			{
				Move(447,1617);
				BYTE Komut[]={0x4B,0xA6,0x0F,0x6F,0x00};
				pSend(Komut,sizeof(Komut));
			}
			else
				return false;
		}break;
		case 1:
		{
			if (Zone != 0x15)
				return false;
			Move(797,526);
			BYTE Komut[]={0x4B,0xAE,0x0F,0x41,0x08};
			pSend(Komut,sizeof(Komut));
		}break;
		case 2:
		{
			if (Zone != 0x15)
				return false;
			Move(837,527);
			BYTE Komut[]={0x4B,0xAD,0x0F,0x4B,0x08};
			pSend(Komut,sizeof(Komut));
		}break;
	default:
		;
	}
	Sleep(1000);
	while(!ZoneState)
	{
	Sleep(250);
	}
		Sleep(3000);
	GoTown();
	return true;
}
bool swxClientClass::GotoNpc(WORD id)
{
	if (NPCS[id].X ==0 ||NPCS[id].Y ==0)
	{
		return false;
	}
		Move(NPCS[id].X,NPCS[id].Y);
		Move(NPCS[id].X,NPCS[id].Y);
		return true;
}

bool swxClientClass::Move(WORD Xx,WORD Yy)
{
	bool geldik=false;
	bool hatavar = false;
	tekrar:
	goX = Xx; goY = Yy;
	if ((goX==0)||(goY==0))
	{
        return false;
		hatavar	= true;
		geldik 	= true;
	}
	float fx=goX-X;
	float fy=goY-Y;

	float distance = hypot(fx,fy);
	if ((distance>350)&&(MadenAktif))
	{
        TerminateProcess(GetCurrentProcess(),0);
		geldik 	= false;
		hatavar = true;
	}
	float myNewX,myNewY;
	if (distance>(moveSpeed))
	{
		myNewX=(moveSpeed/distance)*fx;
		myNewY=(moveSpeed/distance)*fy;
		WORD NewX=X+myNewX  ;
		WORD NewY=Y+myNewY;
		HareketEt(NewX,NewY);
		geldik 	= false;
		hatavar = false;
	}
	else if (distance<1)
	{
		geldik 	= true;
		hatavar = false;
	}
	else if (distance<moveSpeed)
	{
		geldik 	= true;
		hatavar = false;
		Sleep(500);
		//Arrive();
		WORD NewX=goX;
		WORD NewY=goY;
		HareketEt(NewX,NewY);
	}

	else
	{
		WORD NewX=goX;
		WORD NewY=goY;
		HareketEt(NewX,NewY);
		geldik 	= false;
		hatavar = false;
	}
	Sleep(moveSleep);
	if ((!geldik)&&(!hatavar))
	{
		goto tekrar;
	}
	//HareketEt(goX,goY);
	return true;
}

bool swxClientClass::HareketEt(float Xx,float Yy)
{
	BYTE movePacket[]={0x6, 0xED, 0xD, 0xFA, 0x43, 0x90, 0x0, 0x2D, 0x0, 0x3, 0xED, 0xD, 0xFA, 0x43, 0x90, 0x0};
	Xx=Xx*10;
	Yy=Yy*10;
	*(WORD*)&movePacket[1]=X*10;
	*(WORD*)&movePacket[3]=Y*10;
	*(WORD*)&movePacket[5]=0;
	*(BYTE*)&movePacket[6]=3;
	*(BYTE*)&movePacket[7]=0x2d;
	*(WORD*)&movePacket[10]=Xx;
	*(WORD*)&movePacket[12]=Yy;
	*(WORD*)&movePacket[14]=0;
	pSend(movePacket,16);
	MoveState = 0;
	//while (MoveState==0){
	//Sleep(100);
	//}
	//if (MoveState==1) {
	UpdatePos(Xx/10,Yy/10);
	//}


	return 1;
}
int swxClientClass::MadenKomut(BYTE state)
{
if (state==1)
{
	for (int i = 0; i < 10; i++)
	{
		BYTE Komut[] = {0x31,0x03,0xA2,0x7A,0x07,0x00,0x0C,0x0A,0x0C,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
		*(WORD*)&Komut[6]=CharID ;
		*(WORD*)&Komut[8]=CharID ;
		pSend(Komut,sizeof(Komut));
        Sleep(100);
	}
}
	char pMaden[2];
	pMaden[0]	= 0x86;
	pMaden[1]	= state;
	pSend(pMaden,2);
	return true;
}
#define ITEM_NORMAL_ORE	399210000
#define ITEM_GOLD_ORE	399200000
bool swxClientClass::RepairItem(BYTE slot)
{
	BYTE Komut0[]={0x3B,0x01,0x06,0xDB,0x3A,0xE0,0xAE,0x31,0x17};
	*(WORD*)&Komut0[3]=SundId;
	Komut0[2]=slot;
	*(DWORD*)&Komut0[5]=Gear_Table[slot].Id;
	pSend(Komut0,sizeof(Komut0)) ;

	return true;
}

bool swxClientClass::RepairAll()
{
	Sleep(1000);
	for (int i = 0; i < 14; i++)
	{
		if (i==0||i==2||i==3||i==5||i==7||i==9||i==11)continue;
		if (Gear_Table[i].Id!=0)
		{
			RepairItem(i);
		}
	}
	return true;
}
bool swxClientClass::SellItem(BYTE indx)
{
				if(	Item_Table[indx].Id==ITEM_BLUE_CHEST||
					Item_Table[indx].Id==ITEM_GREEN_CHEST||
					Item_Table[indx].Id==ITEM_RED_CHEST||
					Item_Table[indx].Id==ITEM_FRAGMENT1||
					Item_Table[indx].Id==ITEM_FRAGMENT2||
					Item_Table[indx].Id==ITEM_FRAGMENT3||
					Item_Table[indx].Id==ITEM_FRAGMENT4||
					Item_Table[indx].Id==ITEM_FRAGMENT5||
					Item_Table[indx].Id==ITEM_FRAGMENT6||
					Item_Table[indx].Id==ITEM_FRAGMENT7||
					Item_Table[indx].Id==ITEM_BUS
				)
				{
                    return false;
                }
	char ppSend[15]		= {0x21,0x02,0x00,0x00,0x00,0x00,0xff,0xff,0x11,0x11,0x11,0x11,0xff,0x12,0x34};
	*(DWORD*)&ppSend[2]	= 255000;
	*(WORD*)&ppSend[6] 	= SundId;
	*(DWORD*)&ppSend[8] = Item_Table[indx].Id;
	*(BYTE*)&ppSend[12]	= indx;
	*(WORD*)&ppSend[13] = Item_Table[indx].Count;
	pSend(ppSend,15);
	Item_Table[indx].Id=0;
	Item_Table[indx].Count=0;
	return true;
}
bool swxClientClass::SellItemsFromList()
{
	for (int i = 0; i < 33; i++)
	{
		if( iItemActionList[i] == ACT_SELL )
		{
			while (FindItemCount(lItemList[i])>0)
			{
				BYTE indx = FindItemIndex(lItemList[i]);
				SellItem(indx);
			}
		}
	}
//InventoryRefresh();
}
float swxClientClass::CalculateDistance(WORD xx,WORD yy)
{
	float a = sqrt(fabs(pow(xx-X,2) +  pow(yy-Y,2)));
	return a ; 
}
bool swxClientClass::OreKir()
{
Move(PitmanX,PitmanY);
 /*	if (Zone == 0x15)
	{
		GotoNpc(PitmanId);
	}
	Sleep(1000);         */



	char ppSend[8];
	*(WORD*)ppSend = 0x120;
	*(WORD*)(ppSend + 2) = PitmanId;
	*(DWORD*)(ppSend + 4) = 0xFFFFFFFF;
	BYTE pPacket_MineMain[6] = {0x64,0x07,0x54,0x4E,0x00,0x00};
	BYTE pPacket_MineOre1[19] = {0x55,0x00,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
	BYTE pPacket_MineOre2[19] = {0x55,0x01,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
	for (int i = 0; i < 28; i++)
	{
		if (Item_Table[i].Id==ITEM_NORMAL_ORE)
		{
        	pSend(ppSend,8);
			pSend(pPacket_MineMain,6);
			pSend(pPacket_MineOre1,19);
			Sleep(1000);
		}
		else if(Item_Table[i].Id==ITEM_GOLD_ORE)
		{
			pSend(ppSend,8);
			pSend(pPacket_MineMain,6);
			pSend(pPacket_MineOre2,19);
			Sleep(1000);
		}
		else if (Item_Table[i].Id==508226000)    //rainworm
		{
			CrashItem(i);
		}
		else if (Item_Table[i].Id==399128000)  //dc flash
		{
			if (Item_Table[i].Count>100)
			{
				CrashItem(i);
			}

		}

	}
	Sleep(1500);
	for (int i = 0; i < 33; i++)
	{

		if( iItemActionList[i] == ACT_REMOVE )
		{
			while (FindItemCount(lItemList[i])>0)
			{
				BYTE indx = FindItemIndex(lItemList[i]);
				if (indx!=255)
				{
					if(lItemList[i] == ITEM_MP_RICE)
					{
						int iRemain = 3;
						while(iRemain)
						{
                        	#define SKILL_MPRICE		501002
							BYTE pBuf_BuffSelf2[26] = {0x31,0x03,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
							BYTE pBuf_RemoveSelf[26] = {0x31,0x06,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
							*(DWORD*)(pBuf_RemoveSelf + 6)= CharID;
							*(DWORD*)(pBuf_RemoveSelf + 8)= CharID;
							*(DWORD*)(pBuf_BuffSelf2 + 6)= CharID;
							*(DWORD*)(pBuf_BuffSelf2 + 8)= CharID;
							*(DWORD*)(pBuf_RemoveSelf + 2) = SKILL_MPRICE;
							*(DWORD*)(pBuf_BuffSelf2 + 2) = SKILL_MPRICE;
							pSend(pBuf_RemoveSelf,24);
							pSend(pBuf_BuffSelf2,24);
							iRemain--;
							Sleep(100);
						}

					}
					CrashItem(indx);
				}
			}
		}
	}
//	InventoryRefresh();
	return true;
}
bool swxClientClass::TimerKontrol(DWORD* ttimer,DWORD ms)
{
	if ((GetTickCount()- *ttimer)>ms)
	{
		*ttimer = GetTickCount();
		return true;
	}
	return false;
}
bool swxClientClass::PotionIc(DWORD PotKod)
{
BYTE POT[]={0x31, 0x3,
0x0, 0x0, 0x0, 0x0,
0x0,
0x5, 0x0,
0x5, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
*(DWORD*)&POT[2]=PotKod;
*(WORD*)&POT[6]=CharID;
*(WORD*)&POT[8]=CharID;
pSend(POT,sizeof(POT));
 return 1;
}
int WINAPI swxClientClass::PotThread()
{
	while (1){

if (Hp<MaxHp) {
if (GetTickCount()-LastHpUseTime > 2000)   {
int fark =MaxHp-Hp;
for (int i = 0; i < 4; i++) {
if (FindItemCount(HpPot[i].PotId)>0) {
if (fark>HpPot[i].PotMiktar) {
PotionIc(HpPot[i].PotSkill);
LastHpUseTime=GetTickCount();
goto NNN;
}
}
}
}
}
NNN:
if (Mana<MaxMana) {
if (GetTickCount()-LastMpUseTime > 2000)   {
int fark =MaxMana-Mana;
for (int i = 0; i < 4; i++) {
if (FindItemCount(MpPot[i].PotId)>0) {
if (fark>MpPot[i].PotMiktar) {
PotionIc(MpPot[i].PotSkill);
LastMpUseTime=GetTickCount();
goto NNNN;
}
}
}
}
}
NNNN:
Sleep(500);
}
return true;
	while (1){
	int hpfark =  MaxHp-  Hp;
	int mpfark = MaxMana - Mana;
	/*if (mpfark>1920)
	{
		BYTE pBuf_BuffSelf2[26] = {0x31,0x03,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
		*(DWORD*)(pBuf_BuffSelf2 + 2)= 490020;
		*(DWORD*)(pBuf_BuffSelf2 + 6)= CharID;
		*(DWORD*)(pBuf_BuffSelf2 + 8)= CharID;
		pSend(pBuf_BuffSelf2,26);
		Sleep(1000);
	}*/
if (mpfark>300)
	{
BYTE POT[]={0x31, 0x3,
0x0, 0x0, 0x0, 0x0,
0x0,
0x5, 0x0,
0x5, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
*(DWORD*)&POT[2]=490017;
*(WORD*)&POT[6]=CharID;
*(WORD*)&POT[8]=CharID;
pSend(POT,26);
Sleep(1000);
}

	Sleep(100);
	}

}
int WINAPI swxClientClass::AtackThread()
{
	while (1){
	float dist;
	TargetId = FindNearNpc(X,Y,&dist,1000);

	if (TargetId !=0||TargetId!=-1)
	{
				BYTE Komut[]={0x22,0x00,0x00,0x00};
				*(WORD*)&Komut[1]=TargetId;
				pSend(Komut,sizeof(Komut));
					BYTE	Komut1[26] = {0x31,0x01,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,};
					BYTE	Komut2[22] = {0x31,0x02,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut3[26] = {0x31,0x03,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut4[26] = {0x31,0x04,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x55,0x02,0x06,0x00,0x87,0x01,0x9B,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					*(DWORD*)&Komut1[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut2[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut3[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut4[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(WORD*)&Komut1[6]=CharID;
					*(WORD*)&Komut2[6]=CharID;
					*(WORD*)&Komut3[6]=CharID;
					*(WORD*)&Komut4[6]=CharID;
					*(WORD*)&Komut1[8]=TargetId;
					*(WORD*)&Komut2[8]=TargetId;
					*(WORD*)&Komut3[8]=TargetId;
					*(WORD*)&Komut4[8]=TargetId;
					*(WORD*)&Komut4[10]=X;// *(WORD*)&GelenBuf[10];
					*(WORD*)&Komut4[12]=0;// *(WORD*)&GelenBuf[12];
					*(WORD*)&Komut4[14]=Y;// *(WORD*)&GelenBuf[14];
					pSend(Komut1,sizeof(Komut1));
					pSend(Komut2,sizeof(Komut2));
					pSend(Komut3,sizeof(Komut3));
					pSend(Komut4,sizeof(Komut4));
	}
	Sleep(1300);
	}
}
bool swxClientClass::GoRandom(WORD xxX,WORD yyY)
{
	DWORD b = GetTickCount()%10;
	int c = GetTickCount()%2;
	if (c==1) {
	 c=-1;
	}else{
		c=1;
	}
	int d = GetTickCount()%2;
	if (d==1) {
	 d=-1;
	}else{
		d=1;
	}
	DWORD a = GetTickCount()%10;
	Move(xxX+a*c,yyY+b*d);
}
int m_index = 0 ;
bool swxClientClass::SetMadenParams(bool degistir)
{
		if (degistir)
		{
			m_index =(m_index+1)%2;
		}

	if (Zone==0x15)
	{
	SundId	 = 12245;
	PitmanId = 22641;
	MadenX	= 641;
	MadenY	= 375;
	SundX	= 761;
	SundY	= 523;
	PitmanX = 663;
	PitmanY = 411;
	}else  if (Zone==0x1) {

	if (m_index==1) {
		m_index = 1;
		MadenX = 618 + GetTickCount()%30;
		MadenY = 1646 + GetTickCount()%30;
		PitmanX = 618;
		PitmanY = 1651;
		PitmanId = 11235;
	}else{
		MadenX = 365 + GetTickCount()%30;
		MadenY = 1468 + GetTickCount()%10;
		PitmanX = 417;
		PitmanY = 1473;
		PitmanId = 11238;
	}
	SundId=30093;
	SundX	= 450;
	SundY	= 1686;

	}else  if (Zone==0x2) {
	if (m_index==1) {
		MadenX = 1438 + GetTickCount()%30;
		MadenY = 323 + GetTickCount()%40;
		PitmanX = 1491;
		PitmanY = 429;
		PitmanId = 26339;
	}else{
		MadenX = 1699 + GetTickCount()%20;
		MadenY = 559 + GetTickCount()%30;
		PitmanX = 1649;
		PitmanY = 573;
		PitmanId = 26336;
	}
	SundId=22676;
	SundX	= 1619;
	SundY	= 365;

	}
}
bool swxClientClass::TownToMineZone()
{
	if (Zone==0x15) {
	Move(817,451);
	Move(776,433);
	Move(667,423);
	}else if (Zone==1)
	{
			Move(484,1607);
			Move(519,1570);

		if (m_index==1)
		{
			Move(621,1643);
		}
		else
		{
			Move(429,1477);
		}
	}else if (Zone==2)
	{
			Move(1580,444);
			Move(1543,482);

		if (m_index==1)
		{
			Move(1418,436);
		}
		else
		{
			Move(1618,576);
		}
    }
}
bool swxClientClass::isMineArea()
{
  /*	switch (Zone)
	{
		case 0x15:
		{
			if (CalculateDistance(MadenX,MadenY)<25)
			{
				return true;
			}
		}break

	default:
	;
	}   */
}
int WINAPI swxClientClass::LootThread()
{
	while (1)
	{
	if (lstChestList.size()>0)
	{

		_CHEST *pCurrentChest = lstChestList.front();

		if(pCurrentChest)
		{
			Move(pCurrentChest->m_fPosX,pCurrentChest->m_fPosY);
			BYTE k[5];
			k[0]= 0x24;
			*(DWORD*)&k[1]= pCurrentChest->m_lChestID;
			pSend(k,5);
			delete (_CHEST*)lstChestList.front();
			lstChestList.pop_back();
		}
	}
		Sleep(500);
	}
}
int WINAPI swxClientClass::LevelThread()
{
bool bow = false;
int a = Gear_Table[8].Id/10000000;
if (a==16)
{
	bow = true;
}
while(1)
{
	if (Level<23)
	{
		WearItem(0,6);
		WORD mX,mY;
		if (4>Level)
		{
			mX =636;
			mY = 421;
		}
		if (14>Level>3)
		{
			mX =618;
			mY = 461;
		}
		else if (Level>13)
		{
			mX =540;
			mY = 389;
		}
		else
		{

		}
		Move(mX,mY);
		BYTE LevelBuffer=Level;
		BYTE bowfind = 0  ;
		BYTE Kmt[] = {0x6a,0x02};
		pSend(Kmt,2);
        Sleep(1000);
			for (int i = 0; i < 28; i++)
			{
				int a = Item_Table[i].Id/10000000;
				if (a==16)
				{
				   /*	cClient.WearItem(i,8);
					printf ("%d :ID<%d>\n",cClient.Item_Table[i].Id,i);  */
                    bowfind = 1;
				}
			}
			int arrcount = FindItemCount(391010000);


		while(Level<23)
		{
		char  c[2];
		if ((Level>9)&&(Para > 4000)&&(CharClass==103))
		{
			Move(816,706);
			BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
			*(WORD*)&Komut1[2]= 12325;
			BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			pSend(Komut1,sizeof(Komut1));
			pSend(Komut2,sizeof(Komut2));
			pSend(Komut3,sizeof(Komut3));
			BYTE b = 0 ;
			pSend(&b,1);
			TerminateThread(Thread41Handle,0);
//			TerminateThread(upHandle,0);
			TerminateThread(MoveThreadHandle,0);
			TerminateThread(AtackThreadHandle,0);
			TerminateThread(LevelThreadHandle,0);
			TerminateThread(PotThreadHandle,0);
		}
		if (bowfind&&arrcount<100&&Para>2000&&!bow) {
		Move(759,521);
		BYTE Komut[] = {0x21,0x01,0x18,0xE4,0x03,0x00,0xD5,0x2F,0xD0,0x56,0x4E,0x17,0x1B,0xE8,0x03,0x00,0x00,};
		pSend(Komut,sizeof(Komut));
        for (int i = 0; i < 28; i++)
			{
				int a = Item_Table[i].Id/10000000;
				if (a==16)
				{
					WearItem(i,8);

				}
			}
			BYTE b = 0 ;
			pSend(&b,1);
			TerminateThread(Thread41Handle,0);
//			TerminateThread(upHandle,0);
			TerminateThread(MoveThreadHandle,0);
			TerminateThread(AtackThreadHandle,0);
			TerminateThread(LevelThreadHandle,0);
			TerminateThread(PotThreadHandle,0);
		}
		if (bow&&arrcount<100)
		{
        	Move(759,521);
			for (int indx = 0; indx < 28; indx++)
			{
				char ppSend[15]		= {0x21,0x02,0x00,0x00,0x00,0x00,0xff,0xff,0x11,0x11,0x11,0x11,0xff,0x12,0x34};
				*(DWORD*)&ppSend[2]	= 255000;
				*(WORD*)&ppSend[6] 	= 0x2fd5;
				*(DWORD*)&ppSend[8] = Item_Table[indx].Id;
				*(BYTE*)&ppSend[12]	= indx;
				*(WORD*)&ppSend[13] = Item_Table[indx].Count;
				pSend(ppSend,15);
				CrashItem(indx);
			}


			BYTE Komut[] = {0x21,0x01,0x18,0xE4,0x03,0x00,0xD5,0x2F,0xD0,0x56,0x4E,0x17,0x1B,0xE8,0x03,0x00,0x00,};
			pSend(Komut,sizeof(Komut));
			arrcount+=1000;
			Item_Table[27].Id = 391010000;
			Item_Table[27].Count = 1000;
			Move(mX,mY);
		}

		char aa[20];
		memset(aa,0,20);
		sprintf(aa,"%d %s %d-%d:%d/%d %d %d [%d/%d]",swx_my_no,name,Level,Para,Hp,MaxHp,bowfind,arrcount,CurrExp,NeedExp);
		SetConsoleTitleA(aa);
		float dist;
		TargetId = FindNearNpc(mX,mY,&dist,Level);
		if (TargetId !=0||TargetId!=-1)
		{
			BYTE Komut[]={0x22,0x00,0x00,0x00};
			*(WORD*)&Komut[1]=TargetId;
			pSend(Komut,sizeof(Komut));

			if (!bow)
			{
			Move(NPCS[TargetId].X,NPCS[TargetId].Y);
            BYTE pBuf_RAttack[10] = {0x08,0x01,0x01,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00};
			*(WORD*)(pBuf_RAttack + 3) = TargetId;
			pSend(pBuf_RAttack,10);
			}
			else
			{
            BYTE	Komut1[26] = {0x31,0x01,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,};
					BYTE	Komut2[22] = {0x31,0x02,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut3[26] = {0x31,0x03,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut4[26] = {0x31,0x04,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x55,0x02,0x06,0x00,0x87,0x01,0x9B,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					DWORD Scode = 207003;
					*(DWORD*)&Komut1[2]=Scode;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut2[2]=Scode;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut3[2]=Scode;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut4[2]=Scode;//*(DWORD*)&GelenBuf[2];
					*(WORD*)&Komut1[6]=CharID;
					*(WORD*)&Komut2[6]=CharID;
					*(WORD*)&Komut3[6]=CharID;
					*(WORD*)&Komut4[6]=CharID;
					*(WORD*)&Komut1[8]=TargetId;
					*(WORD*)&Komut2[8]=TargetId;
					*(WORD*)&Komut3[8]=TargetId;
					*(WORD*)&Komut4[8]=TargetId;
					*(WORD*)&Komut4[10]=X;// *(WORD*)&GelenBuf[10];
					*(WORD*)&Komut4[12]=0;// *(WORD*)&GelenBuf[12];
					*(WORD*)&Komut4[14]=Y;// *(WORD*)&GelenBuf[14];
					pSend(Komut1,sizeof(Komut1));
					pSend(Komut2,sizeof(Komut2));
					pSend(Komut3,sizeof(Komut3));
					pSend(Komut4,sizeof(Komut4));
					Sleep(300);
            }

			Sleep(1000);
			if (Level!=LevelBuffer)
				break;

		}
		}
	}
	else{
		/*

			BYTE Komut = 0 ;
			cClient.pSend(&Komut,1);
			TerminateThread(cClient.Thread41Handle,0);
			TerminateThread(upHandle,0);
			TerminateThread(cClient.MoveThreadHandle,0);
			TerminateThread(cClient.AtackThreadHandle,0);
			TerminateThread(cClient.LevelThreadHandle,0);
			TerminateThread(cClient.PotThreadHandle,0);

          	float dist;
	TargetId = FindNearNpc(X,Y,&dist,1000);

	if (TargetId !=0||TargetId!=-1)
	{
				BYTE Komut[]={0x22,0x00,0x00,0x00};
				*(WORD*)&Komut[1]=TargetId;
				pSend(Komut,sizeof(Komut));
					BYTE	Komut1[26] = {0x31,0x01,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,};
					BYTE	Komut2[22] = {0x31,0x02,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut3[26] = {0x31,0x03,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut4[26] = {0x31,0x04,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x55,0x02,0x06,0x00,0x87,0x01,0x9B,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					*(DWORD*)&Komut1[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut2[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut3[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut4[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(WORD*)&Komut1[6]=CharID;
					*(WORD*)&Komut2[6]=CharID;
					*(WORD*)&Komut3[6]=CharID;
					*(WORD*)&Komut4[6]=CharID;
					*(WORD*)&Komut1[8]=TargetId;
					*(WORD*)&Komut2[8]=TargetId;
					*(WORD*)&Komut3[8]=TargetId;
					*(WORD*)&Komut4[8]=TargetId;
					*(WORD*)&Komut4[10]=X;// *(WORD*)&GelenBuf[10];
					*(WORD*)&Komut4[12]=0;// *(WORD*)&GelenBuf[12];
					*(WORD*)&Komut4[14]=Y;// *(WORD*)&GelenBuf[14];
					pSend(Komut1,sizeof(Komut1));
					pSend(Komut2,sizeof(Komut2));
					pSend(Komut3,sizeof(Komut3));
					pSend(Komut4,sizeof(Komut4));
	}
	Sleep(1300);
	}
		*/
	}
}
}
int WINAPI swxClientClass::MadenThread()
{

			for (int i = 0; i < 28; i++)
			{
				if (Item_Table[i].Id==389135000)
				{
					WearItem(i,6);
				}
			}
			if (Gear_Table[6].Id==0)
			{
			for (int i = 0; i < 28; i++)
			{
				if (Item_Table[i].Id==389132000)
				{
					WearItem(i,6);
				}
			}
			}
	DWORD MadenTick = GetTickCount();
	OturHpFulle();
	printf("started \n");
	bool tried = false;
	ilkgir:
	SetMadenParams(true);
	if (CalculateDistance(MadenX,MadenY)<50)
	{
		goto kazbasi;
	}else
	{
		if (!tried)
		{
            tried = true;
			goto ilkgir;
		}
    }
	GoTown();
	if (Zone==0x15) {
	Move(768,542);
	}
    Move(SundX,SundY);
	RepairAll();
	SellItemsFromList();
	againn:
	GoTown();
	SetMadenParams(true);
    TownToMineZone();

	kazbasi:
	Move(MadenX,MadenY);
	if (Zone==0x15) {
	GoRandom(641,375);
	}

	Sleep(1000);
	MadenKomut(1);
	MadenRecvTick= GetTickCount();
	while (1)
	{
		if (FindItemCount(0)<3)
		{
			MadenKomut(3);

			if (FindItemCount(0)==0)
			{
				if (FindItemIndex(ITEM_NORMAL_ORE)!=255)
				{
					CrashItem(FindItemIndex(ITEM_NORMAL_ORE));
				}
				if (FindItemIndex(ITEM_GOLD_ORE)!=255)
				{
					CrashItem(FindItemIndex(ITEM_GOLD_ORE));
				}
                Sleep(1000);
//                InventoryRefresh();
			}


			OreKir();
			//InventoryRefresh();
			if (FindItemCount(0)<10)
			{
				//active = false;
				GoTown();
				if (Zone ==0x15) {
					Move(768,542);
				}
                Move(SundX,SundY);
				RepairAll();
				SellItemsFromList();



				goto againn;
				//
				//761,523
				//29196
			}
			else
			{
                SetMadenParams(false);
				Move(MadenX,MadenY);
				MadenKomut(1);
				MadenRecvTick= GetTickCount();
			}
			}


		if (TimerKontrol(&MadenTick,5000))
		{
			if (GetTickCount()-MadenRecvTick>15000)
			{
			GoTown();
			if (Zone==0x15) {
				Move(768,542);
			}
				ofstream fSave;
				fSave.open("reiz",std::ios_base::out | std::ios_base::app);
				if(fSave.is_open() == true)
				{
					fSave << " : " << "\n";

				}
					fSave.close();
            Move(SundX,SundY);
				RepairAll();
				SellItemsFromList();
				goto againn;
			}
			else
			{
				MadenKomut(2);
			}
		}
		Sleep(500);
	}
	printf("\nend \n");
	ExitThread(0);
}
bool swxClientClass::OturHpFulle()
{
	if (Hp==MaxHp)
		return true;
	BYTE Komut[]={0x29,0x01,0x02,0x00,0x00,0x00,0x00,0x00};
	pSend(Komut,sizeof(Komut));
	int sittimer = 0 ;
	while (Hp!=MaxHp)
	{
		Sleep(1000);
		sittimer++;
		if (sittimer>15)
            break;
	}
	BYTE Komut2[]={0x29,0x01,0x01,0x00,0x00,0x00,0x00,0x00};
	pSend(Komut2,sizeof(Komut2));
}
bool swxClientClass::GoTown()
{
	OturHpFulle();
	TownState = false;
	BYTE Komut[]={0x48,0x00};
	pSend(Komut,2);
	Sleep(2000);
	int ccc = 0 ;
	while(!TownState)
	{
	ccc++;
	Sleep(250);
	if (ccc>240){
		TownState = true;
		TerminateProcess(GetCurrentProcess(),0);
	}
	}
	return true;
}
bool swxClientClass::pSend(BYTE* Komut,int len)
{
	void * cls= myclass;
	PacketYolla(cls,Komut,len);
	return true;
}
bool swxClientClass::CrashItem(BYTE indx)
{
				if(	Item_Table[indx].Id==ITEM_BLUE_CHEST||
					Item_Table[indx].Id==ITEM_GREEN_CHEST||
					Item_Table[indx].Id==ITEM_RED_CHEST||
					Item_Table[indx].Id==ITEM_FRAGMENT1||
					Item_Table[indx].Id==ITEM_FRAGMENT2||
					Item_Table[indx].Id==ITEM_FRAGMENT3||
					Item_Table[indx].Id==ITEM_FRAGMENT4||
					Item_Table[indx].Id==ITEM_FRAGMENT5||
					Item_Table[indx].Id==ITEM_FRAGMENT6||
					Item_Table[indx].Id==ITEM_FRAGMENT7||
					Item_Table[indx].Id==ITEM_BUS||
					Item_Table[indx].Id==ITEM_TS_SCROLL||
					Item_Table[indx].Id==ITEM_OPAL||
					Item_Table[indx].Id==ITEM_SAPPHIRE||
					Item_Table[indx].Id==ITEM_CRYSTAL)
				{
                    return false;
                }
	BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
	*(DWORD*)&Komut1[3]=Item_Table[indx].Id ;
	Komut1[2]=indx ;
	pSend(Komut1,sizeof(Komut1));
	Item_Table[indx].Id		= 0;
	Item_Table[indx].Count	= 0;
	return true;
}
bool swxClientClass::CrashWearItem(BYTE indx)
{
	BYTE Komut1[]={0x3F,0x01,0x08,0x38,0xD6,0x2F,0x17};
	*(DWORD*)&Komut1[3]=Gear_Table[indx].Id ;
	Komut1[2]=indx ;
	pSend(Komut1,sizeof(Komut1));
	Gear_Table[indx].Id		= 0;
	Gear_Table[indx].Count	= 0;
	return true;
}
bool swxClientClass::WearItem(BYTE indx,BYTE indx2)
{
/*0x1F,0x01,0x01,0xE0,0xAE,0x31,0x17,0x00,0x06,    giy
0x1F,0x01,0x02,0xE0,0xAE,0x31,0x17,0x06,0x00,      cikar
*/
	BYTE Komut1[]={0x1F,0x01,0x01,0xE0,0xAE,0x31,0x17,0x00,0x06};
	*(DWORD*)&Komut1[3]=Item_Table[indx].Id ;
	Komut1[7]=indx ;
	Komut1[8]=indx2 ;
	pSend(Komut1,sizeof(Komut1));
	Gear_Table[indx2].Id =  Item_Table[indx].Id;
	Item_Table[indx].Id		= 0;
	Item_Table[indx].Count	= 0;
	return true;
}
BYTE swxClientClass::FindItemIndex(DWORD Itemid)
{
	for (int i = 0; i < 28; i++) 
	{
		if (Item_Table[i].Id==Itemid)return i;
	}
	return 255;
}
int swxClientClass::FindItemCount(DWORD Itemid)
{
	int ret = 0;
	for (int i = 0; i < 28; i++)
	{
		if (Item_Table[i].Id == Itemid)
		{
			if (Itemid == 0)
			{
				ret++;
			}
			else
			{
                ret+= Item_Table[i].Count;
            }   
		}
	}
	return ret;

}
bool swxClientClass::InventoryRefresh()
{
	InvRefState = false;
	BYTE Komut[]={0x6a,0x02};
	pSend(Komut,sizeof(Komut));
	while (!InvRefState)
	{
		Sleep(250);
	}

	return 1 ;
}
bool swxClientClass::GorevAl(WORD NpcId,WORD id,int index)
{
BYTE Komut1[]={0x20,0x01,0xF0,0x73,0xFF,0xFF,0xFF,0xFF};
*(WORD*)&Komut1[2]= NpcId;
BYTE Komut2[]={0x64,0x07,0xB3,0x14,0x00,0x00};
*(WORD*)&Komut2[2]= id;
pSend(Komut1,sizeof(Komut1));
pSend(Komut2,sizeof(Komut2));
switch (index)
{
	case 0:
	{
		BYTE Komut3[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,};
		BYTE Komut4[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0xFF,};
        pSend(Komut3,sizeof(Komut3));
		pSend(Komut4,sizeof(Komut4));
	}break;
	case 1:
	{
		BYTE Komut3[]={0x55,0x00,0x0F,0x31,0x39,0x30,0x30,0x33,0x5F,0x4C,0x65,0x69,0x7A,0x79,0x2E,0x6C,0x75,0x61,};
		BYTE Komut4[]={0x55,0x00,0x0F,0x31,0x39,0x30,0x30,0x33,0x5F,0x4C,0x65,0x69,0x7A,0x79,0x2E,0x6C,0x75,0x61,0xFF,};
    	pSend(Komut3,sizeof(Komut3));
		pSend(Komut4,sizeof(Komut4));
	}break;
default:
	;
}





	return 1 ;
}
bool swxClientClass::GorevTeslim(WORD NpcId,WORD id)
{
BYTE Komut1[]={0x20,0x01,0xF0,0x73,0xFF,0xFF,0xFF,0xFF};
*(WORD*)&Komut1[2]= NpcId;
BYTE Komut2[]={0x64,0x07,0xB3,0x14,0x00,0x00};
*(WORD*)&Komut2[2]= id;
BYTE Komut3[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,};
BYTE Komut4[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0xFF,};
pSend(Komut1,sizeof(Komut1));
pSend(Komut2,sizeof(Komut2));
pSend(Komut3,sizeof(Komut3));
pSend(Komut4,sizeof(Komut4));
	return 1 ;
}
bool swxClientClass::Arrive(int param_arrive)
{
return true;
/*	switch (param_arrive)
	{
		case 0:
		{
			InventoryRefresh();
		}break;
		case 1://Kaz
		{
			//Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
			//CharacterMove(Ko_Threadsyn->tsocketno,MineX,MineY,4);
		}break;
		case 2://Kir
		{
			for (int j = 0; j < 28; j++)
			{
				if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0x2faf8cd0)
				{
					BYTE Komut1[]={0x31,0x03,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					*(WORD*)&Komut1[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					*(WORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					BYTE Komut2[]={0x31,0x06,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
					*(WORD*)&Komut2[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					*(WORD*)&Komut2[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					for (int i = 0; i < 3; i++)
					{
						Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1));
						Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
					}
				}
				else if (CrashListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1)
				{
					BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
					*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
					Komut1[2]=j ;
					Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
				}
			}			BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
			*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[27].Id ;
			Komut1[2]=27 ;
			Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
			for (int a = 0; a < 28; a++)
			{
				Sleep(50);
				if ((Ko_Threadsyn->Socket_Bilgi1->LoginOk))
				{
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
			for (int j = 0; j < 28; j++)
			{
				if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0x2faf8cd0)
				{
					BYTE Komut1[]={0x31,0x03,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					*(WORD*)&Komut1[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					*(WORD*)&Komut1[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					BYTE Komut2[]={0x31,0x06,0x0A,0xA5,0x07,0x00,0xD5,0x06,0xD5,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
					*(WORD*)&Komut2[6]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					*(WORD*)&Komut2[8]=Ko_Threadsyn->Socket_Bilgi1->CharID;
					for (int i = 0; i < 3; i++)
					{
						Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1));
						Ko_Threadsyn->Extern_KomutYolla(Komut2,sizeof(Komut2));
					}
				}
				else if (CrashListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1)
				{
					BYTE Komut1[]={0x3F,0x02,0x08,0x38,0xD6,0x2F,0x17};
					*(DWORD*)&Komut1[3]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id ;
					Komut1[2]=j ;
					Ko_Threadsyn->Extern_KomutYolla(Komut1,sizeof(Komut1)) ;
				}
			}
			InventoryRefresh();
			if ((TradeListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id))==-1&&(Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id!=0))
			{
				for (int j = 0; j < 28; j++)
				{
					if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id==0)
					{
						BYTE Komut[]={0x1F,0x03,0x00,0x4F,0xCB,0x17,0x04,0x05};
						*(DWORD*)&Komut[2]=Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id;
						Komut[6]=25;
						Komut[7]=j;
						Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
					}
				}
			}
			if ((Ko_Threadsyn->Socket_Bilgi1->Item_Table[25].Id!=0)||(Ko_Threadsyn->Socket_Bilgi1->Gear_Table[6].Durability<500))
			{
				CharacterMove(Ko_Threadsyn->tsocketno,Zone.Sundress.X,Zone.Sundress.Y,3);
			}
			else
			{
				Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
				CharacterMove(Ko_Threadsyn->tsocketno,MineX,MineY,4);
			}
		} break;
		case 3://Sund
		{
			InventoryRefresh();
			for (int j = 0; j < 28; j++)
			{
				if (Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id!=0)
				{
					if (SellListControl(Ko_Threadsyn->Socket_Bilgi1->Item_Table[j].Id)!=-1)
					{
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
			if (AutoMine)
			{
				CharacterMove(Ko_Threadsyn->tsocketno,MineX,MineY,4);
			}
			else
			{
				PartyChatYolla("TTT Tp")    ;
				//CharacterMove(Ko_Threadsyn->tsocketno,DonulecekX,DonulecekY,0);
			}
		} break;
		case 4:
		{   //kazmaya basla
			Ko_Threadsyn->Socket_Bilgi1->Kaz=true;
			Ko_Threadsyn->Socket_Bilgi1->Arrive=0;
		}break;
		case 5:
		{ //potcu
			SellItems(1);
			PotBuy();
			//Client[Ko_Threadsyn->tsocketno].PartyChatYolla(Form1->spcode->Text + " Tp")    ;
			CharacterMove(Ko_Threadsyn->tsocketno,Zone.Sundress.X,Zone.Sundress.Y,10);
			//CharacterMove(Ko_Threadsyn->tsocketno,Client[Ko_Threadsyn->tsocketno].DonulecekX,Client[Ko_Threadsyn->tsocketno].DonulecekY,0);
		}break;
		case 6:
		{ //dolas

		}break;
		case 7:
		{
			Ko_Threadsyn->Socket_Bilgi1->Arrive=0;
		}break;
		case 8 :
		{  //buy armor
			BYTE Komut[]={0x21,0x01,0x11,0x15,0x03,0x00,0xED,0x2A,0x69,0xD1,0x9D,0x0F,0x01,0x01,0x00,0x01,0x0C,};
			*(DWORD*)&Komut[8]=201001001+PaperArmor*1000000+PaperItem*1000;
			switch (PaperClass)
			{
				case 0 :;break;
				case 1 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+40000000;break;
				case 2 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+60000000;break;
				case 3 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+80000000;break;
				default:;
			}
			Komut[15]=  PaperArmor;
			Komut[16]=  PaperItem+6*PaperClass;
			//Form1->log->Items->Add(BufferToHex(Komut,sizeof(Komut)));
			for (int i = 0; i < 28; i++)
			{
				Komut[12]= i ;
				KomutYolla(Komut,sizeof(Komut));
			}
			Komut[0]=0x6a;
			Komut[1]=0x2;
			KomutYolla(Komut,2);
		}break;
		case 9:
		{ //inn

		}break;
		case 10:
		{ //sund
			SellItems(0);
			ItemRepair();
			PartyChatYolla("TTT SlotTp")    ;
		}break;
		case 11:
		{ //matock al
			BYTE Komut1[]={0x20,0x01,0xB0,0x3A,0xFF,0xFF,0xFF,0xFF};
			*(WORD*)&Komut1[2]=Zone.Pitman.Id;
			BYTE Komut2[]={0x64,0x07,0x4D,0x4E,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			KomutYolla(Komut1,sizeof(Komut1));
			KomutYolla(Komut2,sizeof(Komut2));
			KomutYolla(Komut3,sizeof(Komut3));
		}break;
		case 12:
		{ //gobif
			BYTE Komut1[]={0x20,0x01,0x1B,0x32,0xFF,0xFF,0xFF,0xFF};
			BYTE Komut2[]={0x55,0x00,0x0F,0x36,0x30,0x32,0x5F,0x42,0x69,0x66,0x6D,0x6F,0x76,0x65,0x2E,0x6C,0x75,0x61};
			KomutYolla(Komut1,sizeof(Komut1));
			KomutYolla(Komut2,sizeof(Komut2));
		}break;
		case 13:
		{ //buybow
			switch (BuyBowIndex)
			{
				case 0 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xA1,0xEE,0x8A,0x09,0x0F,0x01,0x00,0x02,0x06};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				case 1 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x51,0x9C,0x8C,0x09,0x0F,0x01,0x00,0x02,0x07};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				case 2 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x91,0xA9,0x8F,0x09,0x10,0x01,0x00,0x02,0x08};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				case 3 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xD1,0xB6,0x92,0x09,0x12,0x01,0x00,0x02,0x09};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				case 4 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0xB1,0x27,0x05,0x0A,0x14,0x01,0x00,0x02,0x0A};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				case 5 :
				{
					BYTE Komut1[]={0x21,0x01,0x29,0x11,0x03,0x00,0xD6,0x3A,0x51,0xAE,0x06,0x0A,0x15,0x01,0x00,0x02,0x0B};
					Komut1[12]=FindItem(0);
					KomutYolla(Komut1,sizeof(Komut1));
				}break;
				default:;
			}
		}break;
		case 14:
		{ //1stjob
			BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
			BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			KomutYolla(Komut1,sizeof(Komut1));
			KomutYolla(Komut2,sizeof(Komut2));
			KomutYolla(Komut3,sizeof(Komut3));
		}break;

		case 15:
		{ //inn
			BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
			BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			KomutYolla(Komut1,sizeof(Komut1));
			KomutYolla(Komut2,sizeof(Komut2));
			KomutYolla(Komut3,sizeof(Komut3));
		}break;
		case 16:
		{ //matock al
			BYTE Komut1[]={0x20,0x01,0x08,0x3B,0xFF,0xFF,0xFF,0xFF,};
			BYTE Komut2[]={0x55,0x01,0x0F,0x33,0x31,0x35,0x32,0x36,0x5F,0x43,0x68,0x61,0x6F,0x73,0x2E,0x6C,0x75,0x61,};
			BYTE Komut3[]={0x55,0x00,0x0F,0x33,0x31,0x35,0x32,0x36,0x5F,0x43,0x68,0x61,0x6F,0x73,0x2E,0x6C,0x75,0x61,};
			KomutYolla(Komut1,sizeof(Komut1));
			KomutYolla(Komut2,sizeof(Komut2));
			KomutYolla(Komut3,sizeof(Komut3));
			KomutYolla(Komut3,sizeof(Komut3));
		}break;
		default:;
	}   */
}

bool swxClientClass::OyunGiris(BYTE* GelenBuf)
{
	CharID = *(WORD*)&GelenBuf[1];
	int GidenLen=0;
	GidenLen=GelenBuf[3]; //Login_Bilgi->CharId.Length();
	int ClanLen=0;
	ClanLen=GelenBuf[GidenLen+0x38];//0x2B]; // 33-2b=8
	char ClanName [25];
	memset(ClanName,0,25);
	if(ClanLen==0)
	{
		ClanLen=0;
	}
	else
	{
		memcpy(ClanName,&GelenBuf[GidenLen+0x38+1],ClanLen);
	}
	Level=GelenBuf[23+GidenLen];
	CharClass=GelenBuf[12+GidenLen];
	/*Point=*(WORD*)&GelenBuf[22+GidenLen];
	SkillPoint=GelenBuf[0x70+ServerLen+GidenLen];
	Skill0=GelenBuf[0x75+ServerLen+GidenLen];
	Skill1=GelenBuf[0x76+ServerLen+GidenLen];
	Skill2=GelenBuf[0x77+ServerLen+GidenLen];
	Skill3=GelenBuf[0x78+ServerLen+GidenLen];
	NeedExp=*(INT64*)&GelenBuf[24+GidenLen];
	CurrExp=*(INT64*)&GelenBuf[32+GidenLen];
	Str=GelenBuf[0x55+ServerLen+GidenLen];
	StrP=GelenBuf[0x56+ServerLen+GidenLen];
	Hp=GelenBuf[0x57+ServerLen+GidenLen];
	HpP=GelenBuf[0x58+ServerLen+GidenLen];
	Dex=GelenBuf[0x59+ServerLen+GidenLen];
	DexP=GelenBuf[0x5A+ServerLen+GidenLen];
	Int=GelenBuf[0x5B+ServerLen+GidenLen];
	IntP=GelenBuf[0x5C+ServerLen+GidenLen];
	Mp=GelenBuf[0x5D+ServerLen+GidenLen];
	MpP=GelenBuf[0x5E+ServerLen+GidenLen];
	AP=*(DWORD*)&GelenBuf[0x5F+ServerLen+GidenLen];
	DEF=*(DWORD*)&GelenBuf[0x61+ServerLen+GidenLen];*/
	Para	= *(DWORD*)&GelenBuf[0x6B+ClanLen+GidenLen];
	MaxMana	= *(WORD*)&GelenBuf[0x47+4+ClanLen+GidenLen];
	Mana	= *(WORD*)&GelenBuf[0x47+4+ClanLen+GidenLen+2];
	MaxHp	= *(WORD*)&GelenBuf[0x47+ClanLen+GidenLen];
	Hp		= *(WORD*)&GelenBuf[0x47+ClanLen+GidenLen+2];
	if (Hp == 0)
	{
			BYTE Komut[]= {0x12,0x01};
			pSend(Komut,sizeof(Komut));
	}
	for (int i = 0; i < 14; i++)
	{
		Gear_Table[i].Id=*(DWORD*)&GelenBuf[0x7b+ClanLen+GidenLen+i*19];
		Gear_Table[i].Durability=*(WORD*)&GelenBuf[0x7b+4+ClanLen+GidenLen+i*19];
	}
	for (int i = 0; i < 28; i++)
	{
		Item_Table[i].Id=*(DWORD*)&GelenBuf[0x7b+ClanLen+GidenLen+i*19+19*14];
		Item_Table[i].Durability=*(WORD*)&GelenBuf[0x7b+4+ClanLen+GidenLen+i*19+19*14];
	}
	/*if (Form1->AutoExp->Checked)
	{
		if (SocketGiris->Gear_Table[6].Id==0)
		{
			BYTE Komut[]={0x1F,0x01,0x51,0x9C,0x8C,0x09,0x00,0x06};
			*(DWORD*)&Komut[2]=SocketGiris->Item_Table[0].Id;
			Ko_Threadsyn->Extern_KomutYolla(Komut,sizeof(Komut));
		}
	}*/
	//String YazilacakClass;
	if (CharClass > 150) {
		CharHuman = true;
	}else{
        CharHuman = false;
    }
	if (CharHuman)
	{
		CharClass-=100;
	}
	if (CharClass==106||CharClass==108||CharClass==110||CharClass==112)
	{
		CharMaster=true;
	   //	YazilacakClass="Master ";
	}
	else
	{
		CharClass++;
	 	CharMaster=false;
	}
	switch (CharClass)
	{
		case 108:CharTipi=0;/*YazilacakClass+="Rogue";*/break;
		case 112:CharTipi=1;/*YazilacakClass+="Priest";*/break;
		case 106:CharTipi=2;/*YazilacakClass+="Warrior";*/break;
		case 110:CharTipi=3;/*YazilacakClass+="Mage";*/break;
		case 103:CharTipi=0;/*YazilacakClass+="Noob Rogue";*/break;
		case 105:CharTipi=1;/*YazilacakClass+="Noob Priest";*/break;
		case 102:CharTipi=2;/*YazilacakClass+="Noob Warrior";*/break;
		case 104:CharTipi=3;/*YazilacakClass+="Noob Mage";*/break;
		default:;
	}



	/*Client[socketno].ZoneChange(Client[socketno].ZoneId);
	DurumYaz->Add("Clan  : " +String(ServerName));
	DurumYaz->Add("Level : "+IntToStr(SocketGiris->Level));
	DurumYaz->Add("Name  : "+String(Login_Bilgi->CharId));
	DurumYaz->Add("Money : " +IntToStr(SocketGiris->Para));
	DurumYaz->Add("Class : "+YazilacakClass);
	DurumYaz->Add("Zone : "+Client[socketno].ZoneName);
	DurumYaz->Add("Coord : "+IntToStr(SocketGiris->X)+","+IntToStr(SocketGiris->Y));
	GidenLen+=379+ServerLen+8;//382;   larfowide65 398
	LoginOk=true;
	SocketForm[socketno].SocketGroup->Caption=String(Login_Bilgi->CharId); */
	BYTE Kmt[]={0x6a,0x02};
	pSend(Kmt,sizeof(Kmt));
	/*ThreadOlustur((LPTHREAD_START_ROUTINE)Thread41,(void*)Ko_Threadsyn,socketno,"Thread41");
	ThreadOlustur((LPTHREAD_START_ROUTINE)AnaThread,(void*)Ko_Threadsyn,socketno,"AnaThread");
	if (Client[socketno].AutoAtack)
	{
		ThreadOlustur((LPTHREAD_START_ROUTINE)AtackThread,(void*)socketno,socketno,"AtackThread");
	}*/
	Sleep(2000);
	if (AutoMine)
	{
		if (AutoRepair&&(Gear_Table[6].Durability<500))
		{
			//DurumYaz->Add("Goto Rpr");
			//Client[socketno].CharacterMove(socketno,Client[socketno].Zone.Sundress.X,Client[socketno].Zone.Sundress.Y,3);
		}
		else
		{
			//Ko_Threadsyn->Socket_Bilgi1->Kaz=false;
			//Client[socketno].CharacterMove(socketno,Form1->MineX->Text.ToIntDef(0),Form1->MineY->Text.ToIntDef(0),4);
		}
	}
	/*else if (Client[socketno].Dolas)
	{
		Client[socketno].CharacterMove(socketno,SocketForm[0].ListX->Items->Strings[0].ToIntDef(0),SocketForm[0].ListY->Items->Strings[0].ToIntDef(0),6);
	} */
	//Form1->log->Items->Add("Character Login : "+SocketGiris->CharName+"\["+ IntToStr(socketno)+"\] Level : "+IntToStr(SocketGiris->Level)) ;
	return true;
}
