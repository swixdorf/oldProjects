// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Vmxfunctions.pas' rev: 11.00

#ifndef VmxfunctionsHPP
#define VmxfunctionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vmxfunctions
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const Shortint VMCALL_GETVERSION = 0x0;
static const Shortint VMCALL_CHANGEPASSWORD = 0x1;
static const Shortint VMCALL_REDIRECTINT1 = 0x9;
static const Shortint VMCALL_INT1REDIRECTED = 0xa;
static const Shortint VMCALL_CHANGESELECTORS = 0xc;
static const Shortint VMCALL_BLOCK_INTERRUPTS = 0xd;
static const Shortint VMCALL_RESTORE_INTERRUPTS = 0xe;
extern PACKAGE unsigned vmx_password1;
extern PACKAGE unsigned vmx_password2;
extern PACKAGE bool vmx_enabled;
extern PACKAGE unsigned __stdcall dbvm_version(void);
extern PACKAGE unsigned __stdcall dbvm_changepassword(unsigned password1, unsigned password2);
extern PACKAGE unsigned __stdcall dbvm_changeselectors(unsigned cs, unsigned ss, unsigned ds, unsigned es, unsigned fs, unsigned gs);
extern PACKAGE unsigned __stdcall dbvm_redirect_interrupt1(int redirecttype, unsigned newintvector, unsigned int1cs, unsigned int1eip);
extern PACKAGE unsigned __stdcall dbvm_block_interrupts(void);
extern PACKAGE unsigned __stdcall dbvm_restore_interrupts(void);
extern PACKAGE void __fastcall configure_vmx(unsigned userpassword1, unsigned userpassword2);

}	/* namespace Vmxfunctions */
using namespace Vmxfunctions;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Vmxfunctions
