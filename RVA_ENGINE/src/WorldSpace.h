#pragma once

#include "Meshes/Cube.h"

#include <vector>

// 256 bytes using float; should extend for models later...
unsigned int vertexLimit{ 64 };


namespace rva
{
	//Temporary (need to study std::pair...)
	// YUCKY
	static struct CubeStatus
	{
		CubeStatus(const Cube& cubeIn, bool ac) : cube(cubeIn), active(ac) {}
		Cube cube;
		bool active;
	};

	class WorldSpace
	{
	private:
		//std::vector<Model> m_models;
		std::vector<CubeStatus> m_cachedCubes;

		float* m_memoryPool;

	public:
		WorldSpace();

		void addCube(Cube* cube);

		//Add algorithm for memory assignment - requires some
		//theory and external practice to consolidate a wise solution...
		void formatData();

		float* getMemoryPtr();

	};
}
