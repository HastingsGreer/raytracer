/*
 * Room.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Room.h"
#include <random>

typedef std::mt19937 rng_type;
std::uniform_real_distribution<> udist(-.5, .5);

rng_type rng;

const int antialias_rays = 64;

const float antialias_divisor = 1. / antialias_rays;

Room::Room(Camera* c, bool do_antialias): camera(c), do_antialias(do_antialias){
	// TODO Auto-generated constructor stub

}
void Room::addLight(Light l){
	lights.push_back(l);
}

void Room::addPrimitive(Renderable* r){
	primitives.push_back(r);
}

void Room::render(std::string filename){
	Canvas canvas {camera->h, camera->v};
	if(do_antialias){
		for(int v = 0; v < camera->v; v++){
			for(int h = 0; h < camera->h; h++){
				Color p {0, 0, 0};
				for(int cast = 0; cast < antialias_rays; cast ++){
					Ray ray = camera->makeRay(h, v);
					p = p.add(trace(
							Ray(ray.start,
									ray.dir.add( camera->hinc.mul(udist(rng))).add(camera->vinc.mul(udist(rng)))
							)).mul(antialias_divisor));
				}
				canvas.setPixel(h, v, p);
			}
		}
	}
	else {
		for(int v = 0; v < camera->v; v++){
			for(int h = 0; h < camera->h; h++){
				canvas.setPixel(h, v, trace(camera->makeRay(h, v)));
			}
		}
	}
    canvas.writeBPM(filename);
}

Color Room::trace(Ray ray){
	intersectionResult res = intersect(ray);
	if(res.did_intersect){
		return res.nearest->shade(ray.getPoint(res.t), this);

	} else {
		return Color({0, 0, 0});
	}
}

intersectionResult Room::intersect(Ray ray) {
	float nearest_t = 0;
	bool does_intersect = false;
	Renderable* nearest = nullptr;
	for (Renderable* elem : primitives) {
		float t = elem->intersect(ray);
		if (t > .001) {
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
