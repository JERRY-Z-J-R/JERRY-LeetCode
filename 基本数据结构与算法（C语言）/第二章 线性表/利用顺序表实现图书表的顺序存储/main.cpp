/*
	Name: ͼ�����ϵͳ���ļ�(˳���ʵ��) 
	Copyright: 
	Author: �ܼ��� 
	Date: 19/04/20 16:30
	Description: ͼ�����ϵͳmain.cpp
*/

#include "SqList.h" 

int main(void)
{
	SqList L;
	InitList_Sq(L);
	
	printf("---------------------------------------\n");
	printf("------------ͼ�����ϵͳ1.0------------\n");
	printf("---------------------------------------\n");
	
	int n;
	printf("������ͼ���Ҫ�����ͼ������");
	scanf("%d", &n);
	CreateList_Sq(L, n);
	
	printf("---------------------------------------\n");
	PrintList_Sq(L);
	
	int r = 1;
	while (r) {
	
		int m;
		printf("---------------------------------------\n");
		printf("1.ͼ�����\n");
		printf("2.ȡ��ͼ��\n");
		printf("3.���ͼ��\n");
		printf("4.��ѯͼ������\n");
		printf("5.�˳�ϵͳ\n"); 
		printf("---------------------------------------\n");
		printf("��ѡ���ܣ�");
		scanf("%d", &m);
	
		switch (m) {
		
			case 1:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ�ͼ�����\n");
				printf("��������Ҫ�������������");
				char b[50];
				scanf("%s", &b); 
				LocateElem_Sq(L, b);
				
				break;
			
			case 2:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ�ȡ��ͼ��\n");
				printf("��������Ҫȡ�����������");
				char c[50];
				scanf("%s", &c);
				GetElem_Sq(L, c);
			
				printf("---------------------------------------\n");
				PrintList_Sq(L); 
				
				break;
			
			case 3:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ����ͼ��\n");
				printf("��������Ҫ�����λ����ţ�");
				int i;
				scanf("%d", &i);
				Book e;
				ScanfElem_Sq(e); 
				ListInsert_Sq(L, i, e); 
			
				printf("---------------------------------------\n");
				PrintList_Sq(L);
				
				break;
			
			case 4:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ���ѯͼ������\n");
				int l;
				ListLength_Sq(L, l);
				printf("ͼ������Ϊ��%d��\n", l); 
				
				break;
			
			case 5:
				r = 0; 
				
				break;
				
		}
		
	}
	
	printf("---------------------------------------\n");
	printf("�ɹ��˳�ϵͳ��\n");
	printf("---------------------------------------\n");
	
	return 0;	
} 
