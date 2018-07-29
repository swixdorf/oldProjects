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

WINAPI msg(int a){
Form1->Memo1->Lines->Add(a);
}
islem(int param){
BYTE asd = param;
asm{
	 mov edx,0
	 mov     dl, asd

	 and     edx, 20h

	 test    edx, edx

	 jz      loc_100996E6
	 push 0
	 call msg
	 loc_100996E6:
	 mov edx,0
	 mov     dl, asd

	 and     edx, 1h

	 test    edx, edx

	 jz      loc_1009981A
		 push 1
	 call msg
	 loc_1009981A:
		 mov edx,0
	 mov     dl, asd

	 and     edx, 10h

	 test    edx, edx

	 jz      loc_10099A24
		 push 2
	 call msg
	 loc_10099A24:
			 mov edx,0
	 mov     dl, asd

	 and     edx, 2h

	 test    edx, edx

	 jz      loc_10099B9F
		 push 3
	 call msg
	 loc_10099B9F:
				 mov edx,0
	 mov     dl, asd

	 and     edx, 4h

	 test    edx, edx

	 jz      loc_10099CF8
		 push 4
	 call msg
	 loc_10099CF8:
					 mov edx,0
	 mov     dl, asd

	 and     edx, 8h

	 test    edx, edx

	 jz      loc_10099E2E
		 push 5
	 call msg
	 loc_10099E2E:
						 mov edx,0
	 mov     dl, asd

	 and     edx, 40h

	 test    edx, edx

	 jz      loc_1009A02E
		 push 6
	 call msg
	 loc_1009A02E:

}
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
islem(0x58);
}
//---------------------------------------------------------------------------
