//comparison function for qsort

int compare(const void*a,const void*b){
    return (* ( int * )a - * ( int * )b);
}
int* numberGame(int* nums, int size, int* returnSize) {

    //allocate memory for the array
    int *arr =  malloc(  4   *  size);
    int alice,bob,index = 0;

    //sort the array in ascending order
    qsort(nums,size,4,compare);
    for(int i=0;i<size-1;i+=2)
    {
        alice = nums[i];
        bob = nums[i+1];
        arr[index++]=bob;
        arr[index++]=alice;
    }
    *returnSize = size;
    return arr;
}