/*
	Name: 实验5-4  main.cpp 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 27/05/20 12:54
	Description: 广度优先搜索遍历连通图的递归算法（邻接矩阵存储）
*/
#include "20190521340 周吉瑞 实验5 邻接矩阵.h"
#include "20190521340 周吉瑞 实验5 队列.h"

bool visited[MVNum] = {false};					//访问标志数组，其初值为"false"
int FirstAdjVex(AMGraph G , int v);				//返回v的第一个邻接点
int NextAdjVex(AMGraph G, int v, int w);		//返回v相对于w的下一个邻接点
void BFS(AMGraph G, int v);					 	//从第v个顶点出发递归地深度优先遍历图G

void BFS(AMGraph G, int v) 	//从第v个顶点出发递归地广度优先遍历图G
{  
	cout << G.vexs[v] << "    ";  
	visited[v] =  true;
	//访问第v个顶点，并置访问标志数组相应分量值为true
	LinkQueue Q;	 
	InitQueue(Q);	//辅助队列Q初始化，置空 
	EnQueue(Q, G.vexs[v]);	//v进队 
	VerTexType u;
	int n;
	while (!QueueEmpty(Q)) {	//队列非空 
		DeQueue(Q, u);			//队头元素出队并置位u
		n = LocateVex(G, u);
		int w;
		for (w = FirstAdjVex(G, n);  w >= 0;  w = NextAdjVex(G, n, w))  
		//依次检查v的所有邻接点w ，FirstAdjVex(G, u)表示u的第一个邻接点 
		//NextAdjVex(G, u, w)表示u相对于w的下一个邻接点，w≥0表示存在邻接点 
			if (!visited[w]) {
				cout << G.vexs[w] << "    ";		//访问w，并置访问标志数组相应分量值为true 
				visited[w] = true;
				EnQueue(Q, G.vexs[w]);	//w进队 
			}//if 
	}//while
}//BFS

int FirstAdjVex(AMGraph G , int v) //求v的第一个未被访问过的邻接点
{
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] != MaxInt && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(AMGraph G , int v , int w) //v相对于w的下一个未被访问过的邻接点
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
	cout << "**广度优先搜索遍历连通图的递归算法**" << endl;
	AMGraph G; 
	CreateUDN(G);
	cout << endl;
	cout << "无向连通图G的邻接矩阵如下：" << endl ;
	PrtAMGraph(G);                     
	VerTexType c;
 	int i;
	do {
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		i = LocateVex(G , c);     //求顶点c的序号
    	if(i < 0)
			cout << "该点不存在，请重新输入！" << endl;
	} while (i < 0);
	
	cout << "广度优先搜索遍历连通图结果：" << endl;
	BFS(G, i);
	cout << endl;
	return 0;
}//main
