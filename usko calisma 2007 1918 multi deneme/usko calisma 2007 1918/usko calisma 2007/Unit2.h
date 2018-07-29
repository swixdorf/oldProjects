//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
extern char DLLPATH[MAX_PATH];
extern HINSTANCE hInstance;
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *HSServer;
	TClientSocket *HSClinet;
	TMemo *Memo1;
	TButton *Button1;
	TTimer *Timer1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HSServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall HSClinetError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
