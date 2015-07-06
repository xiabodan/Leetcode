#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int r = 0;
	int i = 0;
	int t = nums[0];
	int j = 1;
	for(i=1;i<numsSize;i++,j++)
	{
		if(nums[i] == t)
		{
			while(nums[++i] != t)
				nums[j] = nums[i];
		}
		else
			nums[j] = nums[i];
		
		t = nums[i];
		
	}

	return j;
}

int main()
{
	int n[10] = {1,2,3,3,3,4,5,5,6,7};
	int s[10] = {1,2,3,4,5,6,7,8,9,10};
	int r = removeDuplicates(s,10);
	printf("r = %d\n",r);
	int i = 0 ;
	for(i=0;i<r;i++)
	{
		printf("n[%d] = %d\n",i,n[i]);
	}
}
