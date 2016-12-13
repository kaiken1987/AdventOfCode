// Day6.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

char getMax(char *letCnt)
{
   int m   = 990;
   int idx = 0;
   for (int i = 0; i < 26; i++)
      if (letCnt[i] < m)
      {
         m = letCnt[i];
         idx = i;
      }
   return idx + 'a';
}

int main(int argc, char* argv[])
{
   char buff[1024] =
   {0};
   char letCnt[8][26] =
   {0};
   char out[9] =
   {0};
   FILE *input_txt = NULL;
   if (argc < 2)
      return -1;
   fopen_s(&input_txt, argv[1], "r");
   while (fgets(buff, 1024, input_txt))
   {
      for (int i = 0; i < 8; i++)
         letCnt[i][buff[i] - 'a']++;
   }
   fclose(input_txt);
   for (int i = 0; i < 8; i++)
      out[i] = getMax(letCnt[i]);
   printf(out);
   getc(stdin);

   return 0;
}
