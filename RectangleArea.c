#include <stdlib.h>
#include <stdio.h>

#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)


//题目:Find the total area covered by two rectilinear rectangles in a 2D plane.
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//求两个正方形的面积(重叠地方只算一次)，已知两个正方形的对角顶点
//关键在于分别求取所有4个横纵轴坐标的两个中间值
//注意:当两个正方形无重叠的情况
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	//正方形1对角顶点(A,B)   	(C,D)  
	//正方形2对角顶点(E,F) 	(G,H)
	//横坐标: A,C,E,G
	//纵坐标: B,D,F,H
	if((abs(A-G)-(C-A)-(G-E)) > 0) 
        return (G-E)*(H-F) + (D-B)*(C-A);
    if((abs(E-C)-(C-A)-(G-E)) > 0) 
        return (G-E)*(H-F) + (D-B)*(C-A);
    if((abs(H-B)-(D-B)-(H-F)) > 0) 
	    return (G-E)*(H-F) + (D-B)*(C-A);
	if((abs(D-F)-(D-B)-(H-F)) > 0) 
	    return (G-E)*(H-F) + (D-B)*(C-A);
	
	if(A == B == C == D) return (G-E)*(H-F);
	if(E == F == G == H) return (D-B)*(C-A);
	int m=0,n=0;

	n = abs((min(G,C))-(max(A,E)));
	m = abs((min(D,H))-(max(B,F)));

	return (G-E)*(H-F) + (D-B)*(C-A) - m*n;
}


int main()
{
	int A = -2,B = -2,C = 2,D = 2,E = -2,F = -2,G = 2,H = 2;
	int area = computeArea( A, B, C, D, E, F, G, H);
	printf("area is :%d\n",area);
}
