/*
 * Vector3.cpp *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Vector3.h"
#include <cmath>
#include <sstream>

#include <random>

typedef std::mt19937 rng_type3;
std::uniform_real_distribution<> udist3(-1, 1);

rng_type3 rng3(1312);

Vector3::Vector3(double x, double y, double z):
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

Vector3 Vector3::mul(double k){
	return Vector3(this->x * k, this->y * k, this->z * k);
}

double Vector3::dot(Vector3 other){
	return this->x * other.x + this->y*other.y + this->z * other.z;
}

Vector3 Vector3::cross(Vector3 other){
	return Vector3(y * other.z - z * other.y,
			       z * other.x - x * other.z,
				   x * other.y - y * other.x);
}

double Vector3::length(){
	return std::sqrt(this->dot(*this));
}

Vector3 Vector3::unit(){
	return this->mul(1/std::sqrt(this->dot(*this)));
}

Vector3 Vector3::randUnit(Vector3 center){
	Vector3 result;
	do {
		result = Vector3(udist3(rng3), udist3(rng3), udist3(rng3));
	} while (result.dot(center) < 0 || result.dot(result) > 1) ;
	return result.unit();
}

Vector3 Vector3::randSphere(){
	Vector3 result = Vector3(udist3(rng3), udist3(rng3), udist3(rng3));
	return result;
}

std::string Vector3::repr(){

	std::ostringstream s;
	s << "(" << x << ", " << y << ", " << z << ")";
	return s.str();

}

