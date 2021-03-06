#include "BinaryNumber.h"
using namespace std;

BinaryNumber XOR(BinaryNumber, BinaryNumber);

int main()
{
	int binary1[8] = { 1, 0, 0, 1, 0, 0, 1, 0 };
	int binary2[8] = {1, 0, 0, 0, 0, 0, 0, 0};
	BinaryNumber Bin1(binary1, 8);
	BinaryNumber Bin2(binary2, 8);
	BinaryNumber Bin3;
	Bin1.printDigits();
	Bin1.ShiftLeft();
	Bin1.printDigits();
	Bin1.setValues(1, 0);
	Bin1.printDigits();

	printf("\n");
	Bin1.printDigits();
	printf("              XOR\n");
	Bin2.printDigits();
	printf("-------------------\n");
	Bin3 = XOR(Bin1, Bin2);
	Bin3.printDigits();
	return 0;
}

BinaryNumber::BinaryNumber()
{
}

bool BinaryNumber::getDigit(int idx) {
	if (idx >= 0 && idx <= 8) return this->digits[i];
	else printf("out of range\n");
}

int BinaryNumber::setValues(int idx, int bin)
{
	if (idx > 7 || idx < 0) {
		printf("invalid input returns 1\n");
		return 1;
	}
	else if (bin != 0 && bin != 1) {
		printf("invalid input returns 2\n");
		return 2;
	}
	else this->digits[idx] = bin;
	return 0;
}

void BinaryNumber::printDigits()
{
	for (int i = 7; i >= 0; --i)
		cout << this->digits[i] << " ";
	printf("\n");
}

void BinaryNumber::ShiftLeft()
{
	bool t[8];
	for (int i = 0; i < 8; ++i) t[i] = this->digits[i];
	for (int i = 1; i < 8; ++i) {
		this->setValues(i, t[i - 1]);
	}
	this->digits[0] = 0;
}

int BinaryNumber::ConvertToDecimal()
{
	int res = 0;
	bool curDig;
	for (int i = 0; i < 8; ++i) {
		curDig = this->digits[i];
		if (curDig == 0) continue;
		else res += pow(2, i);
	}
	return res;
}

BinaryNumber::BinaryNumber(int dig[], int sz = 8)
{
	if ( sz <= 8 ) {
		for (int i = 0; i < sz; ++i)
			this->setValues(i, dig[i]);
	}
	else printf("no putting into digits\n");
}

BinaryNumber::~BinaryNumber()
{
}


BinaryNumber XOR(BinaryNumber A, BinaryNumber B)
{
	BinaryNumber C;
	int a, b;
	for (int i = 0; i < 8; ++i) {
		a = A.getDigit(i); b = B.getDigit(i);
		C.setValues(i, ((a && !b) || (b && !a) ? true : false));
	}
	return C;
}