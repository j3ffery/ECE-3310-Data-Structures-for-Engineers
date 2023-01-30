#include <iostream>
#include <string>
using namespace std;
#include "Class_ECE3310.h"
void Class_ECE3310::set(int index, StudentScore s)
{
	data[index].name = s.name;
	data[index].score = s.score;
}

StudentScore Class_ECE3310::getStudentData(int index)
{
	return data[index];
}

void Class_ECE3310::display()
{
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << data[i].name << ": " << data[i].score << '\n';
	}
	cout << "\n";
}

