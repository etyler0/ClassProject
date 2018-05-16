#ifndef PARSER_H
#define PARSER_H

#include "vector.h"

using namespace nserkkvector;

void readFile(QPaintDevice *device, MyVector<Shape *> *pShapeVector);
void writeFile(MyVector<Shape *> *pShapeVector);

#endif // PARSER_H
