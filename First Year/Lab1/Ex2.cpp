#include <iostream>
using namespace std;

//Fn. PROTOTYPE
bool IsGrowing(int&);

int main() {
	//DECLERATION
	int Largest;

	//INPUT, PROCESS N OUTPUT
	printf("Input values are %sin growing order\n", IsGrowing(Largest) ? "" : "NOT "); //if you find it confusing, read it three times to undestand
	printf("Largest value entered is %d", Largest);
	return 0;
}

//Fn DEFINITION
bool IsGrowing(int& Large) {
	//INPUT
	int current, prev;
	cin >> prev; //store the first entry in prev
	Large = prev; //Initial value to the largest no.
	if (prev <= 0) return false; // returns false in case of the first entry being non-positive
	bool firstTime = true; //a boolean flag to pass the case of only one positive no.
	bool grow = true; //a flag to store if growing or not, initially true.
	
	while (true) {
		cin >> current;
		if (current <= 0) {
			if (firstTime) {
				//this means that only the first entry - prev - is positive
				grow = false;
			}
			break;
		}
		else
			//compare with the previous
			if (current <= prev) {
				grow = false; //it's not growing
				break;
			}
			else 
				Large = current; //Updates the Largest
		prev = current; //moves the prev to the current for the new loop turn
		firstTime = false; //GoodBye, firstTime :"
	}
	return grow;
}