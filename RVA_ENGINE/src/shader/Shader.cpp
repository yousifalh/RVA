#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


namespace rva
{
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "SHADER: Shader " << type << " compile error: " << std::endl << infoLog << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "PROGRAM: Shader program linking error: " << std::endl << infoLog << std::endl;
			}
		}
	}

	Shader::Shader(const char* vsPath, const char* fsPath)
	{
		std::string vCode;
		std::string fCode;

		std::ifstream vFile;
		std::ifstream fFile;

		vFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		fFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

		try
		{
			std::stringstream vStream;
			vFile.open(vsPath);
			vStream << vFile.rdbuf();
			vFile.close();

			vCode = vStream.str();
		}
		catch (std::exception e)
		{
			std::cout << "SHADER: Failed to open and read vertex file!" << std::endl << "[";
			std::cout << e.what() << "]" << std::endl;
		}

		try
		{
			std::stringstream fStream;

			fFile.open(fsPath);
			fStream << fFile.rdbuf();
			fFile.close();

			fCode = fStream.str();
		}
		catch (std::exception e)
		{
			std::cout << "SHADER: Failed to open and read fragment file!" << std::endl << "[";
			std::cout << e.what() << "]" << std::endl;
		}

		const char* vertexCode = vCode.c_str();
		const char* fragmentCode = fCode.c_str();

		unsigned int v, f;

		v = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(v, 1, &vertexCode, NULL);
		glCompileShader(v);
		checkCompileErrors(v, "VERTEX");

		f = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(f, 1, &fragmentCode, NULL);
		glCompileShader(f);
		checkCompileErrors(f, "FRAGMENT");

		m_ID = glCreateProgram();
		glAttachShader(m_ID, v);
		glAttachShader(m_ID, f);

		glLinkProgram(m_ID);
		checkCompileErrors(m_ID, "PROGRAM");


		glDeleteShader(v);
		glDeleteShader(f);

	}

	void Shader::use()
	{
		glUseProgram(m_ID);
	}
}

