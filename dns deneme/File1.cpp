#include <winsock.h>
#include<stdio.h>
#include<string.h>
#include <io.h>
#include <sys/stat.h>
#include <conio.h>

int main()
{
	
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) {
		fprintf(stderr, "WSAStartup failed.\n");
		exit(1);
	}
	int sock;
	struct sockaddr_in serv_addr;
	sock = socket(AF_INET,SOCK_DGRAM,0);
	
	if(sock == -1){
		printf("Error creating socket");
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(53);
	serv_addr.sin_addr.s_addr = inet_addr("4.2.2.6");//Notice that inet_addr() returns the address in Network Byte Order already–you don’t have to call htonl()
	//bzero(&(serv_addr.sin_zero),8);
	int i= connect(sock, (struct sockaddr*)& serv_addr, sizeof(struct sockaddr));	
	if(i==-1) {
		printf("nahhhhh");
	}
	else{
		printf("Connection Established\n");

	}
	char *send_data, recv_data[1024];
	send_data="00020100000100000000000003706F7064026978066E6574636F6D03636F6D0000010001"; //dns header and dns messages concatinated
	printf("send_data is: %s\n", send_data);
	send(sock, send_data, strlen(send_data), 0); // send data to server
		
	if(strcmp(send_data, "EXIT") == 0) {
		printf("%s", "Disconnected!\n\n");
		//break;
	}
	int byte_count = recv(sock,recv_data,1024,0); // receive data from server
	recv_data[byte_count] = '\0';
	printf("Recieved data is: %s",recv_data);

	closesocket(sock);
	getch();
	return 0;
}
