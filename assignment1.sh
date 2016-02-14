#!/bin/bash
cd Release
make all
cd ..
Release/raytracer -f part1.ppm 
Release/raytracer -f part2.ppm --shade
Release/raytracer -f part3.ppm --shade --antialias
