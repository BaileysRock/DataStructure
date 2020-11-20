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

//			1111	1110	1101	1011	1010	0101	0100	0010	0001	0000
//	1111	 0		  0		  0		  0		  0		  1		  0		  0		  0		  0
//	1110	 0		  0		  0		  0		  0		  0		  1		  1		  0		  0
//	1101	 0		  0		  0		  0		  0		  1		  1		  0		  1		  0
//	1011	 0		  0		  0		  0		  0		  0		  0		  1		  1		  0
//	1010	 0		  0		  0		  0		  0		  0		  0		  1		  0		  1
//	0101	 1		  0		  1		  0		  0		  0		  0		  0		  0		  0
//	0100	 0		  1		  1		  0		  0		  0		  0		  0		  0		  0
//	0010	 0		  1		  0		  1		  1		  0		  0		  0		  0		  0
//	0001	 0		  0		  1		  1		  0		  0		  0		  0		  0		  0
//	0000	 0		  0		  0		  0		  1		  0		  0		  0		  0		  0