/*
	Name: ʵ��1-1(2) 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 07/04/20 21:32
	Description: ���Գ������100�������е��������ú���ʵ�֣� 
*/

#include <stdio.h>

int isprime(int n)	/*�ж�һ�����Ƿ�Ϊ����*/
{
	int m = 2;
	while (m < n) {
		if (n % m == 0)	/*������m����*/
			return 0;
		++m;
	}
	
	return 1;
}

int main()	/*���100������������*/
{
	int i;
	
	printf("\n");
	
	for (i = 2; i < 100; ++i) {	/*�жϷ�Χ��2~~99*/
		if (isprime(i) == 1)
			printf("%4d", i);
	} 
	
	return 0;
}

