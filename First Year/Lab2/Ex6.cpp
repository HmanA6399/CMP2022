#include <iostream>
using namespace std;

//Fn.s DECLERATION	
bool RemoveDuplicates(int*, int*&, int, int&);

int main() {
	//DECLERATION AND ALLOCATION
 	int *X, *Y, Y_sz;
 	int N; cin >> N;
 	X = new int[N];
 	
	//INPUT
	for ( int i = 0; i<N; ++i ) cin >> X[i];

	//PROCESS N OUTPUT
 	if ( RemoveDuplicates(X, Y, N, Y_sz) ) //this will do the processand return true/false 
 		printf("The Array has Duplicates\n");
 	else 
 		printf("The Array has NO Duplicates\n");
	for ( int i = 0; i<Y_sz; ++i ) printf("%d ", Y[i]);
	printf("\n"); 	

	//HEAP DEALLCOC.
	delete[] X; delete[] Y;
 	
	return 0;
}


//Fn.s DEFINITION
bool isFound(int x, int a[], int n) //searches for x within a, returns true if found 
{ 
	for ( int i = 0; i<n; ++i )
		if ( a[i] == x ) return true;
	return false;
}
//I needn't write a prototype to isFound because i'll not use it in the main


bool RemoveDuplicates(int* x, int*& y, int n, int& sz)
{
	bool dup = false; //flag indicates if therer are duplicates or not 
	int cnt = 0, hasDup[n] //arrays stores 1 in i if x[i] has a duplicate before, 0 if not
	sz = 0; //counter of unique el.s
	for ( int i = 0; i<n; ++i )
		if ( isFound(x[i], x, i) ) {
			dup = true;
			hasDup[i] = 1;
			continue;
		} else {
			hasDup[i] = 0;
			sz++;
		}
	y = new int[sz];
	//store unique els. in y
	for ( int i = 0; i<n; ++i )
		if ( hasDup[i] ) {
			continue;
		} else {
			y[cnt++] = x[i];
		}
	return dup;
}