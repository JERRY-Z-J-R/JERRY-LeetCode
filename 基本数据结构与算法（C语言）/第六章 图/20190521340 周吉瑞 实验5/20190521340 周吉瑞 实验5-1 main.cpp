/*
	Name: ʵ��5-1  main.cpp
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 27/05/20 09:24
	Description: �����ڽӾ����ʾ�������������������ͳ�Ƹ������Ķ�
*/
#include "20190521340 �ܼ��� ʵ��5 �ڽӾ���.h"

int main()
{
	cout << "****�����ڽӾ����ʾ������������****" << endl ;
	AMGraph G;
	CreateUDN(G);
	cout << endl;
	cout << "��ͼ���ڽӾ������£�" << endl;
  	PrtAMGraph(G);
	cout << endl << "*****��������Ķȣ�*****" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		printf("��%d������ %c �Ķȣ�%d\n", i, G.vexs[i] , Degree(G,i));
	} 
	return 0;
}//main
