#pragma once

#include "VertexBuffer.h"
#include "Elements.h"

#include <vector>


//#include <map>
/*
	will look into using unordered_map/map
*/

class Cube;
class Shader;

namespace rva
{
	class BufferManager
	{
	private:
		bool s_instance;
		
		//remove this nonesense later
		std::vector<VertexBuffer> m_vBuffers;

		std::shared_ptr<Shader> m_usingShader;

	public:
		BufferManager();

		void bindShader(std::shared_ptr<Shader>& shader);

		template<typename T>
		void newBuffer();

		//bind active buffers...
		void bindBuffers();

		inline void drawBuffers(std::shared_ptr<WorldSpace>& worldSpace);

		//function to activate certain buffer...

	};


}