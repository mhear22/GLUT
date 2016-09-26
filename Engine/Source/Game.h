#pragma once
#include "header.h"
#include "DrawTool.h"
#include "Shader.h"
#include "Camera.h"
#include "Input.h"
#include "ModelBase.h"
#include "ModelContainer.h"

using namespace std::chrono;

class Game
{
public:
	Game();
	void Run();
	GLuint Program;
private:
	void Draw();
	
	GLFWwindow* currentWindow;
	DrawTool* drawTool;
	Camera* cam;
	Input* input;
	ModelContainer* container;
};
