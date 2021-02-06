/*
	Name: ���ö�����������ʽ 
	Copyright: 
	Author: Jerry_Z.
	Date: 06/05/20 19:21
	Description: ������������������ʽ������������������� 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {      /* ���ṹ���� */
	char data ;              /* ������� */
	struct BTNode *lchild;
	struct BTNode *rchild ;  /* ָ�� */
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

void InOrder(BiTree p)      /* ������������� */
{
  if (p != NULL) {
 	InOrder(p->lchild);
   	printf("%c", p->data);
   	InOrder(p->rchild);
  }
}/* InOrder */

double calculate(BiTree p)
{
	if (p == NULL)
		return 0;
	else if ('0' <= p->data &&  p->data <= '9')
		return p->data - '0';
	else if (p->data == '+')
		return calculate(p->lchild) + calculate(p->rchild);
	else if (p->data == '-')
		return calculate(p->lchild) - calculate(p->rchild);
	else if (p->data == '*')
		return calculate(p->lchild) * calculate(p->rchild);
	else if (p->data == '/')
		return calculate(p->lchild) / calculate(p->rchild);
}/* calculate */ 

int main(void)
{
  BiTree t = NULL;

  printf("\nplease input data:(��.��ʾ����)\n");
  printf("ע�������������\n"); 
  createBiTree(t);

  InOrder(t);
  printf("\nbioadashi = %f\n", calculate(t));

  system("pause");
  return 0;
}

