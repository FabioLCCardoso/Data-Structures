void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //points to the last element of nums1
    int i = m - 1;
    //points to the last element of nums2
    int j = n - 1;
    //points to the last position of the new nums1
    int k = m + n - 1;
    //starts from the end and moves backwards
    while (i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]){
            // places the larger number in the correct position
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
       
        
    }
    //If there are remaining elements in nums2, copy them
    while(j>=0){
        nums1[k--] = nums2[j--];
    }

}