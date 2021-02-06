/*
	Name: ͼ�����ϵͳ����ͷ�ļ�(˳���ʵ�֣� 
	Copyright: 
	Author: �ܼ��� 
	Date: 19/04/20 16:29
	Description: ͼ�����ϵͳSqList.h 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char no[20];		// ͼ��ISBN  
	char name[50];		// ͼ������ 
	float price;		// ͼ��۸� 

} Book;					// ÿ��ͼ����Ϣ�Ľṹ����ΪBook 

typedef struct {
	
	Book *elem;			// �洢�ռ����ַ 
	int length;			// ͼ����е�ǰͼ�����
	 
} SqList;				// ͼ����˳��洢�ṹ����ΪSqList 

Status InitList_Sq(SqList &L);							// ��ʼ��˳��� 
Status CreateList_Sq(SqList &L, int n);					// ����˳��� 
Status ListLength_Sq(SqList L, int &l);					// ��˳���� 
Status LocateElem_Sq(SqList L, char *b);				// ͼ��Ԫ�صĲ��� 
Status ListInsert_Sq(SqList &L, int i, Book e);			// ͼ��Ԫ�صĲ��� 
Status GetElem_Sq(SqList &L, char *b);					// ͼ��Ԫ�ص�ȡ�� 
Status PrintList_Sq(SqList L);							// ˳�����ͼ��Ԫ������ 
Status ScanfElem_Sq(Book &e);							// ͼ��Ԫ�ص����� 

Status InitList_Sq(SqList &L)		// ��ʼ��˳�������һ���յ�˳��� 
{	
	L.elem = new Book[MAXSIZE];		// Ϊ˳������һ����СΪMAXSIZE�Ľṹ������ռ� 
	if (!L.elem)					// �������ʧ�� 
		exit(OVERFLOW);
	
	L.length = 0;					// �ձ���Ϊ0 
	
	return OK;
}// InitList_Sq

Status CreateList_Sq(SqList &L, int n)		// ����˳��� 
{
	Book e;
	int i;
	
	for (i = 0; i < n; ++i) {
		printf("�������%d�����ISBN��", i + 1);
		scanf("%s", e.no);
		
		printf("�������%d�����������", i + 1);
		scanf("%s", e.name);
		
		printf("�������%d����ļ۸�", i + 1);
		scanf("%f", &e.price);
		
		if (!ListInsert_Sq(L, i + 1, e)) {  	//����i+1�������Ϣ����ͼ����i+1��Ԫ�ش� 
			printf("CreateList_Sq ERROR!\n");
			return ERROR;
		}
	} 
	
	return OK;
}// CreateList_Sq

Status ListLength_Sq(SqList L, int &l)		// ��˳����	
{
	l = L.length;
	
	return OK;
}// ListLength_Sq 

Status LocateElem_Sq(SqList L, char *b)		// ͼ��Ԫ�صĲ���
{
	int i;
	
	for (i = 0; i < L.length; ++i) {
		if (!strcmp(L.elem[i].name, b)) {
			printf("���ҳɹ���\n");
			printf("%-10s  ", L.elem[i].no);
			printf("%-10s  ", L.elem[i].name);
			printf("%-10f\n", L.elem[i].price);
			return OK;
		}
	}
	
	printf("û�������鼮��\n");
	return ERROR; 
}// LocateElem_Sq

Status ListInsert_Sq(SqList &L, int i, Book e)		// ͼ��Ԫ�صĲ���
{
	if ((i < 1) || (i > MAXSIZE)) {
		printf("1_ListInsert_Sq ERROR!\n");
		return ERROR;
	}
	
	if (L.length == MAXSIZE) {
		printf("2_ListInsert_Sq ERROR!\n");
		return ERROR;
	}
	
	for (int j = L.length - 1; j >= i - 1; --j)
		L.elem[j+1] = L.elem[j];
		
	L.elem[i-1] = e;
	++L.length;
	
	printf("����ɹ���\n"); 
	return OK;
}// ListInsert_Sq

Status GetElem_Sq(SqList &L, char *b)	// ͼ��Ԫ�ص�ȡ��
{
	int i, j;
	
	for (i = 0; i < L.length; ++i) {
		if (!strcmp(L.elem[i].name, b)) {
			for (j = i; j < L.length - 1; ++j) {
				L.elem[j] = L.elem[j+1];
			}
			
			--L.length;
			printf("�ɹ�ȡ����\n");
			return OK;
		}
	}

	printf("û����Ҫȡ�����鼮��\n");
	return ERROR; 
}//  GetElem_Sq	
	
Status PrintList_Sq(SqList L)	// ˳�����ͼ��Ԫ������
{
	printf("ͼ�����Ϊ��\n"); 
	
	int i;
	for (i = 1; i <= L.length; ++i) {
		printf("%-10s  ", L.elem[i-1].no);
		printf("%-10s  ", L.elem[i-1].name);
		printf("%-10f\n", L.elem[i-1].price);
	}	
	
	return OK;
}// PrintList_Sq 

Status ScanfElem_Sq(Book &e)	// ͼ��Ԫ�ص�����
{
	printf("���������ISBN��");
	scanf("%s", e.no);
		
	printf("���������������");
	scanf("%s", e.name);
		
	printf("��������ļ۸�");
	scanf("%f", &e.price);
	
	return OK;
}// ScanfElem_Sq 
