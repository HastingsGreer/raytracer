/*
 * Canvas.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include <cstring>
#include "Color.h"
#include <iostream>

class Canvas {
public:
	int h, v;
	Canvas(int h, int v);
	void setPixel(int h, int v, Color c);
	void print();
	void writeBPM(std::string filename);
	virtual ~Canvas();
private:
	Color* pixels;
};

#endif /* CANVAS_H_ */
