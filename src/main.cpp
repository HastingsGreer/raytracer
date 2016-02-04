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




int main(){

	Vector3 cameraPosition {0, 1, 0.};
	Vector3 u {1., 0., 0.};
	Vector3 v {0., 1., 0.};
	Vector3 w {0., 0., 1.};

	int n = 512;

	Color White {1,1,1};
	Color Black {0,0,0};


    Room room { new Camera(cameraPosition, u, v, w, .2, .2, .1, n, n), false};


    room.addPrimitive(new Plane({0, -2, 0}, {0, 1, 0},
        		PhongProfile{Color {.2, .2, .2},
                             White,
                             Black,
    						 0}));
    room.addPrimitive(new Sphere({-4, 0, -7}, 1,
   		     PhongProfile{Color {0.2,0, 0},
                         {1,0,0},
                         Black,
						 0}));
    room.addPrimitive(new Sphere({0, 0, -7}, 2,
        		 PhongProfile{Color {0, .2, 0},
                              Color {0, .5, 0},
                              Color {.5, .5, .5},
    						  32}));
    room.addPrimitive(new Sphere({4, 0, -7}, 1,
    		PhongProfile{Color {0, 0, 0.2},
                         Color {0, 0, 1},
                         Black,
						 0}));

    Plane* movePlane = new Plane({-6, 0, 0}, {1, 0, 0},
    		PhongProfile{Color {.2, .2, .2},
                         Color {1, 1, 1},
                         Color {1, 1, 1}, 32});
    //room.addPrimitive(movePlane);
    //for(float x = -4; x < 4; x += 2){
        room.addLight(Light({-4, 4, -3}, White));

    //}
    std::cout << "starting" << std::endl;
    room.render("hello.ppm");
    std::cout << "done" << std::endl;

    n = 0;
    for(float x = -4; x < 4; x += .03){

    	std::ostringstream file;
    	file << "video/" << n;
    	n++;
    	room.camera->position = {x, 1, 0};
    	room.render(file.str());
    	std::cout << x << std::endl;


    }





}



