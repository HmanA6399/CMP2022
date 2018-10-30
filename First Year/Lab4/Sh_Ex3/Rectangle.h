#pragma once
#include <iostream>
using namespace std;

class Rectangle
{
	float length = 2, width = 1;
public:
	void setLength(float);
	Rectangle(float l, float w);
	void setWidth(float w);
	float getLength();
	float getWidth();
	float getPrimeter();
	float getArea();
	Rectangle();
};

