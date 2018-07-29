//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "_dlgCZ.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgCZ *dlgCZ;
//--------------------------------------------------------------------- 
__fastcall TdlgCZ::TdlgCZ(TComponent* AOwner)
	: TForm(AOwner)
{
	bSuicideOnEnemy	=	false;
	bSuicideOnLimit	=	false;
	iSuicideLimit	=	25;
	bFlee			=	false;
	iFleeWait		=	20;
	bFleeTown		=	false;
	bFleeRing		=	false;
	iFleeCount		=	0;
}
//---------------------------------------------------------------------
void __fastcall TdlgCZ::btncloseClick(TObject *Sender)
{
	this->Hide();
}
//---------------------------------------------------------------------------

