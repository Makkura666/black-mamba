/**
 * Clock.h
 * Contributors:
 *	* Jens Ackou
 * Description:
 *	Dedicated to keep track of seperate slices of time
 */

#ifndef CLOCK
#define CLOCK

class Clock
{
public:

  Clock();
  float getDeltaTime();
  float getFrameTime();
  float getGameTime();
  int   getFPS();
  int   getTotalFrames();
  void  frameStarted();
  void  frameEnded();

private:

  float startTime;
  float endTime;
  float deltaTime;
  float frameTime;
  float gameTime;
  int   fps;
  int   totalFrames;
};

#endif /* ifndef CLOCK */
