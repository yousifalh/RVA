#pragma once

#include "data/WindowData.h"

class GLFWwindow;

namespace rva
{

	class Window
	{
	private:
		static bool s_instance;

		GLFWwindow* m_window;


	public:
		static void initContext();

		Window() = delete;
		Window& operator=(Window&) = delete;
		Window(WindowData data);



	};

}