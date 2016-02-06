/*
 * Canvas.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Canvas.h"

#include <iostream>
#include <fstream>
#include <cmath>

Canvas::Canvas(int h, int v): h(h), v(v) {
	pixels = new Color[h * v];

}

void Canvas::setPixel(int i, int j, Color c){
	pixels[i + h * j] = c;
}

void Canvas::print(){
	double max = 0;
	    for(int i = v-1; i >= 0; i--){
	            for(int j = 0; j < h; j++){
	            	Color* c = & pixels[j + h * i];
	            	max = c->r > max ? c->r: max;
	            	max = c->g > max ? c->g: max;
	            	max = c->b > max ? c->b: max;

	            }
	    }
	for(int i = 0; i < v; i++){
		for(int j = 0; j < h; j++){
			Color* c = & pixels[j + h * i];
			double shade = (c->r + c->g + c->b) / (2 * max);
            std::cout << "@B%8&WM#oahkbdpqwmZO0QJUYXzcvunxrjft+~<>i!l;:,^`_-'."[(int) (shade * 53)]
			          <<"@B%8&WM#oahkbdpqwmZO0QJUYXzcvunxrjft+~<>i!l;:,^`_-'."[(int) (shade * 53)];
		}
		std::cout << std::endl;
	}
}

void Canvas::writeBPM(std::string filename){
	std::ofstream myfile;
    myfile.open (filename.c_str());
	myfile << "P3\n";
	myfile << "#cool image\n";
    myfile << h << " " << v << "\n";
    myfile << "255\n";

    double max = 0;
    for(int i = v-1; i >= 0; i--){
            for(int j = 0; j < h; j++){
            	Color* c = & pixels[j + h * i];
            	max = c->r > max ? c->r: max;
            	max = c->g > max ? c->g: max;
            	max = c->b > max ? c->b: max;

            }
    }
    for(int i = v-1; i >= 0; i--){
        for(int j = 0; j < h; j++){
    	    Color* c = & pixels[j + h * i];
    	    myfile << ((int) (std::pow((c->r / max), 1/2.2) * 255)) << " "
    	    	   << ((int) (std::pow((c->g / max), 1/2.2) * 255)) << " "
    	           << ((int) (std::pow((c->b / max), 1/2.2) * 256)) << " ";
        }
        myfile << std::endl;
    }
	myfile.close();
}

Canvas::~Canvas() {
	delete[] pixels;
}

