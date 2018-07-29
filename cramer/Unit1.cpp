//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int det(int matris[2][2]){
int ret = matris[0][0]*matris[1][1]-matris[1][0]*matris[0][1];
return ret;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int a1 = Edit1->Text.ToIntDef(0);
int b1 = Edit2->Text.ToIntDef(0);
int a2 = Edit3->Text.ToIntDef(0);
int b2 = Edit4->Text.ToIntDef(0);
int c1 = Edit5->Text.ToIntDef(0);
int c2 = Edit6->Text.ToIntDef(0);
//  a1*x + a2*y =c1
//  b1*x + b2*y =c2
//
//
int mymatris[2][2];
mymatris[0][0]=a1;
mymatris[0][1]=b1;
mymatris[1][0]=a2;
mymatris[1][1]=b2;
int mydet  = det(mymatris);
Memo1->Lines->Add("determinant : " + IntToStr(mydet));
int bufmatris[2][2];
memcpy(bufmatris,mymatris,sizeof(mymatris));
bufmatris[0][0]=c1;
bufmatris[1][0]=c2;
int det1  = det(bufmatris);
Memo1->Lines->Add("determinant1 : " + IntToStr(det1));
memcpy(bufmatris,mymatris,sizeof(mymatris));
bufmatris[0][1]=c1;
bufmatris[1][1]=c2;
int det2  = det(bufmatris);
Memo1->Lines->Add("determinant2 : " + IntToStr(det2));
float x = det1/mydet;
float y = det2/mydet;
Memo1->Lines->Add("x : " + FloatToStr(x));
Memo1->Lines->Add("y : " + FloatToStr(y));
}
//---------------------------------------------------------------------------
