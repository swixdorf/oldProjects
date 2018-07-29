/********************************************************************************************************\
*                                                                                                        *
*   Component Name : CSocks Component																	 *
*   Purpose        : Establishes Socket through Socks Proxy Ver 4 and Ver 5                              *
*                                                                                                        *
*   Author		   : Ravi Kiran                                                                          *
*   email          : ravi824@rediffmail.com                                                              *
*                                                                                                        *
*   Copy Rights    : All copy rights reserved                                                            *
*                                                                                                        *
\********************************************************************************************************/
#ifndef _SOCKS_H_
#define _SOCKS_H_

#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>

#define SOCKS_VER4		4
#define SOCKS_VER5		5
#define	SOCKS_INTERVAL	1000

/********************************************************************************************************\
*                                                                                                        *
*   Class Name   : CSocks																				 *
*   Purpose      :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
\********************************************************************************************************/
class CSocks
{
public:
	CSocks();
	~CSocks();
	CSocks(char *in_szSocksAddress, int in_ScoksPort, 
			char *in_szDestinationAddress , int in_DestinationPort);
//Set Methods	
	void	SetSocksPort(int in_Port);
	void	SetDestinationPort(int in_Port);
	void	SetSocksAddress(char *in_szSocksAddress);
	void	SetDestinationAddress(char *in_szDestinationAddress);
	int		Connect();
	void	SetVersion(int in_Version);
	void	SetUserName(char* in_szUserName);
	void	SetPassword(char* in_szPassword);
	void	SetSocksInterval(int in_MilliSeconds);
//Get Methods
	char	*GetUserName();
	char	*GetPassword();
	int		GetVersion();
	char	*GetLastErrorMessage();
private:
	int CSocks::ConnectToSocksFour( SOCKET in_Socket,
						const struct sockaddr FAR *in_szName,
						int nameLen,
						const struct sockaddr FAR *in_Socks,
						int socksLen,
						const char *szUserId );
	int CSocks::ConnectToSocksFive( SOCKET in_Socket,
						const struct sockaddr FAR *in_szName,
						int nameLen,
						const struct sockaddr FAR *in_Socks,
						int socksLen,
						const char *szUserId );
	
	int	InitiateSocket();
// Memeber Variables
public :
	BOOL	m_Authentication;
	int		m_Interval;
	BOOL	m_IsError;
private:
	int		m_Version;
	int		m_Socket; 
	int		m_SocksPort;
	int		m_DestinationPort;
	char	m_SocksAddress[25];
	char	m_DesitnationAddress[25];
	char	m_UserName[100];
	char	m_Password[100];
	char	m_szErrorMessage[255];
};

#endif