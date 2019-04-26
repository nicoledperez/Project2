/*****************************************************
* Logger.hpp
*
* This file creates the Logger Object for the TestHarness.
*
*
* Author: Nicole Perez, Ashraf Elnashar
* Date: April 2019
* Object Oriented Design - Syracuse University
*****************************************************/

#ifndef LOGGER_H
#define LOGGER_H


#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

namespace Logger {

	struct TestResult {
		int testNumber; //index of test in testFunctions vector defined in main (used for formatting)
		bool testResult; //pass or fail value
		std::string errorMessage; //contents of the exception
		char* testTimeAndDate; //time stamp on exception

		TestResult(int n, bool r, std::string m, char* t) : testNumber(n), testResult(r), errorMessage(m), testTimeAndDate(t) {}
	};

	/*
		This enum defines the level of detail that the Logger will produce.
		Level A:
			Basic Pass/Fail on list of tests
		Level B:
			Test specific Pass/Fail
		Level C:
			Time/Date Stamp and values of test-defined variables
	*/
	enum Level { A, B, C };

	class Log {

	private:
		const std::string appName;
		const Level level;
		std::ofstream& fileStream;
		std::vector<TestResult> results;

		//private print methods for each level of logging
		void produceLevelAOutput();
		void produceLevelBOutput();
		void produceLevelCOutput();

	public:
		//constructor
		Log(std::string name, Level l, std::ofstream& fs) : appName(name), level(l), fileStream(fs) {}

		//member methods
		void addTestResult(int n, bool r, std::string m, char* t);
		void printLog();
	};
}

#endif // !LOGGER_H