/*
	Name: ʵ��2-3 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 09/04/20 09:26
	Description: �Ķ���������ں��ߴ���дǷȱ���ݣ������亯���Ļ�������ע�͡�
				���г���д����������н�ͼ��   
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;		/* �����Ԫ�ص����� */
typedef int Status; 		/* Status�Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���� */

typedef struct LNode { 		 /* ���Ա��ѭ��������洢 */

    ElemType data;		  	/* ���������� */ 
    struct LNode *next;		/* ����ָ���� */ 
    
} LNode, *LinkList;

LinkList CreateList(int n); 				    /* ������ͷ����ѭ�������� */
Status PrintList(LinkList L); 				    /* ˳����������� */
Status GetElem(LinkList L, int i, ElemType &e); /* ȡ���������i��ֵ����e������ֵ */

LinkList CreateList(int n) {					/* ���������� */ 
    LNode *p, *q, *head;
    int i;
    
    head = new LNode;       
	head->next = head;
    p = head;
    
    for (i = 0; i < n; i++) {
    	q = new LNode;       
		printf("input data %i:",i+1);
    	scanf("%d", &(q->data));            /* ����Ԫ��ֵ */
    	p->next = q;                       	/* �½�����ڱ�ĩβ */
    	p = q;
	}
	
	q->next = head;
	                           
    return head;
}/*CreateList*/

Status PrintList(LinkList L)
{
    LNode *p;
    
    p = L->next;  /*pָ������ĵ�1��Ԫ��*/
    
    while(p != L) {
        printf("p:%d  p->data:%d  p->next:%d\n", p, p->data, p->next);
        p = p->next;
	}
                        
    return OK;
}/*PrintList*/

Status GetElem(LinkList L, int i, ElemType &e)		/* ȡ���������i��ֵ����e������ֵ */
{
    LNode *p;						
	int j = 1;						/* ������j��ֵ��Ϊ1 */ 
	
    p = L->next;					/* ��ʼ����pָ����Ԫ��� */ 
    
    while (p != L && j < i) {        /* ˳�������ɨ�裬ֱ��pΪ�ջ�pָ���i��Ԫ�� */              
        p = p->next;			/* pָ����һ����� */
		++j;					/* ������j��Ӧ��1 */
    }
    
    if (p == L || j > i)			/* iֵ���Ϸ�i>n��i<=0 */
        return ERROR;           /* ȡ��i������������ */     
		  
	e = p->data;
	                       
	return OK;
}/*GetElem*/

int main()
{
    int n, i;
	ElemType e;
	
    LinkList L = NULL;      /* ����ָ�������ָ�� */
    
    printf("please input n:");  /* ���뵥�����Ԫ�ظ��� */
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\n1-Create LinkList:\n");	/* ������ѭ������ */
        L = CreateList(n);      
		  
        printf("\n2-Print LinkList:\n");	/* ��������� */ 
        PrintList(L);
		           
        printf("\n3-GetElem from LinkList:\n");		/* �������ȡֵ */ 
        printf("input i=");
        scanf("%d", &i);
        if (GetElem(L, i, e))     
            printf("No%i is %d", i, e);
        else
            printf("not exists\n");
    }
    
	else
        printf("ERROR\n");
        
    return 0;
}

