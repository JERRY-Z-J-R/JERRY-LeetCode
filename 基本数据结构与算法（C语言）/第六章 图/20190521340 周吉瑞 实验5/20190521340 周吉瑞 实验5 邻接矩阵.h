/*
	Name: ʵ��5  �ڽӾ���.h
	Copyright: 
	Author: 20190521340 �ܼ���
	Date: 27/05/20 09:24
	Description: ͷ�ļ������������ڽӾ����ʾ��
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxInt 32767                    	//��ʾ����ֵ������
#define MVNum 100                       	//��󶥵���
#define OK 1
#define ERROR 0
#define OVERFLOW -2 

typedef int Status;
typedef char VerTexType;              		//���趥�����������Ϊ�ַ���
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ����

//- - - - -ͼ���ڽӾ���洢��ʾ- - - - -
typedef struct {
	VerTexType vexs[MVNum];            		//�����
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ���
	int vexnum, arcnum;                		//ͼ�ĵ�ǰ�����ͱ���
} AMGraph;

int LocateVex(AMGraph G , VerTexType v);	//ȷ����v��G�е�λ��
Status CreateUDN(AMGraph &G);    				//�����ڽӾ����ʾ��������������G
void  PrtAMGraph(AMGraph G);  				//����ڽӾ���
int Degree(AMGraph G, int k);  				//���k������Ķ�

int LocateVex(AMGraph G , VerTexType v)
{
	//ȷ����v��G�е�λ��
	for (int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
	return -1;
}//LocateVex

Status CreateUDN(AMGraph &G)
{
    //�����ڽӾ����ʾ��������������G
	int i , j , k;
	cout << "�������ܶ��������ܱ������Կո������";
    cin >> G.vexnum >> G.arcnum;	//�����ܶ��������ܱ���
	cout << endl;
	cout << "���������ƣ���a" << endl;
	for (i = 0; i < G.vexnum; ++i) {
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];         	//������������Ϣ
	}
	cout << endl;
	for (i = 0; i < G.vexnum; ++i) {  	
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	}
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	for (k = 0; k < G.arcnum; ++k) {	//�����ڽӾ���
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;			//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  
		j = LocateVex(G, v2);		
		//ȷ��v1��v2��G�е�λ�ã�������������±�
		G.arcs[i][j] = w;				//��<v1, v2>��Ȩֵ��Ϊw
		G.arcs[j][i] = G.arcs[i][j];	//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw
	}//for
	return OK;
}//CreateUDN

void  PrtAMGraph(AMGraph G)  //����ڽӾ���
{
	int i,j;
	for (i = 0 ; i < G.vexnum ; ++i) {
		for (j = 0; j < G.vexnum; ++j) {
			if (G.arcs[i][j] != MaxInt)
				cout << G.arcs[i][j] << "\t";
			else
				cout << "��" << "\t";
		}//for j
		cout << endl;
 	}//for i
	cout << endl;
}//Ptrgraph

int Degree(AMGraph G, int k) //���k������Ķ�
{ 
	int j, d = 0;
	for (j = 0; j < G.vexnum; ++j) {
		if (G.arcs[k][j] != MaxInt)
			d = d + G.arcs[k][j];
	}
	return d;
}//Degree
