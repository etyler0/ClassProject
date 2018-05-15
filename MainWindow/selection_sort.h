#ifndef __SELECTION_SORT_H_INCL__
#define __SELECTION_SORT_H_INCL__


namespace nserkkselsort
{

//! selection_sort - an O(n**2) simple sort - relatively ineffcient iterative
//!                  that steps through a collection and exchanges the current
//!                  element with the element in the remainder of the collection
//!                  that has the lowest value
//!
//! \author edt (5/8/18)
//!
//! \param first - collection iterator first element to scan
//! \param last -  collection iterator last+1 element to scan 
//! \param complessfunc - functor/predicate that returns true if a<b
//!
//! \return None 
template <typename iterator, typename LessCompare>
void selection_sort(iterator first, iterator last, LessCompare complessfunc)
{
    while (first != last)
    {
        iterator minelem = first;
        iterator compare = first;
        ++compare;

        // inner loop scans from current position in collection to end
        // we casn ignore all elements in the collection prior to the
        // the current position are already sorted in ascending order
        while (compare != last)
        {
            if (complessfunc(*compare, *minelem))
            {
                // element further into the collection content is less than 
                // the element's content from the outer loop
                minelem = compare;
            }
            ++compare; // continue scanning to find lowest element
        }

        // set lowest unsorted eleemnt to contain new minuimum value
        if (first != minelem)
        {
            std::iter_swap(first, minelem);
        }
        ++first;
    }
}

}
#endif // __SELECTION_SORT_H_INCL__

