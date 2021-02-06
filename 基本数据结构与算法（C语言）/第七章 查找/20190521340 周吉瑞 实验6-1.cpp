/*
	Name:20190521340 �ܼ��� ʵ��6-1
	Copyright:
	Date:�ܼ���
	Description:���Ա�Ĳ���(���ü����ڵ�˳�����) 
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;
typedef int KeyType;

int count_1 = 0; 

typedef struct {
	KeyType key;
	char name;
} ElemType;

typedef struct {
	ElemType *R;
	int length;
} SSTable;

Status InitList_SSTable(SSTable &ST)
{
	ST.R = new ElemType[MAXSIZE + 1];

	if (!ST.R) {
		printf("��ʼ������.\n");
		exit(OVERFLOW);
	}

	ST.length = 0;
	
	return OK;
}

Status Create_SSTable(SSTable &ST)
{
	int i = 1;
	int j;

	printf("����˳���, ��'0'Ϊ������־.\n");

	do {
		scanf("%d", &j);

		if (j == 0) {
			break;
		}

		ST.R[i++].key = j;
		ST.length++;
	} while (1);

	printf("\n");
	
	return OK;
}

void Output_table(SSTable ST)
{
	int i;
	
	printf("˳���Ϊ:\n");
	for (i = 1; i <= ST.length; i++) {
		printf("%4d\t", ST.R[i].key);
	}

	printf("\n\n");

	return ;
}

int Search_Seq(SSTable ST, KeyType key, int &count_1)
{
	int i;
	count_1 = 1;
	ST.R[0].key = key;

	for (i = ST.length; ST.R[i].key != key; --i) {
		count_1++;
	} 

	return i;
}

void Shou_End(int resule, int testkey)
{
	if (resule == 0) {
		printf("δ�ҵ�%d\n", testkey);
	}

	else {
		printf("�ҵ�%d, λ��Ϊ%d\n", testkey, resule);
	}
	
	printf("�Ƚϴ���Ϊ:%d\n\n", count_1);
	
	return ;
}

int main(void)
{
	SSTable ST;

	InitList_SSTable(ST);
	Create_SSTable(ST);
	Output_table(ST);

	int testkey;
	int resule;

	do {
		printf("���������ؼ���, ����'0'�˳�����.\n");
		scanf("%d", &testkey);
		
		printf("\n");

		resule = Search_Seq(ST, testkey, count_1);
		Shou_End(resule, testkey);
	} while (testkey != 0);

	return 0;
}
