#include <iostream>
using namespace std;

//Fn. PROTOTYPE
int CountLTR(char, int);

int main() {
	//DECLERATION
	char LTR; int N;
	
	//INPUT
	cin >> LTR >> N;

	//PROCESS N OUTPUT
	printf("Letter %c appeared %d times\n", LTR, CountLTR(LTR, N));
	return 0;
}

//Fn. DEFINITION
bool SmallCap(char c, char& sm, char& cap)
{
	//Function to store small and capital versions of a char
	//Returns true if the input c is numerical, false otherwise.
	bool isAlpha = true;
	if (c >= 'a' && c <= 'z') { // the char is small
		sm = c;
		cap = 'A' + (c - 'a');
	}
	else if (c >= 'A' && c <= 'Z') { // the input is capital
		cap = c;
		sm = ('a' + (c - 'A'));
	}
	else isAlpha = false;

	return isAlpha;
}

int CountLTR(char ltr, int n)
{
	char smLtr, capLtr, in, smIn, capIn;
	int cnt = 0;
	SmallCap(ltr, smLtr, capLtr);
	
	for (int i = 0; i < n; ++i) {
		cin >> in; //Store for the input char every time

		if (SmallCap(in, smIn, capIn) == false) {
			continue;
		}
		else {
			if (smIn == smLtr || capIn == capLtr) cnt++;
			else continue; //ensure continueness
		}
	}
	return cnt;
}