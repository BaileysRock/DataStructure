#include"Maze.h"
#include"stack.h"
#include"Search.h"
int main()
{
	Create_Maze();
	STACK stack = nullptr;
	stack = Head_Node(stack);
	if (Move(stack))
		Show_Road(stack);
	Delete(stack);
	return 0;

}