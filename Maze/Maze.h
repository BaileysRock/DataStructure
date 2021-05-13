#pragma once
#ifndef Maze_H
#define Maze_H
#include <iostream>
#define Max_Size 50

//对迷宫赋值为0
int Maze[Max_Size][Max_Size]{ 0 };

using namespace std;

typedef int ElementType;

struct Position
{
	ElementType x;
	ElementType y;
};

Position Start, End;

struct Stack
{
	Position position;
	struct Stack* next;
};

//输入位置
Position Location()
{
	int x, y;
	cin >> x >> y;
	return Position{ x,y };
}

//对迷宫写入
//读取当前位置以及结束位置
void Create_Maze()
{
	int Width, Height;
	cout << "请输入迷宫大小( Width  Height ):" << endl;
	cin >> Width >> Height;
	cout << "请输入迷宫(0表示路障 1表示道路):" << endl;
	for (int i = 1; i <= Height; i++)
	{
		for (int n = 1; n <= Width; n++)
		{
			cin >> *(*(Maze + i) + n);
		}
	}
	cout << "请输入起点位置:" << endl;
	Start = Location();
	cout << "请输入终点位置:" << endl;
	End = Location();
}

#endif // !Maze_H