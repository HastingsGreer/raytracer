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

const int antialias_rays = 150;

const int recurse_depth = 2;

const double antialias_divisor = 1. / antialias_rays;

Room::Room(Camera* c, bool do_antialias, bool do_shading, bool do_falloff, bool do_reflect, bool do_interreflection, bool do_shadows): camera(c), do_antialias( do_antialias), do_shading(do_shading), do_falloff(do_falloff), do_reflect(do_reflect), do_interreflection(do_interreflection), do_shadows(do_shadows){
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
							      ),
								  recurse_depth
					        ).mul(antialias_divisor));
				}
				canvas.setPixel(h, v, p);
			}
			if(v%10 == 0){
							std::cout << v << std::endl;
						}
		}
	}
	else {
		for(int v = 0; v < camera->v; v++){
			for(int h = 0; h < camera->h; h++){
				canvas.setPixel(h, v, trace(camera->makeRay(h, v), recurse_depth));
			}
			if(v%10 == 0){
				std::cout << v << std::endl;
			}
		}
	}
    canvas.writeBPM(filename);
}

Color Room::trace(Ray ray, int recursions){
	intersectionResult res = intersect(ray);
	if(res.did_intersect){
        if(do_shading){
		    return res.nearest->shade(ray.getPoint(res.t), this, ray, recursions);
        } else {
        	return Color({1, 1, 1});
        }

	} else {
		return Color({0,0,0});
	}
}

intersectionResult Room::intersect(Ray ray) {
	intersectionResult nearest = intersectionResult{-1, false, nullptr};
	for (Renderable* elem : primitives) {
		intersectionResult canidate  = elem->intersect(ray);
		if (canidate.t > .001) {
			if (nearest.t > canidate.t || nearest.t == -1) {
				nearest = canidate;
			}
		}
	}

	return nearest;
}
Room::~Room() {
	for(Renderable* r: primitives){
		delete r;
	}
	delete camera;
	// TODO Auto-generated destructor stub
}

