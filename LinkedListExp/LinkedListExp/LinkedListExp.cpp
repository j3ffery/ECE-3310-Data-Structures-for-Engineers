#include <iostream>
using namespace std;
#include "Node.h"
#include "LList.h"
int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	LList mylist;
	if (mylist.empty() == true)
		cout << "The list is empty now\n";
	mylist.insert(n1, mylist.head);
	mylist.insert(n2, n1);
	mylist.insert(n3, n2);
	mylist.insert(n4, n3);
	mylist.display();
	mylist.erase(n1);
	mylist.display();
	mylist.erase(mylist.head);
	mylist.display();
	if (mylist.check_existance(n3) == true)
		cout << "The node you are looking for exists.\n";
	else
		cout << "The node you are looking for does not exists.\n";

	if (mylist.check_existance(n2) == true)
		cout << "The node you are looking for exists.\n";
	else
		cout << "The node you are looking for does not exists.\n";

	if (mylist.check_existance(n4) == true)
		cout << "The node you are looking for exists.\n";
	else
		cout << "The node you are looking for does not exists.\n";

	if (mylist.check_existance(n1) == true)
		cout << "The node you are looking for exists.\n";
	else
		cout << "The node you are looking for does not exists.\n";
}
 