/*
 * Renderable.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Renderable.h"
Renderable::Renderable(PhongProfile prof): prof(prof) {
}

Renderable::~Renderable() {
	// TODO Auto-generated destructor stub
}

Color Renderable::shade(Vector3 place, Room* room){
	Color c = prof.ambient;
	Vector3 norm = normal(place);
	Vector3 vec2camera = room->camera->position.sub(place);
	for(Light l : room->lights){
		Vector3 vec2light = l.position.sub(place);
        float dist2light = vec2light.length();
        intersectionResult res = room->intersect(Ray(place, vec2light.unit()));
        if((!res.did_intersect ) || (res.t > dist2light)){
            c = c.add(l.color.filt(prof.diffuse) .mul(vec2light.dot(norm) > 0 ? vec2light.unit().dot(norm) : 0));

            float spectralMult = std::pow(
            		norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera).unit().dot(vec2light.unit()),
            				prof.power);
            c = c.add(l.color.filt(prof.spectral).mul(spectralMult));
        }
	}
	c =c.add( room->trace(Ray(place, norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera))).filt(prof.spectral));
    return c;


}

