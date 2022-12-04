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
		VertexData vert;
		ColourData col;

		friend std::ostream& operator<<(std::ostream& out, const Vertex& vert);
	};


	struct TextureVertex
	{
		VertexData v;
		TextureData t;
	};

	
	static std::ostream& operator<<(std::ostream& out, const Vertex& v)
	{
		out << "Vertex([" << v.vert.x << "," << v.vert.y << "," << v.vert.z
			<< "],[" << v.col.r << "," << v.col.g << "," << v.col.b << "])" << std::endl;
		return out;
	}

}