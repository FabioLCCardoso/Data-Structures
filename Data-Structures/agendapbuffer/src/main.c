/*schedule without using variables 
    menu: 1 - Add person
          2 - Remove person
          3 - Search person
          4 - List all
          5 - Exit
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //memory allocation for temporary inputs
void *tempName = malloc ( 300 * sizeof (char));
void *tempAge = malloc ( 2 * sizeof ( int ) );
void *tempEmail =  malloc ( 50 * sizeof ( char ) );
void *pBuffer = malloc( 1 );
void *counter = pBuffer;
void *select = malloc ( sizeof ( int )); 
    //check if it allocated successfully 
    if(tempName == NULL || tempAge == NULL || tempEmail == NULL || pBuffer == NULL || counter == NULL || select == NULL ){
        printf("failed to allocate memory");
        exit(EXIT_FAILURE);
    }

//menu 
for(;;){
    printf("select an option: \n 1) Add Person \n 2) Remove Person \n 3) Search Person \n 4) List all \n 5) Exit  \n ");
    scanf("%d", ( int * ) select);

    switch ( * ( int* ) select ){
        //add person
        case(1): {
            printf("\nEnter name: ");
            scanf("%s", ( char * ) tempName);
            
            printf("\nEnter age: ");
            scanf("%d", ( int * ) tempAge);

            printf("\nEnter email: ");
            scanf("%s", ( char * ) tempEmail);

        //Realloate buffer
         pBuffer = realloc(pBuffer, sizeof(int) + (*(int *)counter + 1) * (300 + sizeof(int) + 50));
                if (pBuffer == NULL) {
                    printf("Failed to reallocate memory\n");
                    exit(EXIT_FAILURE);
        }
            //update counter 
            counter = pBuffer;

        //store person's data in the buffer 
            void *personPtr = pBuffer + sizeof(int) + (*(int *)counter) * ( 300 + sizeof(int) + 50);
                memcpy( personPtr  , tempName, 300);
                memcpy( personPtr + 300, tempAge, sizeof(int));
                memcpy( personPtr + 300 + sizeof(int), tempEmail, 50);

                (* ( int * ) counter )++; //increment counter
            printf("Person added");
        break;

        //remove a person
        case(2) : {
            if(*(int *) counter == 0 ){
                printf("There is no person to remove \n");
                continue;
               // break;
            }
            void *removeName = malloc(300 * sizeof ( char ) );
            if(removeName == NULL){
                printf("Memory allocation failed \n" );
                exit(EXIT_FAILURE);
            }

            printf("\nEnter the name you want to remove: \n");
            scanf("%s", (char * ) removeName);

            void *i = pBuffer + sizeof(int); // Buffer data 
            void *end = pBuffer +sizeof(int) + (*(int *) counter) * (300 + sizeof(int ) + 50); 
            
            //loop through the buffer
            while(i < end){
                if (strcmp((char *)i, (char *)removeName) == 0){
                    
                    //shift remaining persons up
                    void *j = i +(300 + sizeof(int) + 50);

                    while( j < end ){
                        memcpy(j - (300 + sizeof(int) + 50), j, 300 + sizeof(int) + 50);
                         j += (300 + sizeof(int) + 50);
                    }
                 // Resize the buffer to remove the last person's space
                pBuffer = realloc( pBuffer , sizeof(int) + ( * ( int * ) counter - 1) * ( 300 + sizeof(int) + 50 ));
                if (pBuffer == NULL) {

                printf("Failed to reallocate memory\n");

                free(removeName);

                exit(EXIT_FAILURE);
                }
                //update counter 
                counter = pBuffer; 

                //decrement counter
                (* (int *) counter )--; 
                printf("Person removed ");
                break;
                }
                
            //move to the next person
            i += (300 + sizeof(int) +50);  
            }

        if(i == end){
            printf("Person not found \n");
            free(removeName);
        }
        free(removeName);
        }
        
        break;
        //search name
        case(3): {
             if(*(int *) counter == 0 ){
                printf("There is no person to remove \n");
                break;
            }

            void *searchName = malloc(300 * sizeof(char));
            if(searchName == NULL){
                
                printf("Memory allocation failed");

                exit(EXIT_FAILURE);

            }
            printf("\nEnter the person's name: ");
            scanf("%s", (char *)searchName);


            void *i = pBuffer + sizeof(int); 
            void *end = pBuffer +sizeof(int) + (*(int *) counter) * (300 + sizeof(int ) + 50); 
            
            //loop through the buffer
            while(i < end){
                if(strcmp((char *)i, (char *)searchName) == 0){
                    printf("\nPerson found:\n");

                    printf("Name: %s\n", ( char *) i );
                    
                    printf("Age: %d\n", *(int *)( i + 300 ));
                    
                    printf("Email: %s\n", (char *)( i + 300 + sizeof(int)));
                    
                    break;
                }
                i += (300 + sizeof(int) + 50);
            }

            if(i == end ){
                printf("Person not found \n");
                free(searchName);
            }
            free(searchName);  
        }

        break;
        
        //list everyone
        case(4): {
            if(*(int * )counter == 0){
                printf("The list is empty: \n");
            }

        void *i = pBuffer + sizeof(int); 

        void *end = pBuffer +sizeof(int) + (*(int *) counter) * (300 + sizeof(int ) + 50); 

        printf("Listing everyone: \n");

        //loop through the buffer
        while(i < end){
            printf("Name: %s, Age: %d, Email: %s \n", (char *)i, *(int *) (i + 300), (char *)(i +300 + sizeof(int)));
            i+=(300 + sizeof(int) + 50 );
        }

        }
        break;
        
        //exit
        case(5): {
            free(select);
            free(tempName);
            free(tempAge);
            free(tempEmail);
            free(pBuffer);
            free(counter);
        exit(0);
        }
        break;
        
    }

    default: 
    printf("Invalid option. \n");
    break;
    }

}
    return 0;
}