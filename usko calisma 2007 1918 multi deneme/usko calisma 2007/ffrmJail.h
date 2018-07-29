//---------------------------------------------------------------------------

#ifndef ffrmJailH
#define ffrmJailH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmJail : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox7;
	TTimer *tmJailRefresh;
	TCheckBox *chJailActive;
	TMemo *memoJailLog;
	TEdit *txtJailMax;
	TLabel *Label11;
	TListBox *lbJailName;
	TButton *clear;
	TMemo *memJailMonsterCount;
	TListBox *lbJailMonster;
	void __fastcall chJailActiveClick(TObject *Sender);
	void __fastcall tmJailRefreshTimer(TObject *Sender);
	void __fastcall clearClick(TObject *Sender);
	void __fastcall memJailMonsterCountChange(TObject *Sender);
	void __fastcall lbJailMonsterDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmJail(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmJail *frmJail;
//---------------------------------------------------------------------------
#endif
