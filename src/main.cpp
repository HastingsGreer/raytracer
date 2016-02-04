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



int main(){
	Color White {1,1,1};
	Color Black {0,0,0};
    double dirhorizangle = 0;
    double dirvertangle = -.2;
	Vector3 cameraPosition {1, 1, 0.};
	Vector3 u {1., 0., 0.};
	Vector3 v {0., 1., 0.};
	Vector3 w {0., 0., 1.};

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);


	int n = 2012;



    Room room { new Camera(cameraPosition, u, v, w, .2, .2, .1, n, n), false};


    room.addPrimitive(new Plane({0, -2, 0}, {0, 1, 0},
        		PhongProfile{Color {.2, .2, .2},
                             White,
                             Black,
    						 0}));
    Sphere* left = new Sphere({-4, 0, -7}, 1,
       		     PhongProfile{Color {0,0, 0},
                             {0,0,0},
                             White,
    						 32});
   Sphere* right = new Sphere({4, 0, -7}, 1,
    		PhongProfile{Color {0, 0, 0.2},
                         Color {0, 0, 1},
                         Black,
						 0});
    room.addPrimitive(left);
    room.addPrimitive(right);
    room.addPrimitive(new Sphere({0, 0, -7}, 2,
        		 PhongProfile{Color {0, .2, 0},
                              Color {0, .5, 0},
                              Color {.5, .5, .5},
    						  32}));


    Plane* movePlane = new Plane({-6, 0, 0}, {1, 0, 0},
    		PhongProfile{Color {.2, .2, .2},
                         Black,
                         Color {1, 1, 1}, 32});
    //room.addPrimitive(movePlane);
    //for(double x = -4; x < 4; x += 2){
        room.addLight(Light({-4, 4, -3}, White));

    //}
    std::cout << "starting" << std::endl;

    Vector3 arm = {4, 0, 0};
    Vector3 disp = {0, 0, -7};
    Matrix3 rot = horizMat(2.5 + 3.14);
    n = 0;
    arm = rot.trans(arm);
    left->center = disp.sub(arm);
    right->center = disp.add(arm);
//
    room.render("help.ppm");
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



