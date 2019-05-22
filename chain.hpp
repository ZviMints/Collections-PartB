
#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <iostream>

namespace itertools {
template <typename T1, typename T2> class chain {
        private:
        T1 a; // range(5,8) for Example
        T2 b; // range(9,10) for Example
        
        public:
        chain(T1 r1,T2 r2) : a(r1), b(r2) {}

       class const_iterator {     
        typename T1::const_iterator t1_begin;
        typename T1::const_iterator t1_end;

        typename T2::const_iterator t2_begin;
        typename T2::const_iterator t2_end;   
       
        public:
        
        const_iterator(typename T1::const_iterator t1_begin,typename T1::const_iterator t1_end,typename T2::const_iterator t2_begin,typename T2::const_iterator t2_end) 
        : t1_begin(t1_begin), t1_end(t1_end), t2_begin(t2_begin), t2_end(t2_end) {} 
        
        const_iterator(typename T1::const_iterator t1_begin,typename T1::const_iterator t1_end,typename T2::const_iterator t2_begin,typename T2::const_iterator t2_end, bool) 
        : t1_begin(t1_end), t1_end(t1_end), t2_begin(t2_end), t2_end(t2_end) {} 
          
        const_iterator& operator++() { 
        if(t1_begin != t1_end) ++ t1_begin;
        else ++ t2_begin;
        return *this; 
        }

        bool operator!=(const const_iterator& iter) const {
            if(t1_begin != iter.t1_begin || t2_begin != iter.t2_begin) return true;
            else return false;
            // == (Negation)
            // t1_begin == iter.t1_begin && t2_begin == iter.t2_begin
        }
        auto operator*() const { 
        if(t1_begin != t1_end) return *t1_begin;
        else return *t2_begin;
        } 
       
     }; // End Struct const_iterator
        
        const_iterator begin() const { return const_iterator(a.begin(),a.end(),b.begin(),b.end()); }
        const_iterator end() const { return const_iterator(a.begin(),a.end(),b.begin(),b.end(),false); }
    };
}

#endif