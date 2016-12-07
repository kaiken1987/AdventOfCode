// Day1b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>

int dirs[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};
int _tmain(int argc, _TCHAR* argv[])
{
   int n=0,e=0;
   int dir = 0;
   int *city[1024];
   for(int i=0;i<1024;i++)
       city[i] = (int*)calloc(1024/sizeof(int),sizeof(int));
   int xo = 512, yo = 512;
   for(int i=1;i<argc;i++)
   {
      char turn = argv[i][0];
      int dist = _ttoi(argv[i]+1);
      if(turn=='R')
         dir++;
      else
         dir--;
      dir = dir&3;
      for(int d=0;d<dist;d++)
      {
         n+=dirs[dir][1];
         e+=dirs[dir][0];
         int x = e+xo;
         int x1=x>>5;
         int x2=1<<(x&31);
         int y = n+yo;
         bool hit = city[n+yo][x1]&x2;
         if(hit)
            goto end;
         else
            city[n+yo][x1]|=x2;
      }
   }
end:
   for(int i=0;i<1024;i++)
       free(city[i]);
   int blocks = abs(n)+abs(e);
   printf("The EBHQ is %d blocks away",blocks);
   getc(stdin);
	return 0;
}

