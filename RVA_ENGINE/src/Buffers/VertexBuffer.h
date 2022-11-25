#pragma once


namespace rva
{
	class VertexBuffer
	{
	private:
		unsigned int m_vbo;
		unsigned int m_vao;

		unsigned int m_size;

	public:
		VertexBuffer() = delete;
		//VertexBuffer(VertexBuffer&) = delete;
		//VertexBuffer& operator=(VertexBuffer&) = delete;

		void drawBuffer();

		VertexBuffer(float* dataPtr, unsigned int numVerticies);
		
		void bind();

	}; 
}