//Leetcode MoveZeroes

void moveZeroes(int* nums, int numsSize) {
    
 int j = 0;
 int temp;
 //Loop through the array
 for( int i = 0; i < numsSize; i++ ){
    //Tests if the element is not a zero and swap when found
    if( nums[i] != 0){
        //Prevents uncessessary swaps
        if(nums[i] != nums[j]){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        }
        j++;
    }
 }

}