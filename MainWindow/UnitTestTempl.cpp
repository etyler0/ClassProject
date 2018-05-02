// --------------------------------------------------------------------------
// CS1C - Class Project-Temoplated Vector Class Tester
// Copyright Eugene Dale Tyler 2018 under the BSD license. All rights Reserved
//
// --------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "time.h"
#include <ostream>
#include <iostream>
#include <string.h>

#include "UnitTestTempl.h"
#include "vector.h"

using namespace std;
using namespace nserkkvector;

//! main - Entry point for program
//!
//! \author edt (2/1/18)
//!
//! \param argc - count of arguments supplied
//! \param argv - array of pointers to arguments
//!
//! \return int 
int main(int argc, char* argv[])
{
    int opt;
    bool unittest = false;
#ifdef UNITTESTFILE_SUPPORT
    bool unittestfile = false;
    char *unittestfilename = NULL;
#endif

    while ((opt = getopt(argc,argv,"tf:u")) != EOF)
    {
        switch(opt)
        {
            case 't':
            {
                unittest = true;
                break;
            }

#ifdef UNITTESTFILE_SUPPORT
            case 'f':
            {
                unittestfile = true;
                unittestfilename = optarg;
                break;
            }
#endif
            
            case '?':
            {
                cout << "Usage CS1C <-t - select unit test> <-f unittestfilename>" << endl;
                return 1;
            }

            default:
            {
                cout << "Invalid option specified - try ? for usage" << endl;
                abort();
            }
        }
    }

    if (unittest)
    {
        if (!RunUnitTests())
        {
            cout << "Unit tests failed" << endl;
        }
        else
        {
            cout << "Unit Tests passed" << endl;
        }
    }
    else
    {
        cout << "hello" << endl;
    }
    
    return 0;
}

//! RunUnitTests - executes specified unit tests
//!
//! \author edt (1/22/18)
//!
//! \param testnum 
//!
//! \return bool - indicates if an error occurred
bool RunUnitTests(int testnum)
{
    bool retcode;
    int fill = 3;
    MyVector<int> *pvti = new MyVector<int>(7, fill);
    MyVector<int> *pvtie = new MyVector<int>;

    if (testnum < FIRST_TEST || testnum > LAST_TEST)
    {
        return false;
    }

    while (testnum <= LAST_TEST)
    {
        switch (testnum)
        {
            //  Templated Vector Tests - Integer
            case MVTI_CREATE_VECTOR_TEST_EMPTY:
            {
                retcode = true;

                cout << endl << "=========== Templated int Vector" << endl;
                cout << "starting unit test# " << testnum << " - Test for vector empty" << endl;

                if (pvtie->size())
                {
                    retcode = false;
                    break;
                }

                pvtie->printAsDebug(false, true);
                cout << endl;
                pvti->printAsDebug(false, true);
                cout << endl;

                break;
            }

            case MVTI_ADD_SIX_PREFILLED:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- add six to previosly filled vector" << endl;

                for (int i = 0; i < 6; i++)
                {
                    pvti->push_back(i);
                }

                pvti->printAsDebug(false, true);
                cout << endl;

                break;
            }

            case MVTI_ADD_FIVE_EMPTY:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- add five to empty template" << endl;

                for (int i = 0; i < 5; i++)
                {
                    pvtie->push_back(i);
                }

                pvtie->printAsDebug(false, true);
                cout << endl;

                break;
            }

            case MVTI_TEST_INSERT:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- insert element to beginning, end and middle of vector template" << endl;

                MyVector<int>::iterator itr1 = pvti->begin();
                pvti->insert(itr1, 99);
                pvti->printAsDebug(false, true);
                cout << endl;
                itr1 +=3;
                pvti->insert(itr1, 999);
                pvti->printAsDebug(false, true);
                cout << endl;
                itr1 = pvti->end();
                pvti->insert(itr1, 9999);
                pvti->printAsDebug(false, true);
                cout << endl;
                break;
            }

            case MVTI_TEST_ERASE:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- erase element at beginning, end and middle of vector template" << endl;

                MyVector<int>::iterator itr1 = pvti->begin();
                pvti->erase(itr1);
                pvti->printAsDebug(false, true);
                cout << endl;
                itr1 +=3;
                pvti->erase(itr1);
                pvti->printAsDebug(false, true);
                cout << endl;
                itr1 = pvti->end();
                pvti->erase(itr1);
                pvti->printAsDebug(false, true);
                cout << endl;

                break;
            }

            case MVTI_TEST_SUBSCRIPTOP:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- retrieve element from beginning, end and middle of vector template" << endl;

                pvti->printAsDebug(false, true);
                cout << endl;
                int elem;

                elem = (*pvti)[0];
                cout << "Element 0:"  << elem << endl;

                elem = (*pvti)[3];
                cout << "Element3:"  << elem << endl;

                elem = (*pvti)[pvti->size()-1];
                cout << "Element last:"  << elem << endl;

                break;
            }

            case MVTI_TESTCOPYCONST:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- copy constructor" << endl;
                cout << "Source Vector" << endl;
                pvtie->printAsDebug(false, true);
                cout << endl;
                MyVector<int> *pvtic = new MyVector<int>(*pvtie);
                cout << "Copied Vector" << endl;
                pvtic->printAsDebug(false, true);
                cout << endl;
                cout << "Note: Compare manually" << endl;

                delete pvtic;

                break;
            }

            case MVTI_TESTASSIGN:
            {
                retcode = true;
                cout << "starting unit test# " << testnum << "- assignment operator" << endl;

                cout << "Source Vector" << endl;
                pvti->printAsDebug(false, true);
                cout << endl;
                MyVector<int> *pvtia = new MyVector<int>;
                MyVector<int> *pvtiae = new MyVector<int>;
                *pvtia = *pvtiae;
                pvtia->printAsDebug(false, true);
                cout << endl;

                delete pvtia;
                delete pvtiae;
                break;
            }
            case MVTI_DELETE_VECTOR:
            {
                delete pvti;
                delete pvtie;
                break;
            }

            default:
            {
                // undefined test - error
                retcode = false;
                break;
            }

            }

            if (!retcode)
            {
                break; // exit while
            }
            testnum++;  // next test
        }

    return retcode;
}
