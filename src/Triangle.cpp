/*
 * Triangle.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: hastings
 */

#include "Triangle.h"

const double epsilon = .000001;

Triangle::Triangle(Vector3 v1, Vector3 v2, Vector3 v3, PhongProfile prof): Renderable(prof), v1(v1), v2(v2), v3(v3) {
	e1 = v2.sub(v1);
	e2 = v3.sub(v1);
	norm = e2.cross(e1).unit();
	// TODO Auto-generated constructor stub

}

intersectionResult Triangle::intersect(Ray ray){
    Vector3 p = ray.dir.cross(e2);
    double det = e1.dot(p);
    if(det > -epsilon && det < epsilon){
    	return intersectionResult{-1, false, nullptr};
    }
    double inv_det = 1./det;
    Vector3 vT = ray.start.sub(v1);
    double u = vT.dot(p) * inv_det;

    if(u < 0 || u > 1){
    	return intersectionResult{-1, false, nullptr};
    }
    Vector3 q = vT.cross(e1);
    double v = ray.dir.dot(q) * inv_det;

    if(v < 0 || u + v > 1){
    	return intersectionResult{-1, false, nullptr};
    }

    double t = e2.dot(q) * inv_det;

    if(t > epsilon){
    	return intersectionResult{t, true, this};
    }
    return intersectionResult{-1, false, nullptr};
}

Vector3 Triangle::normal(Vector3 place){
	return norm;
}

//intersection algorithm from https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

