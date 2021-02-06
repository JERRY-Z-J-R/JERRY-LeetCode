/*
	Name: ͼ�����ϵͳ2.0����ͷ�ļ�(������ʵ�֣� 
	Copyright: 
	Author: �ܼ��� 
	Date: 20/04/20 12:55
	Description: ͼ�����ϵͳLinkList.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char no[20];		// ͼ��ISBN  
	char name[50];		// ͼ������ 
	float price;		// ͼ��۸� 

} Book;					// ÿ��ͼ����Ϣ�Ľṹ����ΪBook 

typedef struct LNode {
	
	Book data;				// ���������� 
	struct LNode *next;		// ����ָ���� 
	
} LNode, *LinkList;			// LinkListΪָ��ṹ��LNode��ָ������

Status InitList_L(LinkList &L);							// ��ʼ�������� 
Status CreateList_L(LinkList &L, int n);				// ���������� 
Status ListLength_L(LinkList L, int &l);				// ������� 
Status LocateElem_L(LinkList L, char *b);				// ͼ��Ԫ�صĲ��� 
Status ListInsert_L(LinkList &L, int i, Book e);		// ͼ��Ԫ�صĲ��� 
Status GetElem_L(LinkList &L, char *b);					// ͼ��Ԫ�ص�ȡ�� 
Status PrintList_L(LinkList L);							// ˳�����ͼ��Ԫ������ 
Status ScanfElem_L(Book &e);							// ͼ��Ԫ�ص����� 

Status InitList_L(LinkList &L)	// ��ʼ������������һ���յĵ�����
{	
	L = new LNode;				// �����µ�ͷ��㣬��ͷָ��Lָ���� 
	if (!L) { 
		printf("InitList_L OVERFLOW!\n");
		exit(OVERFLOW);			// ͷ������ʧ�� 
	}
		
	L->next = NULL;				// ͷ����ָ�����ÿ� 
	
	return OK; 
}// InitList_L 

Status CreateList_L(LinkList &L, int n)		//���������� 
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
		
		if (!ListInsert_L(L, i + 1, e)) {
			printf("CreateList_L ERROR\n");
			return ERROR; 
		}
	}
	
	return OK;	
}// CreateList_L

Status ListLength_L(LinkList L, int &l)		// �������	
{
	LNode *p;
	
	p = L->next;
	
	l = 0;
	while (p) {
		++l;
		p = p->next;
	}  
	
	return OK;
}// ListLength_L

Status LocateElem_L(LinkList L, char *b)		// ͼ��Ԫ�صĲ���
{
	LNode *p;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			printf("���ҳɹ���\n");
			printf("%-10s  ", p->data.no);
			printf("%-10s  ", p->data.name);
			printf("%-10f\n", p->data.price);
			return OK;
		}
	}
	
	printf("û�������鼮��\n");
	return ERROR; 
}// LocateElem_L

Status ListInsert_L(LinkList &L, int i, Book e)		// ͼ��Ԫ�صĲ���
{
	LNode *p;
	LNode *s;
	int j = 0;
	
	p = L;
	
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	
	if (!p || (j > i - 1)) {
		if (i == 1) {
			s = new LNode;
			s->data = e;
			s->next = p->next;
			p->next = s;
		}
		
		printf("ListInsert_L ERROR\n");
		return ERROR;
	}
	
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	printf("����ɹ���\n");
	return OK;
}// ListInsert_L

Status GetElem_L(LinkList &L, char *b)	// ͼ��Ԫ�ص�ȡ��
{
	LNode *p;
	LNode *q;
	int i = 1;
	int j = 0;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			q = L;
			
			while ((q->next) && (j < i - 1)) {
				q = q->next;
				++j;
			}
			
			if (!(q->next) || (j > i - 1)) {
				printf("GetElem_L ERROR\n");
				return ERROR;
			}
			
			q->next = p->next;
			
			delete p;
			
			printf("�ɹ�ȡ����\n");
			return OK;
		}
		++i;
	}
	
	printf("û����Ҫȡ�����鼮��\n");
	return ERROR; 
}//  GetElem_Sq	 

Status PrintList_L(LinkList L)	// ˳�����ͼ��Ԫ������
{
	printf("ͼ�����Ϊ��\n");
	
	LNode *p;
	
	p = L->next;
	
	while (p) {
		printf("%-10s  ", p->data.no);
		printf("%-10s  ", p->data.name);
		printf("%-10f\n", p->data.price);
		
		p = p->next;	
	}
	
	return OK;	
}// PrintList_L 

Status ScanfElem_L(Book &e)		// ͼ��Ԫ�ص�����
{
	printf("���������ISBN��");
	scanf("%s", e.no);
		
	printf("���������������");
	scanf("%s", e.name);
		
	printf("��������ļ۸�");
	scanf("%f", &e.price);
	
	return OK;	
}// ScanfElem_L 
