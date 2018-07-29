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
	TServerSocket *CustomerServer;
	TServerSocket *MinerServer;
	TServerSocket *ServerSocket3;
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TClientSocket *ClientSocket1;
	TClientSocket *ClientSocket2;
	TListBox *ListBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall MinerServerClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall CustomerServerClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
