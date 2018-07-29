//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String DbName = "bot_program";
int bankey (String esn){
if ((esn.Length()<12)) {
return 3;
}
TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=	DbName+"ses";
//Q->OnPostError= ErrorLogla;
Q->SQL->Clear();
String Query;
try {
String Query ="SELECT * FROM codes WHERE code_esn = '"+esn+"'";
Q->SQL->Add(Query) ;
Q->Open();

if (Q->RecordCount>0) {
String codeindex = Q->FieldByName("code_id")->Value;
String codetime	 = Q->FieldByName("code_time")->Value;

Q->Close();
Q->SQL->Clear();

Query ="UPDATE  codes SET code_active='2' WHERE code_id = '"+ codeindex +"'";
Q->SQL->Add(Query) ;
Q->ExecSQL();
Q->Close();
Q->SQL->Clear();
}

}catch(...){
return 0;
}
}



int keyControl(String esn){
int ret;
if ((esn.Length()<12)) {
return 5;
}
TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=	DbName+"ses";
//Q->OnPostError= ErrorLogla;
Q->SQL->Clear();
String Query;
try {
String Query ="SELECT * FROM codes WHERE code_esn = '"+esn+"'";
Q->SQL->Add(Query) ;
Q->Open();

if (Q->RecordCount>0) {
ret = Q->FieldByName("code_active")->Value;
Q->Close();
Q->SQL->Clear();
Q->Free();
return ret;
}else{
Q->Free();
return 5;
}
}catch(...){
Q->Free();
return 5;
}
}


void __fastcall TForm2::Button1Click(TObject *Sender)
{
Memo1->Lines->SaveToFile("1.txt");
Memo2->Lines->SaveToFile("2.txt");
Memo3->Lines->SaveToFile("3.txt");

}
//---------------------------------------------------------------------------
void __fastcall TForm2::taraClick(TObject *Sender)
{
 for (int i = 0; i < Memo1->Lines->Count; i++) {
 Application->ProcessMessages();
	Memo2->Lines->Add(IntToStr(keyControl(Memo1->Lines->Strings[i])));
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
 for (int i = 0; i < Memo1->Lines->Count; i++) {
 Application->ProcessMessages();

	bankey(Memo1->Lines->Strings[i]);
 }
 Memo3->Lines->Add("#ban done#")  ;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2Change(TObject *Sender)
{
DbName = Edit2->Text ;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{
ListBox1->Items->Clear();
TQuery *Q;
Q = new TQuery(NULL);
Q->DatabaseName= DbName;
Q->SessionName	=	DbName+"ses";
Q->SQL->Clear();
String Query;
try {
for (int i = 0; i < Edit3->Text.ToIntDef(0) ; i++) {
Q->Close();
Q->SQL->Clear();
String Query ="select * from codes where (code_time = "+Edit4->Text+")  and code_reseller= 10";
Q->SQL->Add(Query) ;
Q->Open();
if (Q->RecordCount>0) {
ListBox1->Items->Add(Q->FieldByName("code_esn")->Value);
int id =  Q->FieldByName("code_id")->Value;
Q->Close();
Q->SQL->Clear();
String Query ="UPDATE codes SET code_reseller='"+Edit1->Text+"' WHERE code_id='"+id+"';";
Q->SQL->Add(Query) ;
Q->ExecSQL();
}
}
Q->Close();
Q->SQL->Clear();
Q->Free();
}catch (...){
ShowMessage("eror");
Q->Close();
Q->SQL->Clear();
Q->Free();
}
DWORD a = GetTickCount();
Label4->Caption = a;
ListBox1->Items->SaveToFile(IntToStr(a)+".txt");
}
//---------------------------------------------------------------------------


