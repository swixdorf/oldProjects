// CodeGear C++Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Disassembler.pas' rev: 11.00

#ifndef DisassemblerHPP
#define DisassemblerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Imagehlp.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Disassembler
{
//-- type declarations -------------------------------------------------------
typedef Set<Byte, 0, 255>  Tprefix;

typedef Byte TMemory[24];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool mode16;
extern PACKAGE unsigned diprocesshandle;
extern PACKAGE AnsiString __fastcall rd(Byte bt);
extern PACKAGE AnsiString __fastcall rd8(Byte bt);
extern PACKAGE AnsiString __fastcall rd16(Byte bt);
extern PACKAGE AnsiString __fastcall r8(Byte bt);
extern PACKAGE AnsiString __fastcall r16(Byte bt);
extern PACKAGE AnsiString __fastcall r32(Byte bt);
extern PACKAGE AnsiString __fastcall xmm(Byte bt);
extern PACKAGE AnsiString __fastcall mm(Byte bt);
extern PACKAGE AnsiString __fastcall sreg(Byte bt);
extern PACKAGE AnsiString __fastcall CR(Byte bt);
extern PACKAGE AnsiString __fastcall DR(Byte bt);
extern PACKAGE Byte __fastcall GetBitOf(unsigned Bt, int bit);
extern PACKAGE AnsiString __fastcall getsegmentoverride(const Tprefix &prefix);
extern PACKAGE Byte __fastcall getmod(Byte bt);
extern PACKAGE Byte __fastcall getRM(Byte bt);
extern PACKAGE Byte __fastcall getREG(Byte bt);
extern PACKAGE AnsiString __fastcall MODRM(Byte * memory, const Tprefix &prefix, int modrmbyte, int inst, unsigned &last)/* overload */;
extern PACKAGE AnsiString __fastcall SIB(Byte * memory, int sibbyte, unsigned &last);
extern PACKAGE AnsiString __fastcall disassemble(unsigned &offset, AnsiString &description, unsigned &codelen)/* overload */;
extern PACKAGE unsigned __fastcall previousopcode(unsigned address);
extern PACKAGE AnsiString __fastcall translatestring(AnsiString disassembled, int numberofbytes);
extern PACKAGE AnsiString __fastcall inttohexs(unsigned address, int chars);

}	/* namespace Disassembler */
using namespace Disassembler;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Disassembler
