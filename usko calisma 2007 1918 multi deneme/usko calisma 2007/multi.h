
char name[MAX_PATH];
DWORD my_tid;
DWORD HSThreadid;
DWORD kontrolThreadid;
DWORD kontrolThreadid2;
DWORD orj3=0;
DWORD HsLastControlTick;
HANDLE hsKontrolEvent;

BYTE ORJCODE[10];

bool logyaz(AnsiString Mesaj)
{
	TDateTime a;
	a = a.CurrentDateTime();
	ofstream fSave;
	fSave.open("mylog.ini",std::ios_base::out | std::ios_base::app);
	if(fSave.is_open() == true)
	{
		fSave << a.DateTimeString().c_str()<< " : " << Mesaj.c_str() << "\n";
		fSave.close();
	}
}

typedef struct
{
	DWORD Par1 ;
	BYTE  Data[2048];
	DWORD DataUzunluk;
	DWORD Par3 ;
	DWORD RetNe;
}MyDataStruct;

DWORD __fastcall HSDLLResponse(char *gelendata,DWORD uzununluk,char *gidecekdata)
{
SetEvent(hsKontrolEvent);
//HsLastControlTick = GetTickCount();
//logyaz(BufferToHex(gelendata,uzununluk));
	DWORD RetNe;
	asm
	{
		push gidecekdata
		push uzununluk
		push  gelendata //0xD                                                         3
		mov eax,HSDCALL
		call eax
		mov RetNe,eax
	}
	return RetNe;
}

WINAPI fakeHSCALL(DWORD a,DWORD b,DWORD c)
{
	return 1;
}
#define socketoku WM_USER+100
typedef struct
{
	TCustomWinSocket *Socket;
	HANDLE ghWriteEvent;
}hsgelenyapi;





hscoz (TCustomWinSocket *Socket)
{
	BYTE Gelen[1024];
	BYTE Yollancak[1024];
	BYTE HsSend[1024];
	memset(Gelen,0,1024);
	int len = Socket->ReceiveLength();
	Socket->ReceiveBuf(Gelen,len);
	try
	{
		if (Gelen[0]==1)
		{
			char Paryaz[2048];
			memset(Paryaz,0,2048);
			char Paroku[2048];
			memset(Paroku,0,2048);
			memcpy(Paroku,&Gelen[7],*(WORD*)&Gelen[5]);
			DWORD sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[5],Paryaz);
			memcpy(&HsSend,&Paryaz,410);

		}
		else if(Gelen[0]==2)
		{
			char Paryaz[2048];
			memset(Paryaz,0,2048);
			char Paroku[2048];
			memset(Paroku,0,2048);
			memcpy(Paroku,&Gelen[7],*(WORD*)&Gelen[5]);
			DWORD sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[5],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			int yer =  *(WORD*)&Gelen[1]+3;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);
			memcpy(&HsSend,&Paryaz,410);

		}
		else if(Gelen[0]==3)
		{
			char Paryaz[2048];
			memset(Paryaz,0,2048);
			char Paroku[2048];
			memset(Paroku,0,2048);
			memcpy(Paroku,&Gelen[7],*(WORD*)&Gelen[5]);
			DWORD sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[5],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			int yer =  *(WORD*)&Gelen[1]+3;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			yer +=  *(WORD*)&Gelen[yer]+2;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);

			memcpy(&HsSend,&Paryaz,410);

		}
		else if(Gelen[0]==4)
		{
			char Paryaz[2048];
			memset(Paryaz,0,2048);
			char Paroku[2048];
			memset(Paroku,0,2048);
			memcpy(Paroku,&Gelen[7],*(WORD*)&Gelen[5]);
			DWORD sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[5],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			int yer =  *(WORD*)&Gelen[1]+3;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			yer +=  *(WORD*)&Gelen[yer]+2;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);
			memset(Paryaz,0,2048);
			memset(Paroku,0,2048);
			yer +=  *(WORD*)&Gelen[yer]+2;
			memcpy(Paroku,&Gelen[yer+6],*(WORD*)&Gelen[yer+4]);
			sonuc=HSDLLResponse(Paroku,*(WORD*)&Gelen[yer+4],Paryaz);
			memcpy(&HsSend,&Paryaz,410);

		}
		Socket->SendBuf(HsSend,410);

	}
	catch (...)
	{

	}
}


int WINAPI kontrol2()
{
	while (1)
	{
		Sleep(15000);
		if (FileExists("mylog.ini"))
		{
		DeleteFileA("mylog.ini");
		}
		else
		{
			logyaz("Terminated");
			ExitProcess(0);
		}
	}
}
int WINAPI kontrol()
{
	while (1)
	{
		Sleep(5000);
		if (WaitForSingleObject(hsKontrolEvent,10000))
		{
			ResetEvent(hsKontrolEvent);
		}
		else
		{
			ResetEvent(hsKontrolEvent);
			logyaz("Terminated");
			ExitProcess(0);
		}
	}
}


int WINAPI threadoku()
{
	hsgelenyapi *gelenhs;
	logyaz("Thread Start");
	MSG msg;
	while(::GetMessage( &msg, NULL, 0, 0 ))
	{
		switch (msg.message)
		{
			case socketoku:
			{
				gelenhs= (hsgelenyapi*)msg.wParam;
				hscoz(gelenhs->Socket);
				if (! SetEvent(gelenhs->ghWriteEvent) )
				{
					logyaz("SetEvent failed : "+IntToStr( GetLastError()));
				}
				else
				{
					logyaz("SetEvent ok");
				}
			}break;
			default:;
		}
	}
	logyaz("Thread cik");
}

BOOL ListProcessThreadsSuspend( DWORD dwOwnerPID ,DWORD DontSuspendtid,bool SuspendMainThread)
{
	HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
	THREADENTRY32 te32;
	hThreadSnap = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 );
	if( hThreadSnap == INVALID_HANDLE_VALUE )
		return( FALSE );
	te32.dwSize = sizeof(THREADENTRY32 );
	if( !Thread32First( hThreadSnap, &te32 ) )
	{
		CloseHandle( hThreadSnap );     // Must clean up the snapshot object!
		return( FALSE );
	}
	do
	{
	if( te32.th32OwnerProcessID == dwOwnerPID )
	{
		DWORD thid=GetCurrentThreadId() ;
		if(thid!= te32.th32ThreadID)
		{
			HANDLE thHandle=OpenThread(2,0,te32.th32ThreadID) ;
			DWORD tid = 0;//GetThreadId(thHandle);
			if (DontSuspendtid!=tid)
			{
				SuspendThread(thHandle);
			}
			CloseHandle( hThreadSnap );
		}

	}
	}
	while( Thread32Next(hThreadSnap, &te32 ) );
	CloseHandle( hThreadSnap );
	return( TRUE );
}

BOOL ListProcessThreadsResume( DWORD dwOwnerPID )
{
	HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
	THREADENTRY32 te32;
	hThreadSnap = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 );
	if( hThreadSnap == INVALID_HANDLE_VALUE )
		return( FALSE );
	te32.dwSize = sizeof(THREADENTRY32 );
	if( !Thread32First( hThreadSnap, &te32 ) )
	{
		CloseHandle( hThreadSnap );     // Must clean up the snapshot object!
		return( FALSE );
	}
	do
	{
		if( te32.th32OwnerProcessID == dwOwnerPID )
		{
			DWORD thid=GetCurrentThreadId() ;
			if(thid!= te32.th32ThreadID)
			{
				HANDLE thHandle=OpenThread(2,0,te32.th32ThreadID) ;
				ResumeThread(thHandle);
				CloseHandle( hThreadSnap );
			}
		}
	} while( Thread32Next(hThreadSnap, &te32 ) );
	CloseHandle( hThreadSnap );
	return( TRUE );
}

void __fastcall duzelt()
{
	memcpy((void*)Kontrol,ORJCODE,10);
}

int WINAPI hshs(long lParam)
{
Sleep(7000);
while (1){
asm{
	mov eax,0x00449560
	call eax
	 fstp    [0x00D81E3C]
}
Sleep(2000);
}
}
int mult ;
__declspec(naked)dondon()
{
	asm
	{
		pushad
		call duzelt
		popad
		mov eax,KODEVAM
		mov [esp+0],eax
		RET
	}
}

bool kitle ()
{
	try
	{
		ff= new TFileStream(name,fmShareDenyRead);
	}
	catch (...)
	{
		ShowMessage("Lock Error");
	}
}
bool coz ()
{
	try
	{
		ff->Free();
	}
	catch (...)
	{
		ShowMessage("UnLock Error");
	}
}
int WINAPI cfhook(DWORD a1,DWORD a2, DWORD a3,DWORD a4)
{
	DWORD retne ;
	asm
	{
		push a4
		push a3
		push a2
		push a1
		mov eax,ds:cfHookAddr
		call eax
		mov retne,eax
		add esp, 10h
	}
	return retne;
}
bool hallet(){
	DWORD adr = (DWORD) malloc(0x200);
	DWORD msc=adr;
	memcpy( (LPVOID)adr, (LPVOID)0x0048F1F0, 0x200 );
//ShowMessage(IntToHex((int)msc,8));
//FillMemory( (PVOID)(adr + 50), 7, 0x90 ); // nop xd
  int fark  = 0 ;
  fark = (DWORD)adr-0x0048F1F0;

  int a = *(int*)(adr+0xb);
  a-=fark;
  *(int*)(adr+0xb)=a;

  a = *(int*)(adr+0x9d);
  a-=fark;
  *(int*)(adr+0x9d)=a;

	a = *(int*)(adr+0xd8);
  a-=fark;
  *(int*)(adr+0xd8)=a;
	a = *(int*)(adr+0x10c);
  a-=fark;
  *(int*)(adr+0x10c)=a;

	a = *(int*)(adr+0x125);
  a-=fark;
  *(int*)(adr+0x125)=a;

	a = *(int*)(adr+0x150);
  a-=fark;
  *(int*)(adr+0x150)=a;

	a = *(int*)(adr+0x1ce);
  a-=fark;
  *(int*)(adr+0x1ce)=a;
}


HRESULT swxCreateDevice2
(
UINT Adapter,
D3DDEVTYPE DeviceType,
HWND hFocusWindow,
DWORD BehaviorFlags,
D3DPRESENT_PARAMETERS *pPresentationParameters,
D3DDISPLAYMODEEX *pFullscreenDisplayMode,
IDirect3DDevice9Ex **ppReturnedDeviceInterface
)
{
ShowMessage(pPresentationParameters->BackBufferWidth);
HRESULT retdeger;
	__asm
	{
		push Adapter
		push DeviceType
		push hFocusWindow
		push BehaviorFlags
		push pPresentationParameters
		push pFullscreenDisplayMode
		push ppReturnedDeviceInterface
		mov eax,orj_cDevice2
		call eax
		mov retdeger,eax
	}
	d3device = *ppReturnedDeviceInterface ;
	return retdeger;
}


IDirect3D9 *__stdcall swxCreateDevice(UINT SDKVersion)
{

__asm{
	push SDKVersion
	mov eax,orj_cDevice
	call eax
	mov d3d,eax

}

 /*
 DWORD lpflOldProtect;

	VirtualProtect((void*)&pVtable[iIndex], sizeof(DWORD), PAGE_READWRITE, &lpflOldProtect);
orj_cDevice2  = *(DWORD*)(*(DWORD*)d3d+ 0x40);
	VirtualProtect(pVtable, sizeof(DWORD), lpflOldProtect, &lpflOldProtect);

//ShowMessage(IntToHex((int)d3d,8));


ShowMessage(IntToHex((int)orj_cDevice2,8));     */
/*
*(DWORD*) = (DWORD)swxCreateDevice2;
ShowMessage(IntToHex((int)swxCreateDevice2,8));
 */
/*


HMODULE hDx = GetModuleHandle("d3d9.dll");
while (hDx==NULL){
HMODULE hDx = GetModuleHandle("d3d9.dll");
Sleep(100);
}

FARPROC hDirect3DCreate9 = GetProcAddress(hDx, "Direct3DCreate9");
ShowMessage(IntToHex((int)hDirect3DCreate9,8)) ;    */
return d3d;
}


bool baypas()

{
		Don:
	Sleep(20);
	if (*(DWORD*)(Kontrol)!=KotrolDeger)
	{
		goto Don;
	}

	ListProcessThreadsSuspend(GetCurrentProcessId(),my_tid,0);

	char tmp[25];
	memset(tmp,0,25);
	Sleep(2000);
	ReadProcessMemory(GetCurrentProcess(),(LPVOID)KO_WNDA,tmp,20,NULL);
	if (String(tmp)!="Knight OnLine Client")
	{
		/*orj_cDevice  = *(DWORD*)cdxDevice;
		*(DWORD*)cdxDevice = (DWORD)swxCreateDevice;  */





 /*
HMODULE hDx = GetModuleHandle("d3d9.dll");
while (hDx==NULL){
HMODULE hDx = GetModuleHandle("d3d9.dll");
Sleep(100);
}

FARPROC hDirect3DCreate9 = GetProcAddress(hDx, "Direct3DCreate9");
ShowMessage(IntToHex((int)hDirect3DCreate9,8)) ;   */


	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)hshs,NULL,0,0);
		*(BYTE*)(0x00A1B432) =  0xb8;
	*(DWORD*)(0x00A1B432+1) =  0x201;
	*(BYTE*)(0x00A1B432+5) =  0xc3;
		memset(name,0,MAX_PATH);
		GetModuleFileNameA(0,name,MAX_PATH);
		memcpy(ORJCODE,(void*)Kontrol,10);
		DWORD d=(DWORD)dondon;
		d=(d-Kontrol);
		d-=5;
		*(BYTE*)Kontrol  = 0xe8;
		*(DWORD*)(Kontrol+1)=d;
          
		asm
		{
			mov eax, offset fakeHSCALL
			mov ds:ds:fakeHsAddr,eax
		}

		/*DWORD d3=(DWORD)  cfhook;
		d3=(d3-Kontrol2);
		d3-=5;
		*(DWORD*)(Kontrol2+1)=d3;*/
	}
	else
	{

	ListProcessThreadsResume(GetCurrentProcessId());
	ShowMessage("BU MESAJI OYUNA GIRIS \nTAMAMLANDIKTAN SONRA ONAYLAYIN.\n Aksi takdirde hackShield hatasi alabilirsiniz.");
		while( *(DWORD*)KO_CHAR == 0 || *(DWORD*)(*(DWORD*)(KO_CHAR) + KO_MYID) == 0 || CheckLoading() == true )
	{
		Sleep(1000);
	}
	my_tid = GetCurrentThreadId();
	return 1;
	//hDLLThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)FormThread,NULL,0,&dwDLLThread);

		 Application->Initialize();
		Application->CreateForm(__classid(TForm2), &Form2);
		/*while (loddll==""){
		Sleep(250);
		}  */
		//Form2->Path = loddll;
		Form2->Show();
		Application->Run();
		Application->ProcessMessages();
	}
	ListProcessThreadsResume(GetCurrentProcessId());
	return 0;
}


