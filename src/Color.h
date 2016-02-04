/*
 * Vector3.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <string>

class Color {
public:
	float r;
	float g;
	float b;
	Color(float r, float g, float b);
	Color();
	Color add(Color other);
	Color mul(float k);
    std::string repr();
};







#endif /* VECTOR3_H_ */
