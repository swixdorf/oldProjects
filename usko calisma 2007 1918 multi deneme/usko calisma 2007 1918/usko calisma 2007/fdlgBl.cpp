//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "fdlgBl.h"
#include "ffrmBot.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgBl *dlgBl;
//---------------------------------------------------------------------
__fastcall TdlgBl::TdlgBl(TComponent* AOwner)
	: TForm(AOwner)
{

}
//---------------------------------------------------------------------

void __fastcall TdlgBl::btnaddselectedClick(TObject *Sender)
{
	if(frmBot->iBlCount == 20)
		return;

	CCharBase pSelected = _CArea.GetUPCBase(_CCharBase.GetTargetID());

	if(pSelected.GetBase()){

		char *pNewName = new char [32];
		memset(pNewName,0,32);
		strcpy(pNewName,pSelected.GetName());
		frmBot->strBlList[frmBot->iBlCount] = pNewName;
		lstBladd->AddItem(pNewName,Sender);
		frmBot->iBlCount++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TdlgBl::btnaddClick(TObject *Sender)
{
	if(frmBot->iBlCount == 20)
		return;

	if(!txtname->Text.Length() || txtname->Text.Length() >= 32)
		return;

	char *pNewName = new char [32];
	memset(pNewName,0,32);
	strcpy(pNewName,txtname->Text.c_str());
	frmBot->strBlList[frmBot->iBlCount] = pNewName;
	lstBladd->AddItem(pNewName,Sender);
	frmBot->iBlCount++;
}
//---------------------------------------------------------------------------

void __fastcall TdlgBl::btnclearClick(TObject *Sender)
{
	if(!frmBot->iBlCount)
		return;

	lstBladd->Clear();

	for (int i = 0; i < 20; i++) {
		if(frmBot->strBlList[i])
			delete [] frmBot->strBlList[i];
		frmBot->strBlList[i] = NULL;
	}

	frmBot->iBlCount = 0;
}
//---------------------------------------------------------------------------


void __fastcall TdlgBl::btnOkClick(TObject *Sender)
{
	this->Hide();
}
//---------------------------------------------------------------------------




void __fastcall TdlgBl::chbltownClick(TObject *Sender)
{
	frmBot->bTownOnBl = chbltown->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TdlgBl::chbldcClick(TObject *Sender)
{
	frmBot->bDcOnBl = chbldc->Checked;
}
//---------------------------------------------------------------------------



void __fastcall TdlgBl::chpmcontrolClick(TObject *Sender)
{
frmBot->bPmControl = chpmcontrol->Checked;
}
//---------------------------------------------------------------------------


