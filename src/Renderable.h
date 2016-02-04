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

#include <cmath>

class Room;

struct PhongProfile{
	Color ambient;
	Color diffuse;
	Color spectral;
	float power;
};

class Renderable {
public:
	PhongProfile prof;
	Renderable(PhongProfile prof);
    virtual float intersect(Ray other) = 0;
    virtual Vector3 normal(Vector3 place) = 0;
    Color shade(Vector3 place, Room* room);
	virtual ~Renderable();
};



#endif /* RENDERABLE_H_ */
