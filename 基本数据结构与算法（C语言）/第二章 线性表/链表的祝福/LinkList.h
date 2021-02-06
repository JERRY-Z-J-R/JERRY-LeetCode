/*
	Name: ѧ������¼ϵͳ����ͷ�ļ�(������ 
	Copyright: ...
	Author: �ܼ��� 
	Date: ...
	Description: ѧ������¼ϵͳ LinkList.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char id[15];			// ѧ��ѧ��
	char name[15];			// ѧ������ 

} Student;					// ÿ��ѧ����Ϣ�Ľṹ����ΪStudent 

typedef struct Lidde {
	
	Student data;			// ���������� 
	struct Lidde *next;		// ����ָ���� 
	
} Lidde, *LinkList;			// LinkListΪָ��ṹ��Lidde��ָ������

Status InitList_L(LinkList &L);							// ��ʼ�������� 
Status CreateList_L(LinkList &L, int n);				// ���������� 
Status ListLength_L(LinkList L, int &l);				// ������� 
Status LocateElem_L(LinkList L, char *b);				// ѧ��Ԫ�صĲ��� 
Status ListInsert_L(LinkList &L, int i, Student e);		// ѧ��Ԫ�صĲ��� 
Status GetElem_L(LinkList &L, char *b);					// ѧ��Ԫ�ص��Ƴ� 
Status PrintList_L(LinkList L);							// ˳�����ѧ������¼���� 
Status ScanfElem_L(Student &e);							// ѧ��Ԫ�ص����� 
Status ForeverStudent_ZhouJiRui(LinkList &L);			// ��ʼ�����Լ�

Status ForeverStudent_ZhouJiRui(LinkList &L)
{
	Student zjr;
	
	strcpy(zjr.id, "20190521340");
	strcpy(zjr.name, "�ܼ���");
	
	ListInsert_L(L, 1, zjr);
	
	return OK;
}// Status ForeverStudent_ZhouJiRui
 
Status InitList_L(LinkList &L)	// ��ʼ������������һ���յĵ�����
{	
	L = new Lidde;				// �����µ�ͷ��㣬��ͷָ��Lָ���� 
	
	if (!L) { 
		printf("\nInitList_L OVERFLOW!\n");
		exit(OVERFLOW);			// ͷ������ʧ�� 
	}// if
		
	L->next = NULL;				// ͷ����ָ�����ÿ� 
	
	return OK; 
}// InitList_L 

Status CreateList_L(LinkList &L, int n)		// ���������� 
{
	Student e;
	int i;
	
	for (i = 0; i < n; ++i) {
		printf("�������%d��ѧ����ѧ�ţ�", i + 1);
		scanf("%s", e.id);
		
		printf("�������%d��ѧ����������", i + 1);
		scanf("%s", e.name);
		
		if (!ListInsert_L(L, i + 1, e)) {
			printf("\nCreateList_L ERROR!\n");
			return ERROR; 
		}// if
	}// for
	
	return OK;	
}// CreateList_L

Status ListLength_L(LinkList L, int &l)		// �������	
{
	Lidde *p;
	
	p = L->next;
	
	l = 0;
	
	while (p) {
		++l;
		p = p->next;
	}// while
	
	return OK;
}// ListLength_L

Status LocateElem_L(LinkList L, char *b)		// ѧ��Ԫ�صĲ���
{
	Lidde *p;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			printf("\n���ҳɹ���\n");
			printf("%-10s  ", p->data.id);
			printf("%-10s  ", p->data.name);
			
			return OK;
		}// if
	}// for
	
	printf("\nû������ѧ����");
	return ERROR; 
}// LocateElem_L

Status ListInsert_L(LinkList &L, int i, Student e)		// ѧ��Ԫ�صĲ���
{
	Lidde *p;
	Lidde *s;
	int j = 0;
	
	p = L;
	
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}// while
	
	if (!p || (j > i - 1)) {
		if (i == 1) {
			s = new Lidde;
			s->data = e;
			s->next = p->next;
			p->next = s;
		}// if
		
		printf("\nListInsert_L ERROR!\n");
		return ERROR;
	}// if
	
	s = new Lidde;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	printf("\n��ӳɹ���\n");
	return OK;
}// ListInsert_L

Status GetElem_L(LinkList &L, char *b)	// ѧ��Ԫ�ص��Ƴ� 
{
	Lidde *p;
	Lidde *q;
	int i = 1;
	int j = 0;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			q = L;
			
			while ((q->next) && (j < i - 1)) {
				q = q->next;
				++j;
			}// while
			
			if (!(q->next) || (j > i - 1)) {
				printf("\nGetElem_L ERROR!\n");
				return ERROR;
			}// if
			
			q->next = p->next;
			
			delete p;
			
			printf("\n�ɹ��Ƴ���\n");
			return OK;
		}// if
		++i;
	}// for
	
	printf("\nû����Ҫ�Ƴ���ѧ����\n");
	return ERROR; 
}//  GetElem_Sq	 

Status PrintList_L(LinkList L)	// ˳�����ѧ������¼����
{
	printf("��ǰ����¼��\n\n");
	
	Lidde *p;
	
	p = L->next;
	
	while (p) {
		printf("%-10s  ", p->data.id);
		printf("%-10s  \n", p->data.name);
		
		p = p->next;	
	}// while
	
	return OK;	
}// PrintList_L 

Status ScanfElem_L(Student &e)		// ѧ��Ԫ�ص�����
{
	printf("������ѧ����ѧ�ţ�");
	scanf("%s", e.id);
		
	printf("������ѧ����������");
	scanf("%s", e.name);
	
	return OK;	
}// ScanfElem_L 
