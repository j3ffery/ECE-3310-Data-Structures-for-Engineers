#pragma once
#define CAPACITY 10
typedef int Element_Type;

class List
{
    int list_size;
    Element_Type dataArray[CAPACITY];
public:
    List(); //contructor
    bool empty();
    void insert(Element_Type item, int pos);
    void erase(int pos);
    void display();
    void check_existance(Element_Type item);
};