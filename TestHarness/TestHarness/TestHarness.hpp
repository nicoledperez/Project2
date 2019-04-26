/*****************************************************
* TestHarness.hpp
*
* This project will create a Test Harness that can execute
* one or more tests and provide multiple levels of logging.
*
* Author: Nicole Perez, Ashraf Elnashar
* Date: April 2019
* Object Oriented Design - Syracuse University
*****************************************************/

#ifndef TEST_HARNESS_H
#define TEST_HARNESS_H


#pragma once
#include "../Logger/Logger.hpp"

namespace TestHarness {
	class MyTestHarness {
	public:
		bool executer(std::vector<void(*)()> functions, Logger::Log logger);
	};
}


#endif // !TEST_HARNESS_H