#version 150

in vec3 vect;

void main()
{
	gl_position = vec4(vert, 1);
}