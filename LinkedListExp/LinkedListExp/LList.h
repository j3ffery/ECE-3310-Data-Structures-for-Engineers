#pragma once
#include "Node.h" //make sure you include the .h file
class LList
{
public:
	Node* first;
	Node* head;
	LList();
	bool empty();
	void insert(Node* newnode, Node* pred);
	void insertfirst(Node* newnode); //See discussion below
	void erase(Node* pred);
	void display();
	bool check_existance(Node* find);
};