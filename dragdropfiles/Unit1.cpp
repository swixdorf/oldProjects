//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall TForm1::WmDropFiles(TWMDropFiles& Message)
{
  char buff[MAX_PATH];
  volatile int x = -1;
  HDROP hDrop = (HDROP)Message.Drop;
  int numFiles = DragQueryFile(hDrop, -1, NULL, NULL);
  ListBox1->Items->Clear();
  for (int i=0;i < numFiles;i++) {
    DragQueryFile(hDrop, i, buff, sizeof(buff));
    if (numFiles == 1) 
	  ListBox1->Items->LoadFromFile(buff);
	else
	  ListBox1->Items->Add(buff);
  }
  DragFinish(hDrop);
}
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  DragAcceptFiles(Handle, true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
for (int i = 0; i < ListBox1->Items->Count; i++) {
	String name =     ExtractFileName(ListBox1->Items->Strings[i]);
	String path =      ExtractFilePath(ListBox1->Items->Strings[i]);
	//String buf = name.SubString(1,name.Length()-7) + ExtractFileExt(ListBox1->Items->Strings[i]);
	ListBox3->Items->LoadFromFile(ListBox1->Items->Strings[i]);
	for (int i = 0; i < ListBox3->Items->Count; i++) {
		if (ListBox2->Items->IndexOf(ListBox3->Items->Strings[i])==-1) {
			ListBox2->Items->Add(ListBox3->Items->Strings[i]);
		}
	}
    ListBox2->Items->SaveToFile("ex.txt");
	//ListBox2->Items->Add(buf);
	/*buf = path + "new\\"+ buf ;
	CopyFileA(ListBox1->Items->Strings[i].c_str(),buf.c_str(),false );   */
}
}
//---------------------------------------------------------------------------

