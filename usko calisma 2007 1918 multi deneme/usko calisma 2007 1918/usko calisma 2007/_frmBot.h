//---------------------------------------------------------------------------

#ifndef _frmBotH
#define _frmBotH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include <stdio.h>
#include <Menus.hpp>
#include <CheckLst.hpp>
#include <ActnPopup.hpp>
//#include <PlatformDefaultStyleActnCtrls.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ToolWin.hpp>
#include <XPStyleActnCtrls.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <list>
#include "Tlhelp32.h"
#include "Windows.h"

#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

#include "CSocket.h"
#include "Main.h"
#include "ServerDefine.h"
#include "Memory.h"
#include "_dlgPartyAdd.h"
#include "_dlgAddition.h"
#include "_dlgCZ.h"

#define WM_SOCKETMSG 401

const short sBotVersion = 1008;

extern char strTrialID[22];
extern bool bHookPatched;

extern HANDLE 	hDLLThread;
extern DWORD	dwDLLThread;

void PatchGameAPIs();

bool __stdcall ProcessRecv(DWORD DataPack, int& iOffset);	//virtual hook
void __stdcall SendFunction(BYTE* pBuf, size_t szBuf);		//virtual send
void __stdcall PostQuitMsg(int nExitCode);					//virtual quit

void __stdcall HookedSendFunction(BYTE* pBuf, size_t szBuf);	//virtual hooked send
void StrEncrypt(char* pStr, BYTE bUseKey);
void StrDecrypt(char* pStr);

bool EnumGameThreads();
void SendTPTPacket();

long 		__stdcall VirtualRegOpenKeyExA(HKEY hKey,LPCTSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,Windows::PHKEY phkResult);
SC_HANDLE 	__stdcall VirtualOpenSCManager(LPCTSTR lpMachineName,LPCTSTR lpDatabaseName,DWORD dwDesiredAccess);
SC_HANDLE 	__stdcall VirtualCreateService(SC_HANDLE hSCManager,LPCTSTR lpServiceName,LPCTSTR lpDisplayName,DWORD dwDesiredAccess,DWORD dwServiceType,DWORD dwStartType,DWORD dwErrorControl,LPCTSTR lpBinaryPathName,LPCTSTR lpLoadOrderGroup,LPDWORD lpdwTagId,LPCTSTR lpDependencies,LPCTSTR lpServiceStartName,LPCTSTR lpPassword);
bool		__stdcall VirtualStartService(SC_HANDLE hService,DWORD dwNumServiceArgs,LPCTSTR *lpServiceArgVectors);
SC_HANDLE	__stdcall VirtualOpenService(SC_HANDLE hSCManager,LPCTSTR lpServiceName,DWORD dwDesiredAccess);
bool	   	__stdcall VirtualControlService(SC_HANDLE hService,DWORD dwControl,LPSERVICE_STATUS lpServiceStatus);
bool		__stdcall VirtualQueryServiceStatus(SC_HANDLE hService,LPSERVICE_STATUS lpServiceStatus);
bool		__stdcall VirtualCloseServiceHandle(SC_HANDLE hSCObject);
LRESULT CALLBACK VirtualWndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

DWORD 		__stdcall VirtualGetModuleFileNameA(HMODULE hModule,LPTSTR lpFilename,DWORD nSize);
HMODULE 	__stdcall VirtualGetModuleHandleA(LPCTSTR lpModuleName);
__declspec(naked) bool __stdcall VirtualGetModuleHandleExA(DWORD dwFlags,LPCTSTR lpModuleName,HMODULE *phModule);
extern bool bOwnCallHandleExA;

BYTE 	HexToByte(char* strHex);
short 	HexToShort(char* strHex);
long 	HexToLong(char* strHex);

void SaveSettings();
void LoadSettings();
void StopBot();

void InitAttackMobList();
void InitMoveList();
void InitLootList();
void InitAlertMobList();
void InitPartyAddList();

bool MoveToPos(float fX, float fY);

void PrintDebuff(char* strName);

inline bool CheckLoading(){return (bool)(!*(DWORD*)(*(DWORD*)(KO_DLGA) + 0x4C4));};

void CastRAttack(DWORD ID);
void CastRock(DWORD ID);

bool IsWarrior(int iClass);
void CheckHealCasts();
DWORD MakeHealCastNum(int iNeededHP);
void RefreshPriestCasts();
bool CheckSelfCure();
bool STRUser(DWORD ID);
bool CureDiseaseUser(DWORD ID);
bool CureCurseUser(DWORD ID);
bool GroupHeal(bool bParty);
bool RestoreUser(DWORD ID);
bool ResistUser(DWORD ID);
bool ACUser(DWORD ID);
bool BuffUser(DWORD ID,int iClass);
bool HealUser(DWORD ID,int iNeededHP);

void CloseInnDlg();
void Gate();
void TeleportUser(DWORD ID);
void ClearDrops();
void LoadSund();
void LoadPot();
void LoadInn();
void SaveSund();
void SavePot();
void SaveInn();
void SupplyChat();
void InnArrived();
void InnReturned();
void PotArrived();
void PotReturned();
void SundArrived();
void SundReturned();
void TownAlert();
bool SHChestTeleport(float fToX, float fToY, int iBoosting);
bool SHTeleport(float fToX, float fToY, int iBoosting);
void CheckServer();
void CloseBot(bool bGoTown);
void QuitBot();
void LogOut();
void BanOther();
void TerminateGame(int iFailIndex);

extern bool bLoadSettings;

extern HWND hGameHWND;

extern char* strServerIP;	//"212.174.142.16"
extern char* strWebAddress;

extern BYTE	bPacketKey;
extern int iRemaining;
extern int iMyUserIndex;
extern int iMyUserID;
extern int iAttackType;

extern CSocket CMainSocket;

extern DWORD dwMyID;
extern DWORD dwRecvdSockHandle;
extern BYTE	pBuf_BuffSelf1[24];
extern BYTE	pBuf_BuffSelf2[24];

extern BYTE	pBuf_Attack1[24];
extern BYTE	pBuf_Attack2[22];
extern BYTE	pBuf_Attack3[24];
extern BYTE	pBuf_Attack4[24];

extern BYTE pBuf_RAttack[10];

struct _POS{
	float m_fPosX;
	float m_fPosY;

	_POS(float fX, float fY){m_fPosX = fX; m_fPosY = fY;}
};

struct _CHEST{
	short	m_sSourceID;
	long	m_lChestID;
	float	m_fPosX;
	float	m_fPosY;

	_CHEST(short sSourceID, long lChestID, float fPosX, float fPosY){m_sSourceID = sSourceID; m_lChestID = lChestID; m_fPosX = fPosX; m_fPosY = fPosY;}
};

struct _DROP{
	long m_lItemID[4];

	_DROP(long ID1, long ID2, long ID3, long ID4){m_lItemID[0] = ID1; m_lItemID[1] = ID2; m_lItemID[2] = ID3; m_lItemID[3] = ID4;}
};

extern std::list<_CHEST*> 					lstChestList;
extern std::list<_CHEST*>::iterator		itChest;

extern std::list<_DROP*> 					lstDropList;
extern std::list<_DROP*>::iterator			itDrop;

//---------------------------------------------------------------------------
class TfrmBot : public TForm
{
__published:	// IDE-managed Components
	TTimer *tmservercheck;
	TTimer *tmcheckrecv;
	TPageControl *pageMain;
	TTabSheet *tabbot;
	TGroupBox *grpsh;
	TLabel *Label1;
	TScrollBar *scsh;
	TLabel *Label2;
	TEdit *txtshdelay;
	TCheckBox *chshenabled;
	TLabel *lbshboost;
	TGroupBox *grpatak;
	TGroupBox *grpskill;
	TCheckBox *chbonus3_1;
	TGroupBox *grpsuperatak;
	TCheckBox *chbonus3;
	TCheckBox *chbonus5;
	TLabel *Label3;
	TEdit *txtbonusdist;
	TGroupBox *grpatakoptions;
	TGroupBox *grptargeting;
	TRadioButton *opautomob;
	TRadioButton *opmanualmob;
	TRadioButton *oplistmob;
	TListBox *lstatakmobs;
	TEdit *txtatakmob;
	TButton *btngetmobname;
	TButton *btnaddmob;
	TGroupBox *grpcasting;
	TLabel *Label4;
	TEdit *txtatakdelay;
	TCheckBox *chshoweffect;
	TCheckBox *chshowmob;
	TCheckBox *chwaitforkill;
	TGroupBox *grpbuffing;
	TCheckBox *chminor;
	TCheckBox *chmana;
	TComboBox *commana;
	TLabel *Label5;
	TEdit *txtmanalimit;
	TCheckBox *chsprint;
	TCheckBox *chsw;
	TCheckBox *chlf;
	TCheckBox *chhide;
	TCheckBox *chevade;
	TCheckBox *chsafety;
	TCheckBox *chscaled;
	TCheckBox *chwolf;
	TCheckBox *chlup;
	TCheckBox *chcats;
	TCheckBox *chcure;
	TGroupBox *grpmove;
	TCheckBox *chts;
	TEdit *txtmovex;
	TEdit *txtmovey;
	TButton *btnmove;
	TCheckBox *chmoving;
	TLabel *Label6;
	TListBox *lstmove;
	TButton *btnaddmove;
	TButton *btnclearmove;
	TButton *btnclearmob;
	TGroupBox *grpchat;
	TEdit *txtchat;
	TComboBox *comchattype;
	TEdit *txtchatdelay;
	TLabel *Label7;
	TCheckBox *chchat;
	TTabSheet *tabother;
	TGroupBox *grploot;
	TCheckBox *chloot;
	TGroupBox *grplootspecial;
	TCheckBox *chmovechest;
	TLabel *Label9;
	TEdit *txtchestdist;
	TLabel *lbcenter;
	TButton *btncenter;
	TCheckBox *chonlyunique;
	TCheckBox *chupgradelimit;
	TEdit *txtupgradelimit;
	TGroupBox *grpother;
	TGroupBox *grpsupply;
	TGroupBox *grpsund;
	TGroupBox *grppot;
	TGroupBox *grpinn;
	TCheckBox *chsund;
	TEdit *txtsund;
	TButton *btnsund;
	TListBox *lstsund;
	TButton *btnsundadd;
	TButton *btnsundclear;
	TButton *btnsundsave;
	TCheckBox *chpot;
	TButton *btnpot;
	TEdit *txtpot;
	TListBox *lstpot;
	TButton *btnaddpot;
	TButton *btnclearpot;
	TButton *btnsavepot;
	TCheckBox *chinn;
	TButton *btninn;
	TEdit *txtinn;
	TListBox *lstinn;
	TButton *btnaddinn;
	TButton *btnclearinn;
	TButton *btnsaveinn;
	TEdit *txtinnslot;
	TCheckBox *chinndepot;
	TLabel *Label13;
	TCheckBox *chwh;
	TCheckBox *chfollowpt;
	TCheckBox *chfollowselected;
	TCheckBox *chotopt;
	TGroupBox *grptown;
	TCheckBox *chgmtown;
	TCheckBox *chmobtown;
	TCheckBox *chtstown;
	TCheckBox *charrowtown;
	TCheckBox *chmanatown;
	TCheckBox *chringwhentown;
	TCheckBox *chpartytown;
	TListBox *lsttownmobs;
	TButton *btnaddtownmob;
	TEdit *txttownmob;
	TButton *btntownmob;
	TButton *btncleartownmob;
	TGroupBox *grpinformsupply;
	TEdit *txtinformsupply;
	TCheckBox *chinformsupply;
	TLabel *Label14;
	TTabSheet *tabmage;
	TTimer *tmsh;
	TCheckBox *chringondie;
	TTimer *tmbuffing;
	TTimer *tmchat;
	TTimer *tmattack;
	TTimer *tmmove;
	TTimer *tmrecvfunction;
	TTimer *tmfollow;
	TTimer *tmtown;
	TButton *btnstopalarm;
	TCheckBox *chlootlist;
	TListBox *lstlootids;
	TEdit *txtlootid;
	TButton *btnadditem;
	TButton *btngetfirstitem;
	TButton *btnclearitems;
	TCheckBox *chpricelimit;
	TEdit *txtpricelimit;
	TTimer *tmsupply;
	TTimer *tmsundgo;
	TTimer *tmpotgo;
	TTimer *tminngo;
	TTimer *tmreport;
	TCheckBox *chhp;
	TComboBox *comhp;
	TLabel *Label17;
	TEdit *txthplimit;
	TButton *btnpotoptions;
	TShape *shpstatus;
	TButton *btnexit;
	TButton *btnstop;
	TButton *btnstart;
	TButton *btnminimize;
	TTimer *tmmovechest;
	TButton *btnclosebot;
	TTabSheet *tabpriest;
	TGroupBox *grpmagetp;
	TCheckBox *chtpchat;
	TEdit *txttpchat;
	TCheckBox *chhptp;
	TEdit *txttplimit;
	TCheckBox *chgate;
	TEdit *txtgatelimit;
	TGroupBox *grpmageatak;
	TTimer *tmtp;
	TTimer *tmmageattack;
	TCheckBox *chantifreeze;
	TGroupBox *grpextra;
	TLabel *Label8;
	TScrollBar *scmysize;
	TLabel *lbmysize;
	TButton *btnresetsize;
	TCheckBox *chtargetsize;
	TTimer *tmtargetsize;
	TCheckBox *chmage62;
	TCheckBox *chlootcoins;
	TCheckBox *chonlyenemy;
	TCheckBox *chonlytarget;
	TTrayIcon *trayMain;
	TButton *btntray;
	TCheckBox *chtopmost;
	TButton *btngamewnd;
	TTabSheet *tabattack;
	TGroupBox *grpprimembers;
	TCheckBox *chprimember1;
	TCheckBox *chprimember2;
	TCheckBox *chprimember3;
	TCheckBox *chprimember4;
	TCheckBox *chprimember5;
	TCheckBox *chprimember6;
	TCheckBox *chprimember7;
	TCheckBox *chprimember8;
	TGroupBox *grppiest;
	TGroupBox *grpheal;
	TCheckBox *chpriheal;
	TComboBox *comheal;
	TRadioButton *ophealcast;
	TRadioButton *ophealoto;
	TLabel *Label12;
	TEdit *txtheallimit;
	TCheckBox *chfirstlesshp;
	TGroupBox *grpbuff;
	TCheckBox *chbuff;
	TComboBox *combuff;
	TComboBox *comac;
	TCheckBox *chac;
	TComboBox *comresist;
	TCheckBox *chresist;
	TGroupBox *grpgroup;
	TCheckBox *chgroup;
	TComboBox *comgroup;
	TComboBox *comrestore;
	TCheckBox *chrestore;
	TCheckBox *chprisit;
	TCheckBox *chpricure;
	TCheckBox *chpristr;
	TCheckBox *chpribook;
	TGroupBox *grpdebuff;
	TCheckBox *chmalice;
	TCheckBox *chparasite;
	TCheckBox *chtorment;
	TCheckBox *chmassive;
	TGroupBox *grppartychat;
	TCheckBox *chchatheal;
	TEdit *txtchatheal;
	TEdit *txtchatbuff;
	TCheckBox *chchatbuff;
	TLabel *lbmember1;
	TLabel *lbmember2;
	TLabel *lbmember3;
	TLabel *lbmember4;
	TLabel *lbmember5;
	TLabel *lbmember6;
	TLabel *lbmember7;
	TLabel *lbmember8;
	TTimer *tmpriest;
	TTimer *tmpribot;
	TCheckBox *chprintname;
	TCheckBox *chundy;
	TTabSheet *tababout;
	TLabel *Label15;
	TLabel *Label16;
	TGroupBox *grpreport;
	TLabel *lbreportcount;
	TLabel *Label11;
	TRichEdit *txtreport;
	TButton *btnreport;
	TButton *btnrprinfo;
	TButton *Button1;
	TGroupBox *grpattack;
	TCheckBox *chrattack;
	TCheckBox *chrunmob;
	TLabel *Label18;
	TEdit *txtrundist;
	TGroupBox *grpasas;
	TCheckListBox *lstasas;
	TCheckBox *chpercent5;
	TCheckBox *chpercent10;
	TCheckBox *chrock;
	TGroupBox *grpwarrior;
	TCheckBox *chbinding;
	TCheckBox *chprovoke;
	TGroupBox *grppriest;
	TRadioButton *opbuff;
	TRadioButton *opheal;
	TRadioButton *opdebuff;
	TCheckBox *chlightstrike;
	TCheckBox *chbrightness;
	TCheckBox *chlightattack;
	TCheckBox *chlightcounter;
	TCheckBox *chcriticallight;
	TCheckBox *chstr30;
	TCheckBox *chpriattack;
	TCheckBox *chasas;
	TCheckBox *chdebuff;
	TListBox *lstwarrior;
	TCheckBox *chsprint2;
	TCheckBox *chdefense;
	TCheckBox *chgain;
	TTimer *tmasasbot;
	TLabel *Label19;
	TLabel *lbbotcenter;
	TButton *btnbotcenter;
	TTimer *tmwarriorbot;
	TCheckBox *chwarrior;
	TPanel *pnsavesund;
	TEdit *txtsundsave;
	TButton *btnsavesund;
	TButton *btnloadsund;
	TButton *btnclosesund;
	TPanel *pnpotsave;
	TEdit *txtpotsave;
	TButton *btnpotsave;
	TButton *btnloadpot;
	TButton *btnclosepot;
	TPanel *pninnsave;
	TEdit *txtinnsave;
	TButton *btninnsave;
	TButton *btninnload;
	TButton *btninnclose;
	TCheckBox *chstealthhack;
	TCheckBox *charchery;
	TCheckBox *chautorevive;
	TButton *btnsell;
	TRadioButton *oproutesh;
	TLabel *Label20;
	TRadioButton *oproutenormal;
	TCheckBox *chstunchar;
	TEdit *txtminorlimit;
	TButton *btnbuy;
	TPanel *pnbuy;
	TButton *btnbuyclose;
	TCheckBox *chbuywolf;
	TCheckBox *chbuyarrow;
	TCheckBox *chbuyts;
	TEdit *txtbuyts;
	TCheckBox *chbuybook;
	TEdit *txtbuybook;
	TCheckBox *chbuyrock;
	TEdit *txtbuyrock;
	TCheckListBox *lstpriest;
	TCheckListBox *lstarchery;
	TCheckBox *chblow;
	TGroupBox *grpsave;
	TLabel *Label21;
	TEdit *txtloadsavefile;
	TButton *btnsave;
	TButton *btnload;
	TCheckListBox *lstmagebasic;
	TCheckListBox *lstmageflame;
	TCheckListBox *lstmageice;
	TCheckListBox *lstmagelight;
	TCheckBox *chmageattack;
	TCheckBox *chfarchest;
	TCheckBox *chringondc;
	TCheckBox *chcloseondc;
	TCheckBox *chbuymaster;
	TEdit *txtbuymaster;
	TPanel *pnsell;
	TCheckBox *chsell;
	TCheckBox *chsellslot;
	TEdit *txtsellslot;
	TCheckBox *chsellabovelimit;
	TEdit *txtsellabovelimit;
	TCheckBox *chselllesslimit;
	TEdit *txtselllesslimit;
	TButton *btnclosesell;
	TRadioButton *opsellwait;
	TRadioButton *opsellgo;
	TPanel *pnpot;
	TCheckBox *btnbuymana;
	TEdit *txtbuymana;
	TEdit *txtbuyhp;
	TCheckBox *btnbuyhp;
	TButton *btnpnok;
	TScrollBar *scsavecpu;
	TCheckBox *chsavecpu;
	TTimer *tmsavecpu;
	TButton *btnaddlist;
	TCheckBox *chautoadd;
	TTimer *tmpartyadd;
	TPopupActionBar *popup1;
	TMenuItem *btnpopup3;
	TMenuItem *btnpopup4;
	TMenuItem *btnpopup5;
	TMenuItem *btnpopup1;
	TMenuItem *btnpopup2;
	TButton *btnhidebot;
	TPopupActionBar *popup2;
	TMenuItem *btnmenubdw;
	TCheckBox *chnotrade;
	TCheckBox *chnoparty;
	TCheckBox *chnocombat;
	TCheckBox *chgamemenu;
	TMenuItem *btnmenucz;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall tmservercheckTimer(TObject *Sender);
	void __fastcall tmcheckrecvTimer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall chshenabledClick(TObject *Sender);
	void __fastcall scshChange(TObject *Sender);
	void __fastcall txtshdelayChange(TObject *Sender);
	void __fastcall tmshTimer(TObject *Sender);
	void __fastcall oparcheryClick(TObject *Sender);
	void __fastcall opperfectClick(TObject *Sender);
	void __fastcall oparcClick(TObject *Sender);
	void __fastcall chbonus3_1Click(TObject *Sender);
	void __fastcall opautomobClick(TObject *Sender);
	void __fastcall opmanualmobClick(TObject *Sender);
	void __fastcall oplistmobClick(TObject *Sender);
	void __fastcall txtatakdelayChange(TObject *Sender);
	void __fastcall chbonus3Click(TObject *Sender);
	void __fastcall chbonus5Click(TObject *Sender);
	void __fastcall txtbonusdistChange(TObject *Sender);
	void __fastcall chshoweffectClick(TObject *Sender);
	void __fastcall chshowmobClick(TObject *Sender);
	void __fastcall chwaitforkillClick(TObject *Sender);
	void __fastcall chminorClick(TObject *Sender);
	void __fastcall chmanaClick(TObject *Sender);
	void __fastcall commanaChange(TObject *Sender);
	void __fastcall txtmanalimitChange(TObject *Sender);
	void __fastcall chwolfClick(TObject *Sender);
	void __fastcall chtsClick(TObject *Sender);
	void __fastcall chsprintClick(TObject *Sender);
	void __fastcall chhideClick(TObject *Sender);
	void __fastcall chscaledClick(TObject *Sender);
	void __fastcall chcureClick(TObject *Sender);
	void __fastcall chswClick(TObject *Sender);
	void __fastcall chevadeClick(TObject *Sender);
	void __fastcall chlupClick(TObject *Sender);
	void __fastcall chlfClick(TObject *Sender);
	void __fastcall chsafetyClick(TObject *Sender);
	void __fastcall chcatsClick(TObject *Sender);
	void __fastcall chmovingClick(TObject *Sender);
	void __fastcall txtchatdelayChange(TObject *Sender);
	void __fastcall comchattypeChange(TObject *Sender);
	void __fastcall chlootClick(TObject *Sender);
	void __fastcall chmovechestClick(TObject *Sender);
	void __fastcall txtchestdistChange(TObject *Sender);
	void __fastcall chonlyuniqueClick(TObject *Sender);
	void __fastcall chupgradelimitClick(TObject *Sender);
	void __fastcall txtupgradelimitChange(TObject *Sender);
	void __fastcall chsundClick(TObject *Sender);
	void __fastcall chpotClick(TObject *Sender);
	void __fastcall chinnClick(TObject *Sender);
	void __fastcall chbuywolfClick(TObject *Sender);
	void __fastcall chbuyarrowClick(TObject *Sender);
	void __fastcall btnbuymanaClick(TObject *Sender);
	void __fastcall txtbuymanaChange(TObject *Sender);
	void __fastcall txtinnslotChange(TObject *Sender);
	void __fastcall chinndepotClick(TObject *Sender);
	void __fastcall chfollowptClick(TObject *Sender);
	void __fastcall chfollowselectedClick(TObject *Sender);
	void __fastcall chotoptClick(TObject *Sender);
	void __fastcall chgmtownClick(TObject *Sender);
	void __fastcall chmobtownClick(TObject *Sender);
	void __fastcall chtstownClick(TObject *Sender);
	void __fastcall charrowtownClick(TObject *Sender);
	void __fastcall chmanatownClick(TObject *Sender);
	void __fastcall chpartytownClick(TObject *Sender);
	void __fastcall chringondieClick(TObject *Sender);
	void __fastcall chringwhentownClick(TObject *Sender);
	void __fastcall chinformsupplyClick(TObject *Sender);
	void __fastcall btnclearmobClick(TObject *Sender);
	void __fastcall btngetmobnameClick(TObject *Sender);
	void __fastcall btnaddmobClick(TObject *Sender);
	void __fastcall tmbuffingTimer(TObject *Sender);
	void __fastcall btnmoveClick(TObject *Sender);
	void __fastcall btnclearmoveClick(TObject *Sender);
	void __fastcall btnaddmoveClick(TObject *Sender);
	void __fastcall chchatClick(TObject *Sender);
	void __fastcall tmchatTimer(TObject *Sender);
	void __fastcall btnstartClick(TObject *Sender);
	void __fastcall btnstopClick(TObject *Sender);
	void __fastcall tmattackTimer(TObject *Sender);
	void __fastcall tmmoveTimer(TObject *Sender);
	void __fastcall tmmovechestTimer(TObject *Sender);
	void __fastcall btncenterClick(TObject *Sender);
	void __fastcall tmrecvfunctionTimer(TObject *Sender);
	void __fastcall chwhClick(TObject *Sender);
	void __fastcall tmfollowTimer(TObject *Sender);
	void __fastcall btnexitClick(TObject *Sender);
	void __fastcall tmtownTimer(TObject *Sender);
	void __fastcall btntownmobClick(TObject *Sender);
	void __fastcall btnaddtownmobClick(TObject *Sender);
	void __fastcall btncleartownmobClick(TObject *Sender);
	void __fastcall btnstopalarmClick(TObject *Sender);
	void __fastcall chlootlistClick(TObject *Sender);
	void __fastcall btngetfirstitemClick(TObject *Sender);
	void __fastcall btnadditemClick(TObject *Sender);
	void __fastcall btnclearitemsClick(TObject *Sender);
	void __fastcall chpricelimitClick(TObject *Sender);
	void __fastcall txtpricelimitChange(TObject *Sender);
	void __fastcall tmsupplyTimer(TObject *Sender);
	void __fastcall tmsundgoTimer(TObject *Sender);
	void __fastcall tmpotgoTimer(TObject *Sender);
	void __fastcall tminngoTimer(TObject *Sender);
	void __fastcall btnsundClick(TObject *Sender);
	void __fastcall btnpotClick(TObject *Sender);
	void __fastcall btninnClick(TObject *Sender);
	void __fastcall btnsundaddClick(TObject *Sender);
	void __fastcall btnaddpotClick(TObject *Sender);
	void __fastcall btnaddinnClick(TObject *Sender);
	void __fastcall btnsundclearClick(TObject *Sender);
	void __fastcall btnclearpotClick(TObject *Sender);
	void __fastcall btnclearinnClick(TObject *Sender);
	void __fastcall btnsundsaveClick(TObject *Sender);
	void __fastcall btnsavepotClick(TObject *Sender);
	void __fastcall btnsaveinnClick(TObject *Sender);
	void __fastcall txtreportChange(TObject *Sender);
	void __fastcall btnreportClick(TObject *Sender);
	void __fastcall tmreportTimer(TObject *Sender);
	void __fastcall chhpClick(TObject *Sender);
	void __fastcall comhpChange(TObject *Sender);
	void __fastcall txthplimitChange(TObject *Sender);
	void __fastcall btnpnokClick(TObject *Sender);
	void __fastcall btnpotoptionsClick(TObject *Sender);
	void __fastcall btnbuyhpClick(TObject *Sender);
	void __fastcall txtbuyhpChange(TObject *Sender);
	void __fastcall btnminimizeClick(TObject *Sender);
	void __fastcall btnclosebotClick(TObject *Sender);
	void __fastcall chtpchatClick(TObject *Sender);
	void __fastcall chhptpClick(TObject *Sender);
	void __fastcall chgateClick(TObject *Sender);
	void __fastcall txttplimitChange(TObject *Sender);
	void __fastcall txtgatelimitChange(TObject *Sender);
	void __fastcall tmtpTimer(TObject *Sender);
	void __fastcall chantifreezeClick(TObject *Sender);
	void __fastcall scmysizeChange(TObject *Sender);
	void __fastcall btnresetsizeClick(TObject *Sender);
	void __fastcall tmtargetsizeTimer(TObject *Sender);
	void __fastcall chtargetsizeClick(TObject *Sender);
	void __fastcall chmage62Click(TObject *Sender);
	void __fastcall tmmageattackTimer(TObject *Sender);
	void __fastcall chlootcoinsClick(TObject *Sender);
	void __fastcall btnrprinfoClick(TObject *Sender);
	void __fastcall chonlyenemyClick(TObject *Sender);
	void __fastcall chonlytargetClick(TObject *Sender);
	void __fastcall chtopmostClick(TObject *Sender);
	void __fastcall btntrayClick(TObject *Sender);
	void __fastcall trayMainClick(TObject *Sender);
	void __fastcall btngamewndClick(TObject *Sender);
	void __fastcall opthroughClick(TObject *Sender);
	void __fastcall chprimember1Click(TObject *Sender);
	void __fastcall chprimember2Click(TObject *Sender);
	void __fastcall chprimember3Click(TObject *Sender);
	void __fastcall chprimember4Click(TObject *Sender);
	void __fastcall chprimember5Click(TObject *Sender);
	void __fastcall chprimember6Click(TObject *Sender);
	void __fastcall chprimember7Click(TObject *Sender);
	void __fastcall chprimember8Click(TObject *Sender);
	void __fastcall chprihealClick(TObject *Sender);
	void __fastcall ophealcastClick(TObject *Sender);
	void __fastcall ophealotoClick(TObject *Sender);
	void __fastcall comhealChange(TObject *Sender);
	void __fastcall txtheallimitChange(TObject *Sender);
	void __fastcall chfirstlesshpClick(TObject *Sender);
	void __fastcall chbuffClick(TObject *Sender);
	void __fastcall chacClick(TObject *Sender);
	void __fastcall chresistClick(TObject *Sender);
	void __fastcall combuffChange(TObject *Sender);
	void __fastcall comacChange(TObject *Sender);
	void __fastcall comresistChange(TObject *Sender);
	void __fastcall chgroupClick(TObject *Sender);
	void __fastcall chrestoreClick(TObject *Sender);
	void __fastcall comgroupChange(TObject *Sender);
	void __fastcall comrestoreChange(TObject *Sender);
	void __fastcall chmaliceClick(TObject *Sender);
	void __fastcall chparasiteClick(TObject *Sender);
	void __fastcall chtormentClick(TObject *Sender);
	void __fastcall chmassiveClick(TObject *Sender);
	void __fastcall chchathealClick(TObject *Sender);
	void __fastcall chchatbuffClick(TObject *Sender);
	void __fastcall chprisitClick(TObject *Sender);
	void __fastcall chpricureClick(TObject *Sender);
	void __fastcall chpristrClick(TObject *Sender);
	void __fastcall chpribookClick(TObject *Sender);
	void __fastcall tmpriestTimer(TObject *Sender);
	void __fastcall chprintnameClick(TObject *Sender);
	void __fastcall chundyClick(TObject *Sender);
	void __fastcall chrattackClick(TObject *Sender);
	void __fastcall chrunmobClick(TObject *Sender);
	void __fastcall txtrundistChange(TObject *Sender);
	void __fastcall chrockClick(TObject *Sender);
	void __fastcall chpercent5Click(TObject *Sender);
	void __fastcall chpercent10Click(TObject *Sender);
	void __fastcall chbindingClick(TObject *Sender);
	void __fastcall chprovokeClick(TObject *Sender);
	void __fastcall chpriattackClick(TObject *Sender);
	void __fastcall opbuffClick(TObject *Sender);
	void __fastcall ophealClick(TObject *Sender);
	void __fastcall opdebuffClick(TObject *Sender);
	void __fastcall chlightstrikeClick(TObject *Sender);
	void __fastcall chlightcounterClick(TObject *Sender);
	void __fastcall chbrightnessClick(TObject *Sender);
	void __fastcall chcriticallightClick(TObject *Sender);
	void __fastcall chlightattackClick(TObject *Sender);
	void __fastcall chstr30Click(TObject *Sender);
	void __fastcall chasasClick(TObject *Sender);
	void __fastcall chdebuffClick(TObject *Sender);
	void __fastcall chsprint2Click(TObject *Sender);
	void __fastcall chdefenseClick(TObject *Sender);
	void __fastcall chgainClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall lstasasClick(TObject *Sender);
	void __fastcall tmasasbotTimer(TObject *Sender);
	void __fastcall btnbotcenterClick(TObject *Sender);
	void __fastcall lstwarriorClick(TObject *Sender);
	void __fastcall tmwarriorbotTimer(TObject *Sender);
	void __fastcall chwarriorClick(TObject *Sender);
	void __fastcall lstpriestClick(TObject *Sender);
	void __fastcall btnclosesundClick(TObject *Sender);
	void __fastcall btnclosepotClick(TObject *Sender);
	void __fastcall btninncloseClick(TObject *Sender);
	void __fastcall btnsavesundClick(TObject *Sender);
	void __fastcall btnloadsundClick(TObject *Sender);
	void __fastcall btnloadpotClick(TObject *Sender);
	void __fastcall btninnsaveClick(TObject *Sender);
	void __fastcall btninnloadClick(TObject *Sender);
	void __fastcall btnpotsaveClick(TObject *Sender);
	void __fastcall chstealthhackClick(TObject *Sender);
	void __fastcall tmpribotTimer(TObject *Sender);
	void __fastcall charcheryClick(TObject *Sender);
	void __fastcall chautoreviveClick(TObject *Sender);
	void __fastcall btnsellClick(TObject *Sender);
	void __fastcall btnclosesellClick(TObject *Sender);
	void __fastcall chsellClick(TObject *Sender);
	void __fastcall chsellslotClick(TObject *Sender);
	void __fastcall txtsellslotChange(TObject *Sender);
	void __fastcall chsellabovelimitClick(TObject *Sender);
	void __fastcall chselllesslimitClick(TObject *Sender);
	void __fastcall txtsellabovelimitChange(TObject *Sender);
	void __fastcall txtselllesslimitChange(TObject *Sender);
	void __fastcall opsellwaitClick(TObject *Sender);
	void __fastcall opsellgoClick(TObject *Sender);
	void __fastcall oprouteshClick(TObject *Sender);
	void __fastcall oproutenormalClick(TObject *Sender);
	void __fastcall chstuncharClick(TObject *Sender);
	void __fastcall txtminorlimitChange(TObject *Sender);
	void __fastcall btnbuycloseClick(TObject *Sender);
	void __fastcall btnbuyClick(TObject *Sender);
	void __fastcall chbuytsClick(TObject *Sender);
	void __fastcall chbuybookClick(TObject *Sender);
	void __fastcall txtbuytsChange(TObject *Sender);
	void __fastcall txtbuybookChange(TObject *Sender);
	void __fastcall chbuyrockClick(TObject *Sender);
	void __fastcall txtbuyrockChange(TObject *Sender);
	void __fastcall lstarcheryClick(TObject *Sender);
	void __fastcall chblowClick(TObject *Sender);
	void __fastcall lstmagebasicClick(TObject *Sender);
	void __fastcall lstmageflameClick(TObject *Sender);
	void __fastcall lstmageiceClick(TObject *Sender);
	void __fastcall lstmagelightClick(TObject *Sender);
	void __fastcall chmageattackClick(TObject *Sender);
	void __fastcall btnsaveClick(TObject *Sender);
	void __fastcall btnloadClick(TObject *Sender);
	void __fastcall chfarchestClick(TObject *Sender);
	void __fastcall chbuymasterClick(TObject *Sender);
	void __fastcall txtbuymasterChange(TObject *Sender);
	void __fastcall chsavecpuClick(TObject *Sender);
	void __fastcall tmsavecpuTimer(TObject *Sender);
	void __fastcall scsavecpuChange(TObject *Sender);
	void __fastcall btnaddlistClick(TObject *Sender);
	void __fastcall chautoaddClick(TObject *Sender);
	void __fastcall tmpartyaddTimer(TObject *Sender);
	void __fastcall btnpopup3Click(TObject *Sender);
	void __fastcall btnpopup4Click(TObject *Sender);
	void __fastcall btnpopup5Click(TObject *Sender);
	void __fastcall btnpopup1Click(TObject *Sender);
	void __fastcall btnpopup2Click(TObject *Sender);
	void __fastcall btnhidebotClick(TObject *Sender);
	void __fastcall btnmenubdwClick(TObject *Sender);
	void __fastcall chnotradeClick(TObject *Sender);
	void __fastcall chnopartyClick(TObject *Sender);
	void __fastcall chnocombatClick(TObject *Sender);
	void __fastcall chgamemenuClick(TObject *Sender);
	void __fastcall btnmenuczClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	int bBotStatus;

	int iServerCheckCounter;
	int	iPutKeyCounter;
	int iCheckTick;

	int		iSHBoost;
	int 	iSHDelay;
	int		iSkillIndex;
	bool	bBonus3_1;
	bool	bBonus5_1;
	bool	bBonus3;
	bool	bBonus5;
	int		iMobCount;
	char*	strMobList[10];
	int		iBonusDistance;
	int		iTargetingType;
	int		iAttackDelay;
	bool	bShowEffect;
	bool   	bShowMob;
	bool	bWaitForKill;
	bool	bMinor;
	bool	bMana;
	bool	bHP;
	DWORD	dwManaSkillNum;
	DWORD	dwManaItemNum;
	DWORD	dwHPSkillNum;
	DWORD	dwHPItemNum;
	int		iManaType;
	int		iManaLimit;
	int		iHPType;
	int		iHPLimit;
	bool 	bWolf;
	bool	bTS;
	bool	bSprint;
	bool	bHide;
	bool	bScaled;
	bool	bCure;
	bool	bSW;
	bool	bEvade;
	bool	bLup;
	bool	bLF;
	bool	bSafety;
	bool	bCats;
	bool	bMoving;
	bool	bMovePaused;
	int		iMoveX[20];
	int		iMoveY[20];
	int		iMoveCount;
	int		iCurrentRoute;
	int		iLastPos;
	int		iChatDelay;
	int		iChatType;
	bool	bLoot;
	bool	bLootPaused;
	bool	bLootCoins;
	bool	bMoveToChest;
	int		iMaxChestDistance;
	int		iCenterX;
	int		iCenterY;
	bool	bLootUnique;
	bool	bLootUpgrade;
	bool	bLootPriceLimit;
	int		iLootPriceLimit;
	int		iLootUpgradeLimit;
	bool	bLootList;
	int		iLootCount;
	long	lLootID[10];
	bool	bSund;
	bool	bPot;
	bool	bInn;
	bool	bBuyWolf;
	bool	bBuyArrow;
	bool	bBuyMana;
	int		iBuyManaLimit;
	bool	bBuyHP;
	int		iBuyHPLimit;
	int		iInnBeginSlot;
	bool	bInnDepot;
	bool	bFollowLeader;
	bool	bFollowSelected;
	bool	bAutoParty;
	bool	bAutoInvite;
	bool	bTownOnGM;
	bool	bTownOnMob;
	bool	bTownOnNoTS;
	bool	bTownOnNoArrow;
	bool	bTownOnNoMana;
	bool	bTownOnNoParty;
	bool	bRingOnDie;
	bool	bRingOnTown;
	bool	bInformAfterSupply;

	int		iLastMinorTick;
	int		iLastManaTick;
	int		iLastHPTick;
	int		iLastWolfTick;
	int		iLastTSTick;
	int		iLastSprintTick;
	int		iLastHideTick;
	int		iLastScaledTick;
	int		iLastCureTick;
	int		iLastSWTick;
	int		iLastEvadeTick;
	int		iLastLupTick;
	int		iLastLFTick;
	int		iLastSafetyTick;
	int		iLastCatsTick;
	int		iLastMage62Tick;

	int		iLastAttackTick;

	WORD	wLastTarget;

	DWORD	dwCastNum;
	DWORD	dwCastNum_3;
	DWORD	dwCastNum_5;

	bool	bWaitingNewDrop;

	DWORD	dwLastChestID;
	float	fLastChestDist;

	char*	strAlertMobList[10];
	int		iAlertMobCount;

	HWND	mciAlarm;

	bool	bOnSundWay;
	bool	bOnPotWay;
	bool	bOnInnWay;

	int		iSundCount;
	int		iSundX[20];
	int		iSundY[20];

	int		iPotCount;
	int		iPotX[20];
	int		iPotY[20];

	int		iInnCount;
	int		iInnX[20];
	int		iInnY[20];

	int		iSundLastPos;
	int		iSundRoute;
	int		iPotLastPos;
	int		iPotRoute;
	int		iInnLastPos;
	int		iInnRoute;

	bool	bBotPaused;

	bool	bMinimized;

	bool	bChatTP;
	bool	bLimitTP;
	int		iTPLimit;
	bool	bAutoGate;
	int		iGateLimit;

	int		iLastTPTick;
	int		iLastGateTick;

	bool	bAntiFreeze;

	bool	bMage62;

	DWORD	dwCastNum18;
	DWORD	dwCastNum33;
	DWORD	dwCastNum43;
	DWORD	dwCastNum45;
	DWORD	dwCastNum51;
	DWORD	dwCastNum54;
	DWORD	dwCastNum56;
	DWORD	dwCastNum57;
	DWORD	dwCastNum60;
	DWORD	dwCastNum70;

	int		iSkillType_18;
	int		iSkillType_33;
	int		iSkillType_43;
	int		iSkillType_45;
	int		iSkillType_51;
	int		iSkillType_54;
	int		iSkillType_56;
	int		iSkillType_57;
	int		iSkillType_60;
	int		iSkillType_70;

	bool	bCast18;
	bool	bCast33;
	bool	bCast45;
	bool	bCast51;
	bool	bCast54;
	bool	bCast57;
	bool	bCast60;
	bool	bCast70;

	bool	bMageCloseAttack;
	int		iSkillIndex_CloseAttack;

	int		iLastCastTick_18;
	int		iLastCastTick_33;
	int		iLastCastTick_45;
	int		iLastCastTick_51;
	int		iLastCastTick_54;
	int		iLastCastTick_57;
	int		iLastCastTick_60;
	int		iLastCastTick_70;

	long	lMageCastData18;
	long	lMageCastData33;
	long	lMageCastData43;
	long	lMageCastData45;
	long	lMageCastData51;
	long	lMageCastData54;
	long	lMageCastData56;
	long	lMageCastData57;
	long	lMageCastData60;
	long	lMageCastData62;
	long	lMageCastData70;

	bool	bOnlyEnemy;
	bool	bOnlyTarget;

	int		iLastDurabilityL;
	int		iLastDurabilityR;

	bool	bFormLoaded;

	int		iLastChestTick;

	bool	bPriestMembers[8];
	bool	bPriestHeal;
	int		iHealType;
	int		iHealCastIndex;
	int		iHealLimit;
	bool	bHealLessHPFirst;
	bool	bBuff;
	bool	bAC;
	bool	bResist;
	int		iBuffCastIndex;
	int		iACCastIndex;
	int		iResistCastIndex;
	bool	bGroupHeal;
	bool	bRestore;
	int		iGroupCastIndex;
	int		iRestoreCastIndex;
	bool	bMalice;
	bool	bParasite;
	bool	bTorment;
	bool	bMassive;
	bool	bChatHeal;
	bool	bChatBuff;
	bool	bChatAC;
	bool	bChatResist;
	bool	bSitWhenIdle;
	bool	bPriAutoCure;
	bool	bPriAutoSTR;
	bool	bPriAutoBook;
	bool	bPriestPaused;

	int		iLastHealTick;
	int		iLastBuffTick;
	int		iLastACTick;
	int		iLastResistTick;
	int		iLastGroupTick;
	int		iLastRestoreTick;
	int		iLastMaliceTick;
	int		iLastParasiteTick;
	int		iLastTormentTick;
	int		iLastMassiveTick;
	int		iLastPriCureTick;
	int		iLastPriDiseaseTick;
	int		iLastPriSTRTick;
	int		iLastPriBookTick;

	int		iLastUserMaxHP[8];
	int		iLastBuffedUserTick[8];
	bool	bUserWaitingForNewHP[8];
	int		iLastRestoredUserTick[8];

	bool	bPriPrintName;
	bool	bUndyForWarriors;

	DWORD	dwPriHealCastNum;
	DWORD	dwPriBuffCastNum;
	DWORD	dwPriACCastNum;
	DWORD	dwPriResistCastNum;
	DWORD	dwPriGroupCastNum;
	DWORD	dwPriRestoreCastNum;
	DWORD	dwPriCureCastNum;
	DWORD	dwPriDiseaseCastNum;
	DWORD	dwPriSTRCastNum;
	DWORD	dwPriUndyCastNum;

	bool	bHealCastArray[8];
	DWORD	dwHealCastArray[8];

	bool	bRAttack;
	bool	bRunToMob;
	int		iRunDist;
	bool	bRock;
	bool	bAsasPercent5;
	bool	bAsasPercent10;
	bool	bBinding;
	bool	bProvoke;
	bool	bPriestAttack;
	int		iPriestAttackType;
	bool	bLightStrike;
	bool	bLightCounter;
	bool	bBrightness;
	bool	bCriticalLight;
	bool	bLightAttack;
	bool	bSTR30;
	bool	bAsasAttack;
	bool	bDebuff;

	bool	bSprintWarrior;
	bool	bDefenseWarrior;
	bool	bGainWarrior;

	bool	bAsasCastArray[9];
	DWORD	dwAsasCastArray[9];
	int		iLastAsasCastTick[9];

	int		iLastAsasAttackTick;
	int		iLastRockTick;
	WORD	wLastRockTarget;

	int		iBotCenterX;
	int		iBotCenterY;

	int		iLastRAttackTick;

	DWORD	dwPercent10Num;
	DWORD	dwPercent5Num;

	int		iLastPercent10Tick;
	int		iLastPercent5Tick;

	DWORD	dwWarriorCastArray[18];
	int		iWarriorCastIndex;
	DWORD	dwBindingCastNum;
	DWORD	dwProvokeCastNum;

	int		iLastWarriorAttackTick;
	int		iLastBindingTick;
	int		iLastProvokeTick;
	WORD	wLastBindingTarget;

	int		iLastDefenseTick;
	int		iLastGainTick;

	bool	bWarriorAttack;

	bool	bPriestCastArray[8];
	DWORD	dwPriestCastArray[8];
	int		iLastPriestCastTick[8];
	int		iPriestCastIndex;
	int		iLastPriestAttackTick;
	DWORD	dwPriestSTR30CastNum;
	int		iLastPriestSTR30Tick;

	int		iLastPriestFarCastTick[5];
	DWORD	dwPriestFarCastArray[5];

	int		iLastPriestDebuffTick[4];
	DWORD	dwPriestDebuffArray[4];
	int		iLastPriestDebuffCastTick;

	int		iPriestMyLastRestoreTick;
	int		iPriestMyLastBuffTick;
	int		iPriestMyLastACTick;
	int		iPriestMyLastResistTick;
	int		iPriestMyLastSTRTick;

	int		iPriestHealLockIndex;

	bool	bMoveChestPaused;
	bool	bRunMobPaused;

	bool	bBotState;
	bool	bArcheryAttack;

	bool	bAutoRevive;

	bool	bAutoSell;
	bool	bSellSlotLimit;
	int		iSellBeginSlot;
	bool	bSellPriceLimitAbove;
	int		iSellPriceLimitAbove;
	bool	bSellPriceLimitLess;
	int		iSellPriceLimitLess;

	bool	bSellWaitForRPR;
	bool	bRouteSH;
	bool	bStunChar;

	int		iMinorLimit;

	float	fLastMovedX;
	float	fLastMovedY;

	bool	bBuyTS;
	bool	bBuyBook;
	bool	bBuyRock;
	int		iBuyTS;
	int		iBuyBook;
	int		iBuyRock;

	bool	bArcheryCastArray[20];
	DWORD	dwArcheryCastArray[20];
	int		iArcheryCastArray[20];
	DWORD	dwCastNum_Blow;
	bool	bBlow;

	bool	bMageBasicCastArray[5];
	DWORD	dwMageBasicCastArray[5];
	int		iMageBasicCastArray[5];
	int		iMageBasicDataArray[5];

	bool	bMageFlameCastArray[17];
	DWORD	dwMageFlameCastArray[17];
	int		iMageFlameCastArray[17];
	int		iMageFlameDataArray[17];

	bool	bMageIceCastArray[17];
	DWORD	dwMageIceCastArray[17];
	int		iMageIceCastArray[17];
	int		iMageIceDataArray[17];

	bool	bMageLightCastArray[17];
	DWORD	dwMageLightCastArray[17];
	int		iMageLightCastArray[17];
	int		iMageLightDataArray[17];

	bool	bMageAttack;

	int		iWentToChestTime;
	bool	bOnChestWay;

	int		iLastArcheryBonusTick;

	bool	bFarChest;

	bool	bRingOnDC;
	bool	bCloseOnDC;

	bool	bFollowPaused;

	bool	bBuyMaster;
	int		iBuyMaster;

	bool 	bSuspendTurn;
	HANDLE	hGameThread;

	char*	strAddList[20];
	int		iAddCount;

	THREADENTRY32	pThreadArray[8];
	HANDLE			hThreadArray[8];

	HMENU	hMainMenu;
	int		iActiveMin;

	WNDPROC dwSelfWndProc;
	WNDPROC dwGameWndProc;

	DWORD dwLastTPTPacketTick;

	bool	bNoTrade;
	bool	bNoParty;
	bool	bNoCombat;

	__fastcall TfrmBot(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBot *frmBot;
//---------------------------------------------------------------------------
#endif
