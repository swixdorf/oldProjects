/********************************************************************************************************\
*                                                                                                        *
*   Component Name : Socks  client written by ravi kiran.																	 *
*   Purpose        : Establish Socket through Socks Proxy Ver 4 and Ver 5                                *
*                                                                                                        *
*   Author		   : Ravi Kiran                                                                          *
*   email          : ravi824@rediffmail.com                                                              *
*                                                                                                        *
*   Copy Rights    : All copy rights reserved                                                            *
*                                                                                                        *
\********************************************************************************************************/

#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include "socks.h"

#define PORT 1001						// the port client will be connecting to 
#define MAXDATASIZE 100

static void ReadThread(void* lp);
int socketId;

int main(int argc, char* argv[])
{

        
		const char temp[]="GET / HTTP/1.0\r\n\r\n";

		CSocks cs;
		cs.SetVersion(SOCKS_VER4);
		cs.SetSocksPort(1080);
		cs.SetDestinationPort(1001);
		cs.SetDestinationAddress("192.168.11.97");
		
		cs.SetSocksAddress("192.168.11.97");
		//cs.SetVersion(SOCKS_VER5);
		//cs.SetSocksAddress("128.0.21.200");
		
		

		socketId = cs.Connect();
        
		// if failed
		if (cs.m_IsError)
		{
			printf( "\n%s", cs.GetLastErrorMessage());
			getch();
			return 0;
		}
		
		// send packet for requesting to a server
		if(socketId > 0)
		{
			send(socketId, temp, strlen(temp), 0);

			HANDLE ReadThreadID;											// handle for read thread id
			HANDLE handle;													// handle for thread handle
			
			handle = CreateThread ((LPSECURITY_ATTRIBUTES)NULL,				// No security attributes.
									(DWORD)0,								// Use same stack size.
									(LPTHREAD_START_ROUTINE)ReadThread,		// Thread procedure.
									(LPVOID)(void*)NULL,					// Parameter to pass.
									(DWORD)0,								// Run immediately.
									(LPDWORD)&ReadThreadID);		

			WaitForSingleObject(handle, INFINITE);
		}
		else
		{
			printf("\nSocks Server / Destination Server not started..");
		}
        closesocket(socketId);
		getch();

		return 0;
}


// Thread Proc for reading from server socket.
static void ReadThread(void* lp)
{

		int numbytes; 
		char buf[MAXDATASIZE];
		
		while(1)
		{
        
			if ((numbytes=recv(socketId, buf, MAXDATASIZE-1, 0)) == -1)
			{
                    printf("\nServer / Socks Server has been closed Receive thread Closed\0");
					break;
            }
			if (numbytes == 0) break;
                buf[numbytes] = '\0';
                printf("Received: %s\r\n",buf);
				send(socketId,buf,strlen(buf),0);
		}
	  
}