#pragma once
#include "stdafx.h"
/*Sis�lt�� ainoastaan kappaleesta riippumattomia m��reit�.
Eli massakeskipisteen  ominaisuuksia*/
class Shape {

protected:

	float x,y,z;

	float speedX, speedY, speedZ;

	float roomsize;
	float size;
	float radius;
	float mass;

public:

	/*Virtuaaliset*/
	virtual void draw();
	virtual float getSize();
	virtual void collisionCheckWall(float _roomsize);
	virtual void collisionSpheres(Shape* sphereTwo);

	/*Matikka funktiot*/
	/*Lopullinen t�rm�yksen j�lkeinen nopeus*/
	virtual void setAfterCollisionSpeed(Shape* sphereTwo);
	/*Impulssi*/
	/*T�m� funktio sis�lt�� t�rm�yskertoimen*/
	virtual float getImpulse(Shape* sphereTwo);
	/*T�rm�yksen suuntaisen yksikk�vektorin N komponentit*/
	virtual float getNX(Shape* sphereTwo);
	virtual float getNY(Shape* sphereTwo);
	virtual float getNZ(Shape* sphereTwo);
	/*Pallojen koordinaattien erotuksen itseisarvo*/
	virtual float getItseisarvo(Shape* sphereTwo);

	/*Kappaleen liikuttaminen nopeuden mukaan*/
	void autoMoving(){
		setObject(speedX, speedY, speedZ);
		glTranslatef(x, y, z);
	}

	/*Setterit*/
	void setSpeed(float n_speedX, float n_speedY, float n_speedZ){
		speedX = n_speedX;
		speedY = n_speedY;
		speedZ = n_speedZ;
	}

	void setObject(float _x = 0, float _y = 0, float _z = 0){
		x += _x;
		y += _y;
		z += _z;
	}

	void setNewCordinates(float _x = 0, float _y = 0, float _z = 0){
		x = _x;
		y = _y;
		z = _z;
	}

	/*Getterit*/
	float getX(){
		return x;
	}

	float getY(){
		return y;
	}

	float getZ(){
		return z;
	}

	float getMass(){
		return mass;
	}

	float getSpeedX(){
		return speedX;
	}

	float getSpeedY(){
		return speedY;
	}


	float getSpeedZ(){
		return speedZ;
	}

};