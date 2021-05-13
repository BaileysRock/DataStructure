#pragma once
#ifndef STACK_H
#define STACK_H
#include "Maze.h"

typedef struct Stack* STACK;

//设立头结点
STACK Head_Node(STACK stk)
{
	stk = new Stack;
	stk->position = { -1,-1 };
	stk->next = nullptr;
	return stk;
}

//入栈
void Push_Stack(Position p, STACK stk)
{
	STACK s;
	s = stk->next;
	stk->next = new Stack;
	stk->next->next = s;
	stk->next->position = p;
}

//出栈并返回当前位置
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