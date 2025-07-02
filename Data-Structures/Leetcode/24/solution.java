/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        //store pointer to next node 
        ListNode nextNode = head.next;
        //recursively swap nodes in pairs starting from head->next->next
        ListNode swappedRest = swapPairs(nextNode.next);
        //connect current node to swapped rest
        head.next = swappedRest;
        //connect next node to current one
        nextNode.next = head;

        return nextNode;
    }
}
