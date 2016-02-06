/*
 * Sphere.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Sphere.h"

#include <cmath>
Sphere::Sphere(Vector3 center, double r, PhongProfile prof): Renderable(prof), center(center), r(r){


}
Sphere::~Sphere() {
}

intersectionResult Sphere::intersect(Ray other){
    Vector3 transRayStart = other.start.sub(center);
    Vector3 p = transRayStart.mul(1 / r);
    Vector3 d = other.dir.mul(1/r);
    double dDotP = d.dot(p);
    double discriminant = dDotP * dDotP - d.dot(d) * (p.dot(p) - 1);
    if(discriminant < 0){
    	intersectionResult{-1, false, nullptr};
    }



    if(-d.dot(p) - std::sqrt(discriminant) > 0.001){
    	return intersectionResult {(-d.dot(p) - std::sqrt(discriminant) )/ d.dot(d), true, this};
    }
    if(-d.dot(p) + std::sqrt(discriminant) > 0.001){
        	return intersectionResult{(-d.dot(p) + std::sqrt(discriminant) )/ d.dot(d), true, this};
        }
    return intersectionResult{-1, false, nullptr};
}


Vector3 Sphere::normal(Vector3 place){
	return (place.sub(center)).mul(1/r);
}

