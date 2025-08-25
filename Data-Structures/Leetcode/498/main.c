/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    if(!mat || !matSize){
        *returnSize = 0;
        return NULL;
    }
    int rows = matSize;
    int cols = *matColSize;
    int total = rows * cols;

    int *result = (int*)malloc(total * sizeof(int));
    *returnSize = total;

    int row = 0, col = 0;

    int dir = 1;

    for(int i = 0; i < total; i++){
        result[i] = mat[row][col];
        //move up right
        //dir = 0 CHANGES TO DOWN
       if(dir ==1 ){
        if(col == cols - 1){
            row++;
            dir = 0;
        }else if(row ==0){
            col++;
            dir = 0;
        }else{ //continuies up right
            row--;
            col++;
        }
        }else{
            if(row == rows - 1){
                col ++;
                dir = 1; //change to up
            }else if (col == 0){
                row ++;
                dir = 1;
            }
            else{
                row++;
                col--;
            }
        }
    }
    return result;
}
