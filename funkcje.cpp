#include "funkcje.hpp"
#include <stdio.h>
#include <math.h>

vector2D *gravityForce(const planet &c1, const planet &c2){
	const double constant = 6.67*pow(10,-11);
	vector2D *graw = NULL;
	graw = (vector2D*) realloc (graw,1*sizeof(vector2D));

	//calculating distances
	double xDist = c2.pos.x-c1.pos.x;
	double yDist = c2.pos.y-c1.pos.y;
	double xyDist = xDist*xDist+ yDist*yDist;
	double mass = c1.mass*c2.mass;
	
	double gForce = constant*mass/xyDist;

	double cosx= xDist/sqrt(xyDist);
	double sinx = yDist/sqrt(xyDist);
	
	graw->x += gForce*cosx;
	graw->y += gForce*sinx;

	return graw;
	free(graw);
	}
