#include"Tree.h"

//�õݹ��������
TREE Input_Tree_Recursive()
{
	TREE t;
	char ch;
	cin >> ch;
	if (ch == '#')
		t = nullptr;
	else
	{
		t = new node;
		t->data = ch;
		t->Lchild = Input_Tree_Recursive();
		t->Rchild = Input_Tree_Recursive();
	}
	return t;
}
//�ǵݹ�����
TREE Input_Tree_Not_Recursive()
{
	const int max = 50;
	TREE t, bt = nullptr;
	TREE s[max] = { nullptr };
	int i, j;
	ELEmentType ch;
	cin >> i >> ch;
	while (i != 0 && ch != 0)
	{
		t = new node;
		t->data = ch;
		t->Lchild = nullptr;
		t->Rchild = nullptr;
		if (i == 1)
		{
			bt = t;
			s[i] = t;
		}
		else
		{
			s[i] = t;
			j = i / 2;
			if (i % 2 == 0)
				s[j]->Lchild = t;
			else
				s[j]->Rchild = t;
		}
		cin >> i >> ch;
	}
	return bt;
}

//�������Ľ�����
int Count(TREE tree)
{
	if (tree == nullptr)
		return 0;
	else
		return 1 + Count(tree->Lchild) + Count(tree->Rchild);


}

//����������߶ȵĵݹ��㷨
int Height(TREE tree)
{
	if (tree == nullptr)
		return 0;
	else
	{
		int m = Height(tree->Lchild);
		int n = Height(tree->Rchild);
		return (m > n) ? (m + 1) : (n + 1);
	}
}

//ɾ���������ĵݹ��㷨
void Delete(TREE tree)
{
	if (tree)
	{
		Delete(tree->Lchild);
		Delete(tree->Rchild);
		delete tree;
	}
}