#include <iostream>
using namespace std;

const int N = 10;

void MinMaxAvg(int* a, int sz, int& min, int& max, float& avg);

int main() {
	int arr[N];
	int n;  cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	printf("You entered %d values\n", N);

	int Min, Max; float Avg;
	MinMaxAvg(arr, N, Min, Max, Avg);
	printf("Minimum value = %d\n", Min);
	printf("Maximum value = %d\n", Max);
	printf("Average value = %f\n", Avg);
	return 0;
}

void MinMaxAvg(int* a, int sz, int& min, int& max, float& avg) {
	int sum = 0;
	min = a[0]; max = a[0];

	for (int i = 0; i < sz; ++i) {
		if (a[i] < min) min = a[i];
		else if (a[i] > max) max = a[i];
		sum += a[i];
	}
	avg = float(sum) / sz;
}