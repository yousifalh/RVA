#pragma once

#include "user/Settings.h"
#include "user/Camera.h"

#include <memory>

struct GLFWwindow;

namespace rva
{
	class Window
	{
	private:
		static Window* s_instance;
		
		GLFWwindow* m_glfwWindow;
		unsigned int m_height;
		unsigned int m_width;

	public:
		std::unique_ptr<Camera> camera;	

	public:
		static void initContext();
		static void terminateContext();

		Window(Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&) = delete;

		Window();
		~Window();

		static unsigned int getWindowHeight();
		static unsigned int getWindowWidth();

		bool windowShouldClose();
		void setWindowShouldClose(bool set);

		void swapBuffers();
		void processPollEvents();
		void processInput();

		unsigned int getHeight();
		unsigned int getWidth();
	};
}