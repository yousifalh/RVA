#include "Window.h"
#include "Renderer.h"
#include "data/WindowData.h"

#include <iostream>


int main()
{
	rva::Window::initContext();

	rva::Window window{ rva::windowData };

	//window.setup();

	rva::Renderer renderer{};

	//Basically the structure of the objects (a world space?)
	/*rva::WorldSpace worldSpace{};

	renderer.bind(&worldSpace);*/



}