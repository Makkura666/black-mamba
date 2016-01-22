/**
* Debug.cpp
* Contributors:
*	* Jens Ackou
* Description:
*	Print ASCII logo and variable data.
*/

#ifndef DEBUG
#define DEBUG

#include <iostream>

class Debug
{
	public:
		Debug();
		// Print debug information
		void printDebug();

	private:
		int counter = 0;
		// Spam newlines to clear the screen
		void clearScreen(){ for (int i=0;i<1000;i++){ std::cout<<"\n"; } }

};

#endif
