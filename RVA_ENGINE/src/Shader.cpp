#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


namespace rva
{
	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		std::fstream vFile, fFile;
		std::string vCode, fCode;


		vFile.exceptions(std::fstream::badbit | std::fstream::failbit);
		fFile.exceptions(std::fstream::badbit | std::fstream::failbit);



		try
		{
			std::stringstream vStream, fStream;

			vFile.open(vertPath);
			vStream << vFile.rdbuf();
			vFile.close();

			fFile.open(fragPath);
			fStream << fFile.rdbuf();
			fFile.close();

			vCode = vStream.str();
			fCode = fStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "Failed to open and read vertex and fragment shader files!"
				<< std::endl << e.what() << std::endl;
		}
		
		const char* vertexCode = vCode.c_str();
		const char* fragmentCode = fCode.c_str();

		unsigned int vID, fID;
		int success;
		char info[512];

		vID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vID, 1, &vertexCode, NULL);
		glCompileShader(vID);

		glGetShaderiv(vID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vID, 512, NULL, info);
			std::cout << "Failed to compile vertex shader!" << std::endl
				<< info << std::endl;
		}

		fID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fID, 1, &fragmentCode, NULL);
		glCompileShader(fID);

		glGetShaderiv(fID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fID, 512, NULL, info);
			std::cout << "Failed to compile fragment shader!" << std::endl
				<< info << std::endl;
		}

		m_ID = glCreateProgram();
		glAttachShader(m_ID, vID);
		glAttachShader(m_ID, fID);
		glLinkProgram(m_ID);

		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, 512, NULL, info);
			std::cout << "Failed to link shader program!" << std::endl
				<< info << std::endl;
		}

		glDeleteShader(vID);
		glDeleteShader(fID);

	}

	void Shader::use()
	{
		glUseProgram(m_ID);
	}
}