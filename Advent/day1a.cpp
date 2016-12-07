// Advent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

int dirs[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};
int _tmain(int argc, _TCHAR* argv[])
{
   int n=0,e=0;
   int dir = 0;
   for(int i=1;i<argc;i++)
   {
      char turn = argv[i][0];
      int dist = _ttoi(argv[i]+1);
      if(turn=='R')
         dir++;
      else
         dir--;
      dir = dir&3;
      n+=dirs[dir][1]*dist;
      e+=dirs[dir][0]*dist;
   }
   int blocks = abs(n)+abs(e);
   printf("The EBHQ is %d blocks away",blocks);
   getc(stdin);
	return 0;
}

