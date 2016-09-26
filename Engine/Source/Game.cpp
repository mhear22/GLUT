#include "Game.h"

Game::Game()
{
	if(!glfwInit())
	{
		exit(0);
	}

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	bool FULLSCREEN = false;
	
	int screenHeight = 0;
	int screenWidth = 0;
	
	if (FULLSCREEN)
	{
		GLFWmonitor* x = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(x);
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		screenWidth = mode->width;
		screenHeight = mode->height;
		currentWindow = glfwCreateWindow(screenWidth, screenHeight, "", monitors[0], NULL);
	}
	else
	{
		screenWidth = 640;
		screenHeight = 480;
		currentWindow = glfwCreateWindow(screenWidth, screenHeight, "", NULL, NULL);
	}

	glfwMakeContextCurrent(currentWindow);
	
	auto ver = glGetString(GL_VERSION);
	printf("%s \n", ver);
	
#ifdef __APPLE__
#else
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		printf("%s \n", glewGetErrorString(err));
		exit(0);
	}
#endif

	std::vector<Shader> shaders;
	
	shaders.push_back(Shader(DefaultVertexShader , GL_VERTEX_SHADER));
	shaders.push_back(Shader(DefaultFragmentShader, GL_FRAGMENT_SHADER));
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);


	
	Program = glCreateProgram();
	for (int i = 0; i < shaders.size(); i++)
	{
		glAttachShader(Program, shaders[i].object());
	}
	glBindAttribLocation(Program, 1, "vert");
	
	
	float aspect = ((screenWidth + 0.0f) /(screenHeight + 0.0f));
	
	glLinkProgram(Program);
	
	glUseProgram(Program);
	
	cam = new Camera(Program, aspect);
	drawTool = new DrawTool(Program);
	input = new Input(cam);
	
	glUseProgram(0);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	glfwSetKeyCallback(currentWindow, Input::KeyPress);
	glfwSetInputMode(currentWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(currentWindow, 0, 0);
	glfwSetMouseButtonCallback(currentWindow, Input::Click);
	glfwSetCursorPosCallback(currentWindow, Input::Move);
	

	drawTool->LoadDebugWall3D();
}

void Game::Run()
{
	if(currentWindow == nullptr)
	{
		throw "Null Pointer Exception";
	}
	
	while (!glfwWindowShouldClose(currentWindow))
	{
		Game::Draw();
		glfwSwapBuffers(currentWindow);
		glfwPollEvents();
	}
	
	glfwTerminate();
}

void Game::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(Program);
	//mouse->draw();
	input->Draw();
	cam->draw();
	drawTool->draw();
}
