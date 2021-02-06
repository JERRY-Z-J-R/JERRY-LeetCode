/*
	Name: ʵ��3-1(2) 
	Copyright: 
	Author: 20190521340 �ܼ��� 
	Date: 14/04/20 13:29
	Description: ˳��ջ��ʵ��.cpp 
*/

#include <stdio.h>
#include "intstack.h"

void PrintStack(SqStack &S)
{
    int n = 1; 
    
    while (n <= S.top - S.base) {
		printf("%3d", Get(S, n));
		++n;
	}
	
    printf("\n");      
}/*Pop_and_Print*/

int CreateStack(SqStack &S)
{
    int e;
    
    if (InitStack(S)) {
		printf("��ʼ��ջ�ɹ�!\n");
    	prt_base_top_length(S);
    }  
    else {
        printf("��ʼ��ʧ��!\n");
        return ERROR;
    }
    
    printf("\n������Ҫ��ջ�ĸ�������:(Terminated by inputing a character)\n");
   	
	while (scanf("%d", &e)) {
		Push(S, e);
        prt_base_top_length(S);
    }
     
    return OK;
}/*CreateStack*/


int main()
{
    SqStack ss;
    
    printf("1-����ջ\n");
    CreateStack(ss);
    
    printf("\n2-��ջ����ӡ\n");
    prt_base_top_length(ss);
	PrintStack(ss);
	
    prt_base_top_length(ss);
    PrintStack(ss);
    
    return 0;
}   	

