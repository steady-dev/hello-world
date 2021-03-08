#include <iostream>
#define EMPTY 0
using namespace std;

struct Node
{
	int data;
	Node* Left;
	Node* Right;
};

void insert(Node** Root, int data)
{
	if (*Root == NULL)
	{
		*Root = new Node;
		(*Root)->data = data;
		(*Root)->Left = NULL;
		(*Root)->Right = NULL;
	}
	else if ((*Root)->data > data)
		insert(&(*Root)->Left, data);
	else if ((*Root)->data < data)
		insert(&(*Root)->Right, data);
	else
		cout << "�ش� ���� �����մϴ�." << endl;
}


Node* Find(Node** Root)
{
	if ((*Root)->Left == NULL)
	{
		Node* Tmp = *Root;
		*Root = (*Root)->Right;
		return Tmp;
	}
	return 	Find(&(*Root)->Left);
}

void NextLink(Node** Root)
{
	if ((*Root)->Left != NULL && (*Root)->Right != NULL)
	{
		Node* Tmp = *Root;
		*Root = Find(&(*Root)->Right);
	}
	else if ((*Root)->Left != NULL)
	{
		*Root = (*Root)->Left;
	}
	else if ((*Root)->Right != NULL)
	{
		*Root = (*Root)->Right;
	}
	else
		return;
}

void Delete(Node** Root, int data)
{
	if (*Root == NULL)
	{
		cout << "�ش� �����Ͱ� �����ϴ�." << endl;
		return;
	}
	else if ((*Root)->data > data)
		Delete(&(*Root)->Left, data);
	else if ((*Root)->data < data)
		Delete(&(*Root)->Right, data);
	else
	{
		Node* tmp = *Root;
		NextLink(Root);
		(*Root)->Left = tmp->Left;
		(*Root)->Right = tmp->Right;
		delete tmp;
	}
}

void Search(Node** Root, int index)
{
	if (*Root == NULL)
	{
		cout << "�ش� ������ �����ϴ�." << endl;
		return;
	}
	else if ((*Root)->data == index)
	{
		cout << "���� " << index << " �� ���� �մϴ�" << endl;
		return;
	}
	else if ((*Root)->data > index)
		Search(&(*Root)->Left, index);
	else if ((*Root)->data < index)
		Search(&(*Root)->Right, index);
}

void PreOrder(Node** Root)
{
	if (*Root)
	{
		cout << (*Root)->data << ",";
		PreOrder(&(*Root)->Left);
		PreOrder(&(*Root)->Right);
	}
}
void InOrder(Node** Root)
{
	if (*Root)
	{
		InOrder(&(*Root)->Left);
		cout << (*Root)->data << ",";
		InOrder(&(*Root)->Right);
	}
}
void PostOrder(Node** Root)
{
	if (*Root)
	{
		PostOrder(&(*Root)->Left);
		PostOrder(&(*Root)->Right);
		cout << (*Root)->data << ",";
	}
}

void main()
{
	Node* Root = NULL;
	insert(&Root, 10);
	insert(&Root, 20);
	insert(&Root, 5);
	insert(&Root, 15);
	insert(&Root, 25);
	insert(&Root, 22);
	insert(&Root, 23);
	Delete(&Root, 20);
	Search(&Root, 25);
	PreOrder(&Root);
	cout << "\b " << endl;
	InOrder(&Root);
	cout << "\b " << endl;
	PostOrder(&Root);
	cout << "\b " << endl;
};
