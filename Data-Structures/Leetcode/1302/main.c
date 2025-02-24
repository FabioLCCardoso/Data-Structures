/**
 * 1302. Deepest Leaves Sum

    Given the root of a binary tree, return the sum of values of its deepest leaves.
 * 
 * 
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 int findMaxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    // Recursively find the deepest leave of each subtree
    int leftDepth = findMaxDepth(root->left);
    int rightDepth = findMaxDepth(root->right);
    // Ternary operators (if leftDepth > rightDepth return leftDepth. Else return rightDepth)
    // Returns the maxDepth with +1 for the current node
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

void dfs(struct TreeNode *root, int currentDepth, int maxDepth, int *sum) {
    if (root == NULL)
        return;
    
    // If the node is at the deepest level, add to sum
    if (currentDepth == maxDepth)
        *sum += root->val;

    // Recursively traverse left and right subtrees increasing depth + 1
    dfs(root->left, currentDepth + 1, maxDepth, sum);
    dfs(root->right, currentDepth + 1, maxDepth, sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    // Finds maximum depth
    int maxDepth = findMaxDepth(root);
    int sum = 0;
    // Dfs to calculate the sum of the deepest nodes
    dfs(root, 1, maxDepth, &sum);
    return sum;
}