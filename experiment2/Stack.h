#pragma once
#ifndef STACK_H
#define STACK_H
#include"Tree.h"


struct stack
{
	TREE data;
	struct stack* next;
};

typedef struct stack* STACK;

STACK Init_Stack()
{
	STACK s1 = new stack;
	s1->data = nullptr;
	s1->next = nullptr;
	return s1;
}

STACK Push_Stack(STACK s, TREE m)
{
	STACK s1;
	s1 = new stack;
	s1->data = m;
	s1->next = s->next;
	s->next = s1;
	return s;
}
TREE Pop_Stack(STACK s)
{

	if (s->next != nullptr)
	{
		TREE m;
		STACK s1;
		s1 = s->next;
		s->next = s->next->next;
		m = s1->data;
		delete s1;
		return m;
	}
}
bool Is_empty(STACK s)
{
	if (s->next == nullptr)
		return true;
	else
		return false;
}
TREE Top_Stack(STACK s)
{
	if (s->next)
		return s->next->data;
}

#endif