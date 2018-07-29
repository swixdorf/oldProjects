//----------------------------------------------------------------------------
#ifndef _dlgCZH
#define _dlgCZH
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
//----------------------------------------------------------------------------
class TdlgCZ : public TForm
{
__published:
	TGroupBox *grpsuicide;
	TCheckBox *chsuicide1;
	TCheckBox *chsuicide2;
	TEdit *txtsuicidelimit;
	TGroupBox *grpflee;
	TCheckBox *chflee;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TListBox *lstflee;
	TButton *btnfleeadd;
	TButton *btnfleeclear;
	TLabel *Label4;
	TEdit *txtfleewait;
	TCheckBox *chfleetown;
	TCheckBox *chfleering;
	TButton *btnclose;
	void __fastcall btncloseClick(TObject *Sender);
private:
public:

	bool bSuicideOnEnemy;
	bool bSuicideOnLimit;
	int	iSuicideLimit;
	bool bFlee;
	int iFleeWait;
	bool bFleeTown;
	bool bFleeRing;
	int iFleeX[20];
	int iFleeY[20];
	int iFleeCount;

	virtual __fastcall TdlgCZ(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TdlgCZ *dlgCZ;
//----------------------------------------------------------------------------
#endif    
