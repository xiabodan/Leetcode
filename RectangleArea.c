#include <stdlib.h>
#include <stdio.h>

#define min(a,b) ((a)<(b))?(a):(b)
#define max(a,b) ((a)>(b))?(a):(b)


//��Ŀ:Find the total area covered by two rectilinear rectangles in a 2D plane.
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//�����������ε����(�ص��ط�ֻ��һ��)����֪���������εĶԽǶ���
//�ؼ����ڷֱ���ȡ����4������������������м�ֵ
//ע��:���������������ص������
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	//������1�ԽǶ���(A,B)   	(C,D)  
	//������2�ԽǶ���(E,F) 	(G,H)
	//������: A,C,E,G
	//������: B,D,F,H
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
