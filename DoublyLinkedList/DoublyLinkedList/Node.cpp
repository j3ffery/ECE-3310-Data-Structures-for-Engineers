#include <iostream>
using namespace std;
#include "Node.h"
Node::Node(int d)
{
	data = d;
	next = nullptr;
	prev = nullptr;
}