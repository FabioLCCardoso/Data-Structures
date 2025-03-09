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

 void reSize(struct Frequency **sums, int *capacity){
          
        *capacity *= 2; 
       struct Frequency *temp = realloc(*sums, (*capacity)*  sizeof(struct Frequency));
        if(temp == NULL){
            free(*sums);
            exit(0);
        }
        *sums = temp;
    
 }

 int postorderTraversal(struct TreeNode* root, struct Frequency **sums, int* count, int *capacity){
    if(!root) return 0;

    int leftSum = postorderTraversal(root->left, sums, count, capacity);
    int rightSum = postorderTraversal(root->right, sums, count, capacity);
    
    int currSum = root->val + leftSum + rightSum;

    int found = 0;

    for(int i = 0; i < *count; i++){
        if( (*sums)[i].sum == currSum){
            (*sums)[i].frequency++;
            found = 1;
            break;
        }

    }

    if(!found){
        if (*count >= *capacity) {
            reSize(sums, capacity);
        }
        (*sums)[*count].sum = currSum;
        (*sums)[*count].frequency = 1;
        (*count)++;
 }
    

    return currSum;
 }

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
    int capacity = 10;
    struct Frequency *sums = malloc(capacity * sizeof (struct Frequency));
    if(!sums){
        return NULL;
    }
    int count = 0;
    postorderTraversal(root, &sums, &count, &capacity);

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