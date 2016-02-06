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
#include "Renderable.h"
#include "Color.h"

class AABB: public Renderable {
public:
	Vector3 min, max;
	AABB(Vector3 min, Vector3 max);
	virtual ~AABB();
};

#endif /* AABB_H_ */
