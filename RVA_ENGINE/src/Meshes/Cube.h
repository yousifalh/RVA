#pragma once


namespace rva
{
	class Cube
	{
	private:
		//Faster: using corner vertex & normal to bottom face 
		//(magnitude of normal is scale? - 2 *  float size data on MM)

		float* m_verticies;

	public:
		Cube() = delete;
		Cube(float* verticies) : m_verticies(verticies) {};
		Cube& operator=(Cube&) = delete;

		float* getVertexPtr() { return m_verticies; }

	};
}