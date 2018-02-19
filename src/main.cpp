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

int reflectiveSpheres();
int boringReflectiveSpheres();
int sibenik();
int sibenikNoShadow();
typedef std::mt19937 rng_type2;
int wild(int argc, char * argv[]);

std::uniform_real_distribution<> udist2(-.5, .5);

rng_type2 rng2(113);

int main(int argc, char * argv[]) {
	/*boringReflectiveSpheres();
	sibenikNoShadow();
	sibenik();*/
	reflectiveSpheres();
        //wild(argc, argv);
}

int sibenik() {
	bool do_interreflection = false;
	bool do_falloff = false;
	bool do_reflect = false;
	bool do_shading = true;
	bool do_antialias = false;
	bool do_shadows = true;
	std::string out = "sibenik.ppm";


	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = 0;
	Vector3 cameraPosition { 0, -10, 0 };
	Vector3 u { 0., 0., 1. };
	Vector3 v { 0., 1., 0. };
	Vector3 w { -1., 0., 0. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int h = 512;
	int vert = 512;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h,
			vert), do_antialias, do_shading, do_falloff, do_reflect, do_interreflection, do_shadows };

	loadtriangles(&room, "stl/sibenik2.plain", { 0, 0, 0 }, Matrix3 { 1, 0, 0,
			0, 1, 0, 0, 0, 1 },
			PhongProfile { Black, { 1, 1, 1 }, Black, 32 , 0});

	room.addLight(Light( { 0, 0, 0 }, Color(1, 1, 1).mul(1 + 39 * do_falloff)));
	std::cout << "starting" << std::endl;

	room.render(out);

	std::cout << "done" << std::endl;
}

int sibenikNoShadow() {
	bool do_interreflection = false;
	bool do_falloff = false;
	bool do_reflect = false;
	bool do_shading = true;
	bool do_antialias = false;
	bool do_shadows = false;
	std::string out = "sibenikNoShadow.ppm";


	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = 0;
	Vector3 cameraPosition { 0, -10, 0 };
	Vector3 u { 0., 0., 1. };
	Vector3 v { 0., 1., 0. };
	Vector3 w { -1., 0., 0. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int h = 512;
	int vert = 512;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h,
			vert), do_antialias, do_shading, do_falloff, do_reflect, do_interreflection, do_shadows };

	loadtriangles(&room, "stl/sibenik2.plain", { 0, 0, 0 }, Matrix3 { 1, 0, 0,
			0, 1, 0, 0, 0, 1 },
			PhongProfile { Black, { 1, 1, 1 }, Black, 32 , 0});

	room.addLight(Light( { 0, 0, 0 }, Color(1, 1, 1).mul(1 + 39 * do_falloff)));
	std::cout << "starting" << std::endl;

	room.render(out);

	std::cout << "done" << std::endl;
}

int reflectiveSpheres() {
	bool do_interreflection = true;
	bool do_falloff = true;
	bool do_reflect = true;
	bool do_shading = true;
	bool do_antialias = true;
	bool do_shadows = true;
	std::string out = "sphfdgseres.ppm";


	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = 0;
	Vector3 cameraPosition { 0, 0, 20 };
	Vector3 u { 1, 0, 0 };
	Vector3 v { 0., 1., 0. };
	Vector3 w { 0, 0., 1};

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int h = 1080;
	int vert = 1920;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h,
			vert), do_antialias, do_shading, do_falloff, do_reflect, do_interreflection, do_shadows };

         room.addPrimitive(new Plane( { 0, -2, 0 }, { 0, 1, 0 }, PhongProfile {
         		Black, { .5, .5, .5 }, Black, 0, .5 }));

         Sphere* s1 = new Sphere( { -4, 0, -7 }, 1, PhongProfile { { 0, 0, 0 }, { 1,
         		1, 1 }, { 0, 0, 0 }, 32 });

         Sphere* s2 = new Sphere( { 0, 0, -7 }, 2, PhongProfile { { 0, .0, 0 }, { 0,
         		1, 0 }, { .5, .5, .5 }, 32 });

         Sphere* s3 = new Sphere( { 4, 0, -7 }, 1, PhongProfile { { 0, 0, .0 }, { 1,
         		1, 1 }, { 0, 0, 0 }, 0, .8});
         room.addPrimitive(s1);

         room.addPrimitive(s2);

         room.addPrimitive(s3);






	for(float magic = 0; magic < 100; magic += 2){
		 Color c = Color::randColor();
	     room.addPrimitive(new Sphere( { 42 * udist2(rng2), 12 * udist2(rng2) + 12, 14 * udist2(rng2)}, 2, PhongProfile { Black, c, c.mul(0.2), 0, .5}));
	}



	for(float magic = 0; magic < 20; magic ++){
	room.addLight(Light( { 8 * udist2(rng2), 8 * udist2(rng2), 8 * udist2(rng2)}, Color::randColor().mul(140)));
	}

         
	room.addLight(Light( { 40, 40, -30}, Color(.5, .5, 1).mul(1 + 39 * do_falloff)));
	room.addLight(Light( { -40, 40, -30}, Color(1, 1, 1).mul(1 + 39 * do_falloff)));
	std::cout << "starting" << std::endl;

	room.render(out);

	std::cout << "done" << std::endl;
}

int boringReflectiveSpheres() {
	bool do_interreflection = false;
	bool do_falloff = false;
	bool do_reflect = true;
	bool do_shading = true;
	bool do_antialias = false;
	bool do_shadows = true;
	std::string out = "spheres.ppm";


	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle = 0;
	Vector3 cameraPosition { 0, 0, 0 };
	Vector3 u { 1, 0, 0 };
	Vector3 v { 0., 1., 0. };
	Vector3 w { 0, 0., 1};

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);

	int h = 512;
	int vert = 512;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h,
			vert), do_antialias, do_shading, do_falloff, do_reflect, do_interreflection, do_shadows};

	room.addPrimitive(new Plane( { 0, -2, 0 }, { 0, 1, 0 }, PhongProfile {
			{.2, .2, .2}, {1, 1, 1}, Black, 0, .5 }));

	Sphere* s1 = new Sphere( { -4, 0, -7 }, 1, PhongProfile { { .2, 0, 0 }, { 1,
			0, .0 }, { 0, 0, 0 }, 32, 0 });

	Sphere* s2 = new Sphere( { 0, 0, -7 }, 2, PhongProfile { { 0, .2, 0 }, { 0,
			.5, 0 }, { .5, .5, .5 }, 32, 0 });

	Sphere* s3 = new Sphere( { 4, 0, -7 }, 1, PhongProfile { { 0, 0, .2 }, { 0,
			0, 1 }, { 0, 0, 0 }, 0, .8});
	room.addPrimitive(s1);

	room.addPrimitive(s2);

	room.addPrimitive(s3);







	room.addLight(Light( { -4, 4, -3}, Color(1, 1, 1)));
	
	room.addLight(Light( { -4, 4, -3}, Color(1, 1, 1)));
	room.addLight(Light( { -4, -4, -3}, Color(7, 7, 10)));
        std::cout << "starting" << std::endl;

	room.render(out);

	std::cout << "done" << std::endl;
}
int wild(int argc, char * argv[]){
       bool do_falloff = true;
	bool do_reflect = false;
	bool do_shading = false;
	bool do_antialias = false;
	bool do_teapot = false;
        std::string out = "out8.ppm";

	for(int argi = 1; argi < argc; argi++){
		std::string arg = std::string(argv[argi]);
		if(arg == "--teapot"){
			do_teapot = true;
		} else if(arg == "--antialias"){
			do_antialias = true;
		} else if(arg == "--shade"){
			do_shading = true;
		} else if(arg == "--reflect"){
			do_reflect = true;
		} else if(arg == "--falloff"){
			do_falloff = true;
		} else if(arg == "-o"){
			argi++;
			if(argi >= argc){
				std::cout << "must specify output file after -o" << std::endl;
				return -1;
			}
			out = std::string(argv[argi]);
		}

	}

	do_falloff = true;
	//do_reflect = true;
	do_teapot = true;

	Color White { 1, 1, 1 };
	Color Black { 0, 0, 0 };
	double dirhorizangle = 0;
	double dirvertangle =  0;
	Vector3 cameraPosition { 0, -10, 0 };
	Vector3 u { 0., 0., 1. };
	Vector3 v { 0., 1., 0. };
	Vector3 w {-1., 0., 0. };

	Matrix3 camDirMat = horizMat(dirhorizangle).mult(vertMat(dirvertangle));

	u = camDirMat.trans(u);
	v = camDirMat.trans(v);
	w = camDirMat.trans(w);


	int h = 512;
	int vert = 512;

	Room room { new Camera(cameraPosition, u, v, w, .2, .2 * vert / h, .1, h, vert), do_antialias, do_shading, do_falloff, do_reflect, false, false};


	loadtriangles(&room, "stl/sibenik2.plain", { 0, 0, 0 }, Matrix3 { 1, 0, 0,
		                                                          0, 1, 0,
																	  0, 0, 1 },
			PhongProfile {Black, {.5, .5, .5}, Black, 32 });


	if(do_teapot){
	    loadtriangles(&room, "stl/teapot.plain", { 6, -9, -1 },
			horizMat(0).mult(vertMat(-3.14 / 2).scale(.01)), PhongProfile { { 0,
					.02, 0 }, { 0, .8, 0 }, {.2, .2, .2}, 32 });
    }
	room.addPrimitive(new Plane( { 0, -12, 0 }, { 0, 1, 0 }, PhongProfile {
			Black, {.5, .5, .5}, Black, 0 }));


	Sphere* s1 = new Sphere({6, -10, 2}, 1, PhongProfile {{0, 0, 0}, { .7, 0,
			.0 }, {.1, .1, .1}, 32});

	Sphere* s2 = new Sphere( { 6, -10, 0 }, 1, PhongProfile { {0, .0, 0}, {0,
			.5, 0 }, {.1, .1, .1}, 32 });

	Sphere* s3 = new Sphere({3, -10, -1}, 1, PhongProfile { { 0,
					0, .0 }, { 0, 0, 1 }, {0, 0, 0}, 0 });
	room.addPrimitive(s1);

	room.addPrimitive(s2);


	room.addPrimitive(s3);

	for(float magic = 0; magic < 100; magic += 2){
		 Color c = Color::randColor();
	     room.addPrimitive(new Sphere( { 42 * udist2(rng2), 12 * udist2(rng2) + 12, 14 * udist2(rng2)}, 2, PhongProfile { Black, c, c.mul(.2), 32 }));
	}



	for(float magic = 0; magic < 20; magic ++){
	room.addLight(Light( { 8 * udist2(rng2), 8 * udist2(rng2), 8 * udist2(rng2)}, Color::randColor().mul(140)));
	}

	//room.addLight(Light({0, 0, 0}, Color(1, 1, 1).mul(1 + 140 * do_falloff)));
	//room.addLight(Light({12, -10, 5}, Color(0, 1, 0).mul(1 + 39 * do_falloff)));
	room.addLight(Light({0, 0, 0}, Color(1, 1, 1).mul(1 + 39 * do_falloff)));
	std::cout << "starting" << std::endl;

    room.render(out);

	std::cout << "done" << std::endl;
}

