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
char g_szServer[128]; // server (e.g. www.goblineye.com)
char g_szDocument[256]; // document on the server (e.g. index.php or somedirectory/somefile.zip)
char g_szProxyServer[128]; // proxy server. this is always retrieved.
WORD g_wProxyPort; // proxy server port

char g_szUsername[32]; // username
char g_szPassword[32]; // password
const char BASE64_LOOKUP[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
// Base64_GetEncodedLen() retrieves the exact encoded string length. it's a bit crude though, and might give problems on other compilers, so watch out.
inline unsigned int Base64_GetEncodedLen(char *lpStr) { unsigned int uiRet = (unsigned int)(((lstrlen(lpStr)*8)/6)); while (uiRet%4 != 0) uiRet++; return(uiRet); }

void Base64_Encode(const char *lpinBuffer,char *lpoutBuffer) // no checking is done here (lpinBuffer and lpoutBuffer might be NULL on error), so look out
{
	unsigned int uiOutProg = 0;
	byte bNewLetter = 0;
	byte bInProg = 0;

	while ((lpinBuffer != NULL) && (*lpinBuffer != '\0'))
	{
		// bInProg is the amount of bits we already have in bNewLetter
		// let's get what we can and scram
		bNewLetter |= (*lpinBuffer & ((0xFC << bInProg) & 0xFF)) >> bInProg;
		bNewLetter >>= 2;
		lpoutBuffer[uiOutProg++] = BASE64_LOOKUP[bNewLetter];

		bNewLetter = 0; // starting over
		bInProg = 8 - (2 + bInProg); // this is how much we need (8 - (6 - bInProg)) - the (-8) is just to make stuff below faster
		bNewLetter = (*lpinBuffer & (0xFF >> bInProg)) << bInProg;
		bInProg = 8 - bInProg;

		// if we're full - unload
		if (bInProg == 6)
		{
			bNewLetter >>= 2;
			lpoutBuffer[uiOutProg++] = BASE64_LOOKUP[bNewLetter];
			bInProg = 0;
			bNewLetter = 0;
		}

		lpinBuffer++;
	}

	if (bInProg > 0)
	{
		bNewLetter >>= 2;
		lpoutBuffer[uiOutProg++] = BASE64_LOOKUP[bNewLetter];
	}

	while (uiOutProg%4 != 0) { lpoutBuffer[uiOutProg++] = '='; }
	lpoutBuffer[uiOutProg] = '\0';
}
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	char szData[2048]; // used for sending/receiving data
	wsprintf(szData,"CONNECT %s \r\n","188.132.161.211:15100");


		lstrcat(szData,"Proxy-Authorization: Basic ");
		char *lpFinalBuffer = NULL; // this buffer will hold the encoded string when we're done
		char szTempBuf[258]; // more than enough
		wsprintf(g_szUsername,"fatihsekmen");
		wsprintf(g_szPassword,"FHFY8UA7");
		lstrcpy(szTempBuf,g_szUsername);
		lstrcat(szTempBuf,":");
		lstrcat(szTempBuf,g_szPassword);

		lpFinalBuffer = new char[Base64_GetEncodedLen(szTempBuf) + 1];
		Base64_Encode(szTempBuf,lpFinalBuffer);
		lstrcat(szData,lpFinalBuffer);
		lstrcat(szData,"\r\n");
		delete [] lpFinalBuffer;
        lstrcat(szData,"\r\n");
	   Socket->SendBuf(szData,lstrlen(szData));

return;
BYTE Komut[]={0x43,0x4f,0x4e,0x4e,0x45,0x43,0x54,0x20,0x31,0x38,0x38,0x2e,0x31,0x33,0x32,0x2e,0x31,0x36,0x31,0x2e,0x32,0x31,0x31,0x3a,0x31,0x35,0x31,0x30,0x30,0x20,0x0d,0x0a,0x50,0x72,0x6f,0x78,0x79,0x2d,0x41,0x75,0x74,0x68,0x6f,0x72,0x69,0x7a,0x61,0x74,0x69,0x6f,0x6e,0x3a,0x20,0x42,0x61,0x73,0x69,0x63,0x20,0x5a,0x6d,0x46,0x30,0x61,0x57,0x68,0x7a,0x5a,0x57,0x74,0x74,0x5a,0x57,0x34,0x36,0x52,0x6b,0x68,0x47,0x57,0x54,0x68,0x56,0x51,0x54,0x63,0x3d,0x0d,0x0a,0x0d,0x0a};
Socket->SendBuf(Komut,sizeof(Komut));
/*
"CONNECT 188.132.161.211:15100"


0000   43 4f 4e 4e 45 43 54 20 31 38 38 2e 31 33 32 2e  CONNECT 188.132.
0010   31 36 31 2e 32 31 31 3a 31 35 31 30 30 20 0d 0a  161.211:15100 ..
0020   50 72 6f 78 79 2d 41 75 74 68 6f 72 69 7a 61 74  Proxy-Authorizat
0030   69 6f 6e 3a 20 42 61 73 69 63 20 5a 6d 46 30 61  ion: Basic ZmF0a
0040   57 68 7a 5a 57 74 74 5a 57 34 36 52 6b 68 47 57  WhzZWttZW46RkhGW
0050   54 68 56 51 54 63 3d 0d 0a 0d 0a                 ThVQTc=....
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
	  TCustomWinSocket *Socket)
{
String a=Socket->ReceiveText();
}
//---------------------------------------------------------------------------

