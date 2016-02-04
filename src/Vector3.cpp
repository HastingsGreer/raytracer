/*
 * Vector3.cpp *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Vector3.h"
#include <cmath>
#include <sstream>

Vector3::Vector3(float x, float y, float z):
    x(x), y(y), z(z){
}

Vector3::Vector3(){
	x = 6969;
	y = 6969;
	z = 6969;
}

Vector3 Vector3::add(Vector3 other){
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::sub(Vector3 other){
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::mul(float k){
	return Vector3(this->x * k, this->y * k, this->z * k);
}

float Vector3::dot(Vector3 other){
	return this->x * other.x + this->y*other.y + this->z * other.z;
}

Vector3 Vector3::unit(){
	return this->mul(1/std::sqrt(this->dot(*this)));
}

std::string Vector3::repr(){

	std::ostringstream s;
	s << "(" << x << ", " << y << ", " << z << ")";
	return s.str();

}

