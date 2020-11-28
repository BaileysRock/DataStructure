#pragma once
#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <ctime>
#include <queue>
#include <fstream>
using namespace std;
typedef int keytype;
typedef char fields;

struct Record
{
	//线性表的值
	keytype key;
	//线性表的其余部分
	fields other;
};

//利用随机数生成随机数的序列
void CreateNumbers(int n, Record L[]);
//将所生成随机数输出到文件中
void OutputFile(int n, Record L[]);
//复制随机生成的随机数序列
void CopyList(int n, Record L[], Record L1[]);
//展示排序后的序列
void ShowList(int n);
//展示各算法所需时间
void ShowTime(int n);
//Swap函数用来交换数组中两个元素
//方便下面代码的交换
void Swap(Record& A, Record& B);

//冒泡排序
void BubbleSort(int n, Record L[]);

//快速排序
//返回基准元素的下标
int FindPivot(int i, int j, Record L[]);
int Partition(int i, int j, keytype key, Record L[]);
void QuickSort(int i, int j, Record L[]);

void QuickSort(int i, int j, Record L[]);


//直接选择排序
void SelectSort(int n, Record L[]);
//堆排序
//构造最小堆
void Pushdown(int n, int i, Record L[]);
void HeapSort(int n, Record L[]);

//直接插入排序
void InsertSort(int n, Record L[]);
//希尔排序
void ShellSort(int n, Record L[]);


//归并排序
void MergeSort(int n, Record L[]);
void MergeSortMain(Record L[], Record L1[], int left, int right);
void Merge(Record L[],Record L1[],int left ,int mid ,int right);


//基数排序
int GetMax(int n, Record L[]);
void CountSort(int n, int exp, Record L[]);
void RadixSort(int n, Record L[]);

#endif // !HEAD_H