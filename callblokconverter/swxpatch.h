//---------------------------------------------------------------------------

#ifndef swxpatchH
#define swxpatchH
#include <Classes.hpp>
//---------------------------------------------------------------------------
typedef struct{
DWORD Addr;
BYTE State;//00 : NOP ; 1: REdirect Original ;2: Redirect Special location.
DWORD Param;
bool Active;
}swx_loc;

class Cswxpatch{
	public:
swx_loc Locations[100];
DWORD StartAddr;
DWORD EndAddr;
DWORD Size;

Cswxpatch();
InitPatch();
AddAddr(DWORD paddr,BYTE pstate,DWORD pnewaddr);

};
#endif
