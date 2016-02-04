/*
 * Color.cpp *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Color.h"
#include <cmath>
#include <sstream>



Color::Color(float r, float g, float b):
    r(r), g(g), b(b){
}

Color::Color(){
	r = 6969;
	g = 6969;
	b = 6969;
}

Color Color::add(Color other){
	return Color(this->r + other.r, this->g + other.g, this->b + other.b);
}

Color Color::filt(Color other){
	return Color(this->r * other.r, this->g * other.g, this->b * other.b);
}

bool Color::equals(Color other){
    return r == other.r && g == other.g && b == other.b;
}
Color Color::mul(float k){
	return Color(this->r * k, this->g * k, this->b * k);
}



std::string Color::repr(){

	std::ostringstream s;
	s << "(" << r << ", " << g << ", " << b << ")";
	return s.str();

}



Color Color::Black ={0, 0, 0};
Color Color::White ={1, 1, 1};
