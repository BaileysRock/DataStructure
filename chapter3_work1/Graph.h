#include <iostream>

using namespace std;

typedef char VertexData;
typedef int cost;

#define NumVertices 10

//�����ڽӾ���Ĵ洢�ṹ
typedef struct Graph
{
	//�洢��
	cost edge[NumVertices][NumVertices];
}Graph_Adjacency_Matrix;


//�������к���
void homework();
int Min_matrix(int distance[],bool visited[]);

void Dijkstra(Graph_Adjacency_Matrix* G, int start, int end);
void Show(int n);