/**
* GameLoopTest.h
* Contributors:
*	* Jens Ackou
* Description:
*	
*/

#ifndef GAMELOOPTEST 
#define GAMELOOPTEST

#include "../system/Application.h"

class GameLoopTest : public Application
{
	public:
		GameLoopTest();
		char const *message = "Wiggle your big toe !";
		virtual void loop();

};

#endif