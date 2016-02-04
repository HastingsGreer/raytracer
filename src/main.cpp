/*
 * main.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include <iostream>
#include <string>
#include <vector>


#include "Vector3.h"
#include "Camera.h"
#include "Ray.h"
#include "Sphere.h"
#include "Renderable.h"
#include "Plane.h"
#include "Canvas.h"
#include "Room.h"

int main(){
	Vector3 cameraPosition {0., 0., 0.};
	Vector3 u {1., 0., 0.};
	Vector3 v {0., 1., 0.};
	Vector3 w {0., 0., 1.};

	int n = 1000;

    Room room { new Camera(cameraPosition, u, v, w, .2, .2, .1, n, n)};



    room.addPrimitive(new Sphere({0, 0, -7}, 2, {.2, 0, 0}));
    room.addPrimitive(new Sphere({-4, 0, -7}, 1, {0, .2, 0}));
    room.addPrimitive(new Sphere({4, 0, -7}, 1, {0, 0, .2}));
    room.addPrimitive(new Plane({0, -2, 0}, {0, 1, 0}, {.2, .2, .2}));

    room.render();

    std::cout << "starting" << std::endl;





}



