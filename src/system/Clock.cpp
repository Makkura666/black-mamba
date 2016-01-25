/**
 * Clock.cpp
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Dedicated to keep track of seperate slices of time
 */

#include "Clock.h"
#include <iostream>
#include <GLFW/glfw3.h>

Clock::Clock()
{
  startTime   = 0.0f;
  endTime     = 0.0f;
  deltaTime   = 0.0f;
  frameTime   = 0.0f;
  gameTime    = 0.0f;
  fps         = 0;
  totalFrames = 0;
}

float Clock::getDeltaTime()
{
  return deltaTime;
}

float Clock::getFrameTime()
{
  return endTime - startTime;
}

float Clock::getGameTime()
{
  return glfwGetTime();
}

int Clock::getFPS()
{
  return totalFrames;
}

int Clock::getTotalFrames()
{
  return totalFrames;
}

void Clock::frameStarted()
{
  startTime = glfwGetTime();
}

void Clock::frameEnded()
{
  endTime   = glfwGetTime();
  deltaTime = endTime - startTime;
  totalFrames++;
}
