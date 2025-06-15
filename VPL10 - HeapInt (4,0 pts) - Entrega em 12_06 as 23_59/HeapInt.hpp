#ifndef HEAPINT
#define HEAPINT

#include <iostream>
#include <string>

using namespace std;

class HeapInt{
    public:
    int* coisa;

    public:
    HeapInt();
    HeapInt(int n);
    HeapInt(const HeapInt& hi);
    HeapInt& operator = (int n);
    HeapInt& operator = (const HeapInt& hi) ;
    HeapInt operator + (const HeapInt& hi) const;
    HeapInt operator - (const HeapInt& hi) const;
    bool operator == (const HeapInt& hi) const;
    friend ostream& operator << (ostream& os, const HeapInt& hi);
    friend istream& operator >> (istream& is, HeapInt& hi);
    ~HeapInt();

};

#endif