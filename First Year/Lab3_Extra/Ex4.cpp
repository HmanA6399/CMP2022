#include <iostream>
using namespace std;

void Cumulative(int*&, int&, int*);

int main() {
	int removedElements[2], size;
	cin >> size;
	if (size < 3) {
		cout << "invalid\n";
	}
	else
	{
		int* arr = new int[size];
		for (int i = 0; i < size; ++i) cin >> arr[i];
		Cumulative(arr, size, removedElements);

		for (int i = 0; i < size; ++i) cout << arr[i] << " ";
		cout << endl;
		for (int i = 0; i < 2; ++i) printf("%d ", removedElements[i]);
		delete[] arr;
	}
	return 0;
}

void Cumulative(int*& a, int& n, int* rem) {
	for (int i = 0; i < 2; ++i) {
		*(rem + i) = a[i];
	}


	a = a + 2; //shift the pointer to the first element of the array to  the third element
	n = n - 2;
	//cumulative sum process
	for (int i = 1; i < n; ++i) {
		a[i] = a[i] + a[i-1];
	}
	//modifing (a) elements
	//for (int i = 0; i < n; ++i) a[i] = c_arr[i];
}