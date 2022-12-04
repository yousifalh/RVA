#include "Mesh.h"


namespace rva
{
	Mesh::Mesh(Vertex* verticiesIn, unsigned int num)
		: m_verticiesPtr(verticiesIn), m_numVertices(num)
	{
	}

}