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
	/*Piirr� kappale*/
	bool drawShape(Shape* obj, GLenum mode);
	/*Piirr� huone*/
	bool drawRoom(Room* rom, GLenum mode);
	/*Piirr� tausta*/
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