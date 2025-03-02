// Provided by:   ____________Karl Savinskiy ID: 6575__________
// Email Address: ____________(karlsavinskiy@gmail.com  / ksavins000@citymail.cuny.edu)________
//  “The work in this assignment is my own. Any outside sources have been properly cited.”
// FILE: sequence2.h
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
// There is no implementation file provided for this class since it is
// a programming assignment from Chpater 4 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.
//
//
// CONSTRUCTOR for the sequence class:

//   sequence(size_type initial_capacity = DEAULT_CAPACITY)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
//     sequence(const sequence& source)
//     Precondition: source is a valid.
//     Postcondition: The sequence is a copy of the source sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void resize(size_type new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has 
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
//   void operator +=(const sequence& addend) 
//     Postcondition: Each item in addend has been added to this sequence.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items on the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
// NONMEMBER FUNCTIONS for the sequence class:
//   sequence operator +(const sequence& s1, const sequence& s2)
//   Postcondition: The sequence returned is the union of s1 and s2.
//
// VALUE SEMANTICS for the sequence class:
//   Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the sequence
//   If there is insufficient dynamic memory, then the following functions
//   call new_handler: The constructors, insert, attach. 

#ifndef MAIN_SAVITCH_SEQUENCE2_H
#define MAIN_SAVITCH_SEQUENCE2_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_4
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        void resize(size_type new_capacity);
        void operator=(const sequence& source);
        // (1) Operators +=
        void operator +=(const sequence& addend);
        // (2) Operator []. For extra credit
        value_type operator[] (size_type index) const;
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const {return used;};
        bool is_item( ) const {return current_item < used;};
        value_type current( ) const {return data[current_item];};
    private:
	// -- Fill in your private member variables here.
    //     -- You'll need a pointer to a dynamic array, and a size_type
    //     -- variable to keep track of the current length of the
    //     -- sequence, an index to the current item, and 
	// -- another size_type variable to keep track of the
    //     -- complete capacity of the dynamic array.
        value_type *data;     // Pointer to partially filled dynamic array
        size_type used;       // How much of array is being used
        size_type capacity; 
        size_type current_item;

    };
    // NONMEMBER FUNCTIONS for the bag class
    // (1) Operators +
    sequence operator +(const sequence& s1, const sequence& s2);
}

#endif

