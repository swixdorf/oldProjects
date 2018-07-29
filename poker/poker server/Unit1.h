//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <ScktComp.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TCheckBox *CheckBox1;
	TButton *Button2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TLabel *Label3;
	TServerSocket *BootServer;
	TDBGrid *DBGrid1;
	TTable *CharTable;
	TDataSource *DataSource1;
	TIntegerField *CharTableSURE;
	TIntegerField *CharTableBAGLI;
	TStringField *CharTableKEY;
	TIntegerField *CharTableZAMAN;
	TIntegerField *CharTableSOCKETNO;
	TDateField *CharTableKAYITZAMAN;
	TIntegerField *CharTableKALANGUN;
	TEdit *Edit1;
	TLabel *Label1;
	TRadioGroup *RadioGroup1;
	TMemo *Memo2;
	TButton *Button1;
	TButton *Button3;
	TTable *KeyIsle;
	TDataSource *DataSource2;
	TStringField *KeyIsleBAYIID;
	TIntegerField *KeyIsleSURE;
	TStringField *KeyIsleKEY;
	TDateField *KeyIsleKAYITZAMAN;
	TIntegerField *KeyIsleSATILDI;
	TDateField *KeyIsleSATILDIZAMAN;
	TButton *URET;
	TDBGrid *DBGrid2;
	TServerSocket *BootServerKayit;
	TLabel *Label2;
	TEdit *Edit2;
	TApplicationEvents *ApplicationEvents1;
	TStringField *CharTableBAYIID;
	TButton *Button4;
	TStringField *CharTableIDKON;
	TStringField *CharTableID;
	TButton *Button5;
	void __fastcall BootServerClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CharTableCalcFields(TDataSet *DataSet);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall URETClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BootServerKayitClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ApplicationEvents1Exception(TObject *Sender, Exception *E);
	void __fastcall CharTableAfterPost(TDataSet *DataSet);
	void __fastcall KeyIsleAfterPost(TDataSet *DataSet);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
