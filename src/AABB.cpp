/*
 * AABB.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#include "AABB.h"

AABB::AABB(Vector3 min, Vector3 max) {

	minx = 	std::min(min.x, max.x);
		miny =		std::min(min.y, max.y);
		minz =		std::min(min.z, max.z);
	maxx = std::max(min.x, max.x);
			maxy = 		std::max(min.y, max.y);
				maxz = 	std::max(min.z, max.z);

}

AABB::AABB(){

}

AABB::AABB(double minx, double miny, double minz, double maxx, double maxy, double maxz){
	this->minx = 	std::min(minx, maxx);
	this->	miny =		std::min(miny, maxy);
	this->	minz =		std::min(minz, maxz);
	this->	maxx = std::max(minx, maxx);
	this->		maxy = 		std::max(miny, maxy);
	this->			maxz = 	std::max(minz, maxz);
}
AABB AABB::combine(AABB other){
   return AABB(
    std::min(minx, other.minx),
	std::min(miny, other.miny),
	std::min(minz, other.minz),
	std::max(other.maxx, maxx),
	std::max(other.maxy, maxy),
	std::max(other.maxz, maxz));
}

double AABB::intersect(Ray ray){
    double invx, invy, invz;
    invx = 1 / ray.dir.x;
    invy = 1 / ray.dir.y;
    invz = 1 / ray.dir.z;
    double tx1 = (minx - ray.start.x)*invx;
    double tx2 = (maxx - ray.start.x)*invx;

    double tmin = std::min(tx1, tx2);
    double tmax = std::max(tx1, tx2);

    double ty1 = (miny - ray.start.y)*invy;
    double ty2 = (maxy - ray.start.y)*invy;

    tmin = std::max(tmin, std::min(ty1, ty2));
    tmax = std::min(tmax, std::max(ty1, ty2));

    double tz1 = (minz - ray.start.z)*invz;
    double tz2 = (maxz - ray.start.z)*invz;

    tmin = std::max(tmin, std::min(tz1, tz2));
    tmax = std::min(tmax, std::max(tz1, tz2));

    if( tmax < tmin){
    	return -1;
    }
    if(tmin > 0){
    	return tmin;
    }
    if (tmax > 0){
    	return tmax;
    }
    return -1;
}

AABB::~AABB() {
	// TODO Auto-generated destructor stub
}

