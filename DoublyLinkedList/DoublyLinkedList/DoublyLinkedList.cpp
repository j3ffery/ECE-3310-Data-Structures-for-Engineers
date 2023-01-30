#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"
int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	DLL mylist;
	if (mylist.empty() == true)
		cout << "\n The list is now empty\n";
	mylist.insert(n1);
	mylist.display();
	mylist.insert(n2, n1);
	mylist.insert(n3, n2);
	mylist.display();
	mylist.insert(n4);
	mylist.display();
	mylist.erase(n2);
	mylist.display();
	mylist.erase(n4);
	mylist.display();
	if (mylist.check_existance(n1) == true)
		cout << "The node exist\n";
	else
		cout << "The node dose not exist\n";
	if (mylist.check_existance(n2) == true)
		cout << "The node exist\n";
	else
		cout << "The node dose not exist\n";
	if(mylist.check_existance(n3) == true)
		cout << "The node exist\n";
	else
		cout << "The node dose not exist\n";
	if (mylist.check_existance(n4) == true)
		cout << "The node exist\n";
	else
		cout << "The node dose not exist\n";
}