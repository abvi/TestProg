#include <cstdio>

int findIndex(int *arr, int numToFind, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == numToFind) return mid;
    
    if (arr[mid] >= arr[low]) {
        // rotation point does not occur in left segment
        if (numToFind >= arr[low] && numToFind < arr[mid]) {
            // needle appears in left segment
            return findIndex(arr, numToFind, low, mid-1);
        } else {
            return findIndex(arr, numToFind, mid+1, high);
        }
    } else {
        // rotation point occurs in left segment
        if (numToFind > arr[mid] && numToFind <= arr[high]) {
            // needle appears in the right segment
            return findIndex(arr, numToFind, mid+1, high);
        } else {
            return findIndex(arr, numToFind, low, mid-1);
        }
    }
}

int main() {
	//code
	int arr[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    printf("Starting findIndex\n");
    printf("Enter number to find: ");
    int num = 0;
    scanf("%d", &num);
	printf("Index for %d is %d\n", num, findIndex(arr, num, 0, sizeof(arr) / sizeof(arr[0])));
	return 0;
}