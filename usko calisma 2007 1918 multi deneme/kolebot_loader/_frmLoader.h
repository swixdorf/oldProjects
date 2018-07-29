//---------------------------------------------------------------------------

#ifndef _frmLoaderH
#define _frmLoaderH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Tlhelp32.h"
#include <ScktComp.hpp>
#include <CheckLst.hpp>
#include <FileCtrl.hpp>
#define _WIN32_WINNT  0x0501
#include "Windows.h"
#include "Winternl.h"
#include "Psapi.h"

extern char* DLLNAME;
extern char* strWebAddress;

extern char* strKODIR;

extern char strKOWND[25];
extern long lLastTick;

extern DWORD dwDebugAPI;

void HandleProcess();
void LoadProcess(bool multi);
void ClearLogFiles();

const DWORD KO_WNDA = 	0x00AFFEBC;
const DWORD KO_APRA =	0xC53E2C;//
const DWORD KO_APRB =	0xC53E3C;//
//const DWORD KO_APRC =	0xC44EE4;//

void StrEncrypt(char* pStr, BYTE bUseKey);
void StrDecrypt(char* pStr);

void GamePatch(HANDLE hProcess);

void CheckDLL();
void CheckDebugger();

bool CheckCommandLine();
void EditDbgBreakPoint();

void MakeRandomCaption();

extern bool bCheckDebugEntry;

//---------------------------------------------------------------------------
class TfrmLoader : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *webMain;
	TPageControl *pageMain;
	TTabSheet *tabauto;
	TOpenDialog *dlgPath;
	TLabel *Label1;
	TEdit *txtPath;
	TLabel *Label2;
	TRadioButton *oprandom;
	TRadioButton *opmanual;
	TEdit *txtmanualwnd;
	TButton *btnLoad2;
	TTabSheet *tabotologin;
	TCheckBox *chotologin;
	TLabel *Label3;
	TEdit *txtgameid;
	TLabel *Label4;
	TEdit *txtgamepw;
	TEdit *txtbotid;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *txtbotpw;
	TLabel *Label7;
	TRadioButton *opleft;
	TRadioButton *opcenter;
	TRadioButton *opright;
	TLabel *Label8;
	TLabel *Label9;
	TComboBox *comserverlist;
	TComboBox *comserverno;
	TTimer *tmautologin;
	TCheckBox *chtrial;
	TTrayIcon *tray;
	TTimer *tmdebugger;
	TWebBrowser *WebBrowser2;
	TWebBrowser *WebBrowser3;
	TWebBrowser *WebBrowser4;
	TButton *Button1;
	TTimer *Timer1;
	TTimer *Timer2;
	TButton *btnsave;
	TButton *Button2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TMemo *Memo1;
	TOpenDialog *OpenDialog1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TCheckListBox *CheckListBox1;
	TButton *Button3;
	TButton *Button4;
	TFileListBox *FileListBox1;
	TMemo *Memo2;
	TButton *Button5;
	TCheckBox *CheckBox1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnLoad2Click(TObject *Sender);
	void __fastcall tmautologinTimer(TObject *Sender);
	void __fastcall chtrialClick(TObject *Sender);
	void __fastcall btnsaveClick(TObject *Sender);
	void __fastcall trayClick(TObject *Sender);
	void __fastcall tmdebuggerTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall pageMainChange(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmLoader(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLoader *frmLoader;
//---------------------------------------------------------------------------
#endif
