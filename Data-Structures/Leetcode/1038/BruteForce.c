/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Function to perform inorder traversal and store values dynamically
void inorder(struct TreeNode* root, int** inorderTraversal, int* size) {
    if (root == NULL) return;
    inorder(root->left, inorderTraversal, size);
    *inorderTraversal = realloc(*inorderTraversal, (*size + 1) * sizeof(int));
    if (*inorderTraversal == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    (*inorderTraversal)[(*size)++] = root->val;
    inorder(root->right, inorderTraversal, size);
}

// Function to swap node values
void swapValues(struct TreeNode* root, int* inorderTraversal, int size) {
    if (root == NULL) return;
    swapValues(root->left, inorderTraversal, size);
    swapValues(root->right, inorderTraversal, size);
    
    int nodeSum = 0;
    for (int i = 0; i < size; i++) {
        if (inorderTraversal[i] > root->val) {
            nodeSum += inorderTraversal[i];
        }
    }
    root->val += nodeSum;
}

// Function to transform BST to GST
struct TreeNode* bstToGst(struct TreeNode* root) {
    int* inorderTraversal = NULL;
    int size = 0;
    inorder(root, &inorderTraversal, &size);
    swapValues(root, inorderTraversal, size);
    free(inorderTraversal); 
    return root;
}