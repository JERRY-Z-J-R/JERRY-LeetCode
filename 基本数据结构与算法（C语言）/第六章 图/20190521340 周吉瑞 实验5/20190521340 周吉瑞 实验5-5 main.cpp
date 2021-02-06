/*
	Name: ʵ��5-5  main.cpp 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 27/05/20 12:54
	Description: �����������������ͨͼ�ĵݹ��㷨���ڽӱ�洢��
*/
#include "20190521340 �ܼ��� ʵ��5 �ڽӱ�.h"
#include "20190521340 �ܼ��� ʵ��5 ����.h"

bool visited[MVNum] = {false};					//���ʱ�־���飬���ֵΪ"false"
int FirstAdjVex(ALGraph G , int v);				//����v�ĵ�һ���ڽӵ�
int NextAdjVex(ALGraph G , int v , int w);		//����v�����w����һ���ڽӵ�
void BFS(ALGraph G, int v);					 	//�ӵ�v����������ݹ��������ȱ���ͼG

void BFS(ALGraph G, int v) 	//�ӵ�v����������ݹ�ع�����ȱ���ͼG
{  
	cout << G.vertices[v].data << "    ";  
	visited[v] =  true;
	//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue
	LinkQueue Q;	 
	InitQueue(Q);	//��������Q��ʼ�����ÿ� 
	EnQueue(Q, G.vertices[v].data);	//v���� 
	VerTexType u;
	int n;
	while (!QueueEmpty(Q)) {	//���зǿ� 
		DeQueue(Q, u);			//��ͷԪ�س��Ӳ���Ϊu
		n = LocateVex(G, u);
		int w;
		for (w = FirstAdjVex(G, n);  w >= 0;  w = NextAdjVex(G, n, w))  
		//���μ��n�������ڽӵ�w ��FirstAdjVex(G, n)��ʾn�ĵ�һ���ڽӵ� 
		//NextAdjVex(G, n, w)��ʾn�����w����һ���ڽӵ㣬w ��0��ʾ�����ڽӵ� 
			if (!visited[w]) {
				cout << G.vertices[w].data << "    ";		//����w�����÷��ʱ�־������Ӧ����ֵΪtrue 
				visited[w] = true;
				EnQueue(Q, G.vertices[w].data);	//w���� 
			}//if 
	}//while
}//BFS

int FirstAdjVex(ALGraph G , int v) //��v�ĵ�һ��δ�����ʹ����ڽӵ�
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while (p != NULL) {
		if (visited[p->adjvex] == false) 
			return p->adjvex;
		else 
			p = p->nextarc;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(ALGraph G , int v , int w) //v�����w����һ��δ�����ʹ����ڽӵ�
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	if (p != NULL) {
		while (1) {
			if (p->adjvex == w) {
				p = p->nextarc;
				break;
			}
			else
				p = p->nextarc;
		}//while
	}//if
	while (p != NULL) {
		if (visited[p->adjvex] == false) 
			return p->adjvex;
		else 
			p = p->nextarc; 
	}//while
	return -1;
}//NextAdjVex

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
		i = LocateVex(G , c);     //�󶥵�c�����
    	if(i < 0)
			cout << "�õ㲻���ڣ����������룡" << endl;
	} while (i < 0);
	
	cout << "�����������������ͨͼ�����" << endl;
	BFS(G, i);
	cout << endl;
	return 0;
}//main
