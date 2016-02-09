/*
 * AABB.h
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#ifndef AABB_H_
#define AABB_H_

#include "Vector3.h"
#include "Ray.h"



//this is intended to be used by other classes as a quantity with operations, like matrix, vector, and color

class AABB {
public:
	double minx, miny, minz, maxx, maxy, maxz;
	AABB();
	AABB(Vector3 min, Vector3 max);
	AABB(double minx, double miny, double minz, double maxx, double maxy, double maxz);
	double intersect(Ray ray);
    AABB combine(AABB other);
	virtual ~AABB();
};

#endif /* AABB_H_ */
