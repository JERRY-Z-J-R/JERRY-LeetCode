/*
	Name: ʵ��2-5 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 10/04/20 14:01
	Description: ����˳���ʵ����������AB�Ĳ�����A = A U B) 
*/

#include <stdio.h>
#include <stdlib.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100     /*��ʼ�����˳�����*/

typedef int ElemType;   /*�����Ԫ�ص�����*/
typedef int Status;		/*��������ֵ���ͣ���ֵ�Ǻ������״̬��*/ 

typedef struct {
	
	ElemType *elem;		//�洢�ռ�Ļ���ַ
	int length;		//��ǰ����
	
} SqList;

Status InitList_sq(SqList &L);	 	/*˳���ĳ�ʼ��(����һ���յ�˳���L)*/
Status CreateList_sq(SqList &L, int n);	 /* ����˳���(˳����������Ԫ��) */
Status PrintList_sq(SqList L);  		/*���˳����Ԫ��*/
Status MergeList_sq(SqList &LA, SqList LB, int n, int m);	/* ���Ա�LA LB�ĺϲ� */
Status ListInsert_sq(SqList &L, int i, ElemType e);		/* ˳���ĵ�i��λ��֮ǰ����Ԫ��e */
Status GetElem_sq(SqList L, int i, ElemType &e);		/* ˳����ȡֵ */
int ListLocate_sq(SqList L, ElemType e);	 	/*����ֵΪe��Ԫ��*/

Status InitList_sq(SqList &L) 	 // ˳���ĳ�ʼ��(����һ���յ�˳���L)
{	
	L.elem = new ElemType[MAXSIZE];
 	//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem) {
		printf("OVERFLOW\n");
		exit(OVERFLOW); //�洢����ʧ���˳� 
	}
	
	L.length = 0; //�ձ���Ϊ0
	
	return OK;
}/*InitList*/


Status CreateList_sq(SqList &L, int n)
{
    ElemType e;
    
    int i;
    for (i = 0; i < n; i++) {
        printf("input data %d: ", i + 1);
        scanf("%d", &e);
        
        if (!ListInsert_sq(L, (i + 1), e)) {
			printf("ERROR\n");
            return ERROR;
    	}
    }
    
    return OK;
}/*CreateList*/

/* ���˳����е�Ԫ�� */
Status PrintList_sq(SqList L) 
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%5d", L.elem[i-1]);
        
    return OK;
}/*PrintList*/

Status MergeList_sq(SqList &LA, SqList LB, int n, int m)	/* ���Ա�LA LB�ĺϲ� */
{
	/* �����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA�� */
	int e;
	
	for (int i = 1; i <= m; i++) {
	 	GetElem_sq(LB, i, e);
	 	if (!ListLocate_sq(LA, e))
	 		ListInsert_sq(LA, ++n, e);
	}
	
	return OK;
}/*MergeList_sq*/

Status ListInsert_sq(SqList &L, int i, ElemType e)
{
    int k;
    
	if (i < 1 || i > (L.length + 1)) {
		printf("ERROR\n");
		return ERROR;
	}
		    
	if (L.length >= MAXSIZE) {
		printf("ERROR\n");
		return ERROR; 
	}
	
    for (k = (L.length - 1); k >= (i - 1); k--)         
        L.elem[k+1] = L.elem[k];

    L.elem[i-1] = e;
	                     
    ++L.length;
	                                 
    return OK;
}/*ListInsert*/

/*��˳����в���ָ��ֵԪ�أ����������*/
int ListLocate_sq(SqList L, ElemType e)
{  
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;     //���ҳɹ����������i+1
	
	return 0;     //����ʧ�ܣ�����0
}/*ListLocate*/

Status GetElem_sq(SqList L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
		return ERROR;
		
	e = L.elem[i - 1];
	
	return OK;
}/*GetElem*/

int main()
{
    SqList LA, LB;
    int n, m;
    
    printf("please input LA(n):");  /* ����˳���LA��Ԫ�ظ��� */
    scanf("%d", &n);
    
    printf("please input LB(m):");  /* ����˳����LBԪ�ظ��� */
    scanf("%d", &m);
    
    
    if ((n && m) > 0 && (n && m) <= 100) {
        printf("\nCreate SqList(LA)):\n");
        InitList_sq(LA);		/*˳���ĳ�ʼ��(����һ���յ�˳���LA)*/
        
        CreateList_sq(LA, n);		/* ����˳���LA(˳����������Ԫ��) */
        
        printf("\nPrint SqList(LA):\n");
        PrintList_sq(LA);		/*���˳���LA*/
        
        printf("\nCreate SqList(LB):\n");
        InitList_sq(LB);		/*˳���ĳ�ʼ��(����һ���յ�˳���LB)*/
        
        CreateList_sq(LB, m);		/* ����˳���LB(˳����������Ԫ��) */
        
        printf("\nPrint SqList(LB):\n");
        PrintList_sq(LB);		/*���˳���LB*/
        
        MergeList_sq(LA, LB, n, m);	/* ���Ա�LA LB�ĺϲ� */
        
        printf("\nPrint SqList(LA U LB):\n");
        PrintList_sq(LA);		/*���˳���LA = LA U LB*/
    }
    else
        printf("ERROR\n");
        
    return 0;
}

