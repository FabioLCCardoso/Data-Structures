/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
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

 // Depth-First Search (DFS) function to convert BST to a Greater Sum Tree (GST).
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

    // Return the accumulated sum for further processing.
    return sum;
}

// Function to convert a Binary Search Tree (BST) to a Greater Sum Tree.
struct TreeNode* convertBST(struct TreeNode* root) {
    // Start DFS traversal with an initial sum of 0.
    dfs(root, 0);

    // Return the modified root of the tree.
    return root;
}
