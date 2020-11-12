#include"Tree.h"

int main()
{
	TREE tree;
	//�ݹ�����
	tree = Input_Tree_Recursive();



	//�������������н��
	//Exchange(tree);
	//Level_Order_Traversal_Not_Recursive(tree);

	//�ǵݹ�����
	//tree = Input_Tree_Not_Recursive();

	//������Ͷ������ĸ߶�
	cout << "���Ľ����" << Count(tree) << "��!" << endl;
	cout << "�������ĸ߶�Ϊ:" << Height(tree) << "!" << endl;


	//�ݹ����

	//�������
	cout << "�������:" << endl;
	Preorder_Traversal_Recursive(tree);
	cout << endl;
	//�������
	cout << "�������:" << endl;
	Inorder_Traversal_Recursive(tree);
	cout << endl;
	//�������
	cout << "�������:" << endl;
	Postorder_Traversal_Recursive(tree);
	cout << endl;
	//����Ҷ��
	cout << "�������Ҷ�ӽ��" << endl;
	Preorder_Traversal_Recursive_leaf(tree);
	cout << endl;
	//�ǵݹ����

	//�������
	//����
	Preorder_Traversal_Not_Recursive(tree);
	//����
	Inorder_Traversal_Not_Recursive(tree);
	//����
	Postorder_Traversal_Not_Recursive(tree);

	//�������
	Level_Order_Traversal_Not_Recursive(tree);
	//�������_ջģ�����
	Level_Order_Traversal_Not_Recursive_stack(tree);

	//���ĸ���
	//TREE tree_copy = Copy_Tree(tree);
	//Preorder_Traversal_Recursive(tree_copy);

	//�ж��Ƿ�����ȫ������
	Is_Complete_Binary_Tree(tree);

	//�󹫹����ڵ�
	//TREE t = Common_parent_node(tree);
	//if (t)
	//	cout << t->data;


	TREE t = Common_parent_optimize(tree);
	cout << t->data;
	//��������ɾ��
	Delete(tree);

	return 0;
}