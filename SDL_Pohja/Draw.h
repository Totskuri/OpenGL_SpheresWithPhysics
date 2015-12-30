#pragma once
#include "stdafx.h"
#include "Sphere.h"
#include "Shape.h"
#include "Room.h"

class Draw {

private:

	Shape* objectOne,* objectTwo;
	Room* room;

public:

	Draw();

	/*Alustus*/
	bool init();
	/*Piirrustusten hallinta*/
	void drawing();
	/*Piirrä kappale*/
	bool drawShape(Shape* obj, GLenum mode);
	/*Piirrä huone*/
	bool drawRoom(Room* rom, GLenum mode);
	/*Piirrä tausta*/
	bool drawBackground();

	/*Setterit*/
	void setObject_one(Shape* object){
		objectOne=object;
	}

	void setObject_two(Shape* object){
		objectTwo=object;
	}

	void setRoom(Room* _room){
		room = _room;
	}

};