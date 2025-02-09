// FILE: pointmain1.cxx
// This small demonstration shows how the point class is used.

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "point.h"   // Provides the throttle class
using namespace std;    // Allows all Standard Library items to be used
using main_savitch_2A::point;


int main( )
{
	int i;
	cout << "Value semantics of the point class" <<endl;

	cin >> i;

	point p1(-1.0,  0.8), p2;
	
	cout << "Point p1 is intialized as (" << p1.get_x() << ", " << p1.get_y() << ")"<< "by the constructor with 2 parameters" << endl; 
	cout << "Point p2 is intialized as (" << p2.get_x() << ", " << p2.get_y()  << ")" << "by the automatic default constructor"<< endl; 

	p2 =  p1;
	cout << "After assigning p1 to p2, Point p2 is (" << p2.get_x() << ", " << p2.get_y()  << ")" << "by the automatic assignment operator" << endl; 

	point p3 (p1);
	cout << "Point p3 is intialized as (" << p2.get_x() << ", " << p2.get_y()  << ")" << "by copying p1" << endl; 

	point p4 = p1;
	cout << "Point p4 is intialized as (" << p2.get_x() << ", " << p2.get_y()  << ")" << "by an alternative copying of p1" << endl; 

    
	return EXIT_SUCCESS;
}
