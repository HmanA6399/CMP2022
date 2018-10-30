#include <stdio.h>
#include <iostream>
#define N 5 // You can change this
using namespace std;

int main() {
	int arr[N];
	for (int i = 0; i < N; ++i) cin >> arr[i];
	
	int I = 1, T, J;
	
	while ( I < N ) {
		T = arr[I];
		J = I;
		while ( J > 0 ) {
			if (arr[J - 1] >= T)
				break;
			arr[J] = arr[J - 1];
			J--;
		}
		arr[J] = T;
		I++;
	}
	
	for (int i = 0; i < N; ++i) cout << arr[i] << " ";
	cout << "\n";
	return 0;
}