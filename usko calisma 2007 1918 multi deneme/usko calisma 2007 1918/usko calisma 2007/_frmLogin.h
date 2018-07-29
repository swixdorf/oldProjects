//---------------------------------------------------------------------------

#ifndef _frmLoginH
#define _frmLoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <ComCtrls.hpp>

#include "_frmBot.h"

extern bool bGameLoaded;

void BanTrialID();

//---------------------------------------------------------------------------
class TfrmLogin : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pageMain;
	TTabSheet *tabLogin;
	TTabSheet *tabRegister;
	TGroupBox *grpLogin;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *txtloginid;
	TEdit *txtloginpw;
	TButton *btnLogin;
	TGroupBox *grpregister;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *txtKey;
	TEdit *txtregisterid;
	TEdit *txtregisterpw;
	TEdit *txtregisterpw2;
	TButton *btnRegister;
	TTabSheet *tabadd;
	TGroupBox *GroupBox1;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *txtaddkey;
	TEdit *txtaddid;
	TEdit *txtaddpw;
	TButton *btnAdd;
	TCheckBox *chload;
	TButton *btntrial;
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnRegisterClick(TObject *Sender);
	void __fastcall btnAddClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall chloadClick(TObject *Sender);
	void __fastcall btntrialClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
#endif
