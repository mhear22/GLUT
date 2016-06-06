R"(
	#version 150

	uniform mat4 camera;
	uniform mat4 projection;

	in vec3 vert;

	void main()
	{
		if(camera == 0 || projection == 0)
		{
			gl_Position = vec4(vert, 1);
		}
		else
		{
			gl_Position = projection * camera * vec4(vert, 1);
		}
	}
)";