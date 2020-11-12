#include"Huffman.h"

//对字符建立哈夫曼树
//选取哈夫曼数组内较小的元素
//通过将weight赋值-1作为排序后的标记
int SelectMin(TreeNode HT[], int i, int* p)
{
	TreeNode t;
	int k = INT_MAX;
	int a;
	for (int j = 0; j < i; j++)
	{
		if (HT[j].weight != -1)
		{
			if (HT[j].weight < k)
			{
				k = HT[j].weight;
				*p = j;
			}
		}
	}
	a = HT[*p].weight;
	HT[*p].weight = -1;
	return a;
}
//建立哈夫曼树
HuffmanTree Huffman_create()
{
	ifstream fin;
	fin.open("Huffman.txt");
	if (!fin.is_open())
	{
		cout << "Failure to open Huffman.txt!" << endl;
		return nullptr;
	}
	char s;
	int Char_frequence[128] = { 0 };
	while (!fin.eof())
	{
		fin.get(s);
		Char_frequence[s]++;
	}
	TreeNode* HT = new TreeNode[255];
	TreeNode* ht = HT;
	for (int i = 0; i < 255; i++)
	{
		if (i <= 127)
		{
			ht->ch = i;
			ht->weight = Char_frequence[i];
			ht->Parent = -1;
			ht->Lchild = -1;
			ht->Rchild = -1;
		}
		else
		{
			ht->ch = '0';
			ht->weight = 0;
			ht->Parent = -1;
			ht->Lchild = -1;
			ht->Rchild = -1;
		}
		if (i < 255)
			ht = ht++;
	}
	int p1, p2;
	for (int i = 128; i < 255; i++)
	{
		HT[i].weight = SelectMin(HT, i, &p1) + SelectMin(HT, i, &p2);
		HT[p1].Parent = HT[p2].Parent = i;
		HT[i].Lchild = p1;
		HT[i].Rchild = p2;
	}
	return HT;
}
//求哈夫曼编码表
void CharSetHuffmanEncoding(string HuffmanEncoding[])
{
	HuffmanTree ht = Huffman_create();
	int j, k;
	for (int i = 0; i < 128; i++)
	{
		j = i;
		while (j < 254)
		{
			k = ht[j].Parent;
			if (ht[k].Lchild == j)
				HuffmanEncoding[i] += '0';
			else if (ht[k].Rchild == j)
				HuffmanEncoding[i] += '1';
			j = k;
		}
	}
	for (int i = 0; i < 128; i++)
		reverse(HuffmanEncoding[i].begin(), HuffmanEncoding[i].end());
	delete[] ht;
}

string InttoString(int n)
{
	string s = "";
	int a;
	char ch;
	for (int i = 0; i < 7; i++)
	{
		a = n % 2;
		n = n / 2;
		ch = a + 48;
		s += ch;
	}
	reverse(s.begin(), s.end());
	return s;
}

long Num_string(string HuffmanEncoding[])
{
	ifstream fin;
	fin.open("Huffman.txt");
	if (!fin.is_open())
	{
		cout << "Failure to open Huffman.txt!" << endl;
		return 0;
	}
	char ch;
	long num = 0;
	while (fin.peek() != EOF)
	{
		fin.get(ch);
		num += (int)HuffmanEncoding[ch].length();
	}
	return num;
}

void Convert_Output_file_list(string HuffmanEncoding[])
{
	ifstream fin;
	ofstream outfile;
	long num = Num_string(HuffmanEncoding);
	int n;
	n = num % 7;
	fin.open("Huffman.txt");
	outfile.open("Huffman_Compress_List.txt");
	if (!fin.is_open() || !outfile.is_open())
		cout << "Failure to open Huffman.txt or Huffman_Compress_List.txt!" << endl;
	else
	{
		char s;
		string str = InttoString(7 - n);
		outfile << str;
		while (fin.peek() != EOF)
		{
			fin.get(s);
			str = HuffmanEncoding[s];
			outfile << str;
		}
	}
	for (int i = 0; i < 7 - n; i++)
		outfile << '0';
	outfile.close();
}

int StringtoInt(string str)
{
	double s = 0;
	for (int i = 0; i < (int)str.length(); i++)
		s = s + pow(2, 6 - i) * (str[i] - 48);
	int a = (int)s;
	return a;
}

void Convert_Output_file(string name1, string name2)
{
	ifstream fin;
	ofstream outfile;
	long num = 0;
	fin.open(name1);
	outfile.open(name2, ios::out | ios::binary);
	if (!fin.is_open() || !outfile.is_open())
		cout << "Failure to open" << name1 << "or" << name2 << "!" << endl;
	else
	{
		char ch;
		int a;
		while (fin.peek() != EOF)
		{
			string num = "";
			for (int i = 0; i < 7; i++)
			{
				fin >> ch;
				num += ch;
			}
			a = StringtoInt(num);
			ch = a;
			outfile.write((char*)&ch, sizeof(ch));
		}
		outfile.close();
	}
}

string ChartoString(char ch)
{
	int n = ch;
	string s = "";
	int a;
	char c;
	for (int i = 0; i < 7; i++)
	{
		a = n % 2;
		n = n / 2;
		c = a + 48;
		s = s + c;
	}
	reverse(s.begin(), s.end());
	return s;
}

void Recover_from_file(string HuffmanEncoding[])
{
	ifstream fin;
	//fin.open("Huffman_Compress.txt");
	fin.open("Huffman_Compress.txt", ios::in | ios::binary);
	if (!fin.is_open())
		cout << "Failure to open Huffman_Compress.txt!" << endl;
	else
	{
		char ch;
		char ch1;
		string s;
		string s1 = "";
		string s2 = "";
		int flag = 0;
		int j, k, n;
		//fin.get(ch);
		fin.read((char*)&ch, sizeof(ch));
		s = ChartoString(ch);
		n = StringtoInt(s);
		while (fin.peek() != EOF)
		{
			//fin.get(ch);
			fin.read((char*)&ch, sizeof(ch));
			s = ChartoString(ch);
			s1 += s;
			if (fin.peek() == EOF)
				break;
			for (j = 0; j < (int)s1.length(); j++)
			{
				s2 = s1.substr(0, j + 1);
				for (k = 0; k < 128; k++)
				{
					if (s2 == HuffmanEncoding[k])
					{
						flag = 1;
						ch1 = k;
						cout << ch1;
						break;
					}
				}
				if (flag == 1)
				{
					s1 = s1.substr(j + 1, (int)s1.length());
					j = -1;
					flag = 0;
				}
			}
		}
		s1 = s1.substr(0, (int)s1.length() - n);
		for (j = 0; j < (int)s1.length(); j++)
		{
			s2 = s1.substr(0, j + 1);
			for (k = 0; k < 128; k++)
			{
				if (s2 == HuffmanEncoding[k])
				{
					flag = 1;
					ch1 = k;
					cout << ch1;
					break;
				}
			}
			if (flag == 1)
			{
				s1 = s1.substr(j + 1, (int)s1.length());
				j = -1;
				flag = 0;
			}
		}
	}
}

void Compress_percent(string name)
{
	cout << endl;
	ifstream in("Huffman.txt");
	in.seekg(0, ios::end);
	streampos ps = in.tellg();
	cout << "File1 size: " << ps << "字节" << endl;
	in.close();
	ifstream in1(name);
	in1.seekg(0, ios::end);
	streampos ps1 = in1.tellg();
	cout << "File2 size: " << ps1 << "字节" << endl;
	in1.close();
	cout << "压缩率为:" << (double)ps1 / (double)ps * 100 << "%" << endl;
}

//最小堆的一些操作
//创建最小堆
void createMinHeap(Heap& minheap)
{

	minheap.size = 0;
	minheap.huffman[0].Huffman_word = "";
	minheap.huffman[0].Huffman_code = "";
	minheap.huffman[0].weight = -1;
	minheap.huffman[0].Lchild = -1;
	minheap.huffman[0].Rchild = -1;
	minheap.huffman[0].Parent = -1;
}
//判断堆是否已满
bool Is_Full(Heap minheap)
{
	if (minheap.size + 1 == Max_length_heap)
		return true;
	else
		return false;
}
//判断最小堆是否为空
bool Is_Empty(Heap minHeap)
{
	if (minHeap.size == 0)
		return true;
	return false;
}
//插入堆
Heap Insert(Heap minheap, Optimize_Huffman huffman)
{
	int i;
	if (!Is_Full(minheap))
	{
		i = minheap.size + 1;

		while ((i != 1) && (huffman.weight < minheap.huffman[i / 2].weight))
		{
			minheap.huffman[i] = minheap.huffman[i / 2];
			i /= 2;
		}
	}
	minheap.huffman[i] = huffman;
	minheap.size++;
	return minheap;
}

//删除最小元素并返回
Optimize_Huffman DeleteMin(Heap& minheap)
{
	int parent = 1, child = 2;
	Optimize_Huffman elem, tmp;
	if (!Is_Empty(minheap))
	{
		elem = minheap.huffman[1];
		tmp = minheap.huffman[minheap.size--];
		while (child <= minheap.size)
		{
			if ((child < minheap.size) &&
				(minheap.huffman[child].weight >= minheap.huffman[child + 1].weight))
				child++; //找最大子结点（左右儿子的大者）
			if (tmp.weight < minheap.huffman[child].weight)
				break;
			minheap.huffman[parent] = minheap.huffman[child];//上推
			parent = child;
			child *= 2;
		}
		minheap.huffman[parent] = tmp; //腾出位置后，把最后一个结点放到适当的位置中
		return elem;
	}
}

//基于单词的优化
//计算每个单词的weight
void WordSetHuffmanWeight(Optimize_Huffman huffman_optimize[])
{
	ifstream fin;
	fin.open("Huffman.txt");
	if (!fin.is_open())
		cout << "Failure to open Huffman.txt!" << endl;
	else
	{
		char ch;
		string str1 = "";
		int i = 0;
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		for (int p = 0; p < Max_length; p++)
		{
			huffman_optimize[p].weight = 0;
			huffman_optimize[p].Lchild = -1;
			huffman_optimize[p].Rchild = -1;
			huffman_optimize[p].Parent = -1;
		}
		while (fin.peek() != EOF)
		{
			fin.get(ch);
			if (ch <= 'z' && ch >= 'a' || ch <= 'Z' && ch >= 'A')
			{
				str1 += ch;
			}
			else
			{
				if (str1 != "")
				{
					for (int j = 0; j < i; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							huffman_optimize[j].weight++;
							flag2 = 1;
							break;
						}
					}
					if (!flag2)
					{
						huffman_optimize[i].weight++;
						huffman_optimize[i++].Huffman_word = str1;
					}
					str1 = "";
					str1 += ch;
					for (int j = 0; j < i; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							huffman_optimize[j].weight++;
							flag = 1;
							break;
						}
					}
					if (!flag)
					{
						huffman_optimize[i].weight++;
						huffman_optimize[i++].Huffman_word = str1;

					}
					flag = 0;
					flag2 = 0;
					str1 = "";
				}
				else
				{
					str1 += ch;
					for (int j = 0; j < i; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							huffman_optimize[j].weight++;
							flag1 = 1;
							break;
						}
					}
					if (!flag1)
					{
						huffman_optimize[i].weight++;
						huffman_optimize[i++].Huffman_word = str1;
					}
					flag1 = 0;
					str1 = "";
				}
			}
		}
		for (int j = 0; j < i; j++)
		{
			if (str1 == huffman_optimize[j].Huffman_word)
			{
				huffman_optimize[j].weight++;
				flag2 = 1;
				break;
			}
		}
		if (!flag2)
		{
			huffman_optimize[i].weight++;
			huffman_optimize[i++].Huffman_word = str1;
		}
	}
}

int Count_huffman(Optimize_Huffman huffman_optimize[])
{
	int n = 0;
	while (huffman_optimize[n].Huffman_word != "")
		n++;
	return n;
}

//建立最小堆
Heap SetMinheap(Optimize_Huffman huffman_optimize[])
{
	Heap minheap;
	createMinHeap(minheap);
	int i = 0;
	while (huffman_optimize[i].Huffman_word != "")
	{
		minheap = Insert(minheap, huffman_optimize[i]);
		i++;
	}
	return minheap;
}

void WordSetHuffmanTree(Optimize_Huffman huffman_optimize[])
{
	Heap minheap = SetMinheap(huffman_optimize);
	int n = 0;
	while (huffman_optimize[n].Huffman_word != "")
		n++;
	Optimize_Huffman h1, h2;
	int p1, p2;
	int flag1 = 0, flag2 = 0;
	for (int i = n; i < 2 * n - 1; i++)
	{
		h1 = DeleteMin(minheap);
		h2 = DeleteMin(minheap);
		int l = 0;
		while (l < i)
		{
			if (huffman_optimize[l].Huffman_word == h1.Huffman_word)
			{
				p1 = l;
				flag1 = 1;
			}
			else if (huffman_optimize[l].Huffman_word == h2.Huffman_word)
			{
				p2 = l;
				flag2 = 1;
			}
			if (flag1 && flag2)
			{
				flag1 = 0;
				flag2 = 0;
				break;
			}
			l++;
		}
		huffman_optimize[i].weight = h1.weight + h2.weight;
		huffman_optimize[p1].Parent = huffman_optimize[p2].Parent = i;
		huffman_optimize[i].Huffman_word = h1.Huffman_word + h2.Huffman_word;
		huffman_optimize[i].Lchild = p1;
		huffman_optimize[i].Rchild = p2;
		minheap = Insert(minheap, huffman_optimize[i]);
	}
	int j, k;
	for (int i = 0; i < n; i++)
	{
		j = i;
		while (j < 2 * n - 2)
		{
			k = huffman_optimize[j].Parent;
			if (huffman_optimize[k].Lchild == j)
				huffman_optimize[i].Huffman_code += '0';
			else if (huffman_optimize[k].Rchild == j)
				huffman_optimize[i].Huffman_code += '1';
			j = k;
		}
	}
	for (int i = 0; i < n; i++)
		reverse(huffman_optimize[i].Huffman_code.begin(), huffman_optimize[i].Huffman_code.end());
}

long Num_string_optimie(Optimize_Huffman huffman_optimize[])
{
	ifstream fin;
	fin.open("Huffman.txt");
	if (!fin.is_open())
	{
		cout << "Failure to open Huffman.txt!" << endl;
		return 0;
	}
	int n = 0;
	while (huffman_optimize[n].Huffman_word != "")
		n++;
	char ch;
	long num = 0;
	string str1 = "";
	while (fin.peek() != EOF)
	{
		fin.get(ch);
		if (ch <= 'z' && ch >= 'a' || ch <= 'Z' && ch >= 'A')
		{
			str1 += ch;
		}
		else
		{
			if (str1 != "")
			{
				for (int j = 0; j < n; j++)
				{
					if (str1 == huffman_optimize[j].Huffman_word)
					{
						num += huffman_optimize[j].Huffman_word.length();
						break;
					}
				}
				str1 = "";
				str1 += ch;
				for (int j = 0; j < n; j++)
				{
					if (str1 == huffman_optimize[j].Huffman_word)
					{
						num += huffman_optimize[j].Huffman_word.length();
						break;
					}
				}
				str1 = "";
			}
			else
			{
				str1 += ch;
				for (int j = 0; j < n; j++)
				{
					if (str1 == huffman_optimize[j].Huffman_word)
					{
						num += huffman_optimize[j].Huffman_word.length();
						break;
					}
				}
				str1 = "";
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (str1 == huffman_optimize[j].Huffman_word)
		{
			num += huffman_optimize[j].Huffman_word.length();
			break;
		}
	}

	return num;
}

void Compress_Optimize_file_list(Optimize_Huffman huffman_optimize[])
{
	ifstream fin;
	ofstream outfile;
	long num = Num_string_optimie(huffman_optimize);
	int n;
	n = num % 7;
	fin.open("Huffman.txt");
	outfile.open("Huffman_Compress_List_Optimize.txt");
	if (!fin.is_open() || !outfile.is_open())
		cout << "Failure to open Huffman.txt or Huffman_Compress_List.txt!" << endl;
	else
	{
		char ch;
		string str1 = InttoString(7 - n);
		outfile << str1;
		str1 = "";
		while (fin.peek() != EOF)
		{
			fin.get(ch);
			if (ch <= 'z' && ch >= 'a' || ch <= 'Z' && ch >= 'A')
			{
				str1 += ch;
			}
			else
			{
				if (str1 != "")
				{
					for (int j = 0;; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							outfile << huffman_optimize[j].Huffman_code;
							break;
						}
					}
					str1 = "";
					str1 += ch;
					for (int j = 0;; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							outfile << huffman_optimize[j].Huffman_code;
							break;
						}
					}
					str1 = "";
				}
				else
				{
					str1 += ch;
					for (int j = 0;; j++)
					{
						if (str1 == huffman_optimize[j].Huffman_word)
						{
							outfile << huffman_optimize[j].Huffman_code;
							break;
						}
					}
					str1 = "";
				}
			}
		}
		for (int j = 0;; j++)
		{
			if (str1 == huffman_optimize[j].Huffman_word)
			{
				outfile << huffman_optimize[j].Huffman_code;
				break;
			}
		}
	}
	for (int i = 0; i < 7 - n; i++)
		outfile << '0';
	outfile.close();
}

void Recover_from_file_optimize(Optimize_Huffman huffman_optimize[], int q)
{
	ifstream fin;
	fin.open("Huffman_Compress_Optimize.txt", ios::in | ios::binary);
	if (!fin.is_open())
		cout << "Failure to open Huffman_Compress.txt!" << endl;
	else
	{
		char ch;
		char ch1;
		string s;
		string s1 = "";
		string s2 = "";
		int flag = 0;
		int j, k, n;
		fin.read((char*)&ch, sizeof(ch));
		s = ChartoString(ch);
		n = StringtoInt(s);
		while (fin.peek() != EOF)
		{
			fin.read((char*)&ch, sizeof(ch));
			s = ChartoString(ch);
			s1 += s;
			if (fin.peek() == EOF)
				break;
			for (j = 0; j < (int)s1.length(); j++)
			{
				s2 = s1.substr(0, j + 1);
				for (k = 0; k < q; k++)
				{
					if (s2 == huffman_optimize[k].Huffman_code)
					{
						flag = 1;
						ch1 = k;
						cout << huffman_optimize[k].Huffman_word;
						break;
					}
				}
				if (flag == 1)
				{
					s1 = s1.substr(j + 1, (int)s1.length());
					j = -1;
					flag = 0;
				}
			}
		}
		s1 = s1.substr(0, (int)s1.length() - n);
		for (j = 0; j < (int)s1.length(); j++)
		{
			s2 = s1.substr(0, j + 1);
			for (k = 0; k < 128; k++)
			{
				if (s2 == huffman_optimize[k].Huffman_code)
				{
					flag = 1;
					ch1 = k;
					cout << huffman_optimize[k].Huffman_word;
					break;
				}
			}
			if (flag == 1)
			{
				s1 = s1.substr(j + 1, (int)s1.length());
				j = -1;
				flag = 0;
			}
		}
	}
}
