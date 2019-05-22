#ifndef ZIP_HPP
#define ZIP_HPP

#include <iostream>

namespace itertools {

template <typename T1, typename T2> class zip {
        private:
        T1 a; // range(5,8) for Example
        T2 b; // range(9,10) for Example
        
        public:
        zip(T1 r1,T2 r2) : a(r1), b(r2) {}

    class const_iterator {  
      template <typename V, typename K>
      class MyPair {
      V v;
      K k;
      public:
      MyPair(const V& v, const K& k) : v(v), k(k) {}
      MyPair() {}

      friend std::ostream& operator<<(std::ostream& os,const MyPair<V,K>& pair)
      {
        return os << pair.v << "," << pair.k;
      }
      }; // End Class MyPair

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
         ++ t1_begin;
         ++ t2_begin;
        return *this; 
        }

        MyPair<decltype(*t1_begin),decltype(*t2_begin)> operator*() const { 
        return MyPair<decltype(*t1_begin),decltype(*t2_begin)> (*t1_begin,*t2_begin);
        } 

        bool operator != (const const_iterator& iter) const {
            if( t1_begin != iter.t1_begin && t2_begin != iter.t2_begin) return true;
            else return false;
            // == (Negation)
            // t1_begin == iter.t1_begin || t2_begin == iter.t2_begin
        }       
     }; // End Struct const_iterator
        
        const_iterator begin() const { return const_iterator(a.begin(),a.end(),b.begin(),b.end()); }
        const_iterator end() const { return const_iterator(a.begin(),a.end(),b.begin(),b.end(),false); }
    };
} // end namespace


#endif