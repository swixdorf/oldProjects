
/********************************************************************************************************\
*                                                                                                        *
*   Component Name : CSocks Component																	 *
*   Purpose        : Establishes Socket through Socks Proxy Ver 4 and Ver 5                              *
*                                                                                                        *
*   Author		   : Ravi Kiran                                                                          *
*   email          : ravi824@rediffmail.com                                                              *
*                                                                                                        *
*   Copy Rights    : All copy rights reserved.                                                           *
*                                                                                                        *
\********************************************************************************************************/

#include "socks.h"
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: CSocks																				 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
\********************************************************************************************************/
CSocks::CSocks()
{
	InitiateSocket();						// call socket initiation
	m_IsError = false;
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: ~CSocks																				 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
\********************************************************************************************************/
CSocks::~CSocks()
{
	WSACleanup();
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: ~SetSocksInterval																				 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
\********************************************************************************************************/

void CSocks::SetSocksInterval( int in_MilliSeconds )
{
	
	if( in_MilliSeconds >= 0 )			// accepts only positive values
		m_Interval = in_MilliSeconds;
}

/********************************************************************************************************\
*                                                                                                        *
*   Function Name: CSocks																				 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
CSocks::CSocks( char *in_szSocksAddress, int in_ScoksPort, 
		char *in_szDestinationAddress , int in_DestinationPort )
{
	InitiateSocket();						// call socket initiation
	if ( in_ScoksPort > 0 )
		m_SocksPort = in_ScoksPort;
	if ( in_DestinationPort > 0 )
		m_DestinationPort = in_DestinationPort;
	strcpy( m_SocksAddress, in_szSocksAddress );
	strcpy( m_DesitnationAddress, in_szDestinationAddress );
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: InitiateSocket																		 *
*   Purpose      : Initiate socket and set default values                                                *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
int	CSocks::InitiateSocket()
{
	WSADATA wsaData;// if this doesn't work
	if ( WSAStartup( MAKEWORD( 1, 1 ), &wsaData ) != 0 ) 
	{
		//WSAStartup failed
		return -1;
	} 
	m_Interval	=	0;
	m_Version	=	SOCKS_VER4;
	strcpy( m_szErrorMessage , "No Message Stored.. \0" );
	return 0;

}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: SetVersion																			 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
void CSocks::SetVersion( int in_Version )
{
	// accepts only Socks Version 4 and 5
	if(in_Version == SOCKS_VER4 || in_Version == SOCKS_VER5)
		m_Version = in_Version;
}


/********************************************************************************************************\
*                                                                                                        *
*   Function Name: GetVersion																			 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
int CSocks::GetVersion()
{
	return m_Version;
}


/********************************************************************************************************\
*                                                                                                        *
*   Function Name: SetSocksPort																			 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
void CSocks::SetSocksPort( int in_Port )
{
	if ( in_Port > 0 )
		m_SocksPort = in_Port;
}

/********************************************************************************************************\
*                                                                                                        *
*   Function Name: SetDestinationPort																	 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
void CSocks::SetDestinationPort( int in_Port )
{
	if ( in_Port > 0 )
		m_DestinationPort = in_Port;
}

/********************************************************************************************************\
*                                                                                                        *
*   Function Name: SetSocksAddress																		 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
void CSocks::SetSocksAddress( char *in_szSocksAddress )
{
	strcpy( m_SocksAddress, in_szSocksAddress );
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: SetDestinationAddress																 *
*   Purpose      :                                                                                       *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
void CSocks::SetDestinationAddress( char *in_szDestinationAddress )
{
	strcpy( m_DesitnationAddress, in_szDestinationAddress );
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: Connect																				 *
*   Purpose      : Establishes connection to socks server and returns socket                             *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
int CSocks::Connect()
{
	struct hostent *hostInfo;
	struct sockaddr_in Destination_Addr;					// connector's address information
	struct sockaddr_in Socks_Addr;							// connector's address information
	char *szSplit   = strchr( m_SocksAddress, ':' );
	int ret_val=-1;
	try
	{
		if ( szSplit ) 
		{
			*szSplit		=	0;
			m_SocksPort		=	atoi( szSplit + 1 );
		}

		if ( ( hostInfo = gethostbyname( m_SocksAddress ) ) == NULL ) 
		{	
			m_IsError = true;
			strcpy( m_szErrorMessage , "Error found resolving Socks host infor(socks)\0" );
			return 0;
		}

		Socks_Addr.sin_family = AF_INET;						// host byte order 
		Socks_Addr.sin_port = htons( m_SocksPort );				// short, network byte order 
		Socks_Addr.sin_addr = *((struct in_addr *)hostInfo->h_addr);
		memset( &(Socks_Addr.sin_zero), 0, 8 );					// zero the rest of the struct 

		if ( (hostInfo = gethostbyname( m_DesitnationAddress ) ) == NULL ) 
		{														// get the host info 
			// gethostbyname failed
			m_IsError = true;
			strcpy( m_szErrorMessage , "Error found resolving Destination host infor(socks)\0" );
			return 0;
		}
		if ( ( m_Socket = socket( AF_INET, SOCK_STREAM, 0 ) ) == -1 ) 
		{
			
			m_IsError = true;
			strcpy( m_szErrorMessage , "Error found Creation of Socket\0" );
			return 0;
		}

		Destination_Addr.sin_family = AF_INET;					// host byte order 
		Destination_Addr.sin_port = htons( m_DestinationPort );	// short, network byte order 
		Destination_Addr.sin_addr = *((struct in_addr *)hostInfo->h_addr);
		memset( &(Destination_Addr.sin_zero), '\0', 8 );			// zero the rest of the struct 

		if ( m_Version == SOCKS_VER4 )
		{
			ret_val = ConnectToSocksFour( m_Socket, 
								(struct sockaddr *)&Destination_Addr,
								sizeof(struct sockaddr),
								(struct sockaddr*)&Socks_Addr,
								sizeof(struct sockaddr),"fatihsekmen:FHFY8UA7");
			if ( ret_val != 0 ) 
			{
					//Failed to Establish connection through Socks
					return ret_val;
			}
		}
		else if ( m_Version == SOCKS_VER5 )
		{
			ret_val = ConnectToSocksFive( m_Socket, 
								(struct sockaddr *)&Destination_Addr,
								sizeof(struct sockaddr),
								(struct sockaddr*)&Socks_Addr,
								sizeof(struct sockaddr),0 );
			if ( ret_val != 0 ) 
			{
					//Failed to Establish connection through Socks
					return ret_val;
			}
		}
		else
		{
			m_IsError = true;
			strcpy( m_szErrorMessage , "Error Invalid Socks Version\0" );
			return 101;	  // Invalid Version
		}
		
		return m_Socket;  // Connected and returns the Socket established with socks server
	}
	catch(...)
	{
		return 0;		// Exception Found
	}
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: ConnectToSocksFour																	 *
*   Purpose      : Connects to Sockets server and returns value                                          *
*   Parameters   : SOCKET,sockaddr,nameLen,sockaddr,socksLen,szUserId                                    *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
int CSocks::ConnectToSocksFour( SOCKET in_Socket,
						const struct sockaddr FAR *in_szName,
						int nameLen,
						const struct sockaddr FAR *in_Socks,
						int socksLen,
						const char *szUserId ) 
{
		
		int retval	=	-1;
    	int lPacketLen	=	 9;								//Length of the Initialize packet
		try
		{

			if ( in_Socks == NULL )							//If no socks server got passed...
    			return connect( in_Socket, in_szName, nameLen );			//General Connect
    		retval = connect( in_Socket, in_Socks, socksLen );	//Connecting to Socks Server

			if ( retval !=0 ) 
				return retval;								//If the return value is not 0, there was an error, so lets return it
	    	

			if ( szUserId ) 
				lPacketLen += strlen(szUserId);				//If there is an extra userid, add its length to the packet length
    		char *packet=new char[lPacketLen];				//Allocate a packet
    		packet[0] = SOCKS_VER4;							//Socks version
    		packet[1] = 1;									//Connect code
    		
    		memcpy( packet+2,
				(char *)&(((sockaddr_in *)in_szName)->sin_port),
				2 );										//Copy the port
    		memcpy( packet+4,
				(char *)&(((sockaddr_in *)in_szName)->sin_addr.S_un.S_addr),
				4 );										//Copy the IP
	    	
    		if ( szUserId )									//If there was a userid, copy it now
    			memcpy( packet+8, szUserId, strlen(szUserId)+1 );
    		else									
    			packet[8]=0;
			
			if ( m_Interval == 0 )
				Sleep( SOCKS_INTERVAL );
			else
				Sleep( m_Interval );
			
    		//Send the packet
    		send( in_Socket, packet, lPacketLen, 0 );
			delete[] packet;								//Unallocate the packet
			char reply[8];									//Allocate memory for the reply packet
			memset( reply, 0 , 8 );							//Set it to 0
			long bytesRecv = 0;
			bytesRecv = recv( in_Socket, reply, 8, 0 );		//Get the reply packet
			
			if ( reply[0] != 0)								//Reply code should be 0
			{ 
        		// SOCKS: Reply code is invalid
		
        		return WSAENETDOWN;
			}
			if ( reply[1] == 90 )							//Request granted!
			{				
        
				return 0;
			}

			retval = reply[1];
		
			m_IsError = true;
			switch ( retval )								//Error codes
			{
				case 91:
					{
						strcpy( m_szErrorMessage , "SOCKS: request rejected or failed\0" );
            			break;
					}
				case 92:
					{
						strcpy( m_szErrorMessage , "SOCKS: request rejected because SOCKS server cannot connect to identd on the client\0" );
            			break;
					}
				case 93:
					{
						strcpy( m_szErrorMessage , "SOCKS: request rejected because the client program and identd report different user-ids\0" );
            			break;
					}
            				
				default:
					{
            			strcpy( m_szErrorMessage , "SOCKS: General Failure or Failed to connect destination server..\0" );
						break;
					}
			}

   			//WSAENETDOWN;
			return retval;
		}
		catch(...)
		{
			return -1;
		}
}
/********************************************************************************************************\
*                                                                                                        *
*   Function Name: ConnectToSocksFive																	 *
*   Purpose      : Connects to Sockets server version five and returns value                             *
*   Parameters   : SOCKET,sockaddr,nameLen,sockaddr,socksLen,szUserId                                    *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
*                                                                                                        *
\********************************************************************************************************/
int CSocks::ConnectToSocksFive( SOCKET in_Socket,
						const struct sockaddr FAR *in_szName,
						int nameLen,
						const struct sockaddr FAR *in_Socks,
						int socksLen,
						const char *szUserId )
{
		int retval	=	-1;
    	int lPacketLen	=	 6;								//Length of the Initialize packet
		try
		{
			if ( in_Socks == NULL )							//If no socks server got passed...
                return connect( in_Socket, in_szName, nameLen );			
    														//General Connect
			retval = connect( in_Socket, 
							  in_Socks, 
							  socksLen );					//Connecting to Socks Server

			if ( retval !=0 ) 
				return retval;								//If the return value is not 0, there was an error, so lets return it
	    	
    		char reply[255];								//Allocate memory for the reply packet
			memset( reply, '\0' , 255 );					//Set it to 0
			char *packet=new char[lPacketLen];				//Allocate a packet
			packet[0] = SOCKS_VER5;							//Socks version
    		packet[1] = 2;									//No of methods
			packet[2] = 0;									//No auth required
			packet[3] = 2;									//for UserName and Password
			packet[4] = 3;									//chap
			packet[5] = 0;									
						
			if ( m_Interval == 0 )
				Sleep( SOCKS_INTERVAL );
			else
				Sleep( m_Interval );

    		//Send the packet
			long bytesSend = 0;
    		bytesSend =	send( in_Socket, packet, lPacketLen, 0 );
			
			long bytesRecv = 0;
			bytesRecv = recv( in_Socket, reply, 255, 0 );	//Get the reply packet

			delete[] packet;								//Unallocate the packet
			//MessageBox(0,"Connected...","",NULL);
			if ( reply[0] != 5)								//Reply code should be 0
			{ 
        		// SOCKS: Reply code is invalid
        		return WSAENETDOWN;
			}
			if ( reply[1] == 0 )							//Request granted!
			{				

			
    			char *packet1=new char[12];					//Allocate a packet
				memset(packet1 , '\0' , 12);
				packet1[0] = SOCKS_VER5;					//Socks version
    			packet1[1] = 1;								//No of methods
				packet1[2] = 0;								//No authuntication
				packet1[3] = 3;								//for domainname
				packet1[4] = 1;								//for ip v4 address

				memcpy( packet+5,							//Copy the IP
					(char *)&(((sockaddr_in *)in_szName)->sin_addr.S_un.S_addr),
					4 );											
				memcpy( packet+9,							//Copy the port
					(char *)&(((sockaddr_in *)in_szName)->sin_port),
					2 );											
	    		packet1[11] = 0;
							
    			//Send the packet
				bytesSend = 0;
    			bytesSend = send( in_Socket, packet1, 12, 0 );
				
				
				memset( reply, 0 , 255 );						//Set it to 0
				recv(in_Socket, reply, 255, 0 );				//Get the reply packet
				
				delete[] packet1;
				
					if ( reply[0] != 5)							//Reply code should be 0
					{ 
        				// SOCKS: Reply code is invalid
		   				return WSAENETDOWN;
					}
					if ( reply[1] == 0 )						//Request granted!
					{
						return 0;
					}
			}

			retval = reply[1];
			printf("retval =%d", retval);
			m_IsError = true;

			switch ( retval )									//Error codes
			{

				case 1:
					{
						strcpy( m_szErrorMessage , "SOCKS: general SOCKS server failure\0" );
            			break;
					}
				case 2:
					{
						strcpy( m_szErrorMessage , "SOCKS: connection not allowed by ruleset\0" );
            			break;
					}
				case 3:
					{
						strcpy( m_szErrorMessage , "SOCKS: Network unreachable\0" );
            			break;
					}
				case 4:
					{
						strcpy( m_szErrorMessage , "SOCKS: Host unreachable\0" );
            			break;
					}
				case 5:
					{
						strcpy( m_szErrorMessage , "SOCKS: Connection refused\0" );
            			break;
					}
				case 6:
					{
						strcpy( m_szErrorMessage , "SOCKS: TTL expired\0" );
            			break;
					}
				case 7:
					{
						strcpy( m_szErrorMessage , "SOCKS: Command not supported\0" );
            			break;
					}
				case 8:
					{
						strcpy( m_szErrorMessage , "SOCKS: Address type not supported\0" );
            			break;
					}
				case 9:
					{
						strcpy( m_szErrorMessage , "SOCKS: to X'FF' unassigned\0" );
            			break;
					}            				
				default:
					{
            			strcpy( m_szErrorMessage , "SOCKS: General Failure or Failed to connect destination server.\0" );
						break;
					}
			}
   			return retval;
		}
		catch(...)
		{
			return -1;
		}
}

/********************************************************************************************************\
*                                                                                                        *
*   Function Name: GetLastErrorMessage																	 *
*   Purpose      : Returns last error message                                                            *
*   Parameters   :                                                                                       *
*       In       :                                                                                       *
*       Out      :                                                                                       *
*       InOut    :                                                                                       *
*   Return       :                                                                                       *
*                                                                                                        *
*   Remarks      :                                                                                       *
*                                                                                                        *
\********************************************************************************************************/
char*	CSocks::GetLastErrorMessage()
{
	return m_szErrorMessage;
}