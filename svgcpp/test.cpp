#include <iostream>
#include <string>
#include "SVGPlot2d.h"

using namespace std;

int main()
{
  SVGDraw2d plt;

  plt.draw_line( 100, 100, 100, 200, "stroke: red;");
  plt.write();

  return 0;
}
