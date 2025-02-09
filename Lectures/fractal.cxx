// File: fractal.cxx
// A demonstration program for the random_fractal function from Chapter 9.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream.h> // Provides cin, cout
#include "useful.h"   // From Appendix H. Provides random_real, display
using namespace std;

// PROTOTYPE for the function used in this demonstration program.
void random_fractal
(double left_height, double right_height, double width, double epsilon);
// Precondition: width and epsilon are both positive.
// Postcondition: The function has generated a random fractal from a line
// segment. The parameters left_height and right_height are the heights of the
// two endpoints of the line segment, and the parameter width is the segment's
// width. The generation of the random fractal stops when the width of the
// line segments reaches epsilon or less. 
// Method of displaying the output: The height of the right endpoint of
// each line segment in the random fractal is displayed by calling the
// function display(...).

int main()
{
    cout << "Turn your head sideways to see a nice landscape:" << endl;
    random_fractal(0, 0, 16, 1);
    return EXIT_SUCCESS;
}

void random_fractal
(double left_height, double right_height, double width, double epsilon)
// Library facilities used: cassert, useful.h (From Appendix I).
{
    double mid_height;   // Height of the midpoint of the line segment

    assert(width > 0);
    assert(epsilon > 0);

    if (width <= epsilon)
        	display(right_height);
    else
    {
        mid_height = (left_height + right_height) / 2;
        	mid_height += random_real(-width, width);
        	random_fractal(left_height, mid_height,   width/2, epsilon);
        	random_fractal(mid_height,  right_height, width/2, epsilon);
    }
}
