// Day7.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

bool checkABBA(char *buff)
{
	char *idx = buff;
	strchr(idx,'\n')[0] = 0;
	//look for invalid
	while((idx=strchr(idx,'['))!=NULL)
	{
		while(idx[3]!=']')
		{
			if(idx[0]==idx[3]&&idx[1]==idx[2]&&idx[0]!=idx[2])
				return false;
			idx++;
		}
	}
	idx = buff;
	while(idx[3]!=0)
	{
		char *prev = idx;
		if(idx[3]=='[')
			idx = strchr(idx,']')+1;
		if(*idx==0)
			break;
		if(idx[0]==idx[3]&&idx[1]==idx[2]&&idx[0]!=idx[2])
			return true;
		idx++;
	}
	return false;
}

bool findSuper(char *buff,char *bab)
{
	char super[512];
	char *idx = buff;

	while((idx=strchr(idx,'['))!=NULL)
	{
		char *end = strchr(idx,']');
		strncpy(super,idx+1,end-idx-1);
		super[end-idx-1]=0;
		if(strstr(super,bab)!=NULL)
			return true;
		idx=end;
	}
	return false;
}

bool checkABA(char *buff)
{
	char *idx = buff;
	strchr(idx,'\n')[0] = 0;
	char bab[4]={0};
	//look for valid
	while(idx[2]!=0)
	{
		//skip supers
		if(idx[2]=='[')
			idx = strchr(idx,']')+1;
		if(*idx==0)
			break;
		//found valid
		if(idx[0]==idx[2]&&idx[1]!=idx[2])
		{
			//turn aba to bab			
			bab[0]=bab[2] = idx[1];
			bab[1] = idx[0];
			//check if bab exists in the super
			if(findSuper(buff,bab))
			{
				printf("%s\n",bab);
				return true;
			}
			break;
		}
		idx++;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int ipCnt=0;
	int line = 0;
   char buff[1024]={0};
   FILE *input_txt = NULL;
   if(argc<2)
      return -1;
   fopen_s(&input_txt,argv[1],"r");
   while(fgets(buff,1024,input_txt))
	{
		line++;
		if(checkABA(buff))
			ipCnt++;
	}
	printf("cnt %d", ipCnt);
	getc(stdin);
	return 0;
}

