#include "Sphere.h"

Sphere::Sphere(float _x, float _y, float _z, float _mass){
	x = _x;
	y = _y;
	z = _z;

	speedX = 0.0f;
	speedY = 0.0f;
	speedZ = 0.0f;

	mass = _mass;
}


float Shape::getSize(){
	return size;
}

void Shape::draw(){
	float lats = 10.0f;
	float longs = 10.0f;
	int i, j;
	for (i = 0; i <= lats; i++) {
		float lat0 = M_PI * (-0.5 + (float)(i - 1) / lats);
		float z0 = sin(lat0) * radius;
		float zr0 = cos(lat0) * radius;

		float lat1 = M_PI * (-0.5 + (float)i / lats);
		float z1 = sin(lat1) * radius;
		float zr1 = cos(lat1) * radius;

		glBegin(GL_QUAD_STRIP);
		glColor3f(1.0, 0.0, 1.0);
		for (j = 0; j <= longs; j++) {
			float lng = 2 * M_PI * (float)(j - 1) / longs;
			float x = cos(lng);
			float y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
		}
		glEnd();
	}
}

void Shape::collisionSpheres(Shape* sphereTwo){
	//check collision with object two
	float xd = x - sphereTwo->getX();
	float yd = y - sphereTwo->getY();
	float zd = z - sphereTwo->getZ();
	float distance = sqrt((xd * xd) + (yd * yd) + (zd * zd));
	float width = (size + sphereTwo->getSize()) / 2;
	if (distance < width){

		//liikutetaan takaisin rajalle
		float erotus = (size - sphereTwo->getSize()) / 2;
		erotus = erotus / 2;

		setObject(erotus, erotus, erotus);
		sphereTwo->setObject(erotus, erotus, erotus);

		//uusi suunta ja nopeus
		setAfterCollisionSpeed(sphereTwo);
	}
}

void Shape::collisionCheckWall(float _roomsize){
	//check collision with room
	float _size = size -0.1f;
	float roomsize = _roomsize;
	if (x >= (roomsize / 2 - _size / 2)){ //check x +
		setSpeed(speedX * -1, speedY, speedZ);
		//X = X - 0.05;
	}
	else if (x <= (-roomsize / 2 + _size / 2)){ //check x -
		setSpeed(speedX  * -1, speedY, speedZ);
		//X = X + 0.05;
	}
	else if (y >= (roomsize / 2 - _size / 2)){ //check y +
		setSpeed(speedX, y * -1, speedZ);
		//Y = Y - 0.05;
	}
	else if (y <= (-roomsize / 2 + _size / 2)){ //check y -
		setSpeed(speedX, speedY * -1, speedZ);
		//Y = Y + 0.05;
	}
	else if (z >= (roomsize / 2 - _size / 2)){ //check z +
		setSpeed(speedX, speedY, speedZ * -1);
		//Z = Z - 0.05;
	}
	else if (z <= (-roomsize / 2 + _size / 2)){ //check z -
		setSpeed(speedX, speedY, speedZ * -1);
		//Z = Z + 0.05;
	}
}

void Shape::setAfterCollisionSpeed(Shape* sphereTwo){

	std::cout << speedX << "x " << speedY << "y " << speedZ << "z nopeus1 ennen \n";
	std::cout << sphereTwo->getSpeedX() << "x " << sphereTwo->getSpeedY() << "y " << sphereTwo->getSpeedZ() << "z nopeus2 ennen \n";

	float impulse = getImpulse(sphereTwo);

	float vx = speedX + ((impulse / mass)*getNX(sphereTwo));
	float vy = speedY + ((impulse / mass)*getNY(sphereTwo));
	float vz = speedZ + ((impulse / mass)*getNZ(sphereTwo));

	float vx2 = sphereTwo->getSpeedX() - ((impulse / sphereTwo->getMass())*getNX(sphereTwo));
	float vy2 = sphereTwo->getSpeedY() - ((impulse / sphereTwo->getMass())*getNY(sphereTwo));
	float vz2 = sphereTwo->getSpeedZ() - ((impulse / sphereTwo->getMass())*getNZ(sphereTwo));

	std::cout << vx << "x " << vy<< "y " << vz << "z nopeus1 jalkeen \n";
	std::cout << vx2 << "x " << vy2 << "y " << vz2 << "z nopeus2 jalkeen \n";

	setSpeed(vx,vy,vz);
	sphereTwo->setSpeed(vx2,vy2,vz2);
}


float Shape::getImpulse(Shape* sphereTwo){
	/*Törmäyskerroin*/
	/*Vain arvoja välillä -1.0 -> -2.0 */
	float kerroin=-1.5f;
	float jakaja = (1 / mass)+(1 / sphereTwo->getMass());

	float nimittäjä = ((speedX - sphereTwo->getSpeedX())*getNX(sphereTwo)) + ((speedY - sphereTwo->getSpeedY())*getNY(sphereTwo)) + ((speedZ - sphereTwo->getSpeedZ())*getNZ(sphereTwo));

	float tulos = kerroin * (nimittäjä / jakaja);

	std::cout << tulos << " impulse \n";

	return tulos;
}

float Shape::getNX(Shape* sphereTwo){
	return (x - sphereTwo->getX()) / getItseisarvo(sphereTwo);
}

float Shape::getNY(Shape* sphereTwo){
	return (y - sphereTwo->getY()) / getItseisarvo(sphereTwo);
}

float Shape::getNZ(Shape* sphereTwo){
	return (z - sphereTwo->getZ()) / getItseisarvo(sphereTwo);
}

float Shape::getItseisarvo(Shape* sphereTwo){

	float powx = pow(x - sphereTwo->getX(), 2.0f);
	float powy = pow(y - sphereTwo->getY(), 2.0f);
	float powz = pow(z - sphereTwo->getZ(), 2.0f);

	return sqrt(powx + powy + powz);
}