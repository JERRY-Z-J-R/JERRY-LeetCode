/*
	Name: ʵ��1-3(2)
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 07/04/20 22:30
	Description: ���Գ����ڶ�ά�����У���ĳһλ���ϵ�Ԫ���ڸ��������  
							���ڸ�������С�����Ԫ�ؼ�Ϊ�ö�ά�����һ�����㡣
							Ҫ��Ӽ���������һ����ά���飬  
							���������ʱ���Ѱ����ҳ���
*/

#include <stdio.h>
#define M 3
#define N 4

int main()
{
	int a[M][N];
	int i,j,k;
	int x,y;
	
	printf("\n�������ά��������ݣ�\n");
	
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
			
	printf("\n---------------\n"); 
			
	for (i = 0; i < M; i++) {		/*�������*/
		for (j = 0; j < N; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	
	for (i = 0; i < M; i++) {
		k = 0;
		for (j = 1; j < N; j++)	/*�ҳ���i�е����ֵ*/
			if (a[i][j] > a[i][k])
				k = j;
		
		x = 0;
		for (y = 1; y < M; y++)	/*�жϵ�i�е����ֵ�Ƿ�Ϊ���е���Сֵ*/
			if (a[y][k] < a[x][k])
				x = y;
				
		if (i == x)			/*�ڵ�i���ҵ�����*/
			printf("����:%d,  ��:%d,  ��:%d\n", a[i][k], i, k);
	}
	
	return 0;
}

