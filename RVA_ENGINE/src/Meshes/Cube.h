#pragma once

#include "Mesh.h"

namespace rva
{
	class Cube : public Mesh
	{
	private:
		unsigned int m_scale;

	public:
		Cube(Cube&) = delete;
		Cube(Cube&&) = delete;
		Cube& operator=(Cube&) = delete;
		Cube& operator=(Mesh&) = delete;
		Cube() = delete;

		Cube(unsigned int scale);


	};
}