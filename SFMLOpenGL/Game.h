#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	int m_shape = -1;
	GLfloat m_rotationAngle;

	// Uncomment for Part 2
	// ********************
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;
	bool flip;
	int current;

	GLfloat rotationAngle = 0.0f;
	bool rotating;
	// ********************
};