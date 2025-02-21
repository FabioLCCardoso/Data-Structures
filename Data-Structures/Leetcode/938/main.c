/*
 
    Leetcode 938: Range Sum of BST


Given the root node of a binary search tree and two integers low and high, return the sum of 
values of all nodes with a value in the inclusive range [low, high].


Example 1:

Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



 void inRange(struct TreeNode* root, int low, int high, int* sum);

int rangeSumBST(struct TreeNode* root, int low, int high){
    int sum = 0;
    //call function to calculate the sum
    inRange(root, low, high, &sum);
    return sum;
}

void inRange(struct TreeNode* root, int low, int high, int* sum){
    
    //test if root is NULL
    if(!root) return;

    //Check if current node is within range
    if(root->val >= low && root->val<=high){
        *sum+= root->val;
    }
    //Recur for the branches
    inRange(root->left, low, high, sum);
    inRange(root->right, low, high, sum);
}