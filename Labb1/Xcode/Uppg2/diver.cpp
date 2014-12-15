#include <iomanip>
#include <ios>
#include <sstream>
#include <array>
#include "diver.h"


//Test if scores line has correct format
//Accepted line format: difficulty, followed by 7 scores, and (possibly) some text
//The 7 scores should be stored in array scores and
//difficulty should be stored in dif
//If the line has correct format then return true
//stringstreams are used, see sec. 11.9 of course book
bool test_scores_line(string line, double scores[], double &dif)
{
    istringstream in_stream(line);
    double U[NR_OF_REF];

    double d;

    if(in_stream >> d >> U[0] >> U[1] >> U[2] >> U[3] >> U[4] >> U[5] >> U[6]){
        
        for (int i = 0; i<NR_OF_REF; i++) {
        scores[i] = U[i];
        }
        
        dif = d;
        return true;
    }

    return false;
}



//Overload operator>> to read data for a diver d from stream in
//If errors were encountered while reading the data for a diver d
//then d.difficulty is set to a negative value
//Return the stream in
istream& operator>>(istream& in, Diver& d)
{
    string line;
    
    do {
        getline(in >> ws, d.name);
    } while (d.name == "\n" || d.name == "\r");
    
    
    
    do {
        getline(in >> ws,line);
    } while (line == "\n" || line == "\r");
    
    if(!test_scores_line(line, d.points, d.difficulty))
    d.difficulty = -1;
    
    return in;
    
}




//Calculate final score for diver d
//and store it in d.final_score
void calculate_final_score(Diver& d)
{
    //Copy d.points to a[]
    
    double a[NR_OF_REF];
    
    for (int i = 0; i < NR_OF_REF; i++) {
        a[i] = d.points[i];
    }
    
    //Sort a[]

    for (int pass = 0; pass <= NR_OF_REF - 2; pass++) {
        for (int i = 0; i < NR_OF_REF - 1; i++) {
            if (a[ i ] < a[ i + 1 ]) {
                double temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
    }
    
    
    //Calculate sum
    
    double final_score = 0.0;
    for (int i = 1; i < NR_OF_REF-1; i++){
        final_score += a[i];
    }
    final_score = final_score/(NR_OF_REF-2);
    final_score = final_score * (d.difficulty*3);
    
    d.final_score = final_score;
}


//Overload operator<< to write data for diver d
//to stream out: name and final score
ostream& operator<<(ostream& out, const Diver& d)
{
    cout << d.name << setprecision(3) << d.final_score << endl;
    return out;
}


//Overload comparison operator
//Return true if d1.final_score < d2.final_score
bool operator<(const Diver& d1, const Diver& d2)
{
    if (d1.final_score < d2.final_score)
        return true;
    
    return false;
}