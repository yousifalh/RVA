#pragma once

#include <memory>

struct GLFWwindow;

namespace rva
{
	class Window
	{
	private:
		static bool s_instance;
		
		GLFWwindow* m_glfwWindow;

	public:
		static void initContext();
		static void terminateContext();

		Window(Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&) = delete;

		Window();

		bool windowShouldClose();
		void setWindowShouldClose(bool set);

		void swapBuffers();
		void processPollEvents();
	};
}