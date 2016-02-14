################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AABB.cpp \
../src/Camera.cpp \
../src/Canvas.cpp \
../src/Color.cpp \
../src/GLDrawer.cpp \
../src/Light.cpp \
../src/Matrix3.cpp \
../src/Plane.cpp \
../src/Ray.cpp \
../src/Renderable.cpp \
../src/Room.cpp \
../src/Sphere.cpp \
../src/Triangle.cpp \
../src/Vector3.cpp \
../src/VolumeHigharchy.cpp \
../src/gluttest.cpp \
../src/main.cpp \
../src/triloader.cpp 

OBJS += \
./src/AABB.o \
./src/Camera.o \
./src/Canvas.o \
./src/Color.o \
./src/GLDrawer.o \
./src/Light.o \
./src/Matrix3.o \
./src/Plane.o \
./src/Ray.o \
./src/Renderable.o \
./src/Room.o \
./src/Sphere.o \
./src/Triangle.o \
./src/Vector3.o \
./src/VolumeHigharchy.o \
./src/gluttest.o \
./src/main.o \
./src/triloader.o 

CPP_DEPS += \
./src/AABB.d \
./src/Camera.d \
./src/Canvas.d \
./src/Color.d \
./src/GLDrawer.d \
./src/Light.d \
./src/Matrix3.d \
./src/Plane.d \
./src/Ray.d \
./src/Renderable.d \
./src/Room.d \
./src/Sphere.d \
./src/Triangle.d \
./src/Vector3.d \
./src/VolumeHigharchy.d \
./src/gluttest.d \
./src/main.d \
./src/triloader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


