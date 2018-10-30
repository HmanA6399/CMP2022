#include<iostream>
using namespace std;

//Fn.s PROTOTYPE
void  merge(int *, int *, int, int, int*&, int&);

int main()
{
	//DECLERATION N ALLOCATION
	int *A, *B, *C, szA, szB, szC;
	cin >> szA >> szB;
	A = new int[szA]; B = new int[szB];

	//INPUT
	for (int i = 0; i < szA; ++i) cin >> A[i];
	for (int i = 0; i < szB; ++i) cin >> B[i];

	//PROCESS
	merge(A, B, szA, szB, C, szC);

	//OUTPUT
	for (int i = 0; i < szC; ++i) printf("%d ", C[i]);
	printf("\n");

	//HEAP DEALLOC.
	delete[] A; delete[] B; delete[] C;
	return 0;
}

//Fn.s DEFINITION

void merge(int *a, int *b, int na, int nb, int *&c, int &nc)
{
	nc = na + nb;
	c = new int[nc];
	int c_cnt = 0;
	for (int i = 0; i < na; ++i) c[c_cnt++] = a[i];
	for (int i = 0; i < nb; ++i) c[c_cnt++] = b[i];
}
