/*
 * triloader.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */
#include "triloader.h"
#include <fstream>

void loadtriangles(Room* room, std::string filename, Vector3 displacement, Matrix3 rotation, PhongProfile prof){
	std::ifstream tri_file;
	tri_file.open(filename.c_str());
    int n;
    tri_file >> n;
    for(int j = 0; j < n; j++){
    	double x, y, z;

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v1 {x, y, z};

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v2 {x, y, z};

    	tri_file >> x;
    	tri_file >> y;
    	tri_file >> z;
    	Vector3 v3 {x, y, z};

    	room->addPrimitive(new Triangle(v1, v2, v3, prof));
    }
}

