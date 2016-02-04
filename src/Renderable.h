/*
 * Renderable.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_
#include "Ray.h"
#include "Color.h"
#include "Vector3.h"
#include "Room.h"
class Room;
class Renderable {
public:
    virtual float intersect(Ray other) = 0;
    virtual Color shade(Vector3 place, Room* room) = 0;
	virtual ~Renderable();
};

#endif /* RENDERABLE_H_ */
