#ifndef PARSER_H
#define PARSER_H

#include "vector.h"

using namespace nserkkvector;

//! readfile - read shapes.txt from disk and populate a vector containing
//!            the parsed shapes
//!
//! \author kole 05/15/18)
//!
//! \param device - QPaintDevice *
//! \param pShapeVector - Pointer to Myvector<Shape> to fill in
void readFile(QPaintDevice *device, MyVector<Shape *> *pShapeVector);

//! writefile - iterate through vector containing shapes, convert them
//!             to external format and write them back to shapes.txt
//!
//! \author kole (5/15/18)
//!
//! \param pShapeVector - Pointer to Myvector<Shape> to iterate 
void writeFile(MyVector<Shape *> *pShapeVector);

#endif // PARSER_H
