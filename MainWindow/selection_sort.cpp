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
template <typename TColl, typename TSort>
void selection_sort(TColl first, TColl last, TSort complessfunc)
{
    while (first != last)
    {
        TColl curelem(first);
        // inner loop scans from current position in collection to end
        // we casn ignore all elements in the collection prior to the
        // the current position are already sorted in ascending order
        while (curelem != last)
        {
            if (complessfunc(*curelem, *first))
            {
                // element further into the collection content is less than 
                // the element's content from the outer loop
                TColl tmp(first);
                first = curelem;
                curelem = tmp;
            }
        }
    }
}

}


#endif // __SELECTION_SORT_H_INCL__

