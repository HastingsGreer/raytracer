/*
 * Matrix3.h
 *
 *  Created on: Feb 4, 2016
 *      Author: hastings
 */

#ifndef MATRIX3_H_
#define MATRIX3_H_
#include "Vector3.h"
#include <sstream>
#include <string>
class Matrix3 {
public:
	float a, b, c, d, e, f, g, h, i;
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	Matrix3(Vector3 v1, Vector3 v2, Vector3 v3);
	Matrix3 mult(Matrix3 other);
	Vector3 trans(Vector3 v);
	std::string repr();
	virtual ~Matrix3();
};
Matrix3 horizMat(float angle);
Matrix3 vertMat(float angle);
#endif /* MATRIX3_H_ */
