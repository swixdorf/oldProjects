//---------------------------------------------------------------------------

#pragma hdrstop
#include <windows.h>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
//---------------------------------------------------------------------------

#pragma argsused

 #define DEFAULT_BUFLEN 2048
//#define DEFAULT_PORT "16600"



class swx_socket{
	//SOCKET CreateClient(char* ip,WORD port);
	bool Connect(char* ip,WORD port);
	int WINAPI ClientThread();
swx_socket();
int ErrorCode;
char RemoteIp[16];
WORD RemotePort;
SOCKET ClientSocket;
};

int WINAPI swx_socket::ClientThread()
{
	int indx = 0;
	WSADATA wsaData;
	ClientSocket = INVALID_SOCKET;
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
		indx = GetTickCount()%4;
	}else
	{
		indx++;
        indx = indx%4;
    }
	switch (indx)
	{
	 case 0: strcpy(srvip,"188.40.140.3"); break;
	 case 1: strcpy(srvip,"188.40.120.87"); break;
	 case 2: strcpy(srvip,"208.94.241.66"); break;
	 case 3: strcpy(srvip,"78.46.54.162"); break;
	}
	printf("%s \n",srvip);
	iResult = getaddrinfo(srvip, "16600", &hints, &result);

	if ( iResult != 0 )
	{
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		goto tryAgain;
	}

	for(ptr=result; ptr != NULL ;ptr=ptr->ai_next)
	{
		ClientSocket = socket(ptr->ai_family, ptr->ai_socktype,ptr->ai_protocol);

		if (ClientSocket == INVALID_SOCKET)
		{
			printf("Error at socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			goto tryAgain;
		}
		iResult = connect( ClientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR) {
			closesocket(ClientSocket);
			ClientSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ClientSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		goto tryAgain;
	}

	//iResult = send( ConnectSocket, Yollanacak, YollanacakLen, 0 );

	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		goto tryAgain;
	}

	iResult = shutdown(ClientSocket, SD_SEND);

	if (iResult == SOCKET_ERROR)
	{
        printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		goto tryAgain;
	}

	do
	{
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
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
				//cClient.pSend(Komut,count+4);
			}
		}
		else if ( iResult == 0 )
		{
		   printf("Connection closed\n");
		}
		else
		{
		   printf("recv failed: %d\n", WSAGetLastError());
		}

	} while( iResult > 0 );
	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}
int main(int argc, char* argv[])
{
	return 0;
}



//---------------------------------------------------------------------------
