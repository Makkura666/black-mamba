/**
 * GameLoopTest.cpp
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Testing of a general game loop.
 *	Can be used to test and tweak the game loop performance.
 */

#include "GameLoopTest.h"
#include <iostream>
#include <GLFW/glfw3.h>

GameLoopTest::GameLoopTest()
{
  std::cout << "[GAMELOOPTEST]: Init GameLoopTest\n";
}

void GameLoopTest::update()
{
  std::cout << "[APPLICATION]: update" << std::endl;
}

void GameLoopTest::render()
{
  std::cout << "[APPLICATION]: render" << std::endl;

  // game logic here
  float ratio = 1;

  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  // reading timer - getting smooth animation
  glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.F, 1.F);

  glBegin(GL_TRIANGLES);
  glColor3f(1.f, 0.f, 0.f);
  glVertex3f(-0.6f, -0.4f, 0.f);
  glColor3f(0.f, 1.f, 0.f);
  glVertex3f(0.6f, -0.4f, 0.f);
  glColor3f(0.f, 0.f, 1.f);
  glVertex3f(0.f, 0.6f, 0.f);
  glEnd();
}
