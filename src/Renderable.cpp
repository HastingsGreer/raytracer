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

Color Renderable::shade(Vector3 place,  Room* room, Ray in){
	Color c = prof.ambient;
	Vector3 norm = normal(place);
	Vector3 vec2camera = in.dir.mul(-1);
	for(Light l : room->lights){
		Vector3 vec2light = l.position.sub(place);
		double dist2light = vec2light.length();
		intersectionResult res = room->intersect(Ray(place, vec2light.unit()));
		if((!res.did_intersect ) || (res.t > dist2light)){
			c = c.add(l.color.filt(prof.diffuse) .mul(vec2light.dot(norm) > 0 ? vec2light.unit().dot(norm) : 0));
			if(!prof.spectral.equals(Color::Black)){
				double spectralMult =
						norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera).unit().dot(vec2light.unit());
				if (spectralMult > 0){
					c = c.add(l.color.filt(prof.spectral).mul(std::pow(spectralMult, prof.power)));
				}
			}
		}
	}
	if(!prof.spectral.equals(Color::Black)){
		c =c.add( room->trace(Ray(place, norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera))).filt(prof.spectral));
	}
	return c;


}

