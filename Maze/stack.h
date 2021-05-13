#pragma once
#ifndef STACK_H
#define STACK_H
#include "Maze.h"

typedef struct Stack* STACK;

//����ͷ���
STACK Head_Node(STACK stk)
{
	stk = new Stack;
	stk->position = { -1,-1 };
	stk->next = nullptr;
	return stk;
}

//��ջ
void Push_Stack(Position p, STACK stk)
{
	STACK s;
	s = stk->next;
	stk->next = new Stack;
	stk->next->next = s;
	stk->next->position = p;
}

//��ջ�����ص�ǰλ��
Position Pop_Stack(Position p, STACK stk)
{
	STACK s;
	Position p1;
	s = stk->next;
	stk->next = stk->next->next;
	p1 = s->position;
	delete s;
	return p1;
}


#endif 