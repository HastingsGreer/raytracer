/*
 * Sphere.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Sphere.h"

#include <cmath>
Sphere::Sphere(Vector3 center, float r, PhongProfile prof): Renderable(prof), center(center), r(r){


}
Sphere::~Sphere() {
}

float Sphere::intersect(Ray other){
    Vector3 transRayStart = other.start.sub(center);
    Vector3 p = transRayStart.mul(1 / r);
    Vector3 d = other.dir.mul(1/r);
    float dDotP = d.dot(p);
    float discriminant = dDotP * dDotP - d.dot(d) * (p.dot(p) - 1);
    if(discriminant < 0){
    	return -1;
    }
    if(-d.dot(p) - std::sqrt(discriminant) > 0.001){
    	return (-d.dot(p) - std::sqrt(discriminant) )/ d.dot(d);
    }
    if(-d.dot(p) + std::sqrt(discriminant) > 0.001){
        	return (-d.dot(p) + std::sqrt(discriminant) )/ d.dot(d);
        }
    return -1;
}


Vector3 Sphere::normal(Vector3 place){
	return (place.sub(center)).mul(1/r);
}

