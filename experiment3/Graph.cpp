#include"Graph.h"

void Experiment()
{
	choice();
	int n;
	cin >> n;
	AdjGraph* G_List = nullptr;
	Graph_Adjacency_Matrix* G_Matrix = nullptr;
	while (n != -1)
	{
		switch (n)
		{
		case 0:
			Print_Matrix(G_Matrix);
			Print_List(G_List);
			cout << "����������ѡ��:" << endl;
			break;
		case 1:
			//�����ڽӾ�����ڽӱ�ֱ𴴽�һ��ͼ
			//����һ�����ڽӾ���Ϊ�洢�ṹ��ͼ
			G_Matrix = Input_Graph_Adjacency_Matrix();
			system("cls");
			choice();
			break;
		case 2:
			//����һ�����ڽӱ�Ϊ�洢�ṹ��ͼ
			G_List = Input_Graph_Adjacency_List();
			system("cls");
			choice();
			break;
		case 3:
			//ͼ��ת��
			//���ڽӾ����ڽӱ�
			G_List = Transform_to_List(G_Matrix);
			system("cls");
			choice();
			break;
		case 4:
			//ͼ��ת��
			//���ڽӱ��ڽӾ���
			G_Matrix = Transform_to_Matrix(G_List);
			system("cls");
			choice();
			break;
		case 5:
			DFS_Recursion_Matrix(G_Matrix);
			cout << "����������ѡ��:" << endl;
			break;
		case 6:
			DFS_Recursion_List(G_List);
			cout << "����������ѡ��:" << endl;
			break;
		case 7:
			DFS_Non_Recursion_Matrix(G_Matrix);
			cout << "����������ѡ��:" << endl;
			break;
		case 8:
			DFS_Non_Recursion_List(G_List);
			cout << "����������ѡ��:" << endl;
			break;
		case 9:
			BFS_Traverse_Matrix(G_Matrix);
			cout << "����������ѡ��:" << endl;
			break;
		case 10:
			BFS_Traverse_List(G_List);
			cout << "����������ѡ��:" << endl;
			break;
		case 11:
			G_Matrix = Input_from_file_Matrix(G_Matrix);
			break;
		case 12:
			G_List = Input_from_file_List(G_List);
			break;
		case 13:
			Print_Kruskal(G_Matrix);
			cout << "����������ѡ��:" << endl;
			break;

		default:
			cout << "��������!" << endl;
			break;
		}
		cin >> n;
	}
}

//���ѡ����ʾ
void choice()
{
	cout << "0.��ʾ�Ѿ������ͼ" << endl;
	cout << "1.���ڽӾ������ʽ����ͼ" << endl;
	cout << "2.���ڽӱ����ʽ����ͼ" << endl;
	cout << "3.���ڽӾ����ͼת��Ϊ�ڽӱ��ͼ" << endl;
	cout << "4.���ڽӱ��ͼת��Ϊ�ڽӾ����ͼ" << endl;
	cout << "5.��ͼ�������������(�ݹ�)(�ڽӾ���)" << endl;
	cout << "6.��ͼ�������������(�ݹ�)(�ڽӱ�)" << endl;
	cout << "7.��ͼ�������������(�ǵݹ�)(�ڽӾ���)" << endl;
	cout << "8.��ͼ�������������(�ǵݹ�)(�ڽӱ�)" << endl;
	cout << "9.��ͼ�Ĺ����������(�ڽӾ���)" << endl;
	cout << "10.��ͼ�Ĺ����������(�ڽӱ�)" << endl;
	cout << "11.���ļ���ʽ����ͼ(�ڽӾ���)" << endl;
	cout << "12.���ļ���ʽ����ͼ(�ڽӱ�)" << endl;
	cout << "13.��Kruskal�㷨�����С������" << endl;
//	cout << "14.��Prim�㷨�����С������" << endl;
	cout << "-1.�˳�" << endl;
	cout << "����������ѡ��:" << endl;
}



//���ͼ�Ĺ���
//���ڽӾ��󴢴��ͼ
void Print_Matrix(Graph_Adjacency_Matrix* G)
{
	if (G)
	{
		cout << "�ڽӾ��󹹳ɵ�ͼΪ:" << endl;
		for (int i = 0; i < G->n; i++)
			cout << "\t" << G->verlist[i];
		cout << endl;
		for (int i = 0; i < G->n; i++)
		{
			cout << G->verlist[i];
			for (int j = 0; j < G->n; j++)
			{
				cout << "\t" << G->edge[i][j];
			}
			cout << endl;
		}
	}
}
//���ڽӱ����ͼ
void Print_List(AdjGraph* G)
{
	if (G)
	{
		cout << "�ڽӱ��ɵ�ͼΪ:" << endl;
		EdgeNode node1;
		for (int i = 0; i < G->n; i++)
		{
			cout << G->vexlist[i].vertex;
			node1 = G->vexlist[i].firstedge;
			while (node1 != nullptr)
			{
				cout << "->" << G->vexlist[node1->adjvex].vertex<<" "<<node1->cost;
				node1 = node1->next;
			}
			cout << endl;
		}
	}
}




//�ڽӾ���Ĵ洢�ṹ
//����ͼ
void Create_Graph_Adjacency_Matrix(Graph_Adjacency_Matrix* G)
{
	int i, j, k, w;
	cout << "��ֱ����붥������ͱ���:" << endl;
	cin >> G->n >> G->e;
	cout << "������ͼ�Ķ�����Ϣ:" << endl;
	for (i = 0; i < G->n; i++)
	{
		cin >> G->verlist[i];
	}
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++)
			G->edge[i][j] = 0;
	cout << "�����붥����±�i��j��Ȩֵ:" << endl;
	for (k = 0; k < G->e; k++)
	{
		cin >> i >> j >> w;
		G->edge[i-1][j-1] = w;
	}
}
//�ڽӱ�Ĵ洢�ṹ
//����ͼ
void Create_Graph_Adjacency_List(AdjGraph* G)
{
	int weight;
	int tail;
	int head;
	cout << "��ֱ����붥������ͱ���:" << endl;
	cin >> G->n >> G->e;
	cout << "�����붥�����Ϣ:" << endl;
	for (int i = 0; i < G->n; i++)
	{
		//�����ڽӱ�����Ϣ
		//cout << "�����붥�����Ϣ:" << endl;
		cin >> G->vexlist[i].vertex;
		G->vexlist[i].firstedge = nullptr;
	}
	cout << "�����붥����±�i��j��Ȩֵ:" << endl;
	for (int i = 0; i < G->e; i++)
	{
		//cout << "��ֱ�����ߵ���Ϣ   ͷ�����±ꡢ�ý����±ꡢȨֵ:" << endl;
		cin >> tail >> head >> weight;
		EdgeNode p = new node;
		p->adjvex = head - 1;
		p->cost = weight;
		p->next = G->vexlist[tail - 1].firstedge;
		G->vexlist[tail-1].firstedge = p;
		
		
	}

}




//�����ڽӾ���洢�ṹ��ͼ
Graph_Adjacency_Matrix* Input_Graph_Adjacency_Matrix()
{
	Graph_Adjacency_Matrix* G = new Graph_Adjacency_Matrix;
	Create_Graph_Adjacency_Matrix(G);
	return G;
}
//�����ڽӾ���洢���ͼ
AdjGraph* Input_Graph_Adjacency_List()
{
	AdjGraph* G = new AdjGraph;
	Create_Graph_Adjacency_List(G);
	return G;
}




//ͼ��ת��
//�ڽӾ���ת�ڽӱ�
AdjGraph* Transform_to_List(Graph_Adjacency_Matrix* G)
{
	AdjGraph* Graph = new AdjGraph;
	Graph->e = G->e;
	Graph->n = G->n;
	for (int i = 0; i < G->n; i++)
	{
		Graph->vexlist[i].vertex = G->verlist[i];
		Graph->vexlist[i].firstedge = nullptr;
		for (int j = 0; j < G->n; j++)
		{
			if (G->edge[i][j] != 0)
			{
				EdgeNode p = new node;
				p->cost = G->edge[i][j];
				p->adjvex = j;
				p->next = Graph->vexlist[i].firstedge;
				Graph->vexlist[i].firstedge = p;	
			}
		}
	}
	return Graph;
}
//ͼ��ת��
//�ڽӱ�ת�ڽӾ���
Graph_Adjacency_Matrix* Transform_to_Matrix(AdjGraph* G)
{
	Graph_Adjacency_Matrix* Graph = new Graph_Adjacency_Matrix;
	EdgeNode node1;
	VertexNode* vertexnode;
	for (int i = 0; i < G->n; i++)
	{
		Graph->verlist[i] = G->vexlist[i].vertex;
		for (int j = 0; j < G->n; j++)
			Graph->edge[i][j] = 0;
	}
	int j;
	for (int i = 0; i < G->n; i++)
	{
		node1 = G->vexlist[i].firstedge;
		while (node1 != nullptr)
		{
			Graph->edge[i][node1->adjvex] = node1->cost;
			node1 = node1->next;
		}
	}
	return Graph;
}


//�����㷨
//�����������
//�ݹ�
void DFS_Recursion_Matrix(Graph_Adjacency_Matrix* G)
{
	bool* visited = new bool[G->n];
	int* dfn = new int[G->n];
	int count = 0;
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	cout << "DFS(�ݹ�)(�ڽӾ���):";
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
			DFS_Matrix(G, i, visited, dfn, count); //�Ӷ��� i ������һ��������BFSX(G, i )
		cout << " ";
	}
	cout << endl;
	delete[]visited;
	delete[]dfn;
}
void DFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[],int dfn[],int count)
{
	int j;
	cout << G->verlist[i];
	visited[i] = true; 
	dfn[i] = count; 
	count++;
	for (j = 0; j < G->n; j++)
		if ((G->edge[i][j] == 1) && !visited[j])
			DFS_Matrix(G, j, visited, dfn,count);
}
//�ڽӱ�
//�ݹ�
void DFS_Recursion_List(AdjGraph* G)
{
	bool* visited = new bool[G->n];
	int* dfn = new int[G->n];
	int count = 0;
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	cout << "DFS(�ݹ�)(�ڽӱ�):";
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
			DFS_List(G, i, visited, dfn, count);
		cout << " ";
	}
	cout << endl;
	delete[]visited;
	delete[]dfn;
}
void DFS_List(AdjGraph* G, int i, bool visited[], int dfn[], int count)
{
	EdgeNode p;
	cout << G->vexlist[i].vertex;
	visited[i] = true;
	dfn[i] = count++;
	p = G->vexlist[i].firstedge;
	while (p) 
	{
		if (!visited[p->adjvex])
			DFS_List(G, p->adjvex, visited, dfn, count);
		p = p->next;
	}
}

//�����������
//�ڽӾ���
//�ǵݹ�
void DFS_Non_Recursion_Matrix(Graph_Adjacency_Matrix* G)
{
	bool* visited = new bool[G->n];
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	stack* s = Init_stack();
	int k;
	int flag = 0;
	int flag1 = 0;
	cout << "DFS(�ǵݹ�)(�ڽӾ���):";
	for (int i = 0; i < G->n; i++)
	{
		k = i;
		if (!visited[i])
		{
			cout << G->verlist[i];
			s = Push_stack(i, s);
			visited[i] = true;	
			while (!Is_empty(s))
			{
				for (int j = 0; j < G->n; j++)
				{
					if (G->edge[i][j] ==1 && visited[j] == false && j != i)
					{	
						flag = 1;
						visited[j] = true;
						cout << G->verlist[j];
						s = Push_stack(j, s);
						i = j;
						j = 0;
						break;
					}
				}
				if (!flag)
					i = Pop_stack(s);	
				flag = 0;	
			} 
			while (i == k)
			{
				s = Push_stack(i, s);
				while (!Is_empty(s))
				{
					for (int j = 0; j < G->n; j++)
					{
						if (G->edge[i][j] == 1 && visited[j] == false && j != i)
						{
							flag = 1;
							visited[j] = true;
							cout << G->verlist[j];
							s = Push_stack(j, s);
							i = j;
							j = 0;
							break;
						}
					}
					if (!flag)
						i = Pop_stack(s);
					flag = 0;
				}
				for (int q = 0; q < G->n; q++)
				{
					if (G->edge[i][q] == 1 && visited[q] == false && q != i)
					{
						flag1 = 1;
						break;
					}
				}
				if (!flag1)
				{
					break;
				}
				flag1 = 0;
			}
		}
		i = k;
		cout << " ";
	}
	cout << endl;
	delete[]visited;
}
//�ڽӱ�
void DFS_Non_Recursion_List(AdjGraph* G)
{
	bool* visited = new bool[G->n];
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	stack* s = Init_stack();
	int k;
	int flag = 0;
	EdgeNode node;
	int j;
	cout << "DFS(�ǵݹ�)(�ڽӱ�):";
	for (int i = 0; i < G->n; i++)
	{
		k = i;
		node = G->vexlist[i].firstedge;
		if (!visited[i] && node == nullptr)
		{
			cout << G->vexlist[i].vertex;
			visited[i] = true;
			cout << " ";
			continue;
		}
		else if (visited[i])
			continue;
		if (!visited[i])
		{
			cout << G->vexlist[i].vertex;
			visited[i] = true;
			s = Push_stack(i, s);
			while (!Is_empty(s))
			{
				while (visited[node->adjvex] && node->next!= nullptr)
					node = node->next;
				if (visited[node->adjvex])
					break;
				cout << G->vexlist[node->adjvex].vertex;
				visited[node->adjvex] = true;
				s = Push_stack(node->adjvex, s);
				node = G->vexlist[node->adjvex].firstedge;

				while (node != nullptr)
				{
					if (visited[node->adjvex] == true)
						node = node->next;
					else
						break;
				}
				while (node == nullptr)
				{
					j = Pop_stack(s);
					node = G->vexlist[j].firstedge;
					while (node != nullptr)
					{
						if (node == nullptr)
							break;
						if (visited[node->adjvex] == true)
						{
							node = node->next;
						}
						else if (visited[node->adjvex] == false)
							break;
					}
					if (Is_empty(s))
						break;
				}
				if (node == nullptr)
					break;
			}
			while (i == k) 
			{
				node = G->vexlist[i].firstedge;
				if (node == nullptr)
					break;
				while (node->next!=nullptr)
				{
					if (visited[node->adjvex] == true)
						node = node->next;
					else
						break;
				}
				if (visited[node->adjvex] == false)
				{
					s = Push_stack(i, s);

					while (!Is_empty(s))
					{
						cout << G->vexlist[node->adjvex].vertex;
						visited[node->adjvex] = true;
						s = Push_stack(node->adjvex, s);
						node = G->vexlist[node->adjvex].firstedge;

						while (node != nullptr)
						{
							if (visited[node->adjvex] == true)
								node = node->next;
							else
								break;
						}

						while (node == nullptr)
						{
							j = Pop_stack(s);
							node = G->vexlist[j].firstedge;
							while (node != nullptr)
							{
								if (node == nullptr)
									break;
								if (visited[node->adjvex] == true)
								{
									node = node->next;
								}
								else if (visited[node->adjvex] == false)
									break;
							}
							if (Is_empty(s))
								break;
						}
						if (node == nullptr)
							break;
					}
				}
				else
					break;	
			}
			cout << " ";
		}
		i = k;
	}
	cout << endl;
	delete[]visited;
}



//�������
//�ڽӾ���
void BFS_Traverse_Matrix(Graph_Adjacency_Matrix* G)
{
	bool* visited = new bool[G->n];
	int* dfn = new int[G->n];
	cout << "BFS(�ڽӾ���):";
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
			BFS_Matrix(G, i, visited, dfn);
		cout << " ";
	}
	delete[]visited;
	delete[]dfn;
	cout << endl;
		
}
void BFS_Matrix(Graph_Adjacency_Matrix* G, int i, bool visited[], int dfn[])
{
	int j;
	queue Q;
	Q = Init_Queue();
	cout << G->verlist[i];
	visited[i] = true;
	Q = EnQueue(i, Q);
	while (!Empty(Q))
	{
		i = Front(Q); 
		Q = DeQueue(Q);
		for (j = 0; j < G->n; j++) 
		{ 
			if (G->edge[i][j] == 1 && !visited[j]) 
			{ 
				cout << G->verlist[j];
				visited[j] = true; 
				Q = EnQueue(j, Q); 
			}
		} 
	}
}
//�ڽӱ�
void BFS_Traverse_List(AdjGraph* G)
{
	bool* visited = new bool[G->n];
	int* dfn = new int[G->n];
	cout << "BFS(�ڽӱ�):";
	for (int i = 0; i < G->n; i++)
		visited[i] = false;
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
			BFS_List(G, i, visited, dfn);
		cout << " ";
	}
	delete[]visited;
	delete[]dfn;
	cout << endl;
}
void BFS_List(AdjGraph* G, int i, bool visited[], int dfn[])
{
	 EdgeNode p;
	 queue Q; 
	 Q = Init_Queue();
	std::cout<< G->vexlist[i].vertex; 
	visited[i] = true;
	Q = EnQueue(i, Q);
	while (!Empty(Q))
	{
		i = Front(Q);
		Q = DeQueue(Q);
		p = G->vexlist[i].firstedge;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				cout << G->vexlist[p->adjvex].vertex;
				visited[p->adjvex] = true;
				Q = EnQueue(p->adjvex, Q);
			}
			p = p->next;
		}
	}
}





//���ļ�����
//���ڽӾ�����ʽ���ļ�����
Graph_Adjacency_Matrix* Input_from_file_Matrix(Graph_Adjacency_Matrix* G)
{
	ifstream fin;
	fin.open("Graph_Adjacency_Matrix.txt");
	if (!fin.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		cout << "����������ѡ��:" << endl;
		return G;
	}
	else
	{
		G = new Graph_Adjacency_Matrix;
		char ch;

		fin >> G->n >> G->e;
		for (int i = 0; i < G->n; i++)
		{
			fin >> ch;
		}
		for (int i = 0; i < G->n; i++)
		{
			fin >> G->verlist[i];
			for (int j = 0; j < G->n; j++)
				fin >> G->edge[i][j];
		}
		cout << "����ɹ�!" << endl;
		cout << "����������ѡ��:" << endl;
		return G;
	}
}
//���ڽӱ���ʽ���ļ�����
AdjGraph* Input_from_file_List(AdjGraph* G)
{
	ifstream fin;
	fin.open("Graph_Adjacency_AdjGraph.txt");
	if (!fin.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		cout << "����������ѡ��:" << endl;
		return G;
	}
	else
	{
		int weight;
		int tail;
		int head;
		int i;
		char ch;
		AdjGraph* G = new AdjGraph;
		fin >> G->n >> G->e;
		for (i = 0; i < G->n; i++)
		{
			fin >> G->vexlist[i].vertex;
			G->vexlist[i].firstedge = nullptr;
		}
		for (i = 0; i < G->e; i++)
		{
			fin >> tail >> head >> weight;
			EdgeNode p = new node;
			p->adjvex = head - 1;
			p->cost = weight;
			p->next = G->vexlist[tail - 1].firstedge;
			G->vexlist[tail - 1].firstedge = p;
		}
		int a = 0;
		cout << "����������ѡ��:" << endl;
		return G;
	}
}



//��С������
//Kruskal�㷨�����С������
void Sort_Graph(Edge edges[],int n)
{
	int i, k, m, q;
	Edge temp;
	for (i = 0; i < n - 1; i++)
	{
		q = i;
		for (k = i + 1; k < n; k++)
		{
			if (edges[q].wet > edges[k].wet)
			{
				q = k;
			}
		}
		if (edges[i].wet > edges[q].wet)
		{
			temp = edges[i];
			edges[i] = edges[q];
			edges[q] = temp;
		}
	}
}

int Find(int father[], int v)
{
	int f = v;
	while (father[f] > 0)
		f = father[f];
	return (f);
}
//��ӡKruskal�㷨�������
void Print_Kruskal(Graph_Adjacency_Matrix* G)
{
	Edge edges[30];
	int* father = new int[G->n];
	int count = 0;
	int bnf, edf;
	for (int i = 0; i < G->n; i++)
		for (int j = i+1; j < G->n; j++)
			if (G->edge[i][j] > 0)
			{
				edges[count].bgn = i;
				edges[count].end = j;
				edges[count].wet = G->edge[i][j];
				count++;
			}
	Sort_Graph(edges,count);
	for (int i = 0; i < G->n; i++)
		father[i] = 0;
	for (int i = 0; i < count; i++)
	{
		bnf = Find(father, edges[i].bgn);
		edf = Find(father, edges[i].end);
		if (bnf != edf) 
		{
			father[bnf] = edf;
			cout << "(" << edges[i].bgn << ", " << edges[i].end << ")" << endl;
		}
	}

}

//Prim�㷨�����С������
//void Print_Prim(Graph_Adjacency_Matrix* G)
//{
//	int* LOWCOST = new int[G->n/2 + 1];
//	int* CLOSSET = new int[G->n/2 + 1];
//	int i, j, k; 
//	int min;
//	int n = G->n;
//	for (int p = 0; p < G->n; p++)
//	{
//		for (int q = 0; q < G->n; q++)
//		{
//			if (G->edge[p][q] == 0)
//				G->edge[p][q] = INT_MAX / 2;
//		}
//	}
//
//	
//	for (i = 2; i <= n; i++) //��ʼ������LOWCOST������CLOSSET
//	{
//		LOWCOST[i] = G->edge[0][i-1]; 
//		CLOSSET[i] = 1;
//	}
//
//
//	for (i = 2; i <= n; i++)
//	{
//		min = LOWCOST[i];
//		k = i;
//		for (j = 2; j <= n; j++) //3.1��LOWCOST��ѡ��̱�,��CLOSSET�ж�Ӧ�Ķ������k
//			if (LOWCOST[j] < min)
//			{
//				min = LOWCOST[j]; k = j;
//			}
//		cout << "(" << k-1 << "," << CLOSSET[k]-1 << ")" << endl;//3.2�����С�������ı���Ϣ
//		LOWCOST[k] = INT_MAX/2; //3.3�Ѷ���k������С��������
//		for (j = 2; j <= n; j++) //3.4��������LOWCOST��CLOSSET
//			if (G->edge[k-1][j-1] < LOWCOST[j] && LOWCOST[j] < INT_MAX/2)
//			{
//				LOWCOST[j] = G->edge[k-1][j-1]; 
//				CLOSSET[j] = k;
//			}
//	}
//
//
//}


