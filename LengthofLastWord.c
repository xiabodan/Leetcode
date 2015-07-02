// 题目: 求取字符串中最后一个单词的长度
// 注意: s="A "返回应该是1
// 		    s=" " 返回应该是0
//              s="a  "返回应该是1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) 
{
	int length = 0;
	int i=0;
	int n = strlen(s);
    for(i=0;i<n;i++)
    {
    	if((('A' <= s[i])&&(s[i] <= 'Z'))||(('a' <= s[i])&&(s[i] <= 'z')))
    	{
    		length++;
    	}
    	if(s[i] == ' ')
    	{
    		if((('A' <= s[i+1])&&(s[i+1] <= 'Z'))||(('a' <= s[i+1])&&(s[i+1] <= 'z')))
    		{
    			length = 0;
				printf("s[%d] = %d\n",i+1,s[i+1]);
    		}
    	}
    }

	return length;
}	

int main()
{
	char *s1 = "H ";
	int r1 = lengthOfLastWord(s1);
	printf("lengthOfLastWord is: %d\n",r1);// 1

	char *s2 = "Hello world xiaobodan";
	int r2 = lengthOfLastWord(s2);
	printf("lengthOfLastWord is: %d\n",r2);// 8

	char *s3 = "  ";
	int r3 = lengthOfLastWord(s3);
	printf("lengthOfLastWord is: %d\n",r3);// 0

	char *s4 = "H  ";
	int r4 = lengthOfLastWord(s4);
	printf("lengthOfLastWord is: %d\n",r4);// 1
}
