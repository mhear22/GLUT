R"(
	#version 150
	
	in vec3 vect;
	
	void main()
	{
		gl_Position = vec4(vect, 1);
	}
)";