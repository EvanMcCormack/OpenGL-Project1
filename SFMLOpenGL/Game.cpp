#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	index = 0;
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
			{
				m_shape = 10;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				m_shape = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				m_shape = 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				m_shape = 3;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				m_shape = 4;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			{
				m_shape = 5;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			{
				m_shape = 6;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			{
				m_shape = 7;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
			{
				m_shape = 8;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			{
				m_shape = 9;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				rotating = true;
				m_rotationAngle += 0.01f;
				if (m_rotationAngle >= 360)
				{
					m_rotationAngle -= 360;
				}
			}
			else
			{
				rotating = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				glTranslatef(0.0f, 0.5f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				glTranslatef(0.0f, -0.5f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				glTranslatef(0.5f, 0.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				glTranslatef(-0.5f, 0.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				glScalef(1.1f, 1.1f, 1.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				glScalef(-1.1f, -1.1f, 1.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				glLoadIdentity();
			}
		}

		update();
		draw();
	}

}

void Game::initialize()
{
	int current = 0;
	index = 1; 
	glGenLists(9);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / 
	window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	isRunning = true;

	//Points
	glNewList(index, GL_COMPILE);
	glBegin(GL_POINTS); {
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
	}
	glEnd();
	glPointSize(5);
	glEndList();

	//Lines
	glNewList(index + 1, GL_COMPILE);
	glLineWidth(3);
	glBegin(GL_LINES); {
		glVertex3f(0.5, 1.5, -5.0);
		glVertex3f(-1.5, -1.0, -5.0);
		glVertex3f(1.5, -1.0, -5.0);
		glVertex3f(0.0, -0.5, -5.0);
	}
	glEnd();
	glEndList();

	//Line Strip
	glNewList(index  + 2, GL_COMPILE);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP); {
		glVertex3f(-1.5, -1.5, -5.0);
		glVertex3f(-0.5, -1.5, -5.0);
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(1.5, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	//Line Loop
	glNewList(index + 3, GL_COMPILE);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP); {
		glVertex3f(-1.5, -1.5, -5.0);
		glVertex3f(-0.5, -1.5, -5.0);
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(0.0, 1.5, -5.0);
		glVertex3f(-1.5, 1.0, -5.0);
	}
	glEnd();
	glEndList();

	//Triangle
	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_TRIANGLES); {
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	//Triangle Strip
	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(-1.5, -1.5, -5.0);
		glVertex3f(-1.0, -0.5, -5.0);
		glVertex3f(-0.5, -1.0, -5.0);
		glVertex3f(-1.0, 0.5, -5.0);
		glVertex3f(0.5, 1.0, -5.0);
		glVertex3f(-1.5, 1.5, -5.0);
	}
	glEnd();
	glEndList();

	//Triangle Fan
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN); {
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(-1.0, 0.0, -5.0);
		glVertex3f(-1.5, -1.0, -5.0);
		glVertex3f(0.0, -1.5, -5.0);
		glVertex3f(1.0, -0.5, -5.0);
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(0.0, 0.7, -5.0);
		glVertex3f(-1.0, 0.0, -5.0);
	}
	glEnd();
	glEndList();

	//Quad
	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS); {
		glVertex3f(-1.0, 1.4, -5.0);
		glVertex3f(-0.5, 0.7, -5.0);
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, 1.7, -5.0);
	}
	glEnd();
	glEndList();

	//Quad Strip
	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP); {
		glVertex3f(1.0, 1.5, -5.0);
		glVertex3f(0.5, 1.5, -5.0);
		glVertex3f(1.5, 1.0, -5.0);
		glVertex3f(0.5, 1.0, -5.0);
		glVertex3f(0.5, -1.0, -5.0);
		glVertex3f(1.0, -1.3, -5.0);
	}
	glEnd();
	glEndList();

	//Polygon
	glNewList(index +9, GL_COMPILE);
	glBegin(GL_POLYGON); {
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, 1.0, -5.0);
		glVertex3f(-1.5, -2.0, -5.0);
		glVertex3f(1.5, -2.0, -5.0);
		glVertex3f(2.0, 1.0, -5.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	if (rotating == true)
	{
		glRotatef(m_rotationAngle, 0.0f, 0.0f, 0.5f);
	}
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(128.0f, 0.0f, 128.0f);


	glCallList(m_shape);
	window.display();
	//cout << "Draw up" << endl;
}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

