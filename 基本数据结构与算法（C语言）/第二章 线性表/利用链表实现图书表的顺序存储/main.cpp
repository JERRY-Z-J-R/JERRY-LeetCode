/*
	Name: ͼ�����ϵͳ2.0���ļ�(������ʵ��)
	Copyright: 
	Author: �ܼ��� 
	Date: 20/04/20 12:55
	Description: ͼ�����ϵͳmain.cpp
*/

#include "LinkList.h" 

int main(void)
{
	LinkList L;
	InitList_L(L);
	
	printf("---------------------------------------\n")
	printf("------------ͼ�����ϵͳ2.0------------\n");
	printf("---------------------------------------\n");
	
	int n;
	printf("������ͼ���Ҫ�����ͼ������");
	scanf("%d", &n);
	CreateList_L(L, n);
	
	printf("---------------------------------------\n");
	PrintList_L(L);
	
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
				LocateElem_L(L, b);
				
				break;
			
			case 2:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ�ȡ��ͼ��\n");
				printf("��������Ҫȡ�����������");
				char c[50];
				scanf("%s", &c);
				GetElem_L(L, c);
			
				printf("---------------------------------------\n");
				PrintList_L(L); 
				
				break;
			
			case 3:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ����ͼ��\n");
				printf("��������Ҫ�����λ����ţ�");
				int i;
				scanf("%d", &i);
				Book e;
				ScanfElem_L(e); 
				ListInsert_L(L, i, e); 
			
				printf("---------------------------------------\n");
				PrintList_L(L);
				
				break;
			
			case 4:
				printf("---------------------------------------\n");
				printf("��ѡ���ˣ���ѯͼ������\n");
				int l;
				ListLength_L(L, l);
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
	
	system("pause");
	return 0;	
} 
