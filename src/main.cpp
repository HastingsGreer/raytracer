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
#include "triloader.h"



typedef std::mt19937 rng_type2;
std::uniform_real_distribution<> udist2(-.5, .5);

rng_type2 rng2(113);

int main() {



	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = -.1;
	Vector3 cameraPosition { 0, 10, 40. };
	Vector3 u { 1., 0., 0. };
	Vector3 v { 0., 1., 0. };
	Vector3 w { 0., 0., 1. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);


	int h = 1600;
	int vert = 900;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h, vert), false};


	loadtriangles(&room, "stl/teapot.plain", {0, 0, 0}, horizMat(0), PhongProfile {
					Black, { .8, .8, .8 }, { .2, .2, .2 }, 10 });

//	room.addPrimitive(new Plane( { 0, -2, 0 }, { 0, 1, 0 }, PhongProfile {
//			Black, { .8, .8, .8 }, { .2, .2, .2 }, 10 }));
//
//
//	Sphere* left = new Sphere( { -4, 0, -7 }, 1, PhongProfile { Black, { 1, 0,
//			.0 }, Black, 3PhongProfile {
	//			Black, { .8, .8, .8 }, { .2, .2, .2 }, 10 }2 });
//	Sphere* right = new Sphere( { 4, 0, -7 }, 1, PhongProfile { Black, { .01,
//			.01, 1 }, Black, 0 });
//	room.addPrimitive(left);
//	room.addPrimitive(right);
//	for(float magic = 0; magic < 100; magic += 2){
//		 Color c = Color::randColor();
//	     room.addPrimitive(new Sphere( { 42 * udist2(rng2), 12 * udist2(rng2) + 12, 14 * udist2(rng2)}, 2, PhongProfile { Black, c, c.mul(.2), 32 }));
//	}



	for(float magic = 0; magic < 100; magic += 20){
	room.addLight(Light( { 42 * udist2(rng2), 12 * udist2(rng2) + 37, 14 * udist2(rng2)}, Color::randColor().mul(140)));
	}
	std::cout << "starting" << std::endl;

    room.render("out4564553645.ppm");

	std::cout << "done" << std::endl;


}

