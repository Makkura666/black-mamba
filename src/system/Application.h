/**
 * Application.h
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Contains everything your need for creating a window through GLFW.
 */

#ifndef APPLICATION
#define APPLICATION

#include <string>

class GLFWwindow;

class Application
{
public:

  Application();

  static Application& getInstance();

  // Get the window id
  GLFWwindow        * getWindow() const;

  // Window control
  void                exit();

  // Application run
  void                run();

private:

  enum State {
    stateReady,
    stateRun,
    stateExit
  };

  State state;

  Application& operator = (const Application&) {return *this; }

  GLFWwindow *window;
  int width;
  int height;

protected:

  Application(const Application &) {};

  std::string title;

  // call the first child loop method
  virtual void update();
  virtual void render();
};

#endif /* ifndef APPLICATION */
