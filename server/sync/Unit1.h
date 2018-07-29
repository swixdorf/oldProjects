//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDatabase *Database1;
	TQuery *Query1;
	TSession *Session1;
	TQuery *Query2;
	TDatabase *Database2;
	TSession *Session2;
	TMemo *Memo1;
	TButton *Connect;
	TMemo *dbs;
	TButton *UserCount;
	TButton *UnUsedCode;
	TButton *Disconnect;
	void __fastcall ConnectClick(TObject *Sender);
	void __fastcall DatabaseBeforeConnect(TObject *Sender);
	void __fastcall DatabaseAfterConnect(TObject *Sender);
	void __fastcall DatabaseAfterDisconnect(TObject *Sender);
	void __fastcall DatabaseBeforeDisconnect(TObject *Sender);
	void __fastcall UserCountClick(TObject *Sender);
	void __fastcall UnUsedCodeClick(TObject *Sender);
	void __fastcall DisconnectClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
