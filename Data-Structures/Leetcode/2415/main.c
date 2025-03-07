/**
 * Reverse Odd Levels of Binary Tree
 * 
 * 
 * Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
 *  For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
 * Return the root of the reversed tree.
 * A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
 * The level of a node is the number of edges along the path between it and the root node.
 * 
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void swapEvenLevels(struct TreeNode* left, struct TreeNode* right, int level){
    if (left==NULL || right == NULL) return;
// If the current level is even, swap the current left and right nodes
    if(level % 2 == 0){
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
    }
// Recursive call to process the next level: left-left with right-right
    swapEvenLevels(left->left, right->right, level +1);
// Recursive call to process the next level: left-right with right-left
    swapEvenLevels(left->right, right->left, level +1);
 }
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if(!root) return NULL;

    swapEvenLevels(root->left, root->right, 0);
    return root;
}