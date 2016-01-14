#include <iostream>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

// Belongs to debug
// This is why the debugger needs to be a class
int counter = 1;

// Spam newlines to clear the screen
void clearScreen()
{
	for (int i=0;i<1000;i++){std::cout<<"\n";}
}

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

int main(int argc, const char *argv[])
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

		// ACTUAL GAME CODE
		{
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

		// Swap buffer after every rendered frame
		glfwSwapBuffers(window);

		// Process pending events
		// also: glfwWaitEvents for update on event (editing tools)
		glfwPollEvents();

        // Custum debugging module
        #include "debug.h"
	}

	// Destroy window
	glfwDestroyWindow(window);

	// Destroys windows, other resources allocated by GLFW
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
	return 0;
}
