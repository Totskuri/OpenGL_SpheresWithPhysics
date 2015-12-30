#include "stdafx.h"

#include "Sphere.h"
#include "Shape.h"
#include "Draw.h"
#include "Room.h"

int main(int argc, char** argv){

	/*Alustetaan piirros*/
	Draw* newdrawing = new Draw();
	newdrawing->init();

	/*Alustetaan huone*/
	Room* room = new Room(2.6f);
	newdrawing->setRoom(room);

	/*Alustetaan objektit*/
	Sphere* sphereOne = new Sphere(0.65f, 0.0f, 0.0f,1.0f);
	Sphere* sphereTwo = new Sphere(-0.65f, 0.0f, 0.0f,1.0f);
	sphereOne->setSize(0.4f);
	sphereTwo->setSize(0.4f);
	sphereOne->setRoomsize(room->getSize());
	sphereTwo->setRoomsize(room->getSize());
	sphereOne->setSpeed(-0.0055f,0.0f,0.0f);
	sphereTwo->setSpeed(0.0025f,0.0f,0.0f);

	/*Lisätään objektit piirrokseen ja piirretään*/
	newdrawing->setObject_one(sphereOne);
	newdrawing->setObject_two(sphereTwo);
	newdrawing->drawing();

	return 0;
}