#include "PathConstructor.h"


namespace rva
{
	PathConstructor::PathConstructor()
	{

	}

	void PathConstructor::pushFeature(Feature& feature)
	{
		m_featureString.push_back(feature);
	}


	//Room for optimisation -- also we could generalise to any kind of extrapolator
	//between two points -- using polynomials (bezier curves)
	std::shared_ptr<Path> PathConstructor::computePath(unsigned int incMagnitude)
	{
		std::shared_ptr<Path> path;

		Feature previousFeature;

		for (Feature f : m_featureString)
		{
			if (f == m_featureString.front())
			{
				previousFeature = f;
			}
			else
			{
				glm::vec3 ab = (f.pos - previousFeature.pos);
				unsigned int length = static_cast<unsigned int>(glm::length(ab));
				glm::vec3 abInc
				{
					ab.x / length * incMagnitude,
					ab.y / length * incMagnitude,
					ab.z / length * incMagnitude
				};

				unsigned int n = static_cast<unsigned int>(floor(length / incMagnitude));
				//double remainder = (length / incMagnitude) - n;

				Feature intermediate = previousFeature;

				for (unsigned int x{ 0 }; x < n; x++)
				{
					intermediate.pos = glm::vec3(
						intermediate.pos.x + abInc.x,
						intermediate.pos.y + abInc.y,
						intermediate.pos.z + abInc.z
					);
					path->data.emplace_back(intermediate);
				}

			
				path->data.push_back(&f.pos);
				
			}
		}

		return path;
	}
}