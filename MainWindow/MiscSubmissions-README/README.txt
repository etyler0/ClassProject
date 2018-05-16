CS1C - Team ERKK
Revisied 05/10/18
First submission - 05/10/18 at 11:55 p.m. git tag c3e7a6b

Application Requirements
------------------------

1. Provide satisfied customer testimonials (solicit for additional
testimonials). Guest users may enter testimonials. The testimonials
should be persistent between executions.  --DONE--

2. Provide “contact us” method with team name and logo --DONE--

3. Display all graphic objects (i.e. shapes including text) in rendering
window. The shape id will be displayed above each shape identifying
it. The rendering area to display shapes must have minimum
dimensions of 1000 pixels (horizontal) by 500 pixels (vertical). The
coordinate system is defined such that the top left corner of the
rendering area is located at point (0,0), the bottom right corner at
point (1000,500). --RENDERING NOT WORKING (coded by broken)--

4. Your program should read from a shape file that keeps track of all
shapes currently being rendered by the 2D modeler. Shapes are
identified by their type: line, polyline, polygon, rectangle, ellipse,
text. Shapes have properties: shape dimensions, pen color, pen
width, pen style, pen cap style, pen join style, brush color, brush
shape. Text has properties: shape dimensions, text string, text
color, text alignment, text point size, text font family, text font
style, text font weight. All shapes must also have a unique ID. --NOT WORKING (bug)--

5. Your program should be able to move shapes, including text, being
rendered. This is accomplished via a move shape form. All changes
are visible in the rendering area. – administrator only --RENDERING NOT WORKING--

6. Your program should be able to add and remove shapes, including
text, being rendered. This is accomplished via an add/remove shape
form. All changes are visible in the rendering area. – administrator
only --DONE, not visible--

7. Produce a shape listing report sorted by shape id (at any time). All
shape properties should be included in the report. --DONE--

8. Produce a shape listing report of ONLY shapes with an area sorted
by area (at any time). The shape type, id and area should be
included in the report. --DONE--

9. Produce a shape listing report of ONLY shapes with a perimeter
sorted by perimeter (at any time). The shape type, id and perimeter
should be included in the report.  --DONE--

10. Save all changes between executions -- NOT WORKING (bug)--


Submission List
---------------

1) URL to GitHub repository.  Please add JKATHSADDLEBACKEDU as a 
contributor to the repository.  

2) zip file containing complete Qt project.  To include working UI once 
project is opened and built in Qt.  
---QT source tree is in MainWindow directory after unpacking tar.gz

3) zip file containing ONLY the class files written specifically to 
satisfy project requirements.  These classes are included in the Qt front 
end UI project from step 2) 
---C++ files written by team are in MainWindow and also in erkk-Codefiles

4) text file documenting which source files, line numbers from step 3) 
satisfy individual project requirements (#1 thru #10) and general project 
requirements (second paragraph of assignment).  For each project 
requirement include source file .h, .cpp name and relevant line numbers. 
--- Included in this README
Use of required C++ features:
Inheritance: Shape->Shape-2D-><circle.h/polygon.h/rectangle.h/square.h>
Composition: Polygon.h: line 35 contains a vector<QPoint>
Exception Handler: vector.h line 195, throws an exception for an invalid
                   number of elements to preallocate
Virtual Functions: shape.h lines 64-69 base class provides 6 functions that
                   can or must (pure virtual) be overloaded by derived
		   classes 
Overloaded Operators: shape.h 87-139 overload of () for comparisons
                      shape.cpp lines 60-84  overload of << for debug printing

5) agile product backlog, scrum backlog for sprint #1, #2 and daily scrum 
meeting documentation 
---SCRUM artifacts in Scrum directory

6) zip file containing doxygen class documentation
---Doxygen output - in Doxygen directory not zipped - just part of tree

7) hwgp01: at least 10 agile user stories
--- Previuously submitted - part of SCRUM docs in Scrum Directory

8) REMOVED - hwgp02: white box unit tests and test plan (hwgp02 
requirement has been removed, assignment not due) 

9) hwgp03: UML class diagram, at least three use cases and at least three 
state diagrams 
--- UNL diagrams in UML directory

10) valgrind memory leak check
--- Valgrind output - VectorUnitTest directory - see .txt file

11) completed team project member contribution form.  Each teammate must 
identify their accomplishments on the project 
--- See CS1C_ERKK_TEAM.pdf in MiscSubmissions-README directory 

Extra Credit [+4 pts]: Implement custom selection_sort algorithm
--- Done - see selection_sort.h/.cpp and comparison function objects in shape.h

Extra Credit [+1 pt]: use waffle.io (or similar) agile management tool
--- Not being used
			
      


