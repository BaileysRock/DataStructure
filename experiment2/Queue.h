#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include"Tree.h"
const int MAX_SIZE = 20;

struct queue
{
	TREE data[MAX_SIZE];
	int front;
	int rear;
};
queue Init_Queue()
{
	queue q;
	q.front = MAX_SIZE - 1;
	q.rear = MAX_SIZE - 1;
	return q;

}
bool Empty(queue q)
{
	if (q.rear == q.front)
		return true;
	else
		return false;
}
TREE Front(queue q)
{
	if (Empty(q)) return nullptr;
	else {
		return (q.data[(q.front + 1) % MAX_SIZE]);
	}
}
queue EnQueue(TREE t, queue q)
{
	if ((q.rear + 1) % MAX_SIZE == q.front)
		cout << "队列满";
	else
	{
		q.rear = (q.rear + 1) % MAX_SIZE;
		q.data[q.rear] = t;
	}
	return q;
}
queue DeQueue(queue q)
{
	if (Empty(q))
		cout << "空队列" << endl;
	else
		q.front = (q.front + 1) % MAX_SIZE;
	return q;
}

#endif