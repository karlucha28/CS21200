#include <iostream>
#include "bag6.h"
using namespace std;
using namespace main_savitch_10;

int main() {
    bag<int> test_bag;
    
    // Test insertion
    cout << "Inserting values into the bag..." << endl;
    test_bag.insert(10);
    test_bag.insert(5);
    test_bag.insert(15);
    test_bag.insert(10); // Duplicate
    
    // Test size
    cout << "Bag size: " << test_bag.size() << endl;
    
    // Test count
    cout << "Count of 10: " << test_bag.count(10) << endl;
    cout << "Count of 5: " << test_bag.count(5) << endl;
    cout << "Count of 15: " << test_bag.count(15) << endl;
    cout << "Count of 20: " << test_bag.count(20) << endl;
    
    // Test erase_one
    cout << "Erasing one 10..." << endl;
    test_bag.erase_one(10);
    cout << "Count of 10 after erase_one: " << test_bag.count(10) << endl;
    
    // Test erase all
    cout << "Inserting more 5 values..." << endl;
    test_bag.insert(5);
    test_bag.insert(5);
    cout << "Count of 5 now: " << test_bag.count(5) << endl;
    
    cout << "Erasing all 5 values..." << endl;
    size_t erased = test_bag.erase(5);
    cout << "Erased " << erased << " occurrences of 5" << endl;
    cout << "Count of 5 now: " << test_bag.count(5) << endl;
    
    // Test the tree structure
    cout << "Current tree structure:" << endl;
    test_bag.debug();
    
    return 0;
}
