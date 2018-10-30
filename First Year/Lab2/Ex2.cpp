#include<iostream>
using namespace std;

//Fn.s PROTOTYPE
int* doubler(int[], int, int &);


int main()
{
	//DECLERATION N ALLOCATION
	int sz, newSz; cin >> sz;
	int *arr = new int[sz], *doubled = new int[sz];
	//INPUT
	for (int i = 0; i < sz; ++i) cin >> arr[i];
	
	//PROCESS
	doubled = doubler(arr, sz, newSz);

	//OUTPUT
	for (int i = 0; i < newSz; ++i) printf("%d ", doubled[i]);

	//HEAP DEALLOC.
	delete[] arr; delete[] doubled;
	return 0;
}


//Fn.s DEFINITION
int* doubler(int a[], int size, int &newSize)
{
	int *doubl = new int[size], dblCnt = 0;
	for (int i = 0; i < size; ++i) 
		if (a[i] == 0) continue;
		else doubl[dblCnt++] = a[i]*2; //means to increment dblCnt after storing a[i] in double[dblCnt]
	//the final size of the new doubl array equals the last value of dblCnt
	newSize = dblCnt;
	return doubl;
}
