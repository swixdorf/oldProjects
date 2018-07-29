//----------------------------------------------------------------------------
#ifndef fdlgBlH
#define fdlgBlH
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
class TdlgBl : public TForm
{
__published:
	TBevel *pnBlAdd;
	TButton *btnOk;
	TListBox *lstBladd;
	TEdit *txtname;
	TButton *btnadd;
	TButton *btnclear;
	TButton *btnaddselected;
	TCheckBox *chbltown;
	TCheckBox *chbldc;
	TCheckBox *chpmcontrol;
	void __fastcall btnaddselectedClick(TObject *Sender);
	void __fastcall btnaddClick(TObject *Sender);
	void __fastcall btnclearClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall chbltownClick(TObject *Sender);
	void __fastcall chbldcClick(TObject *Sender);
	void __fastcall chpmcontrolClick(TObject *Sender);
private:
public:
	bool bAccept;
	bool bRequest;
	virtual __fastcall TdlgBl(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TdlgBl *dlgBl;
//----------------------------------------------------------------------------
#endif    
