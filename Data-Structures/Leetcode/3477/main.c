#include <stdbool.h>
int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
   int unplaced = 0;
    //boolean list to check if the basket is beign used
   bool *used = malloc(basketsSize * sizeof(bool));
   for (int i = 0; i < basketsSize; i++) {
    used[i] = false;
}
//loop through the fruits
for(int i = 0; i < fruitsSize; i++){
    //check if fruit is already 
    int flag = 0;
    //loop through the baskets
    for(int j = 0; j < basketsSize; j++){
        //if the basket is capable and not used, fruits are placed there
        if(*(fruits + i)<= *(baskets + j) && !used[j]){
            used[j] = true;
            flag = 1;
            break;
        }
    }
   if(flag == 0) unplaced++;  
}

free(used);
return(unplaced);
}
