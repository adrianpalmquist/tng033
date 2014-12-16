//
//  main.cpp
//  labb 4
//
//  Created by Oscar Nord on 2014-12-08.
//  Copyright (c) 2014 Oscar Nord. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int,string>> parVec;
typedef map<string,int> sMap;
typedef pair<int,string> par;

//Jämför
bool comp(par i, par j)
{
    return (i.first > j.first);
}

//Skriv ut
void print(parVec &par_vec, sMap &word, int counter)
{
    sMap::iterator it;
    
    parVec::iterator it_vec;
    
    for(it = word.begin(); it!=word.end(); it++)
    {
        //cout << it->first << ": " << it->second<<endl;
        
        //cout << "Key: " << it->first << endl << "Values:" << endl;
        
        par p (it->second,it->first);
        
        par_vec.push_back(p);
    }
    
    cout << endl;
    
    sort(par_vec.begin(),par_vec.end(), comp);//sorterar vektor
    
    
    for(it_vec=par_vec.begin(); it_vec != par_vec.end(); it_vec++) //Skriv
    {
        cout << it_vec->first << " " << it_vec->second<<endl;
    }
    
    
    cout << endl << endl << "counter: " << counter << endl;
}



//Läs in
int read(sMap &word)
{
    string file_name;
    string s;
    string temp;
    
    int counter = 0;
    
    cout << "Enter file name: ";
    cin >> file_name;
    
    
    ifstream infil(file_name);
    
    sMap::iterator itr;
    
   
    
    //Testa om det går att öppna fil
    if (!infil)
    {
        cout << "FEL!" << endl;
        return 0;
    }
    
    
    
    while(infil>>s)
    {
        for(int j = 0; j<s.size(); j++)//testa varje element
        {
            if((('a'<=s[j]) && (s[j] <= 'z')) || (s[j] =='\x27') || (s[j] =='\x60')) temp +=s[j];
            
            if(('A'<=s[j]) && (s[j] <= 'Z')) temp +=s[j]+('a'-'A');
        }
        
        itr = word.find(temp); //kolla om temp finns
        
        if(itr != word.end())
        {
            word[temp] = itr->second + 1;
        }
        
        else
        {
            word[temp]++;
            
        }
        
        counter++;
        temp = "";
    }
    
    infil.close();
    return counter;
}



int main()
{
    sMap word;
    parVec par_vec;
    
    print(par_vec, word, read(word));
    
    return 0;
}



