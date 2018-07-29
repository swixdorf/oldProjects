//---------------------------------------------------------------------------


#pragma hdrstop

#include "koclinet.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

KoClinet::KoClinet()
{
AutoLogin=false;
AutoPotion=false;
AutoRepair=false;
AutoLoot=false;
AutoMine=false;
AutoPressOk=false;
AutoHeal=false;
AutoBuff=false;
ProxyEnable=false;
RunToMob=false;
Dolas=false;
HpAl=5;
MpAl=100;
Distance = 30 ;
MineX = 629;
MineY = 369;
Speed = 10;
SupportId = 0xffff;
AtackType = 2;
ChatTimer=500;
ChatType=1;

HpPot[0].PotMiktar=90;HpPot[1].PotMiktar=180;HpPot[2].PotMiktar=360;HpPot[3].PotMiktar=720;
HpPot[0].PotId=389011000;HpPot[1].PotId=389012000;HpPot[2].PotId=389013000;HpPot[3].PotId=389014000;
HpPot[0].PotSkill=490011;HpPot[1].PotSkill=490012;HpPot[2].PotSkill=490013;HpPot[3].PotSkill=490014;
HpPot[0].PotcuYer=1;HpPot[1].PotcuYer=2;HpPot[2].PotcuYer=3;HpPot[3].PotcuYer=4;
MpPot[0].PotMiktar=180;MpPot[1].PotMiktar=480;MpPot[2].PotMiktar=960;MpPot[3].PotMiktar=1920;
MpPot[0].PotId=389017000;MpPot[1].PotId=389018000;MpPot[2].PotId=389019000;MpPot[3].PotId=389020000;
MpPot[0].PotSkill=490017;MpPot[1].PotSkill=490018;MpPot[2].PotSkill=490019;MpPot[3].PotSkill=490020;
MpPot[0].PotcuYer=7;MpPot[1].PotcuYer=8;MpPot[2].PotcuYer=9;MpPot[3].PotcuYer=10;




}

AnsiString KoClinet::Key_Uret(AnsiString prkey)
{
  return KeyUret(prkey);
}

//WORD KoClinet::NearNpc(WORD *messafe){
//
//}  ;
