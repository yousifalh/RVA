#pragma once

#include "Cube.h"
#include "Mesh.h"

#include <vector>
#include <memory>


namespace rva
{
	class WorldSpace
	{
	private:
		std::vector<Cube> m_cubes;
		// std::vector<Skeleton> m_skeletons;

		//Can expand to EntitiesContainer
		class VertexContainer
		{
		private:
			float* m_ptr;
			unsigned int m_size;

		public:
			VertexContainer() = delete;
			VertexContainer(float* ptr, unsigned int size)
				: m_ptr(ptr), m_size(size) {}

			float* getPtr() { return m_ptr; }
			unsigned int getSize() { return m_size; }
		};

	public:
		WorldSpace();

		void addCube();
		void addCube(glm::vec3 position);
		void addCube(glm::vec3 position, int scale);

	};
}