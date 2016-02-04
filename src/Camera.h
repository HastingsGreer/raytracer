/*
 * Camera.h
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Ray.h"
#include "Vector3.h"

class Camera {
public:
	Vector3 position;
	Vector3 vinc;
	Vector3 hinc;
	Vector3 topLeft;
	int h, v;
	Camera(Vector3 position, Vector3 u, Vector3 v, Vector3 w, double width,
			double height, double dist, int vresolution, int hresolution);
	Ray makeRay(int h, int v);
	virtual ~Camera();
};

#endif /* CAMERA_H_ */







