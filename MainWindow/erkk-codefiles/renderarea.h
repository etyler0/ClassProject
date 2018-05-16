/******************************
 * Render Area - Creates the
 * widget where the shapes
 * will be rendered
 ******************************/

#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPixmap>
#include "shape.h"
#include "vector.h"

//! renderArea - manages the rendering of the shapes
//!
//! \author kevin (5/15/18)
class renderArea: public QWidget
{
    //! constructor - create a Qwidget that points to its parent in the rendering tree
    //!
    //! \author edt (5/15/18)
    //!
    //! \param parent QWidget
    renderArea(QWidget* parent=0);

    //! setShape - sets our internal member with the appwide MyVector<Shape> pointer
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param source  - Pointer to Myvector<Shape> 
    void setShape(nserkkvector::MyVector<Shape*> source);

    //! getShape - returns pointer to specific shape from vector
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param int 
    //!
    //! \return Shape* 
    Shape* getShape(int);

    //! getShapes - return reference to entire MyVector<Shape>
    //!
    //! \author kevin (5/15/18)
    //!
    //! \return nserkkvector::MyVector&lt;Shape*&gt;&amp; 
    nserkkvector::MyVector<Shape*>& getShapes();

    //! paintEvent - draw the shapes in the rendering area
    //!
    //! \author kevin (5/15/18)
    //!
    //! \param pEvent - QPaintEvent*
    void paintEvent(QPaintEvent *pEvent);

private:
    nserkkvector::MyVector<Shape*> shapes; ///> holds the shapes that the modeler will draw and modify
    renderArea *renderA; ///> holds the canvas object
    


};

#endif // RENDERAREA_H


