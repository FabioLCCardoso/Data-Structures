/** Leetcode 206
 * 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 * 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
          struct ListNode* curr = head;
          struct ListNode* next;
  
          while(curr) {
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          return prev;
  }