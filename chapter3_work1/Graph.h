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


//运行所有函数
void homework();
int Min_matrix(int distance[],bool visited[]);

void Dijkstra(Graph_Adjacency_Matrix* G, int start, int end);
void Show(int n);