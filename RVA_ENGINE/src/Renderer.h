#pragma once

#include "Buffers/BufferManager.h"
#include "Shader.h"
#include "Meshes/WorldSpace.h"


#include <memory>


namespace rva
{
	class Renderer
	{
	private:
		static bool s_instance;
		
		std::unique_ptr<BufferManager> m_bufferManager;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<WorldSpace> m_worldSpaceContext;

	public:
		Renderer();
		~Renderer();

		Renderer(Renderer&) = delete;

		void bindWSContext(std::shared_ptr<WorldSpace>& worldSpace);
		void uploadWSState();

		void renderFrame();

	};
}