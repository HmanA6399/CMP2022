#include "pch.h"
#include <iostream>
using namespace std;

void GradStats(float*, int, float*, int, float*, int, float*, int, float*, float*, float*);
float Pctg(int, int);

int main()
{
	//DECLERATION AND ALLOCATION
	int size; cin >> size;
	float* arr = new float[size], *A, *B, *C;
	float A_stats[3], B_stats[3], C_stats[3];
	int szA = 0, szB = 0, szC = 0;

	//INPUT
	float t; //temproary input picker
	for (int i = 0; i < size; ++i) { //I'll use my input for-loop to count no. of elements in A, B and C
		cin >> t;
		if (t >= 75) szA++;
		else if (t < 75 && t >= 50) szB++;
		else szC++;
		arr[i] = t;
	}

	//ALLOCATION OF A, B AND C
	A = new float[szA];
	B = new float[szB];
	C = new float[szC];
	
	//PROCESS - Fn. CALLING
	GradStats(arr, size, A, szA, B, szB, C, szC, A_stats, B_stats, C_stats);

	//OUTPUT
	///Those Arrays are to avoid repetiton in the print statments
	char groups[3] = { 'A', 'B', 'C' };
	float* gradArrs[3] = { A, B, C }; //An Array that collects the arrays A, B and C
	int sizes[3] = { szA, szB, szC }; //An Array that collects the sizes of the arrays A, B and C
	float* statArrs[3] = { A_stats, B_stats, C_stats }; //An Array that collects the arrays of the stastics A_stats, B_stats, C_stats 

	//printing the first 3 lines
	for (int i = 0; i < 3; ++i) {
		printf("%c Grades: ", groups[i]);
		
		for (int j = 0; j < sizes[i]; ++j)
			printf("%.2f ", gradArrs[i][j]); //the first index [i] reaches one of  the arrays A,B or C. the other [j] loops on its elements

		printf("\n");
	}

	//printing the next 3 lines
	for (int i = 0; i < 3; ++i) {
		printf("For %c, Max = %.2f, Min= %.2f , Average= %.2f\n", groups[i], statArrs[i][0], statArrs[i][1], statArrs[i][2]);
	}

	//printing the last 3 lines
	for (int i = 0; i < 3; ++i) {
		printf("Percentage of %c: %.2f\n", groups[i], Pctg(sizes[i], size));
	}

	//DYNAMIC MEMORY DEALLOCATION
	delete[] arr;
	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}


//Utility fn to calculate Percentage
float Pctg(int part, int total) {
	return (float(part) / total) * 100;
}


//Utility fn to calculate Average of two values
float Avg(float s, int n) {
	return (n == 0) ? 0 : float(s) / n;
}
// We don't need to write the prototype of Avg before the main() because we'll not use it
//in the main, only in our function GradStats


void GradStats(float* in, int n, float* a, int na, float* b, int nb, float* c, int nc, float* a_stats, float* b_stats, float* c_stats) {
	float a_sum = 0.0, b_sum = 0.0, c_sum = 0.0, x;
	int a_cnt = 0, b_cnt = 0, c_cnt = 0;
	//loop over all the inputs to calc. a_sum, b_sum, c_sum and fill the arrays 
	///All stats arrays are in the order [max, min, avg] where max and min of all grades
	///starts with -INFINITY and INFINITY respectively - think of it thoroughly -
	a_stats[0] = -INFINITY; b_stats[0] = -INFINITY; c_stats[0] = -INFINITY;
	a_stats[1] = INFINITY; b_stats[1] = INFINITY; c_stats[1] = INFINITY;
	for (int i = 0; i < n; ++i) {
		x = in[i];
		if (x >= 75) {
			//x is of A group
			a[a_cnt++] = x;
			a_sum += x;
			if (x > a_stats[0]) a_stats[0] = x;
			if (x < a_stats[1]) a_stats[1] = x;

		}
		else if (x < 75 && x >= 50) {
			//x is of B group
			b[b_cnt++] = x;
			b_sum += x;
			if (x > b_stats[0]) b_stats[0] = x;
			if (x < b_stats[1]) b_stats[1] = x;
		}
		else if (x<50) {
			//x is of C group
			c[c_cnt++] = x;
			c_sum += x;
			if (x > c_stats[0]) c_stats[0] = x;
			if (x < c_stats[1]) c_stats[1] = x;
		}
	}
	//calculte avg
	a_stats[2] = Avg(a_sum, na); b_stats[2] = Avg(b_sum, nb); c_stats[2] = Avg(c_sum, nc);
}