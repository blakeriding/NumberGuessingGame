#include <iostream>
#include <algorithm>
using namespace std;

// following several lines for unit testing purposes
#include "RecursionCounter.h"
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;



void GuessNumber(int lowVal, int highVal)
{
    int midVal;// Midpoint of low and high value
    char userAnswer;
    
    
    midVal = (highVal + lowVal) / 2;
    
    // Prompt user for input
    cout << "Is it " << midVal << " (l,y,h)? " << endl;
    cin >> userAnswer;

    
    if(midVal == lowVal + 1 && userAnswer == 'h')
    {
        cout << "You cheated!" << endl;
    }
    else if(midVal == lowVal + 1 || userAnswer == 'y')
    {
        cout << "Your number is " << midVal + 1 << endl;
        
    }
    
    
    
    
    else {// Recursive case: split into lower OR upper half
        if (userAnswer == 'h') {// Guess in lower half
            GuessNumber(lowVal, midVal);// Recursive call
        }
        
        else {// Guess in upper half
            GuessNumber(midVal, highVal);// Recursive call
        }
        
    }
}

void hilo(int n)
{
    
    // Call recursive function to guess number
    GuessNumber(1, 100);
}


// Sort Method


// Sort Helper Method
void sorthelp(int a[], int start,int n)
{
    RecursionCounter rc;
    // Base case to stop recursion
    if (start == n)
        return;
    
    for (int i =0 ; i < n - 1; i++)
        if (a[i] > a[i+1])
            swap(a[i], a[i+1]);
    
    sorthelp(a, start + 1, n);
}

void mysort(int nums[],int nelems)
{
    int start = 1;
    sorthelp(nums,start,nelems);
}



int main()
{
    
    int guess = 50;
    
    cout << "Think of a number between 1 and 100" << endl;
    cout <<  "I will try and guess it with your help." << endl;
    
    hilo(guess);
    
    
 
    //Sort an array
    int a[]= {5,4,3,2,1};
    const int n=5;
    //Call the sort function
    mysort(a,n);
    cout << "Sorted result:\n";
    
    for(int n:a)
        cout <<n << endl;
    cout << endl;
    
    
    
    return 0;
}
