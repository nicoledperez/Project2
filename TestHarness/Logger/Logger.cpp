/*****************************************************
* Logger.cpp
*
* This file defines the log method of the Logger class.
*
* Author: Nicole Perez, Ashraf Elnashar
* Date: April 2019
* Object Oriented Design - Syracuse University
*****************************************************/

#include "pch.h"
#include "Logger.hpp"

using namespace Logger;

void Log::addTestResult(int n, bool r, std::string m, char* t) {

	//create a test results object for the function
	TestResult testResult = TestResult(n, r, m, t);
	results.push_back(testResult);
}

void Log::printLog() {
	//write out beginning formatting to cout and output file
	std::cout << std::endl << appName << " Output-------------------------------------------------" << std::endl << std::endl;
	fileStream << std::endl << appName << " Output-------------------------------------------------" << std::endl << std::endl;
	//iterate through results vector and output info based on testResults

	if (results.size() != 0) {
		//choose the level of output based on the provided level for the logger
		switch (level) {
		case A:
			produceLevelAOutput();
			break;
		case B:
			produceLevelBOutput();
			break;
		case C:
			produceLevelCOutput();
			break;
		default:
			break;
		}
	}
	else {
		std::cout << "There are no functions to test." << std::endl;
		fileStream << "There are no functions to test." << std::endl;
	}


	std::cout << std::endl << "-------------------------------------------------------------------" << std::endl;
	fileStream << std::endl << "-------------------------------------------------------------------" << std::endl;
}


//Level A: Basic Pass / Fail on list of tests
void Log::produceLevelAOutput() {
	bool testsPassed = true;
	//loop through results
	for (auto && result : results) {
		//if any test failed set testsPassed to false
		if (!result.testResult) {
			testsPassed = false;
		}
	}

	//write to cout and the output file based on testsPassed flag
	if (!testsPassed) {
		std::cout << "One or more tests failed." << std::endl;
		fileStream << "One or more tests failed." << std::endl;
	}
	else {
		std::cout << "All tests passed." << std::endl;
		fileStream << "All tests pased." << std::endl;
	}
}

//Level B: Test Specific Pass/Fail
void Log::produceLevelBOutput() {
	//loop through results
	for (auto && result : results) {
		//write to cout and the output file based on the results of the test
		if (result.testResult) {
			std::cout << "Test " << result.testNumber << ": PASSED" << std::endl;
			fileStream << "Test " << result.testNumber << ": PASSED" << std::endl;
		}
		else {
			std::cout << "Test " << result.testNumber << ": FAILED" << std::endl;
			fileStream << "Test " << result.testNumber << ": FAILED" << std::endl;
		}
	}
}

//Level C: Time / Date Stamp and values of test defined variables
void Log::produceLevelCOutput() {
	//loop through results
	for (auto && result : results) {
		//write to cout and the output file based on the results of the test
		if (result.testResult) {
			std::cout << "Test " << result.testNumber << ": PASSED" << std::endl;
			fileStream << "Test " << result.testNumber << ": PASSED" << std::endl;
		}
		else {

			std::cout << "Test " << result.testNumber << ": FAILED" << std::endl;
			std::cout << "\t" << result.testTimeAndDate << "	" << result.errorMessage << std::endl;

			fileStream << "Test " << result.testNumber << ": FAILED" << std::endl;
			fileStream << "\t" << result.testTimeAndDate << "	" << result.errorMessage << std::endl;
		}
	}
}

int main()
{
	std::cout << "Hello World!\n";
}