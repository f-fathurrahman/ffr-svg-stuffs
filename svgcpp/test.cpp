#include <iostream>
#include <string>
#include "SVGPlot2d.h"

using namespace std;

int main()
{
  SVGDraw2d plt;

  plt.draw_line( 100, 100, 100, 200, "stroke: red;");
  plt.draw_circle( 100, 300, 30, "fill: green;");
  plt.write();

  return 0;
}
