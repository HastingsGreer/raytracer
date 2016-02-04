/*
 * Light.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Vector3.h"
#include "Color.h"

class Light {
public:
	Vector3 position;
	Color color;
	Light(Vector3 position, Color color);
	virtual ~Light();
};

#endif /* LIGHT_H_ */
