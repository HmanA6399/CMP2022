#include <iostream>
using namespace std;

float getPower(float, int);
float getPolynomial(float, int);


int main()
{
	float x; cin >> x;
	int n; cin >> n;
	cout << getPolynomial(x, n) << "\n";
	return 0;
}


float getPower(float x, int p) {
	if (p == 1) return x;
	return x * getPower(x, p - 1); //you can do it with for loops as well, this is called Recursion
}


float getPolynomial(float x, int n) {
	if (n == 1) return x;
	return n * getPower(x, n) + getPolynomial(x, n - 1); //you can do it with for loops as well, this is called Recursion
}