/*
	Name: intstack.h(2)
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 14/04/20 13:29
	Description: ˳��ջ��ʵ��.h
*/

#include <iostream>
#include <fstream>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE  100	//˳��ջ�洢�ռ�ĳ�ʼ������

typedef int Status;
typedef char SElemType;

typedef struct {

	SElemType *base;	//ջ��ָ��
	SElemType *top;		//ջ��ָ��
	int stacksize;		//ջ���õ��������

} SqStack;

//�㷨3.1��˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) 
{
	//����һ����ջS
	S.base = new SElemType[MAXSIZE];//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	
	if (!S.base)
		exit(OVERFLOW); 		//�洢����ʧ��
	
	S.top = S.base;				//top��ʼΪbase����ջ
	S.stacksize = MAXSIZE; 		//stacksize��Ϊջ���������MAXSIZE
	
	return OK;
}

//�㷨3.2��˳��ջ����ջ
Status Push(SqStack &S, SElemType e)
{
	// ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base == MAXSIZE) 
		return ERROR;
		
	*(S.top) = e;
	S.top++;
	
	return OK;
}

//�㷨3.3��˳��ջ�ĳ�ջ
Status Pop(SqStack &S, SElemType &e) 
{
	//ɾ��S��ջ��Ԫ�أ���e������ֵ	
	if (S.top == S.base)
		return ERROR;
		
	S.top--;
	e = *(S.top);
	
	return OK;
}

//�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
SElemType GetTop(SqStack S) 
{
	//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S.top != S.base) 			//ջ�ǿ�
		return *(S.top - 1);		//����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}

//�㷨3.5���ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)
{
	//��ջΪ�գ�����1 �����򷵻�0
	if (S.top == S.base)
		return 1;
 	else
		return 0; 			    
}

SElemType Get(SqStack S, int n) 
{
	//����S��Ԫ�أ����޸�topָ��
	if (S.top != S.base) 			//ջ�ǿ�
		return *(S.top - n);		//����ջԪ�ص�ֵ��topָ�벻��
}

void prt_base_top_length(SqStack s)
{
	//���ջ�Ĳ���
	printf("s.base=%d  s.top=%d   s.length=%d\n", s.base, s.top, s.top-s.base);
}

