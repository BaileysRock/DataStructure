#pragma once
#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include "Maze.h"
#include "stack.h"

//判断此时可以往何处移动
int Direction(Position p)
{
	if (Maze[p.y + 1][p.x + 1] != 0)
		return 1;
	else if (Maze[p.y + 1][p.x - 1] != 0)
		return 2;
	else if (Maze[p.y - 1][p.x - 1] != 0)
		return 3;
	else if (Maze[p.y - 1][p.x + 1] != 0)
		return 4;
	else if (Maze[p.y][p.x + 1] != 0)
		return 5;
	else if (Maze[p.y + 1][p.x] != 0)
		return 6;
	else if (Maze[p.y][p.x - 1] != 0)
		return 7;
	else if (Maze[p.y + 1][p.x] != 0)
		return 8;
	else
		return 0;

}

//返回挪动后的position
Position Move_Position(Position p, STACK stk, int Direction)
{
	switch (Direction)
	{
	case 5:			//右移
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x + 1,p.y };

	case 1:			//右下移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x + 1,p.y + 1 };

	case 6:			//下移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x ,p.y + 1 };

	case 2:			//左下移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x - 1,p.y + 1 };

	case 7:			//左移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x - 1,p.y };

	case 3:			//左上移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x - 1,p.y - 1 };

	case 8:			//上移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x,p.y - 1 };

	case 4:			//右上移动
		Maze[p.y][p.x] = 0;
		Push_Stack(p, stk);
		return { p.x + 1,p.y - 1 };

	case 0:
		Maze[p.y][p.x] = 0;
		return { 0,0 };

	}
}

//自动寻路函数
int Move(STACK stk)
{
	int v;
	Position position;
	position = Start;
	while (position.x != End.x || position.y != End.y)
	{
		v = Direction(position);

		if (v == 0 && stk->next == nullptr)
		{
			cout << "迷宫无解！" << endl;
			return 0;
		}
		else if (v == 0 && stk->next != nullptr)
		{
			Maze[position.y][position.x] = 0;
			position = Pop_Stack(position, stk);
		}
		else
		{
			position = Move_Position(position, stk, v);
		}
	}
	if (position.x == End.x && position.y == End.y)
	{
		position = Move_Position(position, stk, v);
		cout << "已找到出口！" << endl;
		return 1;
	}
}

//对路径优化
//第一个函数判断两个结点是否靠近
//第二个函数进行节点的变更
int Judge(STACK stk1, STACK stk2)
{
	if (stk1->position.x == stk2->position.x + 1 && stk1->position.y == stk2->position.y)
		return 1;
	else if (stk1->position.x == stk2->position.x + 1 && stk1->position.y == stk2->position.y + 1)
		return 1;
	else if (stk1->position.x == stk2->position.x + 1 && stk1->position.y == stk2->position.y - 1)
		return 1;
	else if (stk1->position.x == stk2->position.x && stk1->position.y == stk2->position.y - 1)
		return 1;
	else if (stk1->position.x == stk2->position.x && stk1->position.y == stk2->position.y + 1)
		return 1;
	else if (stk1->position.x == stk2->position.x - 1 && stk1->position.y == stk2->position.y - 1)
		return 1;
	else if (stk1->position.x == stk2->position.x - 1 && stk1->position.y == stk2->position.y + 1)
		return 1;
	else if (stk1->position.x == stk2->position.x - 1 && stk1->position.y == stk2->position.y)
		return 1;
	else
		return 0;
}
STACK Optimization(STACK stk)
{
	STACK s, s1, s2, s3;
	s = stk;
	s1 = stk;
	s2 = stk;
	while (s->next->next != nullptr)
	{
		s = s->next;
		while (s1->next != nullptr)
		{
			s1 = s1->next;

			if (s != s1 && Judge(s, s1) && s->next != s1)
			{
				s2 = s->next;
				s->next = s1;
				while (s2->next != s1)
				{
					s3 = s2->next;
					delete s2;
					s2 = s3;
				}
				delete s2;
			}
		}
		s1 = s->next;
	}
	return stk;

}

//对栈反序输出 输出路径
void Show_Road(STACK stk)
{
	int i = 0;
	stk = Optimization(stk);
	STACK p1 = stk;
	STACK p = stk->next;
	if (p->next != nullptr)
	{
		while (p->next != nullptr)
		{
			STACK p0 = p;
			while (p0->next->next != nullptr)
			{
				p0 = p0->next;
			}
			p1->next = p0->next;

			p0->next = nullptr;
			p1 = p1->next;

		}
		if (p->next == nullptr)
			p1->next = p;
	}
	p = stk;
	while (p->next != nullptr)
	{

		p = p->next;
		cout << "(" << p->position.x << ","
			<< p->position.y << ")" << endl;
		i++;
	}
	cout << "共" << i << "步！";
}

void Delete(STACK stk)
{
	STACK s;
	if (stk != nullptr)
	{
		while (stk->next != nullptr)
		{
			s = stk;
			stk = stk->next;
			delete s;
		}

		s = stk;
		delete s;

	}
}
#endif