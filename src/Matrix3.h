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
	double a, b, c, d, e, f, g, h, i;
	Matrix3(double a, double b, double c, double d, double e, double f, double g, double h, double i);
	Matrix3(Vector3 v1, Vector3 v2, Vector3 v3);
	Matrix3 mult(Matrix3 other);
	Matrix3 scale(double k);
	Vector3 trans(Vector3 v);
	std::string repr();
	virtual ~Matrix3();
};
Matrix3 horizMat(double angle);
Matrix3 vertMat(double angle);
#endif /* MATRIX3_H_ */
