/**
* Application.h
* Contributors:
*	* Jens Ackou
* Description:
*	Contains everything your need for creating a window through GLFW.
*/

#include "Application.h"
#include <iostream>
#include "../debug/Debug.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

// Debugger class
Debug debug;

// GLFW function fails
void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

// Set window to receive key press and release events
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

Application::Application()
{
	
}

void Application::run()
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	// Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	// Create window and context
	window = glfwCreateWindow(640, 480, "Black Mamba", NULL, NULL);

	// If context creation fails
	if(!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Make OpenGL context current
	glfwMakeContextCurrent(window);

	// How many frames to wait before swapping buffer (vsync)
	glfwSwapInterval(1);

	// Check keyevents for window
	glfwSetKeyCallback(window, key_callback);

	// When user attempts to close window, close flag is set to 1
	// also: glfwWindowCloseCallback & glfwSetWindowShouldClose
	while (!glfwWindowShouldClose(window)) 
	{
		// Get framebuffer size
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);

		// Execute the frame code
		loop();

		// Swap buffer after every rendered frame
		glfwSwapBuffers(window);

		// Process pending events
		// also: glfwWaitEvents for update on event (editing tools)
		glfwPollEvents();

        // Custum debugging module
        //debug.printDebug();
	}

	// Destroy window
	glfwDestroyWindow(window);

	// Destroys windows, other resources allocated by GLFW
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
}

void Application::loop()
{
    std::cout << "[INFO] : loop" << std::endl;
}
