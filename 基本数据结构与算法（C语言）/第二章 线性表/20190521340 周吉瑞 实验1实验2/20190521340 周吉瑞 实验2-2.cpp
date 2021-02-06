/*
	Name: ʵ��2-2
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 08/04/20 23:24
	Description: �Ķ���������ں��ߴ���дǷȱ���ݣ������亯���Ļ�������ע�͡����г���д����������н�ͼ�� 
				Ϊʵ��2-1����ɾ���Ͳ��ҹ��ܺ����������������в�����룬��֤��������������ȷ�ԣ�д����������н�ͼ�� 
*/

#include <stdio.h>
#include <malloc.h>
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
Status ListInsert_sq(SqList &L, int i, ElemType e);		/* ˳���ĵ�i��λ��֮ǰ����Ԫ��e */
Status PrintList_sq(SqList L);  		/*���˳����Ԫ��*/
Status ListDelete_sq(SqList &L, int i);	 /*ɾ����i��Ԫ��*/
int ListLocate_sq(SqList L, ElemType e);	 	/*����ֵΪe��Ԫ��*/

Status InitList_sq(SqList &L) 	 //�㷨2.1 ˳���ĳ�ʼ��(����һ���յ�˳���L)
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

/*���˳����е�Ԫ��*/
Status PrintList_sq(SqList L) 
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%5d", L.elem[i-1]);
        
    return OK;
}/*PrintList*/

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

/*��˳�����ɾ����i��Ԫ��,����e������ֵ��iֵ�ĺϷ���Χ��1<=i<=L.length */
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	if ((i < 1) || (i > L.length)) {
		printf("ERROR\n"); 
		return ERROR;  //iֵ���Ϸ�
	}   
	 
	e = L.elem[i - 1];	
	
	for (int j = i; j <= L.length; j++)
		L.elem[j-1] = L.elem[j];  //��ɾ��Ԫ��֮���Ԫ��ǰ��
		    
	--L.length;      //����1
	
	return OK;
}

/*��˳����в���ָ��ֵԪ�أ����������*/
int ListLocate_sq(SqList L, ElemType e)
{  
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;     //���ҳɹ����������i+1
	
	printf("There is no the element.\n")	;	
	return 0;     //����ʧ�ܣ�����0
}

int main()
{
    SqList sl;
    int n;
	int m, k;
	int i, e;
	int x;
    
    printf("please input n:");  /*����˳����Ԫ�ظ���*/
    scanf("%d", &n);
    
    if (n > 0 && n <= 100) {
        printf("\n1-Create SqList:\n");
        InitList_sq(sl);		/*˳���ĳ�ʼ��(����һ���յ�˳���L)*/
        
        CreateList_sq(sl, n);		/* ����˳���(˳����������Ԫ��) */
        
        printf("\n2-Print SqList:\n");
        PrintList_sq(sl);		/*���˳���*/
		 
        printf("\nplease input insert location and data:(location,data)\n");
	    scanf("%d,%d", &m, &k);
	    ListInsert_sq(sl, m, k);		/* ˳���ĵ�m��λ��֮ǰ����Ԫ��k */
	    
	    printf("\n3-Print SqList:\n");
	    PrintList_sq(sl);		/*���˳���*/	
	    
	    printf("\nplease input delete elem's location:");		/*��˳�����ɾ����i��Ԫ��,����e������ֵ*/
	    scanf("%d", &i);
	    ListDelete_Sq(sl, i, e);
	    if (ListDelete_Sq(sl, i, e))
	    	printf("delete elem is: %d\n", e);
	    
	    printf("\n4-Print SqList:\n");
	    PrintList_sq(sl);		/*���˳���*/	
	    
	    printf("\nplese input locate element:");	/*��˳����в���ָ��ֵԪ�أ����������*/
	    scanf("%d", &x);
	    if (ListLocate_sq(sl, x))
	    	printf("The element is top %d\n", ListLocate_sq(sl, x));
	    
	    
    }
    else
        printf("ERROR\n");
        
    return 0;
}

