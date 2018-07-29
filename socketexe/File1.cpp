#define WIN32_LEAN_AND_MEAN
#pragma warning(disable:4996)
#pragma warning(default:4716)
#include <windows.h>
#include <mmsystem.h>
#include <winbase.h>
#include <stdio.h>
#include <tchar.h>
#include <Winuser.h>
#include <shellapi.h>
#include <Tlhelp32.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <io.h>
#include <iostream>
#include <conio.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <exception>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ostream>
//#include <boost/algorithm/string.hpp>
#include <wbemidl.h>
#include <winsock.h>
#include <sys/stat.h>
#include <dos.h>
#include <psapi.h>
#include <time.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "Ws2_32.lib")


//#include "ClassMorphinee.h"
#include "koclassturet.h"

using namespace std;

extern "C" __declspec(dllimport)  void *  WINAPI KoClassOlustur ();





int main(int argc, char *argv[])
{

	//KnightOnline_CLASS * deneme=(KnightOnline_CLASS*)KoClassOlustur();
	KnightOnline_CLASS * deneme;// =(KnightOnline_CLASSInterface *)a;
	bool floodet=false;
    HMODULE aa=LoadLibraryA("c:\\ClassMorphineeDll.dll");
	DWORD a=(DWORD)	GetProcAddress( aa,"KoClassOlustur");
DWORD x;
_asm{
	call a
	mov deneme,eax
}
 //KoClassOlustur(); 
//KnightOnline_CLASS* deneme  = new KnightOnline_CLASS;//
//KnightOnline_CLASS* deneme2  = new KnightOnline_CLASS;//
//KnightOnline_CLASS* deneme3  = new KnightOnline_CLASS;//
//KnightOnline_CLASS* deneme4 = new KnightOnline_CLASS;//*/
	
//pathos 1.
deneme->mainclassad("heroinnbottest9","11111111a","gamefirst1999","188.132.161.202",0);//"HeroinnVistaTester","188.132.161.202");// yenisi soldaa//"188.132.161.230");//serverlist::Akara ,karakterpozisyonlari::orta ) ;


while(1)
{
	if(GetAsyncKeyState(0x61)&1)
	{
		//	BYTE partikabul[]={0x2F,0x02,0x01};
		//deneme->wsSendPackets(partikabul,sizeof(partikabul),32);
		floodet = true;
	}
	Sleep(1000);
}
  

	getch();
	
}
