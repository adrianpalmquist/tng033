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

//Skriv ut
void print(vecPar &par_vec, mp &word, int counter)
{
    mp::iterator it;
    
    vecPar::iterator it_vec;
    
    for(it = word.begin();it!=word.end();it++)
    {
        cout << it->first << ": " << it->second<<endl;
        
        par p (it->second,it->first);
        
        par_vec.push_back(p);
    }
    
    cout << endl;
    
    sort(par_vec.begin(),par_vec.end(), comp);//sorterar vektor
    
    for(it_vec=par_vec.begin();it_vec != par_vec.end();it_vec++) //Skriv
    {
        cout << it_vec->first << it_vec->second<<endl;
    }
    
    //cout << endl << endl << "counter: " << counter << endl;
}


//Läs in
int read(mp &word)
{
    string file_name;
    string s;
    string temp;
    
    int counter=0;
    int stringCounter = 0;
    
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
    //string::iterator sIt = s.begin();
    
    //copy(in_it, in_end, inserter(word,it));
    
    while (infil>>s) {
        
        s.resize(remove_if(s.begin(), s.end(),[](char x){return !isalnum(x) && !isspace(x);})-s.begin());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        it = word.find(s);
        
        if (it != word.end())
        word[s] = it->second++;
        else
        word[s] = 1;
        
        counter++;
    }
    
    
    /*
    
    while(infil>>s)
    {
        for(int j = 0;j<s.size();j++)//testa varje element
        {
            if((('a'<=s[j]) && (s[j]<= 'z')) || (s[j]=='\x27') || (s[j]=='\x60')) temp+=s[j];
            
            if(('A'<=s[j]) && (s[j]<= 'Z')) temp+=s[j]+('a'-'A');
        }
        
        it = word.find(temp); //kolla om temp finns
        
        if(it != word.end())
        {
            word[temp]=it->second++;
        }
        
        else
        {
            word[temp]=1;
        }
        
        counter++;
        temp = "";
    }
     */
    
    
    
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
