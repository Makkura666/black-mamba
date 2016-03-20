/**
 * Application.cpp
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Contains everything your need for creating a window through GLFW.
 */

 #include "Application.h"

 #include <GL/glew.h>
 #include <GLFW/glfw3.h>
 #include <string>
 #include <iostream>
 #include <stdexcept>
 #include "../debug/Debug.h"
 #include "Clock.h"

Application *currentApplication = NULL;

Application& Application::getInstance()
{
  if (currentApplication) return *currentApplication;
  else throw std::runtime_error("There is no current Application");
}

Application::Application() :
  state(stateReady),
  width(640),
  height(480),
  title("Black Mamba Gaming Engine")
{
  currentApplication = this;

  // initialize GLFW
  if (!glfwInit())
  {
    std::runtime_error("[APPLICATION]: Couldn't init GLFW");
  } else std::cout << "[APPLICATION]: Initialized GLFW\n";

  // setting the opengl version
  int major = 3;
  int minor = 2;
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE,        GLFW_OPENGL_CORE_PROFILE);

  // create window and context
  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    throw std::runtime_error("Couldn't create a window");
  } else std::cout << "[APPLICATION]: Created Window\n";

  // make OpenGL context current
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  GLenum err = glewInit();

  if (err != GLEW_OK)
  {
    glfwTerminate();
    throw std::runtime_error(std::string("Could initialize GLEW, error = ") +
                             (const char *)glewGetErrorString(err));
  }

  // get version info
  const GLubyte *renderer = glGetString(GL_RENDERER);
  const GLubyte *version  = glGetString(GL_VERSION);
  std::cout << "Renderer: " << renderer << std::endl;
  std::cout << "OpenGL version supported " << version << std::endl;

  // opengl configuration
  glEnable(GL_DEPTH_TEST); // enable depth-testing
  glDepthFunc(GL_LESS);    // depth-testing interprets a smaller value as
                           // "closer"

  // vsync
  // glfwSwapInterval(false);
}

GLFWwindow * Application::getWindow() const
{
  return window;
}

void Application::exit() {
  state = stateExit;
}

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
  state = stateRun;

  // Clock newClock;

  glfwMakeContextCurrent(window);

  glfwSetErrorCallback(error_callback);

  // check keyevents for window
  glfwSetKeyCallback(window, key_callback);

  // when user attempts to close window, close flag is set to 1
  // also: glfwWindowCloseCallback & glfwSetWindowShouldClose
  while (!glfwWindowShouldClose(window))
  {
    /*
    TODO implement http://gafferongames.com/game-physics/fix-your-timestep/
    */
    // newClock.frameStarted();

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

    // newClock.frameEnded();
  }

  // destroy window
  glfwDestroyWindow(window);

  // destroys windows, other resources allocated by GLFW
  glfwTerminate();
}

void Application::update()
{
  std::cout << "[APPLICATION]: update" << std::endl;
}

void Application::render()
{
  std::cout << "[APPLICATION]: render" << std::endl;
}
