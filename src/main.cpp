/*
 * main.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include <iostream>
#include <string>
#include <vector>

#include <random>

#include "Vector3.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Renderable.h"
#include "Plane.h"
#include "Canvas.h"
#include "Room.h"
#include <sstream>
#include "Matrix3.h"
#include "Triangle.h"
#include "gluttest.h"
int main() {



	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = 0;
	Vector3 cameraPosition { 0, 0, 0. };
	Vector3 u { 1., 0., 0. };
	Vector3 v { 0., 1., 0. };
	Vector3 w { 0., 0., 1. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int n = 512;


	Room room { new Camera(cameraPosition, u, v, w, .2, .2, .1, n, n), false};

	room.addPrimitive(new Plane( { 0, -2, 0 }, { 0, 1, 0 }, PhongProfile {
			{.2, .2, .2}, { .8, .8, .8 }, { .2, .2, .2 }, 10 }));

	Sphere* left = new Sphere( { -4, 0, -7 }, 1, PhongProfile { {.2, 0, 0}, { 1, 0,
			.0 }, Black, 32 });
	Sphere* right = new Sphere( { 4, 0, -7 }, 1, PhongProfile { {0, 0, .2}, { .01,
			.01, 1 }, Black, 0 });
	room.addPrimitive(left);
	room.addPrimitive(right);
	room.addPrimitive(new Sphere( { 0, 0, -7 }, 2, PhongProfile { {0, .2, 0}, Color {
			.01, .5, .01 }, Color { .5, .5, .5 }, 32 }));




	room.addLight(Light( { -4, 4, -3 }, White));

	std::cout << "starting" << std::endl;

    room.render("out.ppm");

	std::cout << "done" << std::endl;


}

