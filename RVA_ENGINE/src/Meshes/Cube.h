#pragma once

#include <glm/glm.hpp>


namespace rva
{
	class Cube
	{
	private:
		//Faster: using corner vertex & normal to bottom face 
		//(magnitude of normal is scale? - 2 *  float size data on MM)

		glm::vec3 m_pos;
		unsigned int m_scale;


	public:
		Cube() = delete;
		Cube(glm::vec3 pos, unsigned int scale) : m_pos(pos), m_scale(scale) {};

		// Cube(glm::vec3 position, );

		Cube& operator=(Cube&) = delete;
		
		glm::vec3 getPosition() { return m_pos; }
		void setPosition(glm::vec3& newPos) { m_pos = newPos; }
		unsigned int getScale() { return m_scale; }
		unsigned int setScale(unsigned int newScale) { m_scale = newScale; }
		
	};
}