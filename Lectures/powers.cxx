// FILE: powers.cxx
// A demonstration program for two recursive functions that compute powers.
#include <cassert>     // Provides assert
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <iostream.h>  // Provides cin, cout
using namespace std;

// PROTOTYPES for the functions used in this demostration program
double power(double x, int n);
// Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.

double pow(double x, int n);
// Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.


int main( )
{
    double x;
    int n;

    cout << "Please type a value for x (double) and n (int) : ";
    cin >> x >> n;
    cout << "The value of x to the n is: " << power(x, n) << endl;
    
    cout << "Please type a value for x (double) and n (int) : ";
    cin >> x >> n;
    cout << "The value of x to the n is: " << power(x, n) << endl;
 
    return EXIT_SUCCESS;
}

double power(double x, int n)
// Library facilities used: cassert
    {
    double product; // The product of x with itself n times
    int count;

    if (x == 0)
        assert(n > 0);

    if (n >= 0)
    {
        product = 1;
        for (count = 1; count <= n; count++)
            product = product * x;
        return product;
    }
    else
        return 1/power(x, -n);
}

double pow(double x, int n)
// Library facilities used: cassert
{
    if (x == 0)
    {   // x is zero, and n should be positive
        assert(n > 0);
        return 0;
    }
    else if (n == 0)
        return 1;
    else if (n > 0)
        return x * pow(x, n-1);
    else // x is nonzero, and n is negative
        return 1/pow(x, -n);
}
