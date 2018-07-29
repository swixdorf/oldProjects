//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <Strutils.hpp>
#include <urlmon.h>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TClientSocket *ClientSocket1;
	TButton *Button2;
	TListBox *ServerlerListe;
	TComboBox *ServerlerListeIp;
	TButton *Button1;
	TMemo *Memo1;
	TMemo *Memo2;
	TListBox *MasaList;
	TCheckBox *CheckBox1;
	TListBox *ListBox1;
	TEdit *MasaBuy;
	TButton *Button3;
	TTimer *Timer1;
	TEdit *Edit1;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit2;
	TButton *Button6;
	TCheckListBox *CheckListBox1;
	TButton *Button7;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TEdit *Edit5;
	TButton *Button13;
	TMemo *Memo3;
	TMemo *Memo4;
	TMemo *Memo5;
	TMemo *Memo6;
	TMemo *Memo7;
	TMemo *Memo8;
	TMemo *Memo9;
	TMemo *Memo10;
	TButton *Button14;
	void __fastcall gir(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerlerListeIpChange(TObject *Sender);
	void __fastcall MasaListDblClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ServerlerListeClick(TObject *Sender);
	void __fastcall MasaBuyChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif