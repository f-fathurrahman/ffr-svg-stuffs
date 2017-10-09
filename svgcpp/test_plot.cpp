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

  double delta_x = (XMAX-XMIN)/(Npts-1);
  for( i = 0; i < Npts; i++ ) {
    x[i] = XMIN + i*delta_x;
//    printf("i, x = %d %f\n", i, x[i]);
    y[i] = YMAX*sin(M_PI*x[i]);
//    printf("%18.10f %18.10f\n", x[i], y[i]);
  }


  SVGDraw2d plt( WIDTH+2*PAD, HEIGHT+2*PAD );

  string style = "stroke: black;";
  plt.draw_line( 0.0+PAD, 0.0+PAD, WIDTH+PAD, 0.0+PAD, style );
  plt.draw_line( WIDTH+PAD, 0.0+PAD, WIDTH+PAD, HEIGHT+PAD, style );
  plt.draw_line( WIDTH+PAD, HEIGHT+PAD, 0.0+PAD, HEIGHT+PAD, style );
  plt.draw_line( 0.0+PAD, HEIGHT+PAD, 0.0+PAD, 0.0+PAD, style );

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
