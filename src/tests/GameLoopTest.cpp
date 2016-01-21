/**
* GameLoopTest.cpp
* Contributors:
*	* Jens Ackou
* Description:
*	
*/

#include "GameLoopTest.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GameLoopTest::GameLoopTest()
{
	// constructor test
	std::cout << "[INFO]: Initiating engine\n";
}

void GameLoopTest::loop()
{
	// ACTUAL GAME CODE
		{
			float ratio = 1;
			glClear(GL_COLOR_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
			glMatrixMode(GL_MODELVIEW);

			glLoadIdentity();

			// Reading timer - getting smooth animation
			glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.F, 1.F);

			glBegin(GL_TRIANGLES);
		        glColor3f(1.f, 0.f, 0.f);
		        glVertex3f(-0.6f, -0.4f, 0.f);
		        glColor3f(0.f, 1.f, 0.f);
		        glVertex3f(0.6f, -0.4f, 0.f);
		        glColor3f(0.f, 0.f, 1.f);
		        glVertex3f(0.f, 0.6f, 0.f);
	        glEnd();
		}
}