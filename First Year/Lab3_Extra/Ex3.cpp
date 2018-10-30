#include "pch.h"
#include <iostream>
using namespace std;

void getConsElementsDivision(int*, int, float*, int);

int main() {
	int size = 0, newSize = 0, *arr = NULL;
	float *newArr = NULL;
	cin >> size;
	
	if (size & 1) { // a faster way to test even and odd, returns 1 if odd, 0 if even
		printf("Invalid");
	}
	else
	{
		arr = new int[size];
		newSize = size / 2;
		newArr = new float[newSize];

		for (int i = 0; i < size; ++i) {
			cin >> arr[i];
		}

		getConsElementsDivision(arr, size, newArr, newSize);

		for (int i = 0; i < newSize; ++i) {
			cout << newArr[i] << " ";
		}
		printf("\n");
	}
	delete[] arr; delete[] newArr;
	return 0;
}

void getConsElementsDivision(int * a, int na, float * b, int nb)
{
	int cnt = 0;  float num, denom; // the numerator and the denominator
	for (int i = 0; i < na - 1; i+=2) {
		num = a[i]; denom = a[i + 1];
		b[cnt++] = (denom == 0) ? INFINITY : num/denom;
		//If the denominator = 0, the Quotient tends to infinity, else it's equal to 
		// num/denom
	}
}
