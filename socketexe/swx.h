#ifndef swx
#define swx
#include <windows.h>
//#include <vcl.h>
#include <math.h>
#include "koclassturet.h"
#include <stdio.h>
#include <vector>

#define ACT_NOP		0
#define ACT_STORE	1
#define ACT_SELL	2
#define ACT_REMOVE	3


#define ITEM_WOLF			370004000
#define ITEM_ARROW			391010000
#define ITEM_NOAH			900000000
#define ITEM_HP45			389010000
#define ITEM_HP90			389011000
#define ITEM_HP180			389012000
#define ITEM_HP360			389013000
#define ITEM_HP720			389014000
#define ITEM_MP120			389016000
#define ITEM_MP240			389017000
#define ITEM_MP480			389018000
#define ITEM_MP960			389019000
#define ITEM_MP1920			389020000
#define ITEM_KILLINGBLADE	700037000
#define ITEM_TS_SCROLL		381001000
#define ITEM_TS_GEM			379091000
#define ITEM_BLESSING_POT	370005000
#define ITEM_PREPOT_HP		389390000
#define ITEM_PREPOT_MP		389400000
#define ITEM_ROCK			389043000
#define ITEM_BOOK			389026000
#define ITEM_MASTER_ROGUE	379060000
#define ITEM_MASTER_MAGE	379061000
#define ITEM_MASTER_PRIEST	379062000
#define ITEM_MASTER_WARRIOR	379059000
#define ITEM_DCPOT_HP		399284000
#define ITEM_DCPOT_MP		399285000

#define ITEM_ACID   		389083000
#define ITEM_BEZOAR   		389034000
#define ITEM_GLUTINOUS     	389035000
#define ITEM_FIRECRACKER   	379092000
#define ITEM_FLOWERFC	  	379137000
#define ITEM_UP_LOWCLASS  	379221000
#define ITEM_CRYSTAL	  	389075000
#define ITEM_OPAL		  	389076000
#define ITEM_SAPPHIRE	   	389074000
#define ITEM_CALLINGSC	   	389050000
#define ITEM_BUS		   	379021000
#define ITEM_UP_SC		   	379016000
#define ITEM_ABYSS		   	379106000
#define ITEM_MS				900144023
#define ITEM_MP_RICE		800034000
#define ITEM_BRONZE_COIN	379110000
#define ITEM_SILVER_COIN	379109000
#define ITEM_GOLD_COIN		379107000

#define ITEM_ABYSS			379106000
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


struct _CHEST{
	short	m_sSourceID;
	long	m_lChestID;
	float	m_fPosX;
	float	m_fPosY;

	_CHEST(short sSourceID, long lChestID, float fPosX, float fPosY){m_sSourceID = sSourceID; m_lChestID = lChestID; m_fPosX = fPosX; m_fPosY = fPosY;}
};



  WINAPI PacketYolla(void * sinif,BYTE *komut,int sizene)
  {
	   KnightOnline_CLASS_Interface * x=(KnightOnline_CLASS_Interface*)sinif  ;
		x->wsSendPackets(komut,sizene,31);
		 return true;
  }
typedef struct
{
	DWORD Id;
	WORD Count;
	WORD Durability;
}item_yapisi;
typedef struct{
	WORD Id;
	WORD Name;
	WORD X;
	WORD Y;
	BYTE Level;
	BYTE NpcType;
	DWORD Hp;
	DWORD MaxHp;
	DWORD LastTick;
	DWORD KutuId;
	//String Isim ;
	   } Npc_yapisi;
typedef struct{

BYTE Sk[4][24];
BYTE SkSize[4];
BYTE SkType;
bool Active;
DWORD Timer;
DWORD LastUse;
}SkillYapi;
typedef struct {
WORD PotMiktar;
DWORD PotId;
DWORD PotSkill;
WORD PotcuYer;
}pot;
   class swxClientClass
{

	public:

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
	DWORD MadenRecvTick;

	HANDLE MadenThreadHandle;
	HANDLE MoveThreadHandle;
	HANDLE AtackThreadHandle;
	HANDLE LootThreadHandle;
	HANDLE LevelThreadHandle;
	HANDLE PotThreadHandle;
	HANDLE Thread41Handle;
	WORD SundId;
	WORD PitmanId;
	bool TownState;
	bool ZoneState;
	bool alan;
	bool veren;

	bool BaskanCoordGeldi;
	WORD RecvX,RecvY;
	BYTE MoveState;
	Npc_yapisi NPCS[0xffff];
	WORD MinNpcId;
	WORD MaxNpcId;

	bool MadenAktif;
    bool tradeModu;
	SkillYapi   Skill[10];
	int	iItemActionList[33];
	long lItemList[33];
	bool bStackable[33];
	char* strItemList[33];
	long lFragmentList[7];
	char* strFragmentList[7];



		SetClass(KnightOnline_CLASS_Interface * cc);
	KnightOnline_CLASS_Interface * myclass;

	swxClientClass();
	bool TradeKoy(BYTE slot,WORD count);
	bool TradeAccept();
	bool TradeConfirm();
	bool TradeCancel();
	UpdatePos(WORD Xx,WORD Yy);
	bool Move(WORD Xx,WORD Yy);
	bool HareketEt(float Xx,float Yy);
	bool pSend(BYTE* Komut,int len);
	bool CrashItem(BYTE indx);
	bool CrashWearItem(BYTE indx);
	bool WearItem(BYTE indx,BYTE indx2);
	BYTE FindItemIndex(DWORD Itemid);
	int FindItemCount(DWORD Itemid);
	bool InvRefState;
	bool InventoryRefresh();
	bool Arrive(int param_arrive);
	bool OyunGiris(BYTE* GelenBuf);
	bool TimerKontrol(DWORD* ttimer,DWORD ms);
	int MadenKomut(BYTE state);
	bool RepairItem(BYTE slot);
	bool RepairAll();	
	bool OreKir();
	bool SellItem(BYTE indx);
	bool SellItemsFromList();
	bool SetMadenParams(bool degistir);
	bool TownToMineZone();
	bool isMineArea();
	int WINAPI MadenThread();
	bool PotionIc(DWORD PotKod);
	int WINAPI PotThread();
	int WINAPI AtackThread();
	int WINAPI LootThread();
	int WINAPI LevelThread();
	bool OturHpFulle();
	bool GoTown();
	bool GoZone(BYTE ZoneId);
	bool GotoNpc(WORD id);
    bool GorevAl(WORD NpcId,WORD id,int index);
    bool GorevTeslim(WORD NpcId,WORD id);
		WORD Vur(WORD targetid);
	bool GoRandom(WORD xxX,WORD yyY);
	float CalculateDistance(WORD xx,WORD yy);
	WORD FindNearNpc(WORD Xx,WORD Yy,float *dist,int lvllimit);
	WORD MadenX,MadenY,SundX,SundY,PitmanX,PitmanY;
	WORD TargetId;
	WORD LvlLimit;
	int swx_my_no;
	bool kutuyakos;
	std::vector<_CHEST*> lstChestList;
    pot HpPot[4];
	pot MpPot[4];
	DWORD LastHpUseTime;
	DWORD LastMpUseTime;
	char baskanNick[20];
	//typedef std::vector<Npc_yapisi>Npcs;
};
#endif