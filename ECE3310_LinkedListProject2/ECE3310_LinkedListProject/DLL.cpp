#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
	first = nullptr;
	end = nullptr;
	listsize = 0;
}
bool DLL::empty()
{
	if (first == nullptr)
		return true;
	else
		return false;
}
void DLL::insert(Node* newnode) {
	if (first == nullptr)
	{
		first = newnode;
	}
	else
	{
		first->prev = newnode;
		newnode->next = first;
		first = newnode;
	}
	listsize++;
}
void DLL::insert(Node* newnode, Node* pred)
{
	if (pred->next != nullptr)
	{
		pred->next->prev = newnode;
		newnode->next = pred->next;
	}
	if (pred->next == nullptr)
	{
		end = newnode;
		newnode->next = nullptr;
	}
	pred->next = newnode;
	newnode->prev = pred;
	listsize++;
}
void DLL::erase(Node* n) {
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
		current = first;
		do
		{
			if (current->exp == 0) 
			{
				cout << current->coe;
			}
			else if (current->exp == 1)
			{
				cout << current->coe << "x";
			}
			else
			{
				cout << current->coe << "x^" << current->exp;
			}
			if (current->next != nullptr)
				cout << " + ";
			current = current->next;
		} while (current != nullptr);
		cout << "\n";
	}
	else
	{
		cout << "\n The list is empty\n";
	}
	cout << "\n";
}
void DLL::display_rev()
{
	Node* current;
	if (first != nullptr)
	{
		current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		while (current != nullptr)
		{
			if (current->exp == 0)
			{
				cout << current->coe;
			}
			else if (current->exp == 1)
			{
				cout << current->coe << "x";
			}
			else
			{
				cout << current->coe << "x^" << current->exp;
			}
			if (current->prev != nullptr)
				cout << " + ";
			current = current->prev;
		}	
		cout << "\n";
	}
	else
	{
		cout << "\n The list is empty\n";
	}
	cout << "\n";
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
DLL* DLL::add(DLL &p1, DLL &p2)
{
	bool n1 = false;
	bool n2 = false;
	Node* pred = p1.first;
	Node* newnode = p2.first;
	Node* P1 = p1.first;
	Node* P2 = p2.first;	

	while (n1 != true || n2 != true)
	{
		pred = newnode;
		
		if (P1->exp < P2->exp)
		{
			if (P1 != p1.end)
			{
				//cout << "1";
				newnode = P1;
				P1 = P1->next;
			}
			else if (P1 == p1.end && n1 == false)
			{
				//cout << "2";
				newnode = P1;
				n1 = true;
			}
			else
			{
				//cout << "3";
				if (P2 == p2.end)
				{
					newnode = P2;
					n2 = true;
				}
				else
				{
					newnode = P2;
					P2 = P2->next;
				}
			}
			
		}
		else if (P2->exp < P1->exp)
		{
			if (P2 != p2.end)
			{
				//cout << "4";
				newnode = P2;
				P2 = P2->next;
			}
			else if (P2 == p2.end && n2 == false)
			{
				//cout << "5";
				newnode = P2;
				n2 = true;
			}
			else
			{
				//cout << "6";
				if (P1 == p1.end)
				{
					newnode = P1;
					n1 = true;
				}
				else
				{
					newnode = P1;
					P1 = P1->next;
				}
			}
		}
		else if (P2->exp == P1->exp)
		{
			//cout << "7";
			newnode = P1;
			newnode->coe = P1->coe + P2->coe;
			P1 = P1->next;
			P2 = P2->next;
		}
		
		newnode->next = nullptr;
		newnode->prev = nullptr;

		if (first == nullptr)
		{
			//cout << "first";
			first = newnode;
			listsize++;
		}
		else
		{
			//cout << "next";
			pred->next = newnode;
			newnode->prev = pred;
			listsize++;
		}	
	}


	return 0;
}
void DLL::sort()
{
	bool done=true;
	Node* current;
	current = first;
	if (first != nullptr)
	{
		while (current != nullptr)
		{
			if (current->next != nullptr && current->exp > current->next->exp)
			{
				done = false;
				Node* Node1 = current;
				Node* Node2 = current->next;
				if (Node2->next == nullptr) 
				{
					end = Node1;
				}
				Node* temp;
				temp = Node1->next;
				Node1->next = Node2->next;
				Node2->next = temp;

				if (Node1->next != nullptr)
					Node1->next->prev = Node1;
				if (Node2->next != nullptr)
					Node2->next->prev = Node2;

				temp = Node1->prev;
				Node1->prev = Node2->prev;
				Node2->prev = temp;

				if (Node1->prev != nullptr)
					Node1->prev->next = Node1;
				if (Node2->prev != nullptr)
					Node2->prev->next = Node2;

			}
			current = current->next;
		}
	}
	if (done == false)
		sort();
}
void DLL::simplify()
{
	Node* n;
	Node* p;
	p = first;
	n = p->next;
	while (p->next != nullptr)
	{
		//cout << "ran";
		if (p->exp == p->next->exp)
		{
			//cout << "simp";
			n = p->next;
			p->coe = p->coe + n->coe;
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
		p = p->next;
	}
	
}
