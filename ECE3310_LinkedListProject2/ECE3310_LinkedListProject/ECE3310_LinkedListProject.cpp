#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

int main()
{
	Node* a1 = new Node(4, 0);
	Node* a2 = new Node(5, 6);
	Node* a3 = new Node(1, 3);
	Node* a4 = new Node(3, 2);
	Node* a5 = new Node(7, 3);
	Node* a6 = new Node(9, 7);
	Node* a7 = new Node(25, 1);

	Node* b1 = new Node(7, 0);
	Node* b2 = new Node(4, 6);
	Node* b3 = new Node(8, 5);
	Node* b4 = new Node(2, 9);
	Node* b5 = new Node(2, 69);

	DLL Poly1;
	DLL Poly2;
	DLL Poly3;
	
	cout << "Double Linked List 1 & 2:\n\n"; //Double Linked List 1 & 2
	Poly1.insert(a1);
	Poly1.insert(a2, a1);
	Poly1.insert(a3, a2);
	Poly1.insert(a4, a3);
	Poly1.insert(a5, a4);
	Poly1.insert(a6, a5);
	Poly1.insert(a7, a6);
	Poly2.insert(b1);
	Poly2.insert(b2, b1);
	Poly2.insert(b3, b2);
	Poly2.insert(b4, b3);
	Poly2.insert(b5, b4);
	cout << "P1(x) =  ";
	Poly1.display();
	cout << "P2(x) =  ";
	Poly2.display();
	
	cout << "Sorted:\n\n"; //sorted DLL1 & DLL2
	Poly1.sort();
	Poly2.sort();
	cout << "P1(x) =  ";
	Poly1.display();
	cout << "P2(x) =  ";
	Poly2.display();
	
	cout << "Simplifing:\n\n"; //simplified
	Poly1.simplify();
	Poly2.simplify();
	cout << "P1(x) =  ";
	Poly1.display();
	cout << "P2(x) =  ";
	Poly2.display();
	
	cout << "Adding P1 & P2:\n\n"; //adding
	Poly3.add(Poly1 , Poly2);
	cout << "P3(x) =  ";
	Poly3.display();
	
	cout << "P3 from greatest to least:\n\n"; //rev 
	cout << "P3(x) =  ";
	Poly3.display_rev();
	
}