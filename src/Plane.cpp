/*
 * Plane.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Plane.h"

Plane::Plane(Vector3 point, Vector3 norm, PhongProfile prof): Renderable(prof),
    point(point){
	this->norm = norm.unit();
	// TODO Auto-generated constructor stub

}
float Plane::intersect(Ray other){
    float distFromPlane = norm.dot(other.start.sub(point));
    float effectiveness = norm.dot(other.dir);
    float t = -distFromPlane / effectiveness;
    if(t > 0.001){
    	return t;
    }
    return -1;
}

Vector3 Plane::normal(Vector3 place){
    return norm;
}
Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

