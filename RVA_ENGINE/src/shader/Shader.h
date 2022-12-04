#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace rva
{
	class Shader
	{
	private:
		unsigned int m_ID;

	public:
		Shader(Shader&) = delete;
		Shader(Shader&&) = delete;
		Shader& operator=(Shader&) = delete;

		Shader(const char* vsPath, const char* fsPath);
		
		unsigned int getID() { return m_ID; }

		void use();

		void setMat4Uniform(const char* name, const glm::mat4& mat);
	};
}