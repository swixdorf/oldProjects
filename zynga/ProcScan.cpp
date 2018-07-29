//---------------------------------------------------------------------------

#include <vcl.h>


#include "ProcScan.h"

//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)


 #define STATUS_SUCCESS ((NTSTATUS)0x00000000L)

#define ThreadQuerySetWin32StartAddress 9
typedef LONG    NTSTATUS;

typedef NTSTATUS (WINAPI *pNtQIT)(HANDLE, LONG, PVOID, ULONG, PULONG);

static CREATESNAPSHOT pCreateToolhelp32Snapshot = NULL;
static MODULEWALK  pModule32First  = NULL;
static MODULEWALK  pModule32Next   = NULL;
static PROCESSWALK pProcess32First = NULL;
static PROCESSWALK pProcess32Next  = NULL;
static THREADWALK  pThread32First  = NULL;
static THREADWALK  pThread32Next   = NULL;

DllHook(DWORD &Adress,String Module,String Proc)
{
   Adress=(DWORD)GetProcAddress(GetModuleHandle(Module.c_str()),Proc.c_str());
}


DWORD WINAPI GetThreadStartAddress(HANDLE hThread)

{

	 NTSTATUS ntStatus;

     HANDLE hDupHandle;

     DWORD dwStartAddress;

    

	pNtQIT NtQueryInformationThread = (pNtQIT)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtQueryInformationThread");

    if(NtQueryInformationThread == NULL) return 0;

    

    HANDLE hCurrentProcess = GetCurrentProcess();

    if(!DuplicateHandle(hCurrentProcess, hThread, hCurrentProcess, &hDupHandle, THREAD_QUERY_INFORMATION, FALSE, 0)){

	  //	SetLastError(ERROR_ACCESS_DENIED);

		return 0;

    }

    ntStatus = NtQueryInformationThread(hDupHandle, ThreadQuerySetWin32StartAddress, &dwStartAddress, sizeof(DWORD), NULL);

    CloseHandle(hDupHandle);

    

	if(ntStatus != STATUS_SUCCESS) return 0;

    return dwStartAddress;

}

BOOL ListProcessModules( DWORD dwPID ,AnsiString &Name)
{
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
  MODULEENTRY32 me32;

  // Take a snapshot of all modules in the specified process.
  hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
  if( hModuleSnap == INVALID_HANDLE_VALUE )
  {

    return( FALSE );
  }

  // Set the size of the structure before using it.
  me32.dwSize = sizeof( MODULEENTRY32 );

  // Retrieve information about the first module,
  // and exit if unsuccessful
  if( !Module32First( hModuleSnap, &me32 ) )
  {

    CloseHandle( hModuleSnap );           // clean the snapshot object
    return( FALSE );
  }

  // Now walk the module list of the process,
  // and display information about each module
  do
  {
			int pos= AnsiString(me32.szModule).AnsiPos("Flash");
			if(pos>0)
			{
			   Name=	 AnsiString(me32.szModule);
			   CloseHandle( hModuleSnap );
  return( true );
            }

  } while( Module32Next( hModuleSnap, &me32 ) );

  CloseHandle( hModuleSnap );
  return( false );
}

//#define MakePtr( cast, ptr, addValue ) (cast)( (DWORD)(ptr)+(DWORD)(addValue))
#ifdef _WIN64
#define POINTER_TYPE ULONGLONG
#else
#define POINTER_TYPE DWORD
#endif

#define MakePtr(cast, base, offset) (cast)((DWORD_PTR)(base) + (DWORD_PTR)(offset))

HRESULT WriteProtectedMemory(LPVOID lpvDest, LPVOID lpvSrc, DWORD dwSize) {

    DWORD dwOldProtect = 0;

    __try {

        if( VirtualProtect(lpvDest, dwSize, PAGE_READWRITE, &dwOldProtect) ) {

            InterlockedExchange((LONG*)lpvDest, (LONG)lpvSrc);
            VirtualProtect(lpvDest, dwSize, dwOldProtect, &dwOldProtect);
            return S_OK;

        } // if( VirtualProtect(pDest, dwSize, PAGE_READWRITE, &dwOldProtect) )

    }
    __except( EXCEPTION_EXECUTE_HANDLER ) {

    }

    return HRESULT_FROM_WIN32(GetLastError());

}

BOOL HookImportsOfImage(HMODULE hModule, PCHAR pchDllTarget, PCHAR pchFuncTarget, LPVOID lpvMineFunc) {

    PIMAGE_DOS_HEADER pDosHeader;
    PIMAGE_NT_HEADERS pNTHeaders;
    PIMAGE_IMPORT_DESCRIPTOR pImpDesc;
    PIMAGE_IMPORT_BY_NAME pImageImpByName;
    DWORD dwImportsStartRVA;
    PDWORD pdwIAT, pdwINTO;
    int iCount, iIndex;
    PCHAR pchDllName = NULL;

    pDosHeader = (PIMAGE_DOS_HEADER)hModule;
    pNTHeaders = MakePtr(PIMAGE_NT_HEADERS, hModule, pDosHeader->e_lfanew);

    if( pNTHeaders->Signature != IMAGE_NT_SIGNATURE || pDosHeader->e_magic != IMAGE_DOS_SIGNATURE )
        return FALSE;

    dwImportsStartRVA = pNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

    if( !dwImportsStartRVA )
        return FALSE;

    pImpDesc = (PIMAGE_IMPORT_DESCRIPTOR)(dwImportsStartRVA+(DWORD)pDosHeader);

    for( iCount = 0; pImpDesc[iCount].Characteristics != 0; iCount++ ) {

        pchDllName = (PCHAR)(pImpDesc[iCount].Name + (DWORD)pDosHeader);
		pdwIAT = (PDWORD)(((DWORD)pDosHeader) + (DWORD)pImpDesc[iCount].FirstThunk);
        pdwINTO = (PDWORD)(((DWORD)pDosHeader) + (DWORD)pImpDesc[iCount].OriginalFirstThunk);
			if (stricmp(pchDllName, pchDllTarget) != 0 )  continue;

        for( iIndex = 0; pdwIAT[iIndex] != 0; iIndex++ ) {

			if( (pdwIAT[iIndex] & IMAGE_ORDINAL_FLAG) != IMAGE_ORDINAL_FLAG ) {


				pImageImpByName = (PIMAGE_IMPORT_BY_NAME)(pdwINTO[iIndex] + ((DWORD)pDosHeader));

				if(strcmp((PCHAR)(pImageImpByName->Name), pchFuncTarget) == 0)  {

					WriteProtectedMemory((LPVOID)&pdwIAT[iIndex], (LPVOID)lpvMineFunc, sizeof(LPVOID));

				} // if( (_stricmp(pchDllName, pchDllTarget) == 0 ) && (strcmp(pImageImpByName->Name, pchFuncTarget) == 0) )


			} // if( (pdwIAT[iIndex] & IMAGE_ORDINAL_FLAG) != IMAGE_ORDINAL_FLAG )
			else
			{
				  char * x= (char*)IMAGE_ORDINAL(pdwIAT[iIndex]);
            }
        
        } // for( iIndex = 0; pdwIAT[iIndex] != 0; iIndex++ )
    
    } // for( iCount = 0; pImpDesc[iCount].Characteristics != 0; iCount++ )

    return TRUE;

}

///////////////////////////////////////

DWORD RvaToOffset(IMAGE_NT_HEADERS *NT, DWORD Rva)
{
   DWORD Offset = Rva, Limit;
   IMAGE_SECTION_HEADER *Img;
   WORD i;

   Img = IMAGE_FIRST_SECTION(NT);

   if (Rva < Img->PointerToRawData)
      return Rva;

   for (i = 0; i < NT->FileHeader.NumberOfSections; i++)
   {
      if (Img[i].SizeOfRawData)
         Limit = Img[i].SizeOfRawData;
      else
         Limit = Img[i].Misc.VirtualSize;

      if (Rva >= Img[i].VirtualAddress &&
         Rva < (Img[i].VirtualAddress + Limit))
      {
         if (Img[i].PointerToRawData != 0)
         {
            Offset -= Img[i].VirtualAddress;
            Offset += Img[i].PointerToRawData;
         }

         return Offset;
      }
   }

   return NULL;
}
int BuildImportTable1(DWORD module,DWORD hookproc,char *Apiname,char *dllname)
{
BYTE *PE_Image;

   IMAGE_DOS_HEADER *ImgDosHdr;
   IMAGE_NT_HEADERS *ImgNtHdrs;

   ULONG_PTR ImgBase, Delta, Reloc_Offset;
   IMAGE_BASE_RELOCATION *ImgBaseReloc;
   WORD *wData;
   UINT i, nItems;
   ULONG_PTR Offset;
   DWORD Type;
   ULONG_PTR *Block, BlockOffs;

   ULONG_PTR IT_Offset;
   IMAGE_IMPORT_DESCRIPTOR *ImgImpDescr;
   UINT x = 0, y = 0;
   CHAR *DllName;
   ULONG_PTR *Thunks, *FThunks;
   IMAGE_IMPORT_BY_NAME *ImgImpName;

	   BYTE *PE_Buffer = ( BYTE *)   module;
	  ImgDosHdr = (IMAGE_DOS_HEADER *) module;

      ImgNtHdrs = (IMAGE_NT_HEADERS *) (ImgDosHdr->e_lfanew +
		 (ULONG_PTR) PE_Buffer);

      if (ImgDosHdr->e_magic != IMAGE_DOS_SIGNATURE ||
         ImgNtHdrs->Signature != IMAGE_NT_SIGNATURE)
	  {

         return FALSE;
      }



      if (ImgBase == NULL)
      {

		 return FALSE;
      }

      //
      // is file image base == memory image base?
      // if not, relocate
      //


	  //
	  // fill the import addres table
	  //

	  if (ImgNtHdrs->OptionalHeader.DataDirectory
		 [IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress)
	  {
		 IT_Offset = RvaToOffset(ImgNtHdrs,
            ImgNtHdrs->OptionalHeader.DataDirectory
            [IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

         ImgImpDescr = (IMAGE_IMPORT_DESCRIPTOR *) (IT_Offset +
            (ULONG_PTR) PE_Buffer);


         // for each descriptor
         while (ImgImpDescr[x].FirstThunk != 0)
         {
			DllName = (CHAR *) (RvaToOffset(ImgNtHdrs,
               ImgImpDescr[x].Name) + (ULONG_PTR) PE_Buffer);

            Thunks = (ULONG_PTR *) (RvaToOffset(ImgNtHdrs,
               ImgImpDescr[x].OriginalFirstThunk != 0 ?
               ImgImpDescr[x].OriginalFirstThunk : 
            ImgImpDescr[x].FirstThunk) + (ULONG_PTR) PE_Buffer);

            FThunks = (ULONG_PTR *) (RvaToOffset(ImgNtHdrs,
               ImgImpDescr[x].FirstThunk) + (ULONG_PTR) PE_Buffer);

			y = 0;
				if (stricmp(DllName, dllname) != 0 )  continue;

            //
            // every imported function of the module
            //

            while (Thunks[y] != 0)
            {
               //
               // imported by ordinal?
               //

               if (Thunks[y] & IMAGE_ORDINAL_FLAG)
			   {
			   if (strcmp( (LPCSTR) (Thunks[y] - IMAGE_ORDINAL_FLAG), Apiname) == 0)
				{
			   FThunks[y] =  hookproc ;return 1;
				}

//                  FThunks[y] = (ULONG_PTR) GetProcAddress(
//                     GetModuleHandle(DllName),
//                     (LPCSTR) (Thunks[y] - IMAGE_ORDINAL_FLAG));

                  y++;

                  continue;
               }

               ImgImpName = (IMAGE_IMPORT_BY_NAME *) (RvaToOffset(
				  ImgNtHdrs, Thunks[y]) + (ULONG_PTR) PE_Buffer);

				  if (strcmp( (LPCSTR) &ImgImpName->Name, Apiname) == 0)
				  FThunks[y] =  hookproc ;return 1;

//			   FThunks[y] = (ULONG_PTR) GetProcAddress(GetModuleHandle(DllName),
//                  (LPCSTR) &ImgImpName->Name);

               y++;
            }

            x++;
         }


	  }
}
//////////////////////////////////////
int BuildImportTable(DWORD module,DWORD hookproc,char *Apiname,char *dllname)
{
	int result=1;
	unsigned char *codeBase = (char*)module;

	PIMAGE_DOS_HEADER dosHeader;
	PIMAGE_NT_HEADERS pNTHeader;
	PIMAGE_IMPORT_DESCRIPTOR importDesc;
	PIMAGE_IMPORT_BY_NAME p_ibn;
	DWORD importsStartRVA;
	PDWORD pd_IAT, pd_INTO;
	int count, index;
	char *dll_name = NULL;
	char *pc_dlltar = dllname;


	dosHeader = (PIMAGE_DOS_HEADER) module;

	pNTHeader = MakePtr( PIMAGE_NT_HEADERS, dosHeader,
								dosHeader->e_lfanew );
	
	// First, verify that the e_lfanew field gave us a reasonable
	// pointer, then verify the PE signature.
	if ( pNTHeader->Signature != IMAGE_NT_SIGNATURE )
		return 0;

importsStartRVA = pNTHeader->OptionalHeader.DataDirectory
							[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

	if (!importsStartRVA)
		return 0;

     importDesc = (PIMAGE_IMPORT_DESCRIPTOR) (importsStartRVA + (DWORD) dosHeader);

	for (count = 0; importDesc[count].Characteristics != 0; count++)
	{
		dll_name = (char*) (importDesc[count].Name + (DWORD) dosHeader);

			   if (stricmp(dll_name, pc_dlltar) != 0)   continue;

		pd_IAT = (PDWORD)(((DWORD) dosHeader) + (DWORD)importDesc[count].FirstThunk);
		pd_INTO = (PDWORD)(((DWORD) dosHeader) + (DWORD)importDesc[count].OriginalFirstThunk);
		PIMAGE_THUNK_DATA th= (PIMAGE_THUNK_DATA) pd_INTO;
	
		for (index = 0; pd_IAT[index] != 0; index++)
		{

			if ((pd_INTO[index] & IMAGE_ORDINAL_FLAG) != IMAGE_ORDINAL_FLAG)
			{
				p_ibn = (PIMAGE_IMPORT_BY_NAME)(pd_INTO[index]+((DWORD) dosHeader));
				if (strcmp(p_ibn->Name, Apiname) == 0)
				{

					*(DWORD*)&pd_IAT[index]=  hookproc;


					   return 1;

				}
			}
			else
			{                   //16 recv    //19 ord send

				 int ord=  IMAGE_ORDINAL(pd_INTO[index]);//(char*)pd_INTO[index]  - IMAGE_ORDINAL_FLAG ;
					if (ord== String(Apiname).ToIntDef(-1))
				  	{

					WriteProtectedMemory((void*)&pd_IAT[index],(void*)hookproc,4) ;
				  //	*(DWORD*)&pd_IAT[index]=  hookproc;

                     return 1;


				}
            }
		}
	}
	
//		PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR) (importsStartRVA + (DWORD) dosHeader);
////		for (; !IsBadReadPtr(importDesc, sizeof(IMAGE_IMPORT_DESCRIPTOR)) && importDesc->Name; importDesc++) {
//			POINTER_TYPE *thunkRef;
//			FARPROC *funcRef;
//
//			if	(strcmp((char*)codeBase +importDesc->Name, dllname) != 0)  continue;
//			
//			if (importDesc->OriginalFirstThunk) {
//				thunkRef = (POINTER_TYPE *) (codeBase + importDesc->OriginalFirstThunk);
//				funcRef = (FARPROC *) (codeBase + importDesc->FirstThunk);
//			} else {
//				// no hint table
//				thunkRef = (POINTER_TYPE *) (codeBase + importDesc->FirstThunk);
//				funcRef = (FARPROC *) (codeBase + importDesc->FirstThunk);
//			}
//			for (; *thunkRef; thunkRef++, funcRef++) {
//				if (IMAGE_SNAP_BY_ORDINAL(*thunkRef)) {
//
//					   if	(strcmp((char*)IMAGE_ORDINAL(*thunkRef), Apiname) == 0)
//					   {
//					*funcRef = (FARPROC)hookproc;
//					return 1;
//					   }
//
//
//				} else {
//					PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME) (codeBase + (*thunkRef));
//
//				  if	(strcmp(thunkData->Name, Apiname) == 0)
//				  {
//					*funcRef = (FARPROC)hookproc;
//					return 1;
//				  }
//				}
//				if (*funcRef == 0) {
//					result = 0;
//					break;
//				}
//			}
//
//			if (!result) {
//				break;
//			}
//		}
//
//
//	return result;
}


DWORD ThreadScan(DWORD ProcID,DWORD Adress,TStrings *DurumYaz)
{

  if(!InitToolhelp32())return 0;
  HANDLE hSnapshotThread = pCreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 );
    if ( hSnapshotThread == INVALID_HANDLE_VALUE )
        return 0;
	THREADENTRY32 TE32;
	TE32.dwSize = sizeof( THREADENTRY32 );
    BOOL gotTE32 = FALSE;
	if ( pThread32First( hSnapshotThread, &TE32 ) )
	{
        do
		{

			if ( TE32.th32OwnerProcessID == ProcID )
			{
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, TE32.th32ThreadID);
				DWORD dwThreadStartAddress = GetThreadStartAddress(hThread);
				DurumYaz->Clear();
				DurumYaz->Add(IntToHex((int)dwThreadStartAddress,8));
				if((dwThreadStartAddress>0x0093C300)&&(dwThreadStartAddress<0x0093C3FF))
				{
				 SuspendThread(hThread);
				 CloseHandle( hSnapshotThread );
				CloseHandle(hThread);
				gotTE32 = TRUE;
				goto Cikis;

				}
				else
				{
				CloseHandle(hThread);
                    continue; 
                }
            }
        } while ( (!gotTE32) && pThread32Next( hSnapshotThread, &TE32 ) );
	}
    if ( !gotTE32 )
    {
        CloseHandle( hSnapshotThread );
        return 0;
	}
	Cikis:
	return gotTE32;
}

 InitToolhelp32(void)
 {
	BOOL   bRet  = FALSE;
	HANDLE hKernel = NULL;

	// Obtain the module handle of the kernel to retrieve addresses of
	// the tool helper functions.
	hKernel = GetModuleHandle("KERNEL32.DLL");

	if (hKernel){
		pCreateToolhelp32Snapshot =
			(CREATESNAPSHOT)GetProcAddress(hKernel,			"CreateToolhelp32Snapshot");

 
		pModule32First  = (MODULEWALK)GetProcAddress(hKernel,
            "Module32First"); 
        pModule32Next   = (MODULEWALK)GetProcAddress(hKernel, 
            "Module32Next"); 
 
        pProcess32First = (PROCESSWALK)GetProcAddress(hKernel, 
            "Process32First"); 
        pProcess32Next  = (PROCESSWALK)GetProcAddress(hKernel, 
            "Process32Next"); 
 
        pThread32First  = (THREADWALK)GetProcAddress(hKernel, 
            "Thread32First"); 

        pThread32Next   = (THREADWALK)GetProcAddress(hKernel, 
            "Thread32Next"); 
 
        // All addresses must be non-NULL to be successful. 
        // If one of these addresses is NULL, one of 
		// the needed lists cannot be walked.
        bRet =  pModule32First && pModule32Next  && pProcess32First && 
                pProcess32Next && pThread32First && pThread32Next && 
                pCreateToolhelp32Snapshot; 
    } 
    else 
        bRet = FALSE; // could not even get the module handle of kernel 

 
	return bRet;
}
