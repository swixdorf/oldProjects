//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "swxpatch.h"
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
DWORD StartAddr;
DWORD EndAddr;
DWORD Size;
DWORD EIP;
void __fastcall TForm1::convClick(TObject *Sender)
{
for (int i = 0; i < ListBox1->Items->Count; i++)
{
String Line = ListBox1->Items->Strings[i];
DWORD EIPbuffer =  StrToInt("0x"+ Line.SubString(5,8));
if (i == 0) {
StartAddr = EIPbuffer;
EndAddr = StrToInt("0x"+ ListBox1->Items->Strings[ListBox1->Items->Count-1].SubString(5,8));
Size = EndAddr -StartAddr;
Memo1->Lines->Add(IntToHex((int)StartAddr,8));
Memo1->Lines->Add(IntToHex((int)EndAddr,8));
Memo1->Lines->Add(Size);
char charbuffer[100];
wsprintf(charbuffer,"DWORD adr = (DWORD) malloc(%d);DWORD MyCall = adr;memcpy( (LPVOID)adr, (LPVOID)0x%d, 128 );",Size,StartAddr);
ListBox2->Items->Add(charbuffer);
/*	DWORD adr = (DWORD) malloc(128);
	MyZPatchCall=adr;
	memcpy( (LPVOID)adr, (LPVOID)SetZPatch, 128 );

EIPbuffer     */
}
if (EIP != EIPbuffer) {
EIP = EIPbuffer;
if (ListBox1->Items->Strings[i].AnsiPos("call")!=0)
{
DWORD Relatif = EIP -StartAddr+1;
char charbuffer[100];
wsprintf(charbuffer,"int a = *(int*)(adr+%d);a-=fark;*(DWORD*)(adr+%d)=a;",Relatif,Relatif);
ListBox2->Items->Add(charbuffer);
}
}

}
ListBox2->Items->SaveToFile("out.txt");
}
//---------------------------------------------------------------------------



