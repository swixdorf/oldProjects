//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *LoginServer;
	TMemo *log;
	TEdit *Edit1;
	TButton *Button1;
	void __fastcall LoginServerClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall LoginServerClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall LoginServerClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall Button1Click(TObject *Sender);




private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
