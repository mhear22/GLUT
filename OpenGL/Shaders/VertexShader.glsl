#version 150

uniform mat4 camera;
//uniform mat4 model;

in vec3 vert;

void main()
{
	gl_Position = camera * vec4(vert, 1);
}