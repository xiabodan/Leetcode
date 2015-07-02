#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int i = 0,j=0;
    for(i=0;i<numsSize;i++)
	{
		for(j=i+1;j<numsSize;j++)
			if(nums[i] == nums[j])
				return true;
	}
	return false;
}

int main()
{
	int nums[2] = {1,1};
	bool r = containsDuplicate(nums,2);
	printf("containsDuplicate is : %d \n",r);
}

