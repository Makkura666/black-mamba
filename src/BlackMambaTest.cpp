/**
* BlackMambaTest.h
* Contributors:
*	* Jens Ackou
* Description:
*	Game engine application test. This file is usually created by
*	a 3rd party user and does not need to know the gritty details
*	that happen behind the scenes. ( which will be simply magic
*	when I finally find out how to this at a pristine level ! )
*/

#include "BlackMambaTest.h"
#include <iostream>

BlackMambaTest::BlackMambaTest()
{
	printMessage();
}

void BlackMambaTest::printMessage()
{
	std::cout << "\n" << std::endl;
	printf("TEST");
	printf("%-18s%-12s\n", "[BlackMambaTest]: ", message);
}