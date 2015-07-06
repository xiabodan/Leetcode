#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {

	if(0 == numRows) return 0;
	
    *returnSize = numRows * (numRows + 1) / 2 ; 
	int i = 0, j = 0;
	int** r = (int**)malloc(sizeof(int*) * numRows);
    //int*cn 	= (int*)malloc(sizeof(int) * numRows);
    *columnSizes = (int*)malloc(sizeof(int) * numRows);
	//*columnSizes = cn;
	for(i=0;i<numRows;i++)
	{
		//cn[i] = i + 1;
		columnSizes[0][i] = i + 1 ;
		r[i]  = (int*)malloc(sizeof(int)*(i+1));
	}

	for(i=0;i<numRows;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(0 == j || i == j) r[i][j] = 1;
			else r[i][j] = r[i-1][j-1] + r[i-1][j];
		}
	}
	return r;
}
int** generate1(int numRows, int** columnSizes, int* returnSize) {
    if(!columnSizes) return 0;
    if(!returnSize||numRows==0) return 0;
    int **returnArray=(int **)malloc(numRows*sizeof(int *));
    int *columnSizesArray=malloc(sizeof(int)*numRows);

    *returnSize=0;
    int i=0;
    int j=0;
    for(i=0;i<numRows;i++){
           returnArray[i]=(int *)malloc(sizeof(int)*(i+1));
          //columnSizes[i]=(int *)malloc(sizeof(int)*(1));
          columnSizesArray[i]=i+1;
            for(j=0;j<i+1;j++)
            {
                if(j==0) 
                {
                    returnArray[i][j]=1;
                }else if(j==i)
                {
                    returnArray[i][j]=1;
                }else{
                    returnArray[i][j]=returnArray[i-1][j]+returnArray[i-1][j-1];
                }

            }
            (*returnSize)++;
            //columnSizes[i][0]=(int)(sizeof(returnArray[i]));
        }
    *columnSizes=columnSizesArray;
    return returnArray;
}

int main()
{	
	int num = 5 ;
	int *columnSizes ;//每一行有几个元素
	int returnSize = 0;
	int **r = generate1(num,&columnSizes,&returnSize);
	int i = 0;
	int j = 0;
	printf("toal element size is : %d\n",returnSize);
	for(i=0;i<num;i++)
	{
		printf("%d row have %d element \n",i,columnSizes[i]);
	}
	
	for(i=0;i<num;i++)
	{
		for(j=0;j<i+1;j++)
			printf("r[%d][%d]  = %d\n",i,j,r[i][j]);

		printf("\n");
	}
	
	
}
