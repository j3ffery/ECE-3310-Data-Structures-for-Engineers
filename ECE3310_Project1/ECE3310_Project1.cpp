#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;
/*
1. use structure to store state name, population, year
2. create an array ADT for 2020, where each element is an object
3. calculate mean of population for 2020 recursicely
*/

//Structure
struct PD //Population Data
{
    string state;
    double population;
    double year;
};

double findMean(struct PD* census2020, int arrSize)
{
    if (arrSize == 1)
    {
        return census2020[arrSize - 1].population;
    }
    else
        return ((findMean(census2020, arrSize - 1) * (arrSize - 1) + census2020[arrSize - 1].population) / arrSize);
}

int main()
{  
   
    ifstream in_state;
    ifstream in_population;
    ofstream out_stream;
    
    //array
    PD census2020[51];

    in_state.open("datainstate.txt");
    in_population.open("datainpopulation.txt");
    if (in_state.fail() || in_population.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    cout << setprecision(12);
    for (int i = 0; i < 51; i++)
    {
        in_state >> census2020[i].state;
        cout << census2020[i].state << '\n';
        in_population >> census2020[i].population;
        cout << census2020[i].population << '\n' << '\n';
    }

    cout << "This is the mean of the population for all states in year 2020: " << findMean(census2020, 51) << '\n';
  
}
