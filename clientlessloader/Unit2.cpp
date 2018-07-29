//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
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

void __fastcall TForm2::Button1Click(TObject *Sender)
{
ListBox1->Items->Clear();
ListBox2->Items->Clear();
ListBox3->Items->Clear();
ListBox4->Items->Clear();
for  (int i = 0; i < Form1->CheckListBox1->Items->Count; i++)
{
if (Form1->CheckListBox1->Checked[i]) {
String filee = ExtractFilePath(Form1->CheckListBox1->Items->Strings[i]) + "item";
String filee2 = ExtractFilePath(Form1->CheckListBox1->Items->Strings[i]) + "count";
if (FileExists(filee)&&FileExists(filee2)) {
ListBox3->Items->LoadFromFile(filee);
ListBox4->Items->LoadFromFile(filee2);
for (int j = 0; j < ListBox3->Items->Count; j++) {
int a = ListBox1->Items->IndexOf(ListBox3->Items->Strings[j]);
if (a!=-1)
{
ListBox2->Items->Strings[a] = ListBox2->Items->Strings[a].ToIntDef(0) + ListBox4->Items->Strings[j].ToIntDef(0);
}else{
ListBox1->Items->Add(ListBox3->Items->Strings[j]);
ListBox2->Items->Add(ListBox4->Items->Strings[j]);
}
}
}
}
}
}

//---------------------------------------------------------------------------

