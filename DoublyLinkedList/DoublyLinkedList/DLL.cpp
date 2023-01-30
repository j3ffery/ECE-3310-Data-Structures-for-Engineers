#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
	first = nullptr;
	listsize = 0;
}
bool DLL::empty()
{
	if (first == nullptr)
		return true;
	else
		return false;
}

void DLL::insert(Node * newnode) {
	if (first == nullptr)
		first = newnode;
	else
	{
		first->prev = newnode;
		newnode->next = first;
		first = newnode;
	}
	listsize++;
}
void DLL::insert(Node * newnode, Node * pred)
{
	if (pred->next != nullptr)
	{
		pred->next->prev = newnode;
		newnode->next = pred->next;
	}
	pred->next = newnode;
	newnode->prev = pred;
	listsize++;
}
void DLL::erase(Node * n) {
	if (n->prev == nullptr)
	{
		first = n->next;
	}
	else
	{
		n->prev->next = n->next;
	}
	if (n->next == nullptr)
	{
		n->prev->next = nullptr;
	}
	else
	{
		n->next->prev = n->prev;
	}
	n->prev = nullptr;
	n->next = nullptr;
	listsize--;
}
void DLL::display()
{
	Node* current;
	if (first != nullptr)
	{
		cout << "\n";
		current = first;
		do
		{
			cout << current->data << "  ";
			current = current->next;
		} while (current != nullptr);
		cout << "\n";
	}
	else
	{
		cout << "\n The list is empty\n";
	}
}
bool DLL::check_existance(Node* find)
{
	Node* current;
	if (first != nullptr)
	{
		cout << "\n";
		current = first;
		while (current != nullptr)
		{
			if (current == find)
				return true;
			current = current->next;
		} 
	}
}