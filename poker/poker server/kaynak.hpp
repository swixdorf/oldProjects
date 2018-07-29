// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Kaynak.pas' rev: 11.00

#ifndef KaynakHPP
#define KaynakHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Shdocvw.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Olectrls.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Kaynak
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall WB_SaveHTMLCode(Shdocvw::TWebBrowser* WebBrowser, const AnsiString FileName);
extern PACKAGE bool __fastcall WB_GetHTMLCode(Shdocvw::TWebBrowser* WebBrowser, Classes::TStrings* ACode);

}	/* namespace Kaynak */
using namespace Kaynak;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Kaynak
