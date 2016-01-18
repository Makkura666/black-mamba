#include "Debug.h"
#include <iostream>
#include <GLFW/glfw3.h>

Debug::Debug()
{

}

void Debug::printDebug()
{
	if((int)glfwGetTime() == counter)
	{	
		clearScreen();
		std::cout << R"###(
	 _ ) | __ _  _   | | _  | \   | __ _ _  _  | |   __ _
	 _ \ |/ _` |/ _/ | |/ / | |\/ |/ _` |  ` \ | _ \/ _` |
	___/_|\__,_|\__\ |_|\_\ |_|  _|\__,_|_|_|_||.__/\__,_|
		)###";

		printf("\n\tCompiled against GLFW %i.%i.%i\n",
       	GLFW_VERSION_MAJOR,
       	GLFW_VERSION_MINOR,
       	GLFW_VERSION_REVISION);

		printf("\n\t########### Gaming Engine ###########\n");
		printf("\t| %-18s | %-12.2f |\n", "Raw time", glfwGetTime());
		printf("\t| %-18s | %-12.2d |\n", "Seconds", (int)glfwGetTime());
		printf("\t| %-18s | %-12.2d |\n", "Counter", counter);
		printf("\t| %-18s | %-12.2s |\n", "GLFW version", glfwGetVersionString());
	    
	    counter++;
	}

}