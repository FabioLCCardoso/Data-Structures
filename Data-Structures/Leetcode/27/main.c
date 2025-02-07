// Remove Element Leetcode

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    // Loop to test and change the string
    for (int i = 0; i < numsSize; i++){
    //Tests if the number is different to val, if it is, it moves to the front of the array
        if( nums [i] != val){
            nums[k++] = nums[i]; 
        }

    }
    return k;
}