/* ############## BINARY SEARCH #########################
 * Implementation of Binary Seach using array in C.
 * Auther - L Saimohan Rao
 * Email  - saimohanrao92@gmail.com
 * Github - https://github.com/saimohan1 
 * Binary Search Time Complexity:
 * 	Best = O(1), worst = O(log n) 
 * ######################################################
 */ 

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Binary Search Function */
static bool
binarySearch(int *arr, int size, int input)
{
	int first = 0;
	int last = size -1;
	int middle, ret = false;

	while (first <= last) {
		middle = (first + last) / 2;
		/* Found the Number */
		if (arr[middle] == input)
			return true;
		/* Number is present in the right sub arr */
		if (arr[middle] < input)
			first = middle + 1;
		/* Number is present in the left sub arr */
		if (arr[middle] > input)
			last = middle - 1;
			
	}
	return false;
}

int main()
{
	/* For Binary Search array Should be shorted */
	int arr[] = {1,3,5,6,8,11,23,54,66,89};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i, input;
	/* Display Array */
	for (i = 0; i < len; i++) 
		printf("%d\t", arr[i]);
	printf("\nPlease enter the number to search: ");
	scanf("%d", &input);
	printf("Number %s in the array\n",
		binarySearch(arr, len, input) == true ? "Found" : "Not Found");	
	return 0;
}
