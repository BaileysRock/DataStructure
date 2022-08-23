#include"Stack.h"
#include"Queue.h"
#include"Tree.h"
//遍历
//递归
//先序
void Preorder_Traversal_Recursive(TREE tree)
{
	if (tree)
	{
		cout << tree->data;
		Preorder_Traversal_Recursive(tree->Lchild);
		Preorder_Traversal_Recursive(tree->Rchild);
	}
}
//中序
void Inorder_Traversal_Recursive(TREE tree)
{
	if (tree)
	{
		Inorder_Traversal_Recursive(tree->Lchild);
		cout << tree->data;
		Inorder_Traversal_Recursive(tree->Rchild);
	}
}
//后序
void Postorder_Traversal_Recursive(TREE tree)
{
	if (tree)
	{
		Postorder_Traversal_Recursive(tree->Lchild);
		Postorder_Traversal_Recursive(tree->Rchild);
		cout << tree->data;
	}
}
//先序打印叶子结点
void Preorder_Traversal_Recursive_leaf(TREE tree)
{
	if (tree)
	{
		if (!tree->Lchild && !tree->Rchild)
			cout << tree->data;

		Preorder_Traversal_Recursive_leaf(tree->Lchild);
		Preorder_Traversal_Recursive_leaf(tree->Rchild);
	}
}

//非递归
//先序
void Preorder_Traversal_Not_Recursive(TREE tree)
{
	cout << "非递归先序遍历:" << endl;
	STACK s = Init_Stack();
	TREE t = tree;
	while (t != nullptr || !Is_empty(s))
	{
		while (t != nullptr)
		{
			cout << t->data;
			Push_Stack(s, t);
			t = t->Lchild;
		}
		if (!Is_empty(s))
		{
			t = Pop_Stack(s);
			t = t->Rchild;
		}
	}
	cout << endl;

}
//中序
void Inorder_Traversal_Not_Recursive(TREE tree)
{
	cout << "非递归中序遍历:" << endl;
	STACK s = Init_Stack();
	TREE t = tree;
	while (t != nullptr || !Is_empty(s))
	{
		while (t != nullptr)
		{

			Push_Stack(s, t);
			t = t->Lchild;
		}
		if (!Is_empty(s))
		{
			t = Pop_Stack(s);
			cout << t->data;
			t = t->Rchild;
		}
	}
	cout << endl;
}
//后序
//对先序的改造
//从根左右改造称根右左
//在压入栈中
//在输出时的顺序就变为了左右根
//输出结果为后序遍历
void Postorder_Traversal_Not_Recursive(TREE tree)
{
	cout << "非递归后序遍历:" << endl;
	STACK s = Init_Stack();
	TREE t = tree;
	STACK s1 = Init_Stack();
	while (t != nullptr || !Is_empty(s))
	{
		while (t != nullptr)
		{
			Push_Stack(s1, t);
			Push_Stack(s, t);
			t = t->Rchild;
		}
		if (!Is_empty(s))
		{
			t = Pop_Stack(s);
			t = t->Lchild;
		}
	}
	while (Is_empty(s1) == false)
	{
		cout << Pop_Stack(s1)->data;
	}
	cout << endl;
}
//层序
void Level_Order_Traversal_Not_Recursive(TREE tree)
{
	if (tree == nullptr)
		cout << "树是空!" << endl;
	else
	{
		cout << "层序遍历(队列):" << endl;
		queue q = Init_Queue();
		TREE t = tree;
		q = EnQueue(t, q);
		while (!Empty(q))
		{
			t = Front(q);
			cout << t->data;
			q = DeQueue(q);

			if (t->Lchild != nullptr)
				q = EnQueue(t->Lchild, q);
			if (t->Rchild != nullptr)
				q = EnQueue(t->Rchild, q);
		}
	}
	cout << endl;
}
//调用栈的层序遍历
void Level_Order_Traversal_Not_Recursive_stack(TREE tree)
{
	if (!tree)
		cout << "树为空!";
	else
	{
		cout << "层序遍历(栈）:" << endl;
		STACK s1 = Init_Stack();
		STACK s2 = Init_Stack();
		TREE t = tree;
		s1 = Push_Stack(s1, t);
		while (!Is_empty(s1))
		{
			t = Pop_Stack(s1);
			cout << t->data;

			if (t->Lchild != nullptr)
			{
				while (!Is_empty(s1))
				{
					s2 = Push_Stack(s2, Pop_Stack(s1));
				}
				s1 = Push_Stack(s1, t->Lchild);
				while (!Is_empty(s2))
				{
					s1 = Push_Stack(s1, Pop_Stack(s2));
				}
			}
			if (t->Rchild != nullptr)
			{
				while (!Is_empty(s1))
				{
					s2 = Push_Stack(s2, Pop_Stack(s1));
				}
				s1 = Push_Stack(s1, t->Rchild);
				while (!Is_empty(s2))
				{
					s1 = Push_Stack(s1, Pop_Stack(s2));
				}
			}
		}
	}
	cout << endl;
}

void Exchange(TREE tree)
{
	TREE p = tree;
	TREE temp;

	if (p != nullptr)
	{
		temp = p->Lchild;
		p->Lchild = p->Rchild;
		p->Rchild = temp;
		Exchange(p->Lchild);
		Exchange(p->Rchild);
	}
}

TREE Copy_Tree(TREE tree)
{
	TREE t_copy = nullptr;
	TREE t_copy1 = nullptr;
	if (tree)
	{
		TREE t1[MAX_SIZE];
		int flag = 0;
		int flag1 = 0;
		STACK s = Init_Stack();
		STACK s1 = Init_Stack();
		TREE t = tree;
		while (t != nullptr || !Is_empty(s))
		{
			while (t != nullptr)
			{
				Push_Stack(s, t);
				if (t_copy == nullptr && !flag)
				{
					t_copy = new node;
					flag = 1;
					t_copy1 = t_copy;
					Push_Stack(s1, t_copy);
				}
				else
				{
					if (flag1 == 0)
					{
						t_copy->Lchild = new node;
						Push_Stack(s1, t_copy->Lchild);
						t_copy = t_copy->Lchild;
					}
					else
					{
						Push_Stack(s1, t_copy);
						flag1 = 0;
					}
				}
				t_copy->data = t->data;
				t_copy->Lchild = nullptr;
				t_copy->Rchild = nullptr;
				t = t->Lchild;
			}
			if (!Is_empty(s))
			{
				t = Pop_Stack(s);
				t_copy = Pop_Stack(s1);
				if (t->Rchild != nullptr)
				{
					t_copy->Rchild = new node;
					t_copy->Rchild->data = t->Rchild->data;
					t_copy->Rchild->Lchild = nullptr;
					t_copy->Rchild->Rchild = nullptr;
					t_copy = t_copy->Rchild;
					flag1 = 1;
				}
				t = t->Rchild;
			}
		}
	}
	return t_copy1;
}

//判断是否是完全二叉树
//思路
//若队列中front的元素的左右节点都为空 或 左不空 右空 
//此时继续front队列元素，若有节点的左右节点不为空 则不为完全二叉树
//若队列中front出的元素左右节点不为空
//则继续front
//若左空右不空，则必不为二叉树
void Is_Complete_Binary_Tree(TREE tree)
{
	int flag = 0;
	int flag1 = 0;
	if (tree == nullptr)
		flag = 1;
	else
	{
		queue q = Init_Queue();
		TREE t = tree;
		q = EnQueue(t, q);
		while (!Empty(q))
		{
			t = Front(q);
			if (t->Lchild != nullptr || t->Rchild != nullptr)
			{
				if (flag1 == 1)
				{
					flag = 1;
					break;
				}
				if (t->Lchild != nullptr && t->Rchild != nullptr)
				{
					q = DeQueue(q);
					q = EnQueue(t->Lchild, q);
					q = EnQueue(t->Rchild, q);
				}
				else if (t->Lchild == nullptr && t->Rchild != nullptr)
				{
					flag = 1;
					break;
				}
				else if (t->Lchild != nullptr && t->Rchild == nullptr)
				{
					q = DeQueue(q);
					flag1 = 1;
				}
			}
			else
			{
				q = DeQueue(q);
				flag1 = 1;
			}
		}

	}
	if (flag)
		cout << "该树不为完全二叉树!" << endl;
	else
		cout << "该树为完全二叉树!" << endl;
}

//寻找公共双亲节点
//加入对输入结点是否存在的判断
//思路：
//判断两个结点是否在同一棵左子树或右子树
//（1）若不同在左子树且不同在右子树
//则此时父节点为根节点
//return tree
//（2）若同时在左节点(右节点)
//则令t=t->Lchild(t=t->Rchild)
//在次判断是否
//在同一左子树或右子树
//到(1)中的返回条件

TREE Preorder_Traversal_Recursive_search(TREE tree, char ch)
{
	STACK s = Init_Stack();
	TREE t = tree;
	while (t != nullptr || !Is_empty(s))
	{
		while (t != nullptr)
		{
			if (t->data == ch)
				return t;
			Push_Stack(s, t);
			t = t->Lchild;
		}
		if (!Is_empty(s))
		{
			t = Pop_Stack(s);
			t = t->Rchild;
		}
	}
	return nullptr;
}

int Preorder_Traversal_Recursive_search_1(TREE tree, TREE tree1)
{

	STACK s = Init_Stack();
	TREE t = tree;
	while (t != nullptr || !Is_empty(s))
	{
		while (t != nullptr)
		{
			if (t == tree1)
				return 1;
			Push_Stack(s, t);
			t = t->Lchild;
		}
		if (!Is_empty(s))
		{
			t = Pop_Stack(s);
			t = t->Rchild;
		}
	}
	return 0;
}

int In_one_tree(TREE tree1, TREE tree2, TREE tree)
{
	if (Preorder_Traversal_Recursive_search_1(tree, tree1) == 1)
	{
		if (Preorder_Traversal_Recursive_search_1(tree, tree2) == 1)
		{
			return 1;
		}
	}

	else
		return 0;
}

TREE Common_parent_node(TREE tree)
{

	if (tree == nullptr)
		cout << "该树为空!" << endl;
	else
	{
		TREE t = tree;
		char ch, ch1;
		cout << "请输入需要查找父节点的两个元素:" << endl;
		cin >> ch >> ch1;
		TREE node1, node2;
		node1 = Preorder_Traversal_Recursive_search(tree, ch);
		if (!node1)
		{
			cout << "该树中无" << ch << "元素!";
			return nullptr;
		}
		node2 = Preorder_Traversal_Recursive_search(tree, ch1);
		if (!node2)
		{
			cout << "该树中无" << ch1 << "元素!";
			return nullptr;
		}
		cout << ch << "与" << ch1 << "的父节点为:" << endl;
		while (t)
		{
			if (node1 == t || node2 == t)
				return t;
			
			if (t->Lchild != nullptr && t->Rchild != nullptr)
			{
				if (In_one_tree(node1, node2, t->Lchild) == 0 &&
					In_one_tree(node1, node2, t->Rchild) == 0)
					return t;

				else if (In_one_tree(node1, node2, t->Lchild) == 1)
				{
					cout << t->data;
					t = t->Lchild;
				}
				else if (In_one_tree(node1, node2, t->Rchild) == 1)
				{
					cout << t->data;
					t = t->Rchild;
				}
			}
			else if (t->Lchild != nullptr && t->Rchild == nullptr)
			{
				t = t->Lchild;
			}
			else if (t->Lchild == nullptr && t->Rchild != nullptr)
			{
				t = t->Rchild;
			}
		}

		return t;
	}
}

//以下为查找公共双亲结点的一些改进
//算法复杂度较低的求公共双亲结点算法
TREE Common_parent_optimize(TREE tree)
{
	if (tree == nullptr)
		cout << "该树为空!" << endl;
	else
	{
		TREE t = tree;
		char ch, ch1;
		cout << "请输入需要查找父节点的两个元素:" << endl;
		cin >> ch >> ch1;
		TREE node1, node2;
		node1 = Preorder_Traversal_Recursive_search(tree, ch);
		if (!node1)
		{
			cout << "该树中无" << ch << "元素!";
			return nullptr;
		}
	
		node2 = Preorder_Traversal_Recursive_search(tree, ch1);
		if (!node2)
		{
			cout << "该树中无" << ch1 << "元素!";
			return nullptr;
		}
		TREE common;
		common = Common_parent(t, node1, node2);
		return common;
	}
}

int Search_node(TREE tree, TREE t) 
{
	if (!tree)
		return 0;
	if (tree == t) 
		return 1;
	if (tree) 
		if (Search_node(tree->Lchild, t) || Search_node(tree->Rchild, t))
		{
			cout << tree->data << " ";
			return 1;
		}
	return 0;
}

TREE Common_parent(TREE tree, TREE node1, TREE node2) 
{
	if (tree == nullptr)
		return nullptr;
	if (tree == node1 || tree == node2)
		return tree;
	TREE left = Common_parent(tree->Lchild, node1, node2);
	TREE right = Common_parent(tree->Rchild, node1, node2);
	if (left && right)
		return tree;
	else if (left && !right)
		return left;
	else if (!left && right)
		return right;
	else if (!left && !right)
		return nullptr;
}
