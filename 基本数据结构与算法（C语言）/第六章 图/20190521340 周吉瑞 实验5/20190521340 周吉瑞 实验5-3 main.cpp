/*
	Name: ʵ��5-3  main.cpp 
	Copyright: 
	Author: 201900521340 �ܼ��� 
	Date: 27/05/20 14:28
	Description: �����������������ͨͼ�ĵݹ��㷨���ڽӱ�洢��
*/

#include "20190521340 �ܼ��� ʵ��5 �ڽӱ�.h"

bool visited[MVNum] = {false};	//���ʱ�־���飬���ֵΪ"false"

void DFS_AL(ALGraph G, int v)	//ͼGΪ�ڽӱ����ͣ��ӵ�v������������������������ 
{
	ArcNode *p;
	int w;
	cout << G.vertices[v].data << "    ";
	visited[v] = true;
	p = G.vertices[v].firstarc;
	while (p != NULL) {
		w = p->adjvex;
		if (!visited[w])
			DFS_AL(G, w);
		p = p->nextarc;
	}
}

int main()
{
	cout << "**�����������������ͨͼ�ĵݹ��㷨**" << endl;
	ALGraph G; 
	CreateUDG(G);
	cout << endl;
	cout << "������ͨͼG���ڽӱ����£�" << endl ;
	PrtALGraph(G);                     
	VerTexType c;
 	int i;
	do {
		cout << "�����������ͨͼ����ʼ�㣺";
		cin >> c;
		i = LocateVex(G, c);     //�󶥵�c�����
    	if(i < 0)
			cout << "�õ㲻���ڣ����������룡" << endl;
	} while (i < 0);
	
	cout << "�����������������ͨͼ�����" << endl;
	DFS_AL(G, i);
	cout << endl;
	return 0;
}//main
