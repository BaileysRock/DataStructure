#include "Graph.h"

int main()
{
	choice();
	int n;
	cin >> n;
	AdjGraph* G_List = nullptr, * G_List1 = nullptr;
	Graph_Adjacency_Matrix* G_Matrix = nullptr, * G_Matrix1 = nullptr;
	while (n!=-1)
	{
		switch (n)
		{
		case 0:
			Print_Matrix(G_Matrix);
			Print_List(G_List);
			cout << "请输入您的选项:" << endl;
			break;
		case 1:
			//利用邻接矩阵和邻接表分别创建一个图
			//创建一个以邻接矩阵为存储结构的图
			G_Matrix = Input_Graph_Adjacency_Matrix();
			system("cls");
			choice();
			break;
		case 2:
			//创建一个以邻接表为存储结构的图
			G_List = Input_Graph_Adjacency_List();
			system("cls");
			choice();
			break;
		case 3:
			//图的转换
			//从邻接矩阵到邻接表
			G_List1 = Transform_to_List(G_Matrix);
			system("cls");
			choice();
			break;
		case 4:
			//图的转换
			//从邻接表到邻接矩阵
			G_Matrix1 = Transform_to_Matrix(G_List);
			system("cls");
			choice();
			break;
		case 5:
			DFS_Recursion_Matrix(G_Matrix);
			break;
		case 6:
			DFS_Recursion_List(G_List);
			break;
		case 7:
			DFS_Non_Recursion_Matrix(G_Matrix);
			break;
		case 8:
			DFS_Non_Recursion_List(G_List);
			break;
		case 9:
			BFS_Traverse_Matrix(G_Matrix);
			cout << "请输入您的选项:" << endl;
			break;
		case 10:
			BFS_Traverse_List(G_List);
			cout << "请输入您的选项:" << endl;
			break;
		case 11:
			G_Matrix = Input_from_file_Matrix(G_Matrix);
			break;
		case 12:
			G_List = Input_from_file_List(G_List);
			break;
		default:
			cout << "输入有误!" << endl;
			break;
		}
		cin >> n;
	}
	return 0;
}
