/*
	Name: ʵ��7-3 ���� 
	Copyright:
	Author: 20190521340 �ܼ��� 
	Date: 2020/07/08 8:30 AM
	Description: �������򷽷��ıȽϣ������������ 
*/

#include <stdio.h>
#define MAXSIZE 100

typedef int keytype;
typedef char anytype;

typedef struct {
	keytype key;
	anytype otherinfo;
}ElemType;

typedef struct {
	ElemType r[MAXSIZE+1];
	int length;
}SqList;

void prt(SqList L, int low, int high) 
{ 
	int i;
	for (i = low; i <= high; i++)
    printf("%4d", L.r[i].key);
}

int InsertSort(SqList &L)
{
	int i, j, sum=0;
	
	for (i = 2; i <= L.length; ++i) {
		if (L.r[i].key < L.r[i-1].key) {
			L.r[0] = L.r[i];		
			L.r[i] = L.r[i-1];
      		for (j = i-2; L.r[0].key < L.r[j].key; --j) {	
			  	L.r[j+1] = L.r[j];	
				sum++;
			}//for 
            L.r[j+1] = L.r[0];         
   		}//if
   		
   		printf("��%2d��:", i-1);
    	printf("{");
		prt(L, 1, i);
		printf("}");
  	 	prt(L, i+1, L.length);
		printf("\n");
    }//for	
    
	return sum;
}//InsertSort


int BubbleSort(SqList &L) 
{	
	int i, j, flag, n, sum=0;
	ElemType t;
	n = L.length;
	flag = 1; 		
	
	for (i=1; i<n && flag==1; i++) {
		flag = 0;		
		
    	for (j = 1; j <= n-i; j++) {
			if(L.r[j].key > L.r[j+1].key) {
				flag = 1;			
				t = L.r[j];
				L.r[j] = L.r[j+1];
				L.r[j+1] = t;	
				sum++;
			}//if	
		}//for 
		
		printf("��%2d��:", i);
		prt(L, 1, L.length);
		printf("\n");
	}//for
	
    return sum;
}//BubbleSort

int SelectSort(SqList &L) 
{	
	int i, j, k, sum=0;
	ElemType t;
	
	for (i = 1; i < L.length; ++i) { 
		k = i;
		
   		for(j = i+1; j <= L.length; ++j) {
			sum++;
			if(L.r[j].key < L.r[k].key) {
				k = j;	
			}//if
  		}//for
  		
		if (k!=i) {
		t = L.r[i];
		L.r[i] = L.r[k];
		L.r[k] = t;
		}//if 
		
		printf("��%2d��:", i);
		prt(L, 1, L.length);
		printf("\n");
	}//for
	
	return sum;
}//SelectSort

int sum2 = 0;
int i = 0;

int Partition(SqList &L, int low, int high)
{
	int pivotkey;
	
	L.r[0] = L.r[low];
	pivotkey = L.r[low].key;
	
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey) {
			--high;
		}//while
		
		L.r[low] = L.r[high];
		++sum2;
		
		while (low < high && L.r[low].key <= pivotkey) {
			++low;
		}//while
		
		L.r[high] = L.r[low];
		++sum2;
	
	}//while
	
	++i;
	printf("��%2d��:", i);
	prt(L, 1, L.length);
	printf("\n");
	
	L.r[low] = L.r[0];
	
	return low;
}//Partition

void QSort(SqList &L, int low, int high)
{
	int pivotloc;
	
	if (low < high) {
		++sum2;
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc-1);
		QSort(L, pivotloc+1, high);
	}//if
}//QSort

int QuickSort(SqList &L)
{
	QSort(L, 1, L.length);
	
	return sum2;
}//QuickSort

void input(SqList &L)
{	
	int i;
 	keytype x;
 	
 	printf("\n������������һ�����ݣ�������%d����,��0��ʾ����:\n", MAXSIZE);
 	
	for (i=1; i<=MAXSIZE; i++) {
		scanf("%d", &x);
    	if (x == 0) {
			break;
		}//if
    	L.r[i].key = x;
    }//for
    
    L.length = i - 1;
}//input

void copy(SqList L1, SqList &L2)   
{ 
	int i;
	
	for (i=0; i<=L1.length; i++) {
    	L2.r[i] = L1.r[i];
    }//for
    
    L2.length = L1.length;
}//copy

int main()
{ 	
	int i, j, n, len1, len2, len3, len4;
  	keytype x;
  	SqList L, L1;
  	
	input(L);
	n = L.length;
  	copy(L, L1);  
	 
 	printf("\n1.ֱ�Ӳ�������\n");
	printf("\n����ǰԪ������Ϊ��\n        ");
    prt(L, 1, L.length);
	printf("\n");
    len1 = InsertSort(L);
    printf("Ԫ�ظ���Ϊ%d�����ƶ�����Ϊ��%d\n", n, len1);

	copy(L1, L);
	printf("\n2.ð������\n");
	printf("\n����ǰԪ������Ϊ��\n       ");
    prt(L, 1, L.length);
	printf("\n");
    len2 = BubbleSort(L);
    printf("Ԫ�ظ���Ϊ%d������������Ϊ��%d\n", n, len2);
    
    copy(L1,L);
	printf("\n3.��ѡ������\n");
    printf("\n����ǰԪ������Ϊ��\n       ");
    prt(L, 1, L.length);   
	printf("\n");
    len3 = SelectSort(L);
    printf("Ԫ�ظ���Ϊ%d�����Ƚϴ���Ϊ��%d\n", n, len3);

   	copy(L1,L);
	printf("\n4.��������\n");
    printf("\n����ǰԪ������Ϊ��\n       ");
    prt(L, 1, L.length);   
	printf("\n");
    len4 = QuickSort(L);
    printf("Ԫ�ظ���Ϊ%d������������Ϊ��%d\n", n, len4);
    getchar();
    
    return 0;
}//main


