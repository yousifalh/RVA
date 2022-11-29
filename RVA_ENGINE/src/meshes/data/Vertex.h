#pragma once

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace rva
{
	struct TextureData
	{
		float a, b;
	};

	struct VertexData
	{
		float x, y, z;
	};

	struct ColourData
	{
		float r, g, b;
	};

	struct Vertex
	{
		VertexData v;
		ColourData c;

		friend std::ostream& operator<<(std::ostream& out, const Vertex& vert);
	};


	struct TextureVertex
	{
		VertexData v;
		TextureData t;
	};

	
	static std::ostream& operator<<(std::ostream& out, const Vertex& vert)
	{
		out << "Vertex([" << vert.v.x << "," << vert.v.y << "," << vert.v.z
			<< "],[" << vert.c.r << "," << vert.c.g << "," << vert.c.b << "])" << std::endl;
		return out;
	}

}