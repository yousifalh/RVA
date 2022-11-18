#include "Renderer.h"

#include "data/ShaderData.h"



namespace rva
{
	Renderer::Renderer()
	{
		//For future: use threading...
		m_shader = std::make_unique<Shader>(VERTEX_PATH, FRAGMENT_PATH);

		m_shader->use();



	}
}