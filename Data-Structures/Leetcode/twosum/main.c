#include <stdio.h>
#include <stdlib.h>

/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/



//// The answer is the twoSum function


int* twoSum(int* nums, int numsSize, int target ,  int* returnSize ) {
    int *indices = malloc(sizeof(int)* 2);
    int i;

    for(i = 0; i < numsSize; i++){
        int j;
    for (j = i + 1; j < numsSize; j++ ){
        if( nums[i] + nums[j] == target ){
            indices[0] = i;
            indices[1] = j; 
            *returnSize = 2;
            return indices;
            free(indices);
        }
    }
    }

    return NULL;
}



// this main doesnt work, the leetcode answer is the twoSum function
/* int main() {
  
  int nums[7] = {0,1,1,1,1,1,3};
  int* indices = twoSum(nums, 7, 5);
  if (!indices) {
    printf("no indices found.\n");
    exit(1);
  }
  printf("The indices are: ");
  int i;
  for (i = 0; i < 2; i++){
    printf("%i ", indices[i]);
  }
  printf("\n");
}
*/