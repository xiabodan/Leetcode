#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
int myAtoi(char* str) {
   //"NULL"  "000234"  "+23" "-34" "+-34"  "    010"
    if(NULL == str )        
    	return 0;    
	int sum  = 0.0;
	int f  = 0;
    int DIV = INT_MAX/10;
	while('\0' != *str)    
	{        
		if(*str == '+')
		{
			str++;
			if(*str < '0' || *str > '9') 
				return 0;
			else
				f = 0;
		}
		if(*str == '-')
		{
			str++;
			if(*str < '0' || *str > '9') 
				return 0;
			else
				f = 1;
		}

		if(*str >= '0' && *str<= '9' )
		{
			if(sum > DIV && f == 0)
				return INT_MAX;
			if(sum > DIV && f == 1)
				return -INT_MAX-1;

			sum = sum * 10.0;

			if(INT_MAX - *str + '0' < sum  && f == 0) 
				return INT_MAX;
			if((INT_MAX - (*str - '0') < sum ) && (f == 1)) 
				return -INT_MAX-1;

			sum = sum + *str - '0';

			str++;
			if(*str == '\0') break;
			else if(*str < '0' || *str > '9')
			    break;
		}
		else
		{
		    if(*str >= 'a' && *str <= 'z' )
				break;
    		str++;
			
		}
	}
   
	if(f) 
		sum = -sum; 
	
	return sum;
}
int main()
{
	char *str = "0034";
	int r = myAtoi(str);
	printf("myAtoi str0 is : %d\n",r);

	char *str1 = "00";
	int r1 = myAtoi(str1);
	printf("myAtoi str1 is : %d\n",r1);

	char *str2 = "+23";
	int r2 = myAtoi(str2);
	printf("myAtoi str2 is : %d\n",r2);

	char *str3 = "-2345";
	int r3 = myAtoi(str3);
	printf("myAtoi str3 is : %d\n",r3);

	char *str4 = "+-23";
	int r4 = myAtoi(str4);
	printf("myAtoi str4 is : %d\n",r4);//  expected 0

	char *str5 = "    010";
	int r5 = myAtoi(str5);
	printf("myAtoi str5 is : %d\n",r5);

	char *str6 = "    +0104";
	int r6 = myAtoi(str6);
	printf("myAtoi str6 is : %d\n",r6);

	char *str7 = "    -0187";
	int r7 = myAtoi(str7);
	printf("myAtoi str7 is : %d\n",r7);//  expected -187

	char *str8 = "    -018a567";
	int r8 = myAtoi(str8);
	printf("myAtoi str8 is : %d\n",r8); //  expected -18

	char *str9 = "2147483648";
	int r9 = myAtoi(str9);
	printf("myAtoi str9 is : %d\n",r9); //  expected 2147483647  由于越界，只取最大

	char *str10 = "-2147483649";
	int r10 = myAtoi(str10);
	printf("myAtoi str10 is : %d\n",r10); //  expected -2147483648 

	char *str11 = "- 204";
	int r11 = myAtoi(str11);
	printf("myAtoi str11 is : %d\n",r11); //  expected 0  

	char *str12 = "b3424242";
	int r12 = myAtoi(str12);
	printf("myAtoi str12 is : %d\n",r12); //  expected 0  

	while(0);
}