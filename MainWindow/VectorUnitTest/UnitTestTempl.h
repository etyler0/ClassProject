
// --------------------------------------------------------------------------
// CS1C - Class Project
// Copyright Eugene Dale Tyler 2018 under the BSD license. All rights Reserved
//
// --------------------------------------------------------------------------

#ifndef CS1C_H
#define CS1C_H


enum unittests
{
    FIRST_TEST =    1,
    MVTI_CREATE_VECTOR_TEST_EMPTY =   FIRST_TEST,
    MVTI_ADD_SIX_PREFILLED,
    MVTI_ADD_FIVE_EMPTY,
    MVTI_TESTCOPYCONST,
    MVTI_TESTASSIGN,
    MVTI_TEST_INSERT,
    MVTI_TEST_ERASE,
    MVTI_TEST_SUBSCRIPTOP,
    MVTI_DELETE_VECTOR,
    LAST_TEST = MVTI_DELETE_VECTOR,
};

bool RunUnitTests(int testnum = 1);

typedef unsigned int uint32;

#undef UNITTESTFILE_SUPPORT


#define ASSERT(x)                       \
    if (!(x))                           \
    {                                   \
        cout << "ASSERT Failed" << endl;\
    }                                   \
    else                                \
    {                                   \
        cout << "ASSERT Passed" << endl;\
    }                                   \

#endif /* CS1C_H */
