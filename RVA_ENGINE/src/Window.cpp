#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


namespace rva
{

	void Window::initContext()
	{
		if (s_instance)
		{
			std::cout << "Already initialised window context!" << std::endl;
			//assert...
		}

		glfwInit();
		glfwWindowHint(GLFW_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_API, GLFW_OPENGL_CORE_PROFILE);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to load glad!" << std::endl;
			//assert...
		}

		s_instance = true;
	}


	Window::Window(WindowData wd)
	{
		m_window = glfwCreateWindow(wd.width, wd.height, wd.name, nullptr, nullptr);

		glfwMakeContextCurrent(m_window);
		// Multiple window stuff would need a window manager thta accesses func above...



	}

}