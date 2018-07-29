//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "TSyncListBox1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

//---------------------------------------------------------------------------
__fastcall TSyncListBox1::TSyncListBox1(TComponent* Owner)
	: TCustomListBox(Owner)
{
}
//---------------------------------------------------------------------------
namespace TSyncListBox1
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TSyncListBox1)};
		RegisterComponents("Samples", classes, 0);
	}
}
//---------------------------------------------------------------------------
