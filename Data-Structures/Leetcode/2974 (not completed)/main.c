/*
IT DOES NOT WORK!!
*/



int comp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), comp);
    
    // Allocate memory for the result array
    int *arr = malloc(numsSize * sizeof(int));
    
    // Check if memory allocation failed
    if (arr == NULL) {
        exit(EXIT_FAILURE);
    }

    // Process the elements, alternating between Bob and Alice
    for (int i = 0; i < numsSize / 2; i++) {
        // Alice removes the smallest element (first half of sorted array)
        int aliceElement = nums[i];
        // Bob removes the next smallest element (second half of sorted array)
        int bobElement = nums[i + (numsSize / 2)];
        if(i + (numsSize/2) == 2 ){
            bobElement = nums[1];
        } 


        // Bob appends his element first
        arr[2 * i] = bobElement;
        // Alice appends her element next
        arr[2 * i + 1] = aliceElement;
    }

    // Set the return size (size of the result array)
    *returnSize = numsSize;

    return arr;
}