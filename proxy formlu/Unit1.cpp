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
void __fastcall TForm1::Button4Click(TObject *Sender)
{

	char proxy_ip[100],proxy_port[100],proxy_user[100],proxy_password[100];
	bool authorize= false;
	memset(proxy_ip,0,100);
	memset(proxy_port,0,100);
	memset(proxy_user,0,100);
	memset(proxy_password,0,100);

	strcpy(proxy_ip,Edit7->Text.c_str()) ;
	strcpy(proxy_port,Edit8->Text.c_str()) ;
	strcpy(proxy_user,Edit9->Text.c_str()) ;
	strcpy(proxy_password,Edit10->Text.c_str()) ;
	authorize = CheckBox1->Checked ;

	SOCKET myGameSocket;
	WSADATA wsaGameData;
	sockaddr_in myGameAddress;
	myGameAddress.sin_family = AF_INET;

	myGameAddress.sin_addr.s_addr = inet_addr( proxy_ip );
	myGameAddress.sin_port = htons(atoi(proxy_port) );

   myGameAddress.sin_addr.S_un.S_un_b.s_b1;
	if( WSAStartup( MAKEWORD(2, 2), &wsaGameData ) != NO_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return;
	}
	myGameSocket = socket( AF_INET, SOCK_STREAM, 0 );

	if ( myGameSocket == INVALID_SOCKET || myGameSocket == SOCKET_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return;
	}

	if ( connect( myGameSocket, (SOCKADDR*) &myGameAddress, sizeof( myGameAddress ) ) == SOCKET_ERROR )
	{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return;
	}
	else
	{
		char szData[2048]; // used for sending/receiving data
		wsprintf(szData,"CONNECT %s:%s \r\n","188.132.161.211","15100");

		if (authorize)
		{
			lstrcat(szData,"Proxy-Authorization: Basic ");
			char *lpFinalBuffer = NULL; // this buffer will hold the encoded string when we're done
			char szTempBuf[258]; // more than enough
			lstrcpy(szTempBuf,proxy_user);
			lstrcat(szTempBuf,":");
			lstrcat(szTempBuf,proxy_password);
			lpFinalBuffer = new char[Base64_GetEncodedLen(szTempBuf) + 1];
			Base64_Encode(szTempBuf,lpFinalBuffer);
			lstrcat(szData,lpFinalBuffer);
			lstrcat(szData,"\r\n");
			delete [] lpFinalBuffer;
			lstrcat(szData,"\r\n");
		}

		send(myGameSocket,(char*)szData,lstrlen(szData),0);

		BYTE kKomut_Al[1024];
		memset(kKomut_Al,0,1024);
		int len=recv(myGameSocket,kKomut_Al,1024,0);

		closesocket(myGameSocket);
		WSACleanup();
		if (len == 0)
		{
		ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
			return;
		}
		String buf = String((char*)kKomut_Al) ;
		if (buf.AnsiPos("establish")!=0)
		{
					ShowMessage("Dogrulandi");

		}
		else
		{
			ShowMessage("kullanici adi yada sifre hatali.") ;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
char proxy_ip[100],proxy_port[100],proxy_user[100],proxy_password[100];
memset(proxy_ip,0,100);
memset(proxy_port,0,100);
memset(proxy_user,0,100);
memset(proxy_password,0,100);

strcpy(proxy_ip,Edit7->Text.c_str()) ;
strcpy(proxy_port,Edit8->Text.c_str()) ;
strcpy(proxy_user,Edit9->Text.c_str()) ;
strcpy(proxy_password,Edit10->Text.c_str()) ;
			char szData[2048]; // used for sending/receiving data
			memset(szData,0,2048);
			wsprintf(szData,"CONNECT %s:%s \r\n","188.132.161.211","15100");
			lstrcat(szData,"Proxy-Authorization: Basic ");
			char *lpFinalBuffer = NULL; // this buffer will hold the encoded string when we're done
			char szTempBuf[258]; // more than enough
			lstrcpy(szTempBuf,proxy_user);
			lstrcat(szTempBuf,":");
			lstrcat(szTempBuf,proxy_password);
			lpFinalBuffer = new char[Base64_GetEncodedLen(szTempBuf) + 1];
			Base64_Encode(szTempBuf,lpFinalBuffer);
			lstrcat(szData,lpFinalBuffer);
			lstrcat(szData,"\r\n");
			delete [] lpFinalBuffer;
			lstrcat(szData,"\r\n");
			Socket->SendBuf(szData,lstrlen(szData)) ;
		  //	send(myGameSocket,(char*)szData,lstrlen(szData),0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
Memo1->Lines->Add(Socket->ReceiveText()) ;
;
}
//---------------------------------------------------------------------------





