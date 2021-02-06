/*
	Name: ʵ��5-2  main.cpp 
	Copyright: 
	Author: 201900521340 �ܼ��� 
	Date: 27/05/20 10:28
	Description: �����������������ͨͼ�ĵݹ��㷨���ڽӾ���洢��
*/

#include "20190521340 �ܼ��� ʵ��5 �ڽӾ���.h"

bool visited[MVNum] = {false};					//���ʱ�־���飬���ֵΪ"false"
int FirstAdjVex(AMGraph G , int v);				//����v�ĵ�һ���ڽӵ�
int NextAdjVex(AMGraph G, int v, int w);		//����v�����w����һ���ڽӵ�

void DFS(AMGraph G, int v) 	//�ӵ�v����������ݹ��������ȱ���ͼG
{  
	cout << G.vexs[v] << "    ";  
	visited[v] =  true;
	//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue
	int w;
	for (w = FirstAdjVex(G, v);  w >= 0;  w = NextAdjVex(G, v, w))  
	//���μ��v�������ڽӵ�w ��FirstAdjVex(G, v)��ʾv�ĵ�һ���ڽӵ� 
	//NextAdjVex(G, v, w)��ʾv�����w����һ���ڽӵ㣬w��0��ʾ�����ڽӵ� 
		if (!visited[w])
			DFS(G, w); //��v����δ���ʵ��ڽӶ���w�ݹ����DFS
}//DFS

int FirstAdjVex(AMGraph G , int v) //��v�ĵ�һ��δ�����ʹ����ڽӵ�
{
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] != MaxInt && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(AMGraph G , int v , int w) //v�����w����һ��δ�����ʹ����ڽӵ�
{
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] != MaxInt && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

int main()
{
	cout << "**�����������������ͨͼ�ĵݹ��㷨**" << endl;
	AMGraph G; 
	CreateUDN(G);
	cout << endl;
	cout << "������ͨͼG���ڽӾ������£�" << endl ;
	PrtAMGraph(G);                     
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
	DFS(G, i);
	cout << endl;
	return 0;
}//main
