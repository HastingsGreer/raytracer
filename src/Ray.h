/*
 * Ray.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vector3.h"
#include <string>
class Ray {
public:
	Vector3 start;
	Vector3 dir;
	Ray(Vector3 start, Vector3 dir);
	std::string repr();
	Vector3 getPoint(float t);
	virtual ~Ray();
};

#endif /* RAY_H_ */
