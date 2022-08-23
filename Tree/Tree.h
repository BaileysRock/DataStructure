#pragma once
#ifndef TREE_H
#define TREE_H
#include<iostream>

using namespace std;

typedef char ELEmentType;
struct node
{
	ELEmentType data;
	struct node* Lchild;
	struct node* Rchild;
};

typedef struct node* TREE;


//对树输入 递归与非递归
//递归输入树
TREE Input_Tree_Recursive();
//非递归输入
TREE Input_Tree_Not_Recursive();

//计算树的结点个数
int Count(TREE tree);
//求二叉树的高度
int Height(TREE tree);
//删除二叉树的递归算法
void Delete(TREE tree);

//遍历算法 递归
//先序
void Preorder_Traversal_Recursive(TREE tree);
//中序
void Inorder_Traversal_Recursive(TREE tree);
//后序
void Postorder_Traversal_Recursive(TREE tree);
//先序输出叶子
void Preorder_Traversal_Recursive_leaf(TREE tree);
//非递归
//先序
void Preorder_Traversal_Not_Recursive(TREE tree);
//中序
void Inorder_Traversal_Not_Recursive(TREE tree);
//后序
void Postorder_Traversal_Not_Recursive(TREE tree);
//层序
void Level_Order_Traversal_Not_Recursive(TREE tree);
//层序_用栈模拟队列
void Level_Order_Traversal_Not_Recursive_stack(TREE tree);

//交换二叉树所有结点子树
void Exchange(TREE tree);
//复制树
TREE Copy_Tree(TREE tree);

//判断是否是完全二叉树
void Is_Complete_Binary_Tree(TREE tree);

//求公共父节点
TREE Preorder_Traversal_Recursive_search(TREE tree, char ch);
int Preorder_Traversal_Recursive_search_1(TREE tree, TREE tree1);
int In_one_tree(TREE tree1, TREE tree2, TREE tree);
TREE Common_parent_node(TREE tree);




//优化后的算法
//优化思路，先递归找到公共父节点
//如果节点等于node1或node2，则返回该节点的值给父节点
//当前节点的左右子树分别包括node1和node2节点,则为所求结点
//找到父节点后，再寻找其所有父节点

//求公共结点
TREE Common_parent(TREE tree, TREE node1, TREE node2);
int Search_node(TREE tree, TREE t);
//输入两个结点
//并判断结点是否在树中
//若在树中
//利用TREE Common_parent(TREE root, TREE p, TREE q);求公共结点
TREE Common_parent_optimize(TREE root);
void Common_all(TREE tree,TREE t);

#endif