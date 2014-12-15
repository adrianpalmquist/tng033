//
//  main.cpp
//  labb 4
//
//  Created by Oscar Nord on 2014-12-08.
//  Copyright (c) 2014 Oscar Nord. All rights reserved.
//

#include <iostream>
#include <map>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(pair<int,string> i, pair<int,string> j)//jämför
{
    return (i.first > j.first);
}

void print(vector<pair<int,string>> &par_vec, map<string,int> &word, int counter)
{
    map<string,int>::iterator it;
    vector<pair<int,string> >::iterator it_vec;
    
    for(it = word.begin();it!=word.end();it++)
    {
        cout<<it->first<<": "<<it->second<<endl;
        
        pair <int,string> p (it->second,it->first);
        
        par_vec.push_back(p);
    }
    cout<<endl;
    
    sort(par_vec.begin(),par_vec.end(), comp);//sorterar vektor
    
    for(it_vec=par_vec.begin();it_vec != par_vec.end();it_vec++) //Skriv
    {
        cout<<it_vec->first<<it_vec->second<<endl;
    }
    cout<<endl<<endl<<"counter: "<<counter<<endl;
}

int read(map<string,int> &word)
{
    ifstream file("uppgift1");
    
    map<string,int>::iterator it;
    
    string s;
    string temp;
    
    int counter=0;
    
    //Testa om det går att öppna fil
    if (!file) {
        cout << "FEL!" << endl;
        return 0;
    }
    
    
    
    while(file>>s)
    {
        for(int j = 0;j<s.size();j++)//testa varje element
        {
            if((('a'<=s[j]) && (s[j]<= 'z')) || (s[j]=='\x27') || (s[j]=='\x60')) temp+=s[j];
            
            if(('A'<=s[j]) && (s[j]<= 'Z')) temp+=s[j]+('a'-'A');
        }
        
        it = word.find(temp); //Leta eter om temp finns 
        
        if(it != word.end())
        {
            word[temp]=it->second++;
        }
        
        else
        {
            word[temp]=1;
        }
        counter++;
        temp="";
    }
    file.close();
    return counter;
}

int main()
{
    map<string,int> word;
    vector<pair<int,string> > par_vec;
    
    print(par_vec, word, read(word));
    return 0;
}



