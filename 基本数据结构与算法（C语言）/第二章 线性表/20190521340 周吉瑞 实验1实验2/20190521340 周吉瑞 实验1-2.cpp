/*
	Name: ʵ��1-2 
	Copyright: 
	Author: 20190521340 �ܼ���  
	Date: 07/04/20 22:03
	Description: ���Գ��򣺶�һά�����е�Ԫ�ؽ����������� 
*/

#include <stdio.h>
#define N 10

int main()
{
	int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	int temp;
	
	printf("\nthe original Array is:\n ");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {		/*��������Ԫ��ʹ֮����*/
		temp = a[i];				/*�м�ֵ��*/
		a[i] = a[N-i-1];
		a[N-i-1] = temp;
	}
	
	printf("\nthe changed Array is:\n");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);

	return 0;
}

