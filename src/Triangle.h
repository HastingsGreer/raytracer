/*
 * Triangle.h
 *
 *  Created on: Feb 5, 2016
 *      Author: hastings
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_


#include "Vector3.h"
#include "Ray.h"
#include "Renderable.h"
#include "Color.h"
#include "Room.h"

class Triangle: public Renderable {
public:
	Vector3 v1, v2, v3, e1, e2, norm;
	Triangle(Vector3 v1, Vector3 v2, Vector3 v3, PhongProfile prof);
	virtual double intersect(Ray other);
	virtual Vector3 normal(Vector3 place);
	virtual ~Triangle();
};

#endif /* TRIANGLE_H_ */
