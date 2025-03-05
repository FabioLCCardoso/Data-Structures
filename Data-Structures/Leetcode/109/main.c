/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 // function to find the middle of the linked list (Divide and conquer)
 struct ListNode* findMid (struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL;
    
    // move fast pointer two steps and slow one step
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //disconnect left half from the middle node
    if (prev != NULL) {
        prev->next = NULL;
    }
    
    return slow;

}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    
    if(!head){
        return NULL;
    }
    //find mid element of the list
    struct ListNode* mid = findMid(head);

    //create the tree node with the mid element as root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = NULL;
    root->right = NULL;

    //if there's only one element, return the root
    if (head == mid) {
        return root;
    }
    //recursively construct left and right subtrees
    root->left = sortedListToBST(head); 
    root->right = sortedListToBST(mid->next); 

    return root;
}