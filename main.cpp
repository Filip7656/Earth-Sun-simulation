/*
 * main.cpp
 * 
 * Copyright 2019 Filip Chlebowski <filip@ubunut>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "funkcje.hpp"
#include <math.h>
int main(int argc, char **argv)
{
	//initializing planets
	planet earth = {{-147095000000,0},{0,-30300}, 5.98*pow(10,24)};
	planet sun = {{0,0},{0,0},1.98*pow(10,30)};
	int fiveYears = 157784630;

	//integrating values per 1 second
	int dt = 1;
	for (int t = 0; t<fiveYears; t+=1){
	vector2D *gravForce = gravityForce(earth, sun);

	earth.vel.x += (gravForce->x/earth.mass) *dt;
	earth.vel.y += (gravForce->y/earth.mass) *dt;

	earth.pos.x += earth.vel.x * dt;
	earth.pos.y += earth.vel.y * dt;

//  adding second planet
//  sun.vel.y += gravForce->y/sun.masa *dt;
//	sun.vel.x += gravForce->x/sun.masa *dt;
//
//	sun.pol.x += sun.vel.x * dt;
//	sun.pol.y += sun.vel.y * dt;

	if ( t%86400==0){
		printf("%d %f %f\n" ,t/86400,earth.pos.x, earth.pos.y);
		}
}
		return 0;
}
