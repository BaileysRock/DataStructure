#include"Tree.h"

int main()
{
	TREE tree;
	//递归输入
	tree = Input_Tree_Recursive();



	//交换二叉树所有结点
	//Exchange(tree);
	//Level_Order_Traversal_Not_Recursive(tree);

	//非递归输入
	//tree = Input_Tree_Not_Recursive();

	//结点数和二叉树的高度
	cout << "树的结点有" << Count(tree) << "个!" << endl;
	cout << "二叉树的高度为:" << Height(tree) << "!" << endl;


	//递归遍历

	//先序遍历
	cout << "先序遍历:" << endl;
	Preorder_Traversal_Recursive(tree);
	cout << endl;
	//中序遍历
	cout << "中序遍历:" << endl;
	Inorder_Traversal_Recursive(tree);
	cout << endl;
	//后序遍历
	cout << "后序遍历:" << endl;
	Postorder_Traversal_Recursive(tree);
	cout << endl;
	//先序叶子
	cout << "先序输出叶子结点" << endl;
	Preorder_Traversal_Recursive_leaf(tree);
	cout << endl;
	//非递归遍历

	//先序遍历
	//先序
	Preorder_Traversal_Not_Recursive(tree);
	//中序
	Inorder_Traversal_Not_Recursive(tree);
	//后序
	Postorder_Traversal_Not_Recursive(tree);

	//层序遍历
	Level_Order_Traversal_Not_Recursive(tree);
	//层序遍历_栈模拟队列
	Level_Order_Traversal_Not_Recursive_stack(tree);

	//树的复制
	//TREE tree_copy = Copy_Tree(tree);
	//Preorder_Traversal_Recursive(tree_copy);

	//判断是否是完全二叉树
	Is_Complete_Binary_Tree(tree);

	//求公共父节点
	//TREE t = Common_parent_node(tree);
	//if (t)
	//	cout << t->data;


	TREE t = Common_parent_optimize(tree);
	cout << t->data;
	//二叉树的删除
	Delete(tree);

	return 0;
}