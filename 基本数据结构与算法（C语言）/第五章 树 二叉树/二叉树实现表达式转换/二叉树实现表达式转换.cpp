#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char TElemType;

typedef struct  BiTNode {

	TElemType data;
	struct BiTNode *lchild, *rchild;
	
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T);		// �����������������
Status InOrderTraverse(BiTree T);	// ������������������
Status PostTraverse(BiTree T);		// ������������������

int main(void)
{
	BiTree T;

	printf("�������������ʽ��ǰ׺ʽ��\n");
	printf("ע�⣺����'#'��ʾ\n");

	CreateBiTree(T);
	
	printf("\n���ʽ����׺ʽΪ��\n\n");
	InOrderTraverse(T);
	printf("\n���ʽ�ĺ�׺ʽΪ��\n\n");
	PostTraverse(T);

	system("pause");
	return 0;
}// main

Status CreateBiTree(BiTree &T)		// �����������������
{
	char ch;
	cin >> ch;

	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

	return OK;
} // CreateBiTree

Status InOrderTraverse(BiTree T)	// ������������������
{
	if (T == NULL)
		return OK;
	else {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}// InOrderTraverse

Status PostTraverse(BiTree T)		// ������������������
{
	if (T == NULL)
		return OK;
	else {
		PostTraverse(T->lchild);
		PostTraverse(T->rchild);
		cout << T->data;
	}
}// PostTraverse



