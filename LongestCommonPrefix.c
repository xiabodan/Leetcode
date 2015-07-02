#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
char* longestCommonPrefix(char** strs, int strsSize) {
    int i=0; int j=0;int index;int tempindex=0;
    if(strsSize<1)
    return "";
    index=strlen(strs[0]);
    char *a;
    a= malloc(sizeof(char)*(index+1));
    strcpy(a,strs[0]);
    for(i=1;i<strsSize;i++)
    {   tempindex=0;
        for(j=0;j<index;j++)
        { 
            if(a[j]==strs[i][j])
            tempindex++;
            else
            {a[j]='\0';
             break;
            }
        } 
        if (tempindex==0)return ("");
        if(tempindex<index)index=tempindex;

    }
    return a;
}*/

char* longestCommonPrefix(char** strs, int strsSize) 
{
	if(strsSize < 2)
		return "";
	int index = strlen(strs[0]) ;
	int i = 0, j =0, m=0;
	for(i=0;i<strsSize-1;i++) //求取最短字串的长度
	{
		if(strlen(strs[i+1])<strlen(strs[i]))
		{
			index = strlen(strs[i+1]);
			m = i+1;
		}
	}
	printf("the most short size of string is :%d \n ",index);
	char *r = (char*)malloc(sizeof(char) * index);
	strcpy(r,strs[m]);
	printf("r is :%s \n ",r);
	int tem = 0;
	for(i=0;i<strsSize;i++)
	{
		tem = 0;
		for(j=0;j<index;j++)
		{
			if(r[j] == strs[i][j])
			{
				tem++;
			}
			else
			{
				r[j] = '\0';
				break;
			}	
		}
		if(tem == 0)  return ("");
		if(tem < index) index = tem;
	}

	return r;
}


int main(char argc,char** argv)
{
	char a3[][30] = {{"xiabodan_firstpoint!"},{"xiabodan_second!"},{"xiabodan_thirdpoint!"}};
	char *a0 = "xiabodan_first!";
	char *a1 = "xiabodan_secondpoint!";
	char *a2 = "xiabodan_thirdpoint!";
	
	char *p3[3] ;
	int i = 0;
	for(i=0;i<3;i++)
	{
		p3[i] = a3[i];
	}
	//p3[0] = a0;
	//p3[1] = a1;
	//p3[2] = a2;
	//printf("strlen  str is: %d \n",strlen(p3)); 
	char* lpc = longestCommonPrefix(p3,3);
	printf("longestCommonPrefix str is: %s \n",lpc);  //输出应该是499才对
}

