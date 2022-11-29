#include "Macro.h"
#include "Instance.h"

#include <glad/glad.h>

#include "meshes/Mesh.h"
#include "meshes/Cube.h"

#define VS_PATH "res/shader/simple_shader.vert"
#define FS_PATH "res/shader/simple_shader.frag"

namespace rva
{
	RvaEngine::RvaEngine()
	{
		Window::initContext();

		m_window = std::make_unique<Window>();

		m_shader = std::make_unique<Shader>(VS_PATH, FS_PATH);

	}

	int RvaEngine::run()
	{
		Cube cube{0};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, cube.getPtr(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//LOG
		RVA_LOG("Setted up buffers...");

		glBindVertexArray(VAO);

		while (!m_window->windowShouldClose())
		{
			glClearColor(0.3f, 0.5f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			m_shader->use();

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);


			m_window->swapBuffers();
			m_window->processPollEvents();
		}

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);

		return 0;
	}

	RvaEngine::~RvaEngine()
	{
		Window::terminateContext();
	}
}