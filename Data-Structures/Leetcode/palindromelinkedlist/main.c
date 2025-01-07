
//leetcode exercise 234: Palindrome Linked List

/*
Given the head of a singly linked list, return true if it is a
palindrome
or false otherwise.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

    //function to reverse the linked list
    struct ListNode* reverse(struct ListNode* head){
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
    //function to check if two lists are identical
    int isIdentical(struct ListNode *n1, struct ListNode *n2){
        for(; n1&&n2; n1 = n1 ->next, n2 = n2->next)
        if (n1->val != n2->val){
        return 0; }
        //returns 1 if all nodes are equal
        return 1;
    }

 //funciton to check if the list is palindrome
bool isPalindrome(struct ListNode* head) {
        if (!head || !head->next){
            return true;
        }

        struct ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        struct ListNode* head2 = reverse(slow->next);
        slow ->next = NULL;

        bool ret =isIdentical(head, head2);

        head2 = reverse(head2);
        slow->next = head2;
        return ret;

}