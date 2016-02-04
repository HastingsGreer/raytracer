/*
 * Plane.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Plane.h"

Plane::Plane(Vector3 point, Vector3 normal, Color c):
    point(point), c(c) {
	this->normal = normal.unit();
	// TODO Auto-generated constructor stub

}
float Plane::intersect(Ray other){
    float distFromPlane = normal.dot(other.start.sub(point));
    float effectiveness = normal.dot(other.dir);
    float t = distFromPlane / effectiveness;
    if(t > 0){
    	return t;
    }
    return -1;
}

Color Plane::shade(Vector3 place, Room* room){
    return c;
}
Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

