#include <fstream>
#include "Queue.h"
#include "Stack.h"

#define NumVertices 50
using namespace std;
typedef char VertexData;
typedef int EdgeData;



//�����ڽӾ���Ĵ洢�ṹ
typedef struct {
	//�����
	VertexData verlist[NumVertices];
	//�洢��
	EdgeData edge[NumVertices][NumVertices];
	int n;//ͼ�Ķ�����
	int e;//ͼ�ı���
}Graph_Adjacency_Matrix;


//�����ڽӱ�Ĵ洢�ṹ
struct node{
	//�ڽӵ��±�
	int adjvex; 
	//�ߵ�Ȩֵ
	EdgeData cost;
	struct node* next;
};
typedef struct node* EdgeNode;
typedef struct
{
	VertexData vertex;
	//�ڽӱ�ͷָ��
	EdgeNode firstedge;
}VertexNode;
//�ڽӱ�
typedef struct
{
	VertexNode vexlist[NumVertices];
	int n;	//�������
	int e;	//�������
}AdjGraph;

void Experiment();

//���ѡ����ʾ
void choice();



//��ʾͼ�Ĺ���
void Print_Matrix(Graph_Adjacency_Matrix* G);
void Print_List(AdjGraph* G);



//�ڽӾ���Ĵ洢�ṹ
//����ͼ
void Create_Graph_Adjacency_Matrix(Graph_Adjacency_Matrix* G);
//�ڽӱ�Ĵ洢�ṹ
//����ͼ
void Create_Graph_Adjacency_List(AdjGraph* G);



//�����ڽӾ���洢�ṹ��ͼ
Graph_Adjacency_Matrix* Input_Graph_Adjacency_Matrix();
//�����ڽӱ�洢���ͼ
AdjGraph* Input_Graph_Adjacency_List();



//ͼ���ڽӾ����ڽӱ��໥ת���㷨
//�ڽӾ���ת�ڽӱ�
AdjGraph* Transform_to_List(Graph_Adjacency_Matrix* G);
//�ڽӱ�ת�ڽӾ���
Graph_Adjacency_Matrix* Transform_to_Matrix(AdjGraph* G);



//�����㷨
//�����������
//�ڽӾ���
//�ݹ�
void DFS_Recursion_Matrix(Graph_Adjacency_Matrix* G);
void DFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[], int dfn[], int count);
//�ڽӱ�
//�ݹ�
void DFS_Recursion_List(AdjGraph* G);
void DFS_List(AdjGraph* G, int i, bool visited[], int dfn[], int count);



//�����������
//�ڽӾ���
//�ǵݹ�
void DFS_Non_Recursion_Matrix(Graph_Adjacency_Matrix* G);
void DFS_Non_Recursion_List(AdjGraph* G);


//�������
//�ڽӾ���
void BFS_Traverse_Matrix(Graph_Adjacency_Matrix* G);
void BFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[], int dfn[]);
//�ڽӱ�
void BFS_Traverse_List(AdjGraph* G);
void BFS_List(AdjGraph* G, int i, bool visited[], int dfn[]);



//���ļ�����
//���ļ������ڽӾ�����ʽ����
Graph_Adjacency_Matrix* Input_from_file_Matrix(Graph_Adjacency_Matrix* G);
//���ļ������ڽӱ���ʽ����
AdjGraph* Input_from_file_List(AdjGraph* G);


