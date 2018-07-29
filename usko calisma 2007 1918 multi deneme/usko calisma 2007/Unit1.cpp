//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Lines->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (Edit1->Text=="") {
ShowMessage("Dosya Adi Yazmalisiniz..") ;
return;

}
Memo1->Lines->SaveToFile(Edit1->Text);
}
//---------------------------------------------------------------------------
bool convertbufferandsend(String buf){
try {
if (buf.Length()<2) {
	return false;
}
int convertedlen = buf.Length()/2;
if (convertedlen*2!=buf.Length()) {
	return false;
}
BYTE Buffer[1024];
for (int i = 0; i < convertedlen; i++) {
BYTE bufnow = StrToIntDef("0x"+buf.SubString(i*2+1,2),0) ;
Buffer[i]=bufnow ;
}
_CPacket.PSend(Buffer,convertedlen);
} catch (...) {
	return false;
}
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
convertbufferandsend(Edit2->Text);
convertbufferandsend(Edit3->Text);
convertbufferandsend(Edit4->Text);
convertbufferandsend(Edit5->Text);
convertbufferandsend(Edit6->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
for (int i = 0; i < CheckListBox1->Items->Count; i++) {
loglanacak[i]=CheckListBox1->Checked[i];
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
logaktif=CheckBox1->Checked;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	*(DWORD*)(pBuf_RemoveSelf + 2) = 0x00077AAF;
									*(DWORD*)(pBuf_BuffSelf2 + 2) =  0x00077AAF;
									_CPacket.PSend(pBuf_RemoveSelf,24);
									_CPacket.PSend(pBuf_BuffSelf2,24);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
DWORD dwTarget = _CCharBase.GetTargetID();
BYTE Komut1[]={0x20,0x01,0x2C,0x53,0xFF,0xFF,0xFF,0xFF,};
*(WORD*)&Komut1[2] = dwTarget ;
_CPacket.PSend(Komut1,sizeof(Komut1));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
BYTE Komut1[]={0x55,0x00,0x0E,0x32,0x39,0x31,0x38,0x30,0x5F,0x4A,0x61,0x63,0x6B,0x2E,0x6C,0x75,0x61};
_CPacket.PSend(Komut1,sizeof(Komut1));
}
//---------------------------------------------------------------------------



