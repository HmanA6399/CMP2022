#include "Rectangle.h"

int main()
{
	Rectangle reco;
	reco.setLength(5);
	reco.setWidth(2);
	float areaRico = reco.getArea();
	float primRico = reco.getPrimeter();
	Rectangle reca(2, 5);
	float primRica = reca.getPrimeter();
	float areaRica = reca.getArea();
	
	printf("Once upon a time, there were 2 rectangles, Reco and Reca\n");
	printf("Reco was %f meters length, %f meters width\n", reco.getLength(), reco.getWidth());
	printf("Reca was different, she was %f meters length, %f meters width\n", reca.getLength(), reca.getWidth());
	printf("Reco's primeter %f was the same as Rica's, so was his area %f\n", primRico, areaRica);
	printf("SO THEY MARRIED\n");
	return 0;
}

void Rectangle::setLength(float l)
{
	this->length = (l > 0) ? l : 1;
}

Rectangle::Rectangle(float l, float w)
{
	setLength(l);
	setWidth(w);
	printf("Rectangle created with length %f and width %f\n", l, w);
}

Rectangle::Rectangle()
{
	this->length = 2; this->width = 1;
}

void Rectangle::setWidth(float w)
{
	this->width = (w > 0) ? w : 1;
}

float Rectangle::getLength()
{
	return this->length;
}

float Rectangle::getWidth()
{
	return this->width;
}

float Rectangle::getPrimeter()
{
	return (this->length + this->width) * 2;
}

float Rectangle::getArea()
{
	return this->length * this->width;
}