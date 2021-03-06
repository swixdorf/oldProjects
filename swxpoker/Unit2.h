//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------



class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TWebBrowser *WebBrowser1;
	TTimer *Timer1;
	TClientSocket *ClientSocket1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	 SOCKET OynSocket;
	 typedef int (WINAPI* r_send)(SOCKET sock, BYTE* buf, int len, int flags);
r_send osend;

typedef int (WINAPI* r_recv)(SOCKET sock, BYTE* buf, int len, int flags);
r_recv orecv;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
