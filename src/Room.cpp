/*
 * Room.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Room.h"

Room::Room(Camera* c): camera(c){
	// TODO Auto-generated constructor stub

}
void Room::addLight(Light l){
	lights.push_back(l);
}

void Room::addPrimitive(Renderable* r){
	primitives.push_back(r);
}

void Room::render(){
	Canvas canvas {camera->h, camera->v};

    for(int v = 0; v < camera->v; v++){
    	for(int h = 0; h < camera->h; h++){
    		Ray ray = camera->makeRay(h, v);
            intersectionResult res = intersect(ray);
    		if(res.did_intersect){
    		    Color c = res.nearest->shade(ray.getPoint(res.t), this);
                canvas.setPixel(h, v, c);
    		} else {
    			canvas.setPixel(h, v, {0, 0, 0});
    		}
    	}
    }
    canvas.writeBPM("hello.ppm");
}

intersectionResult Room::intersect(Ray ray) {
	float nearest_t = 0;
	bool does_intersect = false;
	Renderable* nearest = nullptr;
	for (Renderable* elem : primitives) {
		float t = elem->intersect(ray);
		if (t > .0001) {
			if (nearest_t > t || nearest_t == 0) {
				does_intersect = true;
				nearest_t = t;
				nearest = elem;
			}
		}
	}
	return intersectionResult {nearest_t, does_intersect, nearest};
}
Room::~Room() {
	for(Renderable* r: primitives){
		delete r;
	}
	delete camera;
	// TODO Auto-generated destructor stub
}

