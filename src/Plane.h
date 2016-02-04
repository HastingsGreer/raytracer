/*
 * Plane.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Vector3.h"
#include "Ray.h"
#include "Renderable.h"
#include "Color.h"


class Plane: public Renderable {
public:
	Vector3 point, normal;
	Color c;
	Plane(Vector3 point, Vector3 normal, Color c);
	virtual float intersect(Ray other);
	virtual Color shade(Vector3 place, Room* room);
	virtual ~Plane();
};

#endif /* PLANE_H_ */
