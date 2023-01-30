#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List scores;
	scores.insert(3, 0);
	scores.insert(2, 1);
	scores.insert(6, 2);
	scores.insert(9, 3);
	scores.insert(1, 4);
	scores.insert(7, 5);
	scores.insert(8, 6);
	scores.display();
	scores.insert(5, 1);
	scores.display();
	scores.erase(2);
	scores.display();
	scores.erase(0);
	scores.display();
	scores.check_existance(9);
	scores.check_existance(4);
}
