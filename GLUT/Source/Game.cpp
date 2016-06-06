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
	
	bool FULLSCREEN = true;
	
	int screenHeight = 0;
	int screenWidth = 0;
	
	GLFWwindow* w;
	if (FULLSCREEN)
	{
		GLFWmonitor* x = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(x);
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		screenWidth = mode->width;
		screenHeight = mode->height;
		w = glfwCreateWindow(screenWidth, screenHeight, "", monitors[0], NULL);
	}
	else
	{
		screenWidth = 640;
		screenHeight = 480;
		w = glfwCreateWindow(screenWidth, screenHeight, "", NULL, NULL);
	}

	glfwMakeContextCurrent(w);
	
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
	mouse = new Mouse(cam);

	glUseProgram(0);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	
	
	glfwSetKeyCallback(w, Game::Keyboard::KeyPress);
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetMouseButtonCallback(w, Game::Mouse::Clicked);
	glfwSetCursorPosCallback(w, Game::Mouse::Moved);
	

	drawTool->LoadDebugWall2D();
	while (!glfwWindowShouldClose(w))
	{
		Game::Draw();
		glfwSwapBuffers(w);
		glfwPollEvents();
	}

	glfwTerminate();
}

void Game::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(Program);
	mouse->draw();
	cam->draw();
	drawTool->draw();
}

Game::Mouse::Mouse(Camera* cam)
{
	camera = cam;
}

void Game::Mouse::Clicked(GLFWwindow* window,int button, int action, int mods)
{
	printf("clicked");
}

double Game::Mouse::mouseX = 0.0;
double Game::Mouse::mouseY = 0.0;

void Game::Mouse::Moved(GLFWwindow* window, double x, double y)
{
	if(x == 0 && y == 0)
	{
		return;
	}
	printf("moved %f, %f\n", x,y);
	mouseX = mouseX + x;
	mouseY = mouseY + y;
	glfwSetCursorPos(window, 0,0);
}

void Game::Mouse::draw()
{
	camera->moveCamera(mouseX, mouseY);
	mouseX = 0.0;
	mouseY = 0.0;
}


void Game::Keyboard::KeyPress(GLFWwindow* window, int key, int scancode, int actions, int mods)
{
	if(key == 256)
	{
		exit(0);
	}
	else if (key == 96)
	{
		printf("Break");
	}

}