/* ############## LINEAR SEARCH #########################
 * Implementation of Linear Seach using array in C.
 * Auther - L Saimohan Rao
 * Email  - saimohanrao92@gmail.com
 * Github - https://github.com/saimohan1 
 * Linear Search Time Complexity:
 * 	Best = O(1), worst = O(n) 
 * ######################################################
 */ 

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Linear Search Function */
static bool
linearSearch(int *arr, int size, int input)
{
	int i, ret = false;
	for (i = 0; i < size; i++) {
		if (arr[i] == input) {
			/* found Number */
			ret = true;
		}
	}
	return ret;
}

int main()
{
	int arr[] = {1,3,8,4,11,29,65,12};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i, input;
	/* Display Array */
	for (i = 0; i < len; i++) 
		printf("%d\t", arr[i]);
	printf("\nPlease enter the number to search: ");
	scanf("%d", &input);
	printf("Number %d is %s in the array.\n", input,
		linearSearch(arr, len, input) == true ? "Found" : "Not Found");	
	return 0;
}
