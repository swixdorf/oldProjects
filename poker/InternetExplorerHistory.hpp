// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Internetexplorerhistory.pas' rev: 11.00

#ifndef InternetexplorerhistoryHPP
#define InternetexplorerhistoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Comobj.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Wininet.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Internetexplorerhistory
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
struct TSTATURL
{
	
public:
	unsigned cbSize;
	unsigned pwcsUrl;
	unsigned pwcsTitle;
	_FILETIME ftLastVisited;
	_FILETIME ftLastUpdated;
	_FILETIME ftExpires;
	unsigned dwFlags;
} ;
#pragma pack(pop)

__interface IEnumSTATURL;
typedef System::DelphiInterface<IEnumSTATURL> _di_IEnumSTATURL;
__interface  INTERFACE_UUID("{3C374A42-BAE4-11CF-BF7D-00AA006946EE}") IEnumSTATURL  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall Next(int celt, /* out */ void *elt, PLongint pceltFetched) = 0 ;
	virtual HRESULT __stdcall Skip(int celt) = 0 ;
	virtual HRESULT __stdcall Reset(void) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IEnumSTATURL &ppenum) = 0 ;
	virtual HRESULT __stdcall SetFilter(WideChar * poszFilter, unsigned dwFlags) = 0 ;
};

__interface IUrlHistoryStg;
typedef System::DelphiInterface<IUrlHistoryStg> _di_IUrlHistoryStg;
__interface  INTERFACE_UUID("{3C374A41-BAE4-11CF-BF7D-00AA006946EE}") IUrlHistoryStg  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall AddUrl(WideChar * pocsUrl, WideChar * pocsTitle, int dwFlags) = 0 ;
	virtual HRESULT __stdcall DeleteUrl(WideChar * pocsUrl, int dwFlags) = 0 ;
	virtual HRESULT __stdcall QueryUrl(WideChar * pocsUrl, int dwFlags, TSTATURL &lpSTATURL) = 0 ;
	virtual HRESULT __stdcall BindToObject(WideChar * pocsUrl, GUID &riid, /* out */ void * &ppvOut) = 0 ;
	virtual HRESULT __stdcall EnumUrls(/* out */ _di_IEnumSTATURL &ppenum) = 0 ;
};

__interface IUrlHistoryStg2;
typedef System::DelphiInterface<IUrlHistoryStg2> _di_IUrlHistoryStg2;
__interface  INTERFACE_UUID("{AFA0DC11-C313-11D0-831A-00C04FD5AE38}") IUrlHistoryStg2  : public IUrlHistoryStg 
{
	
public:
	virtual HRESULT __stdcall AddUrlAndNotify(WideChar * pocsUrl, WideChar * pocsTitle, int dwFlags, int fWriteHistory, void * &poctNotify, const System::_di_IInterface punkISFolder) = 0 ;
	virtual HRESULT __stdcall ClearHistory(void) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_CUrlHistory;
extern PACKAGE void __fastcall ClearInternetExplorerHistory(void);
extern PACKAGE void __fastcall DeleteIECache(void);

}	/* namespace Internetexplorerhistory */
using namespace Internetexplorerhistory;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Internetexplorerhistory
