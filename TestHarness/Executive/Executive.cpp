/*****************************************************
* Executive.cpp
*
* This file defines the methods of the Executive class.
*
* Author: Nicole Perez, Ashraf Elnashar
* Date: April 2019
* Object Oriented Design - Syracuse University
*****************************************************/

#include "pch.h"
#include "Executive.hpp"
#include "../Logger/Logger.hpp"
#include "../TestHarness/TestHarness.hpp"
#include <fstream>
#include <iostream>

using namespace Executive;


void helloWorld() {
	std::cout << "Hello World!\n";
}

void nullPointerException() {
	throw std::exception("Null Pointer Exception!");
}

void basicMath() {
	int i = 5;
	int j = 4;
	int k = i + j;
}

//This method tests if we can catch c++ exceptions that are not explicitely thrown by us
void lengthError() {
	// vector throws a length_error if resized above max_size
	std::vector<int> myvector;
	myvector.resize(myvector.max_size() + 1);
}

int main()
{
	//declare a TestHarness object
	TestHarness::MyTestHarness myTestHarness;

	//declare vector to hold test functions
	std::vector<void(*)()> functions;

	//add test functions to vector
	functions.push_back(helloWorld);
	functions.push_back(nullPointerException);
	functions.push_back(basicMath);
	functions.push_back(lengthError);

	//declare Level A logger object (top level pass/fail)
	Logger::Level myLevelA = Logger::A;
	std::ofstream fileStreamA("../LevelAOutput.txt");
	Logger::Log myLogA = Logger::Log("Test Harness Level A", myLevelA, fileStreamA);

	//execute test harness with Level A Logger
	myTestHarness.executer(functions, myLogA);

	//declare Level B logger object (pass/fail by test)
	Logger::Level myLevelB = Logger::B;
	std::ofstream fileStreamB("../LevelBOutput.txt");
	Logger::Log myLogB = Logger::Log("Test Harness Level B", myLevelB, fileStreamB);

	//execute test harness with Level B Logger
	myTestHarness.executer(functions, myLogB);

	//declare Level C logger object (pass/fail by test with timestamp and error messages)
	Logger::Level myLevelC = Logger::C;
	std::ofstream fileStreamC("../LevelCOutput.txt");
	Logger::Log myLogC = Logger::Log ("Test Harness Level C", myLevelC, fileStreamC);

	//execute test harness with Level A Logger
	myTestHarness.executer(functions, myLogC);

	//keep window open until user is done
	printf("Press any key to close this window . . .\n");
	getchar();
}
