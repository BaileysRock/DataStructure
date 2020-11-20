#include <fstream>
#include "Queue.h"
#include "Stack.h"

#define NumVertices 50
using namespace std;
typedef char VertexData;
typedef int EdgeData;



//定义邻接矩阵的存储结构
typedef struct {
	//顶点表
	VertexData verlist[NumVertices];
	//存储边
	EdgeData edge[NumVertices][NumVertices];
	int n;//图的顶点数
	int e;//图的边数
}Graph_Adjacency_Matrix;


//定义邻接表的存储结构
struct node{
	//邻接点下标
	int adjvex; 
	//边的权值
	EdgeData cost;
	struct node* next;
};
typedef struct node* EdgeNode;
typedef struct
{
	VertexData vertex;
	//邻接表头指针
	EdgeNode firstedge;
}VertexNode;
//邻接表
typedef struct
{
	VertexNode vexlist[NumVertices];
	int n;	//顶点个数
	int e;	//顶点边数
}AdjGraph;

void Experiment();

//输出选项提示
void choice();



//显示图的构造
void Print_Matrix(Graph_Adjacency_Matrix* G);
void Print_List(AdjGraph* G);



//邻接矩阵的存储结构
//构造图
void Create_Graph_Adjacency_Matrix(Graph_Adjacency_Matrix* G);
//邻接表的存储结构
//构造图
void Create_Graph_Adjacency_List(AdjGraph* G);



//输入邻接矩阵存储结构的图
Graph_Adjacency_Matrix* Input_Graph_Adjacency_Matrix();
//输入邻接表存储表的图
AdjGraph* Input_Graph_Adjacency_List();



//图的邻接矩阵、邻接表相互转换算法
//邻接矩阵转邻接表
AdjGraph* Transform_to_List(Graph_Adjacency_Matrix* G);
//邻接表转邻接矩阵
Graph_Adjacency_Matrix* Transform_to_Matrix(AdjGraph* G);



//搜索算法
//深度优先搜索
//邻接矩阵
//递归
void DFS_Recursion_Matrix(Graph_Adjacency_Matrix* G);
void DFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[], int dfn[], int count);
//邻接表
//递归
void DFS_Recursion_List(AdjGraph* G);
void DFS_List(AdjGraph* G, int i, bool visited[], int dfn[], int count);



//深度优先搜索
//邻接矩阵
//非递归
void DFS_Non_Recursion_Matrix(Graph_Adjacency_Matrix* G);
void DFS_Non_Recursion_List(AdjGraph* G);


//广度搜索
//邻接矩阵
void BFS_Traverse_Matrix(Graph_Adjacency_Matrix* G);
void BFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[], int dfn[]);
//邻接表
void BFS_Traverse_List(AdjGraph* G);
void BFS_List(AdjGraph* G, int i, bool visited[], int dfn[]);



//从文件读入
//从文件中以邻接矩阵形式读入
Graph_Adjacency_Matrix* Input_from_file_Matrix(Graph_Adjacency_Matrix* G);
//从文件中以邻接表形式读入
AdjGraph* Input_from_file_List(AdjGraph* G);


