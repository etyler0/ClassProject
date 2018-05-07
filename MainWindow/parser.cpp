#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include <Qt>
#include <QFont>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vector.h"
#include "rectangle.h"

using namespace std;

using namespace nserkkvector;

#if 0
//void readFile(vector<string> shapesVec, vector<int> shapeIdVec,
//              vector<int> penColorVec, vector<int> penWidthVec,
//              vector<int> penStyleVec, vector<int> penCapStyleVec,
//              vector<int> penJoinStyleVec, vector<int> brushColorVec,
//              vector<int> brushStyleVec, vector<string> textStringVec,
//              vector<int> textColorVec, vector<int> textAlignmentVec,
//              vector<int> textPointSizeVec, vector<string> fontFamilyVec,
//              vector<int> fontStyleVec, vector<int> fontWeightVec);

void readFile(QPaintDevice *device);

// testing only
int main(int argc, char *argv[])
{


        vector<string> shapesVec;
        vector<int> shapeIdVec;
        vector<int> penColorVec;
        vector<int> penWidthVec;
        vector<int> penStyleVec;
        vector<int> penCapStyleVec;
        vector<int> penJoinStyleVec;
        vector<int> brushColorVec;
        vector<int> brushStyleVec;
        vector<string> textStringVec;
        vector<int> textColorVec;
        vector<int> textAlignmentVec;
        vector<int> textPointSizeVec;
        vector<string> fontFamilyVec;
        vector<int> fontStyleVec;
        vector<int> fontWeightVec;

        ifstream fin;

//        readFile(shapesVec, shapeIdVec, penColorVec, penWidthVec, penStyleVec,
//                penCapStyleVec, penJoinStyleVec, brushColorVec, brushStyleVec,
//                 textStringVec, textColorVec, textAlignmentVec, textPointSizeVec,
//                 fontFamilyVec, fontStyleVec, fontWeightVec);

        readfile(device);

        QApplication a(argc, argv);
        MainWindow w;
        w.show();



    return a.exec();
}

//void readFile(vector<string> shapesVec, vector<int> shapeIdVec,
//              vector<int> penColorVec, vector<int> penWidthVec,
//              vector<int> penStyleVec, vector<int> penCapStyleVec,
//              vector<int> penJoinStyleVec, vector<int> brushColorVec,
//              vector<int> brushStyleVec, vector<string> textStringVec,
//              vector<int> textColorVec, vector<int> textAlignmentVec,
//              vector<int> textPointSizeVec, vector<string> fontFamilyVec,
//              vector<int> fontStyleVec, vector<int> fontWeightVec)
//
//{
#endif


// FIXME suggestions:
//1) We need to parse the ShapeDimensions String.
//See https://stackoverflow.com/questions/11719538/how-to-use-stringstream-to-separate-comma-separated-strings
//2) No real need for vectors, just create the objects.
//3) I provided an example for Rectangle, but did not capture all of the colors, etc
//4) I will provide the rest of the object dfinitions shortly in Git
//5) You might want to look for "ShapeId" in the file and use the id from that
//6) I commented out your main and moded the vectors to readline - which can be removed (I think)
//7) You will need a writeFile function that takes a pointer to MyVector<Shape *>, which you can the iterate through and write the same lines back to the file


// QPiantDevice * will be passed in from main in Qt application
void readFile(QPaintDevice *device, MyVector<Shape *> *pShapeVector)
{

    vector<string> shapesVec;
    vector<int> shapeIdVec;
    vector<int> penColorVec;
    vector<int> penWidthVec;
    vector<int> penStyleVec;
    vector<int> penCapStyleVec;
    vector<int> penJoinStyleVec;
    vector<int> brushColorVec;
    vector<int> brushStyleVec;
    vector<string> textStringVec;
    vector<int> textColorVec;
    vector<int> textAlignmentVec;
    vector<int> textPointSizeVec;
    vector<string> fontFamilyVec;
    vector<int> fontStyleVec;
    vector<int> fontWeightVec;
    ifstream fin;
    ofstream fout;
    string file;
    string fileSave;

    //For Shapes: All
    int shapeId;
    string shapeName;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;

    //For Shapes: Polygon
    string brushColor;
    string brushStyle;
    int brushIndex;

    //For Shapes: Text
    string textString;
    string textColor;
    string textAlignment;
    int textPointSize;
    string fontFamily;
    string fontStyle;
    string fontWeight;
    int textIndex;

    //Initialize
    shapeId = 0;
    brushIndex = 0;
    textIndex = 0;


//    cout << "What file would you like to load?" << endl;
//    cin >> file;
    //Open File
    fin.open("./shapes.txt");

    while(fin)
    {
        //getline(fin, shapeID);
        fin >> shapeId;
        
        shapeIdVec.push_back(shapeId);
        fin.ignore();
        getline(fin,shapeName);

        if (shapeName == "Line")
        {
            shapesVec.push_back(shapeName); //Puts name of shape into Vector

            getline(fin, penColor);         //Pulls pen color from file
            if(penColor == "blue")
            {
                penColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
            }
            else if(penColor == "green")
            {
                   penColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
            }

            fin >> penWidth;
            penWidthVec.push_back(penWidth);
            fin.ignore();


            getline(fin, penStyle);
            if(penStyle == "NoPen")
            {
                penStyleVec.push_back(Qt::PenStyle::NoPen);
            }
            else if(penStyle == "SolidLine")
            {
                penStyleVec.push_back(Qt::PenStyle::SolidLine);
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
            }

            getline(fin, penCapStyle);
            if(penCapStyle == "FlatCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::FlatCap);
            }
            else if(penCapStyle == "SquareCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::SquareCap);
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
            }

            getline(fin, penJoinStyle);
            if(penJoinStyle == "MiterJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::MiterJoin);
            }
            else if(penJoinStyle == "BevelJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::BevelJoin);
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
            }
            fin.ignore();
        }
        else if(shapeName == "Polyline") //Different shape
        {
            shapesVec.push_back(shapeName);

            getline(fin, penColor);
            if(penColor == "blue")
            {
                penColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
            }
            else if(penColor == "green")
            {
                   penColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
            }

            fin >> penWidth;
            penWidthVec.push_back(penWidth);

            fin.ignore();
            getline(fin, penStyle);
            if(penStyle == "NoPen")
            {
                penStyleVec.push_back(Qt::PenStyle::NoPen);
            }
            else if(penStyle == "SolidLine")
            {
                penStyleVec.push_back(Qt::PenStyle::SolidLine);
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
            }

            getline(fin, penCapStyle);
            if(penCapStyle == "FlatCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::FlatCap);
            }
            else if(penCapStyle == "SquareCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::SquareCap);
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
            }

            getline(fin, penJoinStyle);
            if(penJoinStyle == "MiterJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::MiterJoin);
            }
            else if(penJoinStyle == "BevelJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::BevelJoin);
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
            }
        }
        else if(shapeName == "Polygon" || shapeName == "Rectangle"
                || shapeName == "Square" || shapeName == "Ellipse"
                || shapeName == "Circle") //Different shapes
        {
            shapesVec.push_back(shapeName);

            getline(fin, penColor);
            QColor PenColor;
            if(penColor == "blue")
            {
                penColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
                PenColor = Qt::GlobalColor::blue;  // do this for the other colors
            }
            else if(penColor == "green")
            {
                   penColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
            }

            fin >> penWidth;
            penWidthVec.push_back(penWidth);

            fin.ignore();
            getline(fin, penStyle);
            Qt::PenStyle PenStyle;
            if(penStyle == "NoPen")
            {
                penStyleVec.push_back(Qt::PenStyle::NoPen);
                PenStyle = Qt::PenStyle::NoPen;
            }
            else if(penStyle == "SolidLine")
            {
                penStyleVec.push_back(Qt::PenStyle::SolidLine);
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
            }

            getline(fin, penCapStyle);
            Qt::PenCapStyle PenCapStyle;
            if(penCapStyle == "FlatCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::FlatCap);
                PenCapStyle = Qt::PenCapStyle::FlatCap;
            }
            else if(penCapStyle == "SquareCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::SquareCap);
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
            }

            
            getline(fin, penJoinStyle);
            Qt::PenJoinStyle PenJoinStyle;
            if(penJoinStyle == "MiterJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::MiterJoin);
                PenJoinStyle = Qt::PenJoinStyle::MiterJoin;
            }
            else if(penJoinStyle == "BevelJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::BevelJoin);
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
            }

            
            //BrushColor
            getline(fin, brushColor);
            QColor BrushColor;
            if(brushColor == "blue")
            {
                brushColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
                BrushColor = Qt::GlobalColor::blue;
            }
            else if(brushColor == "green")
            {
                   brushColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
            }
            else if(brushColor == "cyan")
            {
                   brushColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
            }
            else if(brushColor == "red")
            {
                   brushColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
            }
            else if(brushColor == "black")
            {
                   brushColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
            }
            else if(brushColor == "white")
            {
                   brushColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
            }
            else if(brushColor == "magenta")
            {
                   brushColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
            }
            else if(brushColor == "yellow")
            {
                   brushColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
            }
            else if(brushColor == "gray")
            {
                   brushColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
            }

            
            getline(fin, brushStyle);
            Qt::BrushStyle BrushStyle;
            if(brushStyle == "SolidPattern")
            {
                brushStyleVec.push_back(Qt::BrushStyle::SolidPattern);
                BrushStyle = Qt::BrushStyle::SolidPattern;
            }
            else if(brushStyle == "HorPattern")
            {
                brushStyleVec.push_back(Qt::BrushStyle::HorPattern);
            }
            else if(brushStyle == "VerPattern")
            {
                brushStyleVec.push_back(Qt::BrushStyle::VerPattern);
            }
            else if(brushStyle == "NoBrush")
            {
                brushStyleVec.push_back(Qt::BrushStyle::NoBrush);
            }


            // Actually construct the object
            if (shapeName == "Rectangle")
            {
                int tlx, tly, w, h;  // Note - these need to be parsed
                Rectangle rect1(device, shapeId, PenColor, penWidth, PenStyle,
                                PenCapStyle, PenJoinStyle, BrushColor, BrushStyle, tlx, tly, w, h );
                pShapeVector->push_back((Shape *)&rect1);
            }
        }
        else if(shapeName == "Text")
        {
            shapesVec.push_back(shapeName);

            
            getline(fin, textString);
            textStringVec.push_back(textString);

            
            
            getline(fin, textColor);
            if(textColor == "blue")
            {
                textColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
            }
            else if(textColor == "green")
            {
                   textColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
            }
            else if(textColor == "cyan")
            {
                   textColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
            }
            else if(textColor == "red")
            {
                   textColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
            }
            else if(textColor == "black")
            {
                   textColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
            }
            else if(textColor == "white")
            {
                   textColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
            }
            else if(textColor == "magenta")
            {
                   textColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
            }
            else if(textColor == "yellow")
            {
                   textColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
            }
            else if(textColor == "gray")
            {
                   textColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
            }

            
            
            getline(fin, textAlignment);
            if(textAlignment == "AlignLeft")
            {
                textAlignmentVec.push_back(Qt::AlignmentFlag::AlignLeft);
            }
            else if(textAlignment == "AlignRight")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignRight);
            }
            else if(textAlignment == "AlignTop")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignTop);
            }
            else if(textAlignment == "AlignBottom")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignBottom);
            }
            else if(textAlignment == "AlignCenter")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignCenter);
            }


            fin >> textPointSize;
            textPointSizeVec.push_back(textPointSize);
            fin.ignore();

            
            getline(fin, fontFamily);
            fontFamilyVec.push_back(fontFamily);

            
            
            getline(fin, fontStyle);
            if(fontStyle == "StyleNormal")
            {
                fontStyleVec.push_back(QFont::Style::StyleNormal);
            }
            else if(fontStyle == "StyleItalic")
            {
                fontStyleVec.push_back(QFont::Style::StyleItalic);
            }
            else if(fontStyle == "StyleOblique")
            {
                fontStyleVec.push_back(QFont::Style::StyleOblique);
            }


            getline(fin, fontWeight);
            if(fontWeight == "Thin")
            {
                fontWeightVec.push_back(QFont::Weight::Thin);
            }
            else if(fontWeight == "Light")
            {
                fontWeightVec.push_back(QFont::Weight::Light);
            }
            else if(fontWeight == "Normal")
            {
                fontWeightVec.push_back(QFont::Weight::Normal);
            }
            else if(fontWeight == "Bold")
            {
                fontWeightVec.push_back(QFont::Weight::Bold);
            }
        }
        else
        {
            cout << "Error: Shape not found" << endl;
        }

    }

    //Prints what was read in to verify that it is working.
    for(unsigned int i = 0; i < shapesVec.size() - 1; i++)
    {
            cout << "ShapeId: "      << shapeIdVec[i]      << endl;
            cout << "ShapeType: "    << shapesVec[i]       << endl;

            if(shapesVec[i] == "Line" || shapesVec[i] == "Polyline"
                    || shapesVec[i]  == "Polygon" || shapesVec[i]  == "Rectangle"
                    || shapesVec[i]  == "Square" || shapesVec[i]  == "Ellipse"
                    || shapesVec[i]  == "Circle")
            {
                cout << "PenColor: "     << penColorVec[i]     << endl;
                cout << "PenWidth: "     << penWidthVec[i]     << endl;
                cout << "PenStyle: "     << penStyleVec[i]     << endl;
                cout << "PenCapStyle: "  << penCapStyleVec[i]  << endl;
                cout << "PenJoinStyle: " << penJoinStyleVec[i] << endl;
            }


        //If these given shapes are specified outputs their respective brush
        //color and style
        if(shapesVec[i]  == "Polygon" || shapesVec[i]  == "Rectangle"
           || shapesVec[i]  == "Square" || shapesVec[i]  == "Ellipse"
           || shapesVec[i]  == "Circle")
        {
                cout << "BrushColor: " << brushColorVec[brushIndex] << endl;
                cout << "BrushStyle: " << brushStyleVec[brushIndex] << endl;
                brushIndex++;
        }
        else if(shapesVec[i] == "Text")
        {
            cout << "TextString: "     << textStringVec[textIndex]    << endl;
            cout << "textColor: "      << textColorVec[textIndex]     << endl;
            cout << "textAlignment: "  << textAlignmentVec[textIndex] << endl;
            cout << "textPointSize: "  << textPointSizeVec[textIndex] << endl;
            cout << "fontFamily: "     << fontFamilyVec[textIndex]    << endl;
            cout << "fontStyle: "      << fontStyleVec[textIndex]     << endl;
            cout << "fontWeight: "     << fontWeightVec[textIndex]    << endl;
            textIndex++;
        }


        cout << endl;
    }


//    cout << "Which file do you want to save to?" << endl;
//    cin  >> fileSave;

//    textIndex = 0;
//    brushIndex = 0;

//    fout.open(fileSave);
//    for(unsigned int i = 0; i < shapesVec.size() - 1; i++)
//    {
//        fout << shapeIdVec[i]      << endl;
//        fout << shapesVec[i]       << endl;

//        if(shapesVec[i] == "Line" || shapesVec[i] == "Polyline")
//        {
//            fout << penColorVec[i]     << endl;
//            fout << penWidthVec[i]     << endl;
//            fout << penStyleVec[i]     << endl;
//            fout << penCapStyleVec[i]  << endl;
//            fout << penJoinStyleVec[i] << endl;
//        }

//        //If these given shapes are specified outputs their respective brush
//        //color and style
//        if(shapesVec[i]  == "Polygon" || shapesVec[i]  == "Rectangle"
//           || shapesVec[i]  == "Square" || shapesVec[i]  == "Ellipse"
//           || shapesVec[i]  == "Circle")
//        {
//            fout << brushColorVec[brushIndex] << endl;
//            fout << brushStyleVec[brushIndex] << endl;
//            brushIndex++;
//        }
//        else if(shapesVec[i] == "Text")
//        {
//            fout << textStringVec[textIndex]    << endl;
//            fout << textColorVec[textIndex]     << endl;
//            fout << textAlignmentVec[textIndex] << endl;
//            fout << textPointSizeVec[textIndex] << endl;
//            fout << fontFamilyVec[textIndex]    << endl;
//            fout << fontStyleVec[textIndex]     << endl;
//            fout << fontWeightVec[textIndex]    << endl;
//            textIndex++;
//        }

//            fout << endl;
//    }

//        fout.close();
          fin.close();
}//End Function

