#include "Graph.h"
#include <stack>


void homework()
{
	int matrix[NumVertices][NumVertices] =
	{
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	};
	//�����ںӰ�Ϊ1�����ڶ԰�0
	//�����ںӰ�Ϊ1�����ڶ԰�0
	//�����ںӰ�Ϊ1�����ڶ԰�0
	//����ںӰ�Ϊ1�����ڶ԰�0
	//�ʴ����������
	//	1111	1110	1101	1100
	//	1011	1010	1001	1000
	//	0111	0110	0101	0100
	//	0011	0010	0001	0000
	//���ݹ��ӹ���
	//��Ҫɾ�������Ϲ��ӹ��������
	//	1100	1001	1000	0111	0110	0011
	//������״̬ת��Ϊ1�������Ϲ����״̬ת��Ϊ1�����������
	//			  0		  1		  2		  3		  4		  5		  6		  7		  8		  9
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
	//��ԭ�������ת��Ϊ��matrix[0][0]��matrix[9][9]�����·��

	//����״̬ת������ڽӾ���
	//Matrix(matrix);
	Graph_Adjacency_Matrix* G = new Graph;
	for (int i = 0; i < NumVertices; i++)
		for (int j = 0; j < NumVertices; j++)
		{
			if (matrix[i][j] != 0)
				G->edge[i][j] = matrix[i][j];
			else
				G->edge[i][j] = INT_MAX / 2;
		}
	cout << "����ΪDijkstra�㷨ʵ�����·��:" << endl;
	Dijkstra(G,0,9);
	cout << endl << endl << endl;
	for (int i = 0; i < NumVertices; i++)
		for (int j = 0; j < NumVertices; j++)
			if (i == j)
				G->edge[i][j] = 0;
	cout << "����ΪFloyd�㷨ʵ�����·��:" << endl;
	Floyd(G, 0, 9);
}

void make_matrix(int a[])
{
	int x, y, z, w;
	for (int i = 0; i < 16; i++)
	{
		w = i % 2;
		z = i / 2 % 2;
		y = i / 2 / 2 % 2;
		x = i / 2 / 2 / 2 % 2;
		if (z == 1 && y == 1 || z == 0 && y == 0 || y == 1 && w == 1 || y == 0 && w == 0)
		{
			a[i] = 0;
		}
		else
			a[i] = 1;
	}
}


//���ɾ���
void Matrix(int matrix[][NumVertices])
{
	int a[16];
	int a1[16];
	make_matrix(a);
	make_matrix(a1);
	int x1, y1, z1, w1;
	int x2, y2, z2, w2;
	int k;
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			for (k = 15; k >= 0; k--)
			{
				if (a[k] == 1)
				{
					w1 = i % 2;
					z1 = i / 2 % 2;
					y1 = i / 2 / 2 % 2;
					x1 = i / 2 / 2 / 2 % 2;
				}
			}
			for (int k = 15; k >= 0; k--)
			{
				if (a[k] == 1)
				{
					w2 = i % 2;
					z2 = i / 2 % 2;
					y2 = i / 2 / 2 % 2;
					x2 = i / 2 / 2 / 2 % 2;
				}
				a1[k] = 0;
			}
			a[k] = 0;
			if (x1 == 1 && x2 == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			
		}

	int m = 0;
}



//Dijkstra�㷨ʵ��
//����Сֵ����λ��
int Min_matrix(int distance[],bool visited[],int i)
{
	int j = -1;
	for (int k = 0; k < NumVertices; k++)
	{
		if (!visited[k])
		{
			if (j == -1 || distance[k] < distance[j])
			{
				j = k;
			}
		}
	}
	return j;
}
//int Min_matrix_test(int distance[], bool visited[])
//{
//	int j = -1;
//	for (int i = 0; i < NumVertices; i++)
//	{
//		if (!visited[i])
//		{
//			j = i;
//			break;
//		}
//	}
//
//	for (int i = 0; i < NumVertices; i++)
//	{
//		if (distance[i] < distance[j] && !visited[i])
//		{
//			j = i;
//		}
//	}
//
//	return j;
//}

void Dijkstra(Graph_Adjacency_Matrix* G, int start, int end)
{
	bool visited[NumVertices];
	int distance[NumVertices];
	int parent[NumVertices];
	for (int i = 0; i < NumVertices; i++)
		visited[i] = false;
	for (int i = 0; i < NumVertices; i++)
		distance[i] = INT_MAX / 2;
	for (int i = 0; i < NumVertices; i++)
		parent[i] = -1;
	int i = start;
	visited[i] = true;
	distance[i] = 0;
	int p;
	for (int j = 0; j < NumVertices-1; j++)
	{
		for (int k = 0; k < NumVertices; k++)
		{
			if (G->edge[i][k] != INT_MAX / 2 && !visited[k] && G->edge[i][k] + distance[i] < distance[k])
			{
				distance[k] = G->edge[i][k] + distance[i];
				parent[k] = i;
			}
		}
		p = Min_matrix(distance, visited, i);
		visited[p] = true;
		i = p;
	}

	//int k;
	//while (i != end)
	//{
	//	for (int j = 0; j < NumVertices; j++)
	//	{
	//		if (visited[j] == false)
	//		{
	//			if (G->edge[i][j] == 1)
	//				distance[j] = distance[i] + G->edge[i][j];
	//			else
	//			{
	//				for (int k = 0; k < NumVertices; k++)
	//				{
	//					if (distance[k] != 0 && G->edge[k][j] == 1)
	//						distance[j] = distance[k] + G->edge[k][j];
	//				}
	//			}
	//		}
	//	}
	//	k = Min_matrix_test(distance, visited);
	//	parent[k] = i;
	//	visited[k] = true;
	//	i = k;
	//}

	i = end;
	stack <int> s;
	s.push(i);
	while (i != start)
	{
		s.push(parent[i]);

		i = parent[i];
	}
	while (!s.empty())
	{
		Show(s.top());
		//cout << s.top();
		s.pop();
	}
}


//Floyd�㷨ʵ��
//��ӡ·��
void PrintPath(int start, int end, int path[][NumVertices])
{
	if (path[start][end] == -1)
		Show(end);
	else
	{
		int mid = path[start][end];
		PrintPath(start, mid, path);
		PrintPath(mid, end, path);
	}
}
void Floyd(Graph_Adjacency_Matrix* G, int start, int end)
{
	int path[NumVertices][NumVertices];
	for (int i = 0; i < NumVertices; i++)
		for (int j = 0; j < NumVertices; j++)
			path[i][j] = -1;
	for (int i = 0; i < NumVertices; i++)
	{
		for (int j = 0; j < NumVertices; j++)
		{
			for (int k = 0; k < NumVertices; k++)
			{
			
				if (G->edge[j][k] > G->edge[j][i] + G->edge[i][k] /*&& j!=k && j!=i && i!=k*/)
				{
					path[j][k] = i;
					G->edge[j][k] = G->edge[j][i] + G->edge[i][k];
				}
			}
		}
	}
	Show(start);
	PrintPath(start, end, path);
}


void Show(int n)
{
	switch (n)
	{
	case 0:
		cout << "������˶��ںӰ�" << endl;
		break;
	case 1:
		cout << "�������ںӰ�,���ڶ԰�" << endl;
		break;
	case 2:
		cout << "���ǲ��ںӰ�,���ڶ԰�" << endl;
		break;
	case 3:
		cout << "������ںӰ�,���ڶ԰�" << endl;
		break;
	case 4:
		cout << "�����ںӰ����ǲ��ڶ԰�" << endl;
		break;
	case 5:
		cout << "�ǲ��ںӰ��������ڶ԰�" << endl;
		break;
	case 6:
		cout << "���ںӰ���������ڶ԰�" << endl;
		break;
	case 7:
		cout << "���ںӰ������ǲ��ڶ԰�" << endl;
		break;
	case 8:
		cout << "���ںӰ����������ڶ԰�" << endl;
		break;
	case 9:
		cout << "������˶��ڶ԰�" << endl;
		break;

	}
}
