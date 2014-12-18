//
//  main.cpp
//  ex1
//
//  Created by Adrian Palmquist on 2014-12-15.
//  Copyright (c) 2014 Adrian Palmquist. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, string> par_is;
typedef pair<string, int> par_si;
typedef vector<par_is> vecPar;
typedef map<string, int> mp;
typedef istream_iterator<string> is_i;


//Jämför
bool comp(par_is i, par_is j)
{
    return (i.first > j.first);
}

//Skriv ut
void print(vecPar &par_vec, mp &word, int counter)
{
    mp::iterator it;
    
    vecPar::iterator it_vec;
    
    cout << "Sortering i bokstavsordning:" << endl << endl;
    
    for_each(word.begin(), word.end(), [&par_vec](par_si p) {cout << p.first << ": " << p.second << endl;
        par_is pr (p.second,p.first);
        par_vec.push_back(pr);});
    
    
    cout << endl;
    
    cout << "Sortering efter antal ord i texten:" << endl;
    
    sort(par_vec.begin(),par_vec.end(), comp);
    
    for_each(par_vec.begin(), par_vec.end(), [](par_is p) {cout << p.second << ": " << p.first << endl;});
    
    
    
    cout << endl << endl << "Counter: " << counter << endl;
}


int read(mp &word)
{
    string file_name;
    string s;
    string temp;
    
    int counter=0;
    
    cout << "Enter file name: ";
    cin >> file_name;
    
    
    ifstream infil(file_name);
    
    if (!infil.is_open())
    {
        cout << "Failed to open " << file_name << endl;
        return 0;
    }
    
    is_i in_it(infil);
    is_i in_end;
    mp::iterator it;
    
    while (infil>>s) {
        
        s.resize(remove_if(s.begin(), s.end(),[](char x){return !isalnum(x) && !isspace(x);})-s.begin()); //Check if character is alphanumeric
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        //it = word.find(s);
        /*
        if (it != word.end())
        {
            word[s] = it->second + 1;
        }
        else
        {*/
            word[s]++;
        //}
        
        counter++;
        s = "";
    }
    
    infil.close();
    return counter;
}



int main()
{
    mp word;
    vecPar par_vec;
    
    print(par_vec, word, read(word));
    
    return 0;
}
