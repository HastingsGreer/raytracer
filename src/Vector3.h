/*
 * Vector3.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <string>

class Vector3 {
public:
	float x;
	float y;
	float z;
	Vector3(float x, float y, float z);
	Vector3();
	Vector3 add(Vector3 other);
	Vector3 sub(Vector3 other);
	Vector3 mul(float k);
	float dot(Vector3 other);
    Vector3 unit();
    std::string repr();
};







#endif /* VECTOR3_H_ */
