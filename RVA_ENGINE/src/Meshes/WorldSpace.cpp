#include "WorldSpace.h"


namespace rva
{

	WorldSpace::WorldSpace()
	{
		m_cubes.reserve(12);
	}

	void WorldSpace::addCube()
	{
		m_cubes.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f), 1);
	}
	
	void WorldSpace::addCube(glm::vec3 position)
	{
		m_cubes.emplace_back(position, 1);
	}

	void WorldSpace::addCube(glm::vec3 position, int scale)
	{
		m_cubes.emplace_back(position, scale);
	}

	//Mesh

	//Links and relations...


}
