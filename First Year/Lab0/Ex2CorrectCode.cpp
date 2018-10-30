#include <stdio.h>
#define N 5
void main() {
	int arr [N], product;
	for (int i = 1 ; i < N ; i++) {
		printf("Enter value of arr[%d]:", i) ;
		scanf("%d", &arr[i]) ;
		if ( arr[i] % 2 == 1 )
			product *= arr[i] ;
	}
	printf("Product of those array elements that are odd = %d\n", product);
}