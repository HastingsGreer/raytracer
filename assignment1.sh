#!/bin/bash
cd Release
make clean
make all
cd ..
Release/raytracer -o part1.ppm 
Release/raytracer -o part2.ppm --shade
Release/raytracer -o part3.ppm --shade --antialias
Release/raytracer -o teapotproblems.ppm --shade --reflect --falloff --teapot
