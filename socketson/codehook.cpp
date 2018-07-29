//---------------------------------------------------------------------------


#pragma hdrstop

#include "codehook.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
DWORD ft;
DWORD hookjmp;

int WINAPI FilterName(char *name,Exefilter *filter,DWORD m_nFilterInfoCount)
{
	for(int i=0; i<m_nFilterInfoCount; i++)
	{
		//WriteLog("i=%d, name=%s, app=%s", i, name, m_pFilterInfo[i].app);
		if(!lstrcmpiA(name, filter[i].exename))
			return false;
	}
	return true;
}
char *GetFileName(char *path)
{
		 int len = strlen(path);
int pos = len - 1;
char* name = NULL;

while (pos >= 0)
{

	if (path[pos] == '\\')
	{

		pos++;
		name = path + pos;
	 //   printf("fname=%s\n", name);
	 break;

	}

	pos--;

}
return name;
}

__declspec(naked)NtOpenProcessMy(PHANDLE ProcessHandle,
ACCESS_MASK DesiredAccess,
POBJECT_ATTRIBUTES ObjectAttributes,
PCLIENT_ID ClientId  )
{

asm{
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop



}





}
__declspec(naked)NtOpenProcessMyNop()
{
    asm{
		mov edi,edi
		nop
		nop

    }
}

void MakeMemoryWritable(unsigned long ulAddress, unsigned long ulSize)
{
	MEMORY_BASIC_INFORMATION* mbi = new MEMORY_BASIC_INFORMATION;
	VirtualQuery((void*)ulAddress, mbi, ulSize);
	if (mbi->Protect != PAGE_EXECUTE_READWRITE)
	{
		unsigned long* ulProtect = new unsigned long;
		VirtualProtect((void*)ulAddress, ulSize, PAGE_EXECUTE_READWRITE, ulProtect);
		delete ulProtect;
	}
   delete mbi;
}
void MEMwrite(void *adr, void *ptr, int size)
{
DWORD OldProtection;
VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &OldProtection);
memcpy(adr,ptr,size);
VirtualProtect(adr,size,OldProtection, &OldProtection);
}


LogTopla(DWORD *x)
{
//  DWORD e=x[1];

  return 0;
}


Topla(DWORD x)
{
asm{
	nop
	nop
	nop
	nop
	nop

}
   DWORD *e=(DWORD*)x;
}

__declspec(naked)Faketopla(DWORD x)
{
 asm{
   push esp
   call ds:ft;
   add esp,4
   test eax,eax
   jnz Devam
   ret 0
   //13
   nop
   nop
 Devam:
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop

   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   //mov eax , 0xAAAAAAAA
   push  0xAAAAAAAA
   ret
   add eax,6
   jmp eax
 }
}
__declspec(naked)Nopla()
{
	asm{
		nop
		nop
	}
}

DWORD CodeLen(void * adress,int sizecode)
{
String Des;  String  disassembled;
	  unsigned int codelen;
	  unsigned int hookbas= (unsigned int) adress;
	  int index=0;
	  BYTE *oldcode;
	  for(;;)
	  {

	//  hookbas+= index;
	  if(index== sizecode)break;

	  if(index> sizecode)
	  {
		   sizecode=  index;
		   break;
	  }
			oldcode=(BYTE*)   hookbas;
		  //	 DWORD  codelen1 =		   previousopcode( hookbas);
		   disassembled=disassemble((unsigned&)hookbas, Des,codelen);
		   codelen 	=hookbas- (DWORD)&oldcode[0];
		   index+= codelen;

		   if( (oldcode[0]==0xE8)|| (oldcode[0]==0xE9) )

		   {
		   oldcode=(BYTE*)   hookbas;
			  disassembled=disassemble((unsigned&)hookbas, Des,codelen);
		   codelen 	=hookbas- (DWORD)&oldcode[0];
		   index+= codelen;
		   }
	  // hookbas+= codelen;
	  //disassembled= translatestring(disassembled,5);
	  }

  return  sizecode;
}

DWORD CallDuzenle(void *codehook,void * hookProc,int cpysize)
{
String Des;  String  disassembled;
	  unsigned int codelen,orjlen;
	  unsigned int hookbas,hookyazcode;
	  int index,indexc;

  hookyazcode= (unsigned int)codehook; //&code[13+7] ;
  hookbas= (unsigned int)hookProc;
	index=0;
	indexc=0;
	for(;;)
	{

	  if(index== cpysize)break;

	  if(index> cpysize)
	  {
	   cpysize=  indexc;
	  }

	   BYTE *CodeTara=  (BYTE *)hookyazcode;
	   BYTE *CodeTara1= (BYTE *) hookbas ;


	   disassembled=disassemble((unsigned&)hookbas, Des,codelen);
	   codelen 	=hookbas- (DWORD)&CodeTara1[0];
	   memcpy(CodeTara,CodeTara1,codelen);
	   disassembled=disassemble((unsigned&)hookyazcode, Des,codelen);
		codelen 	=hookyazcode- (DWORD)&CodeTara[0];



	  //index+= codelen;


	   if( *CodeTara==0xE8)
	   {
		   DWORD Adress= (DWORD)&CodeTara[0];
			BYTE *Adresshook =(BYTE *)hookProc;

		   int CallDeger=*(int *)&CodeTara[1] ;
			 CallDeger+=5;
			 DWORD CallDegerHook= (DWORD)&Adresshook[index];
			 CallDeger+= CallDegerHook; //Adress;

			 CallDeger-=  Adress;//-5;
			 CallDeger-=5;


			 *(DWORD*)&CodeTara[1]= CallDeger;
	   }

	   else if( *CodeTara==0xE9)
	   {
		   DWORD Adress= (DWORD)&CodeTara[0];
			BYTE *Adresshook =(BYTE *)hookProc;

		   int CallDeger=*(int *)&CodeTara[1] ;
			 CallDeger+=5;
			 DWORD CallDegerHook= (DWORD)&Adresshook[index];
			 CallDeger+= CallDegerHook; //Adress;

			 CallDeger-=  Adress;//-5;
			 CallDeger-=5;


			 *(DWORD*)&CodeTara[1]= CallDeger;
	   }
	   else if( *CodeTara==0xEb)
	   {
			 DWORD Adress= (DWORD)&CodeTara[0];
			BYTE *Adresshook =(BYTE *)hookProc;

		   char CallDegerk=CodeTara[1] ;
			 CallDegerk+=2;
			 DWORD CallDegerHook= (DWORD)&Adresshook[index];
			 DWORD CallDeger= CallDegerHook+CallDegerk; //Adress;

			  CallDeger-=  Adress;//-5;
			 CallDeger-=5;


			 *(DWORD*)&CodeTara[1]= CallDeger;

			CodeTara[0]= 0xe9;
			unsigned int conlen;
			unsigned int oldadress= Adress;
		   String	disassembledc=disassemble((unsigned&)Adress, Des,conlen);
		   conlen=   Adress- oldadress;
			indexc+=conlen;
			hookyazcode=Adress;
			index+= codelen;
			continue;


	   }

   //	  disassembled=disassemble((unsigned&)hookbas, Des,codelen);
	  index+= codelen;
	  indexc+= codelen;
	}

	return  indexc;
}

DWORD HOOKHazirla1(void *Logadres,DWORD &logjmp, void *hookProc,void *faceProc,BYTE *code,int cpysize,int fakesize,
DWORD &jmpadres ,BYTE *fmove ,BYTE retvalue ,BYTE *callkonrol

)
{
//  MakeMemoryWritable((DWORD)hookProc,8);

  logjmp= (DWORD)Logadres;
  jmpadres= (DWORD)faceProc;
   memcpy(code,faceProc,fakesize);
   *(DWORD*)&code[4]=(DWORD)&logjmp;
	code[13]=callkonrol[0];
	code[14]=callkonrol[1];
	 code[13+3]=retvalue;
	 cpysize=  CodeLen(hookProc,cpysize);


 //  memcpy(&code[13+7],hookProc,cpysize);

	cpysize= CallDuzenle( &code[13+7], hookProc, cpysize);



   BYTE RetOp[20];
	  memset( RetOp,0x90,20);
	  RetOp[5]=0x68;
	  *(DWORD*)&RetOp[6]=(DWORD)hookProc+cpysize;
	  RetOp[10]=0xc3;

	   memcpy(&code[13+7+cpysize],RetOp,20);


  jmpadres=  (DWORD)&code[0] ;

  BYTE *toplaBuda=(BYTE*) hookProc;

//  MEMwrite((void*)&toplaBuda[0],(void*)(PBYTE)"\x75",1);
MEMwrite((void*)&toplaBuda[0],fmove,2);
// *(WORD*)&toplaBuda[0]= fmove;
MEMwrite((void*)&toplaBuda[0+2],(void*)(PBYTE)"\xFF",1);
//	toplaBuda[0+2]=0xFF;
MEMwrite((void*)&toplaBuda[1+2],(void*)(PBYTE)"\x25",1);
//	toplaBuda[1+2]=0x25;

//	*(DWORD*)&toplaBuda[2+2]=(DWORD)&jmpadres   ;
BYTE adressekle[4];
*(DWORD*)&adressekle[0]=(DWORD)&jmpadres ;
MEMwrite((void*)&toplaBuda[2+2],(void*)adressekle,4);


	}


