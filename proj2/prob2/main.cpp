#define _CRT_SECURE_NO_WARNINGS

#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

bool tokenize() {
	std::string inputString;
	std::cout << "INPUT: ";
	std::getline(std::cin, inputString);
	char* cString = new char[inputString.length() + 1];
	strcpy(cString, inputString.c_str());
	char* token = std::strtok(cString, " ");
	if (token == NULL) return false;
	inf_int a(token);
	token = std::strtok(nullptr, " ");
	char op = token[0];
	token = std::strtok(nullptr, " ");
	inf_int b(token);
	token = std::strtok(nullptr, " ");
	delete[] cString;
	if (op == '+')cout << "RESULT: " << a + b << endl;
	else if (op == '-')cout << "RESULT: " << a - b << endl;
	else if (op == '*')cout << "RESULT: " << a * b << endl;
	else cout << "Warning. Invalid input data." << endl;
	return true;
}

int main()
{
	cout << "(positive integer)(space)(operator)(space)(positive integer)" << endl;
	cout << "Exit the program: enter." << endl;
	while (true) {
		if (tokenize());
		else break;
	}
	return 0;
}
