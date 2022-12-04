#include "Macro.h"
#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "user/Controls.h"
#include "user/Settings.h"



namespace rva
{
	Window* Window::s_instance{nullptr};
	
	WindowProperties defaultWindowProp{ 1200, 800, "RVA-ENGINE" };


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

	unsigned int Window::getWindowHeight()
	{
		RVA_ASSERT(s_instance, "Window does not exist! Trying to access nullptr!");
		return s_instance->getHeight();
	}

	unsigned int Window::getWindowWidth()
	{
		RVA_ASSERT(s_instance, "Window does not exist! Trying to access nullptr!");
		return s_instance->getWidth();
	}


	Window::Window()
		: m_height(defaultWindowProp.height), m_width(defaultWindowProp.width)
	{
		if (s_instance)
		{
			//Destroy window?
			RVA_ASSERT(0, "There already exists a window instance! Window is a singleton!")
		}
		else
		{
			std::cout << "Creating window?" << std::endl;
			s_instance = this;
			m_glfwWindow = glfwCreateWindow(
				defaultWindowProp.width,
				defaultWindowProp.height,
				defaultWindowProp.name,
				NULL,
				NULL);

			RVA_ASSERT(m_glfwWindow, "Failed to create window!");
			
			camera = std::make_unique<Camera>();
		}

		glfwMakeContextCurrent(m_glfwWindow);
		glfwSetFramebufferSizeCallback(m_glfwWindow, framebuffer_size_callback);
		glfwSetCursorPosCallback(m_glfwWindow, mouse_callback);
		glfwSetScrollCallback(m_glfwWindow, scroll_callback);

		glfwSetInputMode(m_glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		

		RVA_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to load glad!")

	}

	Window::~Window()
	{
		s_instance = nullptr;
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
	}

	float previousTime{ 0.0f };
	
	void Window::processInput()
	{
		//Temporary -- trying to figure out event dispatcher...

		double currentTime{ glfwGetTime() };
		double deltaTime{ currentTime - previousTime };

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			setWindowShouldClose(true);

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_W) == GLFW_PRESS)
			camera->processKeyboard(Camera::CameraMovement::FORWARD, deltaTime);

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_S) == GLFW_PRESS)
			camera->processKeyboard(Camera::CameraMovement::BACKWARD, deltaTime);

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_A) == GLFW_PRESS)
			camera->processKeyboard(Camera::CameraMovement::LEFT, deltaTime);

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_D) == GLFW_PRESS)
			camera->processKeyboard(Camera::CameraMovement::RIGHT, deltaTime);

		if (glfwGetKey(m_glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			setWindowShouldClose(true);
		
		previousTime = currentTime;

	}

	unsigned int Window::getHeight()
	{
		return m_height;
	}

	unsigned int Window::getWidth()
	{
		return m_width;
	}
}


