#include <iostream>
using namespace std;

const int N = 7;

void Swap(int&, int&);
void  Move(int, int);
int ReorderMe(int*, int);

int main() {
	int arr[N]; 
	for ( int i = 0; i<N; ++i ) cin >> arr[i];

	printf("Reorder Value %d\n", ReorderMe(arr, N));
	printf("Array after reorder: ");
	for ( int i = 0; i<N; ++i ) printf("%d ", arr[i]);	
	printf("\n");
	return 0;
}


void Swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}


void Move(int* a, int loc, int dist) {
	for ( int i = loc; i>dist; --i ) 
		Swap(a[i], a[i-1]);
}


int ReorderMe(int* a, int n) {
	int first = a[0], j = 0;
	for ( int i = 1; i<n; ++i ) {
		if ( a[i] < first ) Move(a, i, j++);
	}
	return first;
}