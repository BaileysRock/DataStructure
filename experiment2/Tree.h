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


//�������� �ݹ���ǵݹ�
//�ݹ�������
TREE Input_Tree_Recursive();
//�ǵݹ�����
TREE Input_Tree_Not_Recursive();

//�������Ľ�����
int Count(TREE tree);
//��������ĸ߶�
int Height(TREE tree);
//ɾ���������ĵݹ��㷨
void Delete(TREE tree);

//�����㷨 �ݹ�
//����
void Preorder_Traversal_Recursive(TREE tree);
//����
void Inorder_Traversal_Recursive(TREE tree);
//����
void Postorder_Traversal_Recursive(TREE tree);
//�������Ҷ��
void Preorder_Traversal_Recursive_leaf(TREE tree);
//�ǵݹ�
//����
void Preorder_Traversal_Not_Recursive(TREE tree);
//����
void Inorder_Traversal_Not_Recursive(TREE tree);
//����
void Postorder_Traversal_Not_Recursive(TREE tree);
//����
void Level_Order_Traversal_Not_Recursive(TREE tree);
//����_��ջģ�����
void Level_Order_Traversal_Not_Recursive_stack(TREE tree);

//�������������н������
void Exchange(TREE tree);
//������
TREE Copy_Tree(TREE tree);

//�ж��Ƿ�����ȫ������
void Is_Complete_Binary_Tree(TREE tree);

//�󹫹����ڵ�
TREE Preorder_Traversal_Recursive_search(TREE tree, char ch);
int Preorder_Traversal_Recursive_search_1(TREE tree, TREE tree1);
int In_one_tree(TREE tree1, TREE tree2, TREE tree);
TREE Common_parent_node(TREE tree);




//�Ż�����㷨
//�Ż�˼·���ȵݹ��ҵ��������ڵ�
//����ڵ����node1��node2���򷵻ظýڵ��ֵ�����ڵ�
//��ǰ�ڵ�����������ֱ����node1��node2�ڵ�,��Ϊ������
//�ҵ����ڵ����Ѱ�������и��ڵ�

//�󹫹����
TREE Common_parent(TREE tree, TREE node1, TREE node2);
int Search_node(TREE tree, TREE t);
//�����������
//���жϽ���Ƿ�������
//��������
//����TREE Common_parent(TREE root, TREE p, TREE q);�󹫹����
TREE Common_parent_optimize(TREE root);
void Common_all(TREE tree,TREE t);

#endif