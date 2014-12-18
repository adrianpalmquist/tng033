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

typedef pair<int, string> par;
typedef vector<par> vecPar;
typedef map<string, int> mp;


//Jämför
bool comp(par i, par j)
{
    return (i.first > j.first);
}

void printPair(map<string, int>::iterator it)
{
    cout << "Word: " << it->first << endl;
    cout << "Num: " << it->second << endl;
}


//Skriv ut
void print(vecPar &par_vec, mp &word, int counter)
{
    mp::iterator it;
    
    vecPar::iterator it_vec;
    
    cout << "Sortering i bokstavsordning" << endl;
    
    cout << endl;
    
    /*
    for(it = word.begin(); it!=word.end(); it++)
    {
        cout << left << setw(10) << it->first << right << setw(60) << it->second<<endl;
        
        //cout << "Key: " << it->first << endl << "Values:" << endl;
        
        //cout << it_vec->first << " " << it_vec->second<<endl;
        
        pair <int,string> p (it->second,it->first);
        
        par_vec.push_back(p);
    }
    */
    
    
    map<string,int>::iterator it_begin = word.begin();
    map<string,int>::iterator it_end = word.end();
    
    
    //for_each(it_begin, it_end, printPair);
    
    for (map<string,int>::iterator it = word.begin(); it != word.end(); it++)
    printPair(it);
    
    
    cout << endl;
    
    cout << "Sortering efter antal ord i texten" << endl;
    
    sort(par_vec.begin(),par_vec.end(), comp);//sorterar vektor
    
    /*
    for(it_vec=par_vec.begin(); it_vec != par_vec.end(); it_vec++) //Skriv
    {
        cout << left << setw(10) << it_vec->second << right << setw(60)<< it_vec->first <<endl;
    }
     */
    
    
    cout << endl << endl << "counter: " << counter << endl;
}


//Läs in
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
    
    istream_iterator<string> in_it(infil);
    istream_iterator<string> in_end;
    mp::iterator it;
    
    while (infil>>s) {
        
        s.resize(remove_if(s.begin(), s.end(),[](char x){return !isalnum(x) && !isspace(x);})-s.begin());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        it = word.find(s);
        
        if (it != word.end())
        {
            word[s] = it->second + 1;
        }
        else
        {
            word[s]++;
        }
        
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
