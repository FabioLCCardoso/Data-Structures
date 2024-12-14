/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


 
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    int i, j;
    int  **p;

    //allocates memory for p (array of row pointers) and returnColumnSizes (to store the size of each row)
    p = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));
  
    //loop for the number of rows
    for(i = 0; i < numRows; i++) {
        // allocate memory for p (current row)
        p[i] = malloc((i + 1 ) * sizeof(int));
        // store the current row's size
        (*returnColumnSizes)[i] = i + 1 ;

        // set the first and last element of each row to 1 
        p[i][0] = 1;
        p[i][i] = 1;
        //fill in the elements between the first and last, each element is the sum of the two elements above them.
        for (j = 1; j < i ; j++ ){
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
        
    }
        *returnSize = numRows ;
    return p;
}