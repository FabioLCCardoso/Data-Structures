int removeDuplicates(int* nums, int numsSize) {
    // k points to the next element
   int k = 1 ;

//Loop
    for ( int i = 1 ;  i < numsSize  ; i++){
        //Checks if the current number is different from the previous one
        if(nums[i]!=nums[i - 1]){
            //Puts the unique number on the place of the last repeated number
            nums[k] = nums[i];
        k++;
        }
    }

    return k;
}