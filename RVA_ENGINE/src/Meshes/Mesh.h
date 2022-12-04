#pragma once

#include "data/Vertex.h"

#include <vector>

namespace rva
{
	class Mesh
	{
	private:
		unsigned int m_numVertices;
		Vertex* m_verticiesPtr;

	public:
		Mesh(Mesh&) = delete;
		Mesh(Mesh&&) = delete;
		Mesh& operator=(Mesh&) = delete;

		//Mesh(std::vector<Vertex> verticies);
		Mesh(Vertex* verticies, unsigned int num);

		//Following function using friend function with buffer objs?
		Vertex* getPtr() { return m_verticiesPtr; }
	};
}