/**
 * HelloDot.cpp
 * Contributors:
 *  * Jens Ackou
 * Description:
 *  Usage of Vertex Buffer Objects (VBO), used to store vertices.
 *  Most efficient way of loading vertices into the GPU.
 *  Can be stored in video memory = shortest access time to the GPU.
 *  Fixed function pipeline will be used.
 */

#include "HelloDot.h"
#include <iostream>

// Includes helper structures such as vector
#include "../../system/Math3d.h"

// Globally allocated to handle VBO, OGL objects
// are almost all accessed via GLuint
GLuint VBO;

HelloDot::HelloDot()
{
  std::cout << "[HelloDot]: Init HelloDot\n";

  drawDot(1, 1, 1);
}

void HelloDot::drawDot(float x, float y, float z)
{
  Vector3f Vertices[1];

  Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

  // (number of objects to be created, address of array of GLunits
  // to store handles that the driver allocates for you)
  // Future calls will not gen the same object handles
  // unless you glDeleteBuffers first
  // You still have a 'generic buffer'
  glGenBuffers(1, &VBO);

  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}
