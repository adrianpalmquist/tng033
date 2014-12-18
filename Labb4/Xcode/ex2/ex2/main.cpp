
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector<string> vec;
typedef map<string,vec> mp;

bool is_anagram(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}


void printMap(map<string,vector<string>>::iterator it, ostream_iterator<string> &outIt)
{
    copy(it->second.begin(), it->second.end(), outIt);
}


int read(mp &word){
    
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
        
        s.resize(remove_if(s.begin(), s.end(),[](char x){return !isalnum(x) && !isspace(x);})-s.begin()); //Check if character is alphanumeric
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        temp = s;
        
        sort(s.begin(), s.end());
        
        it = word.find(s);
        
        word[s].push_back(temp);
        
        counter++;
        s = "";
    }
    
    infil.close();
    return counter;
    
    return 0;
}

void print(mp &word, int counter){
    
    mp::iterator it;
    
    cout << "Number of words: " << counter << endl;
    
    ostream_iterator<string> outIt(cout, " ");
    
    for_each(word.begin(), word.end(), [outIt] (pair<string, vector<string>> p){if (p.second.size() != 1){
        copy(p.second.begin(), p.second.end(), outIt);
        cout << "   -->   "<< p.second.size() << " words." << endl;
    } });
    
}

int main() {
    mp word;
    print(word, read(word));
    
    return 0;
}
