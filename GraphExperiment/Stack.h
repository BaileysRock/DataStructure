#pragma once
#ifndef STACK_H
#define STACK_H

using namespace std;
struct stack
{
	int flag;
	struct stack* next;
};

struct stack* Init_stack();
struct stack* Push_stack(int flag, stack* s);
int Pop_stack(stack* s);
bool Is_empty(stack* s);
#endif