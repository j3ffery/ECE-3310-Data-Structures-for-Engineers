#include "Node.h"
#include "LList.h"
#include <iostream>
using namespace std;
LList::LList()
{
	head = new Node(0);
	first = head;
}
bool LList::empty()
{ 
	if (first == nullptr)
		return true;
	else
		return false; 
}
void LList::insert(Node* newnode, Node* pred)//assume pred is on the list already
{
	newnode->next = pred->next;
	pred->next = newnode;
}
void LList::insertfirst(Node* newnode)
{
	newnode->next = first;
	first = newnode;
}  
void LList::erase(Node* pred)
{
	Node* temp;
	temp = pred->next;
	pred->next = pred->next->next;
	temp->next = nullptr;
}
void LList::display()
{
	Node* current=head ->next;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << "\n";
}
bool LList::check_existance(Node* find)
{
	Node* current = head->next;
	while (current != nullptr)
	{
		if (current == find)
		{
			return true;
		}
		current = current->next;
	}
	
}