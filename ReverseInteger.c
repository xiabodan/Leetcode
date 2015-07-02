#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
//Linux下编译一定要加-lm
//gcc ReverseInteger.c  -o  ReverseInteger -lm
int reverse1(int x) {
    int f = 0;
    int k = 0;
    int m = 0;
    int tem[20] = {0};
    int r = 0;
    if(x<-32768 && x >32767) 
		return 0;
	
    if(x < 0) 
    {
        x = -x;
        f = 1;
    }
    while(x)
    {
        tem[k++] = x % 10;
        x   = x/10;
       
    }
    while(k--)
    {
        r += tem[m] * pow(10 , k); 
		m++;
    }
	if(f)
    	r = -r;
    
    return r;
}
int reverse(int x) {
    int f = 0;
    int k = 0;
    int m = 0;
    int tem=0;
    int r = 0;
    if(x<-INT_MAX && x >INT_MAX) 
		return 0;
	
    if(x < 0) 
    {
        x = -x;
        f = 1;
    }
    while(x)
    {
    	r = r*10;
		tem = x % 10;
		r = r + tem;
		x = x/10;
    }
	if(f)
    	r = -r;
    
    return r;
}

int main()
{
	int x = 1;
	int r = reverse(x);
	printf("reverse x %d = %d \n",x,r);
	
	x = 13579;
	r = reverse(x);
	printf("reverse x %d = %d \n",x,r);

	x = 0;
	r = reverse(x);
	printf("reverse x %d = %d \n",x,r);

	x = -13579;
	r = reverse(x);
	printf("reverse x %d = %d \n",x,r);

	x = -1;
	r = reverse(x);
	printf("reverse x %d = %d \n",x,r);
	
	x = 1534236469;
	r = reverse(x);
	printf("reverse x %d = %d \n",x,r);
}
