#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace rva
{
	//Idea: Mesh type registered every time used so that renderer can iterate
	//over all mesh types.


	template<typename T>
	class MeshManger
	{
	private:
		static bool s_registeredMeshType;

		//Could use hash table
		std::vector<std::shared_ptr<T>> m_instances;

	public:
		MeshManager();

		friend void registerComponent(MeshManager<T> mm, T c);


	};
}