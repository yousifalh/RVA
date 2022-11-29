#include "Cube.h"

#include "data/NormalisedCubeData.h"

namespace rva
{
	//This way all cubes will have the same copy of verticies
	//Optimisation is to store as pointer...
	Cube::Cube(unsigned int scale)
		: m_scale{scale}, Mesh(staticCubeVertices, num)
	{
	}
}