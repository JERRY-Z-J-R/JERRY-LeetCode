/*
	Name: ʵ��5  ����.h 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 27/05/20 13:20
	Description: ͷ�ļ������� �����ӣ� 
*/
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char VerTexType;
typedef int Status;

typedef struct QNode {
	VerTexType data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front;		//��ͷָ�� 
	QueuePtr rear;		//��βָ�� 
} LinkQueue;

Status InitQueue(LinkQueue &Q)	//����һ���ն���Q 
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue &Q, VerTexType e)	//����Ԫ��eΪQ���¶�βԪ�� 
{
	QNode *p;
	p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK; 	
}

Status DeQueue(LinkQueue &Q, VerTexType &e)	//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	QNode *p;
	if (Q.front == Q.rear)
		return ERROR; 
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) 
		Q.rear = Q.front;
	delete p;
	return OK;
}

Status QueueEmpty(LinkQueue Q)	//�ж϶���Ϊ��
{
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR; 
} 


 
