#include <iostream>
#include <cmath>
#include <math.h>

#include "statistics.h"


//Return the largest value stored in V
//Return the smallest value stored in V through reference argument min
//a is an array storing n ints
int max_min (int a[], int n, int& min)
{
    int maxi;
    int mini;

    maxi = a[0];
    mini = a[0];

    for(int i=1; i<n; i++)
    {
        if(a[i] > maxi)
            maxi = a[i];
        if(a[i] < mini)
            mini = a[i];
    }
    min = mini;

	return maxi;
}

//Return the average of the values stored in a
//a is an array storing n ints
double mean (int a[], int n)
{
    double sum, mean;

    sum = a[0];
    for(int i=1; i<n; i++)
    {
        sum += a[i];
    }
    mean = sum/n;

	return mean;
}


//Return the median of the values stored in a
//a is a sorted array storing n ints
//Median is the middle value inthe sorted array, if n is odd
//Otherwise, the median is the average of the two middle values
double median (int a[], int n)
{
    int temp, templ, temph;
    double median;
    if(n % 2 != 0){
        temp = ceil(n/2);
        median = a[temp];
    }
    else{
        templ = a[n/2];
        temph = a[(n/2)+1];
        median = (templ + temph)/2;
    }

	return median;
}


//Returns the standard deviation of n integers stored in array a
double standard_deviation(int a[], int n)
{
    //Mean
    double sum, mean, deviation;

    sum = a[0];
    for(int i=1; i<n; i++)
    {
        sum += a[i];
    }
    mean = sum/n;

    std::cout << "mean: " << mean;

    //Deviation
    sum = pow(a[0] - mean, 2.0);

     for(int i=1; i<n; i++)
    {
        sum += pow(a[i] - mean, 2.0);
    }

    deviation = sqrt(sum/n);

	return deviation;

}

