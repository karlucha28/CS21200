#include "sequence1.h"
#include <cassert>

namespace main_savitch_3 {
    // constr
    sequence::sequence(){
        items = 0;
        current_item = 0;
    }
    // const member functions (use the type def in class)
    sequence::size_type sequence::size() const {
        return items;
    }

    bool sequence::is_item() const {
        return current_item < items;
    }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_item];
    }

    void sequence::start(){
        current_item = 0;
    }

    void sequence::advance(){
        assert(is_item());
        current_item += 1;
    }

    void sequence::insert(const value_type& entry){   
        assert(size() < CAPACITY);
        if(!is_item()){
            current_item = 0;
        }
        // moved everything one index to the right and have two same values for cur_it and cur_it-1
        for (size_t i = items; i > current_item; i--){
            data[i] = data[i -1];
        }
        // took the code from bag1.cxx
        data[current_item] = entry;
        ++items;
    }

    void sequence::attach(const value_type& entry){
        assert(size() < CAPACITY);
        if(!is_item()){
            // items is 0 = 0-index if it's empty
            current_item = items;
        } else {
            // to insert after the curr item
            ++current_item;
            // the rest is the same from the insert function
            for (size_t i = items; i > current_item; --i){
                data[i] = data[i -1];
            }
        }
        data[current_item] = entry;
        ++items;
    }

    void sequence::remove_current(){
        assert(is_item());
        for (size_t i = current_item; i < items-1; i++){
            data[i] = data[i+1];
        }
        items = items - 1;
    }
    
}