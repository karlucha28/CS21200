// FILE: maze.cxx
// An interactive program to lead the user into a maze and back out again,
// while searching for a magic tapestry.

#include <cctype>     // Provides toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream.h> // Provides cin, cout
#include "useful.h"   // From Appendix I; Provides eatline, inquire
using namespace std;

// PROTOTYPES of functions used in this program.
bool dead_end();
// Postcondition:The return value is true if the direction directly in front
// is a deadend (i.e., a direction that cannot contain the tapestry).

bool traverse_maze();
// Precondition: The user of the program is facing an unblocked spot in the
// maze which has not previously been visited by the user.
// Postcondition: The function has asked a series of questions and provided
// various directions to the user. The questions and directions have led the
// user through the maze and back to the exact same position that the user
// started at. The return value of the function is a true/false value
// indicating whether or not the user found a magic tapestry in the maze.


int main()
{
    if (traverse_maze())
	cout << "You found it!" << endl;
    else
	cout << "It wasn't found!" << endl;
    return EXIT_SUCCESS;
}

bool dead_end()
// Library facilities used: useful.h (From Appendix I)
{
    return inquire("Are you facing a wall?")
	   ||
	   inquire("Is your name written in front of you?");
}

bool traverse_maze()
// Library facilities used: iostream.h
{
    int direction;  // Counts 1, 2, 3 for the three directions to explore
    bool found;     // Will be set to true if we find the tapestry

    cout << "Step forward & write your name on the ground." << endl;
    found = inquire("Have you found the tapestry?");

    if (found)
    {   // Pick up the tapestry and step back from whence you came.  
        	cout << "Pick up the tapestry and take a step backward." << endl;
    }
    else
    {   // Explore the three directions (not counting the one that you just
        // came from). Start with the direction on your left, and then
        // turn through each of the other possible directions one at a time.

        	cout << "Please turn left 90 degrees." << endl;
        for (direction = 1; direction <= 3; direction++)
        {
             if ( !found && !dead_end( ) )
                 found = traverse_maze( );
             cout << "Please turn right 90 degrees." << endl;
        }
    
        // You're now facing the direction from whence you came, so step
        // forward and turn around. This will put you in the exact
        	// spot that you were at when the function call began.
        	cout << "Please step forward, then turn 180 degrees." << endl;
    }
    return found;
}
