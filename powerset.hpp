
#ifndef POWERSET_HPP
#define POWERSET_HPP

#include <iostream>
#include <vector> 
#include <cmath>

namespace itertools {
template <typename T> class powerset {
        
        private:
        T _object; // Range (1,5) for example

        public:        
        powerset(const T& _object) :_object(_object) {} 
        
    struct const_iterator {
        const_iterator(typename T::const_iterator it_begin,int n, int N) : it_begin(it_begin), n(n), N(N) {}
        const_iterator& operator++(){  ++N; return *this; }       
        
        std::string operator*() const { 
        std::string ans;
        ans += "{";
        for(int j=0; j<n; j++)
        {
            if( N & (1<<j)) {
                auto at_j = At(j);
                add_to_string(ans,at_j);
                ans += ",";
            }
        }
        ans = ans.substr(0,ans.find_last_of(","));
        ans += "}";
        return ans;
        } 

        bool operator!=(const const_iterator& iter) const { return N != iter.N; }
        
        private:
        typename T::const_iterator it_begin;
        int n; // Size of the total _ _ _ _ 
        int N; // pow of n

        auto At(int j) const {
        auto temp = it_begin;
        for(int i=0; i<j; i++)
             ++temp;
        return *temp;
        }
        template <typename U>
        void add_to_string(std::string& ans, U var ) const {
            ans += std::to_string(var);
        }
        void add_to_string(std::string& ans, char var ) const {
            ans += var;
        }  
     }; // End Struct const_iterator
        
        const_iterator begin() const {
            int counter = 0;
            for(auto p : _object) counter++;      
             return const_iterator(_object.begin(),counter,0); 
        }
        const_iterator end() const { 
            int counter = 0;
            for(auto p : _object) counter++;
            return const_iterator(_object.begin(),counter,pow(2,counter));
        }
    };
} // End Namespace 'itertools'

#endif