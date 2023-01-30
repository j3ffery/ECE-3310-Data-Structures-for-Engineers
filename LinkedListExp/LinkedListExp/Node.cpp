#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
Node::Node(int d) //We only have this constructor declared in the Node.h file
{
	data = d;
	next = nullptr; //null character indicates the node is not linked to any other node initially 
}

