// Name: Karl Savinskiy
// Email Address: karlsavinskiy@gmail.com / ksavins000@citymail.cuny.edu
// The work in this assignment is my own. Any outside sources have been properly cited.

#include <iostream>
using namespace std;


// 1. One Binary Number
void binary_print(ostream& outs, unsigned int n){
    if (n == 0){ 
        outs << 0;
        return;
    }
    if (n > 1){
        binary_print(outs, n / 2);
    }
    outs << n % 2;
}


// 2. Triangle Pattern
void triangle(ostream& outs, unsigned int m, unsigned int n){
    if (m > n) return;

    for(size_t i = 0;  i < m; i++){
        cout << "*";
    }
    cout << "\n";

    triangle(outs, m + 1, n);

    for(size_t i = 0;  i < m; i++){
        cout << "*";
    }
    cout << "\n";
    
}


// 3. Pow Function
double pow(double x, int n){
    if(n == 0) return 1;

    if(n < 0){
        return 1.0/ pow(x, -n);
    }

    if ( n % 2 == 0){
        double half = pow(x, n/2);
        return half * half;
    }else{
        return x * pow(x, n - 1);
    }
}
    
    
// 4.  Repeated and Indented Sentences
void indented_sentences(size_t m, size_t n){
    if (m > n){
        return;
    }
    
    for (size_t i = 1; i < m; i++){
        cout << "    ";
    }

    cout << "This was written by calling number " << m << "." << "\n";

    indented_sentences(m + 1,n);

    for (size_t i = 1; i < m; i++){
        cout << "    ";
    }

    cout << "This was ALSO written by calling number " << m << "." << "\n";
}
