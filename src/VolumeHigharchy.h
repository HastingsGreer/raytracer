/*
 * VolumeHigharchy.h
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#ifndef VOLUMEHIGHARCHY_H_
#define VOLUMEHIGHARCHY_H_

#include "Renderable.h"
#include "Triangle.h"
#include "Room.h"
#include <vector>
#include "AABB.h"

class VolumeHigharchy: public Renderable {
public:
	AABB outer;
	bool leavesAreTriangles;
	std::vector<Triangle*>* leaves;

	VolumeHigharchy* leftnode;
	VolumeHigharchy* rightnode;

	VolumeHigharchy(std::vector<Triangle*>* tris, PhongProfile prof);

    virtual intersectionResult intersect(Ray other);
    virtual Vector3 normal(Vector3 place);



	virtual ~VolumeHigharchy();
};

#endif /* VOLUMEHIGHARCHY_H_ */
