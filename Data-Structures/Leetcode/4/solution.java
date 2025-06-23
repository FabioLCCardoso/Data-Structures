import java.util.PriorityQueue;
import java.util.Collection;
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int mid;
    PriorityQueue<Integer>medianQ = new PriorityQueue<>();
    for(int i = 0; i < nums1.length; i++){
        medianQ.offer(nums1[i]);
    }
    for(int j = 0; j < nums2.length; j++){
        medianQ.offer(nums2[j]);
    }

    ArrayList<Integer> list = new ArrayList<>(medianQ);
    Collections.sort(list);
    mid = (list.size() / 2);
    if(list.size() % 2 == 0){
        int num1, num2;
        double result;
        num1 = list.get(mid - 1);
        num2 = list.get(mid);
       result = ((num1 + num2) / 2.0);
        return result;
    }
    else{
        int result = list.get(mid);
        return result ;
    }

    //return result ;
    }
}
