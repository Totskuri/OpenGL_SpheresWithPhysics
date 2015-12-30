#include "Room.h"

Room::Room(float _size){
	roomsize = _size;
}

void Room::drawRoom(){
	glBegin(GL_QUADS);
	// front face
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, roomsize / 2);
	glVertex3f(roomsize / 2, -roomsize / 2, roomsize / 2);
	// left face
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, -roomsize / 2);
	glVertex3f(-roomsize / 2, roomsize / 2, -roomsize / 2);
	// back face
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(roomsize / 2, roomsize / 2, -roomsize / 2);
	glVertex3f(-roomsize / 2, roomsize / 2, -roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, -roomsize / 2);
	glVertex3f(roomsize / 2, -roomsize / 2, -roomsize / 2);
	// right face
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(roomsize / 2, -roomsize / 2, roomsize / 2);
	glVertex3f(roomsize / 2, -roomsize / 2, -roomsize / 2);
	glVertex3f(roomsize / 2, roomsize / 2, -roomsize / 2);
	// top face
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, roomsize / 2, -roomsize / 2);
	glVertex3f(roomsize / 2, roomsize / 2, -roomsize / 2);
	// bottom face
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(roomsize / 2, -roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, roomsize / 2);
	glVertex3f(-roomsize / 2, -roomsize / 2, -roomsize / 2);
	glVertex3f(roomsize / 2, -roomsize / 2, -roomsize / 2);
	glEnd();
}