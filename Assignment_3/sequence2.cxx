//  Karl Savinskiy ID: 6575
//“The work in this assignment is my own. Any outside sources have been properly cited.”

// FILE: sequence2.cxx
// CLASS implemented: sequence (see sequence2.h for documentation)
// INVARIANT for the sequence class:
//   1. The number of items in the sequence is in the member variable used;
//   2. The actual items of the sequence are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   3. The size of the dynamic array is in the member variable capacity.
//   4. The index of the current item is the member variable current_item

#include <algorithm>    // Provides copy function
#include <cassert>       // Provides assert function
#include "sequence2.h"
using namespace std;

namespace main_savitch_4
{
    const sequence::size_type sequence::DEFAULT_CAPACITY;
    // CONSTRUCTOR
    sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }

    sequence::sequence(const sequence& source)
    // Library facilities used: algorithm
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_item = source.current_item; 
        copy(source.data, source.data + used, data);
    }

    sequence::~sequence(){delete [ ] data;}
   

    void sequence::start(){
        current_item = 0;
    }

    
    void sequence::advance(){
        assert(is_item());
        if (current_item < used - 1) {
            ++current_item;
        } else {
            current_item = used;
        }
    }

    void sequence::insert(const value_type& entry){
        if (used == capacity){
            resize(used*2);
        }
        
        if(!is_item()){
            current_item = 0;
        }
        for (size_t i = used; i > current_item; i--){
            data[i] = data[i -1];
        }
        data[current_item] = entry;
        ++used;
    }


    void sequence::attach(const value_type& entry){
        if (used == capacity)
        resize(used*2);
        if(!is_item()){
            current_item = used;
        } else {
            for (size_t i = used; i > current_item + 1; --i){
                data[i] = data[i -1];
            }
            ++current_item;
        }
        data[current_item] = entry;
        ++used;
    }


    void sequence::remove_current() {
        assert(is_item());
        for (size_type i = current_item; i < used - 1; ++i) {
            data[i] = data[i+1];
        }
        --used;
        if (current_item >= used) current_item = used;
    }


    void sequence::resize(size_type new_capacity){
        // took from the bag2.cxx
        value_type *larger_array;

        if (new_capacity == capacity)
            return; // The allocated memory is already the right size.

        if (new_capacity < used)
            new_capacity = used; // Canot allocate less than we are using.

        larger_array = new value_type[new_capacity];
        copy(data, data + used, larger_array);
        delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }


    void sequence::operator=(const sequence& source){
        // took from the bag2.cxx and added some changes
        value_type *new_data;

        // Check for possible self-assignment:
        if (this == &source)
                return;

        // If needed, allocate an array with a different size:
        if (capacity != source.capacity)
        { 
            new_data = new value_type[source.capacity];
            delete [ ] data;
            data = new_data;
            capacity = source.capacity;
        }

        // Copy the data from the source array:
        used = source.used;
        current_item = source.current_item;
        copy(source.data, source.data + used, data);
    }
    // (1) Operators +  //took from the bad2.cxx and modified
    sequence operator +(const sequence& s1, const sequence& s2){
        sequence arr(s1.size( ) + s2.size( ));

        arr += s1; 
        arr += s2;
        return arr;
    }

    // (1) Operators += //took from the bad2.cxx and modified
    void sequence::operator +=(const sequence& addend)
    // Library facilities used: algorithm
    {
        if (used + addend.used > capacity){
            resize(used + addend.used);
        }

        copy(addend.data, addend.data + addend.used, data + used);
	    used += addend.used;
    }

    // (2) Operator []. For extra credit
    sequence::value_type sequence::operator[] (size_type index) const {
        assert(index < used);
        return data[index];
    }
}