#include <iostream>
using namespace std;

int main()
{
    double temp_high, temp_low, temp_avg;
    cout << "What is the highest temp?";
    cin >> temp_high;
    cout << "What was the lowest temp?";
    cin >> temp_low;

    temp_avg = (temp_high + temp_low) / 2;

    cout << "The Temperature average is " << temp_avg << "degrees Fahrenheit.";
}
