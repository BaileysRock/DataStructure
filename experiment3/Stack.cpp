#include"Stack.h"

struct stack* Init_stack()
{
	struct stack* s = new stack;
	s->flag = -1;
	s->next = nullptr;
	return s;
}

struct stack* Push_stack(int flag, stack* s)
{
	stack* s1 = new stack;
	s1->next = s->next;
	s->next = s1;
	s1->flag = flag;
	return s;
}

int Pop_stack(stack* s)
{
	stack* s1;
	s1 = s->next;
	s->next = s1->next;
	int m = s1->flag;
	delete s1;
	return m;
}

bool Is_empty(stack* s)
{
	if (s->next == nullptr)
		return true;
	else
		return false;
}

