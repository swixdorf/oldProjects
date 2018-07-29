//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "unzip.h"
#include "zip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	HZIP hz; DWORD writ;
	hz = CreateZip("simple1.zip",0);
   //	ZipAdd(hz,_T("a.bmp"), _T("\\simple.bmp"));
	ZipAdd(hz,"a.txt", "\\simple.txt");
	CloseZip(hz);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	HZIP hz; DWORD writ;
	 hz = OpenZip("simple1.zip",0);
  SetUnzipBaseDir(hz,"");
  ZIPENTRY ze; GetZipItem(hz,-1,&ze); int numitems=ze.index;
  for (int zi=0; zi<numitems; zi++)
  {
  GetZipItem(hz,zi,&ze);
    UnzipItem(hz,zi,ze.name);
  }
  CloseZip(hz);
}
//---------------------------------------------------------------------------
