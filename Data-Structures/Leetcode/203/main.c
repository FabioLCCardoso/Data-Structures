//not optmized

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
// create a node to point to the head of the list

struct ListNode* start = (struct ListNode*)malloc(sizeof(struct ListNode));

start -> next = head;
    //Previous Node (points to the start node)
    struct ListNode* prev = start;
    /// current node
    struct ListNode* current = head;

    //tests if the start is null
    if (start == NULL){
        return NULL;
    }

    //Loop until reaching the end
    while(current != NULL){
        //tests if the current node matches val
        if (current->val == val) {
            //skip the current node by switching the prev node's next pointer 
            prev -> next = current -> next;
            // free memory for the removed current node
            free(current);
            //move the current pointer to the next node
            current = prev -> next;
        }  else{
            //move both prev and current pointers forward
            prev = current;
            current = current->next;
        }
    }
    // creates the new head of the list
    struct ListNode* newhead = start -> next;
    free(start);
    //returns the new head
    return newhead;
}
