/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// USING RECURSIVE MERGE
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // result variable
   struct ListNode* result = NULL;
   // tests if one of the lists is null
    if ( list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }

    //picks either list 1 or list 2 and recur
    if( list1 -> val <= list2 -> val ){
        result = list1;
        result -> next = mergeTwoLists(list1 -> next, list2);
    }
    else{
        result = list2;
        result -> next = mergeTwoLists(list1, list2 -> next);
    }
    return result;
}