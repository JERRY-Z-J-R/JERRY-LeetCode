/*
	Name: ʵ��1-5 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 07/04/20 23:48
	Description: ���Գ�������һ��ѧ����������������䡢�༶3��
				���������Ա�����ݣ����Ա�����
*/

#include <stdio.h>
#define N 10

typedef struct student {
	char name[8];		/*����*/
	int age;	    	/*����*/
	int clas;		/*�༶*/
}PERSON; 

int main()
{
	int i, n;
	PERSON stu[N];

	printf("\n����������(<10):\n");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {				/*����n����Ա����Ϣ*/
		printf("\n�������%d��Ա����Ϣ��(name  age    class)\n", i + 1);
		scanf("%s%d%d",stu[i].name, &stu[i].age, &stu[i]. clas);
	}
	printf("\n------------------------------\n"); 
	printf("name          age               class/office\n");
	
	for (i = 0; i < n; i++) 			/*���*/
		printf("%4s  is     %3d years old      His class  is %d\n", stu[i].name, stu[i].age,  stu[i].clas);

	return 0;
}

