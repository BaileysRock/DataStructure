#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <fstream>
#include <limits.h>
#include <algorithm>
#include <windows.h>
#include <string>
using namespace std;
#define Max_length 500
#define Max_length_heap 501

typedef int Weight;
typedef char ElementType;
struct TreeNode
{
	ElementType ch;
	Weight weight;
	int Lchild;
	int Rchild;
	int Parent;
};
typedef TreeNode* HuffmanTree;
struct Optimize_Huffman
{
	string Huffman_word;
	string Huffman_code;
	Weight weight;
	int Lchild;
	int Rchild;
	int Parent;
};

struct Heap
{
	Optimize_Huffman huffman[Max_length_heap];
	//��ǰԪ�ظ���
	int size;
};

//���������������С�Ľ��
int SelectMin(TreeNode HT, int i, int* p);
//���������������
HuffmanTree Huffman_create();
//��Huffman
void CharSetHuffmanEncoding(string HuffmanEncoding[]);
//����string���ַ�������
long Num_string(string HuffmanEncoding[]);
//��intת��Ϊstring
string InttoString(int n);
//������������
void Convert_Output_file_list(string HuffmanEncoding[]);
//���ַ���ת����int��ʽ
int StringtoInt(string s);
//��ѹ���ļ������txt��
void Convert_Output_file(string name1, string name2);
//��char��תΪstring��01����
string ChartoString(char ch);
//���ļ��лָ���01�룬������
void Recover_from_file(string HuffmanEncoding[]);
//�����ļ���ѹ����
void Compress_percent(string name);




//���ڵ��ʵ��Ż�


//�ѵĲ���
//����һ���ն�
void createMinHeap(Heap& minheap);
//�ж϶��Ƿ�Ϊ��
bool Is_Full(Heap minheap);
//�ж϶��Ƿ�Ϊ��
bool Is_Empty(Heap minHeap);
//�����
Heap Insert(Heap minheap, Optimize_Huffman huffman);
//ɾ����СԪ�ز�����
Optimize_Huffman DeleteMin(Heap& minheap);



int Count_huffman(Optimize_Huffman huffman_optimize[]);
//ͳ��ÿ�����ʵĳ��ִ���
void WordSetHuffmanWeight(Optimize_Huffman huffman_optimize[]);
//������С��
Heap SetMinheap(Optimize_Huffman huffman_optimize[]);
//������С�Ѵ�����������
void WordSetHuffmanTree(Optimize_Huffman huffman_optimize[]);
//�Ż�ѹ����������Ʊ�
void Compress_Optimize_file_list(Optimize_Huffman huffman_optimize[]);
//��������01���и���
long Num_string_optimie(Optimize_Huffman huffman_optimize[]);
//���ļ��ж���
void Recover_from_file_optimize(Optimize_Huffman huffman_optimize[], int q);


#endif