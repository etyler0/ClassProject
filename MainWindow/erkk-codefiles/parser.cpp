#include "mainwindow.h"
#include "polyline.h"
#include "line.h"
#include "square.h"
#include "ellipse.h"
#include "text.h"
#include "polygon.h"
#include "circle.h"
#include <QApplication>
#include <QPainter>
#include <Qt>
#include <QFont>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <QPoint>
#include <QString>

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
//2) No real need for vectors, just create the objects. -Done FIX THE PARAMETERS FOR EACH SHAPE, but rectangle. -Note for self
//3) I provided an example for Rectangle, but did not capture all of the colors, etc
//4) I will provide the rest of the object dfinitions shortly in Git
//5) You might want to look for "ShapeId" in the file and use the id from that
//6) I commented out your main and moded the vectors to readline - which can be removed (I think)
//7) You will need a writeFile function that takes a pointer to MyVector<Shape *>,
//     which you can the iterate through and write the same lines back to the file


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
    vector<QPoint> *newpts1 = new vector<QPoint>();

    //Dimensions
    vector<string> dataDimensions;
    int lineToplx,lineToply,lineBotrx,lineBotry;
    string dimensions;
    string token;
    int tlx, tly, w, h;
    int stlx,stly,xs;
    int ellipseTlx,ellipseTly,ellipseW, ellipseH;
    int circleTlx,circleTly,circleD;
    int textTlx,textTly,textW,textH;

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
    QString textString;
    string textColor;
    string textAlignment;
    int textPointSize;
    QString fontFamily;
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

            dimensions.erase(0);
            getline(fin, dimensions);

            stringstream ss(dimensions);
            while(getline(ss, token, ','))
            {
                dataDimensions.push_back(token);
            }

            for(unsigned int i = 0; i < dataDimensions.size(); i++)
            {
                cout << dataDimensions[i] << " ";
            }

            lineToplx = stoi(dataDimensions[0]);
            lineToply = stoi(dataDimensions[1]);
            lineBotrx = stoi(dataDimensions[2]);
            lineBotry = stoi(dataDimensions[3]);

            QColor PenColor;
            getline(fin, penColor);         //Pulls pen color from file
            if(penColor == "blue")
            {
                penColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
                PenColor = Qt::GlobalColor::blue;
            }
            else if(penColor == "green")
            {
                   penColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::green;
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::cyan;
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::red;
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::black;
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::white;
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::magenta;
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::yellow;
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::gray;
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
                PenStyle = Qt::PenStyle::NoPen;
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
                PenStyle = Qt::PenStyle::DashLine;
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
                PenStyle = Qt::PenStyle::DotLine;
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
                PenStyle =  Qt::PenStyle::DashDotLine;
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
                PenCapStyle = Qt::PenCapStyle::SquareCap;
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
                PenCapStyle = Qt::PenCapStyle::RoundCap;
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
                PenJoinStyle = Qt::PenJoinStyle::BevelJoin;
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
                PenJoinStyle = Qt::PenJoinStyle::RoundJoin;
            }
            fin.ignore();
        }
        else if(shapeName == "Polyline") //Different shape
        {
            shapesVec.push_back(shapeName);

            dimensions.erase(0);
            getline(fin, dimensions);

            stringstream ss(dimensions);
            while(getline(ss, token, ','))
            {
                dataDimensions.push_back(token);
            }

            for(unsigned int i = 0; i < dataDimensions.size(); i++)
            {
                cout << dataDimensions[i] << " ";
            }

            int polylineX1,polylineY1,polylineX2,polylineY2,polylineX3,polylineY3,polylineX4, polylineY4;
            polylineX1 = stoi(dataDimensions[0]);
            polylineY1 = stoi(dataDimensions[1]);
            polylineX2 = stoi(dataDimensions[2]);
            polylineY2 = stoi(dataDimensions[3]);
            polylineX3  = stoi(dataDimensions[4]);
            polylineY3 = stoi(dataDimensions[5]);
            polylineX4 = stoi(dataDimensions[6]);
            polylineY4 = stoi(dataDimensions[7]);

            vector<QPoint> *newpts2 = new vector<QPoint>();

            QPoint qp2(polylineX1,polylineY1);
            newpts2->push_back(qp2);
            QPoint qp22(polylineX2,polylineY2);
            newpts2->push_back(qp22);
            QPoint qp23(polylineX3,polylineY3);
            newpts2->push_back(qp23);
            QPoint qp24(polylineX4,polylineY4);
            newpts2->push_back(qp24);

            getline(fin, penColor);
            QColor PenColor;
            if(penColor == "blue")
            {
                penColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
                PenColor = Qt::GlobalColor::blue;
            }
            else if(penColor == "green")
            {
                   penColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::green;
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::cyan;
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::red;
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::black;
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::white;
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::magenta;
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::yellow;
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::gray;
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
                PenStyle = Qt::PenStyle::SolidLine;
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
                PenStyle = Qt::PenStyle::DashLine;
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
                PenStyle = Qt::PenStyle::DotLine;
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
                PenStyle = Qt::PenStyle::DashDotLine;
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
                PenCapStyle = Qt::PenCapStyle::SquareCap;
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
                PenCapStyle = Qt::PenCapStyle::RoundCap;
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
                PenJoinStyle = Qt::PenJoinStyle::BevelJoin;
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
                PenJoinStyle = Qt::PenJoinStyle::RoundJoin;
            }

            //Constructs Objects
            if(shapeName == "Line")
            {
                Line *line1 = new Line(device, shapeId, PenColor, penWidth, PenStyle,
                           PenCapStyle, PenJoinStyle,lineToplx,lineToply,lineBotrx,lineBotry);
                pShapeVector->push_back((Shape *)&line1);
            }
            else if(shapeName == "Polyline")
            {
                PolyLine *polyline1 = new PolyLine(device, shapeId, PenColor, penWidth, PenStyle,
                                   PenCapStyle, PenJoinStyle,*newpts2); //Add Dimensions
                pShapeVector->push_back((Shape *)&polyline1);
            }
            cout << pShapeVector;

        }
        else if(shapeName == "Polygon" || shapeName == "Rectangle"
                || shapeName == "Square" || shapeName == "Ellipse"
                || shapeName == "Circle") //Different shapes
        {
            shapesVec.push_back(shapeName);

            if(shapeName == "Rectangle")
            {
//                int tlx, tly, w, h;

                dimensions.erase(0);
                getline(fin, dimensions);

                stringstream ss(dimensions);
                while(getline(ss, token, ','))
                {
                    dataDimensions.push_back(token);
                }

                for(unsigned int i = 0; i < dataDimensions.size(); i++)
                {
                    cout << dataDimensions[i] << " ";
                }

                tlx = stoi(dataDimensions[0]);
                tly = stoi(dataDimensions[1]);
                w = stoi(dataDimensions[2]);
                h = stoi(dataDimensions[3]);

            }
            else if(shapeName == "Square")
            {
//                int stlx,stly,xs; // Add
                dimensions.erase(0);
                getline(fin, dimensions);

                stringstream ss(dimensions);
                while(getline(ss, token, ','))
                {
                    dataDimensions.push_back(token);
                }

                for(unsigned int i = 0; i < dataDimensions.size(); i++)
                {
                    cout << dataDimensions[i] << " ";
                }

                stlx = stoi(dataDimensions[0]);
                stly = stoi(dataDimensions[1]);
                xs = stoi(dataDimensions[2]);

            }
            else if(shapeName == "Ellipse")
            {
//                int ellipseTlx,ellipseTly,ellipseW, ellipseH; //ADD
                dimensions.erase(0);
                getline(fin, dimensions);

                stringstream ss(dimensions);
                while(getline(ss, token, ','))
                {
                    dataDimensions.push_back(token);
                }

                for(unsigned int i = 0; i < dataDimensions.size(); i++)
                {
                    cout << dataDimensions[i] << " ";
                }

                ellipseTlx = stoi(dataDimensions[0]);
                ellipseTly = stoi(dataDimensions[1]);
                ellipseW = stoi(dataDimensions[2]);
                ellipseH = stoi(dataDimensions[3]);

            }
            else if(shapeName == "Circle")
            {
//                int circleTlx,circleTly,circleD;
                dimensions.erase(0);
                getline(fin, dimensions);

                stringstream ss(dimensions);
                while(getline(ss, token, ','))
                {
                    dataDimensions.push_back(token);
                }

                for(unsigned int i = 0; i < dataDimensions.size(); i++)
                {
                    cout << dataDimensions[i] << " ";
                }

                circleTlx = stoi(dataDimensions[0]);
                circleTly = stoi(dataDimensions[1]);
                circleD = stoi(dataDimensions[2]);
            }
            else if(shapeName == "Polygon")
            {
                dimensions.erase(0);
                getline(fin, dimensions);

                stringstream ss(dimensions);
                while(getline(ss, token, ','))
                {
                    dataDimensions.push_back(token);
                }

                for(unsigned int i = 0; i < dataDimensions.size(); i++)
                {
                    cout << dataDimensions[i] << " ";
                }

                int polygonX1,polygonY1,polygonX2,polygonY2,polygonX3,polygonY3,polygonX4,polygonY4;

                polygonX1 = stoi(dataDimensions[0]);
                polygonY1 = stoi(dataDimensions[1]);
                polygonX2 = stoi(dataDimensions[2]);
                polygonY2 = stoi(dataDimensions[3]);
                polygonX3 = stoi(dataDimensions[4]);
                polygonY3 = stoi(dataDimensions[5]);
                polygonX4 = stoi(dataDimensions[6]);
                polygonY4 = stoi(dataDimensions[7]);


                    //vector<QPoint> *newpts1 = new vector<QPoint>();
                    QPoint qp1(polygonX1,polygonY1);
                    newpts1->push_back(qp1);
                    QPoint qp12(polygonX2,polygonY2);
                    newpts1->push_back(qp12);
                    QPoint qp13(polygonX3,polygonY3);
                    newpts1->push_back(qp13);
                    QPoint qp14(polygonX4,polygonY4);
                    newpts1->push_back(qp14);

            }

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
                   PenColor = Qt::GlobalColor::green;
            }
            else if(penColor == "cyan")
            {
                   penColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::cyan;
            }
            else if(penColor == "red")
            {
                   penColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::red;
            }
            else if(penColor == "black")
            {
                   penColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::black;
            }
            else if(penColor == "white")
            {
                   penColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::white;
            }
            else if(penColor == "magenta")
            {
                   penColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::magenta;
            }
            else if(penColor == "yellow")
            {
                   penColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::yellow;
            }
            else if(penColor == "gray")
            {
                   penColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
                   PenColor = Qt::GlobalColor::gray;
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
                PenStyle = Qt::PenStyle::SolidLine;
            }
            else if(penStyle == "DashLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashLine);
                PenStyle = Qt::PenStyle::DashLine;
            }
            else if(penStyle == "DotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DotLine);
                PenStyle = Qt::PenStyle::DotLine;
            }
            else if(penStyle == "DashDotLine")
            {
                penStyleVec.push_back(Qt::PenStyle::DashDotLine);
                PenStyle = Qt::PenStyle::DashDotLine;
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
                PenCapStyle = Qt::PenCapStyle::SquareCap;
            }
            else if(penCapStyle == "RoundCap")
            {
                penCapStyleVec.push_back(Qt::PenCapStyle::RoundCap);
                PenCapStyle = Qt::PenCapStyle::RoundCap;
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
                PenJoinStyle = Qt::PenJoinStyle::BevelJoin;
            }
            else if(penJoinStyle == "RoundJoin")
            {
                penJoinStyleVec.push_back(Qt::PenJoinStyle::RoundJoin);
                PenJoinStyle = Qt::PenJoinStyle::RoundJoin;
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
                   BrushColor = Qt::GlobalColor::green;
            }
            else if(brushColor == "cyan")
            {
                   brushColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::cyan;
            }
            else if(brushColor == "red")
            {
                   brushColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::red;
            }
            else if(brushColor == "black")
            {
                   brushColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::black;
            }
            else if(brushColor == "white")
            {
                   brushColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::white;
            }
            else if(brushColor == "magenta")
            {
                   brushColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::magenta;
            }
            else if(brushColor == "yellow")
            {
                   brushColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::yellow;
            }
            else if(brushColor == "gray")
            {
                   brushColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
                   BrushColor = Qt::GlobalColor::gray;
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
                BrushStyle = Qt::BrushStyle::HorPattern;
            }
            else if(brushStyle == "VerPattern")
            {
                brushStyleVec.push_back(Qt::BrushStyle::VerPattern);
                BrushStyle = Qt::BrushStyle::VerPattern;
            }
            else if(brushStyle == "NoBrush")
            {
                brushStyleVec.push_back(Qt::BrushStyle::NoBrush);
                BrushStyle = Qt::BrushStyle::NoBrush;
            }


            // Actually construct the object
            if(shapeName == "Polygon")
            {

               Polygon *poly1 = new Polygon(device, shapeId, PenColor, penWidth, PenStyle,
                                PenCapStyle, PenJoinStyle, BrushColor, BrushStyle,*newpts1);//ADD DIMENSIONS
                pShapeVector->push_back((Shape *)&poly1);
            }
            else if (shapeName == "Rectangle")
            {
                  // Note - these need to be parsed
                Rectangle *rect1 = new Rectangle(device, shapeId, PenColor, penWidth, PenStyle,
                                PenCapStyle, PenJoinStyle, BrushColor, BrushStyle, tlx, tly, w, h );
                pShapeVector->push_back((Shape *)&rect1);
            }
            else if(shapeName == "Square")
            {

                Square *square1 = new Square(device, shapeId, PenColor, penWidth, PenStyle,
                                PenCapStyle, PenJoinStyle, BrushColor, BrushStyle, stlx, stly, xs);
                pShapeVector->push_back((Shape *)&square1);
            }
            else if(shapeName == "Ellipse")
            {

                Ellipse *ellipse1 = new Ellipse(device, shapeId, PenColor, penWidth, PenStyle,
                                PenCapStyle, PenJoinStyle, BrushColor, BrushStyle,ellipseTlx,
                                ellipseTly,ellipseW,ellipseH);
                pShapeVector->push_back((Shape *)&ellipse1);
            }
            else if(shapeName == "Circle")
            {
                Circle *circle1 = new Circle(device, shapeId, PenColor, penWidth, PenStyle,
                                            PenCapStyle, PenJoinStyle, BrushColor, BrushStyle,circleTlx,
                                            circleTly,circleD);
                pShapeVector->push_back((Shape *)&circle1);
            }
        }
        else if(shapeName == "Text")
        {
            shapesVec.push_back(shapeName);


            string tempString;
            getline(fin, tempString);
            textString = QString::fromStdString(tempString);


            textStringVec.push_back(tempString);

            dimensions.erase(0);
            getline(fin, dimensions);

            stringstream ss(dimensions);
            while(getline(ss, token, ','))
            {
                dataDimensions.push_back(token);
            }

            for(unsigned int i = 0; i < dataDimensions.size(); i++)
            {
                cout << dataDimensions[i] << " ";
            }

            circleTlx = stoi(dataDimensions[0]);
            circleTly = stoi(dataDimensions[1]);
            circleD = stoi(dataDimensions[2]);


            getline(fin, textColor);
            QColor TextColor;
            if(textColor == "blue")
            {
                textColorVec.push_back(Qt::GlobalColor::blue); //Puts color of shape into Vector
                TextColor = Qt::GlobalColor::blue;
            }
            else if(textColor == "green")
            {
                   textColorVec.push_back(Qt::GlobalColor::green); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::green;
            }
            else if(textColor == "cyan")
            {
                   textColorVec.push_back(Qt::GlobalColor::cyan); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::cyan;
            }
            else if(textColor == "red")
            {
                   textColorVec.push_back(Qt::GlobalColor::red); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::red;
            }
            else if(textColor == "black")
            {
                   textColorVec.push_back(Qt::GlobalColor::black); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::black;
            }
            else if(textColor == "white")
            {
                   textColorVec.push_back(Qt::GlobalColor::white); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::white;
            }
            else if(textColor == "magenta")
            {
                   textColorVec.push_back(Qt::GlobalColor::magenta); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::magenta;
            }
            else if(textColor == "yellow")
            {
                   textColorVec.push_back(Qt::GlobalColor::yellow); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::yellow;
            }
            else if(textColor == "gray")
            {
                   textColorVec.push_back(Qt::GlobalColor::gray); //Puts color of shape into Vector
                   TextColor = Qt::GlobalColor::gray;
            }



            getline(fin, textAlignment);
            Qt::AlignmentFlag TextAlignment;
            if(textAlignment == "AlignLeft")
            {
                textAlignmentVec.push_back(Qt::AlignmentFlag::AlignLeft);
                TextAlignment = Qt::AlignmentFlag::AlignLeft;
            }
            else if(textAlignment == "AlignRight")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignRight);
                   TextAlignment = Qt::AlignmentFlag::AlignRight;
            }
            else if(textAlignment == "AlignTop")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignTop);
                   TextAlignment = Qt::AlignmentFlag::AlignTop;
            }
            else if(textAlignment == "AlignBottom")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignBottom);
                   TextAlignment = Qt::AlignmentFlag::AlignBottom;
            }
            else if(textAlignment == "AlignCenter")
            {
                   textAlignmentVec.push_back(Qt::AlignmentFlag::AlignCenter);
                   TextAlignment = Qt::AlignmentFlag::AlignCenter;
            }


            fin >> textPointSize;
            textPointSizeVec.push_back(textPointSize);
            fin.ignore();


            string tempFontfamily;
            getline(fin, tempFontfamily);
            fontFamily = QString::fromStdString(tempFontfamily);

            fontFamilyVec.push_back(tempFontfamily);



            getline(fin, fontStyle);
            QFont::Style FontStyle;
            if(fontStyle == "StyleNormal")
            {
                fontStyleVec.push_back(QFont::Style::StyleNormal);
                FontStyle = QFont::Style::StyleNormal;
            }
            else if(fontStyle == "StyleItalic")
            {
                fontStyleVec.push_back(QFont::Style::StyleItalic);
                FontStyle = QFont::Style::StyleItalic;
            }
            else if(fontStyle == "StyleOblique")
            {
                fontStyleVec.push_back(QFont::Style::StyleOblique);
                FontStyle = QFont::Style::StyleOblique;
            }


            getline(fin, fontWeight);
            QFont::Weight FontWeight;
            if(fontWeight == "Thin")
            {
                fontWeightVec.push_back(QFont::Weight::Thin);
                FontWeight = QFont::Weight::Thin;
            }
            else if(fontWeight == "Light")
            {
                fontWeightVec.push_back(QFont::Weight::Light);
                FontWeight = QFont::Weight::Light;
            }
            else if(fontWeight == "Normal")
            {
                fontWeightVec.push_back(QFont::Weight::Normal);
                FontWeight = QFont::Weight::Normal;
            }
            else if(fontWeight == "Bold")
            {
                fontWeightVec.push_back(QFont::Weight::Bold);
                FontWeight = QFont::Weight::Bold;
            }

            if(shapeName == "Text")
            {
//                int textTlx,textTly,textW,textH;
                Text *text1 = new Text(device, shapeId, textString, TextColor, TextAlignment, textPointSize,
                                       fontFamily, FontStyle, FontWeight,textTlx,textTly,textW,textH);//Add the parameters
                pShapeVector->push_back((Shape *)&text1);
            }
        }
        else
        {
            cout << "Error: Shape not found" << endl;
        }

    }

    //Prints what was read in to verify that it is working.
//    for(unsigned int i = 0; i < shapesVec.size() - 1; i++)
//    {
//            cout << "ShapeId: "      << shapeIdVec[i]      << endl;
//            cout << "ShapeType: "    << shapesVec[i]       << endl;

//            if(shapesVec[i] == "Line" || shapesVec[i] == "Polyline"
//                    || shapesVec[i]  == "Polygon" || shapesVec[i]  == "Rectangle"
//                    || shapesVec[i]  == "Square" || shapesVec[i]  == "Ellipse"
//                    || shapesVec[i]  == "Circle")
//            {
//                cout << "PenColor: "     << penColorVec[i]     << endl;
//                cout << "PenWidth: "     << penWidthVec[i]     << endl;
//                cout << "PenStyle: "     << penStyleVec[i]     << endl;
//                cout << "PenCapStyle: "  << penCapStyleVec[i]  << endl;
//                cout << "PenJoinStyle: " << penJoinStyleVec[i] << endl;
//            }


//        //If these given shapes are specified outputs their respective brush
//        //color and style
//        if(shapesVec[i]  == "Polygon" || shapesVec[i]  == "Rectangle"
//           || shapesVec[i]  == "Square" || shapesVec[i]  == "Ellipse"
//           || shapesVec[i]  == "Circle")
//        {
//                cout << "BrushColor: " << brushColorVec[brushIndex] << endl;
//                cout << "BrushStyle: " << brushStyleVec[brushIndex] << endl;
//                brushIndex++;
//        }
//        else if(shapesVec[i] == "Text")
//        {
//            cout << "TextString: "     << textStringVec[textIndex]    << endl;
//            cout << "textColor: "      << textColorVec[textIndex]     << endl;
//            cout << "textAlignment: "  << textAlignmentVec[textIndex] << endl;
//            cout << "textPointSize: "  << textPointSizeVec[textIndex] << endl;
//            cout << "fontFamily: "     << fontFamilyVec[textIndex]    << endl;
//            cout << "fontStyle: "      << fontStyleVec[textIndex]     << endl;
//            cout << "fontWeight: "     << fontWeightVec[textIndex]    << endl;
//            textIndex++;
//        }


//        cout << endl;
//    }

    fin.close();
}

void writeFile(MyVector<Shape *> *pShapeVector)
{
    ofstream fout;
    int shape;
    int index = 1;
    Shape2D* temp = dynamic_cast<Shape2D*>((*pShapeVector)[index - 1]);
    Text* tempText = dynamic_cast<Text*>((*pShapeVector)[index - 1]);

    fout.open("./shapes.txt");
    MyVector<Shape *>::iterator i = pShapeVector->begin();
    while(i != pShapeVector->end())
    {
        shape = (*i)->getShapeType();

        if(shape == 0 || shape == 1 || shape == 2 || shape == 3 ||
           shape == 3 || shape == 4 ||shape == 5 ||shape == 6)
        {
            switch(shape)
            {
                case 0 : fout << "Line" << endl;
                         break;
                case 1 : fout << "Polyline" << endl;
                         break;
                case 2 : fout << "Polygon" << endl;
                         break;
                case 3 : fout << "Rectangle" << endl;
                         break;
                case 4 : fout << "Square" << endl;
                         break;
                case 5 : fout << "Ellipse" << endl;
                         break;
                case 6 : fout << "Circle" << endl;
                         break;
            }

            fout << (*i)->getId();

            //Dimensions

            QColor PenColor = temp->pen.color();


            if(PenColor == Qt::GlobalColor::blue)
            {
                fout << "Blue" << endl;
            }
            else if(PenColor == Qt::GlobalColor::green)
            {
                fout << "Green" << endl;
            }
            else if(PenColor == Qt::GlobalColor::cyan)
            {
                fout << "Cyan" << endl;
            }
            else if(PenColor == Qt::GlobalColor::red)
            {
                fout << "Red" << endl;
            }
            else if(PenColor == Qt::GlobalColor::black)
            {
                fout << "Black" << endl;
            }
            else if(PenColor == Qt::GlobalColor::white)
            {
                fout << "White" << endl;
            }
            else if(PenColor == Qt::GlobalColor::magenta)
            {
                fout << "Magenta" << endl;
            }
            else if(PenColor == Qt::GlobalColor::gray)
            {
                fout << "Gray" << endl;
            }

            fout << temp->pen.width();

            int PenStyle = temp->pen.style();

            switch(PenStyle)
            {
                case(Qt::PenStyle::NoPen) : fout << "NoPen" << endl;
                                              break;
                case(Qt::PenStyle::SolidLine) : fout << "SolidLine" << endl;
                                          break;
                case(Qt::PenStyle::DashLine) : fout << "DashLine" << endl;
                                          break;
                case(Qt::PenStyle::DotLine) : fout << "DotLine" << endl;
                                          break;
                case(Qt::PenStyle::DashDotLine) : fout << "DashDotLine" << endl;
                                          break;
                case(Qt::PenStyle::DashDotDotLine) : fout << "DashDotDotLine" << endl;
                                          break;
            }

            Qt::PenCapStyle PenCapStyle = temp->pen.capStyle();

            switch(PenCapStyle)
            {
                case(Qt::PenCapStyle::FlatCap) : fout << "FlatCap" << endl;
                                                    break;
                case(Qt::PenCapStyle::SquareCap) : fout << "SquareCap" << endl;
                                                    break;
                case(Qt::PenCapStyle::RoundCap) : fout << "RoundCap" << endl;
                                                    break;
            }

            Qt::PenJoinStyle PenJoinStyle = temp->pen.joinStyle();

            switch(PenJoinStyle)
            {
                case(Qt::PenJoinStyle::MiterJoin) : fout << "MiterJoin" << endl;
                                                    break;
                case(Qt::PenJoinStyle::BevelJoin) : fout << "BevelJoin" << endl;
                                                    break;
                case(Qt::PenJoinStyle::RoundJoin) : fout << "RoundJoin" << endl;
                                                    break;
            }

          }

        if(shape == 2 || shape == 3 ||shape == 3 || shape == 4 ||shape == 5 ||shape == 6)
        {

                QColor BrushColor = temp->brush.color();

                if(BrushColor == Qt::GlobalColor::blue)
                {
                    fout << "Blue" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::green)
                {
                    fout << "Green" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::cyan)
                {
                    fout << "Cyan" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::red)
                {
                    fout << "Red" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::black)
                {
                    fout << "Black" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::white)
                {
                    fout << "White" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::magenta)
                {
                    fout << "Magenta" << endl;
                }
                else if(BrushColor == Qt::GlobalColor::gray)
                {
                    fout << "Gray" << endl;
                }


                Qt::BrushStyle BrushStyle = temp->brush.style();

                switch(BrushStyle)
                {
                    case(Qt::BrushStyle::SolidPattern) : fout << "SolidPattern" << endl;
                                                  break;
                    case(Qt::BrushStyle::HorPattern) : fout << "HorPattern" << endl;
                                              break;
                    case(Qt::BrushStyle::VerPattern) : fout << "VerPattern" << endl;
                                              break;
                    case(Qt::BrushStyle::NoBrush) : fout << "NoBrush" << endl;
                                              break;
                }
        }
        else if(shape == 7)
        {
            fout << tempText->String.toStdString();

            QColor textColor = tempText->Color;
            if(textColor == Qt::GlobalColor::blue)
            {
                fout << "Blue" << endl;
            }
            else if(textColor == Qt::GlobalColor::green)
            {
                fout << "Green" << endl;
            }
            else if(textColor == Qt::GlobalColor::cyan)
            {
                fout << "Cyan" << endl;
            }
            else if(textColor == Qt::GlobalColor::red)
            {
                fout << "Red" << endl;
            }
            else if(textColor == Qt::GlobalColor::black)
            {
                fout << "Black" << endl;
            }
            else if(textColor == Qt::GlobalColor::white)
            {
                fout << "White" << endl;
            }
            else if(textColor == Qt::GlobalColor::magenta)
            {
                fout << "Magenta" << endl;
            }
            else if(textColor == Qt::GlobalColor::gray)
            {
                fout << "Gray" << endl;
            }

            Qt::AlignmentFlag textAlign = tempText->Alignment;
            if(textAlign == Qt::AlignmentFlag::AlignCenter)
            {
                fout << "AlignCenter" << endl;
            }
            else if(textAlign == Qt::AlignmentFlag::AlignLeft)
            {
                fout << "AlignLeft" << endl;
            }
            else if(textAlign == Qt::AlignmentFlag::AlignRight)
            {
                fout << "AlignRight" << endl;
            }
            else if(textAlign == Qt::AlignmentFlag::AlignTop)
            {
                fout << "AlignTop" << endl;
            }
            else if(textAlign == Qt::AlignmentFlag::AlignBottom)
            {
                fout << "AlignBottom" << endl;
            }

            fout << tempText->FontSize;

            cout << tempText->FontFamily.toStdString();

            QFont::Style fontStyle = tempText->FontStyle;

            if(fontStyle == QFont::Style::StyleNormal)
            {
                fout << "StyleNormal" << endl;
            }
            else if(fontStyle == QFont::Style::StyleItalic)
            {
                fout << "StyleItalic" << endl;
            }
            else if(fontStyle == QFont::Style::StyleOblique)
            {
                fout << "StyleOblique" << endl;
            }

            QFont::Weight fontWeight = tempText ->FontWeight;

            switch(fontWeight)
            {
                case QFont::Weight::Thin : fout << "Thin" << endl;
                                           break;
                case QFont::Weight::Light : fout << "Light" << endl;
                                           break;
                case QFont::Weight::Normal : fout << "Normal" << endl;
                                           break;
                case QFont::Weight::Bold : fout << "Bold" << endl;
                                           break;
            }

        }




        i++;
        index++;
    }
}














//    fout << textString;

//    switch(TextAlignment)
//    {
//        case(Qt::AlignmentFlag::AlignLeft) : fout << "AlignLeft" << endl;
//                                  break;
//        case(Qt::AlignmentFlag::AlignRight) : fout << "AlignRight" << endl;
//                                  break;
//        case(Qt::AlignmentFlag::AlignTop) : fout << "AlignTop" << endl;
//                                  break;
//        case(Qt::AlignmentFlag::AlignBottom) : fout << "AlignBottom" << endl;
//                                  break;
//        case(Qt::AlignmentFlag::AlignCenter) : fout << "AlignCenter" << endl;
//                                  break;
//    }

//    fout << textPointSize << endl;

//    fout << textFontfamily<< endl;

//    switch(TextFontStyle)
//    {
//        case(QFont::Style::StyleNormal) : fout << "AlignCenter" << endl;
//                                  break;
//        case(QFont::Style::StyleItalic) : fout << "AlignCenter" << endl;
//                                  break;
//        case(QFont::Style::StyleOblique) : fout << "AlignCenter" << endl;
//                                  break;
//        case(QFont::Style::StyleNormal) : fout << "AlignCenter" << endl;
//                                  break;
//    }

//    switch(TextFontWeight)
//    {
//        case(QFont::Weight::Thin) : fout << "Thin" << endl;
//                            break;
//        case(QFont::Weight::Light) : fout << "Light" << endl;
//                            break;
//        case(QFont::Weight::Normal) : fout << "Normal" << endl;
//                            break;
//        case(QFont::Weight::Bold) : fout << "Bold" << endl;
//                            break;
//    }








//}

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
