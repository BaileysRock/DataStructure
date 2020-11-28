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
	//���Ա��ֵ
	keytype key;
	//���Ա�����ಿ��
	fields other;
};

//������������������������
void CreateNumbers(int n, Record L[]);
//�������������������ļ���
void OutputFile(int n, Record L[]);
//����������ɵ����������
void CopyList(int n, Record L[], Record L1[]);
//չʾ����������
void ShowList(int n);
//չʾ���㷨����ʱ��
void ShowTime(int n);
//Swap����������������������Ԫ��
//�����������Ľ���
void Swap(Record& A, Record& B);

//ð������
void BubbleSort(int n, Record L[]);

//��������
//���ػ�׼Ԫ�ص��±�
int FindPivot(int i, int j, Record L[]);
int Partition(int i, int j, keytype key, Record L[]);
void QuickSort(int i, int j, Record L[]);

void QuickSort(int i, int j, Record L[]);


//ֱ��ѡ������
void SelectSort(int n, Record L[]);
//������
//������С��
void Pushdown(int n, int i, Record L[]);
void HeapSort(int n, Record L[]);

//ֱ�Ӳ�������
void InsertSort(int n, Record L[]);
//ϣ������
void ShellSort(int n, Record L[]);


//�鲢����
void MergeSort(int n, Record L[]);
void MergeSortMain(Record L[], Record L1[], int left, int right);
void Merge(Record L[],Record L1[],int left ,int mid ,int right);


//��������
int GetMax(int n, Record L[]);
void CountSort(int n, int exp, Record L[]);
void RadixSort(int n, Record L[]);

#endif // !HEAD_H