/**
* Main.cpp
* Contributors:
*	* Jens Ackou
* Description:
*	Main entry point. You can use this file to select which application
*	you want to run by swapping the include and instance variable.
*/

#include "tests/GameLoopTest.h"

int main(int argc, const char *argv[])
{
	GameLoopTest app;
    app.run();
	return 0;
}