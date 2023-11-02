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
	/*cout << "(positive integer)(space)(operator)(space)(positive integer)" << endl;
	cout << "Exit the program: enter." << endl;
	while (true) {
		if (tokenize());
		else break;
	}*/
	inf_int a;
	inf_int b(100);
	inf_int c("123123");
	inf_int d(b);
	inf_int e = c;
	inf_int f("-123456");
	inf_int g(-123);
	inf_int h = f;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
	cout << "f: " << f << endl;
	cout << "g: " << g << endl;
	cout << "h: " << h << endl;

	return 0;
}
