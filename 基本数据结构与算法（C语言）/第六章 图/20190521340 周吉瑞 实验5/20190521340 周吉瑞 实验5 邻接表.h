/*
	Name: ʵ��5  �ڽӱ�.h
	Copyright: 
	Author: 20190521340 �ܼ���
	Date: 27/05/20 13:24
	Description: ͷ�ļ������������ڽӱ��ʾ��
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define OK 1
#define ERROR 0
#define OVERFLOW -2 

typedef int Status;
typedef char VerTexType;              		//���趥�����������Ϊ�ַ���
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ����

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - -
typedef struct ArcNode {		//�߽�� 
	int adjvex;					//�ñ���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;	//ָ����һ���ߵ�ָ�� 
	ArcType info;				//�ͱ���ص���Ϣ 
} ArcNode;

typedef struct VNode {			//������Ϣ 
	VerTexType data;
	ArcNode *firstarc;			//ָ���һ�������ö���ıߵ�ָ�� 
} VNode, AdjList[MVNum];		//AdjList��ʾ�ڽӱ����� 

typedef struct {				//�ڽӱ� 
	AdjList vertices;
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͱ��� 
} ALGraph;

int LocateVex(ALGraph G, VerTexType v);
Status CreateUDG(ALGraph &G);
void  PrtALGraph(ALGraph G);

int LocateVex(ALGraph G, VerTexType v)
{
	//ȷ����v��G�е�λ��
	for (int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
	return -1;
}//LocateVex

Status CreateUDG(ALGraph &G)
{
    //�����ڽӱ��ʾ��������������G
	int i , j , k;
	cout << "�������ܶ��������ܱ������Կո������";
    cin >> G.vexnum >> G.arcnum;	//�����ܶ��������ܱ���
	cout << endl;
	cout << "���������ƣ���a" << endl;
	for (i = 0; i < G.vexnum; ++i) {
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;         	//������������Ϣ
		G.vertices[i].firstarc = NULL;		//��ʼ����ͷ����ָ����ΪNULL 
	}
	cout << endl;
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	for (k = 0; k < G.arcnum; ++k) {	//�����ڱ� 
		VerTexType v1 , v2;
		ArcType w;
		ArcNode *p1, *p2;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;			//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  
		j = LocateVex(G, v2);		
		//ȷ��v1��v2��G�е�λ�ã�������G.vertices�е����
		p1 = new ArcNode;
		p1->adjvex = j;
		p1->info = w;					//��<v1, v2>��Ȩֵ��Ϊw
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		//���½��*p1���붥��vi�ı߱�ͷ��
		p2 = new ArcNode;
		p2->adjvex = i;
		p2->info = w;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2; 
	}//for
	return OK;
}//CreateUDG

void  PrtALGraph(ALGraph G)  //����ڽӱ� 
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; ++i) {
		printf("%d %c", i, G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (1) {
			if (p != NULL) {
				printf(" -> [%d,%d]", p->adjvex, p->info);
				p =  p->nextarc;
			}
			else
				break;
		}
		cout << endl;	
	}
	
}//Ptrglaph
