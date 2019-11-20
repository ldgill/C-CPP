#include "coord.h"
#include <complex.h>
#include <math.h>
#include <stdlib.h>

/* The type declaration of the ADT. */
struct _coord{
  double complex d;
};

/* Create a coordinate. */
coord * newCoord(void){
  coord*c= malloc(sizeof(coord));
  if (!c) return NULL;
  c -> d =0;
  return c;
}

/* Deletes a coordinate. */
void deleteCoord(coord * c){
  free (c);
}
/* "getters" */
double getX(coord const * c){
  return creal (c->d);
    }
double getY(coord const * c){
  return cimag (c->d);
    }
/* Returns the radius component. */
double getR(coord const * c){
  return cabs(c->d);
}
/* Returns the angle component. */
double getTheta(coord const * c){
  return carg(c->d);
}
/* "setters" */
/* For Cartesian coordinates. */
void setX(coord * c, double x){
  c->d = x+ I * cimag(c->d);
}
void setY(coord * c, double y){
  c->d = creal (c->d) + I*y;
}
/* Set the radius/angle components. */
void setR(coord * c, double r) {
  c->d = r*cexp(I*carg(c->d));
}
void setTheta(coord * c, double th){
  c->d = cabs(c->d)*cexp(I*th);
}



 
