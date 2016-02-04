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
	float r;
	Color c;
	Sphere(Vector3 center, float r, Color c);
	virtual float intersect(Ray other);
	virtual Color shade(Vector3 place, Room* room);
	virtual ~Sphere();
};

#endif /* SPHERE_H_ */
