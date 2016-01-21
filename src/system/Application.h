/**
* Application.h
* Contributors:
*	* Jens Ackou
* Description:
*	Contains everything your need for creating a window through GLFW.
*/

#ifndef APPLICATION
#define APPLICATION

class Application
{
	public:
		Application();

		// Start the application
		void run();

		// Call the first child loop method
		virtual void loop();
};

#endif