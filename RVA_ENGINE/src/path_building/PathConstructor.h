#pragma once

#include "FeatureTools.h"

#include <iostream>
#include <list>
#include <memory>


namespace rva
{
	struct Path
	{
		std::list<glm::vec3*> data;
		
		friend std::ostream& operator<<(std::ostream& out, const Path& path);
	};

	std::ostream& operator<<(std::ostream& out, const Path& path)
	{
		for (auto& v : path.data)
		{
			out << "(" << v->x << ", " << v->y << ", " << v->z << ")" << "\n";
		}
		return out;
		
	}


	class PathConstructor
	{
	private:
		std::list<Feature> m_featureString;

	public:
		PathConstructor();

		void pushFeature(Feature& feature);

		std::shared_ptr<Path> computePath(unsigned int incMagnitude);
		
	};
}