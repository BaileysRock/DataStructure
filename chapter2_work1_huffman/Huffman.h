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
	//当前元素个数
	int size;
};

//求哈夫曼数组中最小的结点
int SelectMin(TreeNode HT, int i, int* p);
//建立哈夫曼编码表
HuffmanTree Huffman_create();
//求Huffman
void CharSetHuffmanEncoding(string HuffmanEncoding[]);
//计算string中字符的数量
long Num_string(string HuffmanEncoding[]);
//将int转化为string
string InttoString(int n);
//将其二进制输出
void Convert_Output_file_list(string HuffmanEncoding[]);
//将字符串转化成int形式
int StringtoInt(string s);
//将压缩文件输出到txt中
void Convert_Output_file(string name1, string name2);
//将char型转为string的01序列
string ChartoString(char ch);
//从文件中恢复回01码，并解码
void Recover_from_file(string HuffmanEncoding[]);
//计算文件的压缩率
void Compress_percent(string name);




//基于单词的优化


//堆的操作
//创建一个空堆
void createMinHeap(Heap& minheap);
//判断堆是否为满
bool Is_Full(Heap minheap);
//判断堆是否为空
bool Is_Empty(Heap minHeap);
//插入堆
Heap Insert(Heap minheap, Optimize_Huffman huffman);
//删除最小元素并返回
Optimize_Huffman DeleteMin(Heap& minheap);



int Count_huffman(Optimize_Huffman huffman_optimize[]);
//统计每个单词的出现次数
void WordSetHuffmanWeight(Optimize_Huffman huffman_optimize[]);
//建立最小堆
Heap SetMinheap(Optimize_Huffman huffman_optimize[]);
//利用最小堆创建哈夫曼树
void WordSetHuffmanTree(Optimize_Huffman huffman_optimize[]);
//优化压缩输出二进制表
void Compress_Optimize_file_list(Optimize_Huffman huffman_optimize[]);
//求出输出的01序列个数
long Num_string_optimie(Optimize_Huffman huffman_optimize[]);
//从文件中读入
void Recover_from_file_optimize(Optimize_Huffman huffman_optimize[], int q);


#endif