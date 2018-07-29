// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Multicpuexecution.pas' rev: 11.00

#ifndef MulticpuexecutionHPP
#define MulticpuexecutionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Multicpuexecution
{
//-- type declarations -------------------------------------------------------
typedef BOOL __stdcall (*TCpuSpecificFunction)(void * parameters);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall forspecificcpu(int cpunr, TCpuSpecificFunction functionpointer, void * parameters);
extern PACKAGE bool __fastcall foreachcpu(TCpuSpecificFunction functionpointer, void * parameters);

}	/* namespace Multicpuexecution */
using namespace Multicpuexecution;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Multicpuexecution
