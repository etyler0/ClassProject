// --------------------------------------------------------------------------
// CS1C - Class Project - vector.h
// a vector which approximates the stl vector
// Copyright ERKK 2018 under the Apache 2.0 license. All rights Reserved
//
// --------------------------------------------------------------------------

#ifndef ERKK_VECTOR_H
#define ERKK_VECTOR_H

#include <iostream>
#include <exception>
using namespace std;

namespace nserkkvector
{

//! MyVector - minimal vector class - partial implementation of STL vector
//!
//! \author edt (5/14/18)
template<class T>
class MyVector
{
    int m_nCurSize;      ///< the number of elements currently in vector
    int m_nAllocated;    ///< allocated = size+free_space
    T* m_pElem;          ///< a pointer to the elements

public:
    using iterator = T*;
    using const_iterator = const T*;

   
    //! MyVector default constructor - create an empty vector
    //!
    //! \author edt (5/14/18)
    MyVector() : m_nCurSize{0}, m_nAllocated{0}, m_pElem{nullptr} {}  // default constructor

    //! MyVector constructor - create a vector of specified size
    //!
    //! \author edt (5/14/18)
    //!
    //! \param size - number of elements -1 that vector may contain
    //! \param fillElem - sample element to put in each entry in vector 
    explicit MyVector(int alloc_size, T &fillElem = T())             // alternate constructor
        : m_nCurSize{alloc_size}, m_nAllocated{alloc_size}
    {
        if (alloc_size <= 0)
        {
            throw (new std::logic_error("Vector size <= 0"));
        }
        m_pElem = new T[alloc_size];
        memset(m_pElem, 0, sizeof(T)*alloc_size);

        for (iterator fill = begin(); fill < end(); fill++)
        {
            *fill = fillElem;
        }
    }

    //! MyVector  copy constructor
    //!
    //! \author edt (5/14/18)
    //!
    //! \param src&amp; - vector to copy elements from
    MyVector(const MyVector<T>& src)              // copy constructor
        : m_nCurSize{src.m_nCurSize}, m_nAllocated{src.m_nAllocated}
    {
        m_pElem = new T[m_nAllocated];
        memset(m_pElem, 0, sizeof(T)*m_nAllocated);

        const_iterator srccopy = src.begin();
        iterator destcopy = begin();
        while (srccopy < src.end())
        {
            *destcopy++ = *srccopy++;
        }
    }

    //! MyVector  copy constructor
    //!
    //! \author edt (5/14/18)
    //!
    //! \param rhs&amp; - vector to copy elements from
    //!
    //! \return MyVector&amp; 
    MyVector& operator=(const MyVector& rhs) // copy assignment
    {
        if (m_nAllocated != rhs.m_nAllocated)
        {
            // delete old contents of this vector, if any
            if (m_pElem != nullptr )
            {
                delete [] m_pElem;
                m_pElem = nullptr;  // in case rhs is zero size vector
            }

            // allocate space for entire content of rhs, if any
            if (rhs.m_nAllocated != 0)
            {
                m_pElem = new T[rhs.m_nAllocated];
                memset(m_pElem, 0, sizeof(T)*m_nAllocated);
            }

            // copy the rhs characteristics
            m_nAllocated = rhs.m_nAllocated;
            m_nCurSize = rhs.m_nCurSize;
        }

        if (rhs.m_nAllocated != 0)
        {
            const_iterator rhscopy = rhs.begin();
            iterator destcopy = begin();
            while (rhscopy != rhs.end())
            {
                *destcopy++ = *rhscopy++;
            }
        }

        return *this;
    }

    //! Destructor - simply free the object space and array of elements
    //!
    //! \author edt (5/13/18)
    ~MyVector()
    {
        delete [] m_pElem;
    }

    //! MyVector iterator - get first element address
    //!
    //! \author edt (5/14/18)
    //!
    //! \return pointer to first element 
    iterator begin()                   // points to first element
    {
        if (m_nCurSize == 0)
        {
            return nullptr;
        }
        return &m_pElem[0];
    }

    //! MyVector iterator - get first element address - const
    //!
    //! \author edt (5/14/18)
    //!
    //! \return pointer to const first element 
    const_iterator begin() const
    {
        if (m_nCurSize == 0)
        {
            return nullptr;
        }
        return &m_pElem[0];
    }

    //! MyVector iterator - get last element address
    //!
    //! \author edt (5/14/18)
    //!
    //! \return pointer to last element 
    iterator end() // points to one beyond the last element
    {
        if (m_nCurSize == 0)
        {
            return nullptr;
        }
        return &m_pElem[m_nCurSize];
    }

    //! MyVector iterator - get last element address - const
    //!
    //! \author edt (5/14/18)
    //!
    //! \return pointer to const lst element 
    const_iterator end() const
    {
        if (m_nCurSize == 0)
        {
            return nullptr;
        }
        return &m_pElem[m_nCurSize];
    }

    //! reserve - allocate more space to vector
    //!
    //! \author edt (5/14/18)
    //!
    //! \param alloc_size - number of elements -1 that can be contained
    void reserve(int alloc_size)         // get more space
    {
        if (alloc_size <= 0)
        {
            throw (new std::logic_error("Vector size <= 0"));
        }
        T *pNewElem = new T[alloc_size];
        memset(pNewElem, 0, sizeof(T)*alloc_size);
        m_nAllocated = alloc_size;
        for (int i = 0; i < m_nCurSize; i++)
        {
            pNewElem[i] = m_pElem[i];
        }
        delete [] m_pElem;
        m_pElem = pNewElem;
    }

    //! insert - place new element into vector before element specified by iterator
    //!
    //! \author edt (5/14/18)
    //!
    //! \param position - location before which to insert new element
    //! \param newval - element to insert
    //!
    //! \return iterator&amp; - location of new element
    iterator insert(iterator position, const T& newval) // insert a new element v before p
	{
        if ( (m_nCurSize + 1) >= m_nAllocated)
        {
            int posOffset = position - begin(); // preserve offset into array in case of expansion
            if (m_nAllocated < 8)
            {
                m_nAllocated = 8;
            }
            m_nAllocated *= 2;
            reserve(m_nAllocated);
            position = begin() + posOffset;
        }

        m_nCurSize++;

        // move elements after position one slot higher to make room for new element
        for (iterator moveup = (end() - 1); moveup != position; moveup--) // error - should be end() NOT -1
        {
            *moveup = *(moveup -1);
        }

        *position = newval;
        return position;
	}

    //! erase - remove element specifieed
    //!
    //! \author edt (5/14/18)
    //!
    //! \param position - location of element to delete
    //!
    //! \return iterator&amp; - location of element now at specified location
    iterator erase(iterator position)         // remove element pointed to by p
    {
        if (position == end())
        {
            // deleting dummy element at end is a no-op
            return position;
        }

        for (iterator movedown = (position + 1); movedown != end(); movedown++)
        {
            *(movedown -1) = *movedown;
        }

        m_nCurSize--;
        return position;
    }

    //! operator[] - return pointer to specified element
    //!
    //! \author edt (5/14/18)
    //!
    //! \param n - element number (0 based) to return
    //!
    //! \return iterator&amp; - location of element at specified location
    T operator [](int n) { return m_pElem[n]; };                     // access: return reference

    //! operator[] - return pointer to specified element - pointer to const
    //!
    //! \author edt (5/14/18)
    //!
    //! \param n - element number (0 based) to return
    //!
    //! \return iterator&amp; - location of element at specified location
    const T& operator [](int n) const { return m_pElem[n]; };        // access: return reference

    //! size - return number of elements in the vector
    //!
    //! \author edt (5/14/18)
    //!
    //! \return int
    int size() const { return m_nCurSize; };         // the current size

    //! capacity - return number of possible elements in the vector + 1
    //!
    //! \author edt (5/14/18)
    //!
    //! \return int
    int capacity() const { return m_nAllocated; }    // current available space

    //! resize - add storage to contain specified number of elements - 1
    //!
    //! \author edt (5/14/18)
    //!
    //! \param alloc_size - number of elements desired -1
    void resize(int alloc_size)           // grow
    {
        if (alloc_size > m_nAllocated)
        {
            reserve(alloc_size);
        }

        T initElem(); // avoid multiple default constructor calls
        for (int i = m_nCurSize; i < alloc_size; ++i)
        {
             m_pElem[i] = initElem; // initialize new elements
        }
        m_nCurSize = alloc_size;
    }

    //! push_back - add element to end of vector - resize if needed
    //!
    //! \author edt (5/14/18)
    //!
    //! \param alloc_size - number of elements desired -1
    void push_back(const T &new_elem)           // add element
    {
        if ( (m_nCurSize + 1) >= m_nAllocated)
        {
            if (m_nAllocated < 8)
            {
                m_nAllocated = 8;
            }
            m_nAllocated *= 2;
            reserve(m_nAllocated);
        }
        m_pElem[m_nCurSize] = new_elem;
        m_nCurSize++;
    }

    //! printAsDebug - print control structures and elements, if desired for debugging
    //!
    //! \author edt (5/14/18)
    //!
    //! \param printeol - print end of line after each feild/element being printed
    //! \param printcontent - print information about elements in the vector
    void printAsDebug(bool printeol, bool printcontent) const
    {
        cout << "ObjAddr:" << std::hex << std::uppercase << "0x" << (unsigned long long)this << std::nouppercase << std::dec;
        if (printeol)
        {
            cout << endl;
        }
        cout << " Size:" << m_nCurSize;
        if (printeol)
        {
            cout << endl;
        }
        cout << " Allocated:" << m_nAllocated;
        if (printeol)
        {
            cout << endl;
        }
        if (printcontent)
        {
            for (int i = 0; i < m_nCurSize; i++)
            {
                cout << " E#" << i << ":" << m_pElem[i];
                if (printeol)
                {
                    cout << endl;
                }
            }
        }
    }

};

}

#endif
