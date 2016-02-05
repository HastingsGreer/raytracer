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

int main() {
	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 3.141592;
	double dirvertangle = -.2;
	Vector3 cameraPosition { 0, 1, 0. };
	Vector3 u { 1., 0., 0. };
	Vector3 v { 0., 1., 0. };
	Vector3 w { 0., 0., 1. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int n = 400;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2, .1, n, n), false};
    room.addPrimitive(new Triangle({0, 0, -12}, {10, 0, -12}, {10, 10, -12},
    		                               PhongProfile{
    	                                     {.2, .2, 0},
											 {.6, .6, 0},
											 {.4, .4, .4},
											 32}));

	room.addPrimitive(new Plane( { 0, -2, 0 }, { 0, 1, 0 }, PhongProfile {
			{.2, .2, .2}, { .8, .8, .8 }, { .2, .2, .2 }, 10 }));

	room.addPrimitive(new Plane( { 0, 0, 1 }, { 0, 0, -1 }, PhongProfile {
			Black, Black, White, 480 }));

	Sphere* left = new Sphere( { -4, 0, -7 }, 1, PhongProfile { Black, { 1, .01,
			.01 }, Black, 32 });
	Sphere* right = new Sphere( { 4, 0, -7 }, 1, PhongProfile { Black, { .01,
			.01, 1 }, Black, 0 });
	room.addPrimitive(left);
	room.addPrimitive(right);
	room.addPrimitive(new Sphere( { 0, 0, -7 }, 2, PhongProfile { Black, Color {
			.01, .5, .01 }, Color { .5, .5, .5 }, 32 }));



	Plane* movePlane = new Plane( { -6, 0, 0 }, { 1, 0, 0 }, PhongProfile {
			Color { .2, .2, .2 }, Black, Color { 1, 1, 1 }, 32 });
	//room.addPrimitive(movePlane);
	for (double x = -4; x < 4; x += 2) {
		room.addLight(Light( { x, 4, -3 }, Color::randColor().mul(40)));

	}

	room.addLight(Light( { 15, 4, -39 }, Color::randColor().mul(40)));

	std::cout << "starting" << std::endl;

	Vector3 arm = { 4, 0, 0 };
	Vector3 disp = { 0, 0, -7 };
	Matrix3 rot = horizMat(.02);
	n = 0;
	arm = rot.trans(arm);
	left->center = disp.sub(arm);
	right->center = disp.add(arm);
//
	room.render("boo.ppm");
//    while(true){
//        arm = rot.trans(arm);
//        left->center = disp.sub(arm);
//        right->center = disp.add(arm);
//
//        std::ostringstream file;
//        file << "spin/" << n;
//        room.render(file.str());
//        n++;
//    }
	std::cout << "done" << std::endl;

//    for(double x = -4; x < 4; x += .03){
//
//
//    	file << "video/" << n;
//    	n++;
//    	room.camera->position = {x, 1, 0};
//    	room.render(file.str());
//    	std::cout << x << std::endl;
//
//
//    }

}

