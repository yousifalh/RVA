#version 450

layout (location = 0) in vec3 inPos;
layout (location = 1) in vec3 inCol;

out vec3 aCol;

uniform mat4 model = mat4(1.0f);
uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model * vec4(inPos, 1.0f);
	aCol = inCol;

}