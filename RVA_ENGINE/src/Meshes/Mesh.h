#pragma once

#include "data/Vertex.h"

#include <vector>

namespace rva
{
	class Mesh
	{
	private:
		unsigned int m_numVertices;
		float* m_verticiesPtr;

	public:
		Mesh(Mesh&) = delete;
		Mesh(Mesh&&) = delete;
		Mesh& operator=(Mesh&) = delete;

		//Mesh(std::vector<Vertex> verticies);
		Mesh(float* verticies, unsigned int num);

		float* getPtr() { return m_verticiesPtr; }
	};
}