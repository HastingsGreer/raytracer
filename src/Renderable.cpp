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

Color Renderable::shade(Vector3 place,  Room* room, Ray in, int recursions){

	Color c = prof.ambient;
	Vector3 norm = normal(place);
	Vector3 vec2camera = in.dir.mul(-1);
	for(Light l : room->lights){
		Vector3 vec2light = l.position.sub(place);//.add(Vector3::randSphere());
		double dist2light = vec2light.length();
		double inv_dist2l = 1/dist2light;
		Vector3 unit2light = vec2light.mul(inv_dist2l);
		intersectionResult res = room->intersect(Ray(place, unit2light));

		double invsqr = room->do_falloff ? inv_dist2l * inv_dist2l: 1 ;

		if((!res.did_intersect ) || (res.t > dist2light) || (!room->do_shadows)){
			double diffuse_coeff = unit2light.dot(norm);
			c = c.add(l.color.filt(prof.diffuse) .mul((diffuse_coeff > 0 ? diffuse_coeff : 0) * invsqr));
			if(!prof.spectral.equals(Color::Black)){
				double spectralMult =
						//norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera).unit().dot(unit2light);
						norm.dot((unit2light.add(vec2camera.unit())).unit());
				if (spectralMult > 0){
					c = c.add(l.color.filt(prof.spectral).mul(std::pow(spectralMult, prof.power) * invsqr) );
				}
			}
		}
	}
	if(!prof.reflectivity == 0 && recursions != 0 && room->do_reflect){
		c =c.mul(1 - prof.reflectivity).add( (room->trace(Ray(place, norm.mul(2 * norm.dot(vec2camera)).sub(vec2camera)), recursions - 1)).mul(prof.reflectivity));
	} else {
	    if(recursions != 0 && room->do_interreflection){
	        c =c.add( room->trace(Ray(place, Vector3::randUnit(norm)), recursions - 1).filt(prof.diffuse));
	    }
	}
	return c;


}

