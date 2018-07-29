//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include "udis86.h"
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
enum {
	UDIS86_MODE = 64 /* 16, 32, or 64 */
};
void __fastcall TForm1::FormCreate(TObject *Sender)
{




	ud_t ud_obj;

	ud_init(&ud_obj);

	ud_set_input_file(&ud_obj, stdin);
	ud_set_mode(&ud_obj, UDIS86_MODE);
	ud_set_syntax(&ud_obj, UD_SYN_INTEL);

	while (ud_disassemble(&ud_obj)) {
		printf("\t%s\n", ud_insn_asm(&ud_obj));
	}

}
//---------------------------------------------------------------------------
