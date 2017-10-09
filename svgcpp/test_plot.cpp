#include <iostream>
#include <cstdio>
#include <cmath>
#include "SVGPlot2d.h"

using namespace std;

int main()
{

  int PAD = 20;

  int WIDTH  = 600;
  int HEIGHT = 400;

  // these values should be analyzed from input data to plot function
  double XMIN = -5.0;
  double XMAX =  5.0;
  double YMIN = -5.0;
  double YMAX =  5.0;

  double XSCALE = WIDTH/(XMAX - XMIN);
  double YSCALE = HEIGHT/(YMAX - YMIN);

//  printf("XSCALE, YSCALE = %f , %f\n", XSCALE, YSCALE );

  // prepare data
  const int Npts = 100;
  double *x = (double*)malloc( Npts*sizeof(double) );
  double *y = (double*)malloc( Npts*sizeof(double) );
  
  int i;

  // prepare data
  double delta_x = (XMAX-XMIN)/(Npts-1);
  for( i = 0; i < Npts; i++ ) {
    x[i] = XMIN + i*delta_x;
    y[i] = YMAX*cos(0.5*M_PI*x[i]);
  }


  SVGDraw2d plt( WIDTH+2*PAD, HEIGHT+2*PAD );

  string style = "stroke: black;";
  // corners
  double xc1 = 0.0 + PAD;
  double yc1 = 0.0 + PAD;
  //
  double xc2 = WIDTH + PAD;
  double yc2 = 0.0 + PAD;
  //
  double xc3 = WIDTH + PAD;
  double yc3 = HEIGHT + PAD;
  //
  double xc4 = 0.0 + PAD;
  double yc4 = HEIGHT + PAD;
  //
  plt.draw_line( xc1, yc1, xc2, yc2, style );
  plt.draw_line( xc2, yc2, xc3, yc3, style );
  plt.draw_line( xc3, yc3, xc4, yc4, style );
  plt.draw_line( xc4, yc4, xc1, yc1, style );

  // scale data
  for( i = 0; i < Npts; i++ ) {
    x[i] = XSCALE*( x[i] - XMIN ) + PAD;
    y[i] = HEIGHT - YSCALE*( y[i] - YMIN ) + PAD;
    plt.draw_circle( x[i], y[i], 2, "fill: blue;");
  }
  plt.draw_polyline( Npts, x, y, "stroke: blue; fill: none;");

  plt.write();

  free(x); x = NULL;
  free(y); y = NULL;

  return 0;
}
