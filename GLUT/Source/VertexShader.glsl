R"(
	#version 410

	//uniform vec4 camera;
	
	in vec3 vert;
	
	void main()
	{
		gl_Position = vec4(vert, 1);
	}
)";