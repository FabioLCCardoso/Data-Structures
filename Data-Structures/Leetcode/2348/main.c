long long zeroFilledSubarray(int* nums, int numsSize) {
    long long ctr = 0, streak = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            //if there are 0's, increment streak.
            streak ++;
            //counter = streak
            ctr+= streak;
        } else{
            //if it's not a 0, the streak resets
            streak = 0;
        }
    }
    return ctr;
}
