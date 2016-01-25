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

#ifndef BLACKMAMBATEST
#define BLACKMAMBATEST

#include "../system/Application.h"

class BlackMambaTest : public Application
{
public:

  BlackMambaTest();

private:

  void printMessage();
  char const *message;
};

#endif /* ifndef BLACKMAMBATEST */
