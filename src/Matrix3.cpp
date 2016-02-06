/*
 * Matrix3.cpp
 *
 *  Created on: Feb 4, 2016
 *      Author: hastings
 */


#include <cmath>
#include "Matrix3.h"

Matrix3::Matrix3(double a, double b, double c, double d, double e, double f, double g, double h, double i): a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i){
	// TODO Auto-generated constructor stub

}

Matrix3::Matrix3(Vector3 v1, Vector3 v2, Vector3 v3){
    a = v1.x;
    b = v2.x;
    c = v3.x;
    d = v1.y;
    e = v2.y;
    f = v3.y;
    g = v1.z;
    h = v2.z;
    i = v3.z;

}

Vector3 Matrix3::trans(Vector3 v){
	return Vector3 (
			a * v.x + b * v.y + c * v.z,
			d * v.x + e * v.y + f * v.z,
			g * v.x + h * v.y + i * v.z
			);
}

Matrix3 Matrix3::scale(double k){
	return Matrix3(k * a, k * b, k * c,
			       k * d, k * e, k * f,
				   k * g, k * f, k * g);
}

Matrix3 Matrix3::mult(Matrix3 other){
    return Matrix3(
    		trans(Vector3 {other.a, other.d, other.g}),
			trans(Vector3 {other.b, other.e, other.h}),
			trans(Vector3 {other.c, other.f, other.i})
			);

}

Matrix3 vertMat(double angle){
    return Matrix3(
    		1, 0,               0,
			0, std::cos(angle),-std::sin(angle),
			0, std::sin(angle), std::cos(angle)
			);
}

Matrix3 horizMat(double angle){
    return Matrix3(
    		std::cos(angle), 0,-std::sin(angle),
			0,               1, 0,
			std::sin(angle), 0, std::cos(angle)
			);
}

std::string Matrix3::repr(){
    std::ostringstream s;
    s << "[\n";
    s << Vector3(a, b, c).repr() << "\n";
    s << Vector3(d, e, f).repr() << "\n";
    s << Vector3(g, h, i).repr() << "\n";
    s << "]\n";
    return s.str();
}

Matrix3::~Matrix3() {
	// TODO Auto-generated destructor stub
}


