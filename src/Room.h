/*
 * Room.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <vector>
#include "Light.h"
#include "Camera.h"
#include "Renderable.h"
#include "Canvas.h"

class Renderable;
class Room {
public:
    std::vector<Light> lights;
    std::vector<Renderable*> primitives;
    Camera* camera;
	Room(Camera* c);
	void addPrimitive(Renderable* r);
	void addLight(Light l);
	void render();
	virtual ~Room();
};

#endif /* ROOM_H_ */
