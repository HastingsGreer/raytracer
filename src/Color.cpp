/*
 * Color.cpp *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Color.h"
#include <cmath>
#include <sstream>

#include <random>
#include "Room.h"


typedef std::mt19937 rng_type1;
std::uniform_real_distribution<> udist1(-.5, .5);

rng_type1 rng1(1312);

Color::Color(double r, double g, double b):
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
Color Color::mul(double k){
	return Color(this->r * k, this->g * k, this->b * k);
}

Color Color::randColor(){
	return Color(udist1(rng1) + .5, udist1(rng1) + .5, udist1(rng1)+ .5);
}


std::string Color::repr(){

	std::ostringstream s;
	s << "(" << r << ", " << g << ", " << b << ")";
	return s.str();

}



Color Color::Black ={0, 0, 0};
Color Color::White ={1, 1, 1};
