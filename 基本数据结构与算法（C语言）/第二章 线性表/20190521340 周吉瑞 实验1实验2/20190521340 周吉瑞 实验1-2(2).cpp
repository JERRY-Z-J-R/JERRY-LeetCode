/*
	Name: ʵ��1-2(2)
	Copyright: 
	Author: 20190521340 �ܼ���  
	Date: 07/04/20 22:12
	Description: ���Գ��򣺶�һά�����е�Ԫ�ؽ����������� 
*/

#include <stdio.h>
#define N 10

int main()
{
	int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[N];	/*����һ��������a����Ԫ�ؽ���������*/
	int i;
	
	printf("\nthe original Array is:\n ");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
		
	for (i = 0; i < N; i++)		/*��������Ԫ��ʹ֮����*/ 
		b[i] = a[N-i-1];
		
	for (i = 0; i < N; i++)		/*��b�����Ԫ�ظ���a����*/
		a[i] = b[i];
	
	printf("\nthe changed Array is:\n");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);

	return 0;
}

