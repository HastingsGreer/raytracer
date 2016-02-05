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
	double r;
	double g;
	double b;
	Color(double r, double g, double b);
	Color();

	Color add(const Color other);
	Color mul(double k);
	Color filt(const Color other);
	bool equals(const Color other);
    std::string repr();
    static Color randColor();
    static Color Black;
    static Color White;
};









#endif /* VECTOR3_H_ */
