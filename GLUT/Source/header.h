#ifndef __header_h__
#define __header_h__

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#elif _WIN64
#include <gl\GL.h>
#endif 

#include <cstdio>
#include <chrono>
#include <time.h>
#include <string>
#include <thread>
#include <tuple>
#include <random>
#include <math.h>
#include <vector>

#endif