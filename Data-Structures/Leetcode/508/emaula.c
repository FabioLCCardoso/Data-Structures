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

 struct Frequency{
    int sum;
    int frequency;
 };

 int postorderTraversal(struct TreeNode* root, struct Frequency *sums, int* count){
    if(!root) return 0;

    int leftSum = postorderTraversal(root->left, sums, count);
    int rightSum = postorderTraversal(root->right, sums, count);
    
    int currSum = root->val + leftSum + rightSum;

    int found = 0;

    for(int i = 0; i < *count; i++){
        if( sums[i].sum == currSum){
            sums[i].frequency++;
            found = 1;
            break;
        }

    }

    return currSum;
 }

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
    //struct Frequency sums[1000];
    struct Frequency *sums = malloc(10* sizeof (struct TreeNode));
    int count = 0;

    postorderTraversal(root, sums, &count);

    int maxFrequency = 0;
    for(int i = 0; i < count; i++){
        if(sums[i].frequency > maxFrequency){
            maxFrequency = sums[i].frequency;
        }
    }

    int rCount = 0;
    for(int i = 0; i < count; i++){
        if(sums[i].frequency == maxFrequency){
            rCount ++;
        }
    }

    int *result = (int*)malloc(rCount * sizeof(int));

    int j = 0;

    for(int i = 0; i < count; i++){
        if(sums[i].frequency == maxFrequency){
            result[j++] = sums[i].sum;
        }
    }
    *returnSize = rCount;

    return result;  

}