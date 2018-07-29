//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label5;
	TLabel *Label4;
	TEdit *Edit2;
	TEdit *Edit4;
	TButton *Button1;
	TLabel *Label6;
	TClientSocket *KOSocKay;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall KOSocKayConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall KOSocKayRead(TObject *Sender, TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	String Kontrol;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
