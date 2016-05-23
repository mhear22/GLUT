#ifndef __header_h__
#define __header_h__

#define GLEW_STATIC

#pragma comment(lib, "glew.lib")

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#elif _WIN64
#include <GL\glew.h>
#endif 

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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
#include <fstream>
#include <sstream>

#endif