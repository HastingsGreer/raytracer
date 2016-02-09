/*
 * VolumeHigharchy.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#include "VolumeHigharchy.h"
#include <iostream>

VolumeHigharchy::VolumeHigharchy(std::vector<Triangle*>* tris, PhongProfile prof): Renderable(prof) {
	outer = (*tris)[0]->getBoundingBox();
	for(size_t i = 1; i < tris->size(); i++){
		outer = (*tris)[i]->getBoundingBox().combine(outer);
	}

	if(tris -> size() > 10){
		leftnode = nullptr;
		rightnode = nullptr;
		leavesAreTriangles = true;

		leaves = tris;
	} else {
        double xsize = outer.maxx - outer.minx;
        double ysize = outer.maxy - outer.miny;
        double zsize = outer.maxz - outer.minz;
	}


}

VolumeHigharchy::~VolumeHigharchy() {
	// TODO Auto-generated destructor stub
}

intersectionResult VolumeHigharchy::intersect(Ray other){
	intersectionResult nearest = intersectionResult{-1, false, nullptr};
	if(outer.intersect(other) != -1){
		if(leavesAreTriangles){

			for (Triangle* elem : (*leaves)) {
				intersectionResult canidate  = elem->intersect(other);
				if (canidate.t > .001) {
					if (nearest.t > canidate.t || nearest.t == -1) {
						nearest = canidate;
					}
				}
			}

			return nearest;
		}
		intersectionResult canidate  = leftnode->intersect(other);
		if (canidate.t > .001) {
			if (nearest.t > canidate.t || nearest.t == -1) {
				nearest = canidate;
			}
		}
		canidate  = rightnode->intersect(other);
		if (canidate.t > .001) {
			if (nearest.t > canidate.t || nearest.t == -1) {
				nearest = canidate;
			}
		}


	}
	return nearest;
}

Vector3 VolumeHigharchy::normal(Vector3 place){
	std::cout<< "fdsafsda" << std::endl;
    throw 1432;
    return Vector3();
}
