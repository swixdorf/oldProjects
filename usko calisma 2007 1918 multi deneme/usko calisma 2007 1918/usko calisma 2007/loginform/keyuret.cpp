//---------------------------------------------------------------------------

 #include <vcl.h>
//#pragma hdrstop

//#include <windows.h>
#include "keyuret.h"

#include "BMD5.cpp"
#include "ThemidaSDK.h"
#include "Iptypes.h"
#include "Iphlpapi.h"
#include <Registry.hpp>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
#define  IDENTIFY_BUFFER_SIZE  512

#define  IDE_ATAPI_IDENTIFY  0xA0
#define  IDE_ATA_IDENTIFY    0xEC
#define  DFP_RECEIVE_DRIVE_DATA   0x0007c088

#pragma pack(1)
typedef struct _IDSECTOR
{
	USHORT  wGenConfig;
	USHORT  wNumCyls;
	USHORT  wReserved;
	USHORT  wNumHeads;
	USHORT  wBytesPerTrack;
	USHORT  wBytesPerSector;
	USHORT  wSectorsPerTrack;
	USHORT  wVendorUnique[3];
	CHAR    sSerialNumber[20];
	USHORT  wBufferType;
	USHORT  wBufferSize;
	USHORT  wECCSize;
	CHAR    sFirmwareRev[8];
	CHAR    sModelNumber[40];
	USHORT  wMoreVendorUnique;
	USHORT  wDoubleWordIO;
	USHORT  wCapabilities;
	USHORT  wReserved1;
	USHORT  wPIOTiming;
	USHORT  wDMATiming;
	USHORT  wBS;
	USHORT  wNumCurrentCyls;
	USHORT  wNumCurrentHeads;
	USHORT  wNumCurrentSectorsPerTrack;
	ULONG   ulCurrentSectorCapacity;
	USHORT  wMultSectorStuff;
    ULONG   ulTotalAddressableSectors;
	USHORT  wSingleWordDMA;
    USHORT  wMultiWordDMA;
	BYTE    bReserved[128];
}IDSECTOR, *PIDSECTOR;

typedef struct _DRIVERSTATUS
{
    BYTE  bDriverError;
	BYTE  bIDEStatus;
	BYTE  bReserved[2];
	DWORD  dwReserved[2];
} DRIVERSTATUS, *PDRIVERSTATUS, *LPDRIVERSTATUS;

typedef struct _SENDCMDOUTPARAMS
{
	DWORD         cBufferSize;
	DRIVERSTATUS  DriverStatus;
	BYTE          bBuffer[1];
} SENDCMDOUTPARAMS, *PSENDCMDOUTPARAMS, *LPSENDCMDOUTPARAMS;

typedef struct _IDEREGS
{
	BYTE bFeaturesReg;
	BYTE bSectorCountReg;
	BYTE bSectorNumberReg;
	BYTE bCylLowReg;
	BYTE bCylHighReg;
	BYTE bDriveHeadReg;
	BYTE bCommandReg;
	BYTE bReserved;
} IDEREGS, *PIDEREGS, *LPIDEREGS;

typedef struct _SENDCMDINPARAMS
{
	DWORD     cBufferSize;
	IDEREGS   irDriveRegs;
	BYTE bDriveNumber;
	BYTE bReserved[3];
	DWORD     dwReserved[4];
	BYTE      bBuffer[1];
} SENDCMDINPARAMS, *PSENDCMDINPARAMS, *LPSENDCMDINPARAMS;

#pragma pack()
	  char * MD5Digest (unsigned char *s)
{
  int i;
  MD5_CTX context;
  unsigned char digest[16];
  static char ascii_digest [33];

 MD5Init(&context);
  MD5Update(&context, s, strlen(s));
  MD5Final(digest, &context);

  for (i = 0;  i < 16;  i++)
	sprintf(ascii_digest+2*i, "%02x", digest[i]);

  return(ascii_digest);
}

long __fastcall hardGetNetCardMacAdd(AnsiString *outAdd)
{

    BYTE szSystemInfo[4096] = {'\0'};
	UINT uSystemInfoLen = 0;

    UINT uErrorCode = 0;
	IP_ADAPTER_INFO iai;
	ULONG uSize = 0;
    DWORD dwResult = GetAdaptersInfo( &iai, &uSize );
    if( dwResult == ERROR_BUFFER_OVERFLOW )
    {
		IP_ADAPTER_INFO* piai = ( IP_ADAPTER_INFO* )HeapAlloc( GetProcessHeap( ), 0, uSize );
        if( piai != NULL )
        {
            dwResult = GetAdaptersInfo( piai, &uSize );
            if( ERROR_SUCCESS == dwResult )
            {
                IP_ADAPTER_INFO* piai2 = piai;
				while( piai2 != NULL && ( uSystemInfoLen + piai2->AddressLength ) < 4096U )
                {
					CopyMemory( szSystemInfo + uSystemInfoLen, piai2->Address, piai2->AddressLength );
                    uSystemInfoLen += piai2->AddressLength;
                    piai2 = piai2->Next;
                }
			}
            else
            {
                uErrorCode = 0xF0000000U + dwResult;
            }
            HeapFree( GetProcessHeap( ), 0, piai );
        }
        else
        {
			return 9;
        }
    }
    else
    {
        uErrorCode = 0xE0000000U + dwResult;
    }
    if( uErrorCode != 0U )
    {
        return 9;
    }
	*outAdd = AnsiString ((char*)szSystemInfo);
    ShowMessage(*outAdd);
	return 0;
}

long __fastcall GetBilgi(AnsiString &outID)

{
 TRegistry *r = new TRegistry();
 r->RootKey=HKEY_LOCAL_MACHINE;
 if(r->OpenKey("HARDWARE\\DESCRIPTION\\System",false))
 {
outID= r->ReadString("Identifier") ;
outID+=":"+r->ReadString("SystemBiosDate") ;
outID+=":"+r->ReadString("VideoBiosDate") ;
}
  r->Free();
 return 1 ;
}

long __fastcall hardGetCPUID(AnsiString &outID)
{
  //	BYTE szSystemInfo[4096] = {'\0'};
  //	UINT uSystemInfoLen = 0;
  //	BOOL bException = FALSE;
	BYTE szCpu[16]  = { 0 };
	UINT uCpuID     = 0U;
	__try
	{
		_asm
		{
			mov eax, 0
			cpuid
			mov dword ptr szCpu[0], ebx
			mov dword ptr szCpu[4], edx
			mov dword ptr szCpu[8], ecx
			mov eax, 1
			cpuid
			mov uCpuID, edx
		}
	}
	__except( EXCEPTION_EXECUTE_HANDLER )
	{
	 //	bException = TRUE;       //3219913727
		return 0;
	}
   outID=AnsiString((char*)szCpu)+" sn ="+IntToStr((int)uCpuID);


 /*	if( !bException )
	{
		CopyMemory( szSystemInfo + uSystemInfoLen, &uCpuID, sizeof( UINT ) );
		uSystemInfoLen += sizeof( UINT );
		uCpuID = strlen( ( char* )szCpu );
		CopyMemory( szSystemInfo + uSystemInfoLen, szCpu, uCpuID );
		uSystemInfoLen += uCpuID;
	}
	*outID = AnsiString((char*)szSystemInfo);
	return 0;   */
	 return 1 ;
}


void GetHardewareInfos(SYSTEM_INFO &siSysInfo)
{
//   SYSTEM_INFO siSysInfo;

   // Copy the hardware information to the SYSTEM_INFO structure.

   ::GetSystemInfo(&siSysInfo);

   // Display the contents of the SYSTEM_INFO structure.

   printf("Hardware information: \n");
   printf(" OEM ID: %u\n", siSysInfo.dwOemId);
   printf(" Number of processors: %u\n",
	  siSysInfo.dwNumberOfProcessors);
   printf(" Page size: %u\n", siSysInfo.dwPageSize);
   printf(" Processor type: %u\n", siSysInfo.dwProcessorType);
   printf(" Minimum application address: %lx\n",
	  siSysInfo.lpMinimumApplicationAddress);
   printf(" Maximum application address: %lx\n",
	  siSysInfo.lpMaximumApplicationAddress);
   printf(" Active processor mask: %u\n",
	  siSysInfo.dwActiveProcessorMask);
}
void ChangeByteOrder(LPSTR lpString, int nLen)
{
	USHORT i;
	CHAR c;

	// 63 63 72 75 6E 2E 63 6F 6D
	for(int i = 0; i < nLen; i += 2)
	{
		c = lpString[i];
		lpString[i] = lpString[i+1];
		lpString[i+1] = c;
	}
}

bool CrnGetHDSerialNumber(LPSTR lpBuf)
{
strcpy(lpBuf, "");

	HANDLE hDevice;

	if(Win32Platform == VER_PLATFORM_WIN32_NT)
		// 获取第一个硬盘，如果有多个，更改PhysicalDrive?就可以了。
		hDevice = CreateFileA("\\\\.\\PhysicalDrive0",
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				OPEN_EXISTING,
                0,
				0);
	else
		hDevice = CreateFileA("\\\\.\\SMARTVSD", 0, 0, NULL, CREATE_NEW, 0, 0);

	if(hDevice == INVALID_HANDLE_VALUE) return false;

	SENDCMDINPARAMS scip = { 0 };
	char szBuffer[sizeof(SENDCMDOUTPARAMS) + IDENTIFY_BUFFER_SIZE] = { 0 };
	DWORD dwBytesRet = 0;
    bool bSuccess = false;
	try
    {
		scip.cBufferSize = IDENTIFY_BUFFER_SIZE;

		scip.irDriveRegs.bSectorCountReg = 1;
		scip.irDriveRegs.bSectorNumberReg = 1;
		scip.irDriveRegs.bDriveHeadReg = IDE_ATAPI_IDENTIFY;
        scip.irDriveRegs.bCommandReg = IDE_ATA_IDENTIFY;

        if(DeviceIoControl(hDevice,
				DFP_RECEIVE_DRIVE_DATA,
                &scip,
				sizeof(SENDCMDINPARAMS) - 1,
                szBuffer,
				sizeof(szBuffer),
                &dwBytesRet,
				NULL))
		{
			PSENDCMDOUTPARAMS pOut = (PSENDCMDOUTPARAMS)szBuffer;
            PIDSECTOR pIdSec = (PIDSECTOR)(pOut->bBuffer);
			ChangeByteOrder(pIdSec->sSerialNumber, sizeof(pIdSec->sSerialNumber));
			strncpy(lpBuf,   pIdSec-> sSerialNumber,   dwBytesRet);
			bSuccess = true;
        }
	}
    __finally
	{
        CloseHandle(hDevice);
	}

	return bSuccess;
}


AnsiString KeyUret(AnsiString prkey)
{
CODEREPLACE_START
AnsiString a;
AnsiString b;
char sz[1024];
ZeroMemory(sz,255);
//CrnGetHDSerialNumber(sz);
//b=String(sz).Trim();
GetBilgi(a);
b+=a;
a="";
hardGetCPUID(a);
b+=a;
//hardGetLocalHostIpAddr(&a);
//SYSTEM_INFO siSysInfo;
//GetHardewareInfos( siSysInfo);
//
//a=IntToStr((int)siSysInfo.dwOemId)+IntToStr((int)siSysInfo.wProcessorArchitecture)+
//IntToStr((int)siSysInfo.dwProcessorType)+IntToStr((int)siSysInfo.wProcessorRevision)+ IntToStr((int)siSysInfo.wProcessorLevel)+
//IntToStr((int)siSysInfo.dwNumberOfProcessors);
//b+=a;
//MEMORYSTATUS m;
//GlobalMemoryStatus(&m);
//a=IntToStr((int)m.dwTotalPhys)+":"+IntToStr((int)m.dwTotalVirtual);
//b+=a;
AnsiString Key=prkey;//"13-08-2011";
AnsiString KeyKontrol=Key+b;
KeyKontrol=( MD5Digest(KeyKontrol.c_str()));
KeyKontrol=KeyKontrol.UpperCase();
KeyKontrol=AnsiString( MD5Digest(KeyKontrol.c_str()));
KeyKontrol= KeyKontrol.UpperCase();

CODEREPLACE_END
return KeyKontrol;
}
