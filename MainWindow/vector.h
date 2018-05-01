// --------------------------------------------------------------------------
// CS1C - Class Project - vector.h
// a vector which approximates the stl vector
// Copyright ERKK 2018 under the Apache 2.0 license. All rights Reserved
//
// --------------------------------------------------------------------------

#ifndef ERKK_VECTOR_H
#define ERKK_VECTOR_H

namespace ns_erkk_vector
{

template<class T>
class vector
{
    int size_v;     // the size
    T* elem;        // a pointer to the elements
    int space;      // size+free_space

    vector();                           // default constructor
    explicit vector(int s);             // alternate constructor

public:
    vector(const vector&);              // copy constructor
    vector& operator=vector(const vector&); // copy assignment
    vector(const vector&&);             // move constructor
    vector& operator=vector(const vector&&); // move assignment
    ~vector() // destructor

    T& operator[] (int n);              // access: return reference
    const T& operator[] (int n);        // access: return reference

    int size() const;                   // the current size
    int capacity() const;               // current available space
    void resize(int newsize);           // grow
    void push_back(double d);           // add element
    void reserve(int newalloc);         // get more space

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin();                   // points to first element
    const_iterator begin() const;
    iterator end();/ points to one beyond the last element
    const_iterator end() const;

    iterator insert(iterator p, const T& v); // insert a new element v before p
    iterator erase(iterator p);         // remove element pointed to by p

    // TODO: Add the implemenations

};

}

#endif
