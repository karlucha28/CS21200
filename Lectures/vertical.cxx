// FILE: vertical.cxx
// Examples of two recursive functions that write the digits of a number
// vertically.
#include <iostream>  // Provides cin, cout
#include <cstdlib>   // Provides EXIT_SUCCESS
using namespace std;

// PROTOTYPES of the functions used in this demonstration:
void write_vertical(unsigned int number);
// Postcondition: The digits of number have been written, stacked vertically.

void super_write_vertical(int number);
// Postcondition: The digits of the number have been written, stacked vertically.
// If number is negative, then a negative sign appears on top.


int main( )
{
    int i;

    cout << "Please type a non-negative number: ";
    cin >> i;
    cout << "The digits of that number are:" << endl;
    write_vertical(i);
    
    cout << "Please type a negative number: ";
    cin >> i;
    cout << "The digits of that number are:" << endl;
    super_write_vertical(i);

    cout << "Let's get vertical!" << endl;
    return EXIT_SUCCESS;
}

void write_vertical(unsigned int number)
// Postcondition: The digits of number have been written, stacked vertically.
// Library facilities used: iostream.h
{
    if (number < 10)
        cout << number << endl; // Write the one digit
    else
    {
        write_vertical(number/10);          // Write all but the last digit
        cout << number % 10 << endl;        // Write the last digit
    }
}

void super_write_vertical(int number)
// Postcondition: The digits of the number have been written, stacked vertically.
// If number is negative, then a negative sign appears on top.
// Library facilities used: iostream.h, math.h
{
    if (number < 0)
    {
        cout << '-' << endl;                 // print a negative sign
        super_write_vertical(abs(number));   // abs computes absolute value
        // This is Spot #1 referred to in the text.
    }
    else if (number < 10)
        cout << number << endl;              // Write the one digit
    else
    {
        super_write_vertical(number/10);     // Write all but the last digit 
        // This is Spot #2 referred to in the text.
        cout << number % 10 << endl;         // Write the last digit
    }
}
