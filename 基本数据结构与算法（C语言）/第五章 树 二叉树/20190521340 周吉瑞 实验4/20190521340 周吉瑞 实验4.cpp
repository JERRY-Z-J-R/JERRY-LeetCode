/*
	Name: ʵ��4 
	Copyright: 
	Author: 20190521340 �ܼ���
	Date: 06/05/20 09:05
	Description: ��������Ӧ����ʵ��
*/

#include <stdio.h>
#include <stdlib.h>

#define PRT printf("p=%8d  p->data=%c  p->lchild=%8d  p->rchild=%8d\n", p, p->data, p->lchild, p->rchild)

typedef struct BTNode {      /* ���ṹ���� */
	char data ;                /* ������� */
	struct BTNode *lchild;
	struct BTNode *rchild ;    /* ָ�� */
} *BiTree;

int createBiTree(BiTree &t)  /* ����������������� */
{
	char s;
	BiTree q;

	s = getchar();

	if (s == '.') {
    t = NULL; 
    return 1;
  }

	q = (BiTree)malloc(sizeof(struct BTNode));

	if (q == NULL) {
    printf("Memory alloc failure!\n");
    return 0;
  }

	q->data = s;
	t = q;

	createBiTree(q->lchild);  /* �ݹ齨�������� */
	createBiTree(q->rchild);  /* �ݹ齨�������� */

	return 1;
}/* createBiTree */

void PreOrder(BiTree p)     /* ������������� */
{
  if (p != NULL) {
       PRT;
       PreOrder(p->lchild);
       PreOrder(p->rchild);
  }
}/* PreOrder */

void InOrder(BiTree p)      /* ������������� */
{
  if (p != NULL) {
 	  InOrder(p->lchild);
   	PRT;
   	InOrder(p->rchild);
  }
}/* InOrder */

void PostOrder(BiTree p)    /* ������������� */
{
  if (p != NULL) {
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    PRT;
  }
}/* PostOrder */

void release(BiTree t)      /* �ͷŶ������ռ� */
{
  if(t != NULL) {
    release(t->lchild);
    release(t->rchild);
    free(t);
  }
}/* release */

int nodenum(BiTree p)       /* ������������ */
{
  int n;

  if (p == NULL)
    return 0;
  else
    n = (nodenum(p->lchild) + nodenum(p->rchild) + 1);

  return n;
}/* nodenum */

int leafnum(BiTree p)       /* �������Ҷ�ӽ���� */
{
  int n0;

  if (p == NULL)
    n0 = 0;
  else
    if (p->lchild == NULL && p->rchild == NULL) 
	   	n0 = 1; 
  	else
	   	n0 = (leafnum(p->lchild) + leafnum(p->rchild));      
  
  return n0;
}/* leafnum */

int depth(BiTree p)         /* ���������� */
{
  int d1,d2;
  if (p == NULL) 
    return 0;
  else {
    d1 = depth(p->lchild);
    d2 = depth(p->rchild);
    
    if (d1 > d2)
      return (d1 + 1);
    else
      return (d2 + 1);
  }
}/* depth */

int main(void)
{
  BiTree t = NULL;

  printf("\nplease input data:(��.��ʾ����)");
  createBiTree(t);

  printf("\n\nPreOrder the tree is:\n");
  PreOrder(t);

  printf("\n\nInOrder the tree is:\n");
  InOrder(t);

  printf("\n\nPostOrder the tree is:\n");
  PostOrder(t);

  printf("\n\n�ö�������%d�����\n", nodenum(t));

  printf("\n�ö�������%d��Ҷ�ӽ��\n", leafnum(t));

  printf("\n�ö����������Ϊ%d\n\n", depth(t));
  release(t);

  system("pause");
  return 0;
}

