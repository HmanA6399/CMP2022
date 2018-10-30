#include <iostream>
using namespace std;

int* readArray(int size);
void printArray(int*, int);

int main()
{
	int size; cin >> size;
	int* arr = readArray(size);
	printArray(arr, size);
}


int* readArray(int sz) {
	int* a = new int[sz];
	for (int i = 0; i < sz; ++i) cin >> a[i];
	return a;
}

void printArray(int* a, int sz) {
	for (int i = 0; i < sz; ++i) cout << a[i] << " ";
	cout << "\n";
}