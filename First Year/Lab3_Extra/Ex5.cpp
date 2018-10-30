#include <iostream>
using namespace std;

//Fn PROTOTYPE
void splitArrayOn(int*, int, int, int*&, int&, int*&, int&);

int main()
{
	//INPUT
	int size, split, *before = NULL, *after = NULL, beforeSize, afterSize;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	cin >> split;

	//PROCESS
	splitArrayOn(arr, size, split, before, beforeSize, after, afterSize);

	//OUTPUT
	if (beforeSize == 0) printf("Empty Array\n");
	else {
		for (int i = 0; i < beforeSize; ++i) cout << before[i] << " ";
		printf("\n");
	}
	if (afterSize == 0) printf("Empty Array\n");
	else {
		for (int i = 0; i < afterSize; ++i) cout << after[i] << " ";
		printf("\n");
	}

	return 0;
}

//Fn DEFINITION
void splitArrayOn(int * a, int na, int sp, int *&bef, int &n_bef, int *&af, int &n_af)
{
	int split_i; // index of the split

	//searching for the split index
	for (int i = 0; i < na; ++i) {
		if (a[i] == sp) {
			split_i = i;
			break;
		}
	}
	n_bef = split_i; //no. of elements in the array before = split index
	bef = new int[n_bef]; bef = a; // the bef. array starts at the first element
	n_af = na - split_i; //no. of el.s in the  array after = (total no. of el.s) - (no. of bef. el.s)
	af = new int[n_af]; af = a + split_i; // the bef. array starts at the split element
}
