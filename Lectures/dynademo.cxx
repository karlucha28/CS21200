// FILE: dynademo.cxx
// This is a small demonstration program showing how a dynamic array is used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS and size_t
#include <cassert>     // Provides assert
using namespace std;

// PROTOTYPES for functions used by this demonstration program
void allocate_doubles(double*& p, size_t& n);
// Postcondition: The user has been prompted for a size n, and this size has been read.
// The pointer p has been set to point to a new dynamic array containing n doubles. 
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.

void fill_array(double data[ ], size_t n);
// Precondition:  data is an array with at least n components.
// Postcondition: The user has been prompted to type n doubles, and these
// numbers have been read and placed in the first n components of the array.

double average(const double data[ ], size_t n);
// Precondition:  data is an array with at least n components, and n > 0.
// Postcondition: The value returned is the average of data[0]..data[n-1].

void compare(const double data[ ], size_t n, double value);
// Precondition:  data is an array with at least n components.
// Postcondition: The values data[0]..data[n-1] have been printed with a
// message saying whether they are above, below, or equal to value.


int main( )        
{
    double *numbers;   // Will point to the first component of an array
    size_t array_size;
    double mean_value;

    // Allocate an array of doubles to hold the user’s input.
    cout << "This program will compute the average of some numbers. The\n";
    cout << "numbers will be stored in an array of doubles that I allocate.\n";
    allocate_doubles(numbers, array_size);

    // Read the user’s input and compute the average.
    fill_array(numbers, array_size);
    mean_value = average(numbers, array_size);

    // Print the output.
    cout << "The average is: " << mean_value << endl;
    compare(numbers, array_size, mean_value);
    cout << "This was a mean program.";
    
    return EXIT_SUCCESS;
}

void allocate_doubles(double*& p, size_t& n)
// Library facilities used: iostream.h, stdlib.h
{
    cout << "How many doubles should I allocate?" << endl;
    cout << "Please type a positive integer answer: ";
    cin  >> n; 
    p = new double[n];      
}

void fill_array(double data[ ], size_t n)
// Library facilities used: cstdlib
{
    size_t i;
    cout << "Please type " << n << " double numbers: " << endl;

    // Read the n numbers one at a time.
    for (i = 0; i < n; ++i) 
        cin >> data[i];       
}

void compare(const double data[ ], size_t n, double value)
{
    size_t i;
   
    for (i = 0; i < n; ++i)
    {
        cout << data[i];
        if (data[i] < value)     
            cout << " is less than ";
        else if (data[i] > value) 
            cout << " is more than ";
        else                      
            cout << " is equal to  ";
        cout << value << endl;
    }
}

double average(const double data[ ], size_t n)
// Library facilities used: cassert, cstdlib
{
    size_t i;   // An array index
    double sum; // The sum of data[0] through data[n - 1]
   
    assert(n > 0);

    // Add up the n numbers and return the average.
    sum = 0;
    for (i = 0; i < n; ++i) 
        sum += data[i];
    return (sum/n);      
}
