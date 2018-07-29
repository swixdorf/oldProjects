//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ffrmJail.h"
#include "ffrmBot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmJail *frmJail;
//---------------------------------------------------------------------------
__fastcall TfrmJail::TfrmJail(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmJail::chJailActiveClick(TObject *Sender)
{
frmBot->btnbotcenterClick(0);
frmBot->iBotCenterX=130;
frmBot->iBotCenterY=130;
frmBot->oplistmob->Checked=true;
frmBot->chshowmob->Checked=true;
frmBot->chwaitforkill->Checked=true;
frmBot->chrattack->Checked=true;
frmBot->chrunmob->Checked=true;
frmBot->txtrundist->Text=100;
frmBot->iRTimer=1500;
if (chJailActive->Checked) {
memJailMonsterCount->Enabled=false;
	tmJailRefresh->Enabled=true;
}else{
memJailMonsterCount->Enabled=true;
	tmJailRefresh->Enabled=false;
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmJail::tmJailRefreshTimer(TObject *Sender)
{
frmBot->btnclearmobClick(0);
frmBot->oplistmobClick(0);
for (int i = 0; i < lbJailName->Items->Count; i++) {
if (frmBot->iJailCount[i]<txtJailMax->Text.ToIntDef(10)) {
frmBot->txtatakmob->Text=lbJailName->Items->Strings[i];
frmBot->btnaddmobClick(0);
}    
}
int kalanvurus = ((_CCharBase.GetDWORD(KO_CRMP)*100)/_CCharBase.GetDWORD(KO_MXMP))/5;
int npckalanvurus =999;
if(_CCharBase.IsSit()){
if (_CCharBase.GetTargetID()!=0xffff){
CCharBase target;
target.SetBase(_CArea.GetNPCBase(_CCharBase.GetTargetID()));
npckalanvurus=target.GetDWORD(KO_CRHP);
}
if ((kalanvurus>npckalanvurus)||(kalanvurus>18)) {
memoJailLog->Lines->Add("Char Kalkti");
_CTest.CommandSit(false);
}
}else{
 if (kalanvurus<1) {
memoJailLog->Lines->Add("Char Oturdu");
_CTest.CommandSit(true);
}
    }



for (int i = 0; i < 4; i++) {
	memJailMonsterCount->Lines->Strings[i] = frmBot->iJailCount[i];    
}
CCharBase target;

if (_CCharBase.GetTargetID()==0xffff) return;
if (_CCharBase.GetTargetID()==0) return;
target.SetBase(_CArea.GetNPCBase(_CCharBase.GetTargetID()));


}
//---------------------------------------------------------------------------
bool degisti;

void __fastcall TfrmJail::clearClick(TObject *Sender)
{
lbJailName->Items->Clear();	
}
//---------------------------------------------------------------------------
void __fastcall TfrmJail::memJailMonsterCountChange(TObject *Sender)
{
if (memJailMonsterCount->Enabled) {
for (int i = 0; i < memJailMonsterCount->Lines->Count; i++) {
	frmBot->iJailCount[i]=memJailMonsterCount->Lines->Strings[i].ToIntDef(0);
}	
}

}
//---------------------------------------------------------------------------
void __fastcall TfrmJail::lbJailMonsterDblClick(TObject *Sender)
{
if (lbJailName->Items->Count>3) {
	return;
}

lbJailName->Items->Add(lbJailMonster->Items->Strings[lbJailMonster->ItemIndex]);	
}
//---------------------------------------------------------------------------
