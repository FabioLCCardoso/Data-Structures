/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return NULL;

  struct  ListNode *curr = head;
  struct  ListNode *temp = head;

    while( curr->next != NULL ){
        if(curr->val == curr->next->val ){
            //Find dupe and remove curr->next (duplicated)
        struct ListNode *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);

        }else
        curr = curr->next;
    }
    return  head;
}
