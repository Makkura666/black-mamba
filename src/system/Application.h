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
		void run();

	private:
		// call the first child loop method
		virtual void loop();

};

#endif
