#include <stdlib.h>
#include <stdio.h>

typedef unsigned int  uint32_t;
typedef unsigned char uchar8_t;


int hammingWeight(uint32_t n) {
    uint32_t i = 0;
	uint32_t tem = 1;
	uint32_t r = 0;
	for(i=0;i<32;i++)
	{
		if(tem & n)
			r += 1;
		n = n >> 1; 
		if(n == 0) break;
	}
	return r;
}
//½â·¨2
int hammingWeight1(uint32_t n) 
{
 
	uint32_t r = 0;
	while(0 != n)
	{
		r++;
		n &= (n-1);
	}
	return r;
}



int main()
{
	uint32_t n = 0b00000000000100000000000000001011;
	int r = hammingWeight(n);
	int r1 = hammingWeight1(n);
	printf("hammingWeight n has %d  1bit\n",r);
	printf("hammingWeight n has %d  1bit\n",r1);
}
