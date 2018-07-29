//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TButton *tara;
	TButton *Button1;
	TButton *Button2;
	TGroupBox *GroupBox1;
	TEdit *Edit2;
	TMemo *Memo4;
	TButton *RaporAL;
	TEdit *raporgun;
	TGroupBox *GroupBox2;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TEdit *Edit4;
	TButton *Button3;
	TListBox *ListBox1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall taraClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
