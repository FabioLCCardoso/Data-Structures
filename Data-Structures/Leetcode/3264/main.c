//leetcode 3264 answer

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));

    //If memory allocation fails
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Copy the original nums array into the result array
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }

    // Perform k operations
    for (int i = 0; i < k; i++) {
        // Find the index of the minimum value in result
        int minIndex = 0;
        for (int j = 1; j < numsSize; j++) {
            if (result[j] < result[minIndex]) {
                minIndex = j;
            }
        }

        // Multiply the minimum value by the multiplier
        result[minIndex] = result[minIndex] * multiplier;
    }

    *returnSize = numsSize;

    return result;
}
