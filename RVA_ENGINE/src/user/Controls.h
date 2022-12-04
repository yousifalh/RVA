#pragma once

#include "Camera.h"
#include "Settings.h"

#include <glad/glad.h>

#define WINDOW_LENGTH 1200
#define WINDOW_HEIGHT 800

namespace rva
{
	float lastX = WINDOW_LENGTH / 2.0f;
	float lastY = WINDOW_HEIGHT / 2.0f;
	bool firstMouse = true;

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
	{
		float xpos = static_cast<float>(xposIn);
		float ypos = static_cast<float>(yposIn);

		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		float xoffset = xpos - lastX;
		float yoffset = ypos - lastY;

		lastX = xpos;
		lastY = ypos;

		Camera::getActiveCamera()->processMouseMovement(xoffset, yoffset, true);
	}

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Camera::getActiveCamera()->processMouseMovement(xoffset, yoffset, true);
	}
}