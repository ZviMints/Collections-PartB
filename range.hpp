#ifndef RANGE_HPP
#define RANGE_HPP

#include <iostream>

namespace itertools {
template <typename T> class range {
        private:
        T a; // begin Point
        T b; // End Point
        public:
        range(T begin,T end) : a(begin), b(end) {}
        struct const_iterator {
        const_iterator(T p) : type(p) {} 
        const_iterator& operator++(){ ++type; return *this; } 
        const T& operator*() const { return type; } 
        bool operator!=(const const_iterator& iter) const { return type != iter.type; }
       
        private:
        T type; 
       
     }; // End Struct const_iterator
        
        const_iterator begin() const { return const_iterator(a); }
        const_iterator end() const { return const_iterator(b); }
    };
} // End Namespace 'itertools'

#endif