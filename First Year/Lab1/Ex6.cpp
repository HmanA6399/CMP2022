#include <iostream>
using namespace std;

const int N = 12;

void Reorder(int*, int*, int, int);

int main() {
	int X; cin >> X;
	int arr[N], brr[N];
	for ( int i =0; i<N; ++i ) cin >> arr[i];

	Reorder(arr, brr, N, X);

	printf("Array before reorder:\n");
	for ( int i =0; i<N; ++i ) printf("%d ", arr[i]);
	printf("\n");
	printf("Reorder Value: %d\n", X);
	printf("Arrays after reorder:\n");
	printf("Arr1: ");
	for ( int i =0; i<N; ++i ) printf("%d ", arr[i]);
	printf("\n");
	printf("Arr2: ");
	for ( int i =0; i<N; ++i ) printf("%d ", brr[i]);
	printf("\n");

	return 0;
}


void Reorder(int* a, int* b, int n, int x) {
	int cnt = 0;
	for ( int i = 0; i<n; ++i )
		if ( a[i] < x ) cnt++;
	int ls = 0, mr = cnt;
	for ( int i = 0; i<n; ++i )
		if ( a[i] < x ) b[ls++] = a[i];
		else b[mr++] = a[i];
}