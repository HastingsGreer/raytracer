/*
 * Ray.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Ray.h"

Ray::Ray(Vector3 start, Vector3 dir): start(start), dir(dir) {


}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

std::string Ray::repr(){
	return "{\n start:" + start.repr() + "\n dir:" + dir.repr() + "\n}";
}

Vector3 Ray::getPoint(float t){
	if(t < 0){
		throw 69;
	}
	return start.add(dir.mul(t));
}
