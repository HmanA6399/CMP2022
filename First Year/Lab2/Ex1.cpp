#include <iostream>
using namespace std;

//Fn PROTOTYPE
int* EvensFirst(int*, int);


int main() {
	//DECLERATION
	int size; cin >> size;
	int* arr = new int[size], *evenf = new int[size];

	//INPUT
	for (int i = 0; i < size; ++i) cin >> arr[i];

	//PROCESS
	evenf = EvensFirst(arr, size);

	//OUTPUT
	for (int i = 0; i < size; ++i) printf("%d ", evenf[i]);

	//HEAP DEALLOC
	delete[] arr; delete[] evenf;
}

//Fn DEFINITION
int* EvensFirst(int* a, int n)
{
	int *b = new int[n], bCnt = 0;
	//looping on a and store the evens in b
	for (int i = 0; i < n; ++i)
		if (!(a[i] & 1)) b[bCnt++] = a[i];
	//looping again to store the odds
	for (int i = 0; i < n; ++i)
		if ((a[i] & 1)) b[bCnt++] = a[i];
	return b;
}
