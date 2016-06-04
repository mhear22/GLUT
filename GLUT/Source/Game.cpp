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

	GLFWwindow* w;
	if (FULLSCREEN)
	{
		GLFWmonitor* x = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(x);
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		
		w = glfwCreateWindow(mode->width, mode->height, "", monitors[0], NULL);
	}
	else
	{
		int width = 640;
		int height = 480;
		w = glfwCreateWindow(width, height, "", NULL, NULL);
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
	
	//glm::mat4 camera = glm::lookAt(glm::vec3(3,3,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
	//shaders[0].SetUniform("camera", camera);
	
	glLinkProgram(Program);
	
	
	drawTool = new DrawTool(Program);
	
	drawTool->LoadDebugWall2D();
	
	glfwSetKeyCallback(w, Game::Keyboard::KeyPress);
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetMouseButtonCallback(w, Game::Mouse::Clicked);
	glfwSetCursorPosCallback(w, Game::Mouse::Moved);
	
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
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawTool->DebugWall2D();
}

void Game::Mouse::Clicked(GLFWwindow* window,int button, int action, int mods)
{
	printf("clicked");
}

void Game::Mouse::Moved(GLFWwindow* window, double x, double y)
{
	if(x == 0 && y == 0)
	{
		return;
	}
	printf("moved %f, %f\n", x,y);
	glfwSetCursorPos(window, 0,0);
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