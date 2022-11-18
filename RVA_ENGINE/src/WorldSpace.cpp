#include "WorldSpace.h"


namespace rva
{
	//File should be become substantially large I suspect...


	WorldSpace::WorldSpace()
	{
		m_memoryPool = new float[vertexLimit];
	}

	void WorldSpace::addCube(Cube* cube)
	{
		m_cachedCubes.emplace_back(&cube, false);
	}

	void WorldSpace::formatData()
	{
		//YUCKY!
		//Temporary!! :(  | (-> queue data struct)
		//To excogitate special data structures!
		

		//----------------------TEST ALGORITHM ON SMALLER SCALE BEFORE ENGINE PROGRESS TEST!!!!!!

		int ptr{0};
		for (int x{0}; x < vertexLimit; x++)
		{
			if (m_cachedCubes[x].active)
			{
				for (int y{ 0 }; y < 6; y++)
				{
					*(m_memoryPool + ptr) = *(m_cachedCubes[x].cube.getVertexPtr()+y);
					ptr++;
				}
			}
		}
	}

	float* WorldSpace::getMemoryPtr()
	{
		return m_memoryPool;
	}


}