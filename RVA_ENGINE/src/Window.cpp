#include "Macro.h"
#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "user/Controls.h"

namespace rva
{
	bool Window::s_instance;
	

	void Window::initContext()
	{
		RVA_LOG("Initialising window context!");

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void Window::terminateContext()
	{
		glfwTerminate();
	}

	Window::Window()
	{
		if (s_instance)
		{
			//Destroy window?
			RVA_ASSERT(0, "There already exists a window instance! Window is a singleton!")
		}
		else
		{
			std::cout << "Creating window?" << std::endl;
			s_instance = true;
			m_glfwWindow = glfwCreateWindow(1200, 800, "RVA-ENGINE", NULL, NULL);

			if (m_glfwWindow == NULL)
			{
				std::cout << "Failed to create window!" << std::endl;
			}
		}

		glfwMakeContextCurrent(m_glfwWindow);
		glfwSetFramebufferSizeCallback(m_glfwWindow, frameBufferSizeCallback);

		RVA_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to load glad!")

	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(m_glfwWindow);
	}

	bool Window::windowShouldClose()
	{
		return glfwWindowShouldClose(m_glfwWindow);
	}

	void Window::setWindowShouldClose(bool set)
	{
		glfwSetWindowShouldClose(m_glfwWindow, set);
	}

	void Window::processPollEvents()
	{
		glfwPollEvents();
		//Process poll
	}

}