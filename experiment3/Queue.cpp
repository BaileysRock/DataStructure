#pragma once
#include"Queue.h"

//初始化队列
queue Init_Queue()
{
	queue q;
	q.front = MAX_SIZE - 1;
	q.rear = MAX_SIZE - 1;
	return q;

}
//判断队列是否为空
bool Empty(queue q)
{
	if (q.rear == q.front)
		return true;
	else
		return false;
}
//返回队列的首元素
int Front(queue q)
{
	return (q.Subscript[(q.front + 1) % MAX_SIZE]);
}
//入队
queue EnQueue(int t, queue q)
{
	if ((q.rear + 1) % MAX_SIZE == q.front)
		cout << "队列满";
	else
	{
		q.rear = (q.rear + 1) % MAX_SIZE;
		q.Subscript[q.rear] = t;
	}
	return q;
}

//删除队顶元素
queue DeQueue(queue q)
{
	if (Empty(q))
		cout << "空队列" << endl;
	else
		q.front = (q.front + 1) % MAX_SIZE;
	return q;
}