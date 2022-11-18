#pragma once

#include "Buffers/BufferManager.h"
#include "Shader.h"

#include <memory>

namespace rva
{

	class Renderer
	{
	private:
		/*
		In current state of code, WorldSpace just does what m_bufferManager should store.
		WorldSpace is designed to have its own functions
		
		*/

		std::unique_ptr<BufferManager> m_bufferManager;
		std::unique_ptr<Shader> m_shader;
		//std::unique_ptr<Camera> m_camera;
		//OPTION 1: std::shared_ptr<WorldSpace> m_wsContext;
		//OPTION 2: std::unique_ptr<WorldSpaceAdapter> for managing
		//			WorldSpace to buffer data conversion


	public:
		Renderer() = delete;
		Renderer();
		Renderer& operator=(Renderer&) = delete;

		/*void bindWorldSpace(WorldSpace* wsContext);
		void renderCurrentContext();*/


		

	};

}