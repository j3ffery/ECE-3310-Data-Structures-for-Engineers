#pragma once
#include "Node.h"
class DLL
{
public: Node* first;
		int listsize;
		DLL();
		bool empty();
		void insert(Node* newnode);
		void insert(Node* newnode, Node* pred);
		void erase(Node* node_to_be_deleted);
		void display();
		bool check_existance(Node* find);
};