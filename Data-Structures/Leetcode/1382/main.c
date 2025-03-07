/**Balance a Binary Search Tree
 * 
 * Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
 * A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 void inorder(struct TreeNode* root, struct TreeNode **nodes, int* index){
    if(!root) return;
    //traverse left subtree
    inorder(root->left, nodes, index);
    //store current node 
    nodes[*index] = root;
    (*index)++;
    //traverse left subtree
    inorder(root->right, nodes, index);
}

struct TreeNode* inorderToBST(struct TreeNode** nodes, int start, int end){
    if(start > end) return NULL;
    //find mid element (could be done using fast and slow pointers)
    int mid = (start + end) / 2;
    //the mid element is the root now
    struct TreeNode* root = nodes[mid];

    //left subtree
    root->left = inorderToBST(nodes, start, mid - 1);
    //right subtree
    root->right = inorderToBST(nodes, mid + 1, end);
    return root;
}
struct TreeNode* balanceBST(struct TreeNode* root) {
//hard coded array to store the nodes
struct TreeNode* nodes[10000];
int index = 0;
//inorder traversal
inorder(root, nodes, &index);
//balance BST
return inorderToBST(nodes, 0, index -1);
}