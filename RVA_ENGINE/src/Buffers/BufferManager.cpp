#include "BufferManager.h"
#include "../Meshes/WorldSpace.h"

#include <iostream>



namespace rva
{
	BufferManager::BufferManager()
	{
		if (!s_instance)
		{
			s_instance = true;
		}
		else
		{
			std::cout << "Already created BufferManager instance!" << std::endl;
		}
		s_instance = true;

	}

	void BufferManager::bindShader(std::shared_ptr<Shader>& shader)
	{
		m_usingShader = shader;
	}

	template<>
	void BufferManager::newBuffer<Cube>()
	{
		m_vBuffers.emplace_back(cubeElement, sizeof(cubeElement));
	}

	/*
	template<>
	void BufferManager::newBuffer<Mesh>()
	{

	}	
	*/

	void BufferManager::bindBuffers()
	{
		for (int x{ 0 }; x < m_vBuffers.capacity(); x++)
		{
			m_vBuffers[x].bind();
		}
	}

	void BufferManager::drawBuffers(std::shared_ptr<WorldSpace>& worldspace)
	{
		

	}


}