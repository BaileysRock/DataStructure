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

void make_matrix(int a[]);
//���ɾ���
void Matrix(int matrix[][NumVertices]);

//�������к���
void homework();

//Dijkstra�㷨ʵ��
int Min_matrix(int distance[],bool visited[]);
void Dijkstra(Graph_Adjacency_Matrix* G, int start, int end);

//Floyd�㷨ʵ��
void PrintPath(int start, int end, int path[][NumVertices]);
void Floyd(Graph_Adjacency_Matrix* G, int start, int end);
//�����ߵ�·��
void Show(int n);

