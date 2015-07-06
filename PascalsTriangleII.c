#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex;
	if(0 > rowIndex) return 0;
	int* r = (int*)malloc(sizeof(int)*(rowIndex+1));
	
    if(0 == rowIndex)
    {
        r[0] = 1;
        return r;
    }
    
	int i = 0 ,j = 0;
	
	int m=0,n=0;
	for(i=1;i<=rowIndex;i++)
	{
		r[0] = r[i] = 1;
		m = r[0];
		n = r[1];
		for(j=1;j<i;j++)
		{
			r[j] = m + n;
			m = n;
			n = r[+1];
		}
	}
	return r;

}


int main()
{	
	int num = 0 ;
	int returnSize = 0;
	int *r = getRow(num,&returnSize);
	int i = 0;

	printf("toal element size is : %d\n",returnSize);

	for(i=0;i<=num;i++)
	{
		printf("The Kth row data is : %d\n",r[i]);
	}
	
	return 0;
}
