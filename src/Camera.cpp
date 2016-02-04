/*
 * Camera.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Camera.h"
#include "Vector3.h"

Camera::Camera(Vector3 position, Vector3 u, Vector3 v, Vector3 w, float width,
		float height, float dist, int hresolution, int vresolution )
        :h(hresolution), v(vresolution){

	this->position = position;

	u = u.unit();
	v = v.unit();
	w = w.unit();

	topLeft = u.mul(-width / 2).add(v.mul(-height / 2)).add(w.mul(-dist));
	hinc = u.mul(width / hresolution);
	vinc = v.mul(height / vresolution);
}

Ray Camera::makeRay(int h, int v){
	return Ray(position, topLeft.add( hinc.mul(h)).add(vinc.mul(v)));
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

