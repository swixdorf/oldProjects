//----------------------------------------------------------------------------
#ifndef fdlgAdditionH
#define fdlgAdditionH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ScktComp.hpp>
//----------------------------------------------------------------------------
class TdlgAddition : public TForm
{
__published:
	TGroupBox *grpbdw;
	TButton *btngetmonuid;
	TLabel *lbmonu;
	TButton *btngetmonu;
	TCheckBox *chautomonu;
	TButton *btnclose;
	TTimer *tmmonu;
	TGroupBox *grpchaos;
	TCheckBox *chdisablesaw;
	TCheckBox *chlootcubes;
	TTimer *tmlootcubes;
	TTimer *tmchaoscheck;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TButton *Button1;
	TServerSocket *ServerSocket1;
	TClientSocket *ClientSocket1;
	TButton *Button2;
	TMemo *Memo1;
	TCheckBox *CheckBox1;
	TMemo *Memo2;
	TListBox *ListBox1;
	TTimer *Timer1;
	TCheckBox *CheckBox2;
	TGroupBox *GroupBox1;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button3;
	TCheckBox *CheckBox3;
	TEdit *Edit5;
	TButton *Button4;
	TEdit *Edit6;
	TButton *Button5;
	TMemo *Memo3;
	TTimer *Timer2;
	void __fastcall btncloseClick(TObject *Sender);
	void __fastcall btngetmonuidClick(TObject *Sender);
	void __fastcall btngetmonuClick(TObject *Sender);
	void __fastcall chautomonuClick(TObject *Sender);
	void __fastcall tmmonuTimer(TObject *Sender);
	void __fastcall chdisablesawClick(TObject *Sender);
	void __fastcall chlootcubesClick(TObject *Sender);
	void __fastcall tmchaoscheckTimer(TObject *Sender);
	void __fastcall tmlootcubesTimer(TObject *Sender);
	void __fastcall FormDblClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SendOtherClient(BYTE *komut,BYTE size);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Memo2Change(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
private:
public:
	DWORD dwMonuID;
	bool  bDisableSaw;
	virtual __fastcall TdlgAddition(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TdlgAddition *dlgAddition;
//----------------------------------------------------------------------------
#endif    
