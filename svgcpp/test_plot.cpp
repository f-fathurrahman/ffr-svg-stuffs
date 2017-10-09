#include <iostream>
#include <cstdio>
#include "SVGPlot2d.h"

using namespace std;

int main()
{

  int PAD = 20;

  int WIDTH  = 600;
  int HEIGHT = 400;

  double XMIN = -5.0;
  double XMAX =  5.0;

  double YMIN = -5.0;
  double YMAX =  5.0;

  double XSCALE = (XMAX - XMIN)/WIDTH;
  double YSCALE = (YMAX - YMIN)/HEIGHT;

  printf("XSCALE, YSCALE = %f , %f\n", XSCALE, YSCALE );

//  SVGDraw2d plt(width,height);

  return 0;
}
