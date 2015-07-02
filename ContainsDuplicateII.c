
//题目:
//给定一个整数数组与一个整数k，当且仅当存在两个不同的下标i和j满足nums[i] = nums[j]并且| i - j | <= k时返回true，否则返回false。
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    //nums[i] = num[j]  &&  |i-j| <= k
	int i=0,j=0;
	for(i=0;i<numsSize-k;i++)
	{
		for(j=i+1;j<=i+k;j++)
		{
			if(nums[i] == nums[j])
				return true;
		}
	}
	
	return false; 
}

int main()
{
	int nums[2] = {1,1};
	bool r = containsNearbyDuplicate(nums,2,2);
	printf("containsNearbyDuplicate is : %d \n",r);
}
