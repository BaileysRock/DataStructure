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


//初始化队列
queue Init_Queue();
//判断队列是否为空
bool Empty(queue q);
//返回队列的首元素
int Front(queue q);
//入队
queue EnQueue(int t, queue q);
//删除队顶元素
queue DeQueue(queue q);


#endif // !QUEUE_H
