// Day4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int getMax(char *letCnt)
{
   int m=0;
   for(int i=0;i<26;i++)
      m = letCnt[i]>m?letCnt[i]:m;
   return m;
}

int _tmain(int argc, _TCHAR* argv[])
{
   char buff[1024]={0};
   char letCnt[26]={0};
   char *idx=NULL;
   char *idStr=NULL;
   char *chksm=NULL;
   int secId=0;
   int sumId=0;
   int line = 0;

   FILE *input_txt = NULL;
   if(argc<2)
      return -1;
   _wfopen_s(&input_txt,argv[1],L"r");
   while(!feof(input_txt))
   {
      idx = fgets(buff,1024,input_txt);
      line++;
      if(idx==NULL)
         continue;
      memset(letCnt,0,sizeof(letCnt));
      while(*idx!=0 && !(*idx>='0'&& *idx<='9'))
      {
         if(*idx!='-')
         {
            int i = *idx-'a';
            if(i>=0 && i<26)
               letCnt[i]++;
            else
               printf("bad idx: line %d idx %d char %c\n",line,i,*idx);
         }
         idx++;   
      }
      idx[-1]=0;
      idStr=idx;
      chksm = strchr(idx,'[');
      *chksm=0;
      chksm++;
      bool validChk = true;
      for(int i=1;i<5;i++)
      {
         int l1 = chksm[i-1];
         int l2 = chksm[i];
         int c1 = letCnt[l1-'a'];
         int c2 = letCnt[l2-'a'];
         if(c1<c2)
         {
            validChk = false;
            break;
         }
         else if(c1==c2)
            if(chksm[i]<chksm[i-1])
            {
               validChk = false;
               break;
            }
      }
      if(!validChk)
         continue;
      for(int i=0;i<5;i++)
      {
         int val = letCnt[chksm[i]-'a'];
         int max = getMax(letCnt);
         if(val!=max)
         {
            validChk = false;
            break;
         }
         letCnt[chksm[i]-'a'] = 0;
      }
      if(!validChk)
         continue;
      secId = atoi(idStr);
      idx=buff;
      while(*idx!=0)
      {
         if(*idx=='-')
            *idx==' ';
         else
            *idx = ((*idx-'a')+secId)%26+'a';
         idx++;
      }
      if(strstr(buff,"north"))
         printf("Sector %3d: %s\n",secId,buff);
   }
   getc(stdin);
	return 0;
}

