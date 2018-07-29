//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <CheckLst.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <vector>
//---------------------------------------------------------------------------
extern char DLLPATH[MAX_PATH];

bool   TipNe();
DllYukle();

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
