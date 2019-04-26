/*****************************************************
* TestHarness.cpp
*
* This file defines the executer method of the TestHarness class.
*
* Author: Nicole Perez, Ashraf Elnashar
* Date: April 2019
* Object Oriented Design - Syracuse University
*****************************************************/

#include "pch.h"
#include "TestHarness.h"
#include <iostream>
#include <chrono>
#include <ctime> 

using namespace TestHarness;

bool MyTestHarness::executer(std::vector<void(*)()> functions, Logger::Log log) {
	//variable declarations
	int n = 1;
	bool testsPassed = true;

	for (auto && fn : functions)
	{
		try
		{
			//run the current function
			fn();

			//add the results to the logger for this test
			const char* m = "";

			//get the time for the logger
			time_t now = time(0);
			char t[26];
			ctime_s(t, sizeof t, &now);

			log.addTestResult(n, true, m, t);
		}
		catch (std::exception& e)
		{
			//if there was an exception then the test failed so set the return value to false
			testsPassed = false;

			//add the results to the logger for this test
			const char* m = e.what();

			//get the time for the logger
			time_t now = time(0);
			char t[26];
			ctime_s(t, sizeof t, &now);

			log.addTestResult(n, false, m, t);
		}
		n++;
	}
	//print the log info
	log.printLog();

	return testsPassed;
}

int main()
{
    std::cout << "Hello World!\n"; 
}
