#pragma once

#include <glm/glm.hpp>


namespace rva
{
	struct Feature
	{
		Feature() { pos = glm::vec3(0.0f, 0.0f, 0.0f); }
		Feature(glm::vec3& v) : pos(v) {}
		Feature(const glm::vec3& v) : pos(v) {}
		glm::vec3 pos;

		friend bool operator==(const Feature f1, const Feature f2);
	};

	bool operator==(const Feature f1, const Feature f2)
	{
		if (f1.pos == f2.pos)
			return true;
		else
			return false;
	}

	

	//Memory pools etc..

}