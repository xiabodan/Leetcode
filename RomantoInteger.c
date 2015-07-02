#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int N=strlen(s);
    int map[26]={0};
    map['I'-'A']=1;
    map['V'-'A']=5;
    map['X'-'A']=10;
    map['L'-'A']=50;
    map['C'-'A']=100;
    map['D'-'A']=500;
    map['M'-'A']=1000;
    int sum=0;
    int n,nn;
	int i=0;
    for(i=0;i<N;i++)
    {
    	//检测是否有IV IX XL XC CD CM
        if(i!=N-1)
        {
            n = map[s[i]-'A'];
            nn= map[s[i+1]-'A'];
            if(n<nn)
            {
                sum += nn - n;
                i++;
            }
            else
                sum += n;
        }
        else
            sum +=map[s[i]-'A'];
    }
    
    return sum;
}

int main(char argc,char** argv)
{
	char *s = "CDXCIX"; //499
	int num = romanToInt(s);

	printf("romanToInt num is: %d \n",num); //输出应该是499才对
}
