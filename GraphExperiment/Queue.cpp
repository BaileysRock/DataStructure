#pragma once
#include"Queue.h"

//��ʼ������
queue Init_Queue()
{
	queue q;
	q.front = MAX_SIZE - 1;
	q.rear = MAX_SIZE - 1;
	return q;

}
//�ж϶����Ƿ�Ϊ��
bool Empty(queue q)
{
	if (q.rear == q.front)
		return true;
	else
		return false;
}
//���ض��е���Ԫ��
int Front(queue q)
{
	return (q.Subscript[(q.front + 1) % MAX_SIZE]);
}
//���
queue EnQueue(int t, queue q)
{
	if ((q.rear + 1) % MAX_SIZE == q.front)
		cout << "������";
	else
	{
		q.rear = (q.rear + 1) % MAX_SIZE;
		q.Subscript[q.rear] = t;
	}
	return q;
}

//ɾ���Ӷ�Ԫ��
queue DeQueue(queue q)
{
	if (Empty(q))
		cout << "�ն���" << endl;
	else
		q.front = (q.front + 1) % MAX_SIZE;
	return q;
}