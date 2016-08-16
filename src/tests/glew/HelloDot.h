/**
 * HelloDot.h
 * Contributors:
 *  * Jens Ackou
 * Description:
 *  Usage of Vertex Buffer Objects (VBO), used to store vertices.
 *  Most efficient way of loading vertices into the GPU.
 *  Can be stored in video memory = shortest access time to the GPU.
 *  Fixed function pipeline will be used.
 */

#ifndef HELLODOT
#define HELLODOT

#include "../../system/Application.h"
#include "../../system/Math3d.h"

class HelloDot : public Application
{
public:

  HelloDot();
  void drawDot(float x,
               float y,
               float z);
};

#endif /* ifndef HELLODOT */
