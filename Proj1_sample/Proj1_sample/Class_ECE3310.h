#pragma once
#include "StudentScore.h"
using namespace std;
#define data_size 5
class Class_ECE3310
{
private:
	int size = data_size;
	StudentScore data[data_size];
public:
	void set(int, StudentScore);
	StudentScore getStudentData(int);
	void display();
};

