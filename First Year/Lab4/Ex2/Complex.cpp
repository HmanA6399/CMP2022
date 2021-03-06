#include "Complex.h"
using namespace std;

Complex Add(Complex, Complex);

int main()
{
	Complex Z, Y(1, 1), C, D;
	Z.setReal(2);
	Z.setImag(2);
	C.setValue(3, 3);

	Z.print();
	Y.print();
	C.print();
	D = Add(Z, Y);
	D.print();
	return 0;
}


void Complex::setReal(float r)
{
	if (!isnan(r)) this->real = r;
}

void Complex::setImag(float im)
{
	if (!isnan(im)) this->imag = im;
}

float Complex::getReal()
{
	return this->real;
}

float Complex::getImag()
{
	return this->imag;
}

void Complex::setValue(float r = 0.0, float im = 0.0)
{
	if (!isnan(r)) this->real = r;
	if (!isnan(im)) this->imag = r;
}

void Complex::print()
{
	printf("(%f, %f)\n", this->real, this->imag);
}

bool Complex::isReal()
{
	return (this->imag == 0.0);
}

bool Complex::isImag()
{
	return (this->real == 0.0);
}

void Complex::Add(Complex Z)
{
	float r = Z.getReal(), im = Z.getImag();

	setReal(this->real + r);
	setImag(this->imag + im);
}

Complex::Complex()
{
}

Complex::Complex(float r, float im)
{
	this->setValue(r, im);
}

Complex::~Complex()
{
}


Complex Add(Complex A, Complex B) {
	Complex C(A.getReal() + B.getReal(), A.getImag() + B.getImag());
	return C;
}
