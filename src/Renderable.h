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
	double power;
};

class Renderable {
public:
	PhongProfile prof;
	Renderable(PhongProfile prof);
    virtual double intersect(const Ray other) = 0;
    virtual Vector3 normal(const Vector3 place) = 0;
    Color shade(Vector3 place, Room* room, Ray in, int recursions);
	virtual ~Renderable();
};



#endif /* RENDERABLE_H_ */
