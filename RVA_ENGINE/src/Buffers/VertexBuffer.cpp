#include "../Core.h"
#include "VertexBuffer.h"

#include <glad/glad.h>

namespace rva
{
	// TODO: location stuff...

	void VertexBuffer::drawBuffer()
	{
		glDrawArrays(GL_TRIANGLES, 0, m_size);
	}

	VertexBuffer::VertexBuffer(float* dataPtr, unsigned int size)
		: m_size(size)
	{
		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindVertexArray(m_vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(float), dataPtr, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

	}

	void VertexBuffer::bind()
	{
		glBindVertexArray(0);
	}
}