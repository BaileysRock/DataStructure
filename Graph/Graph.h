#include <iostream>

using namespace std;

typedef char VertexData;
typedef int cost;

#define NumVertices 10

//定义邻接矩阵的存储结构
typedef struct Graph
{
	//存储边
	cost edge[NumVertices][NumVertices];
}Graph_Adjacency_Matrix;

void make_matrix(int a[]);
//生成矩阵
void Matrix(int matrix[][NumVertices]);

//运行所有函数
void homework();

//Dijkstra算法实现
int Min_matrix(int distance[],bool visited[]);
void Dijkstra(Graph_Adjacency_Matrix* G, int start, int end);

//Floyd算法实现
void PrintPath(int start, int end, int path[][NumVertices]);
void Floyd(Graph_Adjacency_Matrix* G, int start, int end);
//表明走的路径
void Show(int n);

