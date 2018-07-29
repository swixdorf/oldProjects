//---------------------------------------------------------------------------

#ifndef SocketFormH
#define SocketFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <Sockets.hpp>



//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ServerlerListeIp;
	TButton *Button1;
	TTimer *RelogTime;
	TPanel *Panel6;
	TLabel *ToplamPara;
	TLabel *MasaParaLabel;
	TLabel *CiftKart;
	TLabel *Label9;
	TLabel *Label1;
	TLabel *Kart1;
	TLabel *Kart2;
	TLabel *Kart3;
	TLabel *Kart4;
	TLabel *Kart5;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *MTime;
	TPanel *Panel1;
	TComboBox *MasaListe;
	TButton *Button10;
	TPanel *Panel4;
	TLabel *Label7;
	TLabel *Label6;
	TLabel *Label8;
	TEdit *RePot;
	TEdit *MasaBuy;
	TComboBox *MinPlayer;
	TCheckBox *OtoOtur;
	TButton *Button11;
	TButton *Button12;
	TPanel *Panel5;
	TButton *Button7;
	TButton *Button8;
	TButton *Button6;
	TButton *Kalk;
	TButton *Otur;
	TButton *Button9;
	TButton *Button14;
	TButton *Button16;
	TCheckBox *MesajDur;
	TTimer *markTurnTime;
	TPanel *Panel2;
	TButton *Button4;
	TButton *Button5;
	TMemo *Memo3;
	TCheckBox *MesajLogla;
	TListBox *ServerlerListe;
	TListBox *ServerlerGezilecek;
	TButton *Button2;
	TButton *Button3;
	TComboBox *ServerlerListeGezilcekIp;
	TRadioGroup *OdaGirisSekli;
	TTcpClient *GirisServer1;
	TCheckBox *HizliOtur;
	TEdit *MesajAt1;
	TCheckBox *CiftMesaj;
	TTimer *GirisTime;
	TButton *Button13;
	TLabel *Label5;
	TLabel *Label10;
	TLabel *Label11;
	TListBox *PotList;
	TLabel *Label12;
	TEdit *Edit1;
	TButton *Button15;
	TButton *Button17;
	TLabel *Label13;
	TComboBox *ServerSayacList;
	TListBox *IdlerList;
	TLabel *Label14;
	TEdit *MesajSayiLimit;
	TMemo *MesajAt;
	TListBox *MasaList;
	TLabel *Label15;
	TListBox *MasaListNo;
	TButton *Button19;
	TCheckBox *CheckBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall GirisServerConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall GirisServerRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall KalkClick(TObject *Sender);
	void __fastcall markTurnTimeTimer(TObject *Sender);
	void __fastcall OturClick(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall RelogTimeTimer(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall GirisServer1Connect(TObject *Sender);
//  	void __fastcall GirisServer1Receive(TObject *Sender, BYTE *Buf, int &DataLen);
	void __fastcall GirisServer1Disconnect(TObject *Sender);
	void __fastcall GirisTimeTimer(TObject *Sender);
	void __fastcall GirisServer1Receive(TObject *Sender, PChar Buf, int &DataLen);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall MasaListClick(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	String GirisData ;
	String ArananOda;
};

class SocketThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall SocketThread(bool CreateSuspended);
};


//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
