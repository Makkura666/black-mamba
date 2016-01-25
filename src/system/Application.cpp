/**
 * Application.cpp
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Contains everything your need for creating a window through GLFW.
 */

#include "Application.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include "../debug/Debug.h"
#include "Clock.h"

Application::Application()
{}

// GLFW function fails
void error_callback(int error, const char *description)
{
  fputs(description, stderr);
}

// Set window to receive key press and release events
static void key_callback(GLFWwindow *window,
                         int         key,
                         int         scancode,
                         int         action,
                         int         mods)
{
  if ((key == GLFW_KEY_ESCAPE) &&
      (action == GLFW_PRESS)) glfwSetWindowShouldClose(window, GL_TRUE);
}

void Application::run()
{
  Debug debug;
  Clock newClock;
  GLFWwindow *window;

  glfwSetErrorCallback(error_callback);

  // initialize GLFW
  if (!glfwInit())
  {
    exit(EXIT_FAILURE);
  }

  // create window and context
  window = glfwCreateWindow(640, 480, "Black Mamba", NULL, NULL);

  // if context creation fails
  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // make OpenGL context current
  glfwMakeContextCurrent(window);

  // how many frames to wait before swapping buffer (vsync)
  glfwSwapInterval(1);

  // check keyevents for window
  glfwSetKeyCallback(window, key_callback);

  // when user attempts to close window, close flag is set to 1
  // also: glfwWindowCloseCallback & glfwSetWindowShouldClose
  while (!glfwWindowShouldClose(window))
  {
    newClock.frameStarted();

    // get framebuffer size
    float ratio;
    int   width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);

    // LOOP GAME CODE
    {
      update();
    }

    // LOOP GAME CODE
    render();

    glfwSwapBuffers(window);

    // process pending events
    // also: glfwWaitEvents for update on event (editing tools)
    glfwPollEvents();

    // custum debugging module
    // disable when not used
    // debug.printDebug();

    newClock.frameEnded();
  }

  // destroy window
  glfwDestroyWindow(window);

  // destroys windows, other resources allocated by GLFW
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

void Application::update()
{
  std::cout << "[APPLICATION]: update" << std::endl;
}

void Application::render()
{
  std::cout << "[APPLICATION]: render" << std::endl;
}
