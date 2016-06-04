R"(
	#version 410

	uniform vec4 camera;
	uniform vec4 projection;

	in vec3 vert;

	void main()
	{
		gl_Position = camera * vec4(vert, 1);
	}
)";