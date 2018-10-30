#include<iostream>
using namespace std;

//Fn.s PROTOTYPE
void AlternateSplit(int*&, int*&, int*&, int, int&, int&);
void AlternateMerge(int*, int*, int*, int);

int main() {
	//DECLERATION N ALLOCATION
	int *X, *Y, *Z;
	int sz; cin >> sz;
	int sz_z, sz_y;
	X = new int[sz];

	//INPUT
	for (int i = 0; i < sz; ++i) cin >> X[i];

	//PROCESS
	AlternateSplit(X, Y, Z, sz, sz_y, sz_z);
	AlternateMerge(Y, Z, X, sz);

	//OUTPUT
	printf("A = ");
	for (int i = 0; i < sz; ++i) printf("%d ", X[i]);
	printf("\n");

	//HEAP DEALLOC.
	delete[] X;

	return 0;
}


//Fn.s DEFINITION
void AlternateSplit(int*& x, int*& y, int*& z, int n, int& ny, int& nz)
{
	ny = (n + 1) / 2; //a faster ceil
	nz = n - ny;
	int cnty = 0, cntz = 0;
	y = new int[ny]; z = new int[nz];
	for (int i = 0; i < n; ++i)
		if (i & 1) //a condition that will be true then false then true then false and so on to switch between z and y
			z[cntz++] = x[i];
		else
			y[cnty++] = x[i];

	//Fns. OUTPUT
	printf("B = "); for (int i = 0; i < cnty; ++i) printf("%d ", y[i]);
	printf("\n");
	printf("C = ");
	for (int i = 0; i < cntz; ++i) printf("%d ", z[i]);
	printf("\n");
}


void AlternateMerge(int *y, int *z, int *x, int n)
 {
	int yCnt = 0, zCnt = 0;
	for (int i = 0; i < n; ++i)
		if (i & 1) x[i] = z[zCnt++];
		else x[i] = y[yCnt++];

	delete[] y; delete[] z;
}