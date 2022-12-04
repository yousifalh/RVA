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
		glEnable(GL_DEPTH_TEST);

		Cube cube{0};

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, cube.getPtr(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(Vertex::vert)));
		glEnableVertexAttribArray(1);


		//Projection matrix
		glm::mat4 proj;


		//proj = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
		proj = glm::perspective(glm::radians(45.0f), (float)m_window->getWidth() / m_window->getHeight(), 0.1f, 100.f);

		//LOG
		RVA_LOG("Setted up buffers...");

		glBindVertexArray(VAO);

		//For debugging
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		while (!m_window->windowShouldClose())
		{
			m_window->processInput();

			glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			m_shader->use();
			
			m_shader->setMat4Uniform("projection", proj);
			m_shader->setMat4Uniform("view", m_window->camera->getViewMatrix());
			

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);

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