/*
 * Sphere.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Vector3.h"
#include "Ray.h"
#include "Renderable.h"
#include "Color.h"
#include "Room.h"
class Sphere : public Renderable{
public:
	Vector3 center;
	double r;
	Color c;
	Sphere(Vector3 center, double r, PhongProfile prof);
	virtual intersectionResult intersect(Ray other);
	virtual Vector3 normal(Vector3 place);
	virtual ~Sphere();
};

#endif /* SPHERE_H_ */
