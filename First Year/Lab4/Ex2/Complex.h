#pragma once
#include <iostream>

class Complex
{
	float real = 0.0, imag = 0.0;
public:
	void setReal(float);
	void setImag(float);
	float getReal();
	float getImag();
	void setValue(float, float);
	void print();
	bool isReal();
	bool isImag();
	void Add(Complex);
	Complex();
	Complex(float, float);
	~Complex();
};

