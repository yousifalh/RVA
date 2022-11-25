#include "Window.h"
#include "Renderer.h"
#include "data/WindowData.h"
#include "Meshes/WorldSpace.h"
#include "Meshes/Cube.h"

#include <iostream>
#include <memory>

int main()
{
	rva::Window::initContext();
	rva::Window window{ rva::windowData };

	std::shared_ptr<rva::WorldSpace> ws = std::make_shared<rva::WorldSpace>();

	rva::Renderer renderer{};
	renderer.bindWSContext(ws);

    
	ws->addCube();

	while (!window.shouldClose())
	{
        renderer.uploadWSState();

		renderer.renderFrame();

	}

	


}