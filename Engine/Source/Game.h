#pragma once
#include "header.h"
#include "DrawTool.h"
#include "Shader.h"
#include "Camera.h"
#include "Input.h"

using namespace std::chrono;

class Game
{
public:
	Game();
	GLuint Program;
private:
	void Draw();
	
	DrawTool* drawTool;
	Camera* cam;
	Input* input;
};
