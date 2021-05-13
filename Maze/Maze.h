#pragma once
#ifndef Maze_H
#define Maze_H
#include <iostream>
#define Max_Size 50

//���Թ���ֵΪ0
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

//����λ��
Position Location()
{
	int x, y;
	cin >> x >> y;
	return Position{ x,y };
}

//���Թ�д��
//��ȡ��ǰλ���Լ�����λ��
void Create_Maze()
{
	int Width, Height;
	cout << "�������Թ���С( Width  Height ):" << endl;
	cin >> Width >> Height;
	cout << "�������Թ�(0��ʾ·�� 1��ʾ��·):" << endl;
	for (int i = 1; i <= Height; i++)
	{
		for (int n = 1; n <= Width; n++)
		{
			cin >> *(*(Maze + i) + n);
		}
	}
	cout << "���������λ��:" << endl;
	Start = Location();
	cout << "�������յ�λ��:" << endl;
	End = Location();
}

#endif // !Maze_H