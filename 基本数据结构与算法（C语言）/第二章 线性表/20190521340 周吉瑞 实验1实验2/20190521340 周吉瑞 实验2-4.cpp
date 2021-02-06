/*
	Name: ʵ��2-4
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 09/04/20 19:30
	Description: �Ķ���������ں��ߴ���дǷȱ���ݣ������亯���Ļ�������ע�͡�
				���г���д����������н�ͼ��
				Ϊ��3�ⲹ����빦�ܺ�����ɾ�����ܺ�����
				�����������в������,��֤��������������ȷ��
*/

#include <stdio.h>
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

LinkList CreateList(int n); 				   		 /* ������ͷ����ѭ�������� */
Status PrintList(LinkList L); 				    	 /* ˳����������� */
Status GetElem(LinkList L, int i, ElemType &e); 	 /* ȡ���������i��ֵ����e������ֵ */
Status ListDelete(LinkList &L, int i, ElemType &e);	 /* �ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��,����e���ر�ɾԪ�� */
Status ListInsert(LinkList &L, int i, ElemType e);	 /* �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½�� */
LNode * LocateElem(LinkList L, ElemType e);			 /* ������ֵe���� */

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
}/* CreateList */

Status PrintList(LinkList L)
{
    LNode *p;
    
    p = L;				/* pָ�������ͷ��� */  
    p = p->next;		/* pָ������ĵ�1��Ԫ�� */
    
    while(p != L) {		/* whileѭ��ֱ��pָ��ͷ���ʱ�˳�ѭ�� */ 
        printf("p:%d  p->data:%d  p->next:%d\n", p, p->data, p->next);
        p = p->next;	/* pָ����һ����� */
	}
                        
    return OK;
}/* PrintList */

Status GetElem(LinkList L, int i, ElemType &e)		/* ȡ���������i��ֵ����e������ֵ */
{
    LNode *p;						
	int j = 1;						/* ������j��ֵ��Ϊ1 */ 
	
    p = L->next;					/* ��ʼ����pָ����Ԫ��� */ 
    
    while (p != L && j < i) {        /* ˳�������ɨ�裬ֱ��pΪ�ջ�pָ���i��Ԫ�� */              
        p = p->next;			/* pָ����һ����� */
		++j;					/* ������j��Ӧ��1 */
    }
    
    if (p == L || j > i) {			/* iֵ���Ϸ�i>n��i<=0 */
    	printf("ERROR\n");
        return ERROR;           /* ȡ��i������������ */    
	}
		  
	e = p->data;
	                       
	return OK;
}/* GetElem */

Status ListDelete(LinkList &L, int i, ElemType &e)	/* �ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��,����e���ر�ɾԪ�� */
{
	LNode *p, *q;
    int j;
    
    p = L;
	j = 0;
	
    while ((p->next != L) && j < i - 1) {		/* ���ҵ�i-1����㣬pָ��ý�� */
    	p = p->next;
      	++j;
	}
	 
 	if (p->next == L || (j > i - 1)) {		/* iֵ���Ϸ� */ 
 		if (i == 1) {
 			q = p->next;							/* ��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� */
 			p->next = q->next; 						/* �ı�ɾ�����ǰ������ָ���� */ 
 			e = q->data;  							/* ��e���汻ɾ��������� */ 
 			delete q; 								/* �ͷ�ɾ�����Ŀռ� */ 
 
    		return OK;		
		}
		
 		printf("ListDeleteERROR\n");
  		return ERROR; 
	}
		     
 	q = p->next;							/* ��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� */
 	p->next = q->next; 						/* �ı�ɾ�����ǰ������ָ���� */ 
 	e = q->data;  							/* ��e���汻ɾ��������� */ 
 	delete q; 								/* �ͷ�ɾ�����Ŀռ� */ 
 
    return OK;
}/* ListDelete */ 

Status ListInsert(LinkList &L, int i, ElemType e)	/* �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½�� */
{
    int j;
	LNode *p, *s; 
	
    p = L;
	j = 0;
	
    while (j < i - 1) {
    	p = p->next;  					/* ���ҵ�i-1����㣬pָ��ý�� */
    	++j;
	}
	
    if (p == L || j > i - 1) {
    	if (i == 1) {
    		s = new LNode; 						/* �����½��*s */ 
  			s->data = e;              			/* �����*s����������λe */ 
  			s->next = p->next;      			/* �����*s��ָ����ָ����ai */ 
  			p->next = s;						/* �����*p��ָ����ָ����*s */ 
  	
  			return OK;	
		}	
		printf("ListInsertERROR\n");
  		return ERROR;
	}
  		
  	s = new LNode; 						/* �����½��*s */ 
  	s->data = e;              			/* �����*s����������λe */ 
  	s->next = p->next;      			/* �����*s��ָ����ָ����ai */ 
  	p->next = s;						/* �����*p��ָ����ָ����*s */ 
  	
  	return OK;
}/* ListInsert */ 

LNode * LocateElem(LinkList L, ElemType e, int &n)		 /* ������ֵe���� */
{
	LNode *p;
	n = 1;
	
	p = L->next;		/* ��ʼ����pָ����Ԫ��� */ 
	
	while (p != L  && p->data != e) {		/* ˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e */
		p = p->next;				/* pָ����һ����� */
		n++;
	}

	return p;						/* ���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪL(ͷ����ַ) */ 
}/* LocateElem */




int main()
{
    int n, i;
	ElemType e;
	int m, k;
	
    LinkList L = NULL;      /* ����ָ�������ָ�� */
    
    printf("please input n:");  /* ���뵥�����Ԫ�ظ��� */
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\n1-Create LinkList:\n");	/* ������ѭ������ */
        L = CreateList(n);      
		  
        printf("\n2-Print LinkList:\n");	/* ��������� */ 
        PrintList(L);
		           
        printf("\n3-GetElem from LinkList:\n");		/* �������ȡֵ */ 
        printf("input i=");					/* ������Ҫȡ����Ԫ����� */ 
        scanf("%d", &i);
        if (GetElem(L, i, e))     
            printf("No%i is %d", i, e);
        else
            printf("not exists\n");
            
        printf("\n4-please input insert location and data:(location,data)\n");
	    scanf("%d,%d", &m, &k);
	    ListInsert(L, m, k);		/* ������ĵ�m��λ��֮ǰ����Ԫ��k */
	    
	    printf("\n5-Print LinkList:\n");	/* ��������� */ 
        PrintList(L);
        
        printf("\n6-please input delete elem's location:");		/* �ڵ��������ɾ����x��Ԫ��,����y������ֵ */
	    scanf("%d", &i);
	    if (ListDelete(L, i, e));
			printf("delete elem is: %d\n", e);
	    	
	    printf("\n7-Print LinkList:\n");	/* ��������� */ 
        PrintList(L);
        
        printf("\n8-please input LocateElem:");
        scanf("%d", &e); 
        if (LocateElem(L, e, n) == L)
        	printf("NO\n");
        else
        	printf("address:%d   No%d\n", LocateElem(L, e, n), n);
    }
    
	else
        printf("ERROR\n");
        
    return 0;
}

