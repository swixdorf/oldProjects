//---------------------------------------------------------------------------


#pragma hdrstop

#include "swxpatch.h"

//---------------------------------------------------------------------------
Cswxpatch::Cswxpatch(){
memset(Locations,0,sizeof(Locations));
}
Cswxpatch::InitPatch()
{
	for (int i = 0; i < 100; i++)
	{
		if (!Locations[i].Active)continue;
	}
}
Cswxpatch::AddAddr(DWORD paddr,BYTE pstate,DWORD pnewaddr)
{
	for (int i = 0; i < 100; i++)
	{
		if (!Locations[i].Active)
		{
			Locations[i].Active = true;
			Locations[i].State = pstate;
			Locations[i].Addr = paddr;
            Locations[i].Param = pnewaddr ;
		}
	}
}
