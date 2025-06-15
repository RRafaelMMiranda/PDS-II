
#include <iostream>
#include <string>
#include "HeapInt.hpp"

using namespace std;

    HeapInt::HeapInt() : HeapInt(0) {};
    HeapInt::HeapInt(int n)
    {
        this->coisa = new int;
        *coisa = n;
    };
    HeapInt::HeapInt(const HeapInt& hi)
    {
        this->coisa = new int;
        *(this->coisa) = *(hi.coisa);
    };
    HeapInt& HeapInt::operator=(int n)
    {
        *(this->coisa) = n;
        return *(this);
    }
    HeapInt& HeapInt::operator=(const HeapInt& hi)
    {
        *(this->coisa) = *(hi.coisa);
        return *(this);
    }
    HeapInt HeapInt::operator + (const HeapInt& hi) const
    {
        HeapInt aux;
        *(aux.coisa) = *(this->coisa) + *(hi.coisa);
        return aux;
    }
    HeapInt HeapInt::operator - (const HeapInt& hi) const
    {
        HeapInt aux;
        *(aux.coisa) = *(this->coisa) - *(hi.coisa);
        return aux;
    }
    bool HeapInt::operator == (const HeapInt& hi) const
    {
        return (*(this->coisa) == *(hi.coisa));
    }
    ostream& operator << (ostream& os, const HeapInt& hi) 
    {
        return os << *(hi.coisa);
    }
    istream& operator >> (istream& is, HeapInt& hi)
    {
        return (is >> *(hi.coisa));
    }
    HeapInt::~HeapInt()
    {
        delete this->coisa;
    }