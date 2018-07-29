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
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{

	char class_name[80];
	char title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
	Form1->Memo1->Lines->Add(title);
	Form1->Memo1->Lines->Add(class_name);
	return TRUE;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
EnumWindows(EnumWindowsProc, NULL);
}
//---------------------------------------------------------------------------
