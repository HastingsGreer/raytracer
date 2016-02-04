/*
 * Canvas.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: hastings
 */

#include "Canvas.h"

#include <iostream>
#include <fstream>

Canvas::Canvas(int h, int v): h(h), v(v) {
	pixels = new Color[h * v];

}

void Canvas::setPixel(int i, int j, Color c){
	pixels[i + h * j] = c;
}

void Canvas::print(){
	for(int i = 0; i < v; i++){
		for(int j = 0; j < h; j++){
			Color* c = & pixels[j + h * i];
			float shade = (c->r + c->g + c->b) / 3;
            std::cout << "@B%8&WM#oahkbdpqwmZO0QJUYXzcvunxrjft+~<>i!l;:,^`_-'."[(int) (shade * 53)]
			          <<"@B%8&WM#oahkbdpqwmZO0QJUYXzcvunxrjft+~<>i!l;:,^`_-'."[(int) (shade * 53)];
		}
		std::cout << std::endl;
	}
}

void Canvas::writeBPM(std::string filename){
	std::ofstream myfile;
    myfile.open (filename);
	myfile << "P3\n";
	myfile << "#cool image\n";
    myfile << h << " " << v << "\n";
    myfile << "255\n";
    for(int i = 0; i < v; i++){
        for(int j = 0; j < h; j++){
    	    Color* c = & pixels[j + h * i];
    	    myfile << ((int) (c->r * 255)) << " "
    	    	   << ((int) (c->g * 255)) << " "
    	           << ((int) (c->b * 256)) << " ";
        }
        myfile << std::endl;
    }
	myfile.close();
}

Canvas::~Canvas() {
	delete[] pixels;
}

