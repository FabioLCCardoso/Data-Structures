#include<limits.h>

int maxProduct(int* nums, int numsSize) {


    int max = INT_MIN;
    int max2 = INT_MIN;
    // Loop through the array
    for( int i = 0; i < numsSize; i++){
    
        //if current number is greater than max, update both
        if(nums[i] > max){
            max2 = max;
            max = nums[i];
        }
        else if( nums[i] > max2){
            max2 = nums[i];
    }
}
    return (max - 1) * (max2 - 1);
}