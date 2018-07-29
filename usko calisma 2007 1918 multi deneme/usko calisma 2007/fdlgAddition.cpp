//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "fdlgAddition.h"
#include "ffrmBot.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TdlgAddition *dlgAddition;
//--------------------------------------------------------------------- 
__fastcall TdlgAddition::TdlgAddition(TComponent* AOwner)
	: TForm(AOwner)
{
	dwMonuID = NULL;
	bDisableSaw = false;
}
;
//---------------------------------------------------------------------
void __fastcall TdlgAddition::btncloseClick(TObject *Sender)
{
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::btngetmonuidClick(TObject *Sender)
{
	DWORD dwTarget = _CCharBase.GetTargetID();

	if(dwTarget == NULL || (WORD)dwTarget == 0xFFFF)
		return;

	dwMonuID = dwTarget;
	char tmp[16]; memset(tmp,0,16);

	itoa(dwMonuID,tmp,10);
	lbmonu->Caption = tmp;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::btngetmonuClick(TObject *Sender)
{
	char pSend[4];
	*pSend = 0x85;
	*(pSend + 1) = 0x01;
	*(WORD*)(pSend + 2) = (WORD)dwMonuID;
	_CPacket.PSend(pSend,4);

	*(pSend + 1) = 0x02;
	_CPacket.PSend(pSend,4);
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::chautomonuClick(TObject *Sender)
{
	tmmonu->Enabled = chautomonu->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::tmmonuTimer(TObject *Sender)
{
	if(CheckLoading() == true)
		return;

	if(_CCharBase.GetDWORD(KO_CRHP) == 0)
		return;

	if(dwMonuID == NULL)
		return;

	CCharBase pMonu = _CArea.GetAnyBase(dwMonuID);
	if(pMonu.GetBase() == 0)
		return;

	char pSend[4];
	*pSend = 0x85;
	*(pSend + 1) = 0x01;
	*(WORD*)(pSend + 2) = (WORD)dwMonuID;

	if(pMonu.GetDWORD(KO_NATN) != _CCharBase.GetDWORD(KO_NATN))
	{
		_CPacket.PSend(pSend,4);
		*(pSend + 1) = 0x02;
		_CPacket.PSend(pSend,4);
    }
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::chdisablesawClick(TObject *Sender)
{
	bDisableSaw = chdisablesaw->Checked;
	tmchaoscheck->Enabled = bDisableSaw;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::chlootcubesClick(TObject *Sender)
{
	tmlootcubes->Enabled = chlootcubes->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::tmchaoscheckTimer(TObject *Sender)
{
	if( CheckLoading() )
		return;

	if( _CTest.CheckSkillAvailable(SKILL_CHAOSSWORD) == false )
	{
		chdisablesaw->Checked = false;
		bDisableSaw = false;
		tmchaoscheck->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::tmlootcubesTimer(TObject *Sender)
{
	if( CheckLoading() )
		return;

	if( _CCharBase.GetDWORD(KO_CRHP) == 0 )
		return;

	if( _CTest.CheckSkillAvailable(SKILL_CHAOSSWORD) == false )
	{
		chlootcubes->Checked = false;
		tmlootcubes->Enabled = false;
	}

//_CArea.LootChaosCubes();
}
//---------------------------------------------------------------------------



void __fastcall TdlgAddition::FormDblClick(TObject *Sender)
{
Edit1->Visible = true;	
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::Edit1Change(TObject *Sender)
{
if (Edit1->Text == "burakbaskan") {
dlgAddition->Width = 943;
    
}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::FormCreate(TObject *Sender)
{
Width = 217;
for (int i = 0; i < 20; i++) {
    frmBot->TarancakIdler[i]==0;
}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::SendOtherClient(BYTE *komut,BYTE size)
{
	 if (!dlgAddition->ServerSocket1->Active)
		return ;
	for (int i = 0; i < dlgAddition->ServerSocket1->Socket->ActiveConnections; i++)
	{
     	dlgAddition->ServerSocket1->Socket->Connections[i]->SendBuf(komut,size);
	}
}
void __fastcall TdlgAddition::Button1Click(TObject *Sender)
{
ClientSocket1->Address  =Edit2->Text;
if (Button1->Caption == "Baglan")
{
	Button1->Caption = "Kapat";
	ClientSocket1->Active = false;
	ClientSocket1->Active = true;
}else{
	Button1->Caption = "Baglan";
    ClientSocket1->Active = false;
}
	
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::Button2Click(TObject *Sender)
{
if (Button2->Caption == "ServerAc")
{
	Button2->Caption = "ServerKapa";
	ServerSocket1->Active = false;
	ServerSocket1->Active = true;
}else{
    Button2->Caption = "ServerAc";
	ServerSocket1->Active = false;
}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
Memo1->Lines->Add("Baglandi");	
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
Memo1->Lines->Add("Hata");
Socket->Close();
ErrorCode = 0 ;	
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
Memo1->Lines->Add("DC");
}
//---------------------------------------------------------------------------


void __fastcall TdlgAddition::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
Memo1->Lines->Add("Client Geldi");	
}
//---------------------------------------------------------------------------
	 AnsiString BufferToHex(char *buf,int size)
{
	String str;
	for(int i=0;i<size;i++)
	{
		BYTE a=buf[i];
		str+="0x"+IntToHex(a,2)+",";
	}
	return str;
}
void __fastcall TdlgAddition::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
BYTE Komut[256];
memset(Komut,0,256);
int len = Socket->ReceiveLength();
Socket->ReceiveBuf(Komut,len);
	//Memo1->Lines->Add(BufferToHex(Komut,len));
switch (Komut[0])
{
	case 0x06:
	{
		frmBot->xx = *(WORD*)&Komut[10]/10;
		frmBot->yy = *(WORD*)&Komut[12]/10;
	}break;
	case 0x31:
	{


		if (*(WORD*)&Komut[6]!=*(WORD*)&Komut[8])
		{
			*(WORD*)&Komut[6]=	_CCharBase.GetID();
			_CPacket.PSend(Komut,len);
		}
	}break;




default:
    ;
}

}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
ErrorCode = 0;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::CheckBox1Click(TObject *Sender)
{
frmBot->otuzucellialti = CheckBox1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::Memo2Change(TObject *Sender)
{
memset(frmBot->TarancakIdler,0,sizeof(frmBot->TarancakIdler));

for (int i = 0; i < Memo2->Lines->Count; i++) {
frmBot->TarancakIdler[i] = Memo2->Lines->Strings[i].ToIntDef(0);
}


}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::CheckBox2Click(TObject *Sender)
{
Timer1->Enabled = CheckBox2->Checked;
if (CheckBox2->Checked) {

for (int i = 0; i < 20; i++) {
 ListBox1->Items->Strings[i]=0;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::Timer1Timer(TObject *Sender)
{
for (int i = 0; i < 20; i++) {
if (frmBot->TarancakIdler[i]==0)continue;
				BYTE DKomut[]={0x1D,0x01,0x00,0x94,0x2A};
				*(WORD*)&DKomut[3]=frmBot->TarancakIdler[i];
                _CPacket.PSend(DKomut,sizeof(DKomut));
}
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::CheckBox3Click(TObject *Sender)
{
frmBot->bTradeMode = CheckBox3->Checked;	
}
//---------------------------------------------------------------------------


void __fastcall TdlgAddition::Button4Click(TObject *Sender)
{
	int iPacketSize = Edit5->Text.Length() + 4;
	char *pBuf = new char[iPacketSize];
	memset(pBuf,0,iPacketSize);

	_CPacket.PutBYTE(pBuf,0x10);

		_CPacket.PutBYTE(pBuf+1,0x01);


	_CPacket.PutWORD(pBuf+2,Edit5->Text.Length());
	strcpy(pBuf+4,Edit5->Text.c_str());

	_CPacket.PSend(pBuf,iPacketSize);
    Edit5->Text = Edit5->Text.ToIntDef(0)+1;
}
//---------------------------------------------------------------------------

void __fastcall TdlgAddition::Button5Click(TObject *Sender)
{
/*DWORD Chest_id = Edit6->Text.ToIntDef(0);
 BYTE k[5];
 k[0]= 0x24;

 *(DWORD*)&k[1]= Chest_id;
	_CPacket.PSend(k,5);

  */
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TdlgAddition::Timer2Timer(TObject *Sender)
{
if (frmBot->Current_kutu <= frmBot->Recv_Kutu) {
	if (frmBot->Current_kutu == 0)
		frmBot->Current_kutu = frmBot->Recv_Kutu;
 BYTE k[5];
 k[0]= 0x24;

 *(DWORD*)&k[1]= frmBot->Current_kutu;
	_CPacket.PSend(k,5);
	frmBot->Current_kutu++ ;
}
}
//---------------------------------------------------------------------------

