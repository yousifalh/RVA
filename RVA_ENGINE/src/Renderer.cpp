#include "Renderer.h"

#include "Buffers/Elements.h"

#include <iostream>

namespace rva
{
	Renderer::Renderer()
	{
		if (s_instance)
		{
			std::cout << "Attempted to create a Renderer instance"
				" when one already exists!" << std::endl;
			Renderer::~Renderer();
		}
		else
		{
			s_instance = true;
		}
	}

	void Renderer::bindWSContext(std::shared_ptr<WorldSpace>& worldSpace)
	{
		m_worldSpaceContext = worldSpace;
	}

	void Renderer::uploadWSState()
	{
		//Cubes
		m_bufferManager->newBuffer<Cube>();

	}

	void Renderer::renderFrame()
	{
		//Maybe scrap the bufferManager... -- just scrap it.

		m_bufferManager->bindBuffers();

		m_bufferManager->drawBuffers(m_worldSpaceContext);
	}

}