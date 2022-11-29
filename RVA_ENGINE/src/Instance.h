#pragma once

#include "Window.h"
#include "shader/Shader.h"

#include <memory>

namespace rva
{
	class RvaEngine
	{
	private:
		std::unique_ptr<Window> m_window;
		std::unique_ptr<Shader> m_shader;


		//WorldSpace is where all the links, meshes and 
		//other similar data are done represented in the real world...
		/*static void WorldSpace();
		Pipeline is where we handle the data stream from RPI/Arduino...
		static void Pipeline();*/

	public:
		RvaEngine(RvaEngine&) = delete;
		RvaEngine(const RvaEngine&) = delete;
		RvaEngine& operator=(RvaEngine&) = delete;

		RvaEngine();
		~RvaEngine();

		int run();

		
	};
}