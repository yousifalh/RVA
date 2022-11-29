#include "Instance.h"

int main()
{
	rva::RvaEngine* rvaEngine = new rva::RvaEngine();
	
	rvaEngine->run();

	delete rvaEngine;


}


/*rva::PathConstructor pathConstruct;


	for (int x{ 1 }; x < 10; x++)
	{
		rva::Feature feature{ glm::vec3(
			static_cast<float>(2*x),
			static_cast<float>(x*x + x),
			0.0f)};

		pathConstruct.pushFeature(feature);
	}

	std::shared_ptr<rva::Path> resultPath = pathConstruct.computePath(1);

	std::cout << "Path: " << std::endl << resultPath << std::endl;*/