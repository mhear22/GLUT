#ifndef __header_h__
#define __header_h__

#define GLEW_STATIC

#pragma comment(lib, "glew.lib")

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>

#include <cstdio>
#include <chrono>
#include <time.h>
#include <string>
#include <thread>
#include <tuple>
#include <random>
#include <math.h>
#include <vector>
#include <iostream>
//#include <fstream>
#include <sstream>

#endif