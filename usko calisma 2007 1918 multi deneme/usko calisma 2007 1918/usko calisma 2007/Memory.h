#ifndef MemoryH
#define MemoryH

#include <Classes.hpp>
#include "ThemidaSDK.h"
	//1917 melih
const DWORD KO_CHAR	=	0xD74C9C;//1918
const DWORD KO_DLGA =	0xD74D54;//1918
const DWORD KO_SOCK = 	0x00D74D20;//1918**
const DWORD KO_SNDF = 	0x48AFF0;//1918
const DWORD KO_SDFX = 	0xD74DEC;//1918
const DWORD KO_RCVA	=	0xAD9F88;//1918                 0x9EE150
const DWORD KO_RCVB	=	0x4E91C0;//1918             0x80B000
const DWORD KO_PRTY = 	0xD74D40;//1918
const DWORD KO_AREA = 	0xD74C98;//
const DWORD KO_FPOZ = 	0x5016F0;//
const DWORD KO_SETM = 	0x4C4910;//
const DWORD KO_FNCZ = 	0x4CAF60;//
const DWORD KO_CRYP = 	0x48A700;//
const DWORD KO_INDX =	0x47D4A0;//1918
const DWORD KO_WNDA = 	0xAF3A18;//1918
const DWORD KO_FPBS = 	0x49E9E0;//
const DWORD KO_FMBS = 	0x49FA10;//
const DWORD KO_RCFX = 	0xCEED20;//1918
const DWORD KO_NXTP = 	0x4992A0;//
const DWORD KO_NXTM = 	0x499310;//
const DWORD KO_MSBX = 	0x916410;//
const DWORD KO_MSOP = 	0x642EC0;//1918
const DWORD KO_DISC = 	0x48ACE0;//
const DWORD KO_CONN = 	0x31313131;//iptal
const DWORD KO_SCK2 = 	0xC1C924;//1918
const DWORD KO_THRD =	0xD74DD4;//1918
const DWORD KO_PFIX =	KO_SOCK+0xC5;
const DWORD KO_ITPA =	0xD74AE8;//0
const DWORD KO_ITPB =	0xD74AF0;//0
const DWORD KO_ITCA =	0x48EFB0;//0
const DWORD KO_ITCB =	0x48F020;//0
const DWORD KO_NPCB =	0x49E510;//
const DWORD KO_ISEN =	0x89FE10;//
const DWORD KO_LOCA =   0xD74C94;//1918
const DWORD KO_IPOS =   0x4CEAE0;//1918**
const DWORD KO_PSFN =   0xD74BAC;//1918**
const DWORD KO_CSFN =   0x4A2170;//1918**
const DWORD KO_INNC =   0x53BF60;//
const DWORD KO_CHKS =   0x31313131;//iptal
const DWORD KO_SITD =	0x31313131;  //iptal
const DWORD KO_PKTC =	0xD74DD2;//1918
const DWORD KO_CRP1 =	0xA0D8D0;//1918
const DWORD KO_CRP2 =	0xACF000;//1918
const DWORD KO_CRP3 =	0xA242A0;//1918
const DWORD KO_CRP4 =	0xA24089;   //           1918
const DWORD KO_APRA =	0;// 0xC53E1C
const DWORD KO_APRB =	0;//  0xC53E2C
const DWORD KO_QUIT =	0xAD5554;  //
const DWORD KO_ACID =	0x31313131;//iptal
const DWORD KO_INTR =	0xCEED24;//
const DWORD KO_CAST =	0x31313131;//iptal
const DWORD KO_PICK = 	0x505ED0;  //
const DWORD KO_HWND = 	0xC1C924;    //
const DWORD KO_API1 =	0x009E3344;    //0x9E2344
const DWORD KO_API2 =	0x009E32A0;      //0x9E22A0
const DWORD KO_API3 =	0x009E32F4;      //  0x9E22F4
const DWORD KO_API4 = 	0x009E3454;   //0x9E2454
const DWORD KO_API5 =	0x009E3408; //0x9E2408
const DWORD KO_API6 =	0x009E32E8;  //0x9E22E8
const DWORD KO_API7 =	0x009E3360;  //0x9E2360
const DWORD KO_TPT1 =	0x950000;
const DWORD KO_TPT2 =	0x955000;
const DWORD KO_LGN1	=	0xC47DF4;
const DWORD KO_LGN2 =	0xC4A170;
const DWORD KO_LGN3 =	0xC4A184;
const DWORD KO_LGN4 =	0x879FC0;
const DWORD KO_LGN5 =	0x87A8C0;
const DWORD KO_LGN6 =	0x89B840;//
const DWORD KO_LGN7 =	0x89B930;
const DWORD KO_LGN8 =	0x89C6E0;//
const DWORD KO_LGN9 =	0x89C3E0;//
const DWORD KO_LGN10 =	0x89B9B0;//
const DWORD KO_LGN11 =	0xC4A1F4;
const DWORD KO_LGN12 =	0x87E910;
const DWORD KO_LGN13 = 	0xC4A190;
const DWORD KO_LGN14 = 	0x885C80;//
const DWORD KO_LGN15 = 	0x885D10;//
const DWORD KO_LGN16 = 	0x8879E0;//
const DWORD KO_LGN17 = 	0xBFE37C;//


const DWORD KO_NICK = 	0x680; //
const DWORD KO_LEVL = 	0x6AC; //
const DWORD KO_CLSS = 	0x6A8; //
const DWORD KO_MYID = 	0x678; //
const DWORD KO_TGID = 	0x644; //
const DWORD KO_VELO = 	0x690; //iptal
const DWORD KO_AUTH =	0x6B8; //
const DWORD KO_CRHP = 	0x6B4; //
const DWORD KO_MXHP = 	0x6B0; //
const DWORD KO_CRMP =	0xAE0; //
const DWORD KO_MXMP = 	0xADC; //
const DWORD KO_CRXP = 	0x9E0; //iptal
const DWORD KO_MXXP = 	0x9D8; //iptal
const DWORD KO_POSX = 	0xD8; //
const DWORD KO_POSY = 	0xE0; //
const DWORD KO_POSZ = 	0xDC; //
const DWORD KO_COIN = 	0x820; //iptal
const DWORD KO_VISB = 	0x524; //iptal
const DWORD KO_NATN = 	0x6A0; //
const DWORD KO_PTRX = 	0xEF4; //
const DWORD KO_PTRY = 	0xEFC; //
const DWORD KO_PTRZ = 	0xEF8; //
const DWORD KO_MOV1 = 	0xEE8; //
const DWORD KO_MOV2 = 	0x3A4;
const DWORD KO_SIZE = 	0x400;
const DWORD KO_BSTN =	0xD38; //iptal
const DWORD KO_FSTN =	0xD3C; //iptal
const DWORD KO_ZONE =	0xB7C; //
const DWORD KO_CHST =	0x420;

const DWORD KO_PT_ID	=	0x8;
const DWORD KO_PT_HP  	=	0x14;
const DWORD KO_PT_MAXHP	=	0x18;
const DWORD KO_PT_MP  	=	0x1C;
const DWORD KO_PT_MAXMP	=	0x20;
const DWORD KO_PT_LVL 	=	0xC;
const DWORD KO_PT_CLASS	=	0x10;
const DWORD KO_PT_DISEASE	=	0x24;
const DWORD KO_PT_CURSE	=	0x25;
const DWORD KO_PT_NICK	=	0x30;

const DWORD KO_MINING	=	0x7D1;

//CGameProcMain offsets:
const DWORD OFF_MSG			=	0x1B0;
const DWORD OFF_STATEBAR	=	0x1B8;
const DWORD OFF_INVENTORY	=	0x1A0;
const DWORD OFF_WAREHOUSE	=	0x1EC;
const DWORD OFF_PARTY		=	0x1CC;
const DWORD OFF_SKILLTREE	=	0x1D0;


#endif
