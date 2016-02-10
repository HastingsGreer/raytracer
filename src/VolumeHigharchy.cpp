/*
 * VolumeHigharchy.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#include "VolumeHigharchy.h"
#include <iostream>

const int X = 0, Y = 1, Z = 2;

VolumeHigharchy::VolumeHigharchy(std::vector<Triangle*>* tris, PhongProfile prof): Renderable(prof) {
	outer = (*tris)[0]->getBoundingBox();
	for(size_t i = 1; i < tris->size(); i++){
		outer = (*tris)[i]->getBoundingBox().combine(outer);
	}

	if(tris -> size() < 5){
		leftnode = nullptr;
		rightnode = nullptr;
		leavesAreTriangles = true;

		leaves = tris;
	} else {
		leavesAreTriangles = false;
		leaves = nullptr;
        double xsize = outer.maxx - outer.minx;
        double ysize = outer.maxy - outer.miny;
        double zsize = outer.maxz - outer.minz;
        std::vector<Triangle*>* leftTriangles = new std::vector<Triangle*>();

        std::vector<Triangle*>* rightTriangles= new std::vector<Triangle*>();

        int splitAxis;
        double split;

        if(xsize > ysize){
        	if (xsize > zsize){
        		splitAxis = X;
        	} else {
        		splitAxis = Z;
        	}
        } else {
        	if (ysize > zsize){
        		splitAxis = Y;
        	} else {
        		splitAxis = Z;
        	}
        }
        switch(splitAxis){
        case X :
        	split = (outer.maxx + outer.minx) / 2;
        	break;
        case Y :
        	split = (outer.maxy + outer.miny) / 2;
        	break;
        case Z :
        	split = (outer.maxz + outer.minz) / 2;
        	break;
        default: throw 123;
        }
        for(Triangle* tri : (*tris)){
        	bool test;
        	switch(splitAxis){
        	case X:
        		test = tri->v1.x + tri->v2.x + tri->v3.x > 3 * split;
        		break;
        	case Y:
        		test = tri->v1.y + tri->v2.y + tri->v3.y > 3 * split;
        		break;
        	case Z:
        		test = tri->v1.z + tri->v2.z + tri->v3.z > 3 * split;
        		break;
        	default: throw 123;
        	}
        	if(test){
        		leftTriangles->push_back(tri);
        	} else {
        		rightTriangles->push_back(tri);
        	}
		}
		std::cout << leftTriangles->size() << std::endl;

		if (leftTriangles->size() == tris->size()
				|| rightTriangles->size() == tris->size()) {
			leftnode = nullptr;
			rightnode = nullptr;
			leavesAreTriangles = true;

			leaves = tris;
		} else {

			leftnode = new VolumeHigharchy(leftTriangles, prof);

			rightnode = new VolumeHigharchy(rightTriangles, prof);
			delete tris;
		}
	}


}

VolumeHigharchy::~VolumeHigharchy() {
    if(leavesAreTriangles){
    	delete leaves;
    } else {
    	delete leftnode;
    	delete rightnode;
    }
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
