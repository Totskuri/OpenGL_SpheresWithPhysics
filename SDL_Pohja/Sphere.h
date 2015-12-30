#pragma once
#include "stdafx.h"
#include "Shape.h"


class Sphere : public Shape{

protected:


public:

	Sphere(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f, float mass=0.0f);

	/*Setterit*/
	void setSize(float _size){
		size = _size;
		radius = _size / 2.0f;
	}

	void setRoomsize(float _size){
		roomsize = _size;
	}

};