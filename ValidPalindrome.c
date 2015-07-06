#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define isstr(a)  ((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))

bool isPalindrome(char* s) {
    if(NULL == s)       return true;
    if('\0' == s)       return true;
    if(strlen(s) < 2)   return true;
    char* pa = s;
    char* pb = s;
    char* l  = s;
    while(*pb != '\0') pb++;
    pb--;
    char* n = pb;
    while(pa < pb)
    {
        while(!isstr(*pa) && pa<=n)  pa++;
        while(!isstr(*pb) && pb>=l)	pb--;
        if(((*pa != *pb) && (abs(*pa-*pb) != 'a'-'A')) && (isstr(*pa)) && (isstr(*pb)))  return false;
		else
		{
			pa++;
			pb--;
		}
    }
    return true;
}


int main()
{

	char* s = "A man, a plan, a canal: panama";
	bool r = isPalindrome(s);
	printf("s is isPalindrome? : %d \n",r);

	char *s1 = "";
	bool r1 = isPalindrome(s1);
	printf("s1 is isPalindrome? : %d \n",r1);

	char *s2 = "*.";
	bool r2 = isPalindrome(s2);
	printf("s2 is isPalindrome? : %d \n",r2);

	char *s3 = "Sore was I ere I saw Eros.";
	bool r3 = isPalindrome(s3);
	printf("s3 is isPalindrome? : %d \n",r3);
	
}

