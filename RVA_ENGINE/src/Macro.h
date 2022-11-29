#pragma once
#ifdef _DEBUG


#include <stdexcept>
#include <iostream>

#define RVA_WARN(message) (std::cout << "WARNING: " << message << std::endl)
#define RVA_LOG(message) (std::cout << message << std::endl)

#elif


#define RVA_WARN
#define RVA_ASSERT
#define RVA_LOG
#define RVA_RUNTIME_ERR


#endif

#define RVA_ASSERT(a, message) \
	if(!a) \
	{ \
		std::cout << "ASSERTION: " << message << std::endl;\
		std::exit(-1);\
	}
#define RVA_RUNTIME_ERR(message) ( throw std::runtime_error(message) )
#define RVA_RUNTIME_ERR(a, message) (if (!a) { throw std::runtime_error(message); })