 #ifndef swxclss
#define swxclss
#include <windows.h>
#include "typedefs.h"

typedef int (__msfastcall   *SynSocketGelenVeriHepsi)(BYTE *GelenBuf,int len,int socketno,void *ths) ;
typedef int (__msfastcall   *SynSocketLog)(char *log) ;

class KnightOnline_CLASS_Interface
{


public:
		BYTE table1[35];
		packetbld ingameinfo; 
		packetbld serverkeyaxietcinfo;
		BYTE sifrelemeicinrecvblogu[0x8000];
		packetbld decryptedsifrelemepaketi;

		DWORD axigercek;// = 0;
		SOCKET mySocket;
		SOCKET myGameSocket;
		WSADATA wsaData;
		sockaddr_in myAddress;
		WSADATA wsaGameData;
		sockaddr_in myGameAddress;
		CRITICAL_SECTION ecs2;
		BYTE tablosonunda[65537];
		bool tablosifirlimi;// = false;
		DWORD tabloislemdegeriorginal;// = 0;
		DWORD tabloislemdegeri;// = 0;
		BYTE bytesiniri[0x5000];//0x42ff
		BYTE onaltilikbibok[256];
		WORD axi1;// = 0;
		WORD axi2;// = 0;
		DWORD saatsayac;// = 0;
		DWORD KOEncCounter;// = 0;
		DWORD table2;
		BYTE counter;
		BYTE dw_Counter1;
		BYTE mimossa[1024];
		WORD bilemedimaq;
		DWORD bunudabilemedimaq ;
		DWORD bilemedigimikinciseyaq;
		
		 BYTE bufferPaket[4096];
		 BYTE ServerKey[8];
		 BYTE OyunServerKey[8];
		BYTE ClientKey[8];
		//////////////////////////////////////////
		int m_CryptionFlag;
		
		DWORD paketsayacif3;
		BYTE *Komut_Al;
		
public:
	    CRITICAL_SECTION decy;
		char charidd[100],passamortt[100],karakteradi[100],server_ipsi[100],crppassamortt[100],proxy_ip[100],proxy_port[100],proxy_user[100],proxy_password[100];
        bool proxy_enable;
		HANDLE ThreadHandle;
		int loginsucess;
		int socketstatus;
		DWORD timeal;
		int socketno;
		SynSocketGelenVeriHepsi VeriYolla;
		SynSocketLog LogCall;
		 
		
		/////////////////////////////////////

public:
    
virtual void __msfastcall mainclassad(char *charidd, char* passamortt,char* karakteradi,char* server_ipsi,int socketno)=0;
virtual BOOL __msfastcall wsSendPackets(BYTE pByte[],DWORD pSize,DWORD threadid)=0;
virtual void __msfastcall Thread41(int Param)=0;
virtual void __msfastcall oyunagir(int oyunkomut)=0;   


virtual void RunLoginThread()=0;
virtual void OyunServerKeyAyir1(BYTE paket[],packetbld *keybuf)=0;
    
virtual void OyunaGirdiKomutlar( BYTE *GelenBuf,WORD gelenpacketlen)=0;
	
virtual int StartKomutlar(packetbld gelenpacket)=0;
virtual void LoginKomutlar(BYTE GelenBuf[], WORD gelenpacketlen)=0;
	  
virtual int unCriptoLoginPacket(unsigned char *pTmp,int GelenPacketSize)=0;
virtual int SendPacket(SOCKET socket,BYTE Buf[],int size)=0;
    
	
virtual void recvLoginPacket( SOCKET recvSocket)=0;
	   
   
virtual int serverlist( int komut)=0;
//////////////////////////////

		virtual void yuklemain(void*)=0;
		virtual packetbld  ServerKeyAyir(BYTE paket[])=0;
		virtual packetbld  OyunServerKeyAyir(BYTE paket[],int deneto)=0;
		virtual packetbld  ClientKeyUret(BYTE serverKey[],unsigned int byteSize)=0;
		virtual packetbld LogRequestEncrypt(BYTE SifresizPaket[],unsigned int pcktSize)=0;
		virtual packetbld bufferdanGelenPaketAyir(BYTE BufferPaket[],unsigned int byteSize)=0;
		virtual packetbld GidecekPaketOlustur(BYTE SifrelenmisPaket[],unsigned int  byteSize)=0;
		virtual packetbld headerAyir(BYTE headerliPaket[],unsigned int byteSize)=0;
		virtual BOOL  wsSendProc(BYTE buffer[],DWORD pSize,DWORD threadid)=0;
		virtual void wsastart()=0;
		virtual bool connectKO()=0;
		virtual void wsastartGame()=0;
		virtual bool connectGameServer(char* serverip)=0;
		virtual  void  sifrelemeyidegistir()=0;
	
		virtual void oyunagir(char* charid, char* passamortt,char*karakteradi,char* server_ip)=0;
		virtual void oyunagir1(char* charid, char* passamortt,char*karakteradi,char* server_ip)=0;
		virtual void loginol(char* userid,char* password)=0;
		virtual void findaddress1()=0;
		//virtual tm* deneter(void* deneme)=0;
		//virtual time_t  deneytime0(time_t* tim)=0;
		virtual int findsub2(int l)=0;
		virtual void  findaxi(int k)=0;
		 virtual int __stdcall islemdegeri()=0;
		virtual void tabloyuolusturbeaq()=0;
		virtual int sifrele(DWORD packetadresi,DWORD packetuzunlugu,BYTE counter)=0;
		virtual int  KOPacketEncryption(DWORD flag1,DWORD bufferadresi,DWORD keyadresi,DWORD sizeofpacket,BYTE flag2)=0;
		virtual int  dwCryptograp(DWORD par1, DWORD par2, DWORD par3,DWORD par4)=0;
	
		virtual int  desifrele(DWORD,DWORD)=0;
		
		virtual  DWORD  sendprocess()=0;
		virtual  DWORD  gameEngine()=0;
		 virtual DWORD  recvprocess()=0;
		
		virtual void serverlistesiniolustur(packetbld serverlistpaketi)=0;
		virtual void  axiicinblogucoz(DWORD param1,DWORD param2,DWORD param3)=0;
		
private:
	
	

};
 #endif









