#include <iostream>
#pragma once
class BinaryNumber
{
	bool digits[8] = {0};
public:
	int setValues(int, int);
	bool getDigit(int idx);
	void printDigits();
	void ShiftLeft();
	int ConvertToDecimal();
	BinaryNumber(int[], int);
	BinaryNumber();
	~BinaryNumber();
};

