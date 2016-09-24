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

	class Mouse
	{
	public:
		Mouse(Camera*);
		void static Clicked(GLFWwindow* window,int button, int action, int mods);
		void static Moved(GLFWwindow* window, double x, double y);
		void draw();
		double static mouseX;
		double static mouseY;
	private:

		Camera* camera;
	};

	class Keyboard
	{
	public:
		void static KeyPress(GLFWwindow*,int,int,int,int);
	private:
		unsigned char static keys[256];
	};

private:
	Mouse* mouse;
};
