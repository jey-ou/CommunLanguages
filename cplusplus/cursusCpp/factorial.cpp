/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int factorial (int n);
int factorial2 (int n);

int main()
{

    int n=0;
    int resultaat = 0;
    cout<<"geef een getal op: ";
    cin>> n;
    cout << endl;
    resultaat = factorial(n);

    cout << resultaat << endl;
    
    resultaat = factorial2(n);

    cout << resultaat << endl;

    return 0;
}

int factorial (int n){
    
    if (n<1)
        return 1;
    return n * factorial (n-1);
}

int factorial2(int n){
    int resultaat =1;
    
    if (n<1)
        return 1;
    while (n>0){
        resultaat *= n;
        n--;
    }
    return resultaat;
}