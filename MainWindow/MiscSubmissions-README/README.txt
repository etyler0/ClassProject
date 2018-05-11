CS1C - Team ERKK
Revisied 05/10/18
First submission - 05/10/18 at 11:55 p.m. git tag c3e7a6b

Submission List

1) URL to GitHub repository.  Please add JKATHSADDLEBACKEDU as a 
contributor to the repository.  

2) zip file containing complete Qt project.  To include working UI once 
project is opened and built in Qt.  
---QT source tree is in MainWindow directory after unpacking tar.gz

3) zip file containing ONLY the class files written specifically to 
satisfy project requirements.  These classes are included in the Qt front 
end UI project from step 2) 
---C++ files written by team are in MainWindow and also in erkk-Codefiles
      Note: Not currently populated

4) text file documenting which source files, line numbers from step 3) 
satisfy individual project requirements (#1 thru #10) and general project 
requirements (second paragraph of assignment).  For each project 
requirement include source file .h, .cpp name and relevant line numbers. 
--- Included in this README
Use of required C++ features:
Inheritance: Shape->Shape-2D-><circle.h/polygon.h/rectangle.h/square.h>
Composition: Polygon.h: line 26 contains a vector<QPoint>
Exception Handler: vector.h line 132, throws an exception for an invalid
                   number of elements to preallocate
Virtual Functions: shape.h lines 60-68 base class provides 8 functions that
                   can or must (pure virtual) be overloaded by derived
		   classes 
Overloaded Operators: shape.h lines 69, 88  overlaod of << for debug printing
                        and () for comparisons

5) agile product backlog, scrum backlog for sprint #1, #2 and daily scrum 
meeting documentation 
---SCRUM artifacts in Scrum directory   - not yet attached

6) zip file containing doxygen class documentation
---Doxygen output - in Doxygen directory --- not yet attached

7) hwgp01: at least 10 agile user stories
--- Previuously submitted - part of SCRUM docs in Scrum Directory

8) REMOVED - hwgp02: white box unit tests and test plan (hwgp02 
requirement has been removed, assignment not due) 

9) hwgp03: UML class diagram, at least three use cases and at least three 
state diagrams 
--- UNL diagream in UML directy - not yet attached

10) valgrind memory leak check
--- Valgrind output - VectorUnitTest directory - see .txt file

11) completed team project member contribution form.  Each teammate must 
identify their accomplishments on the project 
--- See CS1C_ERKK_TEAM.pdf in MiscSubmissions-README directory 

Extra Credit [+4 pts]: Implement custom selection_sort algorithm
--- Done - see selection_sort.h/.cpp and comparison classes in shapes.h

Extra Credit [+1 pt]: use waffle.io (or similar) agile management tool
--- Not being used
			
      


