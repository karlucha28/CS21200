// Name: Karl Savinskiy
// Email Address: karlsavinskiy@gmail.com / ksavins000@citymail.cuny.edu
// The work in this assignment is my own. Any outside sources have been properly cited.

#include <iostream>
using namespace std;

void binary_print(ostream& outs, unsigned int n);
void triangle(ostream& outs, unsigned int m, unsigned int n);
double pow(double x, int n);
void indented_sentences(size_t m, size_t n);

int main() {
    cout << "Testing binary_print function:" << "\n";

    // Test case 1: n = 0
    cout << "binary_print(0): ";
    binary_print(cout, 0);
    cout << " (Expected: 0)" << "\n";

    // Test case 2: n = 8
    cout << "binary_print(8): ";
    binary_print(cout, 8);
    cout << " (Expected: 1000)" << "\n";

    // Test case 3: n = 31
    cout << "binary_print(31): ";
    binary_print(cout, 31);
    cout << " (Expected: 11111)" << "\n";

    // Test case 4: n = 52
    cout << "binary_print(52): ";
    binary_print(cout, 52);
    cout << " (Expected: 110100)" << "\n";

   
    cout << "binary_print(1): ";
    binary_print(cout, 1);
    cout << " (Expected: 1)" << "\n";

    cout << "binary_print(1023): ";
    binary_print(cout, 1023);
    cout << " (Expected: 1111111111)" << "\n";

    cout << "Testing triangle function:" << "\n";

    // Test case: m = 3, n = 5
    cout << "triangle(cout, 3, 5):\n";
    triangle(cout, 3, 5);
    cout << " (Expected:\n"
         << "  ***\n"
         << "  ****\n"
         << "  *****\n"
         << "  *****\n"
         << "  ****\n"
         << "  ***)" << "\n";

   
    cout << "triangle(cout, 1, 1):\n";
    triangle(cout, 1, 1);
    cout << " (Expected:\n"
         << "  *\n"
         << "  *)" << "\n";

    cout << "Testing pow function:" << "\n";

    // Test case: x = 2, n = 3
    cout << "pow(2, 3): ";
    cout << pow(2, 3);
    cout << " (Expected: 8)" << "\n";

   
    cout << "pow(2, 0): ";
    cout << pow(2, 0);
    cout << " (Expected: 1)" << "\n";

    cout << "pow(2, -3): ";
    cout << pow(2, -3);
    cout << " (Expected: 0.125)" << "\n";

    cout << "pow(0, 5): ";
    cout << pow(0, 5);
    cout << " (Expected: 0)" << "\n";

    cout << "Testing indented_sentences function:" << "\n";

    // Test case: m = 1, n = 4
    cout << "indented_sentences(1, 4):\n";
    indented_sentences(1, 4);
    cout << " (Expected:\n"
         << "This was written by calling number 1.\n"
         << "  This was written by calling number 2.\n"
         << "     This was written by calling number 3.\n"
         << "        This was written by calling number 4.\n"
         << "        This was ALSO written by calling number 4.\n"
         << "     This was ALSO written by calling number 3.\n"
         << "  This was ALSO written by calling number 2.\n"
         << "This was ALSO written by calling number 1.)" << "\n";

    
    cout << "indented_sentences(2, 3):\n";
    indented_sentences(2, 3);
    cout << " (Expected:\n"
         << "  This was written by calling number 2.\n"
         << "     This was written by calling number 3.\n"
         << "     This was ALSO written by calling number 3.\n"
         << "  This was ALSO written by calling number 2.)" << "\n";

    return 0;
}


