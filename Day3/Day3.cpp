// Day3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void swap(int &a, int &b){int c=a;a=b;b=c;}

int _tmain(int argc, _TCHAR* argv[])
{
   if(argc<2)
      return -1;
   FILE *input_txt = NULL;
   _wfopen_s(&input_txt,argv[1],L"r");
   int tris[3][3] = {0};
   int s1,s2,s3;
   int num_tri = 0;
   int tri = 0;
   char buff[1024];
      // Begin processing direction instructions until EOF
   while(!feof(input_txt))
   {
      for(int i=0;i<3;i++)
         if(fscanf(input_txt, "%d %d %d ", &tris[i][0], &tris[i][1], &tris[i][2])==EOF)
            break;
      
      for(int i=0;i<3;i++)
      {
         s1 = tris[0][i];
         s2 = tris[1][i];
         s3 = tris[2][i];
         if(s1+s2>s3 && s1+s3>s2 && s2+s3>s1){
            printf("%3d %3d %3d\n",s1,s2,s3);
            num_tri++;
         }
         tri++;
      }
   }

   fclose(input_txt);
   printf("Possible Triangles %d of %d",num_tri, tri);
   getc(stdin);
   return 0;
}

