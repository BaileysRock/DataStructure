#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

const int MAX_SIZE = 20;


struct queue
{
	int Subscript[MAX_SIZE];
	int front;
	int rear;
};


//��ʼ������
queue Init_Queue();
//�ж϶����Ƿ�Ϊ��
bool Empty(queue q);
//���ض��е���Ԫ��
int Front(queue q);
//���
queue EnQueue(int t, queue q);
//ɾ���Ӷ�Ԫ��
queue DeQueue(queue q);


#endif // !QUEUE_H
