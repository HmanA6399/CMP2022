#include <iostream>
using namespace std;

const int N = 9;

void Swap(int&, int&);
bool Reverse(int*, int);

int main() {
	int arr[N];
	for ( int i = 0; i<N; ++i ) cin >> arr[i];

	bool reversed = Reverse(arr, N);
	
	if ( reversed ) printf("Array is NOT symmetric\n");
	else printf("Array is symmetric\n");
	printf("Array after reverse:\n");
	for ( int i = 0; i<N; ++i ) printf("%d ", arr[i]);
	printf("\n");
}


void Swap(int x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}


bool Reverse(int* a, int n) {
	bool rev = false;
	for ( int i = 0; i<n/2; ++i ) {
		if ( a[i]!=a[n-i-1] ) {
			rev = true;
			break;
		}
	}
	if ( !rev ) return rev;
	else for ( int i = 0; i<n/2; ++i ) swap(a[i], a[n-i-1]);
}