#define WIN32_LEAN_AND_MEAN
#pragma warning(disable:4996)
#pragma warning(default:4716)


#include <windows.h>
#include <mmsystem.h>
#include <winbase.h>
#include <stdio.h>
#include <tchar.h>
#include <Winuser.h>
#include <shellapi.h>
#include <Tlhelp32.h>                                       
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <io.h>
#include <iostream>
#include <conio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <exception>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ostream>
//#include <boost/algorithm/string.hpp>
#include <wbemidl.h>
//#include <winsock.h>
#include <sys/stat.h>
#include <dos.h>
#include <psapi.h>
#include <time.h>


#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "Ws2_32.lib")

bool mod = false;

char swx_my_no_a[10];
BYTE firstpar[1024];
bool firstpargeldi;
BYTE secondpar[1024];
bool secondpargeldi;
BYTE thirdpar[1024];
bool thirdpargeldi;
BYTE Yollanacak[1024];
int YollanacakLen;
//#include "ClassMorphinee.h"
#include "koclassturet.h"
#include "swx.h"

#define DEFAULT_BUFLEN 2048
//#define DEFAULT_PORT "16600"
bool logyaz(char* Mesaj)
{

	ofstream fSave;
	fSave.open("mylog.ini",std::ios_base::out | std::ios_base::app);
	if(fSave.is_open() == true)
	{
		fSave << Mesaj << "\n";
		fSave.close();
	}
}

char DEFAULT_PORT[10] = "16600";
LRESULT CALLBACK MsgHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
   /* if (msg == WM_CREATE)      //Her hangi bir mesaj oluşturulduğunda bunun WM_CREATE olup olmadığını kontrol et
	{      */
		MessageBoxA(NULL,"amk","amk",NULL);
   /*	}     */
	}

DWORD infoTick ;

DWORD Recv_Kutu;
DWORD Current_kutu;
swxClientClass cClient;
using namespace std;
typedef KnightOnline_CLASS_Interface*  (WINAPI *KoClassOlustur) ();
KoClassOlustur c;
HANDLE EscHandle;
int WINAPI EscapeThread()
{
	Sleep(50000);
	logyaz("Escape :)");
	TerminateProcess(GetCurrentProcess(),0);
}
/*
int WINAPI lootthread()
{
while (1){

if (Current_kutu <= Recv_Kutu) {
printf("c: %d\n", Current_kutu);
printf("r: %d\n", Recv_Kutu);
	if (Current_kutu < Recv_Kutu-1000)
		Current_kutu = Recv_Kutu;
 BYTE k[5];
 k[0]= 0x24;

 *(DWORD*)&k[1]= Current_kutu;
	cClient.pSend(k,5);
	Current_kutu++ ;
}
Sleep(1250);
}

}
 */
int WINAPI potbaslat()
{
while (1){
	cClient.PotThread();
		Sleep(100);
}

	ExitThread(0);
	 return true;
}
int WINAPI madenbaslat()
{
	cClient.MadenThread();
	ExitThread(0);
	 return true;
}
int WINAPI atackthread	()
{
cClient.AtackThread();
	ExitThread(0);
	 return true;
}
int WINAPI lootthread	()
{
cClient.LootThread();
	ExitThread(0);
	 return true;
}
int WINAPI levelthread	()
{
cClient.LevelThread();
	ExitThread(0);
	 return true;
}
int WINAPI movethread	()
{
bbb:
    //printf("ddddddddddddddd");
	if (cClient.BaskanCoordGeldi==1){
		cClient.Move(cClient.goX,cClient.goY);
	}
		Sleep(100);
goto bbb;
	 return true;
}
bool movetopos(WORD X,WORD Y)
{
	cClient.goX = X;
	cClient.goY = Y;
	TerminateThread(cClient.MoveThreadHandle,0);
	cClient.MoveThreadHandle= CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
	 return true;
}
HANDLE upHandle;
int WINAPI tup	()
{
		  char aa[20];
		  memset(aa,0,20);
		  int a = 0;
for (int i = 0; i < 28; i++) {
if (    cClient.Item_Table[i].Id%10==7) {
	a++;
}
}
int b = 0;
for (int i = 0; i < 28; i++) {
if (    cClient.Item_Table[i].Id%10==8) {
	b++;
}
}
		  sprintf(aa,"%d-%d:%d-%d",cClient.Item_Table[0].Count,cClient.Item_Table[1].Count,a,b);
		  SetConsoleTitleA(aa);
if (a>14) {
		mod=true;;
}else{
    mod=false;
}
if (b>5) {
strcpy(cClient.command,"innkoy");
}else{
for (int i = 0; i < 5; i++) {

Sleep(1500);
strcpy(cClient.command,"1");
}
	BYTE Komut = 0 ;
			cClient.pSend(&Komut,1);
			TerminateThread(cClient.Thread41Handle,0);
			TerminateThread(upHandle,0);
}
}

int WINAPI t41	()
{
	while (1)
	{
	DWORD Detay41;
	BYTE Komut[7];
	Komut[0]=0x41;
	Komut[1]=1;
	Komut[6]=0x00;
	float time41;
	static bool bInit = false;
	static bool bUseHWTimer = FALSE;
	static LARGE_INTEGER nTime, nFrequency;
	if(bInit == false)
	{
		if(TRUE == ::QueryPerformanceCounter(&nTime))
		{
			::QueryPerformanceFrequency(&nFrequency);
			bUseHWTimer = TRUE;
		}
		else
		{
			bUseHWTimer = FALSE;
		}

		bInit = true;
	}

	if(bUseHWTimer)
	{
		::QueryPerformanceCounter(&nTime);
		time41= (float)((double)(nTime.QuadPart)/(double)nFrequency.QuadPart);
		goto Yolla;
	}
	time41= (float)timeGetTime();
	Yolla:
	DWORD deger41= time41;
	*(DWORD*)&Komut[2]=deger41;//GetTickCount();
	cClient.pSend(Komut,sizeof(Komut));
	Sleep(9990) ;
	}
}

 int WINAPI HsThread2()
{
 int indx = 0;
		SOCKET myGameSocket;
		WSADATA wsaGameData;
		sockaddr_in myGameAddress;
		char srvip[16];
		tekrar:
		memset(srvip,0,16);
	 printf("tttttttt\n");
   //	if (!hs_girdi)
   //	{

	//}

if (indx==0)
	{
		indx = GetTickCount()%10;
	}else
	{
		indx++;
		indx = indx%10;
    }
	switch (indx)
	{
		case 0: strcpy(srvip,"5.199.139.55"); break;
		case 1: strcpy(srvip,"5.199.136.18"); break;
		case 2: strcpy(srvip,"5.199.136.17"); break;
		case 3: strcpy(srvip,"5.199.133.167"); break;
		case 4: strcpy(srvip,"5.199.133.166"); break;
		case 5: strcpy(srvip,"46.20.37.166"); break;
		case 6: strcpy(srvip,"46.20.37.244"); break;
		case 7: strcpy(srvip,"46.20.37.245"); break;
		case 8: strcpy(srvip,"46.20.37.246"); break;
		case 9: strcpy(srvip,"46.20.37.247"); break;
	}
	  int a = 16600 + GetTickCount()%100;

	myGameAddress.sin_family = AF_INET;
	myGameAddress.sin_addr.s_addr = inet_addr( srvip );
	myGameAddress.sin_port = htons(a);
	printf("%s \n",srvip);
	//printf("%s \n",a);
	if( WSAStartup( MAKEWORD(2, 2), &wsaGameData ) != NO_ERROR )
	{
		//ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		goto tekrar;
	}
	myGameSocket = socket( AF_INET, SOCK_STREAM, 0 );

	if ( myGameSocket == INVALID_SOCKET || myGameSocket == SOCKET_ERROR )
	{
		//ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		goto tekrar;
	}

		unsigned long iMode = 1;
	TIMEVAL Timeout;
	Timeout.tv_sec = 5;
	Timeout.tv_usec = 0;
	int iResult = ioctlsocket(myGameSocket, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
    {	
		//printf("ioctlsocket failed with error: %ld\n", iResult);
		WSACleanup();
		goto tekrar;
	}

	connect( myGameSocket, (SOCKADDR*) &myGameAddress, sizeof( myGameAddress ));

	fd_set Write, Err;
	FD_ZERO(&Write);
    FD_ZERO(&Err);
	FD_SET(myGameSocket, &Write);
	FD_SET(myGameSocket, &Err);
	select(0,NULL,&Write,&Err,&Timeout);
	if(FD_ISSET(myGameSocket, &Write))
	{

	   goto devam;
	}else{
		closesocket(myGameSocket);
		WSACleanup();
		goto tekrar;
	}


		devam:
	iMode = 0;
	iResult = ioctlsocket(myGameSocket, FIONBIO, &iMode);
	if(1){
		int iResult = send( myGameSocket, Yollanacak, YollanacakLen, 0 );

	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(myGameSocket);
		WSACleanup();
		goto tekrar;
	}
	   //	send( ConnectSocket, frmBot->Yollanacak, frmBot->YollanacakLen, 0 );

		BYTE kKomut_Al[1024];
		memset(kKomut_Al,0,1024);

		iResult = recv(myGameSocket, kKomut_Al, 1024, 0);
		if ( iResult > 0 )
		{
			printf("HackShield Emulated\n");
			logyaz("HackShield Emulated");
			TerminateThread(EscHandle,0);
			BYTE Komut[1024];
			memset(Komut,1024,0);
			Komut[0]=0xb0;
			Komut[1]=1;
			WORD count=*(WORD*)&kKomut_Al[0x190];
			*(WORD*) &Komut[2]=(WORD)count;
			memcpy(&Komut[4],&kKomut_Al,count);

			if (count!=0)
			{
				cClient.pSend(Komut,count+4);
			}
		}
		else if ( iResult == 0 )
		{
		   printf("Connection closed\n");
		}
		else
		{
		   printf("recv failed: %d\n", WSAGetLastError());
		   WSACleanup();
		   goto tekrar;
		}



		closesocket(myGameSocket);
		shutdown(myGameSocket,2);
		WSACleanup();

	}
	return false;
	}

int WINAPI HsThread()
{
	int indx = 0;
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,*ptr = NULL,hints;
	char recvbuf[DEFAULT_BUFLEN];
	memset(recvbuf,0,DEFAULT_BUFLEN);
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	tryAgain:

	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

	if (iResult != 0)
	{
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	char srvip[16];
	memset(srvip,0,16);
	if (indx==0)
	{
		indx = GetTickCount()%8;
	}else
	{
		indx++;
		indx = indx%8;
    }
	switch (indx)
	{
		case 0: strcpy(srvip,"46.4.185.65"); break;
		case 1: strcpy(srvip,"46.4.185.66"); break;
		case 2: strcpy(srvip,"46.4.185.67"); break;
		case 3: strcpy(srvip,"46.4.185.68"); break;
		case 4: strcpy(srvip,"46.4.185.69"); break;
		case 5: strcpy(srvip,"46.4.185.70"); break;
		case 6: strcpy(srvip,"46.4.185.71"); break;
		case 7: strcpy(srvip,"46.4.185.72"); break;
	}
			//strcpy(srvip,"46.4.185.65");
		  int a = 16600 + GetTickCount()%10;
		  itoa(a,DEFAULT_PORT,10);
	printf("%s \n",srvip);
	printf("%s \n",DEFAULT_PORT);
	iResult = getaddrinfo(srvip, DEFAULT_PORT, &hints, &result);

	if ( iResult != 0 )
	{
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		goto tryAgain;
	}

	for(ptr=result; ptr != NULL ;ptr=ptr->ai_next)
	{
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol);

		if (ConnectSocket == INVALID_SOCKET)
		{
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			goto tryAgain;
		}
		iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		goto tryAgain;
	}

	iResult = send( ConnectSocket, Yollanacak, YollanacakLen, 0 );

	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		goto tryAgain;
	}

	iResult = shutdown(ConnectSocket, SD_SEND);

	if (iResult == SOCKET_ERROR)
	{
        printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		goto tryAgain;
	}

	do
	{
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if ( iResult > 0 )
		{
			printf("HackShield Emulated\n");
			BYTE Komut[1024];
			memset(Komut,1024,0);
			Komut[0]=0xb0;
			Komut[1]=1;
			WORD count=*(WORD*)&recvbuf[0x190];
			*(WORD*) &Komut[2]=(WORD)count;
			memcpy(&Komut[4],&recvbuf,count);

			if (count!=0)
			{
				cClient.pSend(Komut,count+4);
			}
		}
		else if ( iResult == 0 )
		{
		   printf("Connection closed\n");
		}
		else
		{
			printf("recv failed: %d\n", WSAGetLastError());
			WSACleanup();
			goto tryAgain;
		}

	} while( iResult > 0 );
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}
	DWORD Komut55AAIsle(BYTE *Decode_Komut,BYTE *Gidecek_Komut,WORD DecodeLen)
{
	DWORD *TempDWord;
	WORD  *TempWord;
	TempWord = (WORD* ) Decode_Komut;
	TempWord[0]=0x55AA;
	TempWord[1]=DecodeLen;
	TempWord= (WORD*)&Decode_Komut[DecodeLen+4];
	TempWord[0]=0xAA55;
	memcpy(&Decode_Komut[4],Gidecek_Komut,DecodeLen);
	return 1 ;
}

int	Dusur(char* Ip,char* Name)
{
	int GidenLen;
	BYTE ServerKomut[55];
	BYTE Aski[50]={0x51,0x08,0x00,0x6D,0x61,0x6B,0x69,0x6E,0x31,0x35,0x36};
	Aski[0]=0x51;
	Aski[1]=lstrlen(Name);//Form1->AccEkle->Text.Length();
	GidenLen=Aski[1];
	GidenLen+=3;
	memcpy(&Aski[3],Name,Aski[1]);
	Komut55AAIsle(ServerKomut,Aski,GidenLen);
	GidenLen+=6;



		SOCKET myGameSocket;
		WSADATA wsaGameData;
		sockaddr_in myGameAddress;
		myGameAddress.sin_family = AF_INET;

		myGameAddress.sin_addr.s_addr = inet_addr(Ip);
		myGameAddress.sin_port = htons(15001 );
			if( WSAStartup( MAKEWORD(2, 2), &wsaGameData ) != NO_ERROR )
	{
		//ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return false;
	}
	myGameSocket = socket( PF_INET, SOCK_STREAM, 0 );

	if ( myGameSocket == INVALID_SOCKET || myGameSocket == SOCKET_ERROR )
	{
		//ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return false;
	}

	if ( connect( myGameSocket, (SOCKADDR*) &myGameAddress, sizeof( myGameAddress ) ) == SOCKET_ERROR )
	{
		//ShowMessage("girdiginiz proxy sunucusuna baglanamiyor ip port kontrol edin");
		WSACleanup();
		return false;
	}
	int got =	send(myGameSocket,ServerKomut,GidenLen,0);

  /*
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,*ptr = NULL,hints;
	char recvbuf[DEFAULT_BUFLEN];
	memset(recvbuf,0,DEFAULT_BUFLEN);
	int iResult;
	int recvbuflen = DEFAULT_BUFLEN;

	tryAgain:

	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

	if (iResult != 0)
	{
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}
	ZeroMemory( &hints, sizeof(hints) );
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	char srvip[16];
	memset(srvip,0,16);
	strcpy(srvip,Ip);

	printf("%s \n",srvip);
	iResult = getaddrinfo(srvip, "15001", &hints, &result);

	if ( iResult != 0 )
	{
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		goto tryAgain;
	}

	for(ptr=result; ptr != NULL ;ptr=ptr->ai_next)
	{
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol);

		if (ConnectSocket == INVALID_SOCKET)
		{
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			goto tryAgain;
		}
		iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		goto tryAgain;
	}

	iResult = send( ConnectSocket, ServerKomut, GidenLen, 0 );

	if (iResult == SOCKET_ERROR)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		goto tryAgain;
	}

	iResult = shutdown(ConnectSocket, SD_SEND);

	if (iResult == SOCKET_ERROR)
	{
        printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		goto tryAgain;
	}
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
			 */
	}

 __declspec(naked) coz43(BYTE *gelenoffset,DWORD arg_4,DWORD CozBuf,DWORD ebxne)
 {
asm{
__0048DCF0:

        MOV ECX,DWORD PTR SS:[ESP+8]
        PUSH EBX
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		PUSH EBP
        PUSH ESI
        PUSH EDI
		MOV EDI,DWORD PTR SS:[ESP+0x14]
        LEA EDX,DWORD PTR DS:[EDI+ECX]
        MOV ECX,DWORD PTR SS:[ESP+0x20]
        MOV EAX,EBX
		MOV DWORD PTR SS:[ESP+0x14],EDX
        LEA EBP,DWORD PTR DS:[EBX+ECX]

__0048DD10:

        MOVZX EDX,BYTE PTR DS:[EDI]
        ADD EDI,1
        CMP EDX,0x20
        JNB __0048DD41
        ADD EDX,1
		LEA ECX,DWORD PTR DS:[EDX+EAX]
        CMP ECX,EBP
        JA __0048DDB4
        LEA ESP,DWORD PTR SS:[ESP]

__0048DD30:

		MOV CL,BYTE PTR DS:[EDI]
        MOV BYTE PTR DS:[EAX],CL
        ADD EAX,1
        ADD EDI,1
		SUB EDX,1
        JNZ __0048DD30
        JMP __0048DD9F

__0048DD41:

        MOV ESI,EDX
        AND EDX,0x1F
		SHL EDX,8
        MOV ECX,EAX
        SUB ECX,EDX
        SHR ESI,5
        SUB ECX,1
        CMP ESI,7
        JNZ __0048DD61
        MOVZX ESI,BYTE PTR DS:[EDI]
        ADD ESI,7
        ADD EDI,1

__0048DD61:

        MOVZX EDX,BYTE PTR DS:[EDI]
        SUB ECX,EDX
		LEA EDX,DWORD PTR DS:[ESI+EAX+2]
        ADD EDI,1
        CMP EDX,EBP
        JA __0048DDB4
        CMP ECX,EBX
        JB __0048DDC6
		MOVZX EDX,BYTE PTR DS:[ECX]
        MOV BYTE PTR DS:[EAX],DL
        MOVZX EDX,BYTE PTR DS:[ECX+1]
        ADD ECX,1
        ADD EAX,1
        MOV BYTE PTR DS:[EAX],DL
		ADD EAX,1
        ADD ECX,1
        LEA ESP,DWORD PTR SS:[ESP]

__0048DD90:

        MOV DL,BYTE PTR DS:[ECX]
        MOV BYTE PTR DS:[EAX],DL
        ADD EAX,1
        ADD ECX,1
        SUB ESI,1
        JNZ __0048DD90

__0048DD9F:

        CMP EAX,EBP
        JNB __0048DDAD
        CMP EDI,DWORD PTR SS:[ESP+0x14]
		JB __0048DD10

__0048DDAD:

		POP EDI
        POP ESI
        POP EBP
        SUB EAX,EBX
        POP EBX
		RET

__0048DDB4:

	//    CALL __00A2BDB7
        POP EDI
        POP ESI
		POP EBP
		MOV DWORD PTR DS:[EAX],7
        XOR EAX,EAX
        POP EBX
		RET

__0048DDC6:

	//    CALL __00A2BDB7
        POP EDI
        POP ESI
        POP EBP
        MOV DWORD PTR DS:[EAX],0x16
        XOR EAX,EAX
		POP EBX

		RET

}
 return true;
}
WINAPI coz42(BYTE *gelenoffset,DWORD arg_4,DWORD CozBuf,DWORD ebxne)
{
DWORD retunne ;
	asm{
	   push ebxne
	   push CozBuf
	   push  arg_4
	   push gelenoffset
	   call coz43
	   add     esp, 10h   //winapiyi kaldirmistik biliyom onemli değil manule
	   mov retunne,eax

	}
	return retunne;
}


int serverindex;
int charindex;
int count1d;
BYTE Array1d[0xffff];
DWORD Timer1d;

npcrecvproces(BYTE *GelenBuf){
	cClient.NPCS[*(WORD*)&GelenBuf[0]].Id 		= *(WORD*)&GelenBuf[0];
	cClient.NPCS[*(WORD*)&GelenBuf[0]].Name 	= *(WORD*)&GelenBuf[2];
	cClient.NPCS[*(WORD*)&GelenBuf[0]].X 		= *(WORD*)&GelenBuf[28]/10;
	cClient.NPCS[*(WORD*)&GelenBuf[0]].Y 		= *(WORD*)&GelenBuf[30]/10;
	cClient.NPCS[*(WORD*)&GelenBuf[0]].Level 	= *(WORD*)&GelenBuf[27];
	cClient.NPCS[*(WORD*)&GelenBuf[0]].NpcType 	= *(WORD*)&GelenBuf[16];
	//printf("NPC Info Recv ID: %d X:%d Y:%d Level:%d Type:%d \n",cClient.NPCS[*(WORD*)&GelenBuf[0]].Id,cClient.NPCS[*(WORD*)&GelenBuf[0]].X,cClient.NPCS[*(WORD*)&GelenBuf[0]].Y,cClient.NPCS[*(WORD*)&GelenBuf[0]].Level,cClient.NPCS[*(WORD*)&GelenBuf[0]].NpcType);
	if (cClient.MinNpcId>*(WORD*)&GelenBuf[0])
		cClient.MinNpcId=*(WORD*)&GelenBuf[0];
	if (cClient.MaxNpcId<*(WORD*)&GelenBuf[0])
		cClient.MaxNpcId=*(WORD*)&GelenBuf[0];
		 return true;
}
DWORD Geln42Coz(BYTE *Geln42,int len,int socketno,void *ths);
int __msfastcall   SynSocketGelenVeriHepsiCall(BYTE *GelenBuf,int len,int socketno,void *ths)
{
	KnightOnline_CLASS_Interface * deneme1=(KnightOnline_CLASS_Interface*)ths;
	switch(GelenBuf[0])
	{
		case 1:
		{
			if (GelenBuf[1]==0x02)
			{
				cClient.CharHuman=true;
			}else if (GelenBuf[1]==0x01){
				cClient.CharHuman=false;
			}else{
				BYTE Komut[]={0x05,0x02};
				cClient.pSend(Komut,2);
				BYTE asd[]={0x0C,0x01};
				cClient.pSend(asd,2);
			}
		}break;

		case 0xB:
		{
			cClient.NPCS[*(WORD*)&GelenBuf[2]].X =*(WORD*)&GelenBuf[4]/10;
			cClient.NPCS[*(WORD*)&GelenBuf[2]].Y =*(WORD*)&GelenBuf[6]/10;

			//printf("npc move %d = %d,%d \n",*(WORD*)&GelenBuf[2],*(WORD*)&GelenBuf[4]/10,*(WORD*)&GelenBuf[6]/10);
			//printf("%d  =  %d\n",cClient.NPCS[*(WORD*)&GelenBuf[2]].Id,cClient.NPCS[*(WORD*)&GelenBuf[2]].LastTick);
			if ((cClient.NPCS[*(WORD*)&GelenBuf[2]].Id==0)&&((GetTickCount()-cClient.NPCS[*(WORD*)&GelenBuf[2]].LastTick)>5000))
			{
				cClient.NPCS[*(WORD*)&GelenBuf[2]].Id =*(WORD*)&GelenBuf[2];
				cClient.NPCS[*(WORD*)&GelenBuf[2]].LastTick = GetTickCount();
				BYTE DKomut[]={0x1D,0x01,0x00,0x94,0x2A};
				*(WORD*)&DKomut[3]=*(WORD*)&GelenBuf[2];
				cClient.pSend(DKomut,sizeof(DKomut));
			}
		}break;

		case 0xA:
		{
			if (GelenBuf[1]==0x02)
			{
				printf("NPC Remove ID:%d\n",*(WORD*)&GelenBuf[2]);
                cClient.NPCS[*(WORD*)&GelenBuf[2]].Id = 0 ;	
				//memset(&cClient.NPCS[*(WORD*)&GelenBuf[2]],0,sizeof(cClient.NPCS[*(WORD*)&GelenBuf[2]]));
			}
			else if (GelenBuf[1]==0x01)
			{
				npcrecvproces(&GelenBuf[2]);
				printf("NPC In ID:%d\n",*(WORD*)&GelenBuf[2]);
			}
		}break;

	case 0x22:
		{
			if (*(DWORD*)&GelenBuf[8]==0)
			{
            	cClient.NPCS[*(WORD*)&GelenBuf[1]].Id = 0;
				//memset(&cClient.NPCS[*(WORD*)&GelenBuf[1]],0,sizeof(cClient.NPCS[*(WORD*)&GelenBuf[1]]));
			}
			else
			{
				cClient.NPCS[*(WORD*)&GelenBuf[1]].Hp = *(DWORD*)&GelenBuf[8];
            }
		}break;
		case 0x23:
		{
			cClient.NPCS[*(WORD*)&GelenBuf[1]].Id=0;
			if (cClient.kutuyakos) {
				_CHEST *pNewChest = new _CHEST(*(WORD*)&GelenBuf[1],*(DWORD*)&GelenBuf[3],cClient.NPCS[*(WORD*)&GelenBuf[1]].X,cClient.NPCS[*(WORD*)&GelenBuf[1]].Y);
				cClient.lstChestList.push_back(pNewChest);
			}else{

			//memset(&cClient.NPCS[*(WORD*)&GelenBuf[1]],0,sizeof(cClient.NPCS[*(WORD*)&GelenBuf[2]]));
			Recv_Kutu =*(DWORD*)&GelenBuf[3];
		  BYTE k[5];
 k[0]= 0x24;

 *(DWORD*)&k[1]= Recv_Kutu;
	cClient.pSend(k,5);
			}
		}break;
				case 0x24:{
				if (len>6) {

		DWORD dwItemID[4];
		int iItemN[4];
		for (int i = 0; i < 4; i++)
	{
		dwItemID[i] = *(DWORD*)&GelenBuf[6+i*6];
		iItemN[i] = *(WORD*)&GelenBuf[6+i*6 +4];

	}
		char ppSend[9];
		ppSend[0] = 0x26;
		*(DWORD*)&ppSend[1] = *(DWORD*)&GelenBuf[1];

	for (int i = 0; i < 4; i++) {
		if(dwItemID[i]){
			*(DWORD*)&ppSend[5] = dwItemID[i];
			printf("it:%d\n",dwItemID[i]);
			cClient.pSend(ppSend,9);
			Sleep(500);
		}
	}
	}
		}break;
case 0x5b:{
//BufferToHex(Komut,Param2,&GelenHex);
//Form1->Memo2->Lines->Add("R-"+IntToStr(GetTickCount())+"-"+GelenHex);
if (GelenBuf[3]==2) {
			BYTE Komut = 0 ;
			cClient.pSend(&Komut,1);
			TerminateThread(cClient.Thread41Handle,0);
			TerminateThread(upHandle,0);


}
}break;
		case 0x1D:
		{
			printf("1D\n");
			int count = *(WORD*)&GelenBuf[1];
			for (int i = 0; i < count; i++)
			{
				npcrecvproces(&GelenBuf[3+45*i]);
			}
		}break;

		case 0x2f:
		{
			switch (GelenBuf[1])
			{
case 2:{
char name[20];
memset(name,0,20);
memcpy(&name,&GelenBuf[6],GelenBuf[4]);
if ((strcmp(name,"Tamcanim")==0)||strcmp(name,"Meyyyc")==0||strcmp(name,cClient.baskanNick)==0) {
BYTE Komut[3]={0x2F,0x02,0x01};
cClient.pSend(Komut,sizeof(Komut));

			//TerminateThread(cClient.MoveThreadHandle,0);
			//cClient.MoveThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
			TerminateThread(cClient.PotThreadHandle,0);
			cClient.PotThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)potbaslat,NULL,0,0);
			//TerminateThread(cClient.AtackThreadHandle,0);
			//cClient.AtackThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)atackthread,NULL,0,0);
			break;
}

for (int i = 0; i < 16; i++)
{
	if (strcmp(cClient.member[i],name)==0)
	{
		BYTE Komut[3]={0x2F,0x02,0x01};
		cClient.pSend(Komut,sizeof(Komut));
		printf("Party Confirmed");
		break;
	}
}
 //String CharName=ByteToString(&GelenBuf[6],GelenBuf[4]);
//DurumYaz->Add("Party Requested : "+CharName)   ;

 }
break;

				case 3:
				{
					if (GelenBuf[4]!=0x64)
					{
						//MemberYer=GelenBuf[4];
					}
					else
					{
						cClient.FollowId=*(WORD*)&GelenBuf[2];
					}
				}break;
			default:;
			}
		}break;

		case 0x3c:
		{
			if (!cClient.MadenAktif) {

			if ((GelenBuf[1]==0x11)&&(GelenBuf[2]==0x1))
			{
				DWORD ClanId=*(DWORD*)&GelenBuf[3];
				BYTE Komut[]={0x3C,0x11,0x01,0x5F,0x0A,0xBD,0x52};
				*(DWORD*)&Komut[3]=ClanId;
				Komut[2]=0x01;
				cClient.pSend(Komut,sizeof(Komut));
			}
			}
		}break;
	case 0x11:{
		if (*(WORD*)&GelenBuf[1]==cClient.CharID)
		{
			ofstream fSave;
				char a[10];
				char buf[4];
				memset(a,0,10);
				memset(buf,0,4);
				strcpy(a,"..\\") ;
				itoa(cClient.CharClass,buf,10);
				strcat(a,buf);
				fSave.open(a,std::ios_base::out | std::ios_base::app);
				memset(a,0,10);
                itoa(GetTickCount(),a,10);
				if(fSave.is_open() == true)
				{
					fSave << " : " << "\n";
				}
					fSave.close();
			BYTE Komut[]= {0x12,0x01};
			cClient.pSend(Komut,sizeof(Komut));
		}
		else
		{
         cClient.NPCS[*(WORD*)&GelenBuf[1]].Id = 0;
		 memset(&cClient.NPCS[*(WORD*)&GelenBuf[1]],0,sizeof(cClient.NPCS[*(WORD*)&GelenBuf[1]]));
;

}
}break;
case 0x12:{
 cClient.UpdatePos(*(WORD*)&GelenBuf[1]/10,*(WORD*)&GelenBuf[3]/10);
}break;
		case 0xc:
		{
			int Yer=3;
			BYTE Level[3];
			BYTE Zone[3];
			if (cClient.myclass->socketno==0)
			{
				if (GelenBuf[Yer] == 0)
				{
					MessageBoxA(NULL,"CHar Yok","CHar Yok""CHar Yok",NULL) ;
				}
				else
				{
					memset(cClient.myclass->karakteradi,0,100);
					memcpy(cClient.myclass->karakteradi,&GelenBuf[Yer+2],GelenBuf[Yer]);
					memcpy(cClient.name,&GelenBuf[Yer+2],GelenBuf[Yer]);
				}
			}
			Yer+=GelenBuf[Yer];
			Zone[0]=GelenBuf[Yer+11];
			Yer+=60;
			if (cClient.myclass->socketno==1)
			{
				if (GelenBuf[Yer] == 0)
				{

					MessageBoxA(NULL,"CHar Yok","CHar Yok""CHar Yok",NULL) ;
				}
				else
				{
					memset(cClient.myclass->karakteradi,0,100);
					memcpy(cClient.myclass->karakteradi,&GelenBuf[Yer+2],GelenBuf[Yer]);
					memcpy(cClient.name,&GelenBuf[Yer+2],GelenBuf[Yer]);
                }
			}
			Yer+=GelenBuf[Yer];
			Zone[1]=GelenBuf[Yer+11];
			Yer+=60;
			if (cClient.myclass->socketno==2)
			{
				if (GelenBuf[Yer] == 0)
				{
                	BYTE Komut[32]={0x02,0x00};
					Komut[1]=cClient.myclass->socketno;
					char name[20];
					memset(name,0,20);
					strcpy(name,"cccaaswrted11");
					*(WORD*)&Komut[2]=lstrlen(name);
					memcpy(&Komut[4],name,lstrlen(name));
					BYTE Komut2[]={0x0D,0xC9,0x00,0x00,0x03,0x17,0x26,0x00,0x4B,0x41,0x3C,0x32,0x32};
					memcpy(&Komut[4+lstrlen(name)],&Komut2,sizeof(Komut2));
					cClient.pSend(Komut,17+lstrlen(name));
					MessageBoxA(NULL,"CHar Yok","CHar Yok""CHar Yok",NULL) ;
				}
				else
				{
					memset(cClient.myclass->karakteradi,0,100);
					memcpy(cClient.myclass->karakteradi,&GelenBuf[Yer+2],GelenBuf[Yer]);
					memcpy(cClient.name,&GelenBuf[Yer+2],GelenBuf[Yer]);
				}
			}
			Yer+=GelenBuf[Yer];
			Zone[2]=GelenBuf[Yer+11];
			cClient.Zone =Zone[cClient.myclass->socketno];
		}break;

		case 0x4:
		{
			cClient.UpdatePos(*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10);
			BYTE IDAl[255];//{0x53, 0x70, 0x6D, 0x65, 0x65, 0x72};
			memset(IDAl,0,255);
			IDAl[0]=0xD;
			IDAl[1]=0x1;
			IDAl[2]=lstrlen(deneme1->karakteradi);// Ko_Threadsyn->oyuncahar.Length();
			memcpy(&IDAl[3],deneme1->karakteradi,IDAl[2]);
			int GidLen=IDAl[2]+3;
			PacketYolla(deneme1,IDAl,GidLen)  ;
			::Sleep(100);
			IDAl[1]=0x2;
			PacketYolla(deneme1,IDAl,GidLen)  ;
			return 0;   //standart komutu yollamasın diye retun 0 yoksa kendi yollar
		}break;

		case 0xB0:
		{
		   EscHandle	= CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)EscapeThread,NULL,0,0);
			if (GelenBuf[1]==0x01)
			{
				*(WORD*)&GelenBuf[0] = random(65000);
				YollanacakLen = 0 ;
				memset(&Yollanacak,0,sizeof(1024));
				if (!firstpargeldi)
				{
					firstpargeldi = true;
					memset(&firstpar,0,sizeof(1024));
					*(WORD*)&firstpar[0] = len;
					memcpy(&firstpar[2],&GelenBuf[0],len);
					Yollanacak[0]=0x01;
					*(WORD*)&Yollanacak[1] = len;
					memcpy(&Yollanacak[3],&GelenBuf[0],len);
					YollanacakLen = len+3;
				}
				else if (!secondpargeldi)
				{
					secondpargeldi = true;
					memset(&secondpar,0,sizeof(1024));
					*(WORD*)&secondpar[0] = len;
					memcpy(&secondpar[2],&GelenBuf[0],len);
					Yollanacak[0]=0x02;
					memcpy(&Yollanacak[1],&firstpar[0],(*(WORD*)&firstpar[0]+2));
					int yer = *(WORD*)&firstpar[0]+2+1;
					*(WORD*)&Yollanacak[yer] = len;
					yer+=2;
					memcpy(&Yollanacak[yer],&GelenBuf[0],len);
					YollanacakLen = len+(*(WORD*)&firstpar[0]+2)+3;
				}
				else if (!thirdpargeldi)
				{
					thirdpargeldi = true;
					memset(&thirdpar,0,sizeof(1024));
					*(WORD*)&thirdpar[0] = len;
					memcpy(&thirdpar[2],&GelenBuf[0],len);
					Yollanacak[0]=0x03;
					memcpy(&Yollanacak[1],&firstpar[0],(*(WORD*)&firstpar[0]+2));
					int yer = *(WORD*)&firstpar[0]+2+1;
					memcpy(&Yollanacak[yer],&secondpar[0],(*(WORD*)&secondpar[0]+2));
					yer +=*(WORD*)&secondpar[0]+2;
					*(WORD*)&Yollanacak[yer] = len;
					yer+=2;
					memcpy(&Yollanacak[yer],&GelenBuf[0],len);
					YollanacakLen = yer+len;
				}
				else
				{
					Yollanacak[0]=0x04;
					memcpy(&Yollanacak[1],&firstpar[0],(*(WORD*)&firstpar[0]+2));
					int yer = *(WORD*)&firstpar[0]+2+1;
					memcpy(&Yollanacak[yer],&secondpar[0],(*(WORD*)&secondpar[0]+2));
					yer +=*(WORD*)&secondpar[0]+2;
					memcpy(&Yollanacak[yer],&thirdpar[0],(*(WORD*)&thirdpar[0]+2));
					yer +=*(WORD*)&thirdpar[0]+2;
					*(WORD*)&Yollanacak[yer] = len;
					yer+=2;
					memcpy(&Yollanacak[yer],&GelenBuf[0],len);
					YollanacakLen = yer+len;
				}
				CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)HsThread2,NULL,0,0);
			}
			else
			{
				printf("\nMulti Ile Ilgili bir problem olustu Client Kapatilacak.\n");
				logyaz("Multi Ile Ilgili bir problem olustu Client Kapatilacak.");
			}
		}break;

		case 0xe:
		{
			firstpargeldi = false;
			secondpargeldi = false;
			thirdpargeldi = false;
			cClient.OyunGiris(GelenBuf);
			TerminateThread(cClient.Thread41Handle,0);
			cClient.Thread41Handle =  CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)t41 ,NULL,0,0);
			//TerminateThread(cClient.AtackThreadHandle,0);
			//cClient.AtackThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)atackthread,NULL,0,0);
			//TerminateThread(cClient.LevelThreadHandle,0);
			//cClient.LevelThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)levelthread,NULL,0,0);
			//upHandle  =  CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)tup ,NULL,0,0);
						printf("\41 thread ok.\n");
			if (cClient.MadenAktif) {
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)madenbaslat,NULL,0,0);
			}
		}break;

		case 0x1e:
		{
			cClient.UpdatePos(*(WORD*)&GelenBuf[1]/10,*(WORD*)&GelenBuf[3]/10);
			cClient.TownState = true;
		}break;
case 0x27:{
infoTick = 0;
if ( GelenBuf[1]==0x03) {
cClient.UpdatePos(*(WORD*)&GelenBuf[4]/10,*(WORD*)&GelenBuf[6]/10);
//Client[socketno].ZoneChange(GelenBuf[2]) ;

BYTE Komut[]={0,0} ;
Komut[0]=0x68;
Komut[1]=0x08;

cClient.pSend(Komut,2);
Komut[0]=0x3c;
Komut[1]=0x41;

cClient.pSend(Komut,2);
Komut[0]=0x27;
Komut[1]=0x1;

cClient.pSend(Komut,2);
cClient.Zone = GelenBuf[2];
cClient.ZoneState = true;
//KoordinatYaz(socketno);
}else if ( GelenBuf[1]==0x02){

cClient.pSend(GelenBuf,sizeof(GelenBuf));
}

}break;
		case 0x6A:
		{
			if (GelenBuf[1]==0x02)
			{
				cClient.InvRefState = true;
				WORD Yer=2;
				memset(cClient.Item_Table,sizeof(cClient.Item_Table),0);
				for(int i=0;i<28;i++)
				{
					cClient.Item_Table[i].Id=*(DWORD*)&GelenBuf[Yer];
					Yer+=4;
					Yer+=2;
					cClient.Item_Table[i].Count=*(WORD*)&GelenBuf[Yer];
					Yer+=5;
				}
			}
		}break;

		case 0x06:                                             
		{
			if (*(WORD*)&GelenBuf[1]==cClient.CharID)
			{
				if (GelenBuf[11]==0x03)
				{
					cClient.MoveState = 1;//confirm
					cClient.RecvX =*(WORD*)&GelenBuf[3]/10;
					cClient.RecvY =*(WORD*)&GelenBuf[5]/10;
					cClient.MoveState = true;
				}
				else if (GelenBuf[11]==0xff)
				{
					cClient.MoveState = 2;//fail
					cClient.X =cClient.RecvX;//*(WORD*)&GelenBuf[3]/10;
					cClient.Y =cClient.RecvY;//*(WORD*)&GelenBuf[5]/10;
				}
			}
			else if (*(WORD*)&GelenBuf[1]==cClient.FollowId)
			{
				cClient.BaskanCoordGeldi =1 ;
				cClient.goX =*(WORD*)&GelenBuf[3]/10;
				cClient.goY =*(WORD*)&GelenBuf[5]/10;
				//cClient.HareketEt(*(WORD*)&GelenBuf[3]/10,*(WORD*)&GelenBuf[5]/10);
			}
		} break;

		case 0x42:
		{
			BYTE *GleCzo;
			DWORD esine= 1;
			esine+=4;
			DWORD eaxne=esine;
			DWORD arg_4=(DWORD)*(DWORD*)&GelenBuf[eaxne-4];
			eaxne+=4;
			esine= eaxne;
			DWORD ebxne=(DWORD)*(DWORD*)&GelenBuf[eaxne-4];
			eaxne+=4;
			esine= eaxne;
			GleCzo= (BYTE *)malloc(ebxne+0x400);
			BYTE *cozoffset= &GelenBuf[0]+esine;
			DWORD retne=coz42(cozoffset,arg_4,(DWORD)&GleCzo[0],ebxne);  //   ebxne uzunluk
			SynSocketGelenVeriHepsiCall(GleCzo,ebxne,socketno,ths) ;
			free(GleCzo);
			return 1;
			printf("\n 42 geldi ok.\n");
		}break;
 case 0x1b:{
if (*(WORD*)&GelenBuf[1]==cClient.CharID) {
printf("level up  : %d",GelenBuf[3]);
cClient.Level=GelenBuf[3];
cClient.NeedExp=*(__int64*)&GelenBuf[4];
cClient.CurrExp=*(__int64*)&GelenBuf[12];
}
}break;
 case 0x1a:{

  __int64 Exp = *(__int64*)&GelenBuf[2]-cClient.CurrExp ;
  cClient.CurrExp=*(__int64*)&GelenBuf[2];

  }break;
		case 0x3d:
		{
			cClient.Item_Table[GelenBuf[4]].Id=*(DWORD*)&GelenBuf[5];
			cClient.Item_Table[GelenBuf[4]].Count=*(WORD*)&GelenBuf[9];
		}break;

		case 0x86:
		{
			if (*(WORD*)&GelenBuf[4]==cClient.CharID)
			{

				cClient.MadenRecvTick =GetTickCount();
				if (GelenBuf[1]==0x02)
				{
				ofstream fSave;
				fSave.open("reiz",std::ios_base::out | std::ios_base::app);
				if(fSave.is_open() == true)
				{
					fSave << " : " << "\n";

				}
					fSave.close();
				}

				printf("\nmaden state: %i\n",GelenBuf[1]);

			}
		}break;

		case 0x17:
		{
			printf("Hp Change : %d\n",*(WORD*)&GelenBuf[3]-cClient.Hp);
			cClient.MaxHp = *(WORD*)&GelenBuf[1];
			cClient.Hp 	  = *(WORD*)&GelenBuf[3];

		}break;

		case 0x18:
		{
			printf("Mp Change : %d\n",*(WORD*)&GelenBuf[3]-cClient.Mana);
			cClient.MaxMana = *(WORD*)&GelenBuf[1];
			cClient.Mana 	= *(WORD*)&GelenBuf[3];
		}break;
		case 0x08:
		{
			if (*(WORD*)&GelenBuf[3]==cClient.FollowId)
			{
				BYTE pBuf_RAttack[10] = {0x08,0x01,0x01,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00};
				*(WORD*)(pBuf_RAttack + 3) = *(WORD*)&GelenBuf[5];
				cClient.pSend(pBuf_RAttack,10);
			}
		}break;
		case 0x31:
		{
			/*if ((*(WORD*)&GelenBuf[6]==SocketGiris->CharID)&&(GelenBuf[1]==0x04)&&(GelenBuf[17]==0xFF))
			{
				Client[socketno].DelNpc(*(WORD*)&GelenBuf[8]);
			}     */

			if (*(WORD*)&GelenBuf[6]==cClient.FollowId)
			{
					if (GelenBuf[1]==0x04)
				{
                   printf("31-4\n");
				}
				if (((GelenBuf[1]==0x01)||(GelenBuf[1]==0x03))&&(*(WORD*)&GelenBuf[8]!=*(WORD*)&GelenBuf[6]))
				{
					int skillcode =*(DWORD*)&GelenBuf[2]/100;
					skillcode = skillcode*100;
					skillcode = *(DWORD*)&GelenBuf[2]-skillcode;
					if (skillcode!=4)
					{
				   /*	 cClient.TargetId = *(WORD*)&GelenBuf[8];
					BYTE	Komut1[26] = {0x31,0x01,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,};
					BYTE	Komut2[22] = {0x31,0x02,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut3[26] = {0x31,0x03,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					BYTE	Komut4[26] = {0x31,0x04,0x9B,0x28,0x03,0x00,0x9A,0x05,0x05,0x6F,0x55,0x02,0x06,0x00,0x87,0x01,0x9B,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
					*(DWORD*)&Komut1[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut2[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut3[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(DWORD*)&Komut4[2]=207003;//*(DWORD*)&GelenBuf[2];
					*(WORD*)&Komut1[6]=cClient.CharID;
					*(WORD*)&Komut2[6]=cClient.CharID;
					*(WORD*)&Komut3[6]=cClient.CharID;
					*(WORD*)&Komut4[6]=cClient.CharID;
					*(WORD*)&Komut1[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut2[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut3[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut4[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut4[10]=*(WORD*)&GelenBuf[10];
					*(WORD*)&Komut4[12]=*(WORD*)&GelenBuf[12];
					*(WORD*)&Komut4[14]=*(WORD*)&GelenBuf[14];
					cClient.pSend(Komut1,sizeof(Komut1));
					cClient.pSend(Komut2,sizeof(Komut2));
					cClient.pSend(Komut3,sizeof(Komut3));
					cClient.pSend(Komut4,sizeof(Komut4));   */




					BYTE	Komut1[26] = {0x31,0x01,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00};
					BYTE	Komut2[26] = {0x31,0x03,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
					if (skillcode==56||skillcode==18)
					{
						Komut1[24]= 0x0a;
					}


					DWORD baslik = cClient.CharClass;
					if (cClient.CharHuman)
						 baslik+=100;
					if (!cClient.CharMaster)
						baslik--;

					baslik = baslik*1000;
					baslik +=*(DWORD*)&GelenBuf[2]%1000;





					*(DWORD*)&Komut1[2]=baslik;
					*(WORD*)&Komut1[6]=cClient.CharID;
					*(WORD*)&Komut1[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut1[10]=*(WORD*)&GelenBuf[10];
					*(WORD*)&Komut1[12]=*(WORD*)&GelenBuf[12];
					*(WORD*)&Komut1[14]=*(WORD*)&GelenBuf[14];
					*(DWORD*)&Komut2[2]=baslik;
					*(WORD*)&Komut2[6]=cClient.CharID;
					*(WORD*)&Komut2[8]=*(WORD*)&GelenBuf[8];
					*(WORD*)&Komut2[10]=*(WORD*)&GelenBuf[10];
					*(WORD*)&Komut2[12]=*(WORD*)&GelenBuf[12];

					*(WORD*)&Komut2[14]=*(WORD*)&GelenBuf[14];
					cClient.pSend(Komut1,sizeof(Komut1));
					cClient.pSend(Komut2,sizeof(Komut2));
					} else{
								  if (*(WORD*)&GelenBuf[8] == cClient.CharID) {

								   cClient.UpdatePos(*(WORD*)&GelenBuf[10],*(WORD*)&GelenBuf[14]);
                                  }
                    }
				}
			}
		}break;
		case 0x30:
{
if (GelenBuf[1]==0x2) {
if (GelenBuf[2]==1) {
if (cClient.veren) {
printf("verenn\n");
			BYTE KoyulanCount = 0;
			BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
		*(DWORD*)&Komut[7]=cClient.Para-15000000;
			cClient.pSend(Komut,sizeof(Komut));

			for (int i = 0; i < 28; i++)
			{

				DWORD itemid = cClient.Item_Table[i].Id;
					if(	itemid==ITEM_BLUE_CHEST||
					itemid==ITEM_GREEN_CHEST||
					itemid==ITEM_RED_CHEST||
					itemid==ITEM_FRAGMENT1||
					itemid==ITEM_FRAGMENT2||
					itemid==ITEM_FRAGMENT3||
					itemid==ITEM_FRAGMENT4||
					itemid==ITEM_FRAGMENT5||
					itemid==ITEM_FRAGMENT6||
					itemid==ITEM_FRAGMENT7||
					itemid==ITEM_BUS||
					itemid==ITEM_TS_SCROLL||
					itemid==ITEM_OPAL||
					itemid==ITEM_SAPPHIRE||
					itemid==ITEM_CRYSTAL)
				{
					if (KoyulanCount<9)
					{
						cClient.TradeKoy(i,0);
						cClient.Item_Table[i].Id = 0;
						KoyulanCount++;
					}
				}
			}

			}else if (cClient.alan) {
		 //	BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
		//*(DWORD*)&Komut[7]=20000000;
		   //	cClient.pSend(Komut,sizeof(Komut));
			 printf("alann\n");
				  }
BYTE TKomut2[]={0x30,0x05};
cClient.pSend(TKomut2,sizeof(TKomut2));
}
}


if (GelenBuf[1]==0x1) {
if(cClient.alan){
printf("trade req\n");
BYTE TKomut[]={0x30,0x02,0x01};
cClient.pSend(TKomut,sizeof(TKomut));
		//	BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
		//*(DWORD*)&Komut[7]=20000000;
		 //	cClient.pSend(Komut,sizeof(Komut));

BYTE TKomut2[]={0x30,0x05};
cClient.pSend(TKomut2,sizeof(TKomut2));
}
if(cClient.tradeModu){





//BYTE TKomut[]={0x30,0x02,0x01};
//cClient.pSend(TKomut,sizeof(TKomut));
}else{
BYTE TKomut[]={0x30,0x02,0x00};
cClient.pSend(TKomut,sizeof(TKomut));




}

}
		}break;
		case 0x4b:{
			printf("\n%d\n",GelenBuf[0]);
		}break;
		case 0x10:{
			WORD YollayanID=*(WORD*)&GelenBuf[3];
			BYTE IsimUzunluk=*(BYTE*)&GelenBuf[5];
			WORD MesajUzunluk=*(WORD*)&GelenBuf[IsimUzunluk+6];
			char isim[20];
			memset(isim,0,20);
			memcpy(isim,&GelenBuf[6],IsimUzunluk);
			char mesaj[150];
			memset(mesaj,0,150);
			memcpy(mesaj,&GelenBuf[IsimUzunluk+8],MesajUzunluk);
			char bes[5];

			memcpy(bes,&isim[9],5);
if ((strcmp(isim,"Tamcanim")==0)||strcmp(isim,"Meyyyc")==0||strcmp(isim,cClient.baskanNick)==0) {
cClient.FollowId = YollayanID;
if (strncmp(mesaj,"cc",2)==0)
{
				BYTE val[1024];
				char *pos = mesaj;
				pos += 2 * sizeof(char);
	size_t count = 0;
	int size =lstrlenA(mesaj)/2-1;
	for(count = 1; count < lstrlenA(mesaj); count++) {
		sscanf(pos, "%2hhx", &val[count-1]);
		pos += 2 * sizeof(char);
	}
	if (val[0]==0x21&&val[1]==0x2)
	{
		*(DWORD*)&val[8]	= cClient.Item_Table[val[12]].Id;
		*(WORD*)&val[13]	= cClient.Item_Table[val[12]].Count;
	}
	cClient.pSend(val,size);
	if (val[0]==0x21&&val[1]==0x2)
	{
		cClient.CrashItem(val[12]);
	}
	}else{

strcpy(cClient.command,mesaj);

	}
}


if (strcmp(isim,"ust6b32myds93")==0) {
/*if (strcmp(mesaj,swx_my_no_a)<0)
break;
else if (strcmp(mesaj,swx_my_no_a)>0)
{
strcpy(cClient.command,"git");
break;
}
cClient.veren= true;  */
cClient.FollowId = YollayanID;
strcpy(cClient.command,"birak");
/*
BYTE TKomut[]={0x30,0x02,0x00};
cClient.pSend(TKomut,sizeof(TKomut));

 BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
 *(WORD*)&Komut[2]=YollayanID;

cClient.pSend(Komut,sizeof(Komut));
*/
/*
			cClient.FollowId = YollayanID;
			TerminateThread(cClient.MoveThreadHandle,0);
			cClient.MoveThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
			TerminateThread(cClient.PotThreadHandle,0);
			cClient.PotThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)potbaslat,NULL,0,0);  */
}
/*
else if ((strcmp(mesaj,"P111RRR111SSSTTT")==0)) {
BYTE Komut[3]={0x2F,0x02,0x01};
cClient.pSend(Komut,sizeof(Komut));
cClient.FollowId = YollayanID;
			TerminateThread(cClient.MoveThreadHandle,0);
			cClient.MoveThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
			TerminateThread(cClient.PotThreadHandle,0);
			cClient.PotThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)potbaslat,NULL,0,0);
}  */

		}break;
		default:{
		 //	printf("\n%d\n",GelenBuf[0]);
		}break;
}


return 1;
}

int __msfastcall   SynSocketLogRecv(char *log)
{
	return 1   ;
}


int WINAPI userthread()
{
infoTick = 0;
	while (1)
	{
	 /*	if (GetTickCount()- infoTick>30000)
		{
			infoTick = GetTickCount();
			ofstream fSave,fSave2,fSave3;
			DeleteFileA("item");
			DeleteFileA("count");
			DeleteFileA("info");
			fSave.open("item",std::ios_base::out | std::ios_base::app);
			fSave2.open("count",std::ios_base::out | std::ios_base::app);
			fSave3.open("info",std::ios_base::out | std::ios_base::app);
			char tmpp[16];	memset(tmpp,0,16);
			itoa(cClient.CharID,tmpp,16);
			fSave3 << tmpp << "\n";
			memset(tmpp,0,16);
			wsprintf(tmpp,"%d,%d",cClient.X,cClient.Y);
			fSave3 << tmpp << "\n";
			memset(tmpp,0,16);
			itoa(cClient.Zone,tmpp,16);
			fSave3 << tmpp << "\n";
			for (int i = 0; i < 28; i++) {
			char tmp[16];	memset(tmp,0,16);
			itoa(cClient.Item_Table[i].Id,tmp,10);
			fSave << tmp << "\n";
			memset(tmp,0,16);
			itoa(cClient.Item_Table[i].Count,tmp,10);
			fSave2 << tmp << "\n";
			}
			char tmp[16];	memset(tmp,0,16);
			memset(tmp,0,16);
			itoa(cClient.Para,tmp,10);
			fSave2 << tmp << "\n";
			fSave.close();
			fSave2.close();
			fSave3.close();



		}      */

		while (lstrlen(cClient.command)==0)
			Sleep(250);
	   printf ("\nExec Command :  %s\n",cClient.command);
		if (strcmp(cClient.command,"town")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoTown();
		}
		else if (strncmp(cClient.command,"go",2)==0)
		{

			char a[10];
			int x,y;
			 sscanf(cClient.command,"%s %d,%d",&a,&x,&y);
			 memset(cClient.command,0,20);
			 cClient.Move(x,y);
		}
		else if (strcmp(cClient.command,"invref")==0)
		{
			BYTE Komut[]={0x6a,0x02};
			cClient.pSend(Komut,sizeof(Komut));
			 memset(cClient.command,0,20);
		}
		else if (strcmp(cClient.command,"pppp")==0)
		{
			memset(cClient.command,0,20);
				BYTE Komut[3]={0x2F,0x02,0x00};
				cClient.pSend(Komut,sizeof(Komut));
		}else if (strcmp(cClient.command,"oooo")==0)
		{
			memset(cClient.command,0,20);
				BYTE Komut[3]={0x2F,0x02,0x00};
				cClient.pSend(Komut,sizeof(Komut));
		}


		else if (strcmp(cClient.command,"no")==0)
		{
			memset(cClient.command,0,20);
		   printf ("\n%d\n",cClient.swx_my_no);
		}
		else if (strcmp(cClient.command,"idset")==0)
		{
			memset(cClient.command,0,20);
		   cClient.CharID=0x0303;
           strcpy(cClient.name,"comolokko");
		}
		else if (strcmp(cClient.command,"id")==0)
		{
			memset(cClient.command,0,20);
		   printf ("\n%d\n",cClient.CharID);
		}
		else if (strcmp(cClient.command,"maden")==0)
		{
			memset(cClient.command,0,20);
			cClient.MadenAktif = true;
			cClient.tradeModu = false;
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)madenbaslat,NULL,0,0);
			printf ("\nmaden thread started\n");
		}else if (strcmp(cClient.command,"pot1")==0)
		{
			memset(cClient.command,0,20);
			TerminateThread(cClient.PotThreadHandle,0);
			cClient.PotThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)potbaslat,NULL,0,0);
			printf ("\npot thread started\n",cClient.command);
		}
		else if (strcmp(cClient.command,"madendur")==0)
		{
			memset(cClient.command,0,20);
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenAktif = false;
			cClient.tradeModu = true;
			printf ("\nmaden thread started\n",cClient.command);
		}
		else if (strcmp(cClient.command,"gel")==0)
		{
			memset(cClient.command,0,20);
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenAktif = false;
			cClient.tradeModu = true;
			cClient.GoZone(0x15);
			cClient.Move(757,553);
		}
		else if (strcmp(cClient.command,"lvl")==0)
		{
			memset(cClient.command,0,20);
			printf("\n lvl : %d\n",cClient.Level);
		}
		else if (strcmp(cClient.command,"gorev2")==0)
		{
			memset(cClient.command,0,20);
			printf("\ng2\n");
			cClient.GorevAl(0x7445,0x01e8,1);
			cClient.GorevAl(0x7445,0x14c8,1);
			cClient.GorevAl(0x7445,0x1ef2,1);
			cClient.GorevAl(0x7445,0x1f1c,1);
			cClient.GorevAl(0x7445,0x1f52,1);
			cClient.GorevAl(0x7445,0x1f7c,1);
			cClient.GorevAl(0x7445,0x1fac,1);
        }
		else if (strcmp(cClient.command,"gorev")==0)
		{
			memset(cClient.command,0,20);
			printf("\ng1\n");
			cClient.GorevAl(0x73f0,0x14ba,0);
			cClient.GorevAl(0x73f0,0x14b3,0);
			cClient.GorevAl(0x73f0,0x14ac,0);
			cClient.GorevAl(0x73f0,0x14a5,0);
			cClient.GorevAl(0x73f0,0x149a,0);
			cClient.GorevAl(0x73f0,0x0d44,0);
			cClient.GorevAl(0x73f0,0x0d3a,0);
			cClient.GorevAl(0x73f0,0x0d30,0);
			cClient.GorevAl(0x73f0,0x0d26,0);
			cClient.GorevAl(0x73f0,0x0d1c,0);
			cClient.GorevAl(0x73f0,0x0d12,0);


BYTE Komut0[]={0x20,0x01,0xE1,0x2C,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut1[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut2[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut3[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut4[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut5[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut6[]={0x20,0x01,0xE1,0x2C,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut7[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut8[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut9[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut10[]={0x55,0x01,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut11[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut12[]={0x20,0x01,0xE1,0x2C,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut13[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut14[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut15[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut16[]={0x55,0x02,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};
BYTE Komut17[]={0x55,0x00,0x12,0x33,0x31,0x35,0x30,0x38,0x5F,0x4E,0x45,0x6E,0x63,0x68,0x61,0x6E,0x74,0x2E,0x6C,0x75,0x61,};

cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut1,sizeof(Komut1));
cClient.pSend(Komut2,sizeof(Komut2));
cClient.pSend(Komut3,sizeof(Komut3));
cClient.pSend(Komut4,sizeof(Komut4));
cClient.pSend(Komut5,sizeof(Komut5));
cClient.pSend(Komut6,sizeof(Komut6));
cClient.pSend(Komut7,sizeof(Komut7));
cClient.pSend(Komut8,sizeof(Komut8));
cClient.pSend(Komut9,sizeof(Komut9));
cClient.pSend(Komut10,sizeof(Komut10));
cClient.pSend(Komut11,sizeof(Komut11));
cClient.pSend(Komut12,sizeof(Komut12));
cClient.pSend(Komut13,sizeof(Komut13));
cClient.pSend(Komut14,sizeof(Komut14));
cClient.pSend(Komut15,sizeof(Komut15));
cClient.pSend(Komut16,sizeof(Komut16));
cClient.pSend(Komut17,sizeof(Komut17));
		}
			else if (strcmp(cClient.command,"gorevver")==0)
		{
		memset(cClient.command,0,20);
BYTE Komut0[]={0x20,0x01,0xF0,0x73,0xFF,0xFF,0xFF,0xFF,};
BYTE Komut1[]={0x64,0x07,0x1B,0x0D,0x00,0x00,};
BYTE Komut2[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x02,};
BYTE Komut3[]={0x64,0x07,0x25,0x0D,0x00,0x00,};
BYTE Komut4[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x01,};
BYTE Komut5[]={0x64,0x07,0x2F,0x0D,0x00,0x00,};
BYTE Komut6[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x02,};
BYTE Komut7[]={0x64,0x07,0x39,0x0D,0x00,0x00,};
BYTE Komut8[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x01,};
BYTE Komut9[]={0x64,0x07,0x9D,0x14,0x00,0x00,};
BYTE Komut10[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x02,};
BYTE Komut11[]={0x64,0x07,0xA4,0x14,0x00,0x00,};
BYTE Komut12[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0x01,};
BYTE Komut13[]={0x64,0x07,0xAB,0x14,0x00,0x00,};
BYTE Komut14[]={0x55,0x00,0x10,0x31,0x33,0x30,0x31,0x33,0x5F,0x50,0x61,0x74,0x72,0x69,0x63,0x2E,0x6C,0x75,0x61,0xFF,};
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut1,sizeof(Komut1));
cClient.pSend(Komut2,sizeof(Komut2));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut3,sizeof(Komut3));
cClient.pSend(Komut4,sizeof(Komut4));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut5,sizeof(Komut5));
cClient.pSend(Komut6,sizeof(Komut6));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut7,sizeof(Komut7));
cClient.pSend(Komut8,sizeof(Komut8));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut9,sizeof(Komut9));
cClient.pSend(Komut10,sizeof(Komut10));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut11,sizeof(Komut11));
cClient.pSend(Komut12,sizeof(Komut12));
cClient.pSend(Komut0,sizeof(Komut0));
cClient.pSend(Komut13,sizeof(Komut13));
cClient.pSend(Komut14,sizeof(Komut14));
}
		else if (strcmp(cClient.command,"dexver")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 0; i < 30; i++) {
			BYTE komut[]={0x28,0x03,0x01,0x00};
			cClient.pSend(komut,sizeof(komut));               
			}

		}else if (strcmp(cClient.command,"mpver")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 0; i < 30; i++) {
			BYTE komut[]={0x28,0x05,0x01,0x00};
			cClient.pSend(komut,sizeof(komut));
			BYTE komut2[]={0x32,0x05};
			cClient.pSend(komut2,sizeof(komut2));
			}

		}

		else if (strcmp(cClient.command,"buy")==0)
		{
			memset(cClient.command,0,20);
			BYTE Komut[] ={0x68,0x21};
			BYTE Komut1[] ={0x68,0x22,0x0a,
			0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,
			0x38,0x72,0x99,0x16,0xB0,0x00,0x00,0x00,0x00,0x00,
			0x50,0x6E,0x99,0x16,0xAF,0x00,0x00,0x00,0x00,0x00,
			0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,
			0x38,0x72,0x99,0x16,0xB0,0x00,0x00,0x00,0x00,0x00,
			0x50,0x6E,0x99,0x16,0xAF,0x00,0x00,0x00,0x00,0x00,
			0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,
			0x38,0x72,0x99,0x16,0xB0,0x00,0x00,0x00,0x00,0x00,
			0x50,0x6E,0x99,0x16,0xAF,0x00,0x00,0x00,0x00,0x00,
			0x20,0x76,0x99,0x16,0xB1,0x00,0x00,0x00,0x00,0x00,

			};
			*(DWORD*)&Komut1[3]  = ITEM_FRAGMENT7;
			*(DWORD*)&Komut1[13] = ITEM_FRAGMENT6;
			*(DWORD*)&Komut1[23] = ITEM_FRAGMENT5;
			*(DWORD*)&Komut1[33] = ITEM_FRAGMENT4;
			*(DWORD*)&Komut1[43] = ITEM_FRAGMENT3;
			*(DWORD*)&Komut1[53] = ITEM_FRAGMENT2;
			*(DWORD*)&Komut1[63] = ITEM_FRAGMENT1;
			*(DWORD*)&Komut1[73] = ITEM_BLUE_CHEST;
			*(DWORD*)&Komut1[83] = ITEM_GREEN_CHEST;
			*(DWORD*)&Komut1[93] = ITEM_BUS;
			cClient.pSend(Komut,sizeof(Komut));
			cClient.pSend(Komut1,sizeof(Komut1));
		}
			else if (strcmp(cClient.command,"k_topla")==0)
		{
		   memset(cClient.command,0,20);
		   cClient.kutuyakos = true;
		   TerminateThread(cClient.AtackThreadHandle,0);
			cClient.LootThreadHandle= CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)lootthread,NULL,0,0);

		}
			else if (strcmp(cClient.command,"pt_kur")==0)
		{
			memset(cClient.command,0,20);
			int  a=1;
			for (int i = 0; i < 16; i++)
			{
				if ((strcmp(cClient.member[i],"")!=0)&&(strcmp(cClient.member[i],cClient.name)!=0))
				{
					BYTE PtKomut[50];
					memset(&PtKomut,0,50);
					PtKomut[0]=0x2f;
					PtKomut[1]=a;
					a=3;

					PtKomut[2]=lstrlenA(cClient.member[i]);
					memcpy(&PtKomut[4],cClient.member[i],lstrlenA(cClient.member[i]));
					cClient.pSend(PtKomut,lstrlenA(cClient.member[i])+4)  ;
				}

			}

		}
			else if (strncmp(cClient.command,"follow",6)==0)
		{

			if (strcmp(cClient.command,"follow on")==0)
			{
				TerminateThread(cClient.MoveThreadHandle,0);
				cClient.MoveThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
			}
			else
			{
				TerminateThread(cClient.MoveThreadHandle,0);
			}

			memset(cClient.command,0,20);
		}
			else if (strcmp(cClient.command,"member")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 0; i < 16; i++)
			{
				printf("member : %s \n",cClient.member[i]);
			}

        }
			else if (strcmp(cClient.command,"birak")==0)
		{
			memset(cClient.command,0,20);
			BYTE Komut[]={0x68,0x23,0xC3,0x03,};
			*(WORD*)&Komut[2]=cClient.FollowId;
			BYTE Komut1[]={0x68,0x24,0x05,0x00,0x01,0x00,};
			BYTE Komut2[]={0x68,0x27,};
			cClient.pSend(Komut,sizeof(Komut));

				if (cClient.FindItemIndex(ITEM_FRAGMENT7)!=255)
				{
					printf("1\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT7);
					Komut1[2]	= i_index;
					Komut1[3]	= 5;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT6)!=255)
				{
					printf("2\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT6);
					Komut1[2]	= i_index;
					Komut1[3]	= 3;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT5)!=255)
				{
					printf("3\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT5);
					Komut1[2]	= i_index;
					Komut1[3]	= 2;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT4)!=255)
				{
					printf("4\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT4);
					Komut1[2]	= i_index;
					Komut1[3]	= 0;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT3)!=255)
				{
					printf("5\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT3);
					Komut1[2]	= i_index;
					Komut1[3]	= 1;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT2)!=255)
				{
					printf("6\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT2);
					Komut1[2]	= i_index;
					Komut1[3]	= 4;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_FRAGMENT1)!=255)
				{
					printf("7\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_FRAGMENT1);
					Komut1[2]	= i_index;
					Komut1[3]	= 6;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_BLUE_CHEST)!=255)
				{
				printf("8\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_BLUE_CHEST);
					Komut1[2]	= i_index;
					Komut1[3]	= 7;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_GREEN_CHEST)!=255)
				{
					printf("9\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_GREEN_CHEST);
					Komut1[2]	= i_index;
					Komut1[3]	= 8;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				if (cClient.FindItemIndex(ITEM_BUS)!=255)
				{
                	printf("10\n");
					BYTE i_index = cClient.FindItemIndex(ITEM_BUS);
					Komut1[2]	= i_index;
					Komut1[3]	= 9;
					Komut1[4]	= cClient.Item_Table[i_index].Count;
					cClient.pSend(Komut1,sizeof(Komut1));
				}
				cClient.pSend(Komut2,sizeof(Komut2));
		}
		else if (strcmp(cClient.command,"git")==0)
		{
			memset(cClient.command,0,20);
			if (cClient.Level>34) {

			if (cClient.CharHuman)
			{
				cClient.GoZone(0x2);
			}
			else
			{
                cClient.GoZone(0x1);
			}
			}

			cClient.MadenAktif = true;
			cClient.tradeModu = false;
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenThreadHandle = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)madenbaslat,NULL,0,0);
		}
		else if (strcmp(cClient.command,"inv")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 0; i < 28; i++)
			{
				bool yazdi=false;
				for (int j = 0; j < 33; j++)
				{
					if (cClient.lItemList[j]==cClient.Item_Table[i].Id)
					{
						printf ("ItemId<%d> : %s : %d \n",i,cClient.strItemList[j],cClient.Item_Table[i].Count);
						yazdi = true;
					}
				}
				if (!yazdi)
				{
					printf ("ItemId<%d>: %d : %d \n",i,cClient.Item_Table[i].Id,cClient.Item_Table[i].Count);
				}

			 }
			 infoTick = 0;
		}
		else if (strcmp(cClient.command,"tradever")==0)
		{
			memset(cClient.command,0,20);
			
		}
		else if (strcmp(cClient.command,"ref")==0)
		{
			memset(cClient.command,0,20);
			cClient.InventoryRefresh();
		}
		else if (strcmp(cClient.command,"kir")==0)
		{
			memset(cClient.command,0,20);
			cClient.OreKir();
		}
		else if (strcmp(cClient.command,"relog")==0)
		{
			memset(cClient.command,0,20);
			BYTE Komut = 0 ;
			cClient.pSend(&Komut,1);
			TerminateThread(cClient.Thread41Handle,0);
			TerminateThread(upHandle,0);
			TerminateThread(cClient.MoveThreadHandle,0);
			TerminateThread(cClient.AtackThreadHandle,0);
			TerminateThread(cClient.LevelThreadHandle,0);
			TerminateThread(cClient.PotThreadHandle,0);
		}
		else if (strcmp(cClient.command,"loot")==0)
		{
			memset(cClient.command,0,20);
			CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)lootthread,NULL,0,0);
		}
		else if (strcmp(cClient.command,"bow2")==0)
		{
         	memset(cClient.command,0,20);
			cClient.WearItem(cClient.FindItemIndex(168210001),6);
		}
		else if (strcmp(cClient.command,"bow")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 0; i < 28; i++)
			{
				int a = cClient.Item_Table[i].Id/10000000;
				if (a==16)
				{
					cClient.WearItem(i,8);
					printf ("%d :ID<%d>\n",cClient.Item_Table[i].Id,i);
				}
			}
		}
		else if (strcmp(cClient.command,"giy")==0)
		{
			memset(cClient.command,0,20);
			cClient.WearItem(0,6);
		   /*	BYTE WearItem[]={0x1F,0x01,0xE0,0xAE,0x31,0x17,0x00,0x08};
			WearItem[6]=0;
			*(DWORD*)&WearItem[2]=cClient.Item_Table[0].Id;
			cClient.pSend(WearItem,sizeof(WearItem));     */
		}
		else if (strcmp(cClient.command,"job")==0)
		{
			memset(cClient.command,0,20);
			cClient.Move(816,706);
			BYTE Komut1[]={0x20,0x01,0xEC,0x3A,0xFF,0xFF,0xFF,0xFF};
			*(WORD*)&Komut1[2]= 12325;
			BYTE Komut2[]={0x64,0x07,0xDE,0x0F,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x31,0x38,0x30,0x30,0x34,0x5F,0x4B,0x61,0x69,0x73,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			cClient.pSend(Komut1,sizeof(Komut1));
			cClient.pSend(Komut2,sizeof(Komut2));
			cClient.pSend(Komut3,sizeof(Komut3));
        }
		else if (strcmp(cClient.command,"party")==0)
		{
            memset(cClient.command,0,20);
			BYTE Komut[3]={0x2F,0x02,0x01};
			cClient.pSend(Komut,sizeof(Komut));
		}
		else if (strcmp(cClient.command,"presok")==0)
		{
            memset(cClient.command,0,20);
			BYTE Komut[]= {0x12,0x01};
			cClient.pSend(Komut,sizeof(Komut));
		}
		else if (strcmp(cClient.command,"1d")==0)
		{
			memset(cClient.command,0,20);
						BYTE DKomut[]={0x1D,0x01,0x00,0x94,0x2A};
				*(WORD*)&DKomut[3]=13751;
				cClient.pSend(DKomut,sizeof(DKomut));
		}
		else if (strcmp(cClient.command,"go")==0)
		{
			memset(cClient.command,0,20);
            TerminateThread(cClient.MoveThreadHandle,0);
			cClient.MoveThreadHandle= CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)movethread,NULL,0,0);
		}
		else if (strcmp(cClient.command,"near")==0)
		{
			memset(cClient.command,0,20);
			float dist;
			WORD Id = cClient.FindNearNpc(cClient.X,cClient.Y,&dist,0xffff);
			printf ("ID<%d>: %f\n",Id,dist);
		}else if (strcmp(cClient.command,"npc")==0)
		{
			memset(cClient.command,0,20);
			float dist;
			WORD Id = cClient.FindNearNpc(cClient.X,cClient.Y,&dist,0xffff);
			cClient.GotoNpc(Id);
		}else if (strcmp(cClient.command,"g0")==0)
		{
			memset(cClient.command,0,20);
			cClient.HareketEt(cClient.X+3,cClient.Y+3);
		}else if (strcmp(cClient.command,"trade")==0)
		{
			memset(cClient.command,0,20);
				BYTE Komut[]={0x30,0x02,0x01};
				cClient.pSend(Komut,sizeof(Komut));
		}else if (strcmp(cClient.command,"tradeok")==0) {
			memset(cClient.command,0,20);
			cClient.TradeConfirm();
		}else if (strcmp(cClient.command,"tradecancel")==0) {
			memset(cClient.command,0,20);
			cClient.TradeConfirm();
		}else if (strcmp(cClient.command,"fff")==0) {
			memset(cClient.command,0,20);

		}else if (strcmp(cClient.command,"trade_ver")==0) {
			memset(cClient.command,0,20);
			BYTE KoyulanCount = 0;
			BYTE Komut[]={0x30,0x03,0xFF,0x00,0xE9,0xA4,0x35,0x40,0x42,0x0F,0x00,};
			*(DWORD*)&Komut[7]=cClient.Para-5000000;
			cClient.pSend(Komut,sizeof(Komut));

			for (int i = 0; i < 28; i++)
			{
				DWORD itemid = cClient.Item_Table[i].Id;
				if(	itemid==ITEM_BLUE_CHEST||
					itemid==ITEM_GREEN_CHEST||
					itemid==ITEM_RED_CHEST||
					itemid==ITEM_FRAGMENT1||
					itemid==ITEM_FRAGMENT2||
					itemid==ITEM_FRAGMENT3||
					itemid==ITEM_FRAGMENT4||
					itemid==ITEM_FRAGMENT5||
					itemid==ITEM_FRAGMENT6||
					itemid==ITEM_FRAGMENT7||
					itemid==ITEM_BUS||
					itemid==ITEM_TS_SCROLL||
					itemid==ITEM_OPAL||
					itemid==ITEM_SAPPHIRE||
					itemid==ITEM_CRYSTAL)
				{
					if (KoyulanCount<9)
					{
						cClient.TradeKoy(i,0);
						cClient.Item_Table[i].Id = 0;
						KoyulanCount++;
					}
				}
			}
		}else if (strcmp(cClient.command,"tr1")==0)
		{
			memset(cClient.command,0,20);

			if (cClient.Gear_Table[5].Id!=0)
			{
				cClient.CrashWearItem(5);
				TerminateProcess(GetCurrentProcess(),0);
			}

			if (cClient.Gear_Table[6].Id!=389132000)
			{
				cClient.CrashWearItem(6);
			}
				cClient.CrashWearItem(8);

			for (int i = 0; i < 28; i++)
			{
				if (cClient.Item_Table[i].Id!=389132000)
				{
					cClient.CrashItem(i);
				}
				else
				{
					cClient.WearItem(i,6);
				}
			}
			cClient.Move(828,529);

		}
		else if (strcmp(cClient.command,"tr2")==0)
		{
			memset(cClient.command,0,20);
			cClient.Move(817,451);
			cClient.Move(776,433);
			cClient.Move(667,423);
			cClient.Move(655,414);
			Sleep(2000);
            cClient.GotoNpc(cClient.PitmanId);
			BYTE Komut1[]={0x20,0x01,0xB0,0x3A,0xFF,0xFF,0xFF,0xFF};
			*(WORD*)&Komut1[2]=cClient.PitmanId;
			BYTE Komut2[]={0x64,0x07,0x4D,0x4E,0x00,0x00};
			BYTE Komut3[]={0x55,0x00,0x10,0x33,0x31,0x35,0x31,0x31,0x5F,0x50,0x69,0x74,0x6D,0x61,0x6E,0x2E,0x6C,0x75,0x61};
			cClient.pSend(Komut1,sizeof(Komut1));
			cClient.pSend(Komut2,sizeof(Komut2));
			cClient.pSend(Komut3,sizeof(Komut3));
		}
		else if (strcmp(cClient.command,"emc")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoZone(0x2);
		}
		else if (strcmp(cClient.command,"lufer")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoZone(1);
		}
		else if (strcmp(cClient.command,"moradon")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoZone(0x15);
		}
		else if (strcmp(cClient.command,"tt")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoTown();
			cClient.Move(757,553);
		}
		else if (strcmp(cClient.command,"goldmatok")==0)
		{
			memset(cClient.command,0,20);
			cClient.GoZone(0x15);
			cClient.Move(837,587);
			BYTE Komut1[]={0x20,0x01,0xA1,0x75,0xFF,0xFF,0xFF,0xFF,};
			BYTE Komut2[]={0x55,0x05,0x0F,0x32,0x39,0x30,0x35,0x36,0x5F,0x4B,0x61,0x69,0x72,0x61,0x2E,0x6C,0x75,0x61,};
			BYTE Komut3[]={0x55,0x00,0x0F,0x32,0x39,0x30,0x35,0x36,0x5F,0x4B,0x61,0x69,0x72,0x61,0x2E,0x6C,0x75,0x61,};
			cClient.pSend(Komut1,sizeof(Komut1));
			cClient.pSend(Komut2,sizeof(Komut2));
			cClient.pSend(Komut3,sizeof(Komut3));
				for (int i = 0; i < 28; i++)
			{
				if (cClient.Item_Table[i].Id==389135000)
				{
					cClient.WearItem(i,6);
				}
			}
		}
		else if (strcmp(cClient.command,"alan")==0)
		{
			memset(cClient.command,0,20);
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenKomut(3);
			cClient.GoTown();
			if (cClient.Zone == 2)
			{
				cClient.Move(1588,415);
			}
			else if (cClient.Zone == 1)
			{
				cClient.Move(447,1617);
			}
			else if (cClient.Zone == 0x15)
			{
				cClient.Move(797,526);
			}
			cClient.alan=true;
			cClient.veren=false;
			//BYTE TKomut[]={0x30,0x02,0x00};
			//cClient.pSend(TKomut,sizeof(TKomut));
			char buf[20];
			memset(buf,0,20);
			strcpy(buf,"teqnoloqy");
			BYTE Komut[20];
		   /*	Komut[0]=0x10;
			Komut[1]=0x1;
			*(WORD*)&Komut[2]=lstrlen(buf);
			memcpy(&Komut[4],buf,lstrlen(buf));
			cClient.pSend(Komut,lstrlen(buf)+4); */

		}
		else if (strcmp(cClient.command,"veren")==0)
		{
			memset(cClient.command,0,20);
			TerminateThread(cClient.MadenThreadHandle,0);
			cClient.MadenKomut(3);
			cClient.GoTown();

			if (cClient.Zone == 2)
			{
				cClient.Move(1588,415);
			}
			else if (cClient.Zone == 1)
			{
				cClient.Move(447,1617);
			}
			else if (cClient.Zone == 0x15)
			{
				cClient.Move(797,526);
			}

			cClient.alan=false;
			cClient.veren=true;
            Sleep(2000);
						BYTE TKomut[]={0x30,0x02,0x00};
			cClient.pSend(TKomut,sizeof(TKomut));
						BYTE Komut[]= {0x30,0x01,0x0F,0x31,0x01};
			*(WORD*)&Komut[2]=cClient.FollowId;

			cClient.pSend(Komut,sizeof(Komut));
		   Sleep(15000);
		   strcpy(cClient.command,"git");
		}
		else if (strcmp(cClient.command,"folk")==0)
		{
			memset(cClient.command,0,20);
			cClient.Move(832,527);
			BYTE Komut[]={0x4B,0xAD,0x0F,0x49,0x08};
			cClient.pSend(Komut,sizeof(Komut));
		}
		else if (strcmp(cClient.command,"2")==0)
		{
		  memset(cClient.command,0,20);
          TerminateThread(upHandle,0);
		}
				else if (strcmp(cClient.command,"1")==0)
		{
		  memset(cClient.command,0,20);

			cClient.Move(1636,418);
			int PaperClass=2;//mage
			int PaperArmor=1;//paper
			int PaperItem =0;//paldron
			BYTE Komut[]={0x21,0x01,0x11,0x15,0x03,0x00,0xED,0x2A,0x69,0xD1,0x9D,0x0F,0x01,0x01,0x00,0x01,0x0C,};
			*(WORD*)&Komut[6] = 21996;
			*(DWORD*)&Komut[8]=201001001+PaperArmor*1000000+PaperItem*1000;
			switch (PaperClass) {
			case 0 :;break;

			case 1 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+40000000;break;
			case 2 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+60000000;break;
			case 3 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+80000000;break;
			default:
			;
			}
			Komut[15]=  PaperArmor;
			Komut[16]=  PaperItem+6*PaperClass;
			for (int i = 2; i < 28; i++)
			{
				Komut[12]= i ;
				cClient.pSend(Komut,sizeof(Komut));
			}
			for (int i = 2; i < 28; i++)
			{
				BYTE Komut[]= {0x5B, 0x2, 0x1, 0x16, 0x27,
				0x29, 0xBC, 0xBF, 0x10,   ////item id ///+1 fabric
				0x15,                    ////item yeri
				0x8, 0x74, 0x9A, 0x16,   //// Scrool id
				0x16,                   //// Scroll yeri
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF
				};
				if (cClient.Item_Table[i].Id!=0)
				{
					if (mod) {
					if (cClient.Item_Table[i].Id%10==7) {
					*(DWORD*)&Komut[5]=cClient.Item_Table[i].Id;

					Komut[9]=i;
					*(DWORD*)&Komut[10]=cClient.Item_Table[1].Id;
					Komut[14]=1;
					  }
					}else{
					*(DWORD*)&Komut[5]=cClient.Item_Table[i].Id;

					Komut[9]=i;
					*(DWORD*)&Komut[10]=cClient.Item_Table[0].Id;
					Komut[14]=0;
					}

                    	


				}
				cClient.Item_Table[i].Id++;
				cClient.pSend(Komut,sizeof(Komut));
			}
			if(mod){
			Sleep(2500);
			BYTE kKomut = 0 ;
			cClient.pSend(&kKomut,1);
			TerminateThread(cClient.Thread41Handle,0);
			TerminateThread(upHandle,0);
			}
		}
		else if (strcmp(cClient.command,"bas")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 2; i < 28; i++)
			{
				BYTE Komut[]= {0x5B, 0x2, 0x1, 0x16, 0x27,
				0x29, 0xBC, 0xBF, 0x10,   ////item id ///+1 fabric
				0x15,                    ////item yeri
				0x8, 0x74, 0x9A, 0x16,   //// Scrool id
				0x16,                   //// Scroll yeri
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF
				};
				if (cClient.Item_Table[i].Id!=0)
				{
					*(DWORD*)&Komut[5]=cClient.Item_Table[i].Id;
					cClient.Item_Table[i].Id++;
					Komut[9]=i;
					*(DWORD*)&Komut[10]=cClient.Item_Table[0].Id;
					Komut[14]=0;
				}

				cClient.pSend(Komut,sizeof(Komut));
			}
		}
		else if (strcmp(cClient.command,"ba2")==0)
		{
			memset(cClient.command,0,20);
			for (int i = 2; i < 28; i++)
			{
				BYTE Komut[]= {0x5B, 0x2, 0x1, 0x16, 0x27,
				0x29, 0xBC, 0xBF, 0x10,   ////item id ///+1 fabric
				0x15,                    ////item yeri
				0x8, 0x74, 0x9A, 0x16,   //// Scrool id
				0x16,                   //// Scroll yeri
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF,
				0x0, 0x0, 0x0, 0x0,
				0xFF
				};
				if (cClient.Item_Table[i].Id!=0)
				{
					*(DWORD*)&Komut[5]=cClient.Item_Table[i].Id;
					cClient.Item_Table[i].Id++;
					Komut[9]=i;
					*(DWORD*)&Komut[10]=cClient.Item_Table[1].Id;
					Komut[14]=1;
				}

				cClient.pSend(Komut,sizeof(Komut));
			}
		}
		else if (strcmp(cClient.command,"satinal")==0)
		{
			memset(cClient.command,0,20);
			cClient.Move(1629,415);
			int PaperClass=2;//mage
			int PaperArmor=0;//paper
			int PaperItem =0;//paldron
			BYTE Komut[]={0x21,0x01,0x11,0x15,0x03,0x00,0xED,0x2A,0x69,0xD1,0x9D,0x0F,0x01,0x01,0x00,0x01,0x0C,};
			*(WORD*)&Komut[6] = 21996;
			*(DWORD*)&Komut[8]=201001001+PaperArmor*1000000+PaperItem*1000;
			switch (PaperClass) {
			case 0 :;break;

			case 1 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+40000000;break;
			case 2 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+60000000;break;
			case 3 :*(DWORD*)&Komut[8]=*(DWORD*)&Komut[8]+80000000;break;
			default:
			;
			}
			Komut[15]=  PaperArmor;
			Komut[16]=  PaperItem+6*PaperClass;
			for (int i = 0; i < 28; i++)
			{
				Komut[12]= i ;
				cClient.pSend(Komut,sizeof(Komut));
			}
		}
		else if (strcmp(cClient.command,"innkoy")==0)
		{
			memset(cClient.command,0,20);
			cClient.Move(1687,368);
			BYTE Komut12[]={0x45,0x02,0x36,0x45,0x00,0xE9,0xA4,0x35,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00};
			*(WORD*)&Komut12[2]=21987  ;
			for (int i = 2; i < 28; i++)
			{
				Komut12[9]	= i;
				if (cClient.Item_Table[i].Id%10==8)
				{
					*(DWORD*)&Komut12[4]=cClient.Item_Table[i].Id;
					for (int xx = 0; xx < 8; xx++)
					{
						for (int yy = 0; yy < 8; yy++)
						{
							Komut12[8]	= xx;
							Komut12[10]	= yy;
							cClient.pSend(Komut12,sizeof(Komut12));
						}
					}
				}
			}



		}
		else if (strcmp(cClient.command,"zone")==0)
		{
			memset(cClient.command,0,20);
			printf("\n Zone : %d\n",cClient.Zone);
		}
		else if (strcmp(cClient.command,"para")==0)
		{
			memset(cClient.command,0,20);
			printf("\n Para : %d\n",cClient.Para);
		}
		else if (strcmp(cClient.command,"pot")==0)
		{
			memset(cClient.command,0,20);
			WORD potcount =cClient.FindItemCount(ITEM_MP1920);
			printf("\n Pot : %d\n",potcount);
		}else if (strncmp(cClient.command,"qaz",3)==0)
		{

			char gx[5],gy[5];
			memset(gx,0,5);
			memset(gy,0,5);
			memcpy(&gx,&cClient.command[4],4);
			memcpy(&gy,&cClient.command[9],4);
			cClient.Move(atoi(gx),atoi(gy));
			memset(cClient.command,0,20);

		}
		else if (lstrlen(cClient.command)==0)
		{
			memset(cClient.command,0,20);
		}
		else
		{


		   //	cClient.FollowId = atoi(cClient.command);
		   //	printf("\n Follow Set : %d\n",cClient.FollowId);
			/*Recv_Kutu =atoi(cClient.command);
			BYTE k[5];
			k[0]= 0x24;

			*(DWORD*)&k[1]= Recv_Kutu;
			cClient.pSend(k,5);                */
			memset(cClient.command,0,20);
		}
		Sleep(200);
	}
}
int main(int argc, char *argv[])
{



logyaz("start");
DeleteFileA("komut");
char cCd[FILENAME_MAX];
GetCurrentDirectoryA(sizeof(cCd),cCd);
bool f;
for (int i = lstrlen(cCd); i > 0; i--) {
if (cCd[i]=='\\')
{
if (f) {

memset(swx_my_no_a,0,10);
memcpy(swx_my_no_a,&cCd[i+1],(lstrlen(cCd)-i-1));
cClient.swx_my_no = atoi(swx_my_no_a);
break;
}else{
	f=true;
}   
}

}

/*
TFileStream *a = new TFileStream("comolokko",fmOpenRead);
BYTE *fileData = (BYTE *) malloc (a->Size);
a->Position=0;
a->ReadBuffer(&cClient.Skill[0],a->Size) ;
a->Free();    */

	bool floodet=false;
	HMODULE aa=LoadLibraryA("ClassMorphineeDll.dll");
	c=(KoClassOlustur)GetProcAddress( aa,"KoClassOlustur");
	cClient.myclass= static_cast< KnightOnline_CLASS_Interface* >(c());
	//cClient.SetClass(deneme);
	cClient.myclass->LogCall=SynSocketLogRecv;
	cClient.myclass->VeriYolla=SynSocketGelenVeriHepsiCall;

	ifstream fLoad;
	try {

	fLoad.open("ayar.txt");
	memset(cClient.myclass->charidd,0,100);
	memset(cClient.myclass->passamortt,0,100);
	memset(cClient.myclass->server_ipsi,0,100);
	cClient.myclass->proxy_enable = false;
	memset(cClient.myclass->proxy_ip,0,100);
	memset(cClient.myclass->proxy_port,0,100);
	memset(cClient.myclass->proxy_user,0,100);
	memset(cClient.myclass->proxy_password,0,100);

	fLoad.getline(cClient.myclass->charidd,100);
	fLoad.getline(cClient.myclass->passamortt,100);
	fLoad.getline(cClient.myclass->server_ipsi,100);
	char buf[100];
	memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.myclass->socketno=atoi(buf);
	memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.myclass->proxy_enable=atoi(buf);
	fLoad.getline(cClient.myclass->proxy_ip,100);
	fLoad.getline(cClient.myclass->proxy_port,100);
	fLoad.getline(cClient.myclass->proxy_user,100);
	fLoad.getline(cClient.myclass->proxy_password,100);
	memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.MadenAktif=atoi(buf);
		memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.moveSpeed=atoi(buf);
		memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.moveSleep=atoi(buf);
	memset(buf,0,100);
	fLoad.getline(buf,100);
	cClient.tradeModu=atoi(buf);
	memset(buf,0,100);
	fLoad.getline(buf,100);
	strcpy(cClient.baskanNick,buf);
	fLoad.close();

	} catch (...) {
	MessageBoxA(NULL,"Ayar Dosyasi Hatali","Ayar Dosyasi Hatali",NULL);
	return false;
	}
char bbb[3];
memset(bbb,0,3);
memcpy(bbb,&cClient.myclass->server_ipsi[12],3);
if (atoi(bbb)>210)
{
Dusur("188.132.161.223",cClient.myclass->charidd);
Dusur("188.132.161.221",cClient.myclass->charidd);
Dusur("188.132.161.226",cClient.myclass->charidd);
}
	/*strcpy(cClient.myclass->proxy_ip,"176.53.124.18");
	strcpy(cClient.myclass->proxy_port,"49498");
	strcpy(cClient.myclass->proxy_user,"fatihsekmen");
	strcpy(cClient.myclass->proxy_password,"FHFY8UA7");   */
   //	getch();
	 void *xxx=  cClient.myclass;
	 asm
	 {
		 mov eax,xxx
	 }

	cClient.myclass->mainclassad("psckpt35","11201987","asd29kajhluou61j","188.132.161.194",1);//"HeroinnVistaTester","188.132.161.202");// yenisi soldaa//"188.132.161.230");//serverlist::Akara ,karakterpozisyonlari::orta ) ;
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)userthread,NULL,0,0);
	//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)mesajdongusu,NULL,0,0);

	printf ("hazir: \n");
	swxClientClass *ptr = &cClient;
	printf ("pointer is : %d \n",ptr);
    DeleteFileA("ver.ini");
	ofstream fSave;
	fSave.open("ver.ini",std::ios_base::out | std::ios_base::app);
	if(fSave.is_open() == true)
	{
		fSave << ptr << "\n";
		fSave.close();
	}
	while(1)
	{
		if (lstrlen(cClient.command)==0) {
		gets (cClient.command);
		printf ("Command is : %s \n",cClient.command);
		Sleep(1000);
        }
	}
	getch();

}
