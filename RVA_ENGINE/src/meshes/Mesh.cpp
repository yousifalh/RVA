#include "Mesh.h"


namespace rva
{
	Mesh::Mesh(float* verticiesIn, unsigned int num)
		: m_verticiesPtr(verticiesIn), m_numVertices(num)
	{
	}

}