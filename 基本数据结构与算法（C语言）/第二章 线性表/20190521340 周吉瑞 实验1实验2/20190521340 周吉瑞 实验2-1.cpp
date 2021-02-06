/*
	Name: ʵ��2-1 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 08/04/20 20:12
	Description: �Ķ���������ں��ߴ���дǷȱ���ݣ������亯���Ļ�������ע�͡����г���д����������н�ͼ��  
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
Status ListInsert_sq(SqList &L, int i, ElemType e);		/* ˳���ĵ�i��λ��֮ǰ����Ԫ��e */
Status PrintList_sq(SqList L);  		/*���˳����Ԫ��*/
Status ListDelete_sq(SqList &L, int i);	 /*ɾ����i��Ԫ��*/
int ListLocate(SqList &L, ElemType e);	 	/*����ֵΪe��Ԫ��*/

Status InitList_sq(SqList &L) 	 //˳���ĳ�ʼ��(����һ���յ�˳���L)
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
}

/*��˳����в���ָ��ֵԪ�أ����������*/
int ListLocate(SqList &L, ElemType e)
{    
}

int main()
{
    SqList sl;
    int n;
	int m, k;
    
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
	    printf("\n");
    }
    else
        printf("ERROR\n");
        
    return 0;
}

