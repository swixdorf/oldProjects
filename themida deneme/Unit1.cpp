//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "ThemidaSDK.h"
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
int WINAPI logla(DWORD param){
Form1->Memo1->Lines->Add(IntToHex((int)param,8));
}
__declspec(naked)nakedproc()
{
asm{
mov eax,esp
push [eax]
call logla
ret
}
}
bool topla(){
int a  = 0x12345678;
int b  = 123123;
WORD c = 33;
CODEREPLACE_START
MessageBoxExA(NULL,"asd","asd",0,NULL);
nakedproc();

CODEREPLACE_END
MessageBoxExA(NULL,"bul","bul",0,NULL);
DWORD asd = 0x99999999;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
topla();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
LoadLibraryA("hs.dll");
}
//---------------------------------------------------------------------------

