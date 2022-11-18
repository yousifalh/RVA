#pragma once


namespace rva
{
	class Shader
	{
	private:
		unsigned int m_ID;

	public:
		Shader() = delete;
		Shader& operator=(Shader&) = delete;

		Shader(const char* vertPath, const char* fragPath);

		void use();


	};
}