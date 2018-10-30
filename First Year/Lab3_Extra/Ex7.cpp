#include "pch.h"
#include <iostream>
using namespace std;

//Fn PROTOTYPE
int getMinIndex(int*, int, int*&, int, int&);
void removeMinElement(int*, int&, int);

int main()
{
	//DECLERATION N INPUT
	int size; cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; ++i) cin >> arr[i];
	int delSize, delCnt = 0; cin >> delSize; //array to store deleted items
	int* delArr = new int[delSize];
	
	//PROCESS N OUTPUT
	int minIndex;
	for (int i = 0; i < delSize; ++i) {
		minIndex = getMinIndex(arr, size, delArr, delSize, delCnt); //Searching for the Min.Idx
		removeMinElement(arr, size, minIndex);
		for (int i = 0; i < size; ++i) cout << arr[i] << " "; //Printing the array every time
		printf("\n");
	}
	for (int i = 0; i < delCnt; ++i) cout << delArr[i] << " ";
	
	//HEAP DEALLOC.
	delete[] arr; delete[] delArr;
	return 0;
}

//Fn DEFINITION
int getMinIndex(int* a, int sz, int*& del_a, int szDel, int& delCnt) {
	int min = a[0];
	int minIdx = 0, i = 0;
	for (int i = 1; i < sz; ++i) {
		if (a[i] < min) {
			min = a[i];
			minIdx = i;
		}
	}
	del_a[delCnt] = min; //store the min. element in the array of deleted elements
	delCnt++;
	return minIdx;
}

void removeMinElement(int* a, int& sz, int idx) {
	//if you find it difficult, try to trace it one or two times
	for (int i = idx; i < sz-1; ++i) {
		a[i] = a[i + 1];
	}
	sz--;
	printf("\n");
}
