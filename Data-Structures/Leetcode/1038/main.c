/*
  1038.   Binary Search Tree to Greater Sum Tree


    Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

    As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// Depth-First Search (DFS) function to convert BST to Greater Sum Tree (GST)
int dfs(struct TreeNode* root, int sum) {
    if (root) {
        // Traverse the right subtree first (reverse in-order traversal).
        sum = dfs(root->right, sum);
        
        // Update the current node's value with the accumulated sum.
        sum += root->val;
        root->val = sum;
        
        // Traverse the left subtree.
        sum = dfs(root->left, sum);
    }
    // Return the accumulated sum.
    return sum;
}

// Function to convert a BST to a Greater Sum Tree.
struct TreeNode* bstToGst(struct TreeNode* root) {
    // Start DFS traversal with an initial sum of 0.
    dfs(root, 0);
    // Return the modified tree.
    return root;
}
