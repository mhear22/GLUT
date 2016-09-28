#pragma once
#ifndef __header_h__
#define __header_h__

#ifndef GLEW_STATIC
#define GLEW_STATIC
#else
#endif // !GLEW_STATIC



#ifdef __APPLE__ //Apple includes
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#else //Includes for Linux and Windows
#include <GL/glew.h>
#include <GL/gl.h>
#endif

//multiplat includes
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//c++11 includes
#include <cstdio>
#include <chrono>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>

#endif
