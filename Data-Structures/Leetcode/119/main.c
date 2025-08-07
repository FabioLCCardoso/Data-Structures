/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* row = (int *)malloc((*returnSize) * sizeof(int));

    row[0] = 1; //First element

    for(int i = 1; i <= rowIndex ; i++){
        //Fill from left to right
        for(int j = i - 1; j > 0; j--){
            row[j] = row[j] + row[j - 1];
        }
        row[i] = 1; //Last element
    }
    return row;
}
