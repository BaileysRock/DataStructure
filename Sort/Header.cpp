#include"Header.h"

//Swap����������������������Ԫ��
//�����������Ľ���
void Swap(Record& A, Record& B)
{
	Record temp;
	temp = A;
	A = B;
	B = temp;
}


//ð���������������
//ð������
void BubbleSort(int n, Record L[])
{
	for (int i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (int j = n - 1; j > i; j--)
			if (L[j].key < L[j-1].key)
			{
				Swap(L[j], L[j - 1]);
				flag = 1;
			}
		if (!flag)
			break;
	}
}
//��������
void QuickSort(int i, int j, Record L[])
{
	int left = i;
	int right = j;
	keytype pivot = L[left].key;
	int pivotindex = left;
	while (left < right)
	{
		while (L[right].key >= pivot)
			right--;
		if (right > left)
		{
			Swap(L[left], L[right]);
			pivotindex = right;
			while (L[left].key < pivot)
				left++;

			if (left < right)
			{
				Swap(L[left], L[right]);
				pivotindex = left;
			}
		}
	}
	if (pivotindex)
	{
		if (i< pivotindex - 1)
			QuickSort(i, pivotindex - 1, L);
		if (pivotindex + 1 < j)
			QuickSort(pivotindex + 1, j, L);
	}
}



//ֱ��ѡ������
void SelectSort(int n, Record L[])
{

	int k;
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (L[j].key < L[k].key)
			{
				k = j;
				flag = 1;
			}
		}
		if (k != i)
			Swap(L[i], L[k]);
		if (!flag)
			break;

	}
}
//������
void Pushdown(int n, int i, Record L[])
{
	int smallest = i;
	
	int Lchild = smallest * 2 + 1;
	int Rchild = smallest * 2 + 2;
	if (Lchild < n && L[Lchild].key < L[smallest].key)
		smallest = Lchild;
	if (Rchild < n && L[Rchild].key < L[smallest].key)
		smallest = Rchild;
	if (smallest != i)
	{
		Swap(L[i], L[smallest]);
		Pushdown(n, smallest, L);
	}

}
void HeapSort(int n, Record L[])
{
	//����
	n = n - 1;
	for (int i = (n - 1) / 2; i >= 0; i--)
		Pushdown(n, i, L);

	for (int i = n ; i > 0; i--)
	{
		Swap(L[i], L[0]);
		Pushdown(n,0,L);
	}
}

//ֱ�Ӳ�������
void InsertSort(int n, Record L[])
{
	int k;
	for (int i = 1; i < n; i++)
	{
		k = i;
		while (k != 0)
		{
			if (L[k].key < L[k - 1].key)
				Swap(L[k], L[k - 1]);
			else
				break;
			k--;
		}
	}
}

//ϣ������
void ShellSort(int n, Record L[])
{
	int k;
	for (int j = n/2; j >= 1; j/=2)
	{
		for (int p = j; p < n; p++)
		{
			for (int i = p; i >= j; i -= j)
			{
				if (L[i].key < L[i - j].key)
					Swap(L[i], L[i - j]);
				else
					break;
			}

		}
	}


	
		
}



//�鲢����
void Merge(Record L[], Record L1[], int left, int mid, int right)
{
	int Lpos = left;
	int Rpos = mid + 1;
	int pos = left;
	while (Lpos <= mid && Rpos <= right)
	{
		if (L[Lpos].key < L[Rpos].key)
			L1[pos++] = L[Lpos++];
		else
			L1[pos++] = L[Rpos++];
	}
	while (Lpos <= mid)
		L1[pos++] = L[Lpos++];
	while (Rpos <= right)
		L1[pos++] = L[Rpos++];
	while (left <= right)
	{
		L[left] = L1[left];
		left++;
	}

}
//�鲢���������
void MergeSort(int n, Record L[])
{
	//����һ����Lһ�����Ľṹ������
	Record* L1 = new Record[n];
	//
	MergeSortMain(L, L1, 0, n - 1);
	delete[] L1;
}
//�鲢����������
void MergeSortMain(Record L[], Record L1[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSortMain(L, L1, left, mid);
		MergeSortMain(L, L1, mid + 1, right);
		Merge(L, L1, left, mid, right);

	}
}

//��������
//���������
int GetMax(int n, Record L[])
{
	int m = L[0].key;
	for (int i = 1; i < n; i++)
		if (L[i].key > m)
			m = L[i].key;
	return m;
}
//����Ͱ��
void CountSort(int n, int exp, Record L[])
{
	queue <Record> Q[10];
	int p;
	int j= 0;
	for (int i = 0; i < n; i++)
	{
		switch (L[i].key / exp - L[i].key / exp / 10 * 10)
		{
		case 0:
			Q[0].push(L[i]);
			break;
		case 1:
			Q[1].push(L[i]);
			break;
		case 2:
			Q[2].push(L[i]);
			break;
		case 3:
			Q[3].push(L[i]);
			break;
		case 4:
			Q[4].push(L[i]);
			break;
		case 5:
			Q[5].push(L[i]);
			break;
		case 6:
			Q[6].push(L[i]);
			break;
		case 7:
			Q[7].push(L[i]);
			break;
		case 8:
			Q[8].push(L[i]);
			break;
		case 9:
			Q[9].push(L[i]);
			break;
		} 
	}
	for (int i = 0; i < n; i++)
	{
		while (Q[j].empty())
			j++;

		L[i] = Q[j].front();
		Q[j].pop();
	}
}
//��������
void RadixSort(int n, Record L[])
{
	int max = GetMax(n, L);
	for (int exp = 1; exp <= max; exp *= 10)
	{
		CountSort(n, exp, L);
	}
}



//������ʼ���������
void CreateNumbers(int n, Record L[])
{
	int a;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a = rand() % n;
		L[i].key = a;
		L[i].other = a % 26 + 65;
	}
}
//�������������������ļ���
void OutputFile(int n, Record L[])
{
	ofstream fout;
	fout.open("data.txt");
	if(fout.is_open())
	{
		for(int i=0;i<n;i++)
		{
			fout << L[i].key;
			fout << endl;
		}
	}
}
//����������ɵ����������
void CopyList(int n, Record L[], Record L1[])
{
	for (int i = 0; i < n; i++)
	{
		L1[i].key = L[i].key;
		L1[i].other = L[i].other;
	}
}



//չʾ����������
void ShowList(int n, Record L[])
{
	for (int i = 0; i < n; i++)
		cout << L[i].key << endl;
}
//����ÿ�������������ʱ��
void ShowTime(int n)
{
	clock_t start, stop;
	Record* L = new Record[n];
	Record* L1 = new Record[n];
	CreateNumbers(n, L);
	OutputFile(n, L);
	CopyList(n ,L, L1);

	//ð��
	start = clock();
	BubbleSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "BubbleSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);

	//����
	start = clock();
	QuickSort(0 ,n-1, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "QuickSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//ֱ��ѡ������
	start = clock();
	SelectSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "SelectSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//������
	start = clock();
	HeapSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "HeapSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//ֱ�Ӳ�������
	start = clock();
	InsertSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "InsertSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//ϣ������
	start = clock();
	ShellSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "ShellSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//�鲢����
	start = clock();
	MergeSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "MergeSort:" << (double)(stop - start) / CLK_TCK << endl;
	CopyList(n, L, L1);


	//��������
	start = clock();
	RadixSort(n, L1);
	//ShowList(n, L1);
	stop = clock();
	cout << "RadixSort:" << (double)(stop - start) / CLK_TCK << endl;
}