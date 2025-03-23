//  Karl Savinskiy ID: 6575
// “The work in this assignment is my own. Any outside sources have been properly cited.”

// FILE: sequence3.cxx
// CLASS implemented: sequence (see sequence3.h for documentation)
// INVARIANT for the sequence class:
//   1. `num_items` the number of items stored in the sequence
//   2. `head_ptr` head pointer to the sequence
//   3. `tail_ptr` pointer to the last item of the sequence
//   4. `cursor` pointer to the current item ( Null if the seq is empty)
//   5. `precursor` pointer to the node before the cursor ( Null if the num_items < 2)


#include "sequence3.h"
#include "./node/node1.h"
#include <cassert> 

namespace main_savitch_5 {
    // CONSTRUCTORS and DESTRUCTOR
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    sequence::sequence() {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        num_items = 0;
    }
    //  Big-O Comparison: Linked List O(n)_______Dynamic Array_______O(1)
    sequence::sequence(const sequence& source) {
        if (source.head_ptr == NULL) {
            head_ptr = NULL;
            tail_ptr = NULL;
            cursor = NULL;
            precursor = NULL;
            num_items = 0;
            return;
        }

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        num_items = source.num_items; 

        // Set cursor and precursor
        cursor = head_ptr;
        precursor = NULL;
        node* check_cur = source.head_ptr;

        while (check_cur != source.cursor) {
            precursor = cursor;
            cursor = cursor->link();
            check_cur = check_cur->link();
        }
    }
    //  Big-O Comparison: Linked List O(n)_______Dynamic Array_______O(1)
    sequence::~sequence() {
        list_clear(head_ptr);
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        num_items = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    void sequence::start() {
        cursor = head_ptr;
        precursor = NULL;
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    void sequence::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(n)
    void sequence::insert(const value_type& entry) {
        if (cursor == head_ptr || !is_item()) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            if (tail_ptr == NULL) {
                tail_ptr = head_ptr;
            }
        } else {
            list_insert(precursor, entry);
            cursor = precursor->link();
        }
        ++num_items; 
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(n)
    void sequence::attach(const value_type& entry) {
        if (!is_item()) {
            if (tail_ptr == NULL) {
                list_head_insert(head_ptr, entry);
                tail_ptr = head_ptr;
                cursor = head_ptr;
            } else {
                list_insert(tail_ptr, entry);
                precursor = tail_ptr;
                cursor = tail_ptr->link();
                tail_ptr = cursor;
            }
        } else {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
            if (cursor->link() == NULL) {
                tail_ptr = cursor;
            }
        }
        ++num_items; 
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(n)
    void sequence::remove_current() {
        assert(is_item());
        if (cursor == head_ptr) {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            if (head_ptr == NULL) {
                tail_ptr = NULL;
            }
        } else {
            list_remove(precursor);
            cursor = precursor->link();
            if (cursor == nullptr) {
                tail_ptr = precursor;
            }
        }
        --num_items; 
    }
    //  Big-O Comparison: Linked List O(n)_______Dynamic Array_______O(n)
    void sequence::operator=(const sequence& source) {
        if (this == &source) return;

        list_clear(head_ptr); 
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        num_items = source.num_items; 

        // Set cursor and precursor
        cursor = head_ptr;
        precursor = NULL;
        node* check_cur = source.head_ptr;

        while (check_cur != source.cursor) {
            precursor = cursor;
            cursor = cursor->link();
            check_cur = check_cur->link();
        }
    }

    // CONSTANT MEMBER FUNCTIONS
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    sequence::size_type sequence::size() const {
        return num_items;
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    bool sequence::is_item() const {
        return cursor != NULL;
    }
    //  Big-O Comparison: Linked List O(1)_______Dynamic Array_______O(1)
    sequence::value_type sequence::current() const {
        assert(is_item());
        return cursor->data();
    }
}