/*
 * Room.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <vector>
#include <string>
#include "Light.h"
#include "Camera.h"
#include "Renderable.h"
#include "Canvas.h"
#include <iostream>

class Renderable;

struct intersectionResult{
	double t;
	bool did_intersect;
	Renderable* nearest;
};

class Room {
public:
    std::vector<Light> lights;
    std::vector<Renderable*> primitives;
    Camera* camera;
	Room(Camera* c);
	void addPrimitive(Renderable* r);
	void addLight(Light l);
	void render(std::string filename, bool do_antialias, bool do_shading, bool do_falloff);
	virtual ~Room();
	intersectionResult intersect(Ray r);
	Color trace(Ray r, int recursions);
};



#endif /* ROOM_H_ */
