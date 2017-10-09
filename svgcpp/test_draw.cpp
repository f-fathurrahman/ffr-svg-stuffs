#include <iostream>
#include <string>
#include "SVGPlot2d.h"

using namespace std;

int main()
{
  SVGDraw2d plt(1000,1000);

  plt.draw_line( 100, 100, 100, 200, "stroke: red;");
  plt.draw_circle( 100, 300, 30, "fill: blue;");
  
  const int Npts = 5;
  double xpts[Npts] = {100, 200, 300, 350, 400};
  double ypts[Npts] = {150, 250, 350, 350, 450};

  for( int i = 0; i < Npts; i++ ) {
    plt.draw_circle( xpts[i], ypts[i], 3, "fill: black;");
  }
  plt.draw_polyline( Npts, xpts, ypts, "stroke: blue; fill: none;");

  plt.write();

  return 0;
}
