#pragma once

#include <glad/glad.h>

namespace rva
{
	void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}