// Day5.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

char *doorId = "uqwqemis";

int main(int argc, TCHAR* argv[])
{
   md5_state_s md5={0};
   md5_byte_t digest[16];
   int out=0;
   int cnt=0;
   BYTE flag=0;
   int *vals = (int*)digest;
   char hashdata[1024];
   int hashIdx = 0;  
   while(flag!=0xff)
   {
      md5_init(&md5);
      sprintf(hashdata,"%s%d",doorId,hashIdx);
      md5_append(&md5,(md5_byte_t*)hashdata,strlen(hashdata));
      md5_finish(&md5,digest);
      if((vals[0]&0xf0ffff)==0 )
      {
         int shift = (vals[0]&0xf0000)>>16;   
         int val = (vals[0]&0xf0000000)>>28;
         if(shift<8 && (flag&(1<<shift))==0)
         {
            out += val<<(28-shift*4);
            printf("position %d, val: %x out: %08x\n",shift, val, out);
            flag |= (1<<shift);
         }
         else
            printf("position %d, val: %x already filled\n",shift, ((0xf0&digest[3])>>4));
            
      }
      hashIdx++;
   }
      
	return 0;
}

