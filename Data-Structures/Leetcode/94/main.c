/*Leetcode 94 
Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


//helper function for inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;
    
    //traverse left subtree
    inorderHelper(root->left, result, index);
    //store current node value
    result[(*index)++] = root->val;
    //traverse right subtree
    inorderHelper(root->right, result, index);
}

// Function to return inorder traversal of a binary tree
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    //allocate memory for result array
    int* result = (int*)malloc(100 * sizeof(int)); 
    //initialize return size
    *returnSize = 0;
    //call helper function to fill the result array
    inorderHelper(root, result, returnSize);
    //return array with the inorder traversal
    return result;
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    //allocate memory for new node
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    //set node value
    node->val = val;
    //initialize left and right node as NULL
    node->left = node->right = NULL;
    return node;
}
