//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "_dlgAddition.h"
#include "_frmBot.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgAddition *dlgAddition;
//--------------------------------------------------------------------- 
__fastcall TdlgAddition::TdlgAddition(TComponent* AOwner)
	: TForm(AOwner)
{
	dwMonuID = NULL;
}
//---------------------------------------------------------------------
void __fastcall TdlgAddition::btncloseClick(TObject *Sender)
{
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::btngetmonuidClick(TObject *Sender)
{
	DWORD dwTarget = _CCharBase.GetTargetID();

	if(dwTarget == NULL || (WORD)dwTarget == 0xFFFF)
		return;

	dwMonuID = dwTarget;
	char tmp[16]; memset(tmp,0,16);

	itoa(dwMonuID,tmp,10);
	lbmonu->Caption = tmp;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::btngetmonuClick(TObject *Sender)
{
	char pSend[4];
	*pSend = 0x85;
	*(pSend + 1) = 0x01;
	*(WORD*)(pSend + 2) = (WORD)dwMonuID;
	_CPacket.PSend(pSend,4);

	*(pSend + 1) = 0x02;
	_CPacket.PSend(pSend,4);
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::chautomonuClick(TObject *Sender)
{
	tmmonu->Enabled = chautomonu->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::tmmonuTimer(TObject *Sender)
{
	if(CheckLoading() == true)
		return;

	if(_CCharBase.GetDWORD(KO_CRHP) == 0)
		return;

	if(dwMonuID == NULL)
		return;

	CCharBase pMonu = _CArea.GetAnyBase(dwMonuID);
	if(pMonu.GetBase() == 0)
		return;

	char pSend[4];
	*pSend = 0x85;
	*(pSend + 1) = 0x01;
	*(WORD*)(pSend + 2) = (WORD)dwMonuID;

	if(pMonu.GetDWORD(KO_NATN) != _CCharBase.GetDWORD(KO_NATN))
	{
		_CPacket.PSend(pSend,4);
		*(pSend + 1) = 0x02;
		_CPacket.PSend(pSend,4);
    }
}
//---------------------------------------------------------------------------

