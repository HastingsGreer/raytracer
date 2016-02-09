/*
 * triloader.h

 *
 *  Created on: Feb 6, 2016
 *      Author: hastings
 */

#include "Room.h"
#include <string>

#include "Vector3.h"
#include "Matrix3.h"
#include "Renderable.h"
#include "Triangle.h"
#include "VolumeHigharchy.h"


void loadtriangles(Room* room, std::string filename, Vector3 displacement, Matrix3 rotation, PhongProfile prof);



