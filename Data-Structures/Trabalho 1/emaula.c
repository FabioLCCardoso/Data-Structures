/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 // nao funciona 

 //explicar o que nâo funcionou no video

 
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    int i, j;
    int  **p;

    //allocates memory for p and returnColumnSizes
    p = malloc(numRows * sizeof(int));
    *returnColumnSizes = malloc(numRows * sizeof(int));
    //loop for the number of rows
    for(i = 1; i <= numRows; i++) {
        // allocate memory for returnSize
        returnSize = malloc(i * sizeof(int));

        p[i - 1] = returnSize;
        (*returnColumnSizes)[i - 1] = i ;

        returnSize[0] = 1;
        for (j = 1; j < i - 1; j++ ){
            returnSize[j] = p[i - 2][j - 1] + p[i - 2][j];
        }
        
        returnSize[i - 1] = 1 ;
    }
    return p;
}