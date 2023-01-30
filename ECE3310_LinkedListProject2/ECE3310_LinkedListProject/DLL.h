#pragma once
#include "Node.h"
class DLL
{
public: 
	Node* first;
	Node* end;
	int listsize;
	DLL();
	bool empty();
	void insert(Node* newnode);
	void insert(Node* newnode, Node* pred);
	void erase(Node* node_to_be_deleted);
	void display();
	void display_rev();
	bool check_existance(Node* find);
	DLL* add(DLL &P1, DLL &P2);
	void sort();
	void simplify();
};