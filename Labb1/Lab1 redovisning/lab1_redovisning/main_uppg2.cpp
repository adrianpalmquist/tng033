
#include <iostream>
#include <iomanip>
#include <fstream>
#include "diver.h"

using namespace std;

/******************************
* 1. Functions declarations   *
*******************************/

//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log);


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n);


//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n);


/******************************
* 2. Main function            *
*******************************/



int main ()
{
    const int NR_OF_DIVERS = 50;
    string file_name;

    Diver DB[NR_OF_DIVERS];
    int howMany = 0;
    string answr;

    cout << "Read from file?  Y/N" << endl;
    cin >> answr;



    ofstream utfil("log.txt");
    if(answr == "y")
    {
        cout << "Enter file name: ";
        cin >> file_name;

        ifstream infil(file_name);

        if ( !infil )
        {
            cout << "Data file not found!" << endl;
            return 0;
        }

        cout << "Reading data from file..." << endl;

        howMany = read_divers(infil, DB, NR_OF_DIVERS, utfil);
    }
    else
    {
        cout << "Enter data: " << endl;
        howMany = read_divers(cin, DB, NR_OF_DIVERS, utfil);
    }

    for (int i = 0; i < howMany; i++)
    {
        calculate_final_score(DB[i]);
    }

    sort_divers(DB, howMany);

    display(DB, howMany);

    return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log)
{
    int counter = 0;
    int errcount = 0;

    log << "The following divers have incorrect data: " << endl;
    log << "------------------------------------------" << endl;

    while (counter < n && (in >> V[counter]))
    {
        if (V[counter].difficulty > 0){
            ++counter;
        }
        else
        {
            ++errcount;
            log << V[counter].name;
            log << ", Line: " << counter << endl;
        }
    }

    if (errcount == 0)
    {
        log << "No incorrect data!" << endl;
    }

    return counter;
}


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n)
{
    //Display header
    cout << "Diver results:" << endl;
    cout << "=======================================" << endl;
    string num;

    //Display sorted divers
    for (int i = 0; i < n; i++)
    {
        cout << setw(1) << left << i+1 << ". " << V[i];
    }
    cout << endl;
}

//To be used by sort function
void swap(Diver& a, Diver& b)
{
    Diver temp = a;
    a = b;
    b = temp;
}


//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n)
{
    Diver temp;

    //sort
    for (int pass = 0; pass <= n - 2; pass++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (V[ i ] < V[ i + 1 ])
            {
                swap(V[i+1], V[i]);
            }
        }
    }
}



