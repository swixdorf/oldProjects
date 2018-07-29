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
  TFileStream *ff ;
    HANDLE Myfile;
  unsigned long  aFileSize  ;
  bool calisiyor;
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TTimer *Timer1;
	TServerSocket *ServerSocket1;
	TGroupBox *GroupBox1;
	TLabel *Label11;
	TLabel *Label12;
	TShape *Shape1;
	TLabel *Label13;
	TEdit *Edit2;
	TButton *Button1;
	TGroupBox *GroupBox2;
	TLabel *Label10;
	TLabel *Label1;
	TLabel *Label2;
	TShape *Shape2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit3;
	TClientSocket *ClientSocket1;
	TButton *Button2;
	TButton *Button3;
	TTimer *Timer2;
	TButton *Button4;
	TTimer *Timer3;
	TMemo *Memo2;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall HSServerClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall HSClinetError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	BYTE HsSend[1024];
	DWORD HsLen;
	String Path;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
