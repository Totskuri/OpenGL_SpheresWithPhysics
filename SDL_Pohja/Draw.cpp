#include "Draw.h"

SDL_Window *window;
SDL_GLContext glcontext;

float angle = 0.0f;
float cameraRotation = 0.0f;

//object info
bool objectOneCreated = false;
bool objectTwoCreated = false;

bool roomCreated = false;

bool running = true;
const int FPS = 60;

Draw::Draw(){

}

bool Draw::init(){
	// For SDL initialization and window creation
	SDL_Init(SDL_INIT_VIDEO);			// Initialize SDL2
	window = SDL_CreateWindow(
		"An SDL2 window",				// window title
		SDL_WINDOWPOS_UNDEFINED,		// initial x position
		SDL_WINDOWPOS_UNDEFINED,		// initial y position
		1280,							// width, in pixels
		960,							// height, in pixels
		SDL_WINDOW_OPENGL				// flags - see below
		);
	if (window == NULL) {
		fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
		return false;
	}
	// OpenGL context creation
	glcontext = SDL_GL_CreateContext(window);

	return true;
}

bool Draw::drawBackground(){
	/*Background color and alpha*/
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1280.0 / 960.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	return true;
}

bool Draw::drawRoom(Room* rom, GLenum mode){
	/*Objektin identity*/
	glLoadIdentity();
	//camera position
	glTranslatef(0, 0, -5.0);
	//camera rotation
	glRotatef(cameraRotation, 0, 1, 0);

	/*Piirretään huone*/
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	rom->drawRoom();

	return true;
}

bool Draw::drawShape(Shape* obj, GLenum mode){
	/*Objektin identity*/
	glLoadIdentity();
	//camera position
	glTranslatef(0, 0, -5.0);
	//camera rotation
	glRotatef(cameraRotation, 0, 1, 0);

	/*Liikutetaan kappaletta*/
	obj->autoMoving();

	/*Piirretään kappale*/
	glPolygonMode(GL_FRONT_AND_BACK, mode);
	obj->draw();

	return true;
}

void Draw::drawing(){

	/*??*/
	Uint32 start;
	SDL_Event event;

	drawBackground();

	/*Toiminnallisuus*/
	while (running) {
		start = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					//Nuolinäppäimet liikuttavat kameraa, f ja g kääntää
				case SDLK_LEFT:  break;
				case SDLK_RIGHT: break;
				case SDLK_UP:    break;
				case SDLK_DOWN:  break;
				case SDLK_f: cameraRotation = cameraRotation + 30; break;
				case SDLK_g: cameraRotation = cameraRotation - 30; break;
					//wasdqe liikuttaa objektia yksi
				case SDLK_q:
					if (room->getSize() / 2 > objectOne->getZ() + 0.05f){
						objectOne->setObject(0, 0, 0.05f);
					}
				break;
				case SDLK_a:
					if ((room->getSize() / 2) < (objectOne->getX() - 0.05f)){
						objectOne->setObject(-0.05f, 0, 0);
					}
				break;
				case SDLK_w:
					if (room->getSize() / 2 > objectOne->getY() + 0.05f){
						objectOne->setObject(0, 0.05f, 0);
					}
				break;
				case SDLK_s:
					if (room->getSize() / 2 < objectOne->getY() - 0.05f){
						objectOne->setObject(0, -0.05f, 0);
					}
				break;
				case SDLK_e: 
					if (room->getSize() / 2 < objectOne->getZ() - 0.05f){
						objectOne->setObject(0, 0, -0.05f);
					}
				break;
				case SDLK_d: 
					if (room->getSize() / 2 > objectOne->getX() + 0.05f){
						objectOne->setObject(+0.05f, 0, 0);
					}
				break;
				}
				break;
			}
		}

		/*Check colissions*/
		if (objectOneCreated){
			objectOne->collisionCheckWall(room->getSize());
			objectOne->collisionSpheres(objectTwo);
		}
		if (objectTwoCreated){
			objectTwo->collisionCheckWall(room->getSize());
			//objectTwo->collisionSpheres(objectOne);
		}

		/*??*/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*Piirretään huone*/
		roomCreated = drawRoom(room, GL_LINE);

		/*Piirretään kappale 1 ja 2*/
		objectOneCreated = drawShape(objectOne, GL_FILL);
		objectTwoCreated = drawShape(objectTwo, GL_LINE);
		
		/*Vaihedaan frame*/
		glEnd();
		SDL_GL_SwapWindow(window);

		/*??*/
		if (1000 / FPS > SDL_GetTicks() - start)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
	}

}