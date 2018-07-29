//---------------------------------------------------------------------------


#pragma hdrstop

#include "clearcache.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



//#include <shlguid.h>
//#include <urlhist.h>

void __fastcall ClearCache()
{
   DWORD dwSize = sizeof(INTERNET_CACHE_ENTRY_INFO); 
   INTERNET_CACHE_ENTRY_INFO *info = (INTERNET_CACHE_ENTRY_INFO*) LocalAlloc(LMEM_FIXED, dwSize); 
   if( info )
   {
      HANDLE hFind = FindFirstUrlCacheEntry(NULL, info, &dwSize); 
      if( hFind == NULL )
      {
         if( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
         { 
            info = (INTERNET_CACHE_ENTRY_INFO*) LocalReAlloc(info, dwSize, LMEM_FIXED); 
            if( info )
               hFind = FindFirstUrlCacheEntry(NULL, info, &dwSize); 
         }
      }

      if( hFind != NULL ) 
      { 
         do
         {
            if( info->CacheEntryType & NORMAL_CACHE_ENTRY )
            {
               DeleteFile(info->lpszLocalFileName);
               DeleteUrlCacheEntry(info->lpszSourceUrlName);
            }

            if( FindNextUrlCacheEntry(hFind, info, &dwSize) )
               continue;

            if( GetLastError() == ERROR_INSUFFICIENT_BUFFER )
            { 
               info = (INTERNET_CACHE_ENTRY_INFO*) LocalReAlloc(info, dwSize, LMEM_FIXED); 
               if( info )
               {
                  if( FindNextUrlCacheEntry(hFind, info, &dwSize) )
                        continue;
               }
            }

            break;

         }
         while( true );

         FindCloseUrlCache(hFind);
      } 

      if( info )
         LocalFree(info); 
   }
}


