/*
	Name: ʵ��3-2 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 14/04/20 13:54
	Description: ��дһ��ʮ����ת��Ϊ�˽��Ƶ�����ת������Ҫ������ջ��ʵ�֣���
				����֤����ȷ�ԡ�������1348�����2504
*/

#include <stdio.h>
#include "intstack.h"

int main()
{
	int n;
	SqStack S;
	SElemType e;
	
	printf("input (10 jinzhi):");
	scanf("%d", &n);
	
	InitStack(S);
	
	while (n) {
		Push(S, n % 8);
		n = n / 8;
	}
	cout << "(8 jinzhi):";
	
	while (!StackEmpty(S)) {
		Pop(S, e);
		cout << e;
	}
} 
