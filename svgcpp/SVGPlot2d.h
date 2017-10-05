#ifndef __SVGPLOT2D__
#define __SVGPLOT2D__

#include <string>
#include <iostream>

using namespace std;

class SVGDraw2d
{

public:

  SVGDraw2d();
  ~SVGDraw2d();

  string str;

  void write();
  void draw_line( double x1, double y1, double x2, double y2, string style );
  void draw_circle( double cx, double cy, double r, string style );
  void draw_polyline( double *pts, string style );

};

// Constructor
SVGDraw2d::SVGDraw2d()
{
  //cout << "Constructor is called" << endl;
  str = "<svg width=\"140\" height=\"170\"\n";
  str += "xmlns=\"http://www.w3.org/2000/svg\"\n";
  str += "xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n";
}

// Destructor
SVGDraw2d::~SVGDraw2d()
{
  //cout << "Destructor is called" << endl;
}

// Finalize and write
void SVGDraw2d::write()
{
  str += "</svg>\n";
  cout << str;
}


void SVGDraw2d::draw_line( double x1, double y1, double x2, double y2, string style )
{
  str += "<line x1=\"" +  to_string(x1) + "\" y1=\"" + to_string(y1) +
         "\" x2=\"" + to_string(x2) + "\" y2=\"" + to_string(y2) + "\" style = \"" + style +
         "\"/>\n";
}

void SVGDraw2d::draw_circle( double cx, double cy, double r, string style )
{

}

void SVGDraw2d::draw_polyline( double *pts, string style )
{

}


//
// A class for to make 2d plot
//

class SVGPlot2d
{
public:
  SVGPlot2d();
  ~SVGPlot2d();
};


#endif

