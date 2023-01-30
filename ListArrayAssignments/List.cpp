#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	list_size = 0;
}

bool List::empty()
{
    if (list_size == 0)
        return true;
    else
        return false;
}

void List::display()
{
    for (int i = 0; i < list_size; i++)
        cout << dataArray[i] << ", ";
    cout << "\n";
}

void List::insert(Element_Type item, int pos)
{
    if ((pos < 0) || (pos > list_size)) //array index starts at 0
    {
        cout << "error position specified\n";
    }
    else
    {
        list_size++;
        if (list_size == 1)  //the list is currently empty
            dataArray[0] = item;
        else
        {
            if (list_size == pos + 1) //the item is going to be inserted as the last item
                dataArray[pos] = item;
            else
            {
                for (int i = list_size - 1; i > pos; i--)
                {
                    dataArray[i] = dataArray[i - 1]; //shifting to make room for the inserted item
                }
                dataArray[pos] = item; //insert the item
            }
        }
    }
}

void List::erase(int pos)
{
    if ((pos < 0) || (pos > list_size))
        cout << "wrong position\n";
    else
    {
        if (list_size > 0)
        {
            for (int i = pos; i < list_size; i++)
            {
                dataArray[i] = dataArray[i + 1];
            }
            list_size--;
        }
    }
}

void List::check_existance(Element_Type item)
{
    bool found = false;
    int i = 0;
    
    while (found == false & i < list_size)
    {
        if (dataArray[i] == item)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found == true)
        cout << "The number " << item << " is at position " << i + 1 << '\n';
    else
        cout << "The number " << item << " is at position " << 0 << '\n';
}   