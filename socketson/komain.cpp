//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "keyuret.h"
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

//if (KeyUret("13-08-2011") =="F971EE57B801D36FB1BCB6628EA22E57") {
//}else if (KeyUret("13-08-2011") =="55EC44008F514035B0A019C37A4FA539") {//11
//}else if (KeyUret("13-08-2011") =="39BAFC367E2BA23BCB521DC2A4BC3C0C") {//15
//	  } else {
////	  ShowMessage(HDDNO)  ;
//TerminateProcess(GetCurrentProcess(),0);
//return 0;
//	  }
	try
	{
		Application->Initialize();
		SetApplicationMainFormOnTaskBar(Application, true);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
