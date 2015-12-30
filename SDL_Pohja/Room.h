#pragma once
#include "stdafx.h"

class Room {

private:

	float roomsize;
	Room();

public:

	Room(float _size);

	void drawRoom();

	/*Getterit*/
	float getSize(){
		return roomsize;
	}

};